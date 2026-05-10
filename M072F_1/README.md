---
title: "M072F — 1% | Robocontest.uz Yechimi"
description: "Robocontest.uz M072F (1%) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M072F, 1% yechimi, robocontest 1%, M072F c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M072F_1/
lang: uz
---

# M072F — 1%

## Masala haqida
Bu masala Zarif ismli shaxsning bankdagi omonati bilan bog'liq. Zarif bankka 100 dollar omonat qo'yadi va bank har yili 1% miqdorida foiz to'laydi. Foiz hisoblanganda dollarning kasr qismi inobatga olinmaydi. Masalaning vazifasi shuki, Zarifning balansi $X$ dollar yoki undan yuqori darajaga yetishi uchun necha yil kerak bo'lishini topishdir. $X$ ning qiymati juda katta bo'lishi mumkin (hatto $10^{18}$ gacha).

## Yondashuv (g'oya)
Masalani yechishning asosiy g'oyasi har yili balansga foizlarni qo'shib borish va bu jarayonni balans $X$ qiymatiga yetguncha simulyatsiya qilish (takroriy hisoblash)dir. Har bir yil o'tishi bilan balans o'zgaradi va biz bu o'zgarishlarni kuzatib boramiz. "Bir dollardan kamroq qismi hisobga olinmaydi" sharti C++ dagi butun sonli bo'lish (integer division) orqali osongina amalga oshiriladi, bu esa bo'linmaning faqat butun qismini oladi. Balans juda katta qiymatlarga yetishi mumkin bo'lganligi sababli, `long long` ma'lumot turidan foydalanish zarur.

## Algoritm qadamlari
1.  **Kirish ma'lumotini o'qish**: Kirishdan `X` (maqsad balans) butun sonini o'qib oling.
2.  **Boshlang'ich qiymatlarni o'rnatish**:
    *   `balance` o'zgaruvchisini 100 ga (boshlang'ich omonat) o'rnating.
    *   `years` o'zgaruvchisini 0 ga (o'tgan yillar soni) o'rnating.
    *   Ikkala o'zgaruvchi ham `long long` turida bo'lishi kerak, chunki `balance` $10^{18}$ gacha o'sishi mumkin.
3.  **Takroriy hisoblash (simulyatsiya) tsikli**: `balance` `X` dan kichik ekan, quyidagi qadamlarni takrorlang:
    a.  **Foizni hisoblash**: Joriy `balance` ning 1% ini hisoblang. Bu `balance / 100` ifodasi orqali amalga oshiriladi. C++ da butun sonli bo'lish (integer division) natijani avtomatik ravishda butun songa yaxlitlaydi, ya'ni kasr qismini e'tiborsiz qoldiradi, bu esa masalaning shartiga to'liq mos keladi.
    b.  **Balansni yangilash**: Hisoblangan foizni `balance` ga qo'shing.
    c.  **Yil hisoblagichini oshirish**: `years` o'zgaruvchisini 1 ga oshiring.
4.  **Natijani chop etish**: Tsikl tugagandan so'ng (ya'ni `balance` `X` ga yetganda yoki undan oshganda), `years` o'zgaruvchisining qiymatini chop eting.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(log X)` yoki aniqrog'i `O(Y)`, bu yerda `Y` — balans `X` ga yetishi uchun kerak bo'ladigan yillar soni. Har yili balans kamida 1% ga oshadi (agar balans 100 dan yuqori bo'lsa), bu esa eksponensial o'sishga olib keladi. Balansning `X` ga yetishi uchun zarur bo'lgan yillar soni `X` ning logarifmiga (masalan, `log base 1.01 X`) proporsionaldir. Eng yomon holatda, `X` $10^{18}$ bo'lganda, yillar soni taxminan 3760 ga teng bo'ladi. 3760 ta iteratsiya 1000 ms vaqt limiti uchun juda tez bajariladi (bir necha millisekundda).
-   **Xotira murakkabligi**: `O(1)`. Algoritm faqat bir nechta o'zgaruvchilarni (masalan, `X`, `balance`, `years`, `interest`) saqlash uchun doimiy miqdorda xotira ishlatadi. Bu o'zgaruvchilarning umumiy hajmi bir necha baytni tashkil qiladi, bu esa 32 MB xotira limitiga bemalol sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi. Asosan iostream kirish/chiqish uchun kerak.

using namespace std; // std:: prefiksini ishlatmasdan standart nom fazosidagi elementlarga kirish imkonini beradi.

int main() {
    // I/O operatsiyalarini tezlashtirish uchun ishlatiladi.
    // sync_with_stdio(false) C++ streamlarini C standart I/O bilan sinxronizatsiyasini o'chiradi.
    // cin.tie(0) cin va cout o'rtasidagi bog'lanishni bekor qiladi, bu cin dan keyin cout flush bo'lmasligini ta'minlaydi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long X; // Maqsad balansni saqlash uchun o'zgaruvchi. X katta bo'lishi mumkin ($10^{18}$ gacha), shuning uchun long long ishlatiladi.
    cin >> X;    // Kirishdan X qiymatini o'qib olish.

    long long balance = 100; // Boshlang'ich balans 100 dollar. Katta qiymatlarga yetishi mumkinligi sababli long long.
    int years = 0;           // O'tgan yillar sonini hisoblash uchun o'zgaruvchi. Yillar soni nisbatan kichik bo'ladi (3760 atrofida), shuning uchun int yetarli.

    // Balans X dan kichik ekan, tsikl davom etadi.
    while (balance < X) {
        // Balansning 1% ini hisoblash. Butun sonli bo'lish (integer division)
        // natijaning kasr qismini avtomatik ravishda tashlab yuboradi,
        // bu "bir dollardan kamroq qismi hisobga olinmaydi" shartiga mos keladi.
        long long interest = balance / 100;
        
        balance += interest; // Hisoblangan foizni balansga qo'shish.
        years++;             // Yillar sonini 1 ga oshirish.
    }

    cout << years << endl; // Tsikl tugagandan so'ng (balans X ga yetganda yoki undan oshganda), yillar sonini chop etish.

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **`long long` ishlatish**: Masalaning shartiga ko'ra $X$ ning qiymati $10^{18}$ gacha bo'lishi mumkin. Standart `int` ma'lumot turi bu qadar katta qiymatlarni saqlay olmaydi (odatda $2 \cdot 10^9$ atrofida). Shu sababli, `X` va `balance` o'zgaruvchilari uchun `long long` ma'lumot turidan foydalanish juda muhimdir.
*   **Butun sonli bo'lish (Integer Division)**: C++ dagi butun sonli bo'lish (`balance / 100`) avtomatik ravishda bo'linmaning faqat butun qismini qaytaradi. Bu masalaning "bir dollardan kamroq qismi hisobga olinmaydi" degan shartini bajarishning oddiy va samarali usuli hisoblanadi. Masalan, agar `balance` 101 bo'lsa, `101 / 100` ning natijasi 1 bo'ladi (qoldiq 1 e'tiborsiz qoldiriladi).
*   **Tsikl sharti**: `while (balance < X)` sharti balansi `X` dan kam ekan, yillarni hisoblashni davom ettiradi. Balans `X` ga teng bo'lganda yoki undan oshganda tsikl to'xtaydi va shu nuqtaga qadar o'tgan yillar soni chiqariladi. Bu masalaning "birinchi marta X dollar yoki undan yuqori darajaga yetadi" degan talabini to'g'ri bajaradi.
*   **Minimal $X$ qiymati**: Masala bo'yicha $X \ge 101$. Agar $X=101$ bo'lsa, birinchi yil oxirida balans 101 dollarga yetadi va javob 1 bo'ladi. Kod bu holatni to'g'ri boshqaradi. (100 -> 101, 1 yil).
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M072F) platformasidagi **M072F** raqamli **1%** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M072F>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M072F, 1% yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
