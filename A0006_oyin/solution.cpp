#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);

    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    int prime_count = 0;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            prime_count++;
        }
    }

    if (prime_count % 2 == 1) {
        cout << "Ali" << endl;
    } else {
        cout << "Bobur" << endl;
    }

    return 0;
}
