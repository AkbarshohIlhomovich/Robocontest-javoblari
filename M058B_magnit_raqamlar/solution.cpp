#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n < 10) {
        cout << "NO" << endl;
    } else {
        int d1 = n / 10;
        int d2 = n % 10;
        if (d1 == d2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
