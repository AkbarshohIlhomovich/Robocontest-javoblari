#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    if (C > A && C > B) {
        cout << "NO\n";
        return;
    }

    int common_divisor = std::gcd(A, B);
    if (C % common_divisor == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
