#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long x;
    std::cin >> x;

    if (x == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    x = std::abs(x);

    long long k = 0;
    long long current_sum = 0;

    while (true) {
        k++;
        current_sum += k;
        if (current_sum >= x && (current_sum - x) % 2 == 0) {
            std::cout << k << std::endl;
            break;
        }
    }

    return 0;
}
