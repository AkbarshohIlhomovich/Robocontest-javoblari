#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int lonely_number = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        lonely_number ^= num;
    }

    cout << lonely_number << endl;

    return 0;
}
