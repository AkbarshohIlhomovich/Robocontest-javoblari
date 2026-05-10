---
title: "M070A — Extensions (uzaytirgichlar) | Robocontest.uz Yechimi"
description: "Robocontest.uz M070A (Extensions (uzaytirgichlar)) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 512 MB."
keywords: "robocontest M070A, Extensions (uzaytirgichlar) yechimi, robocontest Extensions (uzaytirgichlar), M070A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M070A_extensions_uzaytirgichlar/
lang: uz
---

# M070A — Extensions (uzaytirgichlar)

## Masala haqida
Nodirda \(N\) ta uzaytirgich (pilot) bor, ularning har birida mos ravishda \(a[i]\) ta rozetka mavjud. Uning uyida faqat bitta energiya manbai bor va cheksiz miqdorda telefonlarni quvvatlantirishi kerak. Masala shartiga ko'ra, uzaytirgichlarni bir-biriga shunday ulash kerakki, maksimal darajada ko'p telefonni quvvatlantirish imkoniyati yaratilsin. Yechim sifatida maksimal nechta telefonni quvvatlantirish mumkinligini topish talab qilinadi.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi – uzaytirgichlar zanjirini optimal tarzda qurishdir. Har bir uzaytirgich o'zining ma'lum miqdordagi rozetkalariga ega. Biroq, agar uzaytirgich devordagi energiya manbaiga to'g'ridan-to'g'ri ulanmasa, u boshqa bir uzaytirgichning rozetkasidan quvvat olishi kerak bo'ladi. Bu degani, har bir "qo'shimcha" uzaytirgich o'zini energiya manbaiga ulash uchun bitta rozetkani "sarflaydi".

Bizning maqsadimiz – telefonlar uchun mavjud bo'lgan rozetkalar sonini maksimallashtirish. Buning uchun barcha uzaytirgichlardagi umumiy rozetkalar sonini hisoblaymiz va shu yig'indidan uzaytirgichlarni bir-biriga ulash uchun sarflanadigan rozetkalar sonini ayiramiz. \(N\) ta uzaytirgichni bitta energiya manbaidan quvvatlantirish uchun, ulardan bittasi devor rozetkasiga ulanadi (u o'zining rozetkalarini ulanish uchun ishlatmaydi). Qolgan \(N-1\) ta uzaytirgich esa bir-biriga (yoki devorga ulangan uzaytirgichga) ulanadi. Har bir bunday ulanish bitta rozetkani talab qiladi. Demak, jami \(N-1\) ta rozetka uzaytirgichlarning o'zaro ulanishlari uchun ishlatiladi.

## Algoritm qadamlari
1.  **\(N\) sonini o'qish**: Birinchi qatordan uzaytirgichlar soni \(N\) o'qiladi.
2.  **Jami rozetkalar yig'indisini hisoblash**: Barcha \(N\) ta uzaytirgichdagi rozetkalar soni \(a_i\) ketma-ket o'qiladi va ularning yig'indisi `total_sockets` o'zgaruvchisiga jamlanadi.
3.  **Ulanish uchun sarflangan rozetkalarni aniqlash**: \(N\) ta uzaytirgichni bitta manbadan quvvatlantirish uchun \(N-1\) ta rozetka uzaytirgichlarni bir-biriga ulash uchun ishlatiladi (rasmga qarang: bitta pilot devorga ulanadi, qolganlari birin-ketin boshqa pilotlarga ulanadi. Har bir qo'shimcha pilot ulanish uchun bitta rozetka band qiladi).
4.  **Telefonlar uchun mavjud rozetkalarni hisoblash**: `total_sockets` dan `N-1` ni ayirish orqali telefonlar uchun qancha rozetka mavjudligini topamiz.
5.  **Natijani chiqarish**: Hisoblangan maksimal telefonlar soni ekranga chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(\(N\))
    *   Algoritm kirish ma'lumotlarini (N va N ta \(a_i\) sonlarini) o'qish uchun bitta sikl (loop) ishlatadi. Bu sikl \(N\) marta takrorlanadi. Sikl ichidagi har bir amal (sonni o'qish, qo'shish) doimiy vaqtda (O(1)) bajariladi. Shuning uchun, algoritmning umumiy vaqt murakkabligi \(N\) ga proporsional bo'lib, O(\(N\)) ni tashkil etadi.
    *   Chegaralar \(N \le 10^5\) bo'lganligi sababli, O(\(N\)) vaqt murakkabligi 1 soniyalik vaqt limitiga bemalol sig'adi.

-   **Xotira murakkabligi**: O(1)
    *   Algoritm faqat bir nechta o'zgaruvchilarni (N, `a_i`, `total_sockets`, `result`) saqlash uchun doimiy miqdordagi xotiradan foydalanadi. Kirish ma'lumotlarining kattaligidan qat'i nazar, qo'shimcha xotira talab qilinmaydi. Shuning uchun xotira murakkabligi O(1) ni tashkil etadi.
    *   Bu doimiy xotira foydalanishi 512 MB xotira limitiga bemalol sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi
using namespace std;     // Standart nomfazodan foydalanishni belgilaydi

int main() {
    // Kiritish/chiqarish (I/O) tezligini optimallashtirish. 
    // Bu C++ streamlarini C standart I/O bilan sinxronizatsiyasini o'chiradi
    // va cout/cin bufyerini bog'liq bo'lmagan holda ishlatishga imkon beradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int N; // Uzaytirgichlar soni
    cin >> N; // N ni o'qish

    long long total_sockets = 0; // Barcha uzaytirgichlardagi jami rozetkalar soni.
                                 // N * a_i maksimal 10^5 * 100 = 10^7 bo'lishi mumkin,
                                 // bu intga sig'sa ham, katta yig'indilar uchun long long ishlatish xavfsizroq.
    
    // Har bir uzaytirgichdagi rozetkalar sonini o'qish va yig'ish
    for (int i = 0; i < N; ++i) {
        int a_i; // Joriy uzaytirgichdagi rozetkalar soni
        cin >> a_i; // a_i ni o'qish
        total_sockets += a_i; // Umumiy yig'indiga qo'shish
    }

    // Har bir uzaytirgich (birinchisidan tashqari) tarmoqqa ulanish uchun 1 ta rozetkani ishlatadi.
    // Shunday qilib, N ta uzaytirgichni bitta asosiy manbadan quvvatlantirish uchun,
    // birinchi uzaytirgich devor rozetkasiga ulanadi, qolgan N-1 ta uzaytirgich esa
    // boshqa uzaytirgichlarning rozetkalariga ulanadi.
    // Bu jami N-1 ta rozetkani o'zaro ulanishlar uchun ishlatilishini anglatadi.
    // Umumiy rozetkalar sonidan bu N-1 ta rozetkani ayirsak, telefonlar uchun mavjud bo'lgan
    // maksimal rozetkalar sonini olamiz.
    long long result = total_sockets - (N - 1); 

    cout << result << endl; // Natijani chiqarish

    return 0; // Dastur muvaffaqiyatli yakunlanganligini bildirish
}
```

## Edge case lar va eslatmalar
*   **\(N=1\) holati**: Agar bitta uzaytirgich bo'lsa (\(N=1\)), u to'g'ridan-to'g'ri devor rozetkasiga ulanadi. Ulanish uchun boshqa uzaytirgichlar yo'q, shuning uchun `N-1 = 0`. Formula bo'yicha `total_sockets - (1-1) = total_sockets`. Ya'ni, uzaytirgichdagi barcha rozetkalar telefonlar uchun mavjud bo'ladi. Bu holat algoritmda to'g'ri hisoblanadi.
*   **`a_i` ning minimal qiymati**: Masala shartiga ko'ra, har bir `a_i >= 2`. Bu degani, har bir uzaytirgichda kamida 2 ta rozetka bor. Bu esa har doim ijobiy natija chiqishini kafolatlaydi, chunki har bir uzaytirgich hech bo'lmaganda bitta telefonni quvvatlay oladi va agar kerak bo'lsa, o'zining bitta rozetkasini boshqa uzaytirgichni ulash uchun bera oladi.
    *   Masalan, \(N=2\), \(a_1=2, a_2=2\) bo'lsa: `total_sockets = 4`. Ulanishlar uchun `N-1 = 1`. Natija `4 - 1 = 3`. Birinchi pilot devorga ulanadi, ikkinchisi birinchi pilotga. Birinchi pilot o'zining bitta rozetkasini ikkinchi pilotga beradi, o'zida bitta rozetka qoladi. Ikkinchi pilot esa ikkita rozetkasini telefonlarga beradi. Jami: 1 + 2 = 3 ta telefon. Bu formulaga mos keladi.
*   **`long long` dan foydalanish**: `total_sockets` o'zgaruvchisi uchun `long long` ma'lumot turi ishlatilishi, \(N\) va \(a_i\) ning maksimal qiymatlarida ( \(N=10^5, a_i=100\), yig'indi \(10^7\) ga yetishi mumkin) int ma'lumot turining chegarasidan oshib ketishining oldini oladi. Garchi `int` ko'pgina tizimlarda \(2 \cdot 10^9\) gacha qiymatlarni saqlay olsa ham, `long long` bunday hisob-kitoblar uchun xavfsizroq va umumiy amaliyot hisoblanadi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M070A) platformasidagi **M070A** raqamli **Extensions (uzaytirgichlar)** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M070A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M070A, Extensions (uzaytirgichlar) yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
