#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    string s;
    cin >> s;

    if (s.length() > k) {
        cout << s.substr(0, k) << "..." << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}
