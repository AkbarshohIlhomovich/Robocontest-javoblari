#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int dfs_num[MAXN], low[MAXN], subtree_size[MAXN];
bool visited[MAXN];
long long ans[MAXN];
int timer;
int N_global; // N is used as a global variable to simplify DFS parameter passing

void dfs(int u, int p) {
    visited[u] = true;
    dfs_num[u] = low[u] = timer++;
    subtree_size[u] = 1;

    long long sum_of_nodes_in_isolated_subtrees = 0; // Sum of sizes of child subtrees that become separate components if 'u' is removed

    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }

        if (visited[v]) {
            // Back-edge or cross-edge to an already visited ancestor
            low[u] = min(low[u], dfs_num[v]);
        } else {
            // v is a child in the DFS tree
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
            low[u] = min(low[u], low[v]);

            if (low[v] >= dfs_num[u]) {
                // If low[v] >= dfs_num[u], then u is an articulation point (unless u is the root of the DFS tree).
                // Removing u separates v's subtree from the rest of the graph (or u's ancestors).
                // v's subtree forms a connected component of size subtree_size[v].
                // The flights within this component are still available. We subtract their count from ans[u].
                ans[u] -= (long long)subtree_size[v] * (subtree_size[v] - 1);
                sum_of_nodes_in_isolated_subtrees += subtree_size[v];
            }
        }
    }

    // After processing all neighbors of u.
    // If u is removed, the remaining nodes (N_global - 1) are split into:
    // 1. Several components formed by children's subtrees where low[v] >= dfs_num[u] (accounted for in the loop).
    // 2. One large component consisting of u's parent, ancestors, and any children subtrees for which low[v] < dfs_num[u].
    // The size of this "remaining" component is N_global - 1 - sum_of_nodes_in_isolated_subtrees.
    long long remaining_nodes_size = N_global - 1 - sum_of_nodes_in_isolated_subtrees;
    
    // If remaining_nodes_size is positive, this component also has internally available flights.
    // We subtract their count from ans[u].
    // This calculation also correctly handles the root of the DFS tree: if the root is an AP,
    // sum_of_nodes_in_isolated_subtrees will be N_global - 1 (assuming a connected graph),
    // making remaining_nodes_size 0. Then 0 * (-1) = 0 is subtracted, which is correct.
    // For a non-AP, sum_of_nodes_in_isolated_subtrees will be 0, making remaining_nodes_size N_global - 1.
    // The total result for non-APs simplifies to 2 * (N_global - 1).
    ans[u] -= remaining_nodes_size * (remaining_nodes_size - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int M;
    cin >> N_global >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize ans array. Initially, assume all N*(N-1) flights are available.
    // For each node u, we will subtract flights that *remain* available after removing u.
    // The final answer ans[u] will be total_flights - remaining_flights_after_removing_u.
    for (int i = 1; i <= N_global; ++i) {
        ans[i] = (long long)N_global * (N_global - 1);
    }
    
    // Run DFS. The problem constraints and typical interpretations imply a connected graph.
    // If N_global = 0 or 1, the formula N_global * (N_global - 1) yields 0, which is correct.
    // The DFS call handles N_global = 1 correctly.
    if (N_global > 0) { 
        dfs(1, -1); 
    }

    for (int i = 1; i <= N_global; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}
