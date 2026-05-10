---
title: "M088C — Shirinlik | Robocontest.uz Yechimi"
description: "Robocontest.uz M088C (Shirinlik) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 2000 ms, xotira: 128 MB."
keywords: "robocontest M088C, Shirinlik yechimi, robocontest Shirinlik, M088C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M088C_shirinlik/
lang: uz
---

# M088C — Shirinlik

## Masala haqida
Robolandiya bolalari konfet yig'ish uchun `N` ta uydan iborat ko'chaga chiqishadi. Har bir `i`-uydan `C_i` ta konfet olishadi. Zarif va Sunatillo `L` va `R` uylari orasidagi barcha konfetlarni yig'ishni rejalashtirishgan, ya'ni `C_L + C_{L+1} + ... + C_R` yig'indisini. Ular konfetlar soni teng bo'lishini xohlashadi, shuning uchun yig'ilgan konfetlarning umumiy soni juft bo'lishi kerak. Masala shartiga ko'ra, ular juft miqdordagi shirinliklar to'plashi mumkin bo'lgan `(L, R)` uy raqamlari juftliklari sonini topish kerak.

## Yondashuv (g'oya)
Masalani samarali hal qilish uchun biz "oldindan yig'indi" (prefix sum) tushunchasidan foydalanamiz. `P[k]` ni `C_1 + C_2 + ... + C_k` yig'indisi deb belgilaymiz. Shuningdek, `P[0] = 0` deb olamiz.
`C_L + C_{L+1} + ... + C_R` yig'indisini `P[R] - P[L-1]` shaklida ifodalash mumkin.
Biz bu yig'indining juft bo'lishini istaymiz. Ikki sonning ayirmasi juft bo'lishi uchun ularning har ikkisi ham juft yoki har ikkisi ham toq bo'lishi kerak. Boshqacha aytganda, `P[R]` va `P[L-1]` sonlarining juft-toqligi (parity) bir xil bo'lishi kerak. Ya'ni, `(P[R] % 2) == (P[L-1] % 2)` shartini qanoatlantiruvchi `(L, R)` juftliklarini topishimiz kerak.
Biz ko'cha bo'ylab bir marta yurib chiqamiz va har bir `i`-uy uchun `P[i]` ni hisoblaymiz. Har bir `P[i]` uchun undan oldingi `P[k]` (bu yerda `k < i`) lardan nechasi `P[i]` bilan bir xil juft-toqlikka ega ekanligini sanaymiz. Bu esa bizga jami juftliklar sonini beradi.

## Algoritm qadamlari
1.  Jami juftliklar sonini saqlash uchun `ans` o'zgaruvchisini `0` ga tenglab olamiz. Bu o'zgaruvchi `long long` tipida bo'lishi kerak, chunki javob juda katta son bo'lishi mumkin (`N` maksimal `10^6` bo'lsa, `ans` `10^12` gacha yetishi mumkin).
2.  Juft oldindan yig'indilar (prefix sums) sonini saqlash uchun `count_even_prefix_sums` o'zgaruvchisini `1` ga tenglab olamiz. Bunga sabab, `P[0] = 0` deb olamiz, va `0` juft son hisoblanadi.
3.  Toq oldindan yig'indilar sonini saqlash uchun `count_odd_prefix_sums` o'zgaruvchisini `0` ga tenglab olamiz.
4.  Joriy oldindan yig'indining juft-toqligini saqlash uchun `current_prefix_sum_parity` o'zgaruvchisini `0` ga tenglab olamiz (bu `P[0]` ning juft-toqligini ifodalaydi).
5.  `N` ta uydan har birining konfet sonini o'qib chiqish uchun `i` ni `0` dan `N-1` gacha sikl yordamida takrorlaymiz.
    a.  Joriy `c_i` konfet sonini o'qiymiz.
    b.  `current_prefix_sum_parity` ni yangilaymiz: `current_prefix_sum_parity = (current_prefix_sum_parity + (c_i % 2)) % 2`. Bu har bir qadamda `P[i]` ning juft-toqligini hisoblaydi.
    c.  Agar `current_prefix_sum_parity` `0` ga teng bo'lsa (ya'ni, `P[i]` juft bo'lsa):
        i.  `ans` ga `count_even_prefix_sums` ni qo'shamiz. Bu shuni anglatadiki, joriy `P[i]` bilan juft-toqligi bir xil bo'lgan barcha avvalgi `P[k]` lardan (shu jumladan `P[0]` dan) `count_even_prefix_sums` ta juftlik hosil bo'ladi.
        ii. `count_even_prefix_sums` ni bittaga oshiramiz, chunki `P[i]` ham endi kelajakdagi juftliklar uchun ishlatilishi mumkin bo'lgan juft oldindan yig'indi hisoblanadi.
    d.  Aks holda (agar `current_prefix_sum_parity` `1` ga teng bo'lsa, ya'ni `P[i]` toq bo'lsa):
        i.  `ans` ga `count_odd_prefix_sums` ni qo'shamiz. Bu joriy `P[i]` bilan bir xil toq juft-toqlikka ega bo'lgan barcha avvalgi `P[k]` lardan `count_odd_prefix_sums` ta juftlik hosil bo'lishini bildiradi.
        ii. `count_odd_prefix_sums` ni bittaga oshiramiz, chunki `P[i]` ham kelajakdagi juftliklar uchun ishlatilishi mumkin bo'lgan toq oldindan yig'indi hisoblanadi.
6.  Sikl tugagandan so'ng, `ans` ning oxirgi qiymatini chop etamiz.

## Murakkablik tahlili
-   **Vaqt**: `O(N)`
    Algoritm faqat bir marta `N` ta uyning konfet sonlarini o'qib chiqadi. Siklning har bir iteratsiyasida doimiy vaqt oladigan (masalan, qo'shish, modulo olish, taqqoslash, increment) amallar bajariladi. Shuning uchun umumiy vaqt murakkabligi `O(N)` ni tashkil qiladi.
-   **Xotira**: `O(1)`
    Algoritm faqat bir nechta o'zgaruvchidan ( `n`, `ans`, `count_even_prefix_sums`, `count_odd_prefix_sums`, `current_prefix_sum_parity`, `c_i`) foydalanadi. Bu o'zgaruvchilarning soni `N` ga bog'liq emas, doimiydir. Shuning uchun xotira murakkabligi `O(1)` ni tashkil qiladi.
-   Nega shu murakkablik chegaraga sig'adi:
    `N` ning maksimal qiymati `10^6` bo'lganligi sababli, `O(N)` vaqt murakkabligi 2000 ms vaqt limitiga to'liq sig'adi (taxminan `10^6` operatsiya sekundiga yaxshi CPU'larda bajariladi). `O(1)` xotira murakkabligi esa 128 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi (kirish/chiqish, boshqalar)

using namespace std; // std nom fazosidan foydalanish

int main() {
    // Kiritish/chiqish operatsiyalarini tezlashtirish uchun kod
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n; // Uylar soni
    cin >> n; // N ni o'qiymiz

    long long ans = 0; // Juft konfet yig'indisi bo'lgan (L, R) juftliklari soni. Katta son bo'lishi mumkin, shuning uchun long long.
    int count_even_prefix_sums = 1; // Juft bo'lgan prefix sum'lar soni. P[0] = 0 (juft) bo'lgani uchun 1 dan boshlaymiz.
    int count_odd_prefix_sums = 0; // Toq bo'lgan prefix sum'lar soni. Dastlab hech qanday toq prefix sum yo'q.
    int current_prefix_sum_parity = 0; // Joriy prefix sum'ning juft-toqligi (0 - juft, 1 - toq). P[0] = 0 bo'lgani uchun 0 dan boshlaymiz.

    // Har bir uydan olinadigan konfet soni C_i ni o'qib chiqish uchun sikl
    for (int i = 0; i < n; ++i) {
        int c_i; // Joriy uyda C_i konfet bor
        cin >> c_i; // C_i ni o'qiymiz

        // Joriy prefix sum'ning juft-toqligini yangilaymiz.
        // (P[i-1] % 2 + C_i % 2) % 2 = P[i] % 2
        current_prefix_sum_parity = (current_prefix_sum_parity + (c_i % 2)) % 2;

        // Agar joriy prefix sum juft bo'lsa
        if (current_prefix_sum_parity == 0) {
            // Javobga avvalgi juft prefix sum'lar sonini qo'shamiz.
            // Chunki P[i] juft bo'lsa, oldingi har qanday juft P[k] bilan P[i] - P[k] juft bo'ladi.
            ans += count_even_prefix_sums;
            // O'zimizni (P[i]) ham kelajakdagi hisob-kitoblar uchun juft prefix sum sifatida qayd etamiz.
            count_even_prefix_sums++;
        } else { // Agar joriy prefix sum toq bo'lsa
            // Javobga avvalgi toq prefix sum'lar sonini qo'shamiz.
            // Chunki P[i] toq bo'lsa, oldingi har qanday toq P[k] bilan P[i] - P[k] juft bo'ladi.
            ans += count_odd_prefix_sums;
            // O'zimizni (P[i]) ham kelajakdagi hisob-kitoblar uchun toq prefix sum sifatida qayd etamiz.
            count_odd_prefix_sums++;
        }
    }

    cout << ans << endl; // Yakuniy javobni chop etamiz

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
```

## Edge case lar va eslatmalar
*   **`N=1` holati:** Agar faqat bitta uy bo'lsa (`N=1`), `(L, R)` juftligi faqat `(1, 1)` bo'lishi mumkin. Agar `C_1` juft bo'lsa, javob `1` bo'ladi. Agar `C_1` toq bo'lsa, javob `0` bo'ladi. Kod bu holatni to'g'ri ishladi: agar `C_1` toq bo'lsa, `current_prefix_sum_parity` `1` bo'ladi, `ans += count_odd_prefix_sums` (ya'ni `ans += 0`) natijasida `ans=0` bo'ladi. Agar `C_1` juft bo'lsa, `current_prefix_sum_parity` `0` bo'ladi, `ans += count_even_prefix_sums` (ya'ni `ans += 1`) natijasida `ans=1` bo'ladi.
*   **`P[0]` ni hisobga olish:** Yechim `P[0] = 0` (juft) oldindan yig'indini `count_even_prefix_sums` ni `1` dan boshlash orqali to'g'ri hisobga oladi. Bu `L=1` bo'lgan juftliklarni aniqlash uchun muhim. Masalan, `(1, R)` juftligi uchun `P[R] - P[0]` hisoblanadi.
*   **`long long` dan foydalanish:** `ans` o'zgaruvchisi `long long` tipida ekanligi juda muhim, chunki `N` `10^6` bo'lganda, mumkin bo'lgan juftliklar soni `N*(N+1)/2` ga yaqin bo'lishi mumkin, bu esa `0.5 * 10^12` gacha yetadi, bu `int` tipining diapazonidan ancha yuqori.
*   **Modul operatori (`%`) ning xususiyatlari:** C++ da manfiy sonlar bilan modul operatori ba'zan kutilmagan natijalar berishi mumkin. Biroq, bu masalada `c_i` har doim musbat (`1 <= C_i <= 10^9`) va `current_prefix_sum_parity` har doim `0` yoki `1` bo'lganligi sababli, faqat musbat sonlar ustida modullo operatsiyasi bajariladi, bu xavfsiz.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M088C) platformasidagi **M088C** raqamli **Shirinlik** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M088C>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M088C, Shirinlik yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
