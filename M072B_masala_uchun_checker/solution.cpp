#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;

    if (std::tolower(s[0]) == 'y' &&
        std::tolower(s[1]) == 'e' &&
        std::tolower(s[2]) == 's') {
        std::cout << "ACCEPTED\n";
    } else {
        std::cout << "WRONG ANSWER\n";
    }

    return 0;
}
