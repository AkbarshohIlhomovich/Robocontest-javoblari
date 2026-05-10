#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For CHAR_BIT for safe __builtin_clz usage

// Custom log2_int function for positive integers that are powers of 2.
// This is an optimized way to calculate log base 2 for powers of 2 using
// GCC/Clang's __builtin_clz (count leading zeros) intrinsic.
// It avoids potential floating-point inaccuracies of std::log2 for integer results.
int log2_int(int n) {
    // For 32-bit integers, (sizeof(int) * CHAR_BIT - 1) is 31.
    // __builtin_clz(n) counts leading zeros in the binary representation of n.
    // Example: n=1 (0...01), __builtin_clz(1)=31. log2(1) = 0. So 31-31 = 0.
    // Example: n=2 (0...10), __builtin_clz(2)=30. log2(2) = 1. So 31-30 = 1.
    return (sizeof(int) * CHAR_BIT - 1) - __builtin_clz(n);
}

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
}

// Max N is 131072. Using 1-indexed array, so N+5 size for safety.
const int MAX_ARRAY_SIZE = 131072 + 5;
int a[MAX_ARRAY_SIZE];

// Segment tree node structure
// max_len: Maximum length of a sorted subsegment (power of 2) found within this node's range
// is_sorted: True if the entire range covered by this node is sorted
struct Node {
    int max_len;
    bool is_sorted;
};

// Segment tree array. 4 * MAX_ARRAY_SIZE is a common safe upper bound for segment tree size.
Node tree[4 * MAX_ARRAY_SIZE];

// Function to build the segment tree
// v: current node index in tree array
// tl, tr: current node's range [tl, tr]
void build(int v, int tl, int tr) {
    if (tl == tr) {
        // Leaf node: a single element is always sorted, and its max_len is 1 (2^0).
        tree[v] = {1, true};
    } else {
        int tm = (tl + tr) / 2; // Midpoint
        // Recursively build left and right children
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

        // Combine results from children
        // The maximum sorted length found in this node's range is the maximum of
        // the max_len from its children.
        tree[v].max_len = std::max(tree[2 * v].max_len, tree[2 * v + 1].max_len);
        
        // The current node's entire range [tl, tr] is sorted if both its children's ranges
        // are sorted AND the element at the split point (a[tm]) is less than or equal to the next element (a[tm+1]).
        tree[v].is_sorted = tree[2 * v].is_sorted && tree[2 * v + 1].is_sorted && (a[tm] <= a[tm + 1]);

        // If the entire range [tl, tr] is found to be sorted, then its length (tr - tl + 1)
        // is also a candidate for max_len. This represents 0 operations to sort this segment.
        if (tree[v].is_sorted) {
            tree[v].max_len = std::max(tree[v].max_len, tr - tl + 1);
        }
    }
}

// Function to query the segment tree for a given range [ql, qr]
// v: current node index
// tl, tr: current node's full range [tl, tr]
// ql, qr: query range [ql, qr]
// Returns a Node structure containing max_len and is_sorted for the query range
Node query(int v, int tl, int tr, int ql, int qr) {
    // If the query range is empty or completely outside the current node's range,
    // return a base case: max_len 0, vacuously sorted.
    if (ql > qr || tl > qr || tr < ql) {
        return {0, true};
    }
    // If the current node's range fully covers the query range,
    // return the precomputed values from this node.
    if (ql == tl && qr == tr) {
        return tree[v];
    }

    int tm = (tl + tr) / 2; // Midpoint of current node's range

    // Recursively query the left and right children.
    // The query ranges for children are clipped to ensure they stay within [tl, tm] and [tm+1, tr].
    Node left_res = query(2 * v, tl, tm, ql, std::min(qr, tm));
    Node right_res = query(2 * v + 1, tm + 1, tr, std::max(ql, tm + 1), qr);

    Node current_res;
    // The maximum length of a sorted segment in the combined query range
    // is the maximum of the maximum lengths found in its left and right parts.
    current_res.max_len = std::max(left_res.max_len, right_res.max_len);
    
    // The query range [ql, qr] is considered sorted if both its left and right parts are sorted.
    current_res.is_sorted = left_res.is_sorted && right_res.is_sorted;

    // Additionally, if the query range [ql, qr] spans across the midpoint (tm and tm+1 are both within ql...qr),
    // we must check if a[tm] <= a[tm+1] to determine if the entire query range [ql, qr] is truly sorted.
    // This condition `ql <= tm && tm + 1 <= qr` precisely checks if the split point `tm, tm+1`
    // is included in the current effective query range `[ql, qr]`.
    if (ql <= tm && tm + 1 <= qr) {
        current_res.is_sorted = current_res.is_sorted && (a[tm] <= a[tm + 1]);
    }

    // If the entire query range [ql, qr] is found to be sorted (current_res.is_sorted is true),
    // then its length (qr - ql + 1) is also a candidate for the maximum sorted length.
    // This represents a scenario where 0 Thanos sort operations are needed for this specific segment.
    current_res.max_len = std::max(current_res.max_len, current_res.is_sorted ? (qr - ql + 1) : 0);
    
    return current_res;
}

int main() {
    fast_io(); // Enable fast I/O

    int N, Q;
    std::cin >> N >> Q;

    for (int i = 1; i <= N; ++i) { // Read array elements (1-indexed)
        std::cin >> a[i];
    }

    // Build the segment tree for the entire array from index 1 to N
    build(1, 1, N);

    for (int k = 0; k < Q; ++k) {
        int l, r;
        std::cin >> l >> r;

        // Query the segment tree for the specific range [l, r]
        Node result = query(1, 1, N, l, r);

        // The initial length of the queried subarray (guaranteed to be a power of 2)
        int initial_len = r - l + 1;
        
        // The maximum length of a sorted subarray that can be achieved by Thanos sort
        // within the range [l, r]. This value is also guaranteed to be a power of 2
        // (minimum 1, representing a single sorted element).
        int final_sorted_len = result.max_len;

        // The number of operations is the difference in log2 of the initial and final lengths.
        // We use the custom log2_int function for robustness.
        int initial_len_log = log2_int(initial_len);
        int final_sorted_len_log = log2_int(final_sorted_len);

        std::cout << initial_len_log - final_sorted_len_log << "\n";
    }

    return 0;
}
