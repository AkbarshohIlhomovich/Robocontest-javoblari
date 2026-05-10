#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    std::vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    // `parents` will store parent[i] for node i. Node indices are 1-based.
    // The maximum possible number of nodes K is 2*N - 1.
    // For N=50000, K can be up to 99999.
    // We preallocate a vector of size 2*N + 1 to safely store up to K nodes (1-indexed).
    std::vector<int> parents(2 * N + 1);

    // `next_node_id` will assign node numbers sequentially, starting from 1.
    int next_node_id = 1;
    
    // `current_leaf_idx` tracks the index of the next leaf height to process from the input H array.
    // This index corresponds to the leftmost leaf in the current subtree being built.
    int current_leaf_idx = 0;

    // The stack stores tuples: (node_id, depth, state)
    // - `node_id`: The ID of the node currently being processed.
    // - `depth`: The depth of `node_id` (root is at depth 0).
    // - `state`: 
    //   - `0`: This node has just been pushed; we need to process its left child.
    //   - `1`: Its left child (and its entire subtree) has been processed; we now need to process its right child.
    std::stack<std::tuple<int, int, int>> s;

    // Create the root node. It's always node 1 at depth 0.
    int root_node_id = next_node_id++;
    parents[root_node_id] = 0; // The root has a parent of 0.
    s.push({root_node_id, 0, 0}); // Push the root onto the stack, ready to process its left child.

    while (!s.empty()) {
        // Use structured binding with references to modify the top element of the stack directly.
        auto& [curr_node_id, curr_depth, state] = s.top();

        if (state == 0) { // Current node `curr_node_id` is about to process its left child.
            // The left child would be at `curr_depth + 1`. We compare this with the depth of the next expected leaf `H[current_leaf_idx]`.
            if (curr_depth + 1 == H[current_leaf_idx]) {
                // If the next leaf's depth matches `curr_depth + 1`, then the left child of `curr_node_id` is itself a leaf.
                int left_child_id = next_node_id++;
                parents[left_child_id] = curr_node_id; // Assign parent.
                current_leaf_idx++;                   // This leaf has been placed, move to the next leaf in the input.
                state = 1;                            // Left child processed, now ready to process the right child.
            } else { // curr_depth + 1 < H[current_leaf_idx]
                // If the next leaf's depth is greater, it means the left child of `curr_node_id` must be an internal node.
                // We create this internal left child and then immediately dive into building its subtree.
                int left_child_id = next_node_id++;
                parents[left_child_id] = curr_node_id; // Assign parent.
                state = 1;                            // Mark current node as having processed its left child.
                                                      // Its right child will be processed after the entire subtree of `left_child_id` is completed.
                s.push({left_child_id, curr_depth + 1, 0}); // Push the new left child, ready to process *its* left child.
            }
        } else { // state == 1, Current node `curr_node_id` is about to process its right child.
            // The right child would be at `curr_depth + 1`. Compare this with the depth of the next expected leaf `H[current_leaf_idx]`.
            if (curr_depth + 1 == H[current_leaf_idx]) {
                // If the next leaf's depth matches `curr_depth + 1`, then the right child of `curr_node_id` is itself a leaf.
                int right_child_id = next_node_id++;
                parents[right_child_id] = curr_node_id; // Assign parent.
                current_leaf_idx++;                   // This leaf has been placed, move to the next leaf in the input.
                s.pop();                              // Both children of `curr_node_id` are processed, so pop it from the stack.
            } else { // curr_depth + 1 < H[current_leaf_idx]
                // If the next leaf's depth is greater, it means the right child of `curr_node_id` must be an internal node.
                // We create this internal right child and then immediately dive into building its subtree.
                int right_child_id = next_node_id++;
                parents[right_child_id] = curr_node_id; // Assign parent.
                s.pop();                              // `curr_node_id` has now conceptually had both children processed (even though the right child is internal).
                                                      // We immediately push the right child to process its subtree.
                s.push({right_child_id, curr_depth + 1, 0}); // Push the new right child, ready to process *its* left child.
            }
        }
    }

    // Output the total number of nodes K.
    // `next_node_id` was incremented one extra time after the last node was assigned an ID.
    std::cout << next_node_id - 1 << std::endl;

    // Output the parents array for nodes 1 to K.
    for (int i = 1; i < next_node_id; ++i) {
        std::cout << parents[i] << (i == next_node_id - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
