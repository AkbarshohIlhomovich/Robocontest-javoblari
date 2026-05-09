#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> input_matrix(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> input_matrix[i][j];
        }
    }

    // All 8 possible 3x3 magic squares with elements from 1 to 9
    // The sum of each row, column, and main/anti-diagonal is 15.
    vector<vector<vector<int>>> magic_squares = {
        // Base magic square
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        // Rotated 90 degrees clockwise
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        // Rotated 180 degrees
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        // Rotated 270 degrees clockwise
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        // Reflected horizontally from the base square
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        // Reflected horizontally from the 90-degree rotated square
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        // Reflected horizontally from the 180-degree rotated square
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        // Reflected horizontally from the 270-degree rotated square
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };

    int min_energy = INT_MAX; // Initialize with maximum possible integer value

    // Iterate through all 8 known 3x3 magic squares
    for (const auto& ms : magic_squares) {
        int current_energy = 0;
        // Calculate the energy required to transform the input matrix into the current magic square
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                current_energy += abs(input_matrix[i][j] - ms[i][j]);
            }
        }
        // Update the minimum energy found so far
        min_energy = min(min_energy, current_energy);
    }

    cout << min_energy << endl;

    return 0;
}
