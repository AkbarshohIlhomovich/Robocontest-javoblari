#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    long long n;
    std::cin >> n;
    long long a, b, c;
    std::cin >> a >> b >> c;
    if (a + b + c >= n) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}
