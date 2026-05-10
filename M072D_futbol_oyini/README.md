---
title: "M072D — Futbol o'yini | Robocontest.uz Yechimi"
description: "Robocontest.uz M072D (Futbol o'yini) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M072D, Futbol o'yini yechimi, robocontest Futbol o'yini, M072D c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M072D_futbol_oyini/
lang: uz
---

# M072D — Futbol o'yini

## Masala haqida
Doniyor futbol o'ynashni mashq qilmoqda va to'pni ma'lum bir `X` masofaga tepishi kerak. Bu `X` masofa ikki shartni qanoatlantirishi lozim: u `K` soniga karrali bo'lishi va `[A, B]` oralig'ida joylashishi kerak. Masala Doniyorning bu shartlarni qanoatlantiradigan tarzda to'p tepishi mumkinligini aniqlashni so'raydi. Agar shartlarga mos masofa mavjud bo'lsa "YES", aks holda "NO" chiqarish kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juda sodda: berilgan `[A, B]` oralig'idagi har bir butun sonni tekshirib chiqish. Agar shu oraliqdagi biron bir `X` soni `K` ga bo'linsa (ya'ni `K` ga karrali bo'lsa), demak Doniyor to'pni tepa oladi va javob "YES" bo'ladi. Agar `A` dan `B` gacha bo'lgan barcha sonlar tekshirib chiqilgandan so'ng ham `K` ga karrali son topilmasa, javob "NO" bo'ladi. Bu yondashuv samarali hisoblanadi, chunki `A` va `B` qiymatlari juda katta emas (maksimal 1000).

## Algoritm qadamlari
1.  Kirish ma'lumotlari — `K`, `A` va `B` butun sonlari o'qib olinadi.
2.  `A` dan `B` gacha (shu jumladan `A` va `B` ham) bo'lgan barcha butun sonlar ustida sikl (loop) boshlanadi. Har bir butun sonni `x` deb belgilaymiz.
3.  Siklning har bir qadamida, joriy `x` soni `K` ga qoldiqsiz bo'linishini tekshiramiz. Buning uchun `x % K == 0` shartidan foydalanamiz. (`%` belgisi qoldiqni hisoblash operatoridir).
4.  Agar `x` soni `K` ga qoldiqsiz bo'linsa:
    *   Ekranga "YES" so'zi chiqariladi.
    *   Dastur darhol yakunlanadi, chunki biz talab qilingan shartlarga javob beradigan kamida bitta masofani topdik.
5.  Agar sikl `A` dan `B` gacha bo'lgan barcha sonlarni tekshirib chiqsa ham, `K` ga karrali biron bir son topilmasa (ya'ni sikl tugaguncha dastur yakunlanmagan bo'lsa):
    *   Ekranga "NO" so'zi chiqariladi.
    *   Dastur yakunlanadi.

## Murakkablik tahlili
-   **Vaqt**: `O(B - A + 1)`. Eng yomon holatda, sikl `A` dan `B` gacha bo'lgan barcha sonlarni, ya'ni `B - A + 1` marta takrorlanadi. `A` va `B` ning maksimal qiymati 1000 bo'lgani sababli, eng yomon holatda bu taxminan `1000 - 1 + 1 = 1000` ta operatsiya degani. Bu juda kichik raqam va berilgan 1000 ms vaqt cheklovi uchun mutlaqo yetarli. Shuning uchun, vaqt murakkabligi `O(B)` deb ham aytish mumkin.
-   **Xotira**: `O(1)`. Dastur faqatgina bir nechta butun sonli o'zgaruvchilarni (`k`, `a`, `b`, `x`) saqlash uchun doimiy miqdordagi xotiradan foydalanadi. Kirish ma'lumotlari hajmi qanchalik katta bo'lishidan qat'i nazar, xotira sarfi o'zgarmaydi.
-   **Nega shu murakkablik chegaraga sig'adi**: `O(B)` vaqt murakkabligi (maksimal 1000 iteratsiya) zamonaviy kompyuterlarda bir necha mikrosekund ichida bajariladi, bu 1000 ms limitdan ancha past. `O(1)` xotira murakkabligi esa bir necha bayt degani bo'lib, bu 32 MB limitdan juda kichikdir. Shuning uchun, yechim berilgan cheklovlarga to'liq mos keladi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Bu qator barcha standart kutubxonalarni o'z ichiga oladi. 
                         // Competitive programmingda tezlikni oshirish uchun keng qo'llaniladi.

using namespace std; // std:: prefiksini yozmasdan standart nomlar maydonidagi funksiyalar va sinflardan foydalanish imkonini beradi.

int main() { // Har qanday C++ dasturining asosiy kirish nuqtasi.
    ios_base::sync_with_stdio(false); // C++ standart kiritish/chiqarish (I/O) oqimlarini (cin, cout)
                                     // C standart I/O oqimlari (scanf, printf) bilan sinxronizatsiyasini o'chiradi.
    cin.tie(0); // cin va cout o'rtasidagi bog'liqlikni bekor qiladi. 
                // Bu ikki qator katta hajmli kirish/chiqarish operatsiyalarida dastur tezligini sezilarli darajada oshiradi.

    int k, a, b; // K, A, B o'zgaruvchilari e'lon qilinadi. Ular masofaning karraligi, quyi va yuqori chegaralarni ifodalaydi.
    cin >> k >> a >> b; // Konsoldan K, A, B qiymatlari o'qib olinadi.

    for (int x = a; x <= b; ++x) { // A dan B gacha bo'lgan barcha butun sonlar (x) ustidan sikl boshlanadi.
                                  // Har bir x masofa uchun tekshiruv o'tkaziladi.
        if (x % k == 0) { // Agar x soni K ga qoldiqsiz bo'linsa (ya'ni K ga karrali bo'lsa)...
            cout << "YES" << endl; // ...ekranga "YES" chiqariladi.
            return 0; // Dastur muvaffaqiyatli yakunlanadi, chunki talab qilingan shart topildi.
        }
    }

    cout << "NO" << endl; // Agar sikl tugaguncha K ga karrali birorta son topilmasa,
                          // bu kod qismi ishlaydi va ekranga "NO" chiqariladi.

    return 0; // Dastur muvaffaqiyatli yakunlanadi.
}
```

## Edge case lar va eslatmalar
*   **Minimal oraliq**: Agar `A = B` bo'lsa, sikl faqat bir marta, `x = A` uchun ishlaydi. Bu holda faqat `A` ning `K` ga bo'linishi tekshiriladi, bu to'g'ri natija beradi.
*   **`K = 1` holati**: Agar `K = 1` bo'lsa, har qanday butun son 1 ga bo'linadi. Shuning uchun, agar `A <= B` bo'lsa, `x = A` ning o'zi `K=1` ga bo'linadi va javob doimo "YES" bo'ladi. Algoritm bu holatni to'g'ri boshqaradi.
*   **Chegaralar**: `A`, `B`, `K` sonlari 1 dan 1000 gacha bo'lgan musbat butun sonlardir. Bu esa `K=0` bo'lishi yoki manfiy sonlar bilan ishlash kabi murakkab holatlarning oldini oladi. Yechim bu chegaralar ichida to'g'ri ishlaydi.
*   **Tez I/O**: `ios_base::sync_with_stdio(false); cin.tie(0);` qatorlari kiritish/chiqarish operatsiyalarini tezlashtirish uchun juda muhim, ammo bu masala uchun kirish ma'lumotlari hajmi kichik bo'lgani sababli, ularning yo'qligi ham javob vaqtiga katta ta'sir qilmasdi. Shunga qaramay, competitive programmingda bu yaxshi odat hisoblanadi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M072D) platformasidagi **M072D** raqamli **Futbol o'yini** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M072D>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M072D, Futbol o'yini yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
