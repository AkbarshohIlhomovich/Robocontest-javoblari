#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long x;
    std::cin >> x;

    std::string s = std::to_string(x);
    int len = s.length();

    for (int i = 0; i < len; ++i) {
        // Agar bu birinchi raqam bo'lmasa va 
        // joriy pozitsiyadan oxirigacha qolgan raqamlar soni (joriy raqamni ham hisobga olgan holda)
        // 3 ga karrali bo'lsa, bo'sh joy qo'yamiz.
        // Bu joriy raqam yangi 3 xonali guruhni boshlayotganini bildiradi.
        if (i > 0 && (len - i) % 3 == 0) {
            std::cout << ' ';
        }
        std::cout << s[i];
    }

    std::cout << ",00\n";

    return 0;
}
