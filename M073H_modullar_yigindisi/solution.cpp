#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long total_max_mod_sum = 0;
    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;
        total_max_mod_sum += (a_i - 1);
    }

    cout << total_max_mod_sum << endl;

    return 0;
}
