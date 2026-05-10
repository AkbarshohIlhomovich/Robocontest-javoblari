#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long n, m;
    std::cin >> n >> m;

    long long expected_total_sum = (m - n + 1) * (n + m) / 2;
    
    long long given_sum = 0;
    int count = m - n;
    for (int i = 0; i < count; ++i) {
        long long x;
        std::cin >> x;
        given_sum += x;
    }

    std::cout << expected_total_sum - given_sum << std::endl;

    return 0;
}
