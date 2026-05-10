---
title: "M038B — Kvadrat | Robocontest.uz Yechimi"
description: "Robocontest.uz M038B (Kvadrat) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M038B, Kvadrat yechimi, robocontest Kvadrat, M038B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M038B_kvadrat/
lang: uz
---

# M038B — Kvadrat

## Masala haqida
Sizga bitta butun `A` soni berilgan bo'lib, uning qiymati $4 \times 10^5$ dan oshmaydi. Vazifangiz ushbu sonning kvadratini hisoblash va natijani chop etishdir. Bu masala sonlarni kiritish va oddiy arifmetik amallarni bajarishni sinovdan o'tkazadi.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi juda sodda: berilgan sonni o'zi bilan ko'paytirish (ya'ni uning kvadratini hisoblash). Bu masala uchun maxsus algoritm yoki murakkab ma'lumot tuzilmalari talab qilinmaydi, chunki sonning qiymati hisob-kitobni to'g'ridan-to'g'ri bajarishga imkon beradi. Faqatgina natija juda katta bo'lishi mumkinligi sababli, to'g'ri ma'lumot turini tanlashga e'tibor berish lozim.

## Algoritm qadamlari
1. Kirish faylidan bitta butun son `A` ni o'qing.
2. `A` sonini o'zi bilan ko'paytiring, ya'ni `A * A` amalini bajaring. Natijani saqlash uchun `long long` kabi yetarlicha katta ma'lumot turini ishlating, chunki kvadratning qiymati `int` turining chegarasidan oshib ketishi mumkin.
3. Hisoblangan kvadrat natijasini chiqish fayliga chop eting.

## Murakkablik tahlili
Bu masala juda sodda bo'lganligi sababli, uning murakkabligi ham minimaldir.
- **Vaqt**: O(1)
    Dastur faqat bitta sonni o'qiydi, bitta arifmetik amal (ko'paytirish)ni bajaradi va natijani chop etadi. Bu operatsiyalar sonning kattaligidan qat'i nazar doimiy vaqtni oladi. Shuning uchun, dasturning vaqt murakkabligi doimiy, ya'ni O(1) ga teng.
- **Xotira**: O(1)
    Dastur faqat bitta butun son `A` ni va uning kvadratini saqlash uchun bir nechta o'zgaruvchi talab qiladi. Bu xotira miqdori sonning qiymatiga bog'liq emas va doimiy ravishda kam miqdorni tashkil etadi. Shuning uchun, dasturning xotira murakkabligi ham doimiy, ya'ni O(1) ga teng.
- O(1) vaqt va O(1) xotira murakkabliklari berilgan vaqt (1000 ms) va xotira (16 MB) limitlariga bemalol sig'adi, chunki bu eng optimal ko'rsatkichlardir.

## Kod izohi

### Kutubxonalarni kiritish va standart sozlamalar
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // ...
}
```
- `#include <bits/stdc++.h>`: Bu satr C++ dasturlashdagi eng ko'p ishlatiladigan kutubxonalarni (masalan, kiritish/chiqarish uchun `iostream`, arifmetik amallar va boshqalar) o'z ichiga oladi. Competitive programmingda tezlikni ta'minlash uchun ko'pincha barcha kerakli kutubxonalarni birgalikda kiritish uchun ishlatiladi.
- `using namespace std;`: Bu qator `std` (standard) nomlar maydonidagi funksiyalar va ob'ektlarga bevosita murojaat qilish imkonini beradi, masalan, `cout` va `cin` ni `std::cout` va `std::cin` shaklida yozmasdan ishlatish mumkin.
- `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu ikki qator C++ ning kiritish/chiqarish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi. `ios_base::sync_with_stdio(false)` C++ standart I/O oqimlarini C tilining I/O oqimlari bilan sinxronizatsiyani o'chiradi, bu esa tezlikni oshiradi. `cin.tie(0)` esa `cin` operatsiyasidan oldin `cout` buferini tozalashni bekor qiladi, bu ham I/O operatsiyalarini tezlashtiradi. Bu juda kichik masalalarda sezilmasa ham, katta kiritish/chiqarish hajmli masalalarda muhim ahamiyatga ega.

### O'zgaruvchini e'lon qilish, kiritish va chop etish
```cpp
    long long a;
    cin >> a;
    cout << a * a << endl;
```
- `long long a;`: Bu yerda `a` nomli o'zgaruvchi e'lon qilingan. Masala matnida `A` sonining qiymati $4 \times 10^5$ dan oshmaydigan natural son ekanligi aytilgan. `A * A` hisoblanganida, natija $(4 \times 10^5)^2 = 16 \times 10^{10}$ bo'ladi. Bu qiymat 32-bitli `int` (taxminan $2 \times 10^9$ gacha saqlay oladi) turining maksimal qiymatidan sezilarli darajada oshadi. Shuning uchun, 64-bitli `long long` ma'lumot turi ishlatilgan, chunki u $9 \times 10^{18}$ gacha bo'lgan qiymatlarni saqlay oladi va kvadrat natijasini to'g'ri saqlashni ta'minlaydi.
- `cin >> a;`: Bu qator foydalanuvchidan (yoki kirish faylidan) bitta butun sonni o'qib, uni `a` o'zgaruvchisiga joylashtiradi.
- `cout << a * a << endl;`: Bu qator `a` o'zgaruvchisining kvadratini (`a * a`) hisoblaydi va hisoblangan natijani chiqish fayliga (yoki konsolga) chop etadi. `endl` esa chop etilgan qiymatdan so'ng yangi qatorga o'tishni ta'minlaydi.

### Dasturning yakuni
```cpp
    return 0;
}
```
- `return 0;`: `main` funksiyasi 0 qiymatini qaytarganda, bu dasturning muvaffaqiyatli yakunlanganligini bildiradi.

## Edge case lar va eslatmalar
Ushbu masala juda sodda bo'lsa-da, diqqat qilish kerak bo'lgan asosiy jihat bu natijaning ma'lumot turidir:
- **Natijaning ma'lumot turi**: `A` ning maksimal qiymati $4 \times 10^5$ bo'lganligi sababli, uning kvadrati $16 \times 10^{10}$ ga teng bo'ladi. Bu qiymat standart 32-bitli `int` ma'lumot turining chegarasidan (taxminan $2 \times 10^9$) ancha kattadir. Shuning uchun, hisoblangan kvadratni saqlash uchun 64-bitli `long long` ma'lumot turidan foydalanish shart. Aks holda, **integer overflow (butun sonning ortib ketishi)** xatosi yuz berishi va noto'g'ri natija qaytarilishi mumkin.
- Masala matnida `A` ning "natural son" ekanligi aytilgan, ya'ni `A` musbat butun son (1, 2, 3, ...). Bu 0 yoki manfiy sonlarni hisobga olish kerak emasligini bildiradi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M038B) platformasidagi **M038B** raqamli **Kvadrat** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M038B>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M038B, Kvadrat yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
