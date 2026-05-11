---
title: "M072C — Antiqa poyga | Robocontest.uz Yechimi"
description: "Robocontest.uz M072C (Antiqa poyga) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M072C, Antiqa poyga yechimi, robocontest Antiqa poyga, M072C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M072C_antiqa_poyga/
lang: uz
---

# M072C — Antiqa poyga

## Masala haqida
Bu masalada Dilshod va uning uchta do'sti yil yakuniga qadar 1000 ta "5" baho to'plash bo'yicha bahslashadi. Ularning har biri yil oxirigacha yana nechta "5" baho to'plashi kerakligi ma'lum. Sizning vazifangiz Dilshoddan ko'ra ko'proq "5" baho to'plagan do'stlari sonini aniqlashdir.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi shundaki, agar biror shaxs yil oxirigacha kamroq "5" baho to'plashi kerak bo'lsa, demak u shu kungacha ko'proq "5" baho to'plagan. Ya'ni, "qolgan baholar soni" qanchalik kichik bo'lsa, "to'plangan baholar soni" shunchalik katta bo'ladi. Shunday qilib, biz har bir do'stning qolgan baholar sonini Dilshodning qolgan baholar soni bilan solishtiramiz. Agar do'stning qolgan baholari Dilshodnikidan kam bo'lsa, u Dilshoddan ko'proq baho to'plagan hisoblanadi.

## Algoritm qadamlari
1.  **Ma'lumotlarni o'qish:** Kirishdan Dilshodning yil yakunigacha qolgan "5" baholari sonini va uning uchta do'stining har birining qolgan "5" baholari sonini o'qib oling.
2.  **Hisoblagichni ishga tushirish:** Dilshoddan ko'proq baho to'plagan do'stlarning sonini hisoblash uchun `count_friends_with_more_fives` nomli o'zgaruvchini `0` ga tenglab oling.
3.  **Har bir do'stni solishtirish:**
    *   Birinchi do'stning qolgan baholari sonini Dilshodning qolgan baholari soni bilan solishtiring. Agar birinchi do'stning qolgan baholari Dilshodning qolgan baholaridan kichik bo'lsa, `count_friends_with_more_fives` ni bittaga oshiring.
    *   Xuddi shu tarzda, ikkinchi do'stni Dilshod bilan solishtiring va kerak bo'lsa hisoblagichni oshiring.
    *   Uchinchi do'stni ham Dilshod bilan solishtiring va kerak bo'lsa hisoblagichni oshiring.
4.  **Natijani chop etish:** Yakuniy `count_friends_with_more_fives` qiymatini ekranga chop eting.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(1)` (Doimiy vaqt murakkabligi). Algoritm kirish ma'lumotlari hajmidan qat'i nazar, har doim bir xil miqdordagi amallarni bajaradi (4 ta sonni o'qish, 3 ta solishtirish, 1 ta sonni chop etish). Bu doimiy amallar soni demakdir.
-   **Xotira murakkabligi**: `O(1)` (Doimiy xotira murakkabligi). Algoritm bir nechta butun sonli o'zgaruvchilarni (Dilshod va do'stlarining qolgan baholari, shuningdek hisoblagich) saqlash uchun doimiy miqdorda xotira ishlatadi. Kirish ma'lumotlari hajmi qancha bo'lishidan qat'i nazar, ishlatiladigan xotira miqdori o'zgarmaydi.
-   **Nega shu murakkablik chegaraga sig'adi**: Berilgan vaqt (1000 ms) va xotira (32 MB) chegaralari uchun `O(1)` murakkablik juda samarali hisoblanadi va muammosiz bajariladi.

## Kod izohi

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Kiritish/chiqarish (I/O) operatsiyalarini tezlashtirish uchun sozlamalar.
    // sync_with_stdio(false) C++ streamlarini C standart I/O bilan sinxronizatsiyadan chiqaradi.
    // cin.tie(0) esa cin va cout ni bog'liqligini uzadi, natijada cin dan keyin cout flush qilinmaydi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Dilshod va uning do'stlarining 1000 ta "5" bahogacha qolgan sonlarini saqlash uchun o'zgaruvchilar.
    int dilshod_rem; // Dilshodga qolgan baholar
    int friend1_rem; // 1-do'stga qolgan baholar
    int friend2_rem; // 2-do'stga qolgan baholar
    int friend3_rem; // 3-do'stga qolgan baholar

    // Kirishdan 4 ta sonni o'qish.
    cin >> dilshod_rem >> friend1_rem >> friend2_rem >> friend3_rem;

    // Dilshoddan ko'proq "5" baho to'plagan do'stlar sonini hisoblash uchun hisoblagich.
    int count_friends_with_more_fives = 0;

    // Izoh: Talaba Dilshoddan ko'proq "5" baho to'plagan bo'ladi, agar uning 1000 tagacha qolgan "5" baholari Dilshodnikidan kam bo'lsa.
    // Misol uchun, agar Dilshodga 50 ta qolgan bo'lsa (demak 950 ta to'plagan),
    // va do'stga 40 ta qolgan bo'lsa (demak 960 ta to'plagan), do'st ko'proq to'plagan bo'ladi.
    
    // Har bir do'stni Dilshod bilan solishtirish.
    if (friend1_rem < dilshod_rem) {
        // Agar 1-do'stga qolgan baholar Dilshodga qolgan baholardan kam bo'lsa,
        // demak 1-do'st Dilshoddan ko'proq "5" baho to'plagan. Hisoblagichni oshiramiz.
        count_friends_with_more_fives++;
    }
    if (friend2_rem < dilshod_rem) {
        // Xuddi shu mantiq 2-do'st uchun.
        count_friends_with_more_fives++;
    }
    if (friend3_rem < dilshod_rem) {
        // Xuddi shu mantiq 3-do'st uchun.
        count_friends_with_more_fives++;
    }

    // Yakuniy natijani, ya'ni Dilshoddan ko'proq "5" baho to'plagan do'stlar sonini chop etish.
    cout << count_friends_with_more_fives << endl;

    // Dastur muvaffaqiyatli yakunlangani haqida tizimga xabar berish.
    return 0;
}
```

## Edge case lar va eslatmalar
*   **Kirish qiymatlari chegarasi**: Kirishdagi sonlar 1000 dan oshmaydi. Bu degani, qolgan baholar soni `[0, 1000]` oralig'ida bo'ladi. Agar `0` bo'lsa, bu shaxs 1000 ta "5" bahoni to'plab bo'lganini anglatadi.
*   **Teng holat**: Agar do'stning qolgan baholari soni Dilshodning qolgan baholari soniga teng bo'lsa (`friend_rem == dilshod_rem`), bu ular bir xil miqdordagi "5" baho to'plaganligini anglatadi. Masala "ko'proq baho to'plaganini" so'ragani uchun, kod `friend_rem < dilshod_rem` shartidan foydalanadi va teng holatni hisobga olmaydi, bu to'g'ri.
*   **Salbiy qiymatlar yo'qligi**: Kirish natural sonlar bo'lganligi sababli, salbiy qiymatlar bo'lmaydi, bu hisob-kitoblarni soddalashtiradi.
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M072C) platformasidagi **M072C** raqamli **Antiqa poyga** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M072C>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M072C, Antiqa poyga yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
