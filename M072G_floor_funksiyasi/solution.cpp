#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    long long A, B, N;
    std::cin >> A >> B >> N;
    long long x_val_for_max_remainder = std::min(N, B - 1);
    long long result = (A * x_val_for_max_remainder) / B;
    std::cout << result << std::endl;
    return 0;
}
