#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long ans = 0;
    int count_even_prefix_sums = 1; 
    int count_odd_prefix_sums = 0;
    int current_prefix_sum_parity = 0; 

    for (int i = 0; i < n; ++i) {
        int c_i;
        cin >> c_i;

        current_prefix_sum_parity = (current_prefix_sum_parity + (c_i % 2)) % 2;

        if (current_prefix_sum_parity == 0) {
            ans += count_even_prefix_sums;
            count_even_prefix_sums++;
        } else {
            ans += count_odd_prefix_sums;
            count_odd_prefix_sums++;
        }
    }

    cout << ans << endl;

    return 0;
}
