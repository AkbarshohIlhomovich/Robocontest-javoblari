#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X, Y;
    while (cin >> X >> Y) {
        int common_divisor = gcd(X, Y);
        int result = 2 * (X + Y) / common_divisor;
        cout << result << "\n";
    }

    return 0;
}
