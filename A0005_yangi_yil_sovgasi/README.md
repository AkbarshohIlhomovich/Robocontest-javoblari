---
title: "A0005 — Yangi yil sovg'asi | Robocontest.uz Yechimi"
description: "Robocontest.uz A0005 (Yangi yil sovg'asi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Oson. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0005, Yangi yil sovg'asi yechimi, robocontest Yangi yil sovg'asi, A0005 c++ kod, oson, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /A0005_yangi_yil_sovgasi/
lang: uz
---

# A0005 — Yangi yil sovg'asi

## Masala haqida
Ushbu masala uchta opaning onalari uchun Yangi yil sovg'asini sotib olish imkoniyatini aniqlashga qaratilgan. Sovg'aning narxi \(N\) so'm bo'lib, opalarning har birida mos ravishda \(A\), \(B\), \(C\) so'm ortiqcha pul bor. Masala ularning jami puli sovg'a narxini qoplashga yetadimi yoki yo'qmi, shuni tekshirishni talab qiladi. Agar yetar bo'lsa "Yes", aks holda "No" chiqarish kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juda sodda: barcha opalarning jami pullarini hisoblash va bu yig'indini sovg'aning narxi bilan solishtirish. Agar opalarning jami puli sovg'a narxiga teng yoki undan ko'p bo'lsa, ular sovg'ani sotib olishlari mumkin. Aks holda, ular sotib ola olmaydilar. Bu masalada maxsus algoritm yoki murakkab ma'lumot tuzilmalari talab qilinmaydi, faqatgina elementar arifmetik amallar yetarli.

## Algoritm qadamlari
1.  Sovg'aning narxini (N) kirishdan o'qib oling.
2.  Uchta opaning pullarini (A, B, C) kirishdan o'qib oling.
3.  Opalarning jami pulini hisoblang: `jami_pul = A + B + C`.
4.  Agar `jami_pul` \(N\) ga teng yoki undan katta bo'lsa (`jami_pul >= N`), "Yes" so'zini ekranga chiqaring.
5.  Aks holda (agar `jami_pul < N`), "No" so'zini ekranga chiqaring.

## Murakkablik tahlili
-   **Vaqt**: O(1)
    Bu masala doimiy vaqt murakkabligiga ega. Kirish ma'lumotlarini o'qish, uchta sonni qo'shish va bitta solishtirish amali doimiy vaqtda bajariladi. Kirish hajmi (masalan, sonlar diapazoni) algoritmning bajarilish vaqtiga ta'sir qilmaydi, chunki bajariladigan amallar soni o'zgarmaydi.
-   **Xotira**: O(1)
    Algoritm faqat bir nechta o'zgaruvchilarni (N, A, B, C va ularning yig'indisini saqlash uchun) ishlatadi, bu esa doimiy miqdordagi xotira. Kirish ma'lumotlarining kattaligidan qat'i nazar, talab qilinadigan xotira miqdori o'zgarmaydi.
-   **Nega shu murakkablik chegaraga sig'adi**: Berilgan vaqt limiti 1000 ms va xotira limiti 16 MB juda keng. O(1) vaqt va xotira murakkabligiga ega bo'lgan bu yechim ushbu chegaralarga osongina sig'adi. Haqiqatda, yechim bir necha millisekundda bajariladi va bir necha kilobayt xotira ishlatadi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // 1
```
1.  Bu qator C++ ning standart kutubxonalarini o'z ichiga oladi. `bits/stdc++.h` bu "prekompilyatsiya qilingan sarlavha fayl" bo'lib, ko'pgina raqobat dasturlash platformalarida barcha standart kutubxonalarni tezda kiritish uchun ishlatiladi. Ushbu masala uchun faqat `iostream` (kirish/chiqish amallari uchun) yetarli bo'lardi.

```cpp
int main() {
    std::ios_base::sync_with_stdio(false); // 2
    std::cin.tie(0); // 3
    long long n; // 4
    std::cin >> n; // 5
    long long a, b, c; // 6
    std::cin >> a >> b >> c; // 7
    if (a + b + c >= n) { // 8
        std::cout << "Yes\n"; // 9
    } else {
        std::cout << "No\n"; // 10
    }
    return 0; // 11
}
```
2.  `std::ios_base::sync_with_stdio(false);` C++ `iostream` (kirish/chiqish oqimlari) va C `stdio` (standart kirish/chiqish) kutubxonalari o'rtasidagi sinxronizatsiyani o'chiradi. Bu C++ kirish/chiqish amallarini tezlashtiradi.
3.  `std::cin.tie(0);` `std::cout` ning `std::cin` bilan bog'lanishini bekor qiladi. Bu shuni anglatadiki, `std::cin` har bir kiritish amali oldidan `std::cout` buferini tozalashni kutmaydi. Bu ham kirish/chiqish tezligini oshirishga yordam beradi. Katta hajmdagi kirish/chiqish bilan ishlashda foydali, ammo bu kabi oddiy masalada unchalik muhim emas.
4.  `long long n;` `n` nomli o'zgaruvchini e'lon qiladi. `long long` ma'lumot turi tanlangan, chunki \(N\) ning qiymati $10^9$ gacha bo'lishi mumkin. Bu $2 \cdot 10^9$ atrofida bo'lgan standart `int` turining maksimal qiymatidan yuqori bo'lishi mumkin, shuning uchun `long long` ishlatish xavfsizroq va to'g'ri.
5.  `std::cin >> n;` foydalanuvchidan sovg'a narxini (N) o'qib, uni `n` o'zgaruvchisiga saqlaydi.
6.  `long long a, b, c;` `a`, `b`, `c` nomli o'zgaruvchilarni e'lon qiladi. Bu opalarning pullarini saqlash uchun ishlatiladi va ular ham $10^9$ gacha bo'lishi mumkinligi sababli `long long` turida e'lon qilingan.
7.  `std::cin >> a >> b >> c;` foydalanuvchidan uchta opaning pullarini o'qib, ularni `a`, `b`, `c` o'zgaruvchilariga saqlaydi.
8.  `if (a + b + c >= n) { ... } else { ... }` Bu kodning asosiy mantiqiy bloki. U `a`, `b`, `c` ning yig'indisini (ya'ni, opalarning jami pulini) hisoblaydi va uni `n` (sovg'a narxi) bilan solishtiradi.
    *   Agar yig'indi narxga teng yoki undan katta bo'lsa, shart rost (`true`) bo'ladi.
    *   Aks holda, shart yolg'on (`false`) bo'ladi.
    *   Qo'shimcha eslatma: Uchta $10^9$ gacha bo'lgan sonning yig'indisi $3 \cdot 10^9$ gacha bo'lishi mumkin. Bu qiymat `int` turiga sig'masligi mumkin ($2 \cdot 10^9$ dan katta), shuning uchun `a`, `b`, `c` ning `long long` bo'lishi juda muhim.
9.  `std::cout << "Yes\n";` Agar opalar sovg'ani sotib olishga qodir bo'lsa, "Yes" so'zini ekranga chiqaradi va yangi qatorga o'tadi (`\n`).
10. `std::cout << "No\n";` Agar opalar sovg'ani sotib olishga qodir bo'lmasa, "No" so'zini ekranga chiqaradi va yangi qatorga o'tadi (`\n`).
11. `return 0;` `main` funksiyasining muvaffaqiyatli bajarilganligini bildiradi.

## Edge case lar va eslatmalar
*   **Ma'lumot turlari (Data Types)**: Eng muhim nuqta. $N, A, B, C$ qiymatlari $10^9$ gacha bo'lishi mumkin. Uchta $10^9$ lik sonning yig'indisi $3 \cdot 10^9$ bo'lishi mumkin. Standart C++ `int` ma'lumot turi odatda $2 \cdot 10^9$ atrofidagi qiymatlarni saqlay oladi xolos. Shuning uchun `long long` ma'lumot turidan foydalanish juda muhim, aks holda sonlar toshib ketishi (overflow) va noto'g'ri natija berishi mumkin. Taqdim etilgan yechimda bu holat to'g'ri qabul qilingan.
*   **Nol qiymatlari**: Agar $N=0$ bo'lsa, sovg'a bepul degani. Bu holda, opalarda qancha pul bo'lishidan qat'i nazar (hatto 0 so'm bo'lsa ham), ular uni ola oladilar, chunki $A+B+C \ge 0$ har doim rost. Algoritm bu holatni to'g'ri boshqaradi. Agar $A, B, C$ hammasi 0 bo'lsa-yu, $N>0$ bo'lsa, $0 < N$ bo'lgani uchun "No" chiqadi, bu ham to'g'ri.
*   **Minimal masala**: Masala juda oddiy va asosan asosiy arifmetikaga, shuningdek, to'g'ri ma'lumot turini tanlashga qaratilgan. Bu turdagi masalalar ko'pincha dasturlash musobaqalariga kirish qismi sifatida beriladi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0005) platformasidagi **A0005** raqamli **Yangi yil sovg'asi** masalasi. U **Oson** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0005>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0005, Yangi yil sovg'asi yechimi, robocontest masalalari, c++17, olimpiada yechimi, oson, dasturlash uzbek, competitive programming O'zbekiston.</sub>
