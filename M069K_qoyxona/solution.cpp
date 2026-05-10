#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    std::vector<int> adj(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> adj[i];
    }

    std::vector<int> color(N + 1, 0); 
    int cycles_count = 0;

    for (int i = 1; i <= N; ++i) {
        if (color[i] == 0) {
            int current_node = i;
            std::vector<int> path; 

            while (color[current_node] == 0) {
                color[current_node] = 1; 
                path.push_back(current_node);
                current_node = adj[current_node];
            }

            if (color[current_node] == 1) {
                cycles_count++;
            }
            
            for (int node : path) {
                color[node] = 2;
            }
        }
    }

    std::cout << cycles_count << std::endl;

    return 0;
}
