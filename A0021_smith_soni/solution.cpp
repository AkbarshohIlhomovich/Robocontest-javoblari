#include <bits/stdc++.h>

int sum_digits_iterative(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    int N;
    std::cin >> N;

    int original_N_sum_digits = sum_digits_iterative(N);
    long long sum_prime_factor_digits = 0; 
    int temp_N = N;
    bool is_composite = false;

    if (temp_N % 2 == 0) {
        is_composite = true;
        while (temp_N % 2 == 0) {
            sum_prime_factor_digits += sum_digits_iterative(2);
            temp_N /= 2;
        }
    }

    for (int i = 3; (long long)i * i <= temp_N; i += 2) {
        if (temp_N % i == 0) {
            is_composite = true;
            while (temp_N % i == 0) {
                sum_prime_factor_digits += sum_digits_iterative(i);
                temp_N /= i;
            }
        }
    }

    if (temp_N > 1) {
        sum_prime_factor_digits += sum_digits_iterative(temp_N);
    }

    if (is_composite && original_N_sum_digits == sum_prime_factor_digits) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}
