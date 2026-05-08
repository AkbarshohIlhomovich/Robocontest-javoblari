#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // Agar son N toq bo'lsa, uning juft bo'luvchilari yo'q.
    if (n % 2 != 0) {
        cout << 0 << "\n";
        return;
    }

    // 1-qadam: N sonining tub ko'paytuvchilar yoyilmasidagi 2 ning darajasini topish.
    // Masalan, N = 2^a * p1^b1 * p2^b2 * ...
    // Bu yerda 'a' - 2 ning darajasi.
    int exponent_of_2 = 0;
    while (n % 2 == 0) {
        n /= 2;
        exponent_of_2++;
    }

    // N hozirda 2 ga bo'linmaydigan qismni ifodalaydi (ya'ni, barcha toq tub ko'paytuvchilarining mahsuli).
    // Misol: Agar N_original = 12 (2^2 * 3^1) bo'lsa, exponent_of_2 = 2, n esa 3 bo'ladi.
    // Agar N_original = 8 (2^3) bo'lsa, exponent_of_2 = 3, n esa 1 bo'ladi.

    // 2-qadam: Qolgan toq qism (hozirgi 'n' qiymati) ning bo'luvchilari sonini topish.
    // Bu qism N_original ning barcha toq bo'luvchilarini beradi.
    int count_odd_divisors_factor = 1;

    // N ning tub bo'luvchilarini topish uchun 3 dan boshlab ildizgacha tekshiramiz.
    // n hozir toq bo'lgani sababli, faqat toq sonlarni tekshiramiz (i += 2).
    // i*i <= n sharti int diapazonida xavfsiz, chunki n <= 10^9 va sqrt(10^9) taxminan 31622.
    // 31622 * 31622 < 10^9 bo'lgani uchun int toshib ketmaydi. Yaxshiroq xavfsizlik uchun (long long)i * i ishlatilmoqda.
    for (int i = 3; (long long)i * i <= n; i += 2) { 
        if (n % i == 0) {
            int current_prime_exponent = 0;
            // 'i' tub sonining necha martda bo'luvchi ekanligini topamiz
            while (n % i == 0) {
                n /= i;
                current_prime_exponent++;
            }
            // Tub bo'luvchining darajasi (k) bo'lsa, uning bo'luvchilari soni (k+1) bo'ladi.
            count_odd_divisors_factor *= (current_prime_exponent + 1);
        }
    }

    // Agar sikldan keyin n > 1 bo'lsa, demak, qolgan 'n' qiymati kvadrat ildizdan katta bo'lgan tub sonning o'zidir.
    // Bu tub sonning darajasi 1 bo'ladi, shuning uchun uning bo'luvchilari soni (1+1) = 2 ga teng.
    if (n > 1) {
        count_odd_divisors_factor *= 2; 
    }

    // 3-qadam: Umumiy juft bo'luvchilar sonini hisoblash.
    // Juft bo'luvchilar soni = (2 ning darajasi) * (N ning toq qismining bo'luvchilari soni).
    // Buning sababi, juft bo'luvchida kamida bitta 2 ko'paytuvchisi bo'lishi kerak.
    // Agar N = 2^a * O bo'lsa, O - toq qism, O ning har bir bo'luvchisi 'd_o' uchun
    // 2^1 * d_o, 2^2 * d_o, ..., 2^a * d_o ko'rinishidagi 'a' ta juft bo'luvchi mavjud.
    // Shuning uchun, jami 'a' * (O ning bo'luvchilari soni) ta juft bo'luvchi bor.
    cout << exponent_of_2 * count_odd_divisors_factor << "\n";
}

int main() {
    // Tezkor kiritish/chiqarish uchun
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t; // Testlar soni
    while (t--) {
        solve(); // Har bir test uchun masalani yechish
    }
    return 0;
}
