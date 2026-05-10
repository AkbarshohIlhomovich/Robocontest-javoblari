#include <iostream>
#include <string>
#include <vector>
#include <cstring> // For memset

using namespace std;

// dp[idx][tight] stores the number of ways to complete numbers 'a' and 'b'
// from bit position 'idx' onwards, given the 'tight' constraint.
// idx: current bit position (from 0 to N-1, where N is L_str.length())
// tight: boolean flag, true if the current prefix a+b is equal to the prefix of L.
//        false if a+b is already strictly less than L.
long long dp[100001][2]; 
string L_str;
int N;
const long long MOD = 1e9 + 7;

long long solve(int idx, bool tight) {
    // Base case: If we have processed all bits, we found one valid way.
    if (idx == N) {
        return 1; 
    }
    // Memoization: If this state has been computed, return the stored result.
    if (dp[idx][tight] != -1) {
        return dp[idx][tight];
    }

    long long ans = 0;
    // Determine the upper limit for the sum_bit at the current position.
    // If tight is true, sum_bit cannot exceed L_str[idx].
    // If tight is false, sum_bit can be 0 or 1 (it's already less than L, so any bit is fine).
    int limit_L_digit = (tight ? (L_str[idx] - '0') : 1);

    // We need to choose bits (a_idx, b_idx) for the current position 'idx'
    // such that a_idx AND b_idx = 0.
    // Possible (a_idx, b_idx) pairs are (0,0), (0,1), (1,0).

    // Case 1: (a_idx, b_idx) = (0,0). Sum bit for this position is 0.
    // This choice is always valid because 0 <= limit_L_digit (limit_L_digit is either 0 or 1).
    // The new 'tight' state: if we were tight and L_str[idx] was 0, we remain tight.
    // If L_str[idx] was 1, we become not tight (0 < 1).
    ans = (ans + solve(idx + 1, tight && (0 == limit_L_digit))) % MOD;

    // Case 2 & 3: (a_idx, b_idx) = (0,1) or (1,0). Sum bit for this position is 1.
    // These choices are valid only if sum_bit (which is 1) is less than or equal to limit_L_digit.
    if (1 <= limit_L_digit) {
        // If sum_bit can be 1, there are 2 ways to achieve it: (0,1) and (1,0).
        // The new 'tight' state: if we were tight and L_str[idx] was 1, we remain tight.
        // If L_str[idx] was 0, this branch would not be taken (1 > 0).
        long long ways_for_one_bit = solve(idx + 1, tight && (1 == limit_L_digit));
        ans = (ans + (2 * ways_for_one_bit) % MOD) % MOD;
    }

    // Store the computed result before returning.
    return dp[idx][tight] = ans;
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> L_str;
    N = L_str.length();

    // Initialize DP table with -1 to indicate uncomputed states.
    // memset works correctly for long long arrays with -1.
    memset(dp, -1, sizeof(dp));

    // Start the DP calculation from the most significant bit (index 0)
    // with the 'tight' constraint initially true (a+b must exactly match L's prefix).
    cout << solve(0, true) << endl;

    return 0;
}
