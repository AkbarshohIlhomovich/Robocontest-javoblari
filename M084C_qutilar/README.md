---
title: "M084C — Qutilar | Robocontest.uz Yechimi"
description: "Robocontest.uz M084C (Qutilar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M084C, Qutilar yechimi, robocontest Qutilar, M084C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M084C_qutilar/
lang: uz
---

# M084C — Qutilar

## Masala haqida
Ushbu masalada bizga ikkita to'g'ri burchakli qutining o'lchamlari (bo'yi, eni, balandligi) beriladi. Birinchi qutining o'lchamlari \(A_1, B_1, C_1\), ikkinchi qutining o'lchamlari esa \(A_2, B_2, C_2\) sifatida berilgan. Bizning vazifamiz — bir qutini ikkinchisining ichiga to'liq joylashtirish mumkinmi yoki yo'qligini aniqlash. Natijaga qarab, "Qutilar o'zaro teng", "Birinchi quti ikkinchisidan katta", "Birinchi quti ikkinchisidan kichik" yoki "Qutilarni solishtirib bo'lmaydi" degan xabarlardan birini chop etishimiz kerak.

## Yondashuv (g'oya)
Masalaning asosiy murakkabligi shundaki, qutini ichkariga joylashtirishda uning orientatsiyasini (ya'ni, qaysi tomoni bo'y, qaysi tomoni en, qaysi tomoni balandlik bo'lishi) o'zgartirish mumkin. Misol uchun, `1x2x3` o'lchamli qutini `3x2x1` o'lchamli quti ichiga bemalol joylashtirish mumkin. Bu muammoni hal qilish uchun har bir qutining o'lchamlarini o'sish tartibida saralash (tartiblash) eng samarali yondashuv hisoblanadi.

Agar ikkita qutining o'lchamlari saralangandan so'ng `(d1_min, d1_mid, d1_max)` va `(d2_min, d2_mid, d2_max)` shaklida bo'lsa, u holda ikkinchi qutini birinchi quti ichiga joylashtirish mumkin, agar va faqat agar `d2_min <= d1_min`, `d2_mid <= d1_mid` va `d2_max <= d1_max` shartlari bajarilsa. Bu yondashuv barcha mumkin bo'lgan orientatsiyalarni avtomatik ravishda hisobga oladi, chunki biz har doim eng kichik o'lchamni eng kichigiga, o'rtancha o'lchamni o'rtanchasiga va eng katta o'lchamni eng kattasiga solishtiramiz.

## Algoritm qadamlari
1.  **Quti 1 o'lchamlarini o'qish va saralash:**
    *   Birinchi qutining uchta o'lchamini (`A_1`, `B_1`, `C_1`) kirishdan o'qing.
    *   Bu uchta o'lchamni o'sish tartibida saralang. Masalan, agar o'lchamlar `[1, 3, 2]` bo'lsa, saralangandan keyin ular `[1, 2, 3]` bo'ladi.
2.  **Quti 2 o'lchamlarini o'qish va saralash:**
    *   Xuddi shu tarzda, ikkinchi qutining uchta o'lchamini (`A_2`, `B_2`, `C_2`) kirishdan o'qing.
    *   Ularni ham o'sish tartibida saralang.
3.  **Solishtirish shartlarini tekshirish:**
    *   Ikkita mantiqiy (`boolean`) o'zgaruvchi yarating:
        *   `box2_fits_in_box1`: Ikkinchi quti birinchi qutiga joylashishi mumkinmi? Bu `true` (rost) bo'ladi, agar ikkinchi qutining saralangan o'lchamlari (masalan, `dims2[0], dims2[1], dims2[2]`) birinchi qutining mos saralangan o'lchamlaridan (`dims1[0], dims1[1], dims1[2]`) kichik yoki teng bo'lsa. Ya'ni, `(dims2[0] <= dims1[0] && dims2[1] <= dims1[1] && dims2[2] <= dims1[2])`.
        *   `box1_fits_in_box2`: Birinchi quti ikkinchi qutiga joylashishi mumkinmi? Bu `true` bo'ladi, agar birinchi qutining saralangan o'lchamlari ikkinchi qutining mos saralangan o'lchamlaridan kichik yoki teng bo'lsa. Ya'ni, `(dims1[0] <= dims2[0] && dims1[1] <= dims2[1] && dims1[2] <= dims2[2])`.
4.  **Natijani chop etish:**
    *   Agar `box1_fits_in_box2` hamda `box2_fits_in_box1` ikkalasi ham `true` bo'lsa, bu qutilarning bir xil o'lchamga ega ekanligini bildiradi (orientatsiyadan qat'iy nazar). "Qutilar o'zaro teng" deb chop eting.
    *   Aks holda, agar faqat `box2_fits_in_box1` `true` bo'lsa, bu birinchi qutining ikkinchisidan kattaroq ekanligini anglatadi. "Birinchi quti ikkinchisidan katta" deb chop eting.
    *   Aks holda, agar faqat `box1_fits_in_box2` `true` bo'lsa, bu birinchi qutining ikkinchisidan kichikroq ekanligini anglatadi. "Birinchi quti ikkinchisidan kichik" deb chop eting.
    *   Boshqa barcha holatlarda (ya'ni, ikkala shart ham `false` bo'lsa), qutilarni bir-biriga joylashtirib bo'lmaydi. "Qutilarni solishtirib bo'lmaydi" deb chop eting.

## Murakkablik tahlili
-   **Vaqt**: O(1)
    *   Har bir quti uchun 3 ta o'lchamni o'qish doimiy vaqt oladi.
    *   3 ta elementdan iborat massivni saralash doimiy vaqt murakkabligiga ega (chunki elementlar soni doimiy va kichik, N=3). Har qanday saralash algoritmi bu holatda doimiy vaqtda ishlaydi.
    *   Solishtirish va natijani chop etish ham doimiy vaqt oladi.
    *   Umumiy vaqt murakkabligi O(1) bo'ladi, chunki bajariladigan operatsiyalar soni kirish ma'lumotlari hajmiga bog'liq emas.
-   **Xotira**: O(1)
    *   Ikkita qutining o'lchamlarini saqlash uchun ikkita massiv (`std::vector<int>`) ishlatiladi. Har bir massivda atigi 3 ta butun son saqlanadi. Bu doimiy miqdordagi xotira talab qiladi.
    *   Shuning uchun umumiy xotira murakkabligi O(1) bo'ladi, chunki ishlatiladigan xotira miqdori kirish ma'lumotlari hajmiga bog'liq emas.
-   **Nega shu murakkablik chegaraga sig'adi**: Berilgan vaqt limiti 1000 ms va xotira limiti 16 MB. O(1) vaqt va xotira murakkabligi juda samarali hisoblanadi va bu limitlarga osongina sig'adi. Dastur bir necha millisoniyada tugallanib, juda oz xotira ishlatadi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Bu fayl ko'pgina standart C++ kutubxonalarini, jumladan, kirish/chiqish (iostream), dinamik massivlar (vector) va saralash algoritmlarini (algorithm) o'z ichiga oladi.

using namespace std; // std nomlar fazosini ishlatishni soddalashtiradi. Bu std::cout, std::cin, std::vector kabi elementlarni bevosita nomlari bilan ishlatishga imkon beradi.

int main() {
    // Kirish/chiqish (I/O) optimizatsiyalari. Katta hajmli kirish/chiqish bilan ishlashda dastur tezligini oshiradi.
    ios_base::sync_with_stdio(false); // C++ oqimlari (cin/cout) va C tilining standart I/O funksiyalari (scanf/printf) orasidagi sinxronizatsiyani o'chiradi.
    cin.tie(0); // cin operatsiyasidan keyin cout buferini avtomatik bo'shatmaslikni buyuradi. Bu ham I/O tezligini oshiradi.

    vector<int> dims1(3); // Birinchi qutining o'lchamlarini saqlash uchun 3 ta butun sonni ushlab turuvchi 'vector' (dinamik massiv) e'lon qilinadi.
    for (int i = 0; i < 3; ++i) {
        cin >> dims1[i]; // Kirishdan birinchi qutining uchta o'lchamini o'qiydi.
    }
    sort(dims1.begin(), dims1.end()); // 'std::sort' funksiyasi yordamida 'dims1' vectoridagi o'lchamlar o'sish tartibida saralanadi.
                                      // Masalan, agar o'qilgan o'lchamlar {3, 1, 2} bo'lsa, saralangandan keyin {1, 2, 3} bo'ladi.

    vector<int> dims2(3); // Ikkinchi qutining o'lchamlarini saqlash uchun xuddi shunday 'vector' e'lon qilinadi.
    for (int i = 0; i < 3; ++i) {
        cin >> dims2[i]; // Kirishdan ikkinchi qutining uchta o'lchamini o'qiydi.
    }
    sort(dims2.begin(), dims2.end()); // Ikkinchi quti o'lchamlari ham o'sish tartibida saralanadi.

    // Qutining boshqa qutiga joylashish shartlarini tekshiramiz.
    // box2_fits_in_box1: Ikkinchi quti birinchi qutiga joylasha oladimi?
    // Bu shart ikkinchi qutining har bir saralangan o'lchami birinchi qutining mos saralangan o'lchamidan kichik yoki teng bo'lganda rost bo'ladi.
    bool box2_fits_in_box1 = (dims2[0] <= dims1[0] && dims2[1] <= dims1[1] && dims2[2] <= dims1[2]);
    // box1_fits_in_box2: Birinchi quti ikkinchi qutiga joylasha oladimi?
    // Bu shart birinchi qutining har bir saralangan o'lchami ikkinchi qutining mos saralangan o'lchamidan kichik yoki teng bo'lganda rost bo'ladi.
    bool box1_fits_in_box2 = (dims1[0] <= dims2[0] && dims1[1] <= dims2[1] && dims1[2] <= dims2[2]);

    // Yuqoridagi mantiqiy o'zgaruvchilarga asoslanib, masalaning talablariga muvofiq natijani chop etamiz.
    if (box1_fits_in_box2 && box2_fits_in_box1) {
        // Agar ikkala quti ham bir-biriga joylashsa, demak, ularning o'lchamlari o'zaro teng.
        cout << "Qutilar o'zaro teng" << endl;
    } else if (box2_fits_in_box1) {
        // Agar faqat ikkinchi quti birinchi qutiga joylashsa, bu birinchi qutining kattaroq ekanligini anglatadi.
        cout << "Birinchi quti ikkinchisidan katta" << endl;
    } else if (box1_fits_in_box2) {
        // Agar faqat birinchi quti ikkinchi qutiga joylashsa, bu birinchi qutining kichikroq ekanligini anglatadi.
        cout << "Birinchi quti ikkinchisidan kichik" << endl;
    } else {
        // Yuqoridagi holatlarning hech biri bajarilmasa, qutilarni bir-biriga joylashtirib bo'lmaydi.
        cout << "Qutilarni solishtirib bo'lmaydi" << endl;
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **O'lchamlarning tengligi**: Agar ikki qutining barcha o'lchamlari (saralangandan keyin) o'zaro teng bo'lsa, ular bir-biriga joylasha oladi va "Qutilar o'zaro teng" deb hisoblanadi. Kodda bu `box1_fits_in_box2 && box2_fits_in_box1` sharti bilan to'g'ri aniqlanadi.
*   **Kublar**: Agar qutilar kub shaklida bo'lsa (masalan, `2x2x2`), ularning o'lchamlari saralangandan keyin ham bir xil bo'ladi, va algoritmlar to'g'ri ishlaydi.
*   **Minimal va maksimal o'lchamlar**: Masala shartida quti o'lchamlari 1 dan kichik bo'lmasligi va \(10^3\) dan oshmasligi kafolatlangan. Bu butun sonlar bilan ishlashda hech qanday muammo tug'dirmaydi.
*   **Optimal orientatsiya**: O'lchamlarni saralash usuli qutini joylashtirish mumkin bo'lgan barcha mumkin bo'lgan orientatsiyalar orasidan eng qulayini avtomatik ravishda tanlaydi. Bu bizga bo'yi, eni, balandlikni aniq moslashtirish haqida o'ylamasdan, shunchaki eng kichikni kichigiga, o'rtanchani o'rtanchasiga va eng kattani kattasiga solishtirish imkonini beradi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M084C) platformasidagi **M084C** raqamli **Qutilar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M084C>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M084C, Qutilar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
