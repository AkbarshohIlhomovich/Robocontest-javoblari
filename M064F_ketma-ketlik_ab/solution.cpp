#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long a, b;
    std::cin >> a >> b;

    long long s = a + b;

    long long total_terms_before_s_group = (s - 2) * (s - 1) / 2;
    long long position_in_s_group = s - a;

    long long result = total_terms_before_s_group + position_in_s_group;

    std::cout << result << std::endl;

    return 0;
}
