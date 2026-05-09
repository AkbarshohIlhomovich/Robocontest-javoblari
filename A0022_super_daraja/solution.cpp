#include <bits/stdc++.h>

using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    if (b == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long phi_b = phi(b);

    long long exponent_for_outer_val;
    bool is_exponent_large_enough_for_phi_rule = false;

    if (a >= 20) { 
        is_exponent_large_enough_for_phi_rule = true;
        exponent_for_outer_val = power(2, a, phi_b);
    } else {
        long long actual_2_pow_a = (1LL << a);
        if (actual_2_pow_a >= phi_b) {
            is_exponent_large_enough_for_phi_rule = true;
            exponent_for_outer_val = actual_2_pow_a % phi_b;
        } else {
            exponent_for_outer_val = actual_2_pow_a;
        }
    }

    if (is_exponent_large_enough_for_phi_rule) {
        exponent_for_outer_val += phi_b;
    }
    
    cout << power(2, exponent_for_outer_val, b) << endl;

    return 0;
}
