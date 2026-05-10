#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cstring> // For memset

// Global arrays for potential minor performance improvement by avoiding std::vector overheads
// and allowing direct memset initialization.
// Max k is 10, so arrays of size 10 or 1 << 10 are sufficient.
long long pairwise_inversions[10][10];
int count_seen[10];
long long dp[1 << 10][10]; // dp[mask][last_char_type]

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int k; // Number of distinct characters in string s
    std::cin >> k;
    std::string s; // The input string
    std::cin >> s;

    int n = s.length(); // Length of the string s

    // Initialize arrays (using memset for potentially faster initialization)
    // pairwise_inversions[i][j] will store the count of pairs (u, v) such that
    // s[u] is of character type 'a'+i, s[v] is of character type 'a'+j, and u < v.
    memset(pairwise_inversions, 0, sizeof(pairwise_inversions));
    // count_seen[i] will store how many times character 'a'+i has appeared so far.
    memset(count_seen, 0, sizeof(count_seen));
    
    // Precomputation: Calculate pairwise_inversions for all character type pairs
    // Time complexity: O(N * k)
    for (int char_idx = 0; char_idx < n; ++char_idx) {
        int current_char_type = s[char_idx] - 'a'; // Map 'a' to 0, 'b' to 1, etc.

        // For each character type that appeared *before* the current character at `char_idx`,
        // it forms a (previous_char_type, current_char_type) pair.
        for (int prev_char_type = 0; prev_char_type < k; ++prev_char_type) {
            if (prev_char_type == current_char_type) {
                continue; // Don't count same character types against themselves
            }
            // `count_seen[prev_char_type]` gives the total occurrences of `prev_char_type`
            // that happened *before* `char_idx`. Each of these forms a pair
            // where `prev_char_type` comes before `current_char_type`.
            pairwise_inversions[prev_char_type][current_char_type] += count_seen[prev_char_type];
        }
        // Increment count for the current character type after processing it
        count_seen[current_char_type]++;
    }

    // Initialize DP table with -1, indicating states that are not yet reachable
    // dp[mask][last_char_type] stores the maximum number of inversions
    // for a permutation of character types represented by 'mask',
    // where 'last_char_type' is the last character type in that permutation.
    memset(dp, -1, sizeof(dp));

    // Base cases for DP: Each character type can be the first element in a permutation.
    // When a single character type is placed, it adds 0 inversions.
    for (int i = 0; i < k; ++i) {
        dp[1 << i][i] = 0; // Mask `1 << i` means only character type `i` is included.
    }

    long long max_total_inversions = 0; // Variable to store the overall maximum inversions

    // Dynamic Programming: Iterate through all possible masks (subsets of character types)
    // Time complexity: O(2^k * k^2)
    for (int mask = 1; mask < (1 << k); ++mask) {
        // Iterate through all possible 'last_char_type's that could be the last element
        // in the permutation represented by the current 'mask'.
        for (int last_char_type = 0; last_char_type < k; ++last_char_type) {
            // Check if 'last_char_type' is part of the 'mask' and if this state is reachable
            if (!((mask >> last_char_type) & 1) || dp[mask][last_char_type] == -1) {
                continue;
            }

            // Try to extend the current permutation by adding a 'next_char_type'
            for (int next_char_type = 0; next_char_type < k; ++next_char_type) {
                // If 'next_char_type' is not yet in the current 'mask' (meaning it's a new character type to add)
                if (!((mask >> next_char_type) & 1)) {
                    long long current_cost_for_next_block = 0;

                    // When 'next_char_type' block is placed after all 'prev_char_in_mask' blocks,
                    // inversions are generated for every pair where 'next_char_type' appeared
                    // before 'prev_char_in_mask' in the original string `s`.
                    for (int prev_char_in_mask = 0; prev_char_in_mask < k; ++prev_char_in_mask) {
                        // If 'prev_char_in_mask' is part of the current 'mask'
                        if (((mask >> prev_char_in_mask) & 1)) {
                            // Add count of (next_char_type BEFORE prev_char_in_mask) to inversions.
                            // This happens because in the target string s', prev_char_in_mask block
                            // comes before next_char_type block. But in the original string s,
                            // next_char_type characters might have appeared before prev_char_in_mask characters.
                            current_cost_for_next_block += pairwise_inversions[next_char_type][prev_char_in_mask];
                        }
                    }

                    int new_mask = mask | (1 << next_char_type); // New mask including 'next_char_type'
                    // Update DP state for the new mask and 'next_char_type' as the last element
                    dp[new_mask][next_char_type] = std::max(dp[new_mask][next_char_type],
                                                             dp[mask][last_char_type] + current_cost_for_next_block);
                }
            }
        }
    }

    // After computing DP for all masks, find the maximum value among all states
    // where all `k` character types are included (mask `(1 << k) - 1`).
    for (int i = 0; i < k; ++i) {
        max_total_inversions = std::max(max_total_inversions, dp[(1 << k) - 1][i]);
    }

    // Output the result
    std::cout << max_total_inversions << std::endl;

    return 0;
}
