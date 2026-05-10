---
title: "M064C — K belgili satr | Robocontest.uz Yechimi"
description: "Robocontest.uz M064C (K belgili satr) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M064C, K belgili satr yechimi, robocontest K belgili satr, M064C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M064C_k_belgili_satr/
lang: uz
---

# M064C — K belgili satr

## Masala haqida
Ushbu masalada sizga `K` butun soni va `S` satri beriladi. Dasturdan talab qilingan vazifa shuki, agar `S` satrining uzunligi `K` sonidan katta bo'lsa, `S` ning boshidan `K` ta belgini ajratib olib, uning ortidan "..." (uch nuqta) qo'yib chop etish kerak. Aks holda, ya'ni `S` ning uzunligi `K` dan katta bo'lmasa, `S` satrining o'zini to'liq chop etish talab etiladi.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juda sodda: berilgan `S` satrining uzunligini `K` soni bilan taqqoslash. Agar `S` ning uzunligi `K` dan oshib ketsa, satrni qisqartirish va uch nuqta qo'shish kerak bo'ladi. Aks holda, satrni o'z holicha qoldirish va chop etish lozim. Bu shartli operator (if-else) va satrning ma'lum bir qismini ajratib olish (substring) funksiyasidan foydalanishni talab qiladi.

## Algoritm qadamlari
1.  Kirish ma'lumotlari: `K` butun sonini va `S` satrini o'qing.
2.  `S` satrining uzunligini (`s.length()`) `K` soni bilan solishtiring.
3.  **Agar** `s.length()` `K` dan katta bo'lsa:
    a.  `S` satrining boshidan (0-indeksdan) boshlab `K` ta belgini ajratib oling.
    b.  Ajratib olingan qismga "..." (uch nuqta) belgisini qo'shib, natijani chop eting.
4.  **Aks holda** (ya'ni, `s.length()` `K` dan kichik yoki unga teng bo'lsa):
    a.  `S` satrining o'zini to'liq chop eting.

## Murakkablik tahlili
-   **Vaqt**: `O(L)`
    *   `K` sonini va `S` satrini o'qish `O(L)` vaqt oladi, bu yerda `L` — `S` satrining uzunligi.
    *   `s.length()` funksiyasi satr uzunligini `O(1)` doimiy vaqtda qaytaradi.
    *   `s.substr(0, k)` funksiyasi `K` ta belgini ajratib olishi uchun `O(K)` vaqt talab qiladi.
    *   Chop etish amali ajratilgan `K` belgini va "..." ni o'z ichiga olgan yangi satr yaratish va chiqarish uchun `O(K)` vaqt oladi. Aks holda, `S` ning o'zini chop etish `O(L)` vaqt oladi.
    *   Eng yomon holatda (`K` `L` ga yaqin bo'lganda), umumiy vaqt murakkabligi `O(L)` ga teng bo'ladi. Masalada `L` ning maksimal qiymati 100 bo'lganligi sababli, bu operatsiyalar juda tez bajariladi va berilgan vaqt chegarasiga (1000 ms) bemalol sig'adi.

-   **Xotira**: `O(L)`
    *   `S` satrini saqlash uchun `L` miqdorida xotira talab qilinadi.
    *   Agar `s.substr(0, k)` yangi satr hosil qilsa, bu qo'shimcha `K` belgilik xotira talab qilishi mumkin.
    *   Eng yomon holatda, `L` va `K` maksimal 100 ga teng bo'lishi mumkin, shuning uchun talab qilinadigan xotira juda kam (taxminan 100-200 bayt) va berilgan xotira chegarasiga (32 MB) bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Barcha standart kutubxonalarni o'z ichiga oladi.
                         // Asosan iostream (kirish/chiqarish) va string (satrlar bilan ishlash) kerak.

using namespace std; // std:: prefiksidan foydalanmaslik uchun standart nomfazodan foydalanish.

int main() { // Dasturning asosiy bajarilish nuqtasi.
    ios_base::sync_with_stdio(false); // C++ kirish/chiqarish oqimlarini C tilining
    cin.tie(0);                      // kirish/chiqarish oqimlari bilan sinxronizatsiyasini o'chiradi.
                                     // Bu kirish/chiqarish amallarini tezlashtiradi,
                                     // ayniqsa katta hajmdagi ma'lumotlar bilan ishlashda foydali.

    int k; // K butun sonini saqlash uchun o'zgaruvchi e'lon qilish.
    cin >> k; // K sonini kiritish.

    string s; // S satrini saqlash uchun o'zgaruvchi e'lon qilish.
    cin >> s; // S satrini kiritish.

    // Satrning uzunligini K soni bilan solishtirish.
    if (s.length() > k) { 
        // Agar satr uzunligi K dan katta bo'lsa:
        // s.substr(0, k) - S satrining boshidan (0-indeksdan) K ta belgini ajratib oladi.
        // "... " - ajratib olingan qismga uch nuqtani qo'shadi.
        // endl - chop etilgandan so'ng yangi qatorga o'tishni bildiradi.
        cout << s.substr(0, k) << "..." << endl;
    } else {
        // Agar satr uzunligi K dan katta bo'lmasa (kichik yoki teng bo'lsa):
        // S satrining o'zini to'liq chop etish.
        cout << s << endl;
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Minimal `K` qiymati**: `K` ning minimal qiymati 1 ga teng. Bu shuni anglatadiki, satrdan har doim kamida bitta belgi chop etish talab qilinadi (agar satr bo'sh bo'lmasa).
*   **Bo'sh satr emasligi**: `S` satri bo'sh emasligi kafolatlangan, shuning uchun bo'sh satrni qayta ishlash haqida tashvishlanish shart emas.
*   **`S` uzunligi `K` ga teng bo'lsa**: Agar `S` satrining uzunligi `K` ga teng bo'lsa (`s.length() == k`), `s.length() > k` sharti noto'g'ri bo'ladi va `else` bloki bajariladi, ya'ni `S` satrining o'zi to'liq chop etiladi. Bu masalaning talabiga mos keladi (1-misol: K=5, S="hello", output="hello").
*   **`S` uzunligi `K` dan kichik bo'lsa**: Agar `S` satrining uzunligi `K` dan kichik bo'lsa (`s.length() < k`), bu holatda ham `s.length() > k` sharti noto'g'ri bo'ladi va `else` bloki bajarilib, `S` satri to'liq chop etiladi. Bu ham masalaning talabiga mos keladi (3-misol: K=7, S="aaa", output="aaa").
*   **Belgi turlari**: `S` satri faqat ingliz alifbosining kichik harflaridan tashkil topishi aytilgan. Boshqa maxsus belgilar yoki katta harflar bilan ishlash haqida tashvishlanish shart emas.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M064C) platformasidagi **M064C** raqamli **K belgili satr** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M064C>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M064C, K belgili satr yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
