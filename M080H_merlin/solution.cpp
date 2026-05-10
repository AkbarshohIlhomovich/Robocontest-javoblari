#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    sort(a.begin(), a.end());

    int max_k = 0;
    for (int k = n; k >= 1; --k) {
        double target_X_val = static_cast<double>(total_sum) / k;
        
        long long threshold = static_cast<long long>(floor(target_X_val));

        auto it = upper_bound(a.begin(), a.end(), threshold);
        int count_le_threshold = distance(a.begin(), it);

        if (count_le_threshold >= k) {
            max_k = k;
            break; 
        }
    }

    cout << n - max_k << endl;

    return 0;
}
