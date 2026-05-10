---
title: "A0017 — Juft bo'luvchilar | Robocontest.uz Yechimi"
description: "Robocontest.uz A0017 (Juft bo'luvchilar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0017, Juft bo'luvchilar yechimi, robocontest Juft bo'luvchilar, A0017 c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /A0017_juft_boluvchilar/
lang: uz
---

# A0017 — Juft bo'luvchilar

## Masala haqida
Bu masala berilgan \(N\) sonining juft bo'luvchilari sonini topishni talab qiladi. Kirishda \(T\) ta test holati mavjud bo'lib, har bir test holati uchun bitta butun son \(N\) (\(1 \le N \le 10^9\)) kiritiladi. Har bir \(N\) uchun uning nechta juft bo'luvchisi borligini hisoblab, alohida qatorda chiqarish kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi tub ko'paytuvchilarga ajratishga (prime factorization) asoslangan. Har qanday juft son kamida bitta 2 ko'paytuvchisini o'z ichiga oladi. Agar \(N\) soni tub ko'paytuvchilarga \(N = 2^a \cdot p_1^{b_1} \cdot p_2^{b_2} \cdot \ldots \cdot p_k^{b_k}\) shaklida yoyilsa, bu yerda \(p_i\) lar 2 dan farqli tub sonlar, u holda \(N\) ning har qanday juft bo'luvchisi \(2^x \cdot d_{toq}\) ko'rinishida bo'ladi, bu yerda \(1 \le x \le a\) va \(d_{toq}\) soni \(p_1^{b_1} \cdot p_2^{b_2} \cdot \ldots \cdot p_k^{b_k}\) ning bo'luvchisi hisoblanadi.

Demak, biz quyidagicha ishlaymiz:
1.  Avvalo, \(N\) dan 2 ning barcha darajalarini ajratib olamiz va 2 ning darajasini (\(a\)) hisoblaymiz.
2.  Qolgan toq qism (\(N' = p_1^{b_1} \cdot p_2^{b_2} \cdot \ldots \cdot p_k^{b_k}\)) ning umumiy bo'luvchilari sonini topamiz. Bu son \(N\) ning barcha toq bo'luvchilari soniga teng bo'ladi.
3.  Jami juft bo'luvchilar sonini topish uchun 2 ning darajasi (\(a\)) ni toq qismning bo'luvchilari soniga ko'paytiramiz.

Misol: \(N = 12 = 2^2 \cdot 3^1\).
1.  2 ning darajasi \(a = 2\). \(N\) ning toq qismi \(3\).
2.  Toq qism \(3\) ning bo'luvchilari soni: \(1\) va \(3\). Ya'ni \((1+1) = 2\) ta bo'luvchi.
3.  Juft bo'luvchilar soni: \(a \times (\text{3 ning bo'luvchilari soni}) = 2 \times 2 = 4\).
    Haqiqatdan ham, 12 ning juft bo'luvchilari: 2, 4, 6, 12.

## Algoritm qadamlari
1.  **Dastlabki tekshiruv**: Agar berilgan \(N\) soni toq bo'lsa (\(N \pmod 2 \neq 0\)), uning juft bo'luvchilari yo'q. Bunday holda 0 ni chiqarib, keyingi testga o'tamiz.
2.  **2 ning darajasini ajratish**: \(N\) ni 2 ga bo'linmaydigan holatgacha 2 ga bo'lib boramiz. Necha marta 2 ga bo'linganini `exponent_of_2` o'zgaruvchisida hisoblaymiz. Shu qadamdan so'ng, \(N\) ning qiymati uning toq qismiga aylanadi.
3.  **Qolgan toq qismning bo'luvchilari sonini topish**:
    *   `count_odd_divisors_factor` deb nomlangan o'zgaruvchini 1 ga tenglaymiz. Bu toq qismning bo'luvchilari sonini hisoblash uchun ishlatiladi.
    *   3 dan boshlab \(N\) ning kvadrat ildizigacha (shu jumladan) faqat toq sonlar (chunki \(N\) hozir toq) bilan bo'lib tekshiramiz. Bu jarayon "trial division" (sinov bo'lish) deb ataladi.
    *   Har bir tekshirilayotgan `i` soni uchun, agar \(N\) shu `i` ga qoldiqsiz bo'linsa:
        *   `current_prime_exponent` o'zgaruvchisini nolga tenglaymiz.
        *   \(N\) ni `i` ga bo'linmaydigan holatgacha `i` ga bo'lib boramiz va necha marta bo'linganini `current_prime_exponent` da sanaymiz.
        *   Topilgan tub bo'luvchining darajasi \(k\) bo'lsa, uning bo'luvchilari soni \((k+1)\) ga teng bo'ladi (chunki \(i^0, i^1, \ldots, i^k\) bo'luvchilari mavjud). Shu \((k+1)\) ni `count_odd_divisors_factor` ga ko'paytiramiz.
    *   Agar sikldan keyin \(N\) > 1 bo'lsa, demak, qolgan \(N\) ning qiymati kvadrat ildizidan katta bo'lgan tub sondir. Bunday tub sonning darajasi 1 ga teng bo'ladi, shuning uchun uning bo'luvchilari soni \((1+1)=2\) ga tengdir. Shuning uchun `count_odd_divisors_factor` ni 2 ga ko'paytiramiz.
4.  **Juft bo'luvchilar sonini hisoblash va chiqarish**: Yakuniy javob `exponent_of_2 * count_odd_divisors_factor` formulasi orqali hisoblanadi va ekranga chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: \(O(T \cdot \sqrt{N})\)
    *   Har bir test holati uchun algoritm \(N\) sonining tub ko'paytuvchilarini topishga harakat qiladi. Eng ko'p vaqt talab qiladigan qism bu \(N\) ning kvadrat ildizigacha (taxminan \( \sqrt{N} \)) bo'lgan barcha toq sonlarni tekshirishdir.
    *   \(N_{max} = 10^9\) bo'lganida, \(\sqrt{N_{max}} \approx 31622\).
    *   Har bir test uchun sikl taxminan \(\sqrt{N}\) marta aylanadi. Ichkaridagi `while` sikli esa logarifmik marta ishlaydi.
    *   Jami \(T\) ta test mavjud (\(T_{max} = 100\)).
    *   Shunday qilib, umumiy vaqt murakkabligi taxminan \(T \cdot \sqrt{N_{max}} \approx 100 \cdot 31622 \approx 3.16 \cdot 10^6\) operatsiyani tashkil etadi. Bu 1000 ms vaqt limiti uchun juda tez hisoblanadi. (Berilgan yechim 1ms natija ko'rsatgan).
-   **Xotira murakkabligi**: \(O(1)\)
    *   Algoritm faqat bir nechta butun son o'zgaruvchilardan foydalanadi. Bu doimiy xotira miqdorini talab qiladi va 16 MB xotira limiti uchun hech qanday muammo tug'dirmaydi.
-   **Nega shu murakkablik chegaraga sig'adi**: Yuqoridagi tahlillarga ko'ra, operatsiyalar soni 10^8 dan ancha kam (taxminan 3 * 10^6) bo'lgani sababli, algoritm belgilangan vaqt ichida muvaffaqiyatli ishlaydi. Xotira foydalanishi esa minimal darajada.

## Kod izohi
Quyida berilgan C++ yechimining asosiy qismlari izohlangan:

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi, tezkor yozish uchun qulay.
using namespace std;     // 'std::' prefiksini yozmaslik uchun.

void solve() { // Har bir test holati uchun masalani yechuvchi funksiya
    int n;
    cin >> n; // N sonini kiritish

    // Agar son N toq bo'lsa, uning juft bo'luvchilari yo'q.
    if (n % 2 != 0) {
        cout << 0 << "\n"; // 0 ni chiqarib, yangi qatorga o'tish
        return;            // Funksiyadan chiqish
    }

    // 1-qadam: N sonining tub ko'paytuvchilar yoyilmasidagi 2 ning darajasini topish.
    // Masalan, N = 2^a * p1^b1 * p2^b2 * ...
    // Bu yerda 'a' - 2 ning darajasi (exponent).
    int exponent_of_2 = 0; // 2 ning darajasini saqlash uchun o'zgaruvchi
    while (n % 2 == 0) {   // N 2 ga bo'linar ekan
        n /= 2;            // N ni 2 ga bo'lamiz
        exponent_of_2++;   // 2 ning darajasini oshiramiz
    }
    // Shu qadamdan so'ng, 'n' hozirda faqat toq tub ko'paytuvchilarni o'z ichiga oladi.

    // 2-qadam: Qolgan toq qism (hozirgi 'n' qiymati) ning bo'luvchilari sonini topish.
    // Bu qism N_original ning barcha toq bo'luvchilarini topishga yordam beradi.
    int count_odd_divisors_factor = 1; // Toq qismning bo'luvchilari sonini saqlovchi o'zgaruvchi

    // N ning tub bo'luvchilarini topish uchun 3 dan boshlab ildizgacha tekshiramiz.
    // n hozir toq bo'lgani sababli, faqat toq sonlarni tekshiramiz (i += 2).
    // (long long)i * i <= n sharti int diapazonida toshib ketish xavfini oldini oladi.
    // Chunki i * i maksimal 31622 * 31622 < 10^9 bo'lishi mumkin, lekin bu int chegarasida turadi.
    // Kattaroq N uchun bu muhim bo'lar edi.
    for (int i = 3; (long long)i * i <= n; i += 2) {
        if (n % i == 0) { // Agar N, i ga qoldiqsiz bo'linsa (demak, i - N ning tub bo'luvchisi)
            int current_prime_exponent = 0; // Joriy tub son (i) ning darajasini saqlash
            // 'i' tub sonining necha marta bo'luvchi ekanligini topamiz
            while (n % i == 0) {
                n /= i;                      // N ni 'i' ga bo'lamiz
                current_prime_exponent++;    // Darajani oshiramiz
            }
            // Tub bo'luvchining darajasi (k) bo'lsa, uning bo'luvchilari soni (k+1) bo'ladi.
            count_odd_divisors_factor *= (current_prime_exponent + 1);
        }
    }

    // Agar sikldan keyin n > 1 bo'lsa, demak, qolgan 'n' qiymati kvadrat ildizdan katta
    // bo'lgan tub sonning o'zidir (masalan, N=34=2*17 da, i=3, sqrt(17)~4.1, for tugaydi, n=17 qoladi).
    // Bu tub sonning darajasi 1 bo'ladi, shuning uchun uning bo'luvchilari soni (1+1) = 2 ga teng.
    if (n > 1) {
        count_odd_divisors_factor *= 2;
    }

    // 3-qadam: Umumiy juft bo'luvchilar sonini hisoblash.
    // Juft bo'luvchilar soni = (2 ning darajasi) * (N ning toq qismining bo'luvchilari soni).
    // Buning sababi, juft bo'luvchida kamida bitta 2 ko'paytuvchisi bo'lishi kerak.
    // Agar N = 2^a * O bo'lsa (O - toq qism), O ning har bir bo'luvchisi 'd_o' uchun
    // 2^1 * d_o, 2^2 * d_o, ..., 2^a * d_o ko'rinishidagi 'a' ta juft bo'luvchi mavjud.
    // Shuning uchun, jami 'a' * (O ning bo'luvchilari soni) ta juft bo'luvchi bor.
    cout << exponent_of_2 * count_odd_divisors_factor << "\n";
}

int main() {
    // Tezkor kiritish/chiqarish uchun
    // stdio kutubxonasi bilan C++ streamlarini sinxronizatsiyasini o'chiradi.
    ios_base::sync_with_stdio(false);
    // cin va cout operatsiyalarini tezlashtiradi.
    cin.tie(0);

    int t;
    cin >> t; // Testlar sonini kiritish
    while (t--) { // Har bir test holati uchun
        solve();   // solve funksiyasini chaqirish
    }
    return 0; // Dastur muvaffaqiyatli yakunlanganini bildirish
}
```

## Edge case lar va eslatmalar
*   **N toq son bo'lsa**: Masalan, \(N=5\). Kodning boshida `if (n % 2 != 0)` sharti bu holatni ushlab oladi va 0 chiqaradi. Bu to'g'ri, chunki toq sonlarning juft bo'luvchisi yo'q.
*   **N ning o'zi 2 ning darajasi bo'lsa**: Masalan, \(N=8 = 2^3\). `exponent_of_2` 3 ga teng bo'ladi. `n` esa 1 ga aylanadi. Ikkinchi sikl (toq bo'luvchilarni hisoblaydigan) ishlamaydi, `count_odd_divisors_factor` 1 ga teng bo'lib qoladi. Natija `3 * 1 = 3`. Bu to'g'ri, 8 ning juft bo'luvchilari: 2, 4, 8.
*   **N ning o'zi tub son bo'lsa (va juft)**: Masalan, \(N=2\). `exponent_of_2` 1 ga teng bo'ladi, `n` esa 1 ga aylanadi. `count_odd_divisors_factor` 1 ga teng bo'ladi. Natija `1 * 1 = 1`. To'g'ri, 2 ning yagona juft bo'luvchisi bu 2 ning o'zidir.
*   **`i * i` da toshib ketish xavfi**: `for` siklida `(long long)i * i <= n` sharti `i * i` ning natijasi `int` tipi diapazonidan chiqib ketishining oldini oladi. \(N_{max} = 10^9\) bo'lganida, \(\sqrt{N_{max}} \approx 31622\). \(31622 \times 31622 \approx 999950884\). Bu qiymat `int` tipiga sig'adi (\(2 \cdot 10^9\) atrofida). Shunga qaramay, `(long long)` dan foydalanish xavfsizlikni oshiradi va \(N\) ning maksimal qiymati kattaroq bo'lganda (masalan, \(10^{18}\) bo'lsa) zarur bo'lar edi.
*   **Algoritmning samaradorligi**: Tub ko'paytuvchilarga ajratish uchun kvadrat ildizgacha tekshirish juda samarali yondashuv hisoblanadi, ayniqsa \(N\) ning qiymati \(10^9\) kabi bo'lganda.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0017) platformasidagi **A0017** raqamli **Juft bo'luvchilar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0017>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0017, Juft bo'luvchilar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
