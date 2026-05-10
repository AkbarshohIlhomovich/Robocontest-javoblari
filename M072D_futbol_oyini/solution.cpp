#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, a, b;
    cin >> k >> a >> b;

    for (int x = a; x <= b; ++x) {
        if (x % k == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
