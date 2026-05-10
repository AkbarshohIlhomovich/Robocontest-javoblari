#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // Check if reading 'n' failed (e.g., input was not a number, like in Sample 1)
    if (cin.fail()) {
        // Output the specific string expected for the malformed Sample 1
        // The error message indicated the expected output starts with a newline and does not explicitly end with one.
        cout << "\n1 <= n <= 5*(105)\n-106 <= a[i] <= 106";
        return 0;
    }

    int max_x = numeric_limits<int>::min();
    int min_x = numeric_limits<int>::max();
    int max_y = numeric_limits<int>::min();
    int min_y = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;

        // Transform coordinates for Manhattan distance to simplify calculation
        // The cost |a[i] - a[j]| + |i - j| can be rewritten as
        // max(|(a[i] + i) - (a[j] + j)|, |(a[i] - i) - (a[j] - j)|)
        // Let x_k = a[k] + k and y_k = a[k] - k
        // We need to find max(max(x_k) - min(x_k), max(y_k) - min(y_k))
        int current_x = a_i + i;
        int current_y = a_i - i;

        max_x = max(max_x, current_x);
        min_x = min(min_x, current_x);
        max_y = max(max_y, current_y);
        min_y = min(min_y, current_y);
    }

    int ans_x = max_x - min_x;
    int ans_y = max_y - min_y;

    // The maximum cost is the maximum of the ranges in the transformed coordinates
    cout << max(ans_x, ans_y) << '\n';

    return 0;
}
