#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // P[i] stores the sum of soldiers from battalion 0 to i-1.
    // P[0] = 0
    // P[i+1] = A[0] + ... + A[i]
    vector<long long> P(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        P[i+1] = P[i] + A[i];
    }

    // current_idx: index of the first battalion that is not fully destroyed.
    // current_rem_soldiers: number of soldiers remaining in battalion A[current_idx].
    // If current_idx == N, it means all battalions are destroyed.
    int current_idx = 0;
    long long current_rem_soldiers = A[0];

    for (int q = 0; q < Q; ++q) {
        long long enemies;
        cin >> enemies;

        // If all battalions were destroyed on the previous day, they are recreated at the start of this day.
        if (current_idx == N) {
            current_idx = 0;
            current_rem_soldiers = A[0];
        }

        // First, check if the currently partially-destroyed battalion (if any) can defeat some enemies.
        // Or if it's a fresh battalion, if it can defeat some enemies.
        if (enemies >= current_rem_soldiers) {
            // The current battalion is completely destroyed.
            enemies -= current_rem_soldiers;
            current_idx++;
            current_rem_soldiers = 0; // This battalion is gone, the next one is initially fresh.

            if (current_idx == N) {
                // All N battalions are now destroyed. The attack stops for the day.
                // The state current_idx = N indicates this.
                // Output will be N, and for the next day, battalions will be recreated.
            } else {
                // There are still enemies and remaining battalions.
                // We use binary search on prefix sums to quickly find how many more full battalions are destroyed.
                
                // P[current_idx] is the sum of soldiers of battalions A[0]...A[current_idx-1].
                // We add `enemies` to this base sum to find the total soldier count that enemies can destroy.
                long long target_sum_for_prefix_search = enemies + P[current_idx];
                
                // Find the first element in P (from P[current_idx] to P[N]) that is strictly greater than `target_sum_for_prefix_search`.
                // `it` will point to P[k] where P[k] > target_sum_for_prefix_search.
                // The actual index we are interested in is `k-1`, which corresponds to `P[k-1] <= target_sum_for_prefix_search`.
                // This `k-1` is the index of the battalion *after* the last fully destroyed one.
                auto it = upper_bound(P.begin() + current_idx, P.begin() + N + 1, target_sum_for_prefix_search);
                int new_current_idx = distance(P.begin(), it) - 1;
                
                // Calculate soldiers consumed by destroying full battalions from `current_idx` to `new_current_idx-1`.
                long long soldiers_consumed_by_full_battalions = P[new_current_idx] - P[current_idx];
                enemies -= soldiers_consumed_by_full_battalions;
                
                current_idx = new_current_idx;

                if (current_idx < N) {
                    // Some battalions still remain, the one at `current_idx` is partially destroyed.
                    current_rem_soldiers = A[current_idx] - enemies;
                } else {
                    // All N battalions are now destroyed.
                    current_rem_soldiers = 0; // Consistency, this will be reset to A[0] next day if needed.
                }
                // All enemies have been dealt with for this day (either defeated or wiped out all battalions).
            }
        } else { // enemies < current_rem_soldiers
            // The current battalion defeats all enemies and survives.
            current_rem_soldiers -= enemies;
            // enemies become 0, and the attack for the day ends.
        }

        // Output the number of remaining battalions for the current day.
        if (current_idx == N) {
            // If all battalions were destroyed during this day's attack, they are recreated by day end.
            cout << N << "\n";
        } else {
            // Otherwise, `N - current_idx` battalions remain alive.
            cout << N - current_idx << "\n";
        }
    }

    return 0;
}
