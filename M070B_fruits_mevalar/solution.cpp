#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

// Segment tree node structure for storing minimum values
std::vector<int> segment_tree_data;
// Stores left_max_P values for each index of the P array.
// This array will be used as the base for the segment tree.
std::vector<int> left_max_P_values; 
int N_plus_1_size; // Represents N+1, the size of P array

// Function to build the segment tree
// node_idx: current node in the segment tree
// start, end: range of indices in left_max_P_values covered by this node
void build(int node_idx, int start, int end) {
    if (start == end) {
        // Leaf node, store the value directly
        segment_tree_data[node_idx] = left_max_P_values[start];
    } else {
        // Internal node, recursively build children and store the minimum of their values
        int mid = (start + end) / 2;
        build(2 * node_idx, start, mid);
        build(2 * node_idx + 1, mid + 1, end);
        segment_tree_data[node_idx] = std::min(segment_tree_data[2 * node_idx], segment_tree_data[2 * node_idx + 1]);
    }
}

// Function to query the segment tree for the largest R_idx
// node_idx: current node in the segment tree
// start, end: range of indices in left_max_P_values covered by this node
// query_L, query_R: the query range for R_idx
// threshold: L_idx value, used to check `left_max_P_values[R_idx] < threshold`
int query_max_idx(int node_idx, int start, int end, int query_L, int query_R, int threshold) {
    // If the current segment range is entirely outside the query range,
    // or if all values in the current segment are >= threshold (meaning no R_idx satisfies condition),
    // return -1 (indicating no such R_idx found)
    if (start > query_R || end < query_L || segment_tree_data[node_idx] >= threshold) {
        return -1;
    }

    // If it's a leaf node, and it passed the threshold check, then this `start` index is a candidate R_idx
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    int res = -1;

    // To find the LARGEST R_idx, we prioritize searching the right child first
    // Check if the right child's range overlaps with the query range
    if (mid + 1 <= query_R) { 
        res = query_max_idx(2 * node_idx + 1, mid + 1, end, query_L, query_R, threshold);
    }
    
    // If an R_idx was found in the right child, return it
    if (res != -1) {
        return res;
    }

    // If not found in the right child, search the left child
    // Check if the left child's range overlaps with the query range
    if (mid >= query_L) {
        res = query_max_idx(2 * node_idx, start, mid, query_L, query_R, threshold);
    }
    
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    N_plus_1_size = N + 1;

    // P array stores prefix sums: P[k] = sum(S[0]...S[k-1]). P[0] = 0.
    // So P has N+1 elements, P[0] to P[N].
    std::vector<int> P(N_plus_1_size);
    P[0] = 0;
    for (int k = 0; k < N; ++k) {
        P[k + 1] = P[k] + (S[k] == 'a' ? 1 : -1);
    }

    // right_min_P[k]: stores the index of the first element to the right of k (strictly > k)
    // whose value in P is strictly less than P[k]. If no such element, stores N_plus_1_size.
    std::vector<int> right_min_P(N_plus_1_size);
    std::stack<int> st;
    for (int k = N; k >= 0; --k) {
        while (!st.empty() && P[st.top()] >= P[k]) {
            st.pop();
        }
        right_min_P[k] = st.empty() ? N_plus_1_size : st.top();
        st.push(k);
    }

    // left_max_P_values[k]: stores the index of the first element to the left of k (strictly < k)
    // whose value in P is strictly greater than P[k]. If no such element, stores -1.
    left_max_P_values.resize(N_plus_1_size); 
    while (!st.empty()) st.pop(); // Clear stack for reuse
    for (int k = 0; k < N_plus_1_size; ++k) {
        while (!st.empty() && P[st.top()] <= P[k]) {
            st.pop();
        }
        left_max_P_values[k] = st.empty() ? -1 : st.top();
        st.push(k);
    }
    
    // Initialize and build the segment tree over indices [0, N] (N+1 elements)
    segment_tree_data.resize(4 * N_plus_1_size);
    build(1, 0, N);

    int max_len = 0;

    // Iterate through all possible starting points (L_idx) for the P-array segment.
    // L_idx corresponds to 'i' in the original string segment S[i...j].
    // R_idx corresponds to 'j+1' in the original string segment S[i...j].
    // The length of the original segment S[i...j] is (j+1) - i = R_idx - L_idx.
    for (int L_idx = 0; L_idx < N_plus_1_size; ++L_idx) {
        // Condition 1: P[L_idx] must be the minimum value in P[L_idx...R_idx].
        // This means no element P[x] in (L_idx, R_idx] should be strictly smaller than P[L_idx].
        // So, the first index 'x' to the right of L_idx such that P[x] < P[L_idx] must be > R_idx.
        // Thus, R_idx must be less than right_min_P[L_idx].
        int query_L_for_R_idx = L_idx + 1; // R_idx must be strictly greater than L_idx
        int query_R_for_R_idx = right_min_P[L_idx] - 1; // R_idx must be strictly less than right_min_P[L_idx]

        // If the calculated range for R_idx is invalid, continue to next L_idx
        if (query_L_for_R_idx > query_R_for_R_idx) { 
            continue;
        }
        
        // Condition 2: P[R_idx] must be the maximum value in P[L_idx...R_idx].
        // This means no element P[x] in [L_idx, R_idx) should be strictly greater than P[R_idx].
        // So, the first index 'x' to the left of R_idx such that P[x] > P[R_idx] must be < L_idx.
        // We use the segment tree to find the largest R_idx in [query_L_for_R_idx, query_R_for_R_idx]
        // that satisfies left_max_P_values[R_idx] < L_idx.
        int R_found = query_max_idx(1, 0, N, query_L_for_R_idx, query_R_for_R_idx, L_idx);

        if (R_found != -1) {
            max_len = std::max(max_len, R_found - L_idx);
        }
    }

    std::cout << max_len << std::endl;

    return 0;
}
