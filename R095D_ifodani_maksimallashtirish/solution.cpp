#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

// Sparse Table for Range Bitwise AND Query
// LOGN_MAX is ceil(log2(N)) for max N. For N = 10^5, log2(10^5) approx 16.6, so 17 is enough.
const int LOGN_MAX = 17;
std::vector<std::vector<int>> st;
std::vector<int> log_table;
int n_st;

void build_sparse_table(const std::vector<int>& a) {
    n_st = a.size();
    if (n_st == 0) return;

    log_table.assign(n_st + 1, 0);
    log_table[1] = 0;
    for (int i = 2; i <= n_st; i++) {
        log_table[i] = log_table[i/2] + 1;
    }

    st.assign(n_st, std::vector<int>(LOGN_MAX + 1));
    for (int i = 0; i < n_st; i++) {
        st[i][0] = a[i];
    }

    for (int j = 1; j <= LOGN_MAX; j++) {
        for (int i = 0; i + (1 << j) <= n_st; i++) {
            st[i][j] = st[i][j-1] & st[i + (1 << (j-1))][j-1];
        }
    }
}

// Queries the bitwise AND of elements in range [l, r] (0-indexed, inclusive).
// Returns ~0u (all bits set) if the range is empty (l > r).
int query_sparse_table(int l, int r) {
    if (l > r) return ~0u; // Empty range for bitwise AND operation (identity element)
    // l and r should be valid indices given how this function is called (e.g., 0 to n-1)
    // If l or r are out of actual array bounds [0, n_st-1] and l<=r, it implies the sparse table wasn't built for that size.
    // However, for this problem, l and r are always derived from 0..n-1 range, so no need for more checks.
    int j = log_table[r - l + 1];
    return st[l][j] & st[r - (1 << j) + 1][j];
}

// Helper to get the actual AND value for a segment for sum calculation.
// Returns 0 if segment is logically empty (should contribute 0 to sum).
int get_actual_segment_and_value_for_sum(int l, int r, int total_n) {
    if (l >= total_n || r < 0 || l > r) return 0; // Empty segment contribution is 0
    return query_sparse_table(l, r);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    build_sparse_table(a);

    // p_orig_for_sum[k] stores the AND of a[0]...a[k-1]. p_orig_for_sum[0]=0 for empty prefix.
    std::vector<int> p_orig_for_sum(n + 1);
    p_orig_for_sum[0] = 0; 
    for (int i = 0; i < n; ++i) {
        p_orig_for_sum[i+1] = get_actual_segment_and_value_for_sum(0, i, n);
    }

    // s_orig_for_sum[k] stores the AND of a[k]...a[n-1]. s_orig_for_sum[n]=0 for empty suffix.
    std::vector<int> s_orig_for_sum(n + 1);
    s_orig_for_sum[n] = 0; 
    for (int i = n - 1; i >= 0; --i) {
        s_orig_for_sum[i] = get_actual_segment_and_value_for_sum(i, n - 1, n);
    }

    long long max_val = 0;

    // Case 1: No operation (a[i_idx] = a[j_idx] is not performed)
    // k_split represents the index of the first element in the second part.
    // First part is a[0]...a[k_split-1], second part is a[k_split]...a[n-1].
    for (int k_split = 0; k_split <= n; ++k_split) {
        long long current_sum = (long long)p_orig_for_sum[k_split] + s_orig_for_sum[k_split];
        max_val = std::max(max_val, current_sum);
    }
    
    // Case 2: One operation a[i_idx] = a[j_idx] is performed.
    // Identify critical i_idx candidates: indices where prefix/suffix AND values change.
    std::set<int> i_idx_candidate_set;
    i_idx_candidate_set.insert(0);
    i_idx_candidate_set.insert(n - 1);
    
    int current_prefix_and_val = ~0u; // Equivalent to query_sparse_table(0, -1)
    for (int i = 0; i < n; ++i) {
        int val = query_sparse_table(0, i);
        if (val != current_prefix_and_val) {
            i_idx_candidate_set.insert(i);
            current_prefix_and_val = val;
        }
    }
    int current_suffix_and_val = ~0u; // Equivalent to query_sparse_table(n, n-1)
    for (int i = n - 1; i >= 0; --i) {
        int val = query_sparse_table(i, n - 1);
        if (val != current_suffix_and_val) {
            i_idx_candidate_set.insert(i);
            current_suffix_and_val = val;
        }
    }
    
    std::vector<int> relevant_i_indices(i_idx_candidate_set.begin(), i_idx_candidate_set.end());

    // Identify critical k_split candidates: split points where prefix/suffix AND values change.
    std::set<int> k_split_candidate_set;
    k_split_candidate_set.insert(0);
    k_split_candidate_set.insert(n);
    
    current_prefix_and_val = ~0u;
    for (int k = 1; k <= n; ++k) { // k is k_split
        int val = query_sparse_table(0, k-1);
        if (val != current_prefix_and_val) {
            k_split_candidate_set.insert(k);
            current_prefix_and_val = val;
        }
    }
    current_suffix_and_val = ~0u;
    for (int k = n - 1; k >= 0; --k) { // k is k_split
        int val = query_sparse_table(k, n - 1);
        if (val != current_suffix_and_val) {
            k_split_candidate_set.insert(k);
            current_suffix_and_val = val;
        }
    }

    std::vector<int> relevant_k_splits(k_split_candidate_set.begin(), k_split_candidate_set.end());

    // All distinct values in 'a' to consider for replacement (val_to_insert = a[j_idx])
    std::set<int> distinct_a_values_set(a.begin(), a.end());
    std::vector<int> unique_a_values(distinct_a_values_set.begin(), distinct_a_values_set.end());

    for (int i_idx : relevant_i_indices) { // The index whose value a[i_idx] is changed
        if (i_idx < 0 || i_idx >= n) continue; // Boundary check, though relevant_i_indices should be within bounds

        for (int k_split : relevant_k_splits) { // The split point k
            int mask_for_inserted_val = ~0u;
            long long other_part_and_val;

            if (k_split <= i_idx) { // a[i_idx] is in the second part (a[k_split]...a[n-1])
                // Modified part is second part. It becomes (prefix_before_i_in_second_part) & val_to_insert & (suffix_after_i_in_second_part)
                // The mask for val_to_insert is (prefix_before_i_in_second_part) & (suffix_after_i_in_second_part)
                int prefix_before_i_in_second_part = query_sparse_table(k_split, i_idx - 1);
                int suffix_after_i_in_second_part = query_sparse_table(i_idx + 1, n - 1);
                mask_for_inserted_val = prefix_before_i_in_second_part & suffix_after_i_in_second_part;

                // Other part (first part) is original a[0]...a[k_split-1]
                other_part_and_val = p_orig_for_sum[k_split];

            } else { // a[i_idx] is in the first part (a[0]...a[k_split-1])
                // Modified part is first part. It becomes (prefix_before_i_in_first_part) & val_to_insert & (suffix_after_i_in_first_part)
                // The mask for val_to_insert is (prefix_before_i_in_first_part) & (suffix_after_i_in_first_part)
                int prefix_before_i_in_first_part = query_sparse_table(0, i_idx - 1);
                int suffix_after_i_in_first_part = query_sparse_table(i_idx + 1, k_split - 1);
                mask_for_inserted_val = prefix_before_i_in_first_part & suffix_after_i_in_first_part;

                // Other part (second part) is original a[k_split]...a[n-1]
                other_part_and_val = s_orig_for_sum[k_split];
            }

            // Find the maximum value of (mask_for_inserted_val & val) for any 'val' in unique_a_values
            int max_and_with_val_to_insert = 0;
            for (int val_to_insert : unique_a_values) {
                max_and_with_val_to_insert = std::max(max_and_with_val_to_insert, mask_for_inserted_val & val_to_insert);
            }
            max_val = std::max(max_val, other_part_and_val + max_and_with_val_to_insert);
        }
    }

    std::cout << max_val << std::endl;

    return 0;
}
