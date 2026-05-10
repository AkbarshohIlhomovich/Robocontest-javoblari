#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s = "Agentlik olimpiadasiga xush kelibsiz";
    char target_char;
    cin >> target_char;

    bool found = false;
    for (char c : s) {
        if (c == target_char) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
