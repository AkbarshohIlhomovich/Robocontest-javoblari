---
title: "A0002 — Dasturchilar kuni | Robocontest.uz Yechimi"
description: "Robocontest.uz A0002 (Dasturchilar kuni) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Oson. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0002, Dasturchilar kuni yechimi, robocontest Dasturchilar kuni, A0002 c++ kod, oson, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /A0002_dasturchilar_kuni/
lang: uz
---

# A0002 — Dasturchilar kuni

## Masala haqida
Bu masala sizdan berilgan yildagi Dasturchilar kuni sanasini aniqlashni talab qiladi. Dasturchilar kuni yilning 255-kunida nishonlanadi, bunda 1-yanvar nolinchi kun deb hisoblanadi. Grigorian taqvimiga koʻra kabisa yilini hisobga olish kerak: yil raqami 400 ga boʻlinadigan yoki 4 ga boʻlinadigan, ammo 100 ga boʻlinmaydigan yillar kabisa yili hisoblanadi. Yakuniy sana `DD/MM/YYYY` formatida chiqarilishi kerak.

## Yondashuv (g'oya)
Yechimning asosiy gʻoyasi — bu yilning birinchi kunidan boshlab kunlarni hisoblash va 256-kunga yetganimizda qaysi oy va kun ekanligini aniqlash. Dasturchilar kuni masalada "255-kunida, 1-yanvar nolinchi kun deb hisoblanadi" deb berilgan. Bu degani, odatda 1-yanvar 1-kun deb hisoblanganda, Dasturchilar kuni aslida yilning `255 + 1 = 256`-kuni bo'ladi. Bu gʻoyani amalga oshirish uchun har bir oyning kunlar sonini saqlaydigan massivdan foydalanamiz va kabisa yilini toʻgʻri aniqlab, fevral oyining kunlari sonini mos ravishda oʻzgartiramiz.

## Algoritm qadamlari
1.  **Kabisa yilini aniqlash funksiyasi:** `is_leap_year` nomli funksiya yaratiladi. Bu funksiya berilgan yilni Grigorian taqvimi qoidalariga koʻra kabisa yili ekanligini tekshiradi:
    *   Agar yil 400 ga qoldiqsiz boʻlinsa, kabisa yili.
    *   Yoki yil 4 ga qoldiqsiz boʻlinsa, lekin 100 ga boʻlinmasa, kabisa yili.
    *   Aks holda, kabisa yili emas.
2.  **Kiritmani oʻqish:** `year` (yil) butun sonini kirish faylidan oʻqib olamiz.
3.  **Oylardagi kunlar roʻyxati:** Har bir oyning standart kunlar sonini (yanvar 31, fevral 28, va hokazo) saqlovchi `days_in_month` nomli `vector` (dinamik massiv) yaratiladi. Dastlabki element (index 0) nol qilib qoldiriladi, bu esa 1-indeksli oylar bilan ishlashni osonlashtiradi.
4.  **Fevralni sozlash:** Agar `is_leap_year` funksiyasi `year` uchun `true` (rost) qaytarsa, ya'ni yil kabisa boʻlsa, `days_in_month` vektoridagi fevral (index 2) oyining kunlari soni 28 dan 29 ga oʻzgartiriladi.
5.  **Dasturchilar kunini topish:**
    *   `target_day_of_year` (yilning maqsadli kuni) 256 ga teng qilinadi (chunki masala 1-yanvarni 0-kun deb hisoblaydi, shuning uchun 255-kun aslida 256-kun).
    *   `current_day_sum` (hozirgacha oʻtgan kunlar yigʻindisi) 0 ga teng qilinadi.
    *   `day` (kun) va `month` (oy) oʻzgaruvchilari nolga initsializatsiya qilinadi.
    *   1-oydan (yanvar) boshlab 12-oygacha (dekabr) tsikl boshlanadi.
    *   Har bir oyda, agar `current_day_sum` ga joriy oyning kunlari sonini qoʻshganimizda `target_day_of_year` ga teng yoki undan katta boʻlib ketsa, demak, Dasturchilar kuni shu oyda joylashgan.
        *   `month` ga joriy oy raqami beriladi.
        *   `day` esa `target_day_of_year` dan `current_day_sum` ni ayirib topiladi.
        *   Tsikl toʻxtatiladi (`break`).
    *   Aks holda, joriy oyning kunlari soni `current_day_sum` ga qoʻshiladi va keyingi oyga oʻtiladi.
6.  **Natijani chiqarish:** Topilgan `day`, `month` va `year` qiymatlari `DD/MM/YYYY` formatida chop etiladi. Bunda `setfill('0')` va `setw()` manipulyatorlaridan foydalanib, bir xonali sonlar oldiga nol qoʻshish (masalan, 9 oyi uchun 09) va yilni toʻrt xonali qilib chiqarish ta'minlanadi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(1)
    *   `is_leap_year` funksiyasi yilning qiymatiga bogʻliq boʻlmagan doimiy arifmetik amallarni bajaradi, shuning uchun uning murakkabligi O(1) ga teng.
    *   Asosiy sikl oylar soni boʻyicha ishlaydi, ya'ni maksimal 12 marta takrorlanadi. Bu ham doimiy son boʻlib, kiritmaning kattaligiga bogʻliq emas.
    *   Shunday qilib, umumiy vaqt murakkabligi doimiy, ya'ni O(1) dir.
-   **Xotira murakkabligi**: O(1)
    *   `days_in_month` `vector`ining hajmi doimiy (13 ta butun son).
    *   Boshqa barcha oʻzgaruvchilar ham doimiy xotira maydoni egallaydi.
    *   Shuning uchun umumiy xotira murakkabligi ham O(1) dir.
-   **Nega shu murakkablik chegaraga sigʻadi**: Berilgan vaqt (1000 ms) va xotira (16 MB) cheklovlari juda qat'iy boʻlsa ham, O(1) vaqt va xotira murakkabligiga ega boʻlgan yechim deyarli har doim bu cheklovlarga sigʻadi. Dastur juda tez ishlaydi va juda kam xotira sarflaydi, bu esa uning optimal ekanligini koʻrsatadi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Ko'plab standart kutubxonalarni o'z ichiga oluvchi umumiy fayl

using namespace std; // Standart nomfazodan foydalanish

// is_leap_year funksiyasi: Berilgan yil kabisa yili ekanligini tekshiradi.
// Grigorian taqvimi qoidalariga amal qiladi:
// - Yil 400 ga bo'linadigan bo'lsa KABISA.
// - Yil 4 ga bo'linib, lekin 100 ga bo'linmaydigan bo'lsa KABISA.
// - Aks holda KABISA EMAS.
bool is_leap_year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    // I/O operatsiyalarini tezlashtirish uchun optimizatsiyalar.
    // C++ ning standart I/O oqimlari (cin, cout) va C standart I/O (printf, scanf)
    // o'rtasidagi sinxronizatsiyani o'chiradi.
    // cin.tie(0) esa cin va cout ni bir-biriga bog'lamaydi, bu ham tezlikni oshiradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int year; // Yilni saqlash uchun o'zgaruvchi
    cin >> year; // Yilni kiritish faylidan o'qish

    // Oylardagi kunlar sonini saqlovchi vektor (dinamik massiv).
    // Index 0 ishlatilmaydi, 1-indexdan boshlab yanvar uchun kunlar soni beriladi.
    vector<int> days_in_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Agar yil kabisa bo'lsa, fevral oyining kunlari sonini 29 ga o'zgartirish.
    if (is_leap_year(year)) {
        days_in_month[2] = 29; // Fevral oyining indexi 2
    }

    // Dasturchilar kuni yilning 255-kuni (1-yanvar 0-kun deb hisoblanganda).
    // Demak, 1-yanvar 1-kun deb hisoblaganda bu 256-kun bo'ladi.
    int target_day_of_year = 256; 

    int current_day_sum = 0; // Joriy kungacha o'tgan kunlar yig'indisi
    int day = 0;             // Topilgan kun
    int month = 0;           // Topilgan oy

    // Oylar bo'yicha tsikl (yanvardan dekabrgacha)
    for (int m = 1; m <= 12; ++m) {
        // Agar joriy oyning kunlari sonini qo'shsak, maqsadli kunga yetsak yoki undan oshib ketsak
        if (current_day_sum + days_in_month[m] >= target_day_of_year) {
            month = m; // Dasturchilar kuni shu oyda
            // Maqsadli kundan oldingi oylardagi kunlar yig'indisini ayirib, aniq kunni topish.
            day = target_day_of_year - current_day_sum;
            break; // Tsiklni to'xtatish, chunki kun topildi
        }
        // Agar maqsadli kunga hali yetmagan bo'lsak, joriy oy kunlarini umumiy yig'indiga qo'shish
        current_day_sum += days_in_month[m];
    }

    // Natijani DD/MM/YYYY formatida chop etish.
    // setfill('0'): Bo'sh joylarni '0' bilan to'ldirish (masalan, 9 oyi uchun 09).
    // setw(2): Kun va oy uchun 2 xonali kenglik belgilash.
    // setw(4): Yil uchun 4 xonali kenglik belgilash.
    cout << setfill('0') << setw(2) << day << "/"
              << setfill('0') << setw(2) << month << "/"
              << setfill('0') << setw(4) << year << endl;

    return 0; // Dastur muvaffaqiyatli yakunlandi
}

```

## Edge case lar va eslatmalar
*   **Kabisa yili qoidalari:** Masalada Grigorian taqvimi bo'yicha kabisa yili aniqlash qoidalari aniq berilgan:
    *   400 ga bo'linadigan yillar (masalan, 2000-yil).
    *   4 ga bo'linadigan, ammo 100 ga bo'linmaydigan yillar (masalan, 2004-yil, 2009-yil kabisa emas).
    Bu qoidalar `is_leap_year` funksiyasida to'g'ri qo'llanilgan.
*   **Dasturchilar kuni indeksi:** "1-yanvar nolinchi kun deb hisoblanadi" degan jumla muhim. Agar 1-yanvar 1-kun boʻlganda edi, 255-kunni izlagan boʻlardik. Lekin 1-yanvar 0-kun boʻlgani uchun, hisob-kitoblarda biz yilning 256-kunini topishimiz kerak (`target_day_of_year = 256`). Bu sample testlar orqali tasdiqlangan.
*   **Kiritma diapazoni:** Yil 1 dan 9999 gacha boʻlgan butun son. Bizning algoritmimiz bu diapazondagi barcha yillar uchun toʻgʻri ishlaydi, chunki yilning qiymati hisob-kitoblarning murakkabligini oʻzgartirmaydi, faqat `is_leap_year` funksiyasining natijasiga ta'sir qiladi.
*   **Chiqish formati:** `DD/MM/YYYY` formatini ta'minlash uchun `iomanip` kutubxonasidagi `setfill('0')` va `setw()` manipulyatorlaridan foydalanish shart. Bular kun va oy uchun ikki xonali, yil uchun toʻrt xonali formatni, kerak boʻlsa oldiga nollar qoʻyib chiqarilishini ta'minlaydi. Masalan, yil 9 bo'lsa `0009` ko'rinishida chiqariladi.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0002) platformasidagi **A0002** raqamli **Dasturchilar kuni** masalasi. U **Oson** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0002>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0002, Dasturchilar kuni yechimi, robocontest masalalari, c++17, olimpiada yechimi, oson, dasturlash uzbek, competitive programming O'zbekiston.</sub>
