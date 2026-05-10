---
title: "M079C — O'yin maydonchasi | Robocontest.uz Yechimi"
description: "Robocontest.uz M079C (O'yin maydonchasi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 2000 ms, xotira: 128 MB."
keywords: "robocontest M079C, O'yin maydonchasi yechimi, robocontest O'yin maydonchasi, M079C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M079C_oyin_maydonchasi/
lang: uz
---

# M079C — O'yin maydonchasi

## Masala haqida
Yosh Zarif kvadrat shakldagi qum maydonchasi qurmoqchi. Buning uchun unga bir xil uzunlikdagi 4 ta taxta kerak. U `N` ta har xil uzunlikdagi taxta sotib olgan. Zarif taxtalarni bir necha butun bo'lakka bo'lishi mumkin. U qum maydonining yuzasi imkon qadar katta bo'lishini istaydi. Biz Zarif qurishi mumkin bo'lgan maksimum maydon yuzasini topishimiz kerak.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi – kvadrat maydonchaning tomon uzunligini (`L`) maksimal darajada oshirish. Chunki maydon yuzasi `L * L` bo'lgani uchun `L` ni oshirish yuzani ham oshiradi.

Agar biz `L` uzunlikdagi tomonga ega kvadrat qurishimiz mumkin bo'lsa, undan kichikroq `L'` (ya'ni `L' < L`) tomonga ega kvadrat qurishimiz ham mumkin bo'ladi (chunki kichikroq bo'laklar berilgan taxtalardan ko'proq chiqadi). Bu xususiyat, ya'ni yechimning **monotonligi**, **ikilik qidiruv (binary search)** algoritmini qo'llash imkonini beradi. Biz mumkin bo'lgan tomon uzunligi `L` diapazoni bo'yicha ikkilik qidiruv o'tkazamiz va maksimal `L` ni topamiz.

## Algoritm qadamlari
1.  **Kirish ma'lumotlarini o'qish**: `N` soni va `N` ta taxtaning uzunliklari `A` massiviga (yoki `std::vector` ga) o'qib olinadi.
2.  **Ikkilik qidiruv diapazonini aniqlash**:
    *   `low` (quyi chegara): Kvadrat tomonining eng kichik butun qiymati 1 bo'lishi mumkin (agar 0 bo'lsa, maydon yuzasi 0). Shuning uchun `low = 1` deb boshlaymiz.
    *   `high` (yuqori chegara): Taxtalarning maksimal uzunligi $10^9$. Demak, kvadrat tomonining maksimal uzunligi ham $10^9$ dan oshmaydi. Shuning uchun `high = 10^9` deb belgilaymiz.
    *   `ans_L` (javob tomoni): Maksimal topilgan tomon uzunligini saqlash uchun `0` ga initsializatsiya qilamiz.
3.  **Ikkilik qidiruvni bajarish**:
    *   `low <= high` sharti bajarilar ekan, tsikl davom etadi.
    *   `mid` ni hisoblaymiz: `mid = low + (high - low) / 2`. Bu butun sonlar diapazonida `mid` ni xavfsiz hisoblash usuli bo'lib, `low + high` yig'indisining **overflow (qiymatning tur sig'imidan oshib ketishi)** bo'lishining oldini oladi.
    *   `check(mid, A)` funksiyasini chaqiramiz. Bu funksiya `mid` uzunlikdagi tomonga ega kvadrat qurish mumkinligini tekshiradi:
        *   Agar `mid` nolga teng bo'lsa, `false` qaytaradi, chunki nol uzunlikli taxta yaroqsiz.
        *   Har bir taxta `length_i` uchun, `length_i / mid` orqali `mid` uzunlikdagi nechta butun bo'lak olish mumkinligini hisoblaydi.
        *   Barcha olingan bo'laklar sonini jamlab, agar `4` yoki undan ko'proq bo'lak hosil bo'lsa, `true` qaytaradi, aks holda `false`.
    *   Agar `check(mid, A)` funksiyasi `true` qaytarsa (ya'ni `mid` uzunlikdagi tomon bilan kvadrat qurish mumkin):
        *   `ans_L = mid` ni yangilaymiz, chunki bu `mid` yaroqli yechimdir.
        *   Kattaroq tomon uzunligini topishga harakat qilib, `low = mid + 1` deb `low` ni yuqoriga siljitamiz.
    *   Agar `check(mid, A)` funksiyasi `false` qaytarsa (ya'ni `mid` uzunlikdagi tomon bilan kvadrat qurish mumkin emas):
        *   `mid` juda katta ekanligini anglatadi, shuning uchun kichikroq tomon uzunligini qidirish uchun `high = mid - 1` deb `high` ni pastga siljitamiz.
4.  **Natijani chiqarish**: Ikkilik qidiruv tugaganidan so'ng, `ans_L` o'zida maksimal mumkin bo'lgan kvadrat tomon uzunligini saqlaydi. Natija sifatida `ans_L * ans_L` ni chop etamiz. Maydon yuzasini saqlash uchun `long long` ma'lumot turi ishlatilishi shart, chunki $10^9 * 10^9 = 10^{18}$ `int` turiga sig'maydi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(N * log(MAX_L))`
    *   Ikkilik qidiruv `log(MAX_L)` marta takrorlanadi, bu yerda `MAX_L` $10^9$ (eng katta taxta uzunligi). `log_2(10^9)` taxminan 30 ga teng.
    *   Har bir ikkilik qidiruv iteratsiyasida `check` funksiyasi chaqiriladi. `check` funksiyasi barcha `N` ta taxtani bir marta ko'rib chiqadi, ya'ni `O(N)` vaqt oladi.
    *   Demak, umumiy vaqt murakkabligi `N * log(MAX_L)` bo'ladi. Masala cheklovlariga ko'ra, `N = 10^6` va `log(MAX_L) = 30` bo'lsa, `10^6 * 30 = 3 * 10^7` operatsiya bajariladi. Bu berilgan 2000 ms (2 soniya) vaqt limiti ichida bemalol bajariladi.
-   **Xotira murakkabligi**: `O(N)`
    *   `N` ta taxta uzunligini saqlash uchun `std::vector<int> A` ishlatiladi. Bu `N` ga proportsional xotira talab qiladi.
    *   `N = 10^6` va `int` 4 bayt bo'lsa, `10^6 * 4 B = 4 MB` xotira ishlatiladi. Bu berilgan 128 MB xotira limiti ichida bemalol sig'adi.

## Kod izohi

```cpp
#include <iostream> // Kiritish/chiqarish funksiyalari uchun
#include <vector>   // Dinamik massiv (vektor) ishlatish uchun
#include <numeric>  // Bu yerda bevosita ishlatilmagan
#include <algorithm> // Bu yerda bevosita ishlatilmagan

// check funksiyasi: Berilgan L uzunlikdagi taxtalardan kamida 4 ta olish mumkinligini tekshiradi.
// L: kvadrat tomonining taxmin qilingan uzunligi
// A: taxta uzunliklari massivi
bool check(long long L, const std::vector<int>& A) {
    if (L == 0) {
        return false; // L=0 bo'lsa, bu yaroqsiz tomon uzunligi. Maydon 0 bo'ladi.
    }
    long long total_pieces = 0; // Jami L uzunlikdagi olinishi mumkin bo'lgan bo'laklar soni
    for (int length_i : A) {    // Har bir taxta uzunligi bo'yicha iteratsiya
        total_pieces += length_i / L; // length_i taxtadan L uzunlikdagi nechta bo'lak chiqishini hisoblaymiz (butun bo'lish)
        if (total_pieces >= 4) { // Agar jami bo'laklar 4 taga yetsa, ko'proq tekshirish shart emas
            return true;         // Demak, L uzunlikdagi tomon bilan kvadrat qurish mumkin
        }
    }
    return total_pieces >= 4; // Tsikl tugagandan keyin ham 4 ta bo'lak yig'ilgan bo'lsa, true qaytaradi
}

int main() {
    // Kiritish/chiqarish (I/O) operatsiyalarini tezlashtirish uchun standard kod
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N; // Taxtalar sonini o'qish

    std::vector<int> A(N); // Taxta uzunliklarini saqlash uchun vektor yaratish
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Har bir taxta uzunligini o'qib, vektorga joylash
    }

    long long low = 1; // Ikkilik qidiruvning quyi chegarasi (eng kichik mumkin bo'lgan tomon uzunligi)
    long long high = 1000000000; // Ikkilik qidiruvning yuqori chegarasi (eng katta taxta uzunligi $10^9$)
    long long ans_L = 0; // Javobning tomon uzunligi (maksimal L), boshida 0 ga teng

    // Ikkilik qidiruv tsikli
    while (low <= high) {
        long long mid = low + (high - low) / 2; // O'rta qiymatni hisoblash (overflowdan saqlanish uchun)
        if (check(mid, A)) { // Agar mid uzunlikdagi tomon bilan kvadrat qurish mumkin bo'lsa
            ans_L = mid;     // Bu mumkin bo'lgan javobni saqlaymiz
            low = mid + 1;   // Kattaroq tomonni qidirishga harakat qilamiz, shuning uchun quyi chegarani oshiramiz
        } else { // Agar mid uzunlikdagi tomon bilan kvadrat qurish mumkin bo'lmasa
            high = mid - 1; // mid juda katta ekanligini anglatadi, shuning uchun yuqori chegarani kamaytiramiz
        }
    }

    // Maksimal topilgan tomon uzunligi ans_L bo'lsa, maydon ans_L * ans_L ga teng.
    // Natijani long long turida chop etish muhim, chunki u $10^9 * 10^9 = 10^{18}$ gacha bo'lishi mumkin.
    std::cout << ans_L * ans_L << std::endl;

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
```

## Edge case lar va eslatmalar
*   **`N=1` holati**: Agar faqat bitta taxta bo'lsa va undan 4 ta bir xil uzunlikdagi bo'lak olish mumkin bo'lsa (masalan, bitta 100 uzunlikdagi taxtadan 25 uzunlikdagi 4 ta bo'lak), algoritm `ans_L = 25` ni topadi va `625` ni chop etadi. Agar 4 ta bo'lak olish mumkin bo'lmasa, `ans_L` `0` bo'lib qoladi va `0` chop etiladi. Algoritm bu holatlarni to'g'ri boshqaradi.
*   **`L=0` holati**: `check` funksiyasida `L=0` uchun maxsus tekshiruv mavjud. Agar `mid` nolga teng bo'lib qolsa, bu holat noto'g'ri hisoblanib, `false` qaytaradi. Bu esa `low` ning har doim `1` dan boshlanishi bilan birga nol uzunlikdagi tomonlarni hisobga olmaslikni ta'minlaydi.
*   **Katta sonlar (`long long`)**: Taxta uzunliklari $10^9$ gacha bo'lishi mumkin, shuning uchun `mid`, `low`, `high` va ayniqsa `ans_L * ans_L` natijasini saqlash uchun `long long` ma'lumot turi ishlatilgan. `int` dan foydalanilsa, `ans_L * ans_L` hisoblashda `overflow` (qiymatning tur sig'imidan oshib ketishi) yuzaga kelishi mumkin, chunki $10^9 * 10^9 = 10^{18}$ `int` turiga sig'maydi.
*   **Tezlashtirish**: `std::ios_base::sync_with_stdio(false); std::cin.tie(0);` qatorlari C++ kiritish/chiqarish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi, bu katta `N` qiymatlarida vaqt limitini saqlashga yordam beradi.
*   `numeric` va `algorithm` sarlavhalari kodda bevosita ishlatilmagan bo'lsa-da, ko'pincha standart kutubxona funksiyalaridan foydalanishda kiritiladi. Bu holatda ularni o'chirib tashlash ham mumkin.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M079C) platformasidagi **M079C** raqamli **O'yin maydonchasi** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M079C>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M079C, O'yin maydonchasi yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
