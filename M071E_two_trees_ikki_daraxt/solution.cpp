#include <vector>
#include <algorithm>
#include <iostream>

const int MAXN = 300005; // Maximum number of nodes N <= 3 * 10^5

std::vector<int> adj1[MAXN]; // Adjacency list for Tree 1
std::vector<int> adj2[MAXN]; // Adjacency list for Tree 2

int tin1[MAXN]; // Entry time for nodes in Tree 1 DFS
int sz1[MAXN];  // Subtree size for nodes in Tree 1
int tin2[MAXN]; // Entry time for nodes in Tree 2 DFS
int sz2[MAXN];  // Subtree size for nodes in Tree 2
int timer_dfs;  // Global timer for DFS traversals

// DFS function to compute tin (entry time) and sz (subtree size) for a tree
// Changed the type of 'adj' parameter from `const std::vector<std::vector<int>>&` to `const std::vector<int> adj[]`
// to correctly accept a C-style array of std::vector<int>.
void dfs_tree(int u, int p, const std::vector<int> adj[], int tin[], int sz[]) {
    tin[u] = ++timer_dfs; // Assign unique entry time
    sz[u] = 1;            // Initialize subtree size to 1 (for node u itself)
    for (int v : adj[u]) {
        if (v == p) continue; // Skip parent to avoid infinite loops in undirected graph
        dfs_tree(v, u, adj, tin, sz); // Recursively call DFS for children
        sz[u] += sz[v];              // Add child's subtree size to current node's subtree size
    }
}

// Fenwick Tree (BIT) implementation
// Max coordinate for tin2 values is N. Using a 1-indexed BIT.
int bit[MAXN];
int bit_max_coord; // The maximum index used in the BIT

// Update operation: adds 'delta' to the element at 'idx'
void bit_update(int idx, int delta) {
    // Fenwick tree indices are 1-based.
    for (; idx <= bit_max_coord; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

// Query operation: gets the sum of elements from index 1 up to 'idx'
int bit_query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

// Structure to represent an event for the sweep-line algorithm
struct Event {
    int x;       // X-coordinate (corresponds to tin1 value)
    int type;    // 0: ADD_POINT, 1: QUERY (for inclusion-exclusion principle)
    int node_idx; // Node index (for query events, identifies which ans[node_idx] to update; -1 for ADD_POINT events)
    int y;       // Y-coordinate (corresponds to tin2 value for points, or Y-boundary for queries)
    int weight;  // +1 or -1 to add or subtract contributions

    // Custom comparison operator for sorting events
    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x; // Primary sort by X-coordinate
        return type < other.type;           // Secondary sort: process ADD_POINT (type 0) before QUERY (type 1)
                                            // This ensures points at current x are added to BIT before queries at current x are processed.
    }
};

long long ans[MAXN]; // Array to store the final answers for each node v

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, r1, r2;
    std::cin >> N >> r1 >> r2;

    bit_max_coord = N; // Max possible tin2 value will be N

    // Read parent array p1 and build adjacency list for Tree 1
    for (int i = 1; i <= N; ++i) {
        int p;
        std::cin >> p;
        if (p != -1) { // -1 indicates the root, which has no parent
            adj1[i].push_back(p);
            adj1[p].push_back(i);
        }
    }

    // Read parent array p2 and build adjacency list for Tree 2
    for (int i = 1; i <= N; ++i) {
        int p;
        std::cin >> p;
        if (p != -1) {
            adj2[i].push_back(p);
            adj2[p].push_back(i);
        }
    }

    // Perform DFS for Tree 1 to compute tin1 (entry times) and sz1 (subtree sizes)
    timer_dfs = 0;
    dfs_tree(r1, 0, adj1, tin1, sz1);
    
    // Perform DFS for Tree 2 to compute tin2 (entry times) and sz2 (subtree sizes)
    timer_dfs = 0; // Reset timer for the second DFS to get independent tin values for Tree 2
    dfs_tree(r2, 0, adj2, tin2, sz2);

    std::vector<Event> events;
    // Reserve space to potentially avoid reallocations.
    // N points and up to 4*N query components.
    events.reserve(N + 4 * N); 

    // Create ADD_POINT events for each node 'u'
    // Each node 'u' is treated as a point (tin1[u], tin2[u]) in a 2D plane.
    for (int i = 1; i <= N; ++i) {
        events.push_back({tin1[i], 0, -1, tin2[i], 1}); 
    }

    // Create QUERY events for each node 'v' using the 2D inclusion-exclusion principle.
    // We want to count points (tin1[u], tin2[u]) within the rectangle defined by:
    // [tin1[v], tin1[v] + sz1[v] - 1] x [tin2[v], tin2[v] + sz2[v] - 1]
    for (int i = 1; i <= N; ++i) {
        int X1 = tin1[i];             // Left X-boundary of the query rectangle
        int X2 = tin1[i] + sz1[i] - 1; // Right X-boundary of the query rectangle
        int Y1 = tin2[i];             // Bottom Y-boundary of the query rectangle
        int Y2 = tin2[i] + sz2[i] - 1; // Top Y-boundary of the query rectangle

        // The count of points P_u=(x_u, y_u) in [X1, X2]x[Y1, Y2] is:
        // f(X2, Y2) - f(X1-1, Y2) - f(X2, Y1-1) + f(X1-1, Y1-1)
        // where f(X, Y) = count(x_u <= X AND y_u <= Y)

        events.push_back({X2, 1, i, Y2, 1}); // +f(X2, Y2)
        
        // Ensure X1-1 is non-negative, as tin values are 1-indexed.
        // An X-coordinate of 0 conceptually means 'before the first actual tin1 value'.
        if (X1 - 1 >= 0) 
            events.push_back({X1 - 1, 1, i, Y2, -1}); // -f(X1-1, Y2)
        
        // Ensure Y1-1 is non-negative for the same reason.
        if (Y1 - 1 >= 0) 
            events.push_back({X2, 1, i, Y1 - 1, -1}); // -f(X2, Y1-1)
        
        // Both X1-1 and Y1-1 must be valid.
        if (X1 - 1 >= 0 && Y1 - 1 >= 0)
            events.push_back({X1 - 1, 1, i, Y1 - 1, 1}); // +f(X1-1, Y1-1)
    }

    // Sort all events by x-coordinate, then by type
    std::sort(events.begin(), events.end());

    // Process events using the sweep-line and Fenwick tree
    for (const auto& event : events) {
        if (event.type == 0) { // ADD_POINT event
            // Add the point's Y-coordinate (tin2 value) to the Fenwick tree.
            // event.weight is +1 here.
            bit_update(event.y, event.weight);
        } else { // QUERY event
            // Query the Fenwick tree for the sum up to event.y, and apply the associated weight.
            // event.y here is a Y-boundary (Y2, Y1-1), and event.weight is +1 or -1.
            ans[event.node_idx] += 1LL * bit_query(event.y) * event.weight;
        }
    }

    // Output the results for each node from 1 to N
    for (int i = 1; i <= N; ++i) {
        std::cout << ans[i] << (i == N ? "" : " "); // Print space between numbers, no space after last
    }
    std::cout << std::endl;

    return 0;
}
