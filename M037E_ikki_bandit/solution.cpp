#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int H, L;
    std::cin >> H >> L;
    int harry_not_shot = L - 1;
    int larry_not_shot = H - 1;
    std::cout << harry_not_shot << " " << larry_not_shot << std::endl;
    return 0;
}
