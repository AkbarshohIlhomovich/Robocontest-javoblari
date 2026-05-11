---
title: "M072B — Masala uchun checker | Robocontest.uz Yechimi"
description: "Robocontest.uz M072B (Masala uchun checker) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M072B, Masala uchun checker yechimi, robocontest Masala uchun checker, M072B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M072B_masala_uchun_checker/
lang: uz
---

# M072B — Masala uchun checker

## Masala haqida
Ushbu masala, Robocontest tizimida ishlatiladigan javob tekshiruvchi (checker) mexanizmi bilan bog'liq muammoni hal qilishga qaratilgan. Standart tekshiruvchilar "Yes" va "yes" kabi turli harf registrdagi javoblarni xato deb hisoblashi mumkin. Bizning vazifamiz — uchta lotin harfidan iborat kiritilgan satrni tekshirib, agar u har qanday harf registrida "yes" so'ziga mos kelsa, "ACCEPTED" deb, aks holda "WRONG ANSWER" deb chiqish (output) beradigan tekshiruvchi dastur yozish.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juda sodda: kiritilgan uch harfli satrning har bir belgisini kichik harfga (lowercase) o'tkazish va so'ngra hosil bo'lgan satrni "yes" so'zi bilan solishtirish. Bu yondashuv har qanday harf registrida (masalan, "YES", "YeS", "yEs") berilgan "yes" so'zini aniq bir xil, kichik harfli ko'rinishga keltirish orqali tekshirish imkonini beradi.

## Algoritm qadamlari
1.  **Kirishni o'qish**: Dastlab, kirish (input) faylidan uchta lotin harfidan iborat bitta satr o'qib olinadi. Bu satr odatda `std::string` tipiga saqlanadi.
2.  **Harf registrini normallashtirish**: Satrning har bir belgisini alohida-alohida `std::tolower()` funksiyasi yordamida kichik harfga o'tkazamiz. Masalan, agar satr "YeS" bo'lsa, birinchi belgi 'Y' -> 'y', ikkinchi belgi 'e' -> 'e', uchinchi belgi 'S' -> 's' bo'ladi.
3.  **Solishtirish**: Kichik harfga o'tkazilgan birinchi belgi 'y' ga, ikkinchi belgi 'e' ga va uchinchi belgi 's' ga tengmi, tekshiriladi. Bunda barcha uchta shart bir vaqtning o'zida bajarilishi kerak (mantiqiy AND `&&` operatori yordamida).
4.  **Natijani chop etish**:
    *   Agar uchta belgi ham mos kelsa (ya'ni, 'y', 'e', 's' ketma-ketligi hosil bo'lsa), dastur "ACCEPTED" so'zini chop etadi.
    *   Aks holda (agar belgilar mos kelmasa), dastur "WRONG ANSWER" so'zini chop etadi.

## Murakkablik tahlili
-   **Vaqt**: O(1) (Doimiy vaqt)
    *   Kirish satri doimiy uzunlikda (3 ta belgi) bo'lgani sababli, uning o'qilishi doimiy vaqtni oladi.
    *   Har bir belgini kichik harfga o'tkazish (`std::tolower`) ham doimiy vaqtli operatsiya hisoblanadi.
    *   Uchta belgini solishtirish ham doimiy vaqtli operatsiya.
    *   Natijani chop etish ham doimiy vaqtni oladi.
    *   Shuning uchun, umumiy vaqt murakkabligi kirish hajmidan (bu yerda 3 ta belgi) mustaqil bo'lib, doimiy (konstant) hisoblanadi.
-   **Xotira**: O(1) (Doimiy xotira)
    *   Faqatgina bitta uch belgili satrni saqlash uchun xotira kerak bo'ladi. Bu ham doimiy miqdordagi xotira hisoblanadi.
    *   Boshqa hech qanday katta ma'lumot tuzilmalari ishlatilmagan.
-   **Nega shu murakkablik chegaraga sig'adi**: Vaqt va xotira murakkabliklari doimiy (konstant) bo'lganligi sababli, bu yechim berilgan 1000 ms va 32 MB cheklovlarga bemalol sig'adi. Aslida, u minimal darajadagi resurslardan foydalanadi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarning ko'pini o'z ichiga olgan umumiy sarlavha

int main() {
    // Kiritish/chiqarish (I/O) tezligini oshirish uchun optimizatsiyalar.
    // std::ios_base::sync_with_stdio(false) - C++ oqimlari va C standarti I/O oqimlari o'rtasidagi sinxronizatsiyani o'chiradi.
    // std::cin.tie(0) - std::cout bilan std::cin bog'lanishini bekor qiladi, bu std::cin dan oldin std::cout ni flush qilishni oldini oladi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s; // Kirish satrini saqlash uchun 's' nomli string o'zgaruvchisi e'lon qilinadi.
    std::cin >> s; // Kirish faylidan satr o'qiladi va 's' ga saqlanadi.

    // Asosiy shart bloki: Satrning har bir belgisini tekshiradi.
    // std::tolower(char) funksiyasi belgi (char) argumentini kichik harfga o'tkazadi.
    // Mantiqiy AND (&&) operatori uchta shartning barchasi bajarilishini talab qiladi.
    if (std::tolower(s[0]) == 'y' && // Birinchi belgi kichik harfda 'y' ga tengmi?
        std::tolower(s[1]) == 'e' && // Ikkinchi belgi kichik harfda 'e' ga tengmi?
        std::tolower(s[2]) == 's') { // Uchinchi belgi kichik harfda 's' ga tengmi?
        
        std::cout << "ACCEPTED\n"; // Agar barcha shartlar bajarilsa, "ACCEPTED" chop etiladi.
    } else {
        std::cout << "WRONG ANSWER\n"; // Aks holda, "WRONG ANSWER" chop etiladi.
    }

    return 0; // Dasturning muvaffaqiyatli yakunlanganligini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Kirish formati**: Masala matnida kiruvchi ma'lumotlar har doim "bir qatorda 3 lotin harfidan iborat satr" bo'lishi aniq ko'rsatilgan. Bu bizni kirish uzunligi 3 dan farq qiladigan holatlarni, raqamlarni, maxsus belgilarni yoki bo'sh joylarni tekshirishdan ozod qiladi.
*   **`std::tolower` funksiyasi**: Bu funksiya faqat lotin harflarini o'zgartiradi; agar unga harf bo'lmagan belgi berilsa, u o'sha belgini o'zgartirmay qaytaradi. Ammo masala shartiga ko'ra, bizda faqat lotin harflari bo'ladi.
*   **Case Insensitivity**: Yechim `std::tolower` funksiyasidan foydalanib, harflarning registriga sezgir bo'lmagan (case-insensitive) solishtirishni amalga oshiradi. Bu esa "yes" so'zining har qanday harf registridagi ko'rinishini to'g'ri deb qabul qilish imkonini beradi.
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M072B) platformasidagi **M072B** raqamli **Masala uchun checker** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M072B>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M072B, Masala uchun checker yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
