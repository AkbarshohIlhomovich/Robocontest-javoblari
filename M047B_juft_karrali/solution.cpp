#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << n << std::endl;
    } else {
        std::cout << 2 * n << std::endl;
    }
    return 0;
}
