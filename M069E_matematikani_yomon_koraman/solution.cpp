#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

long long count_pairs_func(int s) {
    if (s >= 0 && s <= 9) {
        return s + 1;
    } else if (s >= 10 && s <= 18) {
        return 19 - s;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    string s_n = to_string(n);
    int len = s_n.length();

    vector<long long> dp(len + 1, 0);

    dp[len] = 1;

    for (int i = len - 1; i >= 0; --i) {
        int d1 = s_n[i] - '0';
        dp[i] += count_pairs_func(d1) * dp[i+1];

        if (i + 1 < len) {
            if (s_n[i] != '0') {
                int d2 = (s_n[i] - '0') * 10 + (s_n[i+1] - '0');
                dp[i] += count_pairs_func(d2) * dp[i+2];
            }
        }
    }

    cout << dp[0] << endl;

    return 0;
}
