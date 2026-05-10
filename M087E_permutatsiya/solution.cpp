#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::max

std::string s;
bool visited[51]; // To keep track of numbers 1-50 that have been used. Indices 1 to 50 are used.
std::vector<int> result_permutation; // Stores the permutation elements found so far.

// idx: current index in the input string s
// max_val_so_far: the maximum number encountered in result_permutation so far
// num_elements_so_far: the count of numbers parsed and added to result_permutation
bool find_permutation(int idx, int max_val_so_far, int num_elements_so_far) {
    // Base case: If the entire string has been parsed.
    if (idx == s.length()) {
        // A valid permutation of 1 to N has exactly N elements, and the maximum element is N.
        // If max_val_so_far equals num_elements_so_far, it implies we have found
        // 'N' distinct numbers, and the largest among them is 'N'.
        // Since we only add numbers that are not yet visited, and within 1-50 range,
        // this condition guarantees that the collected numbers are exactly 1, 2, ..., N.
        if (max_val_so_far == num_elements_so_far) {
            for (size_t i = 0; i < result_permutation.size(); ++i) {
                std::cout << result_permutation[i] << (i == result_permutation.size() - 1 ? "" : " ");
            }
            std::cout << std::endl;
            return true; // Found a solution, propagate true upwards to stop further search
        }
        return false; // Not a valid permutation at the end of the string
    }

    // Pruning: If max_val_so_far exceeds 50, it's not a valid permutation
    // of numbers up to 50. (This can be implied by num1/num2 <= 50 checks below but doesn't hurt).
    // Or if num_elements_so_far exceeds 50.
    if (max_val_so_far > 50 || num_elements_so_far > 50) {
        return false;
    }

    // Try parsing a 1-digit number
    // Ensure 'idx' is within string bounds
    if (idx < s.length()) {
        int num1 = s[idx] - '0';
        // Check if num1 is a valid number (1-50) and has not been used yet
        if (num1 >= 1 && num1 <= 50 && !visited[num1]) {
            visited[num1] = true; // Mark as used
            result_permutation.push_back(num1); // Add to current permutation
            if (find_permutation(idx + 1, std::max(max_val_so_far, num1), num_elements_so_far + 1)) {
                return true; // If a solution is found, return true
            }
            result_permutation.pop_back(); // Backtrack: remove from permutation
            visited[num1] = false; // Backtrack: unmark as used
        }
    }

    // Try parsing a 2-digit number
    // Ensure 'idx + 1' is within string bounds AND the number doesn't start with '0'
    // (e.g., "01" is not a valid way to represent 1 in this context).
    if (idx + 1 < s.length() && s[idx] != '0') {
        int num2 = (s[idx] - '0') * 10 + (s[idx+1] - '0');
        // Check if num2 is a valid number (10-50) and has not been used yet
        if (num2 >= 10 && num2 <= 50 && !visited[num2]) {
            visited[num2] = true; // Mark as used
            result_permutation.push_back(num2); // Add to current permutation
            if (find_permutation(idx + 2, std::max(max_val_so_far, num2), num_elements_so_far + 1)) {
                return true; // If a solution is found, return true
            }
            result_permutation.pop_back(); // Backtrack: remove from permutation
            visited[num2] = false; // Backtrack: unmark as used
        }
    }

    return false; // No solution found from this path
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // Read the input string
    std::cin >> s;

    // The 'visited' array is a global static storage duration variable,
    // so it's guaranteed to be zero-initialized (all elements set to false).
    // We start the backtracking search from the beginning of the string (idx=0),
    // with no numbers found yet (max_val_so_far=0, num_elements_so_far=0).
    find_permutation(0, 0, 0);

    return 0;
}
