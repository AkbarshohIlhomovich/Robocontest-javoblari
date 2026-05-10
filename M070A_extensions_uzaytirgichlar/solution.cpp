#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    long long total_sockets = 0; 
    for (int i = 0; i < N; ++i) {
        int a_i;
        cin >> a_i;
        total_sockets += a_i;
    }

    // Har bir uzaytirgich (birinchisidan tashqari) tarmoqqa ulanish uchun 1 ta rozetkani ishlatadi.
    // Shunday qilib, N ta uzaytirgichni bitta asosiy manbadan quvvatlantirish uchun,
    // birinchi uzaytirgich devor rozetkasiga ulanadi, qolgan N-1 ta uzaytirgich esa
    // boshqa uzaytirgichlarning rozetkalariga ulanadi.
    // Bu jami N-1 ta rozetkani o'zaro ulanishlar uchun ishlatilishini anglatadi.
    // Umumiy rozetkalar sonidan bu N-1 ta rozetkani ayirsak, telefonlar uchun mavjud bo'lgan
    // maksimal rozetkalar sonini olamiz.
    long long result = total_sockets - (N - 1);

    cout << result << endl;

    return 0;
}
