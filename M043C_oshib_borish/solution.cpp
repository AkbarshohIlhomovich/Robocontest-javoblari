#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // An array can be rearranged to be strictly increasing if and only if
    // all its elements are unique. If there are duplicate elements,
    // it's impossible to satisfy the strict inequality condition.
    
    // Sort the array to easily check for duplicates.
    sort(a.begin(), a.end());

    bool possible = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
