#include <bits/stdc++.h>

using namespace std;

long long N_val, K_val;
long long MOD = 1e9 + 7;

// Matrix structure
struct Matrix {
    vector<vector<long long>> mat;
    int size;

    Matrix(int s) : size(s) {
        mat.assign(s, vector<long long>(s, 0));
    }

    static Matrix identity(int s) {
        Matrix I(s);
        for (int i = 0; i < s; ++i) {
            I.mat[i][i] = 1;
        }
        return I;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int l = 0; l < size; ++l) {
                    result.mat[i][j] = (result.mat[i][j] + mat[i][l] * other.mat[l][j]) % MOD;
                }
            }
        }
        return result;
    }
};

// Matrix exponentiation
Matrix matrix_pow(Matrix base, long long exp) {
    Matrix res = Matrix::identity(base.size);
    
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}

// Modular exponentiation for scalar
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N_val >> K_val;

    if (N_val == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Base cases for N <= K_val + 1:
    // dp[1] = 1
    // dp[i] = 2^(i-2) for i >= 2 and i <= K_val+1
    if (N_val <= K_val + 1) {
        cout << power(2, N_val - 2) << endl;
        return 0;
    }

    // For N_val > K_val + 1, use matrix exponentiation
    // The recurrence relation is dp[i] = 2*dp[i-1] - dp[i-K_val-1]
    // The state vector is V_t = [dp[t], dp[t-1], ..., dp[t-K_val]]^T
    // This requires a (K_val+1) x (K_val+1) transition matrix.
    
    int mat_size = K_val + 1;
    Matrix T(mat_size);

    // Build the transition matrix T
    // First row: coefficients for dp[t+1] = 2*dp[t] - dp[t-K_val]
    T.mat[0][0] = 2;              // Coefficient for dp[t] (first element of V_t)
    T.mat[0][K_val] = MOD - 1;    // Coefficient for -dp[t-K_val] (last element of V_t)

    // Other rows implement the shift: dp[t-j] becomes dp[t-(j-1)]
    for (int i = 1; i < mat_size; ++i) {
        T.mat[i][i-1] = 1;
    }

    // Construct the initial state vector V_{K_val+1} = [dp[K_val+1], dp[K_val], ..., dp[1]]^T
    vector<long long> initial_vec(mat_size);
    
    // dp[1] is the last element in the vector (index K_val)
    initial_vec[K_val] = 1; 
    
    // dp[j] = 2^(j-2) for j = 2 to K_val+1
    // The value at initial_vec[i] corresponds to dp[K_val + 1 - i]
    for (int i = K_val - 1; i >= 0; --i) {
        initial_vec[i] = power(2, (K_val + 1 - i) - 2);
    }

    // Calculate T raised to the power (N_val - (K_val+1))
    // This transforms V_{K_val+1} to V_{N_val}
    long long exponent = N_val - (K_val + 1);
    Matrix T_pow = matrix_pow(T, exponent);

    // Multiply T_pow with initial_vec.
    // The first element of the resulting vector (dp[N_val]) is the answer.
    long long ans = 0;
    for (int i = 0; i < mat_size; ++i) {
        ans = (ans + T_pow.mat[0][i] * initial_vec[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
