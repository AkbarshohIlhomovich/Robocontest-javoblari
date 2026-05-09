#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

const int MAX_COMB_N = 1999; 
long long fact[MAX_COMB_N + 1];
long long invFact[MAX_COMB_N + 1];

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_COMB_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    invFact[MAX_COMB_N] = modInverse(fact[MAX_COMB_N]);
    for (int i = MAX_COMB_N - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr_mod_p(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    precompute_factorials();

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        int n_val = K + N - 1;
        int r_val = K; 
        
        cout << nCr_mod_p(n_val, r_val) << "\n";
    }

    return 0;
}
