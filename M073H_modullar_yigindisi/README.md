---
title: "M073H — Modullar yig'indisi | Robocontest.uz Yechimi"
description: "Robocontest.uz M073H (Modullar yig'indisi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M073H, Modullar yig'indisi yechimi, robocontest Modullar yig'indisi, M073H c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M073H_modullar_yigindisi/
lang: uz
---

# M073H — Modullar yig'indisi

## Masala haqida
Ushbu masalada `N` ta butun sondan tashkil topgan `A` massivi berilgan. Bizdan `f(m) = (m mod a_1) + (m mod a_2) + ... + (m mod a_N)` funksiyasining manfiy bo'lmagan `m` soni uchun erishishi mumkin bo'lgan maksimal qiymatini topish talab qilinadi. Bu yerda `X mod Y` - `X` sonining `Y` soniga bo'lgandagi qoldig'ini anglatadi.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi har bir `(m mod a_i)` ifodaning maksimal qiymati nimaga teng bo'lishini tushunish va bunday maksimal qiymatga barcha `a_i` lar uchun bir vaqtda erishish mumkinligini isbotlashdan iborat.

Matematik nuqtai nazardan, `X mod Y` ning qiymati doimo `0` dan `Y-1` gacha bo'ladi. Demak, `(m mod a_i)` ifodasining maksimal qiymati `a_i - 1` ga teng. Misol uchun, `5 mod 6 = 5`, `11 mod 6 = 5`, ya'ni `(6-1)` ga teng.

Endi savol tug'iladi: shunday bir `m` sonini topa olamizmi-ki, barcha `i` lar uchun `(m mod a_i)` aynan `a_i - 1` ga teng bo'lsin?
Agar `m mod a_i = a_i - 1` bo'lsa, bu `m+1` soni `a_i` ga qoldiqsiz bo'linishini anglatadi. Ya'ni, `m+1` har bir `a_i` ning karralisi (multipli) bo'lishi kerak. Bunday `m+1` sonini topish uchun `a_1, a_2, ..., a_N` sonlarining eng kichik umumiy karralisini (EKUK yoki ing. Least Common Multiple - LCM) olsak kifoya.

Misol uchun, `L = EKUK(a_1, a_2, ..., a_N)` bo'lsin. Agar biz `m = L - 1` deb tanlasak, unda `m+1 = L` bo'ladi. `L` esa har bir `a_i` ga bo'lingani uchun, `L - 1` ni `a_i` ga bo'lganda qoldiq `a_i - 1` ga teng bo'ladi.
Misol: `a = [3, 4, 6]`. `EKUK(3, 4, 6) = 12`.
Agar `m = 12 - 1 = 11` deb olsak:
`11 mod 3 = 2` (`3-1`)
`11 mod 4 = 3` (`4-1`)
`11 mod 6 = 5` (`6-1`)
Unda `f(11) = 2 + 3 + 5 = 10` bo'ladi. Bu `(3-1) + (4-1) + (6-1)` yig'indisiga teng.

Shuning uchun, `f(m)` ning maksimal qiymati har bir `a_i` uchun `a_i - 1` ning yig'indisiga teng bo'ladi. Algoritm shunchaki `A` massividagi barcha elementlar uchun `(a_i - 1)` ifodalarini hisoblab, ularni jamlab beradi.

## Algoritm qadamlari
1.  Massiv elementlari soni `N` ni kiritish.
2.  `total_max_mod_sum` nomli `long long` (katta butun sonlarni saqlashga mo'ljallangan tur) turidagi o'zgaruvchini `0` ga initsializatsiya qilish. Bu o'zgaruvchi maksimal qoldiqlar yig'indisini saqlaydi.
3.  `i` ni `0` dan `N-1` gacha (inklyuziv) takrorlanadigan sikl boshlash:
    a.  Joriy `a_i` elementini kiritish.
    b.  `total_max_mod_sum` o'zgaruvchisiga `(a_i - 1)` ni qo'shish.
4.  Sikl yakunlangach, `total_max_mod_sum` ning oxirgi qiymatini chop etish.

## Murakkablik tahlili
-   **Vaqt murakkabligi (Time Complexity)**: `O(N)`.
    *   Algoritm `N` ta elementni kiritish va har birini bir marta ko'rib chiqishni talab qiladi. Har bir element uchun bir nechta elementar arifmetik amallar bajariladi (ayirish va qo'shish). Shuning uchun umumiy vaqt `N` ga proporsional bo'ladi.
-   **Xotira murakkabligi (Space Complexity)**: `O(1)`.
    *   Algoritm massivni xotirada saqlamaydi. Faqatgina `N`, joriy `a_i` va `total_max_mod_sum` kabi bir nechta o'zgaruvchilar ishlatiladi, ularning hajmi `N` ga bog'liq emas.
-   **Nega shu murakkablik chegaraga sig'adi**:
    *   `N` ning maksimal qiymati `1000` bo'lganligi sababli, `O(N)` vaqt murakkabligi juda tez ishlaydi (taxminan `1000` ga yaqin amallar).
    *   Xotira talabi doimiy bo'lgani uchun, `32 MB` chekloviga osongina sig'adi.
    *   Hisoblangan yig'indi `N * (maks_A_i - 1)` ya'ni `1000 * (10^5 - 1) = 99,999,000` bo'lishi mumkin. Bu qiymat `long long` turiga bemalol sig'adi. Hatto 32-bitli `int` (taxminan `2 * 10^9` gacha) ham bu qiymatni saqlashi mumkin, ammo `long long` ishlatish xavfsizroq va umumiy amaliyotdir.

## Kod izohi
```cpp
#include <bits/stdc++.h> // C++ ning standart kutubxonalarini (masalan, kirish/chiqish uchun iostream) o'z ichiga oladi

using namespace std; // std nomlar fazosidan foydalanishni osonlashtiradi

int main() {
    // Kirish/chiqish amallarini tezlashtirish uchun optimizatsiyalar.
    // Bu C++ iostream funksiyalari va C stdio funksiyalari o'rtasidagi sinxronizatsiyani o'chiradi.
    ios_base::sync_with_stdio(false);
    // cin va cout o'rtasidagi bog'lanishni bekor qiladi, bu cin ni yanada tezlashtiradi.
    cin.tie(0); 

    int n; // Massiv elementlari sonini saqlash uchun o'zgaruvchi
    cin >> n; // N qiymatini o'qish

    long long total_max_mod_sum = 0; // Maksimal qoldiqlar yig'indisini saqlash uchun o'zgaruvchi.
                                   // Yig'indi int turining chegarasidan oshib ketishi mumkinligi sababli
                                   // long long ishlatiladi (maksimal N * (maksimal A_i - 1) = 1000 * (10^5 - 1) = 99,999,000).
                                   // Bu int ga sig'sa ham, long long xavfsizroq.

    // Massivning N ta elementini birma-bir o'qish va hisoblash sikli
    for (int i = 0; i < n; ++i) {
        int a_i; // Joriy massiv elementini saqlash uchun o'zgaruvchi
        cin >> a_i; // a_i qiymatini o'qish
        // Har bir a_i uchun maksimal qoldiq (a_i - 1) ga teng.
        // Bu qiymatni umumiy yig'indiga qo'shamiz.
        total_max_mod_sum += (a_i - 1); 
    }

    // Hisoblangan maksimal yig'indini ekranga chiqarish
    cout << total_max_mod_sum << endl;

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi
}

```

## Edge case lar va eslatmalar
*   **`m` ning manfiy bo'lmasligi**: Masala shartiga ko'ra `m` manfiy bo'lmagan son bo'lishi kerak. Bizning yondashuvimizda `m = EKUK(...) - 1` deb olinadi. `A_i >= 2` bo'lgani uchun, `EKUK(A_i)` doimo `2` yoki undan katta bo'ladi. Shuning uchun `m = EKUK(...) - 1` har doim `1` yoki undan katta, ya'ni manfiy bo'lmaydi.
*   **`A_i` ning minimal qiymati**: `A_i \ge 2` ekanligi muhim. Bu `(a_i - 1)` ifodaning doim musbat yoki nol bo'lishini ta'minlaydi (`2-1 = 1`). Agar `A_i = 1` bo'lganda, `(1 mod 1) = 0` bo'lar edi, va `(a_i - 1)` mantiq hali ham ishlayverardi, lekin masalaning shartiga ko'ra `A_i` hech qachon `1` ga teng bo'lmaydi.
*   **Ma'lumotlar turining to'g'ri tanlanishi**: `total_max_mod_sum` o'zgaruvchisi uchun `long long` turidan foydalanish zarur. Yuqorida tahlil qilinganidek, yig'indi `int` turining maksimal qiymatidan (taxminan `2 * 10^9`) oshib ketmasligi mumkin, lekin chekka holatlarda yoki kichikroq `int` turlari (masalan, 16-bit) mavjud bo'lganda xatolikka yo'l qo'ymaslik uchun `long long` dan foydalanish har doim yaxshi amaliyotdir.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M073H) platformasidagi **M073H** raqamli **Modullar yig'indisi** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M073H>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M073H, Modullar yig'indisi yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
