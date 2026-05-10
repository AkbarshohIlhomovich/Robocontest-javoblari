#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long N;
    int Q;
    std::cin >> N >> Q;

    // diff_map stores (index, delta_value).
    // A[i] is the sum of all delta_values for keys <= i.
    // Range updates [L, R] by V are translated to diff_map[L] += V and diff_map[R+1] -= V.
    std::map<long long, long long> diff_map;

    for (int i = 0; i < Q; ++i) {
        int T;
        long long X, Y;
        std::cin >> T >> X >> Y;
        if (T == 1) {
            // Increment the first X elements by Y.
            // This affects elements A[0], A[1], ..., A[X-1].
            diff_map[0] += Y;
            diff_map[X] -= Y; // At index X, the increment stops.
        } else {
            // Decrement the last X elements by Y.
            // This affects elements A[N-X], A[N-X+1], ..., A[N-1].
            // The starting index is N-X.
            diff_map[N - X] -= Y;
            diff_map[N] += Y; // At index N, the decrement stops (exclusive upper bound).
        }
    }

    long long current_cumulative_value = 0;
    long long max_absolute_value = 0;

    // Iterate through the map, which automatically processes keys in increasing order.
    // Each 'entry' marks a point where the value potentially changes.
    // The 'current_cumulative_value' before updating it with 'delta' represents
    // the value of all array elements in the segment from the previous key up to 'index - 1'.
    for (auto const& entry : diff_map) {
        long long index = entry.first;
        long long delta = entry.second;

        // Before updating current_cumulative_value with the current delta,
        // the current_cumulative_value represents the value for the segment
        // ending at 'index - 1'. We must consider this value for max_absolute_value.
        // We only care about elements within the array bounds [0, N-1].
        // The initial current_cumulative_value (0) covers indices < 0.
        // If 'index' is within [0, N-1], the segment 'prev_index' to 'index-1' contributes.
        // If 'index' is 'N', it means the segment from 'prev_index' to 'N-1' has 'current_cumulative_value'.
        // This is exactly what we need.
        max_absolute_value = std::max(max_absolute_value, std::abs(current_cumulative_value));
        
        // Update current_cumulative_value for the next segment.
        current_cumulative_value += delta;
    }
    // After the loop, the current_cumulative_value will reflect the sum up to (and including changes at)
    // the largest key in the map. The max_absolute_value will have correctly captured
    // the absolute values of all segments within the array [0, N-1].
    // If N is the largest key, current_cumulative_value has just been updated based on the delta at N.
    // The max_absolute_value for the segment A[prev_index]..A[N-1] would have been taken before this update.

    std::cout << max_absolute_value << std::endl;

    return 0;
}
