---
title: "M058A — Bunyodbekning do‘stlari | Robocontest.uz Yechimi"
description: "Robocontest.uz M058A (Bunyodbekning do‘stlari) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M058A, Bunyodbekning do‘stlari yechimi, robocontest Bunyodbekning do‘stlari, M058A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# M058A — Bunyodbekning do‘stlari

## Masala haqida
Bu masala Bunyodbekning do'stlari soni va ulardan qancha nafari kafeda "fast food" buyurtma qilganini aniqlashga qaratilgan. Masala shartiga ko'ra, Bunyodbekning jami `N` nafar do'sti bor. Ulardan uchtasi, ya'ni Halim, Salim va Bilol o'zlari bilan tushlik olib kelishganligi sababli hech narsa buyurtma qilmaydilar. Qolgan do'stlarining har biri esa "fast food" buyurtma qiladi. Bunyodbekning o'zi ham tushlik olib kelganligi haqidagi ma'lumot faqatgina masala shartini to'ldirish uchun berilgan bo'lib, yakuniy javobga ta'sir ko'rsatmaydi.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juda sodda: masala shartini diqqat bilan o'qib, uning mohiyatini tushunish. Jami do'stlar soni `N` bo'lib, ulardan 3 nafari (Halim, Salim va Bilol) hech narsa buyurtma qilmagan. Demak, qolgan do'stlar sonini topish uchun jami do'stlar sonidan buyurtma qilmagan do'stlar sonini ayirish kifoya. Bu to'g'ridan-to'g'ri arifmetik hisoblashga asoslangan.

## Algoritm qadamlari
1.  Kirishdan Bunyodbekning jami do'stlari sonini ifodalovchi `N` butun sonini o'qing.
2.  "Fast food" buyurtma qilgan do'stlar sonini topish uchun `N` dan 3 ni ayiring.
3.  Hos Bo'lgan natijani chiqishga chop eting.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(1)` (Doimiy vaqt murakkabligi).
    *   Masala faqatgina bitta butun sonni o'qish, bitta arifmetik ayirish amali (`n - 3`) va bitta butun sonni chop etishni talab qiladi. Bu amallar soni kirish `N` ning qiymatiga bog'liq emas, doimiy bo'lib qoladi. Shuning uchun vaqt murakkabligi doimiy, ya'ni `O(1)`.
-   **Xotira murakkabligi**: `O(1)` (Doimiy xotira murakkabligi).
    *   Dastur faqat bitta butun son (`n`) saqlash uchun xotira ishlatadi. Bu xotira miqdori `N` ning qiymatidan qat'i nazar doimiy bo'lib qoladi.
-   **Chegaralarga sig'ishi**: Masala uchun belgilangan vaqt (1000 ms) va xotira (16 MB) limitlari bu `O(1)` murakkablikdagi yechim uchun juda keng hisoblanadi. Dastur bir necha millisekundda bajariladi va bir necha kilobayt xotira ishlatadi.

## Kod izohi

```cpp
#include <bits/stdc++.h> 
```
Bu qator C++ standart kutubxonalarining ko'pini o'z ichiga oluvchi `bits/stdc++.h` faylini yuklaydi. Bu, ayniqsa, musobaqa dasturlashda qulaylik uchun tez-tez ishlatiladi, chunki u I/O (kirish/chiqish) uchun `iostream`, stringlar uchun `string`, vektorlar uchun `vector` kabi ko'plab boshqa kerakli sarlavha fayllarini bir vaqtning o'zida yuklaydi.

```cpp
using namespace std;
```
Bu qator `std` (standart) nomfazodan elementlarni (masalan, `cout`, `cin`, `endl`) to'liq malumotsiz, ya'ni `std::cout` o'rniga faqat `cout` deb yozib ishlatishga ruxsat beradi.

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
```
`main` funksiyasi C++ dasturining asosiy kirish nuqtasidir. Ichidagi yuqoridagi ikki qator I/O (kirish/chiqish) operatsiyalarini tezlashtirish uchun ishlatiladi:
-   `ios_base::sync_with_stdio(false);`: C++ streamlarini C tilining standart I/O funksiyalari (masalan, `printf`, `scanf`) bilan sinxronlashishini o'chiradi. Bu C++ streamlarining ishlashini tezlashtiradi.
-   `cin.tie(0);`: `cin` (kirish oqimi) ni `cout` (chiqish oqimi) dan ajratadi. Odatda, `cin` har bir operatsiyadan oldin `cout` buferini tozalaydi. Buni o'chirish katta hajmdagi kirish/chiqishda ishlashni tezlashtiradi. Kichik masalalarda unchalik muhim bo'lmasada, bu odat yaxshi hisoblanadi.

```cpp
    int n;
    cin >> n;
```
`int n;` qatori `n` nomli, `int` (butun son) turidagi o'zgaruvchini e'lon qiladi. Keyin `cin >> n;` qatori kirish oqimidan bitta butun sonni o'qib, uni `n` o'zgaruvchisiga saqlaydi.

```cpp
    cout << n - 3 << endl;
```
Bu asosiy hisoblash va chiqarish qatoridir. `n - 3` ifodasi Bunyodbekning "fast food" buyurtma qilgan do'stlari sonini hisoblaydi. `cout << ...` bu natijani chiqish oqimiga yozadi. `endl` esa chop etilgan sondan keyin yangi qatorga o'tishni va chiqish buferini tozalashni ta'minlaydi.

```cpp
    return 0;
}
```
`return 0;` qatori `main` funksiyasining muvaffaqiyatli bajarilganligini bildiradi.

## Edge case lar va eslatmalar
-   **`N` ning minimal qiymati**: Masala shartida `N` ning minimal qiymati 3 ekanligi aytilgan (`3 <= N <= 50`). Bu muhim, chunki agar `N` 3 dan kichik bo'lganida (masalan, `N = 2`), `n - 3` natijasi manfiy (-1) bo'lar edi, bu esa do'stlar soni uchun mantiqiy xato hisoblanadi. `N >= 3` sharti sababli, `n - 3` natijasi har doim manfiy bo'lmagan (nol yoki musbat) son bo'lib chiqadi, bu esa vaziyatga to'g'ri keladi (masalan, `N=3` bo'lsa, `3-3=0` do'st buyurtma qiladi).
-   **Chalg'ituvchi ma'lumot (red herring)**: Masala shartida Bunyodbekning o'zi ham o'zi bilan tushlik olib kelgani haqida aytilgan. Bu ma'lumot faqatgina hikoyani to'ldirish uchun berilgan bo'lib, "Bunyodning nechta do‘stlari “fast food” buyurtma qilishdi?" degan savolga javob berishda hech qanday rol o'ynamaydi. Faqatgina Halim, Salim va Bilolning buyurtma qilmaganligi muhim.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M058A) platformasidagi **M058A** raqamli **Bunyodbekning do‘stlari** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M058A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M058A, Bunyodbekning do‘stlari yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
