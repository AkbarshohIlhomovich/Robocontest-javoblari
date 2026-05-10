#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // For std::pair

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> intervals;
    intervals.reserve(M);

    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        
        // A conflict between cities u and v requires breaking one of the bridges
        // on the path between them.
        // Bridges are numbered by their left endpoint: bridge k connects city k and city k+1.
        // If u < v, the path involves bridges (u, u+1), (u+1, u+2), ..., (v-1, v).
        // The indices of these bridges are u, u+1, ..., v-1.
        // This corresponds to an interval of bridge indices [min(u,v), max(u,v) - 1].
        int left_bridge_idx = std::min(u, v);
        int right_bridge_idx = std::max(u, v) - 1;
        intervals.push_back({left_bridge_idx, right_bridge_idx});
    }

    // Sort intervals primarily by their right endpoints.
    // If right endpoints are equal, sort by left endpoints for deterministic behavior (not strictly necessary for correctness).
    std::sort(intervals.begin(), intervals.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    int broken_bridges_count = 0;
    // Stores the index of the rightmost bridge broken so far.
    // Initialize to 0, since valid bridge indices start from 1.
    // This ensures that the first interval will always trigger a new bridge to be broken.
    int last_broken_bridge_pos = 0; 

    for (const auto& interval : intervals) {
        // If the current interval's left endpoint is greater than the last broken bridge's position,
        // it means this interval is not covered by any previously broken bridge.
        // Therefore, we must break a new bridge.
        if (interval.first > last_broken_bridge_pos) {
            broken_bridges_count++;
            // To cover the current interval and potentially as many subsequent intervals as possible,
            // we break the bridge at the current interval's rightmost possible position.
            last_broken_bridge_pos = interval.second;
        }
    }

    std::cout << broken_bridges_count << std::endl;

    return 0;
}
