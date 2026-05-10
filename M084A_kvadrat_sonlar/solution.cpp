#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    bool first_output = true;

    for (long long k = 1; ; ++k) {
        long long square = k * k;

        if (square > n) {
            break;
        }

        if (!first_output) {
            cout << " ";
        }
        cout << square;
        first_output = false;
    }
    cout << endl;

    return 0;
}
