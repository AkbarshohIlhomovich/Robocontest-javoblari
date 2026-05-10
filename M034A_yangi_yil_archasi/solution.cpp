#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int h, d, g;
        cin >> h >> d >> g;

        if (h >= 200 && h <= 300 && d >= 50 && g >= 150) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
