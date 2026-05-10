#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const long long INV2 = 500000004; // Modular inverse of 2 mod (10^9 + 7)

long long nCr_2(long long n) {
    if (n < 2) return 0;
    long long res = (n * (n - 1)) % MOD;
    res = (res * INV2) % MOD;
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    if (N < 9) { // A "Kanji for King" pattern requires exactly 9 nodes.
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> adj(N + 1);
    std::vector<int> deg(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    long long total_kanji_count = 0;

    // Iterate through each node 'c' to consider it as the potential center of the Kanji pattern.
    for (int c = 1; c <= N; ++c) {
        // The center node 'c' must have at least 4 neighbors in the original tree
        // to form 2 simple arms and 2 complex arms that are distinct neighbors.
        if (deg[c] < 4) {
            continue;
        }

        long long sum_Wx = 0;      // Sum of W_n values for all eligible complex arm candidates
        long long sum_Wx_sq = 0;   // Sum of W_n * W_n for all eligible complex arm candidates
        int complex_arm_candidate_count = 0; // Number of neighbors of 'c' that can be complex arms

        // Iterate through neighbors 'n' of the potential center 'c'.
        for (int n : adj[c]) {
            long long kx = deg[n] - 1; // Number of neighbors of 'n', excluding 'c'.
                                       // These are potential children of 'n' if 'n' acts as a complex arm.
            if (kx >= 2) { // 'n' can be a complex arm if it has at least 2 other neighbors to connect to as leaves.
                long long ways_for_k_children = nCr_2(kx); // C(kx, 2)
                sum_Wx = (sum_Wx + ways_for_k_children) % MOD;
                sum_Wx_sq = (sum_Wx_sq + ways_for_k_children * ways_for_k_children) % MOD;
                complex_arm_candidate_count++;
            }
        }

        // We need to pick two distinct complex arms.
        // If there are not enough candidates, skip this center.
        if (complex_arm_candidate_count < 2) {
            continue;
        }

        // Calculate ways to pick two distinct complex arms from the qualified candidates.
        // This is sum_{i<j} W_i * W_j = ( (sum W_i)^2 - (sum W_i^2) ) / 2
        long long ways_for_two_complex_arms_children = (sum_Wx * sum_Wx - sum_Wx_sq + MOD) % MOD;
        ways_for_two_complex_arms_children = (ways_for_two_complex_arms_children * INV2) % MOD;

        // If no valid pairs of complex arms can be formed, skip.
        if (ways_for_two_complex_arms_children == 0) {
            continue;
        }

        // We have chosen 2 neighbors of 'c' to be complex arms.
        // The remaining neighbors of 'c' are candidates for simple arms.
        // We need to pick 2 simple arms from these remaining neighbors.
        long long num_available_for_simple_arms = deg[c] - 2;
        
        // If there are not enough remaining neighbors for 2 simple arms, skip.
        if (num_available_for_simple_arms < 2) {
            continue;
        }

        long long ways_for_simple_arms = nCr_2(num_available_for_simple_arms);

        // Total Kanji patterns centered at 'c' is (ways for complex arms) * (ways for simple arms).
        total_kanji_count = (total_kanji_count + ways_for_two_complex_arms_children * ways_for_simple_arms) % MOD;
    }

    std::cout << total_kanji_count << std::endl;

    return 0;
}
