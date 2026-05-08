#include <bits/stdc++.h>

// Function to solve a single test case
void solve() {
    int n, k;
    std::cin >> n >> k; // Read N and K for the current test case

    int current_pos = k; // Initialize the current position of the ball initially at K

    // The problem describes a sequence of reverse operations:
    // 1. Reverse the entire array (from index 0 to N-1).
    // 2. Then, reverse from position 1 to N-1.
    // 3. Then, reverse from position 2 to N-1.
    // ...
    // N. Finally, reverse from position N-1 to N-1 (which is a no-op).
    //
    // The loop variable 'i' represents the 'start_index' for each reverse operation.
    // The 'end_index' for all operations is always N-1.
    for (int i = 0; i < n; ++i) {
        int start_index = i;
        int end_index = n - 1;

        // Check if the ball we are tracking (at 'current_pos')
        // falls within the segment being reversed [start_index, end_index].
        if (current_pos >= start_index && current_pos <= end_index) {
            // If it does, apply the reverse transformation:
            // An element at position 'p' within the segment [start, end]
            // moves to a new position calculated as 'start + (end - p)'.
            current_pos = start_index + (end_index - current_pos);
        }
        // If 'current_pos' is outside the range [start_index, end_index],
        // its position does not change during this particular reverse operation.
    }
    
    std::cout << current_pos << std::endl; // Output the final position of the ball
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cin before every cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
