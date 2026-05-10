---
title: "M034C — Quruvchi Xumoy | Robocontest.uz Yechimi"
description: "Robocontest.uz M034C (Quruvchi Xumoy) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M034C, Quruvchi Xumoy yechimi, robocontest Quruvchi Xumoy, M034C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M034C_quruvchi_xumoy/
lang: uz
---

# M034C — Quruvchi Xumoy

## Masala haqida
Xumoy to'g'ri to'rtburchak shaklidagi maydonlarni qoziqlar bilan o'rab olishi kerak. Unga ikkita muhim cheklov berilgan: qo'shni qoziqlar orasidagi masofa har doim bir xil bo'lishi shart va u eng kam miqdordagi qoziqlardan foydalanishi kerak. Sizning vazifangiz Xumoyga yordam berish uchun maydonning `X` va `Y` o'lchamlari berilganda, zarur bo'lgan minimal qoziqlar sonini hisoblab beradigan dastur yozish.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi qoziqlar orasidagi masofani maksimal darajada oshirish orqali ularning umumiy sonini minimallashtirishdir. Agar qoziqlar orasidagi masofa `D` bo'lsa, u holda maydonning har bir tomoni (uzunligi `X` va `Y`) `D` ga bo'linishi kerak. Ya'ni, `D` soni `X` va `Y` ning umumiy bo'luvchisi bo'lishi lozim. Qoziqlar sonini minimallashtirish uchun `D` ning qiymati iloji boricha katta bo'lishi kerak. `X` va `Y` ning eng katta umumiy bo'luvchisi (EKUB yoki ingliz tilida *Greatest Common Divisor - GCD*) bu shartni qanoatlantiruvchi eng katta `D` qiymati hisoblanadi.

Shunday qilib, bizning yechimimiz `X` va `Y` ning EKUBini topishga asoslangan bo'lib, bu qoziqlar orasidagi maksimal masofani beradi. Keyin, shu masofadan foydalanib, butun perimetr bo'ylab nechta qoziq joylashishini hisoblaymiz.

## Algoritm qadamlari
1.  **Kirish ma'lumotlarini o'qish**: Dastur bir nechta test holatlari uchun ishlaydi, shuning uchun `X` va `Y` o'lchamlarini har bir qatordan o'qib olish kerak.
2.  **EKUBni topish**: `X` va `Y` sonlarining eng katta umumiy bo'luvchisini (EKUB/GCD) hisoblang. Bu son har bir qoziq orasidagi masofani ifodalaydi.
3.  **Perimetrni hisoblash**: To'g'ri to'rtburchakning perimetri `2 * (X + Y)` formulasi bo'yicha hisoblanadi.
4.  **Minimal qoziqlar sonini hisoblash**: Perimetrni EKUBga bo'lish orqali zarur bo'lgan minimal qoziqlar sonini topamiz: `(2 * (X + Y)) / EKUB`. Bu, maydonning har bir tomoniga joylashtirilgan segmentlar (qoziqlar oralig'i) sonini yig'ishga tengdir.

## Murakkablik tahlili
*   **Vaqt murakkabligi**: `O(log(min(X, Y)))`. Har bir test holati uchun `std::gcd` funksiyasi chaqiriladi, bu Evklid algoritmi yordamida `log(min(X, Y))` vaqt ichida ishlaydi. `X` va `Y` sonlari `10^8` gacha bo'lishi mumkin, shuning uchun `log(10^8)` juda kichik son bo'lib, amalda doimiy vaqtga yaqin. Kirish/chiqish operatsiyalari (`cin`, `cout`) soni test holatlari soniga bog'liq. Umuman olganda, har bir test holati uchun juda tez ishlaydi.
*   **Xotira murakkabligi**: `O(1)`. Dastur faqat bir nechta o'zgaruvchilarni (X, Y, common_divisor, result) saqlaydi, bu doimiy miqdordagi xotirani talab qiladi.
*   **Nega shu murakkablik chegaraga sig'adi**: Berilgan vaqt limiti 1000 ms va xotira limiti 16 MB. Yuqoridagi murakkablik tahlili shuni ko'rsatadiki, yechim hatto eng katta `X` va `Y` qiymatlari uchun ham belgilangan vaqt va xotira chegaralariga osongina sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarning ko'pini o'z ichiga oluvchi sarlavha fayl

using namespace std; // std nomlar fazosidan foydalanish

int main() {
    // Kirish/chiqish (I/O) operatsiyalarini tezlashtirish uchun optimizatsiyalar.
    // sync_with_stdio(false) C++ streamlarini C standart I/O bilan sinxronizatsiyani o'chiradi.
    // cin.tie(0) 'cout' 'cin' ni tozalashini oldini oladi, shu bilan I/O tezligini oshiradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X, Y; // To'rtburchakning X va Y o'lchamlarini saqlash uchun o'zgaruvchilar
    
    // Kiruvchi ma'lumotlar tugaguncha takrorlanuvchi tsikl.
    // Har bir tsikl bir test holatini qayta ishlaydi.
    while (cin >> X >> Y) {
        // X va Y ning eng katta umumiy bo'luvchisini (EKUB/GCD) hisoblash.
        // C++17 standart kutubxonasida 'std::gcd' funksiyasi mavjud.
        // Bu bizning qoziqlar orasidagi maksimal masofadir.
        int common_divisor = gcd(X, Y);
        
        // Minimal qoziqlar sonini hisoblash.
        // Umumiy perimetr = 2 * (X + Y).
        // Har bir qoziq orasidagi masofa 'common_divisor' bo'lsa,
        // perimetr bo'ylab jami qoziqlar soni = perimetr / common_divisor.
        // Misol: X=2, Y=2, EKUB=2. Perimetr=8. 8/2=4.
        int result = 2 * (X + Y) / common_divisor;
        
        // Natijani chop etish va yangi qatorga o'tish.
        cout << result << "\n";
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganligini bildiradi
}
```

## Edge case'lar va eslatmalar
*   **`X = Y` bo'lgan holatlar**: Agar maydon kvadrat shaklida bo'lsa (masalan, `2 2`), EKUB `X` ning o'zi bo'ladi (ya'ni, `2`). Natija `2 * (X + Y) / X = 2 * (2X) / X = 4`. Bu to'g'ri, chunki kvadratni o'rab olish uchun to'rtta qoziq yetarli (har burchakka bittadan).
*   **`X` yoki `Y` ning katta qiymatlari**: `X` va `Y` `10^8` gacha bo'lishi mumkin. `X + Y` yig'indisi `2 * 10^8` ga yetishi mumkin, va `2 * (X + Y)` esa `4 * 10^8` ga. Bu qiymatlar `int` turiga sig'adi. Shuning uchun `overflow` (qiymatning tur chegarasidan oshib ketishi) xavfi yo'q.
*   **Minimal qiymatlar**: `X` va `Y` minimal `1` bo'lishi mumkin. Masalan, `1 1` bo'lsa, EKUB `1` ga teng. Natija `2 * (1 + 1) / 1 = 4`. Bu ham to'g'ri.
*   **`std::gcd` funksiyasi**: Bu funksiya C++17 standartining bir qismidir. Agar eskiroq C++ versiyasi ishlatilayotgan bo'lsa, Evklid algoritmini qo'lda implementatsiya qilish yoki `<numeric>` kutubxonasini `<bits/stdc++.h>` o'rniga kiritish kerak bo'ladi (garchi `<bits/stdc++.h>` odatda uni ham o'z ichiga olsa ham).
*   **Butun sonli bo'lish**: `(X + Y)` har doim `common_divisor` ga bo'linadi, chunki `common_divisor` `X` va `Y` ning bo'luvchisi bo'lgani uchun, ularning yig'indisi ham `common_divisor` ga bo'linadi. Shuning uchun `(X + Y) / common_divisor` qoldiqsiz butun son bo'ladi.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M034C) platformasidagi **M034C** raqamli **Quruvchi Xumoy** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M034C>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M034C, Quruvchi Xumoy yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
