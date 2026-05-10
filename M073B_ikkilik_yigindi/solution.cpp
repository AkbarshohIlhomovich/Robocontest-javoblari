#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int s;
    cin >> s;

    int max_digit = 0;
    // S ni raqamlariga ajratib, eng katta raqamni topamiz.
    // 1 <= S <= 10^9 sharti tufayli S har doim musbat bo'ladi.
    while (s > 0) {
        max_digit = max(max_digit, s % 10); // Oxirgi raqamni olamiz va maksimal bilan solishtiramiz
        s /= 10; // Oxirgi raqamni olib tashlaymiz
    }

    cout << max_digit << endl;

    return 0;
}
