#include <bits/stdc++.h>

using namespace std;

vector<int> m_stars;
long long target_sum_per_galaxy;
int N_stars, K_galaxies;

// memo[k_remaining] stores a vector representing mask states.
// -1: unvisited, 0: false, 1: true
vector<char> memo[21]; 

// Recursive function to determine if the remaining elements in `available_mask` can be
// partitioned into `k_remaining` groups, each summing to `target_sum_per_galaxy`.
// `available_mask`: bitmask of elements that are *not yet placed* into a complete group.
// `current_bucket_sum`: the sum of the elements currently being assembled for the *current* group.
// `start_idx_for_inner`: optimization to ensure we don't try elements already considered for this bucket.
//                        When starting a *new* bucket (current_bucket_sum == 0), this should be 0.
//                        When continuing a bucket, it should be the index *after* the last element added.
bool can_partition(int k_remaining, int available_mask, long long current_bucket_sum, int start_idx_for_inner) {
    // Base case 1: All k groups formed successfully
    if (k_remaining == 0) {
        return true; 
    }

    // Base case 2: Current bucket is complete
    if (current_bucket_sum == target_sum_per_galaxy) {
        // Start forming the next group. Reset current_bucket_sum to 0.
        // The `available_mask` now contains fewer elements as the current group's elements are used.
        // We start searching for elements for the new group from index 0.
        return can_partition(k_remaining - 1, available_mask, 0, 0); 
    }

    // Base case 3: Current bucket sum exceeded target.
    if (current_bucket_sum > target_sum_per_galaxy) {
        return false;
    }
    
    // Base case 4: No elements left to add to current bucket or form new ones.
    if (available_mask == 0) { 
        return false;
    }

    // Memoization: Only memoize when starting a *new* bucket (current_bucket_sum == 0)
    // The state `(k_remaining, available_mask)` uniquely identifies if we can complete
    // `k_remaining` groups from `available_mask` of elements when starting a fresh group.
    if (current_bucket_sum == 0) {
        if (memo[k_remaining][available_mask] != -1) {
            return memo[k_remaining][available_mask];
        }
    }
    
    bool possible = false;
    // Iterate through available elements from `start_idx_for_inner` onwards.
    // `m_stars` is sorted in descending order, so this loop effectively tries larger elements first for pruning.
    for (int i = start_idx_for_inner; i < N_stars; ++i) {
        if ((available_mask >> i) & 1) { // If m_stars[i] is available in the current mask
            // Try including m_stars[i] in the current bucket
            // Recursively call with:
            // - `k_remaining`: remains the same, as we are still filling the same group.
            // - `available_mask ^ (1 << i)`: remove m_stars[i] from available elements.
            // - `current_bucket_sum + m_stars[i]`: update sum for the current group.
            // - `i + 1`: start searching for the next element from index `i + 1` to avoid duplicate permutations.
            if (can_partition(k_remaining, available_mask ^ (1 << i), current_bucket_sum + m_stars[i], i + 1)) {
                possible = true;
                break; // Found a way to partition, no need to explore other options for this step
            }
        }
    }

    // If we were starting a new bucket (current_bucket_sum was 0), memoize the result.
    if (current_bucket_sum == 0) { 
        memo[k_remaining][available_mask] = possible;
    }
    return possible;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N_stars >> K_galaxies;

    long long total_mass = 0;
    m_stars.resize(N_stars);
    for (int i = 0; i < N_stars; ++i) {
        cin >> m_stars[i];
        total_mass += m_stars[i];
    }

    // If total mass is not divisible by K, it's impossible.
    if (total_mass % K_galaxies != 0) {
        cout << "NO" << endl;
        return 0;
    }

    target_sum_per_galaxy = total_mass / K_galaxies;
    
    // Edge case: if target_sum_per_galaxy is 0, it means all m_stars must be 0 (total_mass = 0).
    // If total_mass is not 0 but target_sum_per_galaxy is 0 (e.g., K is huge), it's impossible.
    // Problem constraints (m_i <= 10^7) typically imply m_i >= 1, making target_sum_per_galaxy > 0.
    // However, if m_i could be 0, and total_mass = 0, target_sum_per_galaxy = 0 is valid.
    // The recursive function naturally handles this case.

    // Optimization: Sort m_stars in descending order. This helps prune branches faster
    // as larger sums exceed target_sum_per_galaxy sooner, allowing early termination.
    sort(m_stars.rbegin(), m_stars.rend());

    // Initialize memoization table: -1 for unvisited, 0 for false, 1 for true.
    for (int i = 0; i <= K_galaxies; ++i) {
        memo[i].assign(1 << N_stars, -1);
    }
    
    // Initial call:
    // - `k_remaining = K_galaxies`: we need to form K galaxies.
    // - `available_mask = (1 << N_stars) - 1`: all stars are initially available.
    // - `current_bucket_sum = 0`: we are starting to form the first galaxy.
    // - `start_idx_for_inner = 0`: start searching for elements from index 0.
    if (can_partition(K_galaxies, (1 << N_stars) - 1, 0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
