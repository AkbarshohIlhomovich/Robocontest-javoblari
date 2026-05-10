#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long x;
    cin >> x;

    // The equation is (10^1 * 3^3 + 22 - 9/3) * 7 - 2022 = a + b + 1
    // Let's evaluate the left side:
    // 10^1 = 10
    // 3^3 = 27
    // 9/3 = 3
    // So, the expression becomes:
    // (10 * 27 + 22 - 3) * 7 - 2022
    // (270 + 22 - 3) * 7 - 2022
    // (292 - 3) * 7 - 2022
    // 289 * 7 - 2022
    // 2023 - 2022
    // 1
    // So, the equation simplifies to:
    // 1 = a + b + 1
    // Subtracting 1 from both sides gives:
    // 0 = a + b
    // This implies that one number is the negative of the other.
    // If we are given one number `x`, the other missing number must be `-x`.

    cout << -x << endl;

    return 0;
}
