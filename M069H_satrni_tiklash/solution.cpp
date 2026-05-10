#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::min

// Z-algorithm implementation
// Computes the Z-array for a given string s.
// Z[i] is the length of the longest common prefix between s and the suffix of s starting at index i.
std::vector<int> calculate_z_array(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    if (n == 0) {
        return z;
    }

    z[0] = n; // Z[0] is typically N, as the string s matches itself fully.

    int l = 0, r = 0; // [l, r] is the current Z-box, which represents the segment s[l...r] that is also a prefix of s.
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            // If i is inside the current Z-box [l, r], we can infer a lower bound for z[i].
            // The value z[i - l] corresponds to the match length for the corresponding position in the prefix s[0...r-l].
            // We take the minimum of (remaining length in Z-box) and z[i-l] to ensure we don't go out of bounds of the current Z-box.
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        // Expand z[i] further by brute-force character comparison if possible.
        // This is done as long as characters match and we are within string bounds.
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        // If the current Z-box [i, i + z[i] - 1] extends beyond the previous 'r', update l and r.
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;

    int n = s.length();

    // The problem implies N >= 1, and requires non-zero operations.
    // If N=0 (empty string), logically 0 operations are needed, but this violates "non-zero minimum".
    // Assuming S is always non-empty based on typical problem constraints (length up to 1,000,000).

    std::vector<int> z_array = calculate_z_array(s);

    // Case 1: The entire string S is replaced by new characters.
    // This happens when all original characters S[0...N-1] are removed.
    // Each operation removes k characters. To remove N characters, we need at least m operations such that m*k >= N.
    // The minimum such m is ceil(N/k), which can be calculated as (N + k - 1) / k using integer division.
    int min_ops = (n + k - 1) / k;

    // Case 2: Part of the string S (a suffix) is retained, and new characters fill the prefix.
    // After 'm' operations, the original characters S[0...m*k-1] are removed.
    // The remaining part of the original string is S[m*k...N-1].
    // We add m*k arbitrary characters to the end.
    // For the resulting string to be equal to S, two conditions must hold:
    // 1. The preserved suffix S[m*k...N-1] must match the corresponding prefix of S, i.e., S[0...N-m*k-1].
    //    This is checked using the Z-array: Z[m*k] >= N - m*k.
    // 2. The m*k appended characters must form the remaining suffix of S, i.e., S[N-m*k...N-1].
    //    This is always possible because we can choose arbitrary characters.
    // We iterate through possible values of 'm' (number of operations) as long as m*k < N.
    for (long long m = 1; m * k < n; ++m) {
        long long current_idx = m * k;
        long long length_to_match = n - current_idx;
        if (z_array[current_idx] >= length_to_match) {
            // If the condition is met, 'm' is a valid number of operations.
            // We take the minimum of current 'min_ops' and this 'm'.
            min_ops = std::min(min_ops, static_cast<int>(m));
        }
    }

    std::cout << min_ops << std::endl;

    return 0;
}
