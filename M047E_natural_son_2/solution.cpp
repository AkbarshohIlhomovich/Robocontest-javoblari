#include <bits/stdc++.h>

using namespace std;

const string ones[] = {
    "", "bir", "ikki", "uch", "to'rt", "besh", "olti", "yetti", "sakkiz", "to'qqiz"
};

const string tens[] = {
    "", "o'n", "yigirma", "o'ttiz", "qirq", "ellik", "oltmish", "yetmish", "sakson", "to'qson"
};

string spellTwoDigits(int num) {
    if (num == 0) {
        return "";
    }
    if (num < 10) {
        return ones[num];
    }
    if (num % 10 == 0) {
        return tens[num / 10];
    }
    return tens[num / 10] + " " + ones[num % 10];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1000) {
        cout << "bir ming\n";
    } else if (n < 100) { // Sonlar 1 dan 99 gacha
        cout << spellTwoDigits(n) << "\n";
    } else { // Sonlar 100 dan 999 gacha
        int hundreds_digit = n / 100;
        int remainder = n % 100;

        cout << ones[hundreds_digit] << " yuz";

        if (remainder > 0) {
            cout << " " << spellTwoDigits(remainder);
        }
        cout << "\n";
    }

    return 0;
}
