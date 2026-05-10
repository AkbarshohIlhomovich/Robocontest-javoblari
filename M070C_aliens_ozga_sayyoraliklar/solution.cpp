#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

const int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> grid(N);
    std::vector<std::vector<int>> dist_tree(N, std::vector<int>(M, INF));
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < N; ++i) {
        std::cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'T') {
                dist_tree[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        std::pair<int, int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (dist_tree[nr][nc] > dist_tree[r][c] + 1) {
                    dist_tree[nr][nc] = dist_tree[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int max_k = 0;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (grid[r][c] == '.') {
                int k_boundary = std::min({r, N - 1 - r, c, M - 1 - c});
                int current_k = std::min(k_boundary, dist_tree[r][c] - 1);
                if (current_k < 0) { // Should not happen for empty cells but a safeguard
                    current_k = 0;
                }
                max_k = std::max(max_k, current_k);
            }
        }
    }
    
    long long result_stones = 2LL * max_k * max_k + 2LL * max_k + 1LL;
    std::cout << result_stones << std::endl;

    return 0;
}
