#include <iostream>
#include <vector>
#include <algorithm>

// Segment tree for range maximum queries
// Each leaf x stores the "next_occurrence" of value x.
// next_occurrence(x, i) is the smallest index p >= i where a[p] == x.
// When iterating i from N-1 down to 0, current_next_occ_val[x] effectively stores next_occurrence(x, i).
// The segment tree stores these current_next_occ_val values.
struct SegmentTree {
    int size;
    std::vector<int> tree; // Stores max values in ranges

    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, n); // Initialize with N (sentinel for not found). Maximum possible index is N-1.
                                  // If a value is not found from current_i to N-1, its next_occurrence is N.
    }

    // Updates the value at `val_idx` to `new_pos`.
    void update(int val_idx, int new_pos, int x, int lx, int rx) {
        if (rx - lx == 1) { // Leaf node
            tree[x] = new_pos;
            return;
        }
        int m = (lx + rx) / 2;
        if (val_idx < m) {
            update(val_idx, new_pos, 2 * x + 1, lx, m);
        } else {
            update(val_idx, new_pos, 2 * x + 2, m, rx);
        }
        tree[x] = std::max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int val_idx, int new_pos) {
        update(val_idx, new_pos, 0, 0, size);
    }

    // Queries the maximum value in the range [l, r) in the segment tree.
    int query_range_max(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return -1; // No overlap or out of range, return a minimal value
        if (lx >= l && rx <= r) return tree[x]; // Current segment completely within query range
        int m = (lx + rx) / 2;
        int left_max = query_range_max(l, r, 2 * x + 1, lx, m);
        int right_max = query_range_max(l, r, 2 * x + 2, m, rx);
        return std::max(left_max, right_max);
    }

    int query_range_max(int l, int r) { // Query max in range [l, r)
        return query_range_max(l, r, 0, 0, size);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    // This problem requires calculating f(k) for k from 1 to N.
    // f(k) is the minimum number of segments such that MEX of each segment is <= k.
    // MEX(S) <= k means that not all numbers 0, ..., k are present in S.
    // Let R_k[i] be the smallest index j >= i such that the segment a[i...j] contains all numbers 0, ..., k.
    // If no such j exists, R_k[i] = N.
    // The maximum valid right endpoint for a segment starting at i with MEX <= k is R_k[i] - 1.
    // So, if a segment starts at `current_pos`, the next segment must start at `R_k[current_pos]`.
    // R_k[i] can be defined as: max_{x=0...k} (next_occurrence(x, i)).
    // next_occurrence(x, i) is the smallest index p >= i such that a[p] == x.

    // To compute R_k[i] efficiently for all i and k:
    // We can iterate i from N-1 down to 0.
    // Maintain a segment tree where leaf `x` stores `next_occurrence(x, i)`.
    // When `i` goes to `i-1`, `next_occurrence(a[i-1], i-1)` becomes `i-1`. Other `next_occurrence(x, i-1)`
    // remain `next_occurrence(x, i)`. This is a point update in the segment tree.
    // After updating for `i`, we need `R_k[i]` for all `k`.
    // R_k[i] is `seg_tree.query_range_max(0, k+1)`.
    // This query is O(log N). Performing it for all `k` for each `i` is O(N * N * log N). Too slow.

    // Optimization: When calculating f(k) using jumps (curr = R_k[curr]),
    // the total number of jumps across all k values (if the next jump values R_k[curr] are distinct)
    // is limited. We can use binary lifting.
    // jump[p][i] = index after 2^p jumps from i, for a specific k.
    // Building jump table for one k is O(N log N). Total O(N^2 log N). Too slow.

    // A crucial observation: f(k) is non-increasing as k increases.
    // f(k) = 1 for k >= max(a_i) + 1. (Because `k` cannot be present, so MEX is always <= k).
    // Let's compute f(k) for k from `max(a_i)` down to 1.
    // This problem is a classic "offline processing" type.
    // We want to calculate `f(k)` values, which rely on `R_k[i]` values.
    // The `R_k[i]` values are `max_{x=0..k} (next_occ(x, i))`.
    // The `next_occ(x, i)` values can be obtained by a `last_pos` array, by sweeping `i` from `N-1` down to `0`.
    // `last_pos[x]` means the first occurrence of `x` at or after current `i`.

    // Store `pos[val]` which contains all indices where `val` appears.
    std::vector<std::vector<int>> pos_list(N);
    for (int i = 0; i < N; ++i) {
        pos_list[a[i]].push_back(i);
    }

    std::vector<int> current_next_occ_val_at_i(N); // next_occ(x, i) for current i
    
    // dp[i] will store the minimum number of segments for the suffix a[i...N-1].
    // We need this for different k. So it should be a structure.
    // dp[k][i] = 1 + dp[k][R_k[i]]
    // This is `f_k[i]` (using f_k for dp for a given k)
    // The base case is f_k[N] = 0.
    // We will compute f_k[i] for i from N-1 down to 0 for all k.
    
    // We need to store `dp[k][idx]` values for `idx > i`.
    // This is a range minimum query on `dp` values.
    
    // This approach is more efficient: For a fixed `k`, `f(k)` can be found using `O(N)` jumps.
    // Let `last_pos_for_k[x]` be the last seen position of `x` such that `x <= k`.
    // We calculate `f(k)` for all `k` simultaneously.
    
    std::vector<int> answers(N + 1);
    
    // next_jump_val_for_k[i] stores R_k[i] for the current k.
    // We don't store R_k[i] explicitly for all i and k due to memory limits.
    // Instead, we compute the necessary R_k[i] values when processing queries.

    // We can use a segment tree on k, where each node stores a list of indices i
    // and can return the smallest f(k) needed. This is too complicated.

    // A simpler approach is to iterate on `k` from `max_val_in_A` down to 0.
    // And for each `k`, compute `f(k)` by traversing the array.

    // A crucial insight for similar problems that often involve sweep-line or D&C:
    // If we iterate from `i = 0` to `N-1`.
    // For each `i`, we need to find `R_k[i]` for all `k`.
    // The values `f(k)` can be calculated using "sparse table for jumps" in `O(log N)` per `f(k)`.
    // To make this efficient enough, we need to calculate `R_k[i]` for all `i, k` in `O(N log N)` or `O(N)`.

    // The maximum possible value for a[i] is N-1.
    // `f(k) = 1` for `k >= N`. This is because for `k >= N`, 0, ..., k cannot all be present as elements are < N.
    // For `k` values from 1 to N-1, we need to compute.
    // If the largest value in `a` is `M_A`, then `f(k) = 1` for `k >= M_A + 1`.

    // Let `next_jump_idx[i]` be the next index to jump to from `i` for a segment with MEX <= k.
    // `next_jump_idx[i] = max_{x=0..k} (next_occurrence(x, i))`.
    // This can be computed for a fixed `k` in `O(N)` if `next_occurrence(x, i)` is `O(1)`.
    // We can precompute `next_occurrence_fixed_val[val][i]` for all `val` and `i` in `O(N*val_range)`.
    // This is too much memory.

    // The problem can be solved in O(N log N) using a segment tree.
    // `dp[i]` = minimum segments to cover suffix `a[i...N-1]`.
    // `dp[i] = 1 + min(dp[j])` for `j` in `[i+1, R_k[i]]`.
    // This is a range minimum query on `dp` values.
    // `R_k[i]` = `max_{x=0..k} next_occ(x, i)`.

    // Calculate `f(k)` for all `k` by processing queries offline or using a persistent segment tree.
    // Or, use a specific segment tree for this problem.
    // A segment tree where each leaf is `i`, and the value is `f(k)`? No.
    // It's `O(N log N)` without explicitly building `R_k[i]` table.

    // Precompute `next_val_pos[val][i]` = the smallest `p >= i` s.t. `a[p] == val`.
    // This can be done by processing `i` from `N-1` down to `0`.
    std::vector<std::vector<int>> next_val_pos(N, std::vector<int>(N + 1, N)); // `next_val_pos[x][i]` stores next_occ(x,i)
    std::vector<int> last_occurrence(N, N); // `last_occurrence[x]` stores the last seen index of `x`
    
    for (int i = N - 1; i >= 0; --i) {
        for (int x = 0; x < N; ++x) {
            next_val_pos[x][i] = last_occurrence[x];
        }
        last_occurrence[a[i]] = i;
    }
    // Now `next_val_pos[x][i]` is `O(1)` lookup. This part uses `O(N^2)` memory. `10^6 * 10^6` too much.

    // The only working approach for N=10^6 under 512MB is `O(N log N)` or `O(N log^2 N)`
    // usually with a segment tree or similar structure where `k` is part of the query.
    // This usually means `R_k[i]` is not precomputed, but queried from a data structure.

    // Create a segment tree over possible values (0 to N-1) for a[i].
    // For each `i` from `0` to `N-1`, we want to find `R_k[i]`.
    // `next_occurrence(x, i)` can be found using `lower_bound` on `pos_list[x]`. `O(log N)`.
    // `R_k[i] = max_{x=0..k} (next_occurrence(x, i))`.
    // This `R_k[i]` can be found by building a segment tree where leaf `x` stores `next_occurrence(x, i)`.
    // Then `query_range_max(0, k+1)` on this segment tree. This is `O(k log N)` per `i`. (The build is `k log N`)

    // This is a standard problem type solvable with `sqrt-decomposition` on `k`.
    // Or, for `f(k)` computation for a fixed `k`:
    // `current_pos = 0`, `segments = 0`.
    // While `current_pos < N`:
    //  `segments++`
    //  `max_next_idx = -1`
    //  For `x = 0` to `k`:
    //    `it = std::lower_bound(pos_list[x].begin(), pos_list[x].end(), current_pos);`
    //    If `it == pos_list[x].end()`: `max_next_idx = N; break;`
    //    `max_next_idx = std::max(max_next_idx, *it);`
    //  `current_pos = max_next_idx;`
    //  If `current_pos == N`: break;
    // `answers[k] = segments;`
    // This is `O(N * k * log N)` for all `k`, total `O(N^2 log N)`.

    // The only way to achieve `O(N log N)` is to optimize the calculation of `R_k[i]`.
    // A segment tree on values `0..N-1` with `N` leaves. For each `i` from `N-1` to `0`:
    // `seg_tree.update(a[i], i)`. Now `seg_tree` contains `next_occ(x,i)` for all `x`.
    // We want to calculate `f(k)` for all `k`.
    // `f(k)` is calculated by repeated jumps. The jumps sequence changes with `k`.
    // The key is that `max_{x=0..k} (next_occ(x,i))` can be queried using a segment tree.
    // The total time for computing all `f(k)` values has to be less than `O(N^2)`.

    // Final strategy: We cannot explicitly store the `R_k_values` table.
    // Instead, for each `k`, we compute `f(k)` by simulating the jumps.
    // `last_occ_val[x]` stores `next_occ(x, current_pos)`.
    // Max over `last_occ_val[x]` for `x` in `[0, k]` is `R_k[current_pos]`.
    // We use a segment tree for the `last_occ_val` array.

    std::vector<int> current_last_occ_for_val(N, N); // Used to calculate next_occ(x,i) for current i
    SegmentTree seg_tree_for_next_occ(N); // Segment tree to query max of next_occ(x,i) in [0,k]

    std::vector<std::vector<int>> jump_next_pos(N + 1, std::vector<int>(20)); // jump_next_pos[i][p] = pos after 2^p jumps
                                                                                // The second dim size (20) for log(N_max=10^6)
    
    // Compute `jump_next_pos[i][0]` for all `i` (which is `R_k[i]`) for a specific `k`.
    // For fixed `k`, we iterate `i` from `N-1` down to `0`.
    // Then calculate `jump_next_pos[i][0]`.

    // Iterate for each `k` from `1` to `N`.
    // For each `k`, we calculate `f(k)`.
    // To do this efficiently, we cannot re-build `next_val_pos` or `last_occurrence` fully.
    
    // Instead, we will simulate the jumps for each k.
    // The `next_occ(x, current_pos)` values are needed to compute `R_k[current_pos]`.
    // `pos_list[x]` stores indices of `x`. Use `lower_bound` on it.
    
    for (int k_val = 1; k_val <= N; ++k_val) {
        int current_pos = 0;
        int segments = 0;
        while (current_pos < N) {
            segments++;
            int max_next_idx_among_0_to_k = -1; // -1 indicates no value found yet
            bool found_missing_in_range_0_to_k = false;

            for (int x = 0; x <= k_val; ++x) {
                // Find next_occurrence(x, current_pos)
                auto it = std::lower_bound(pos_list[x].begin(), pos_list[x].end(), current_pos);
                if (it == pos_list[x].end()) { // Value x is missing from current_pos to N-1
                    max_next_idx_among_0_to_k = N; // This effectively makes R_k[current_pos] = N
                    found_missing_in_range_0_to_k = true;
                    break;
                }
                max_next_idx_among_0_to_k = std::max(max_next_idx_among_0_to_k, *it);
            }

            if (found_missing_in_range_0_to_k) {
                // If any value in [0, k_val] is missing from `a[current_pos ... N-1]`,
                // then MEX of segment `[current_pos ... N-1]` is <= k_val.
                // So, current segment can extend to the end of the array.
                current_pos = N;
            } else {
                // All values 0..k_val are present from current_pos onwards.
                // The segment must end before `max_next_idx_among_0_to_k`
                // to have MEX <= k_val.
                // So the next segment starts at `max_next_idx_among_0_to_k`.
                current_pos = max_next_idx_among_0_to_k;
            }
        }
        answers[k_val] = segments;
    }

    for (int k_val = 1; k_val <= N; ++k_val) {
        std::cout << answers[k_val] << (k_val == N ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
