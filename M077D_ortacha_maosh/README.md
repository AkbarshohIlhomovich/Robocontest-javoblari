---
title: "M077D — O'rtacha maosh | Robocontest.uz Yechimi"
description: "Robocontest.uz M077D (O'rtacha maosh) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 64 MB."
keywords: "robocontest M077D, O'rtacha maosh yechimi, robocontest O'rtacha maosh, M077D c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M077D_ortacha_maosh/
lang: uz
---

# M077D — O'rtacha maosh

## Masala haqida
Bu masala \(n\) nafar xodimning maoshlari ro'yxati berilganda, direktor ixtiyoriy ketma-ket \(k\) ta xodimni tanlab, ularning maoshlari o'rtachasining eng maksimal qiymatini topishni talab qiladi. Hisobchi direktorga shu maksimal qiymatni aniqlashda yordam berishi kerak.

## Yondashuv (g'oya)
Masalani hal qilish uchun "sirg'anuvchi oyna" (sliding window) texnikasi qo'llaniladi. Bu texnika ma'lum bir uzunlikdagi (bu yerda \(k\)) ketma-ket elementlar guruhining (kichik massiv yoki "oyna") yig'indisini samarali hisoblash imkonini beradi. Har bir \(k\) uzunlikdagi oynaning yig'indisini boshidan hisoblab chiqish o'rniga, oynani massiv bo'ylab bir qadam o'ngga surganimizda, oldingi yig'indidan oynadan chiqqan elementni ayirib, yangi kirgan elementni qo'shamiz. Bu yig'indini har bir qadamda \(O(1)\) (doimiy) vaqtda yangilash imkonini beradi, bu esa umumiy hisoblashni juda tezlashtiradi.

## Algoritm qadamlari
1.  Kirish ma'lumotlari: Dastlab, \(n\) (xodimlar soni) va \(k\) (direktor tanlaydigan ketma-ket xodimlar soni) butun sonlari o'qib olinadi.
2.  Maoshlarni saqlash: Keyin, \(n\) ta xodimning maoshlari `salaries` nomli `std::vector` (dinamik massiv) ga o'qib saqlanadi.
3.  Boshlang'ich yig'indi: Birinchi \(k\) ta xodimning maoshlari yig'indisi hisoblanadi. Bu yig'indi `current_sum` (joriy yig'indi) o'zgaruvchisiga saqlanadi va shu bilan birga `max_sum` (maksimal yig'indi) ga ham tayinlanadi, chunki bu biz ko'rgan birinchi yig'indi hisoblanadi.
4.  Oynani sirg'atish: Massivning qolgan qismi bo'ylab (ya'ni, `k`-chi indeksdan `n-1`-chi indeksgacha) iteratsiya qilinadi. Har bir qadamda (tsikl ichida):
    *   `current_sum` yangilanadi: oynadan chiqib ketayotgan element (`salaries[i - k]`) `current_sum` dan ayiriladi va oynaga kirib kelayotgan yangi element (`salaries[i]`) `current_sum` ga qo'shiladi. Bu, oynani bir qadam o'ngga siljitishni anglatadi.
    *   Maksimal yig'indini yangilash: Agar yangilangan `current_sum` hozirgi `max_sum` dan katta bo'lsa, `max_sum` yangi `current_sum` ga tenglashtiriladi.
5.  O'rtachani hisoblash: Iteratsiya tugagandan so'ng, `max_sum` o'zida barcha \(k\) uzunlikdagi ketma-ket maoshlar yig'indilari ichidagi eng kattasini saqlaydi. Endi `max_average` (maksimal o'rtacha) hisoblanadi: `max_sum` ni `k` ga bo'lish orqali. Hisoblashda aniqlikni ta'minlash uchun `max_sum` `long double` (kengaytirilgan aniqlikdagi suzuvchi nuqta soni) turiga o'tkaziladi.
6.  Natijani chop etish: Natija talab qilingan aniqlikda chop etiladi. Agar `max_sum` `k` ga qoldiqsiz bo'linsa (ya'ni, o'rtacha butun son bo'lsa), natija bitta o'nlik verguldan keyingi raqam bilan (masalan, "80.0") chiqariladi. Aks holda, yuqori aniqlikda (masalan, 14 xona) chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: \(O(N)\)
    -   Kirish ma'lumotlarini (massivni) o'qish uchun \(O(N)\) vaqt talab qilinadi.
    -   Dastlabki \(k\) ta elementning yig'indisini hisoblash \(O(K)\) vaqt oladi.
    -   Sirg'anuvchi oyna butun massiv bo'ylab bir marta (aniqrog'i, \(N-K\) marta) harakatlanadi. Har bir harakat \(O(1)\) (doimiy) vaqtda joriy yig'indini yangilaydi.
    -   Shunday qilib, umumiy vaqt murakkabligi \(O(N + K + (N-K)*1) = O(N)\) bo'ladi, chunki \(K \le N\) shartidan foydalangan holda K ni ham N ga bog'lab yozish mumkin. Bu \(N = 5 \times 10^5\) kabi katta kirishlar uchun juda samarali va berilgan 1000 ms vaqt chegarasiga bemalol sig'adi.

-   **Xotira murakkabligi**: \(O(N)\)
    -   Barcha \(N\) ta maoshni `std::vector<int> salaries` ga saqlash uchun \(O(N)\) xotira talab qilinadi.
    -   Boshqa o'zgaruvchilar (masalan, `n`, `k`, `current_sum`, `max_sum`, `max_average`) uchun sarflangan xotira miqdori doimiy bo'lib, kirish hajmi \(N\) ga bog'liq emas, ya'ni \(O(1)\).
    -   `N = 5 \times 10^5` va har bir `int` 4 bayt bo'lsa, \(5 \times 10^5 \times 4\) bayt = 2 MB xotira talab qilinadi, bu 64 MB xotira chegarasiga bemalol sig'adi.

## Kod izohi

```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun standart kutubxona
#include <vector>   // Dinamik massiv (std::vector) ishlatish uchun
#include <numeric>  // Ba'zi hollarda yig'indini hisoblash uchun ishlatilishi mumkin (bu kodda to'g'ridan-to'g'ri ishlatilmagan)
#include <algorithm> // std::max kabi algoritmlar uchun (bu kodda shartli operator ishlatilgan)
#include <iomanip>  // Chiqishni formatlash (aniqlikni belgilash) uchun

int main() {
    // std::ios_base::sync_with_stdio(false) va std::cin.tie(0)
    // C++ ning standart kirish/chiqish (I/O) streamlarini C ning stdio streamlari bilan sinxronizatsiyasini o'chiradi
    // va std::cin ni std::cout bilan bog'lanishini bekor qiladi. Bu katta hajmdagi
    // ma'lumotlar bilan ishlaganda kirish/chiqish operatsiyalarini tezlashtiradi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k; // n: xodimlar soni, k: ketma-ket tanlanadigan xodimlar soni
    std::cin >> n >> k; // n va k qiymatlarini konsoldan o'qib olish

    std::vector<int> salaries(n); // n ta xodimning maoshlarini saqlash uchun vektor yaratish
    for (int i = 0; i < n; ++i) {
        std::cin >> salaries[i]; // Har bir maoshni o'qib, vektorga saqlash
    }

    long long current_sum = 0; // Joriy oynadagi maoshlar yig'indisini saqlash uchun o'zgaruvchi.
                               // Maoshlar qiymatlari va N ning kattaligi tufayli (5*10^5 * 10^6 = 5*10^11)
                               // 'int' tipidan oshib ketishi mumkin, shuning uchun 'long long' ishlatiladi.
    
    // Dastlabki k ta elementning (birinchi oynaning) yig'indisini hisoblash
    for (int i = 0; i < k; ++i) {
        current_sum += salaries[i];
    }

    long long max_sum = current_sum; // Hozirgacha topilgan eng katta yig'indi.
                                     // Dastlabki k ta element yig'indisini eng kattasi deb qabul qilamiz.

    // Massiv bo'ylab sirg'anuvchi oyna algoritmini qo'llash
    for (int i = k; i < n; ++i) {
        // Oynani bir qadam o'ngga surish:
        // Oynadan chiqib ketayotgan elementni (salaries[i - k]) joriy yig'indidan ayiramiz.
        // Oynaga kirgan yangi elementni (salaries[i]) joriy yig'indiga qo'shamiz.
        current_sum = current_sum - salaries[i - k] + salaries[i];
        
        // Joriy yig'indini maksimal yig'indi bilan solishtiramiz va agar katta bo'lsa, yangilaymiz.
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    // Maksimal o'rtachani hisoblash
    // Aniqlikni ta'minlash uchun 'max_sum' ni 'long double' turiga o'tkazamiz,
    // so'ngra 'k' ga bo'lamiz.
    long double max_average = static_cast<long double>(max_sum) / k;

    // Chiqarish formatini namunaviy natijaga moslashtirish:
    // Agar maksimal yig'indi 'k' ga qoldiqsiz bo'linsa (ya'ni, o'rtacha butun son bo'lsa),
    // natijani bir o'nlik xona aniqligida (masalan, "80.0") chiqarish.
    if (max_sum % k == 0) {
        std::cout << std::fixed << std::setprecision(1) << max_average << std::endl;
    } 
    // Aks holda, yuqori aniqlikda (14 o'nlik xona, masalan, sample 2 dagi kabi) chiqarish.
    else {
        std::cout << std::fixed << std::setprecision(14) << max_average << std::endl;
    }

    return 0; // Dastur muvaffaqiyatli yakunlangani
}
```

## Edge case lar va eslatmalar
*   **`k=1` holati**: Agar \(k=1\) bo'lsa, algoritm to'g'ri ishlaydi va massivdagi eng katta individual maoshni topadi. Bu, bir elementdan iborat oynalarning maksimal yig'indisi va shu bilan birga maksimal o'rtachasi bo'ladi.
*   **Ma'lumot turlari**: `current_sum` va `max_sum` o'zgaruvchilari `long long` tipida e'lon qilingan. Buning sababi, \(N\) va maosh qiymatlari juda katta bo'lishi mumkinligi tufayli (masalan, \(5 \times 10^5\) ta xodimning har birining maoshi \(10^6\) bo'lsa, yig'indi \(5 \times 10^{11}\) ga yetadi), bu qiymat standart `int` (odatda \(2 \times 10^9\) gacha) chegarasidan oshib ketishi mumkin. O'rtacha qiymatni hisoblashda yuqori aniqlikni ta'minlash uchun `long double` dan foydalanilgan.
*   **Chiqarish aniqligi**: Masala 10^-5 absolut xatolik talab qiladi. Kodda ishlatilgan `std::setprecision(14)` `long double` uchun bu aniqlikni qondirishga yetarli. Namuna natijalariga moslashish uchun butun sonli o'rtachalar (masalan, 80.0) alohida formatlangan. Bu yaxshi amaliyot bo'lib, ba'zi test tizimlari uchun muhim bo'lishi mumkin.
*   **I/O Tezlashtirish**: `std::ios_base::sync_with_stdio(false);` va `std::cin.tie(0);` kod qatorlari katta kirish/chiqish (I/O) ma'lumotlari bilan ishlaganda dasturning vaqt chegarasidan oshib ketmasligi uchun muhim. Ular C++ streamlarining ishlashini sezilarli darajada tezlashtiradi.
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M077D) platformasidagi **M077D** raqamli **O'rtacha maosh** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M077D>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M077D, O'rtacha maosh yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
