---
title: "R078I — A+B | Robocontest.uz Yechimi"
description: "Robocontest.uz R078I (A+B) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Oson. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest R078I, A+B yechimi, robocontest A+B, R078I c++ kod, oson, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /R078I_ab/
lang: uz
---

# R078I — A+B

## Masala haqida
Bu masala sizdan ikkita butun sonni kiritishni va ularning yig'indisini hisoblab, natijani chiqarishni talab qiladi. Kiritiladigan sonlar $10^9$ (bir milliard) dan kichik bo'ladi. Masala eng sodda arifmetik amallardan birini bajarishga qaratilgan.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi juda oddiy: berilgan ikkita butun sonni to'g'ridan-to'g'ri o'qib, ularni bir-biriga qo'shish va natijani ekranga chiqarish. Bu jarayon uchun hech qanday murakkab algoritm yoki ma'lumotlar tuzilmasiga ehtiyoj yo'q, chunki standart arifmetik amallar yetarli.

## Algoritm qadamlari
1.  Ikkita butun sonni saqlash uchun ikkita o'zgaruvchi (masalan, `a` va `b`) e'lon qilinadi.
2.  Konsoldan `a` va `b` o'zgaruvchilariga qiymatlar kiritiladi.
3.  `a` va `b` sonlarining yig'indisi (ya'ni, `a + b`) hisoblanadi.
4.  Hisoblangan yig'indi konsolga chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(1) — doimiy vaqt
    *   Kirish (input) ikki butun sonni o'qishdan iborat.
    *   Hisoblash bitta qo'shish amali.
    *   Chiqish (output) bitta butun sonni yozishdan iborat.
    *   Barcha bu amallar har doim bir xil, doimiy miqdordagi vaqtni oladi, kirish hajmidan (bu holatda, sonlarning kattaligidan) deyarli mustaqil. Shuning uchun vaqt murakkabligi O(1) ga teng. Bu 1000 ms vaqt limitiga bemalol sig'adi.

-   **Xotira murakkabligi**: O(1) — doimiy xotira
    *   Faqat ikkita butun sonni saqlash uchun (`a` va `b`) va ularning yig'indisi uchun oz miqdordagi xotira ajratiladi.
    *   Bu xotira hajmi kiritiladigan sonlarning qiymatiga bog'liq emas, balki faqat kerakli o'zgaruvchilar soniga bog'liq. Shuning uchun xotira murakkabligi O(1) ga teng. Bu 16 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h>
```
*   Bu qator C++ ning deyarli barcha standart kutubxonalarini (input/output, arifmetika, va boshqalar) o'z ichiga oladigan "omnibus" sarlavha faylini (header file) qo'shadi. Competitive programming (raqobatli dasturlash) musobaqalarida tezlik uchun keng qo'llaniladi.

```cpp
using namespace std;
```
*   Bu qator `std` nomlar fazosidagi (namespace) elementlarga (masalan, `cin`, `cout`, `endl`) to'g'ridan-to'g'ri `std::` prefiksini yozmasdan kirish imkonini beradi.

```cpp
int main() {
```
*   Har bir C++ dasturi `main` funksiyasidan boshlanadi. Bu dasturning asosiy kirish nuqtasidir.

```cpp
    ios_base::sync_with_stdio(false);
    cin.tie(0);
```
*   Bu ikkita qator C++ dasturlarida kirish/chiqish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi.
    *   `ios_base::sync_with_stdio(false);` C standart I/O oqimlari (stream) bilan C++ I/O oqimlari orasidagi sinxronizatsiyani o'chiradi. Bu C++ I/O ni sezilarli darajada tezlashtirishi mumkin.
    *   `cin.tie(0);` `cin` (kirish) oqimini `cout` (chiqish) oqimidan uzadi. Odatda, `cin` har bir kiritishdan oldin `cout` ni tozalaydi (flush), bu esa sekinlikka olib kelishi mumkin. Ularni uzish bu xatti-harakatni oldini oladi. Bunday sodda masalada juda muhim emas, lekin katta hajmli kirish/chiqish bo'lgan masalalarda juda foydali.

```cpp
    int a, b;
```
*   Bu qator `int` (butun son) turidagi `a` va `b` nomli ikkita o'zgaruvchini e'lon qiladi. Masala shartiga ko'ra, sonlar $10^9$ dan kichik, shuning uchun ularning yig'indisi $2 \times 10^9$ dan kichik bo'ladi. `int` tipi odatda $2 \times 10^9$ atrofidagi qiymatlarni saqlay oladi, shuning uchun bu ma'lumotlar turi yetarli.

```cpp
    cin >> a >> b;
```
*   Bu qator konsoldan kiritilgan ikkita butun sonni o'qiydi va ularni mos ravishda `a` va `b` o'zgaruvchilariga yuklaydi.

```cpp
    cout << a + b << endl;
```
*   Bu qator `a` va `b` o'zgaruvchilarining yig'indisini hisoblaydi (`a + b`) va natijani konsolga chiqaradi.
*   `endl` chiqish oqimiga yangi qator belgisini qo'shadi va oqimni tozalaydi (flushes the output buffer).

```cpp
    return 0;
}
```
*   `return 0;` dastur muvaffaqiyatli yakunlanganini bildiradi.

## Edge case lar va eslatmalar
*   **Ma'lumotlar turi**: Berilgan sonlar $10^9$ dan kichik bo'lganligi sababli, ularning yig'indisi $2 \times 10^9$ dan kichik bo'ladi. C++ dagi standart `int` ma'lumotlar turi odatda -2,147,483,648 dan 2,147,483,647 gacha bo'lgan qiymatlarni saqlay oladi. Bu masala uchun `int` tipi to'liq mos keladi. Agar sonlar kattaroq bo'lganda (masalan, $10^{18}$ gacha), `long long` ma'lumotlar turini ishlatish kerak bo'lardi.
*   **Natural sonlar**: Masala matnida "natural sonlar" deb berilgan. Matematikada natural sonlar odatda 1, 2, 3, ... (ba'zida 0 ham qo'shiladi) deb qabul qilinadi. Bu yerda kiritiladigan sonlarning manfiy bo'lmasligi va juda kichik bo'lmasligi e'tiborga olingan.
*   **Tezkor I/O**: Garchi bu masalada tezkor kirish/chiqish (`ios_base::sync_with_stdio(false); cin.tie(0);`) juda muhim bo'lmasa-da, katta hajmdagi ma'lumotlar bilan ishlaganda bu yaxshi odat va dasturning ishlashini sezilarli darajada tezlashtirishi mumkin. Shuning uchun buni har doim dasturlaringizga kiritishni tavsiya etamiz.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/R078I) platformasidagi **R078I** raqamli **A+B** masalasi. U **Oson** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/R078I>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest R078I, A+B yechimi, robocontest masalalari, c++17, olimpiada yechimi, oson, dasturlash uzbek, competitive programming O'zbekiston.</sub>
