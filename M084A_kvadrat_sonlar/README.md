---
title: "M084A — Kvadrat sonlar | Robocontest.uz Yechimi"
description: "Robocontest.uz M084A (Kvadrat sonlar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M084A, Kvadrat sonlar yechimi, robocontest Kvadrat sonlar, M084A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M084A_kvadrat_sonlar/
lang: uz
---

# M084A — Kvadrat sonlar

## Masala haqida
Ushbu masalada bizga \(N\) deb nomlangan natural son beriladi. Bizning vazifamiz, kvadrati \(N\) dan oshmaydigan barcha natural sonlarning kvadratlarini topish va ularni o'sish tartibida chop etish. Misol uchun, agar \(N=65\) bo'lsa, javob `1 4 9 16 25 36 49 64` bo'lishi kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juda sodda va to'g'ridan-to'g'ri. Biz 1 dan boshlab natural sonlarni (misol uchun, `k`) birma-bir ko'rib chiqamiz. Har bir `k` uchun uning kvadratini (`k*k`) hisoblaymiz. Agar hisoblangan kvadrat \(N\) dan kichik yoki unga teng bo'lsa, uni javobga qo'shamiz (yoki chop etamiz). Agar hisoblangan kvadrat \(N\) dan katta bo'lib ketsa, demak keyingi `k` sonlarining kvadratlari ham \(N\) dan katta bo'ladi (chunki `k` o'sib boradi), shuning uchun jarayonni to'xtatamiz. Bu yondashuv barcha talablarni qondiradi: sonlar o'sish tartibida bo'ladi va faqat \(N\) dan oshmaydiganlari kiritiladi.

## Algoritm qadamlari
1.  Kirishdan \(N\) sonini o'qib olish. \(N\) qiymati \(10^9\) gacha bo'lishi mumkinligi sababli, `long long` ma'lumot turi ishlatiladi.
2.  `first_output` deb nomlangan `bool` (mantiqiy) o'zgaruvchini `true` (rost) qiymatiga o'rnatish. Bu o'zgaruvchi natijalarni chop etishda sonlar orasiga bo'sh joy (space) qo'yishni to'g'ri boshqarish uchun ishlatiladi.
3.  `k` ni 1 dan boshlab o'sish tartibida cheksiz sikl (loop) boshlash. `k` ham `long long` tipida bo'ladi.
4.  Siklning har bir iteratsiyasida, `k` ning kvadratini (`k * k`) `square` o'zgaruvchisiga hisoblab yozish. Bu o'zgaruvchi ham `long long` tipida bo'lishi kerak, chunki \(N\) ning maksimal qiymatida `k*k` natijasi `int` (butun son) chegarasidan oshib ketishi mumkin.
5.  Agar `square` ning qiymati \(N\) dan katta bo'lsa (`square > n`), bu degani kerakli kvadratlar tugadi. Shuning uchun siklni to'xtatish (`break` buyrug'i bilan).
6.  Agar `square` hali ham \(N\) dan kichik yoki teng bo'lsa (`square <= n`):
    *   `first_output` `false` (yolg'on) bo'lsa (ya'ni, bu birinchi chop etilayotgan son emas), avval bitta bo'sh joy chop etish.
    *   `square` qiymatini chop etish.
    *   `first_output` ni `false` ga o'zgartirish, chunki endi kamida bitta son chop etildi va keyingi son chop etilishi kerak bo'lsa, uning oldiga bo'sh joy qo'yiladi.
7.  Sikl tugagandan so'ng, chop etilgan sonlardan keyin yangi qatorga o'tish (`endl`) uchun buyruq berish.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(\(\sqrt{N}\))
    *   Algoritm `k` sonini 1 dan boshlab, `k*k` qiymati \(N\) dan oshib ketguncha oshirib boradi. Bu degani `k` ning maksimal qiymati taxminan \(\sqrt{N}\) ga teng bo'ladi.
    *   Har bir iteratsiyada (sikl ichida) faqat doimiy vaqt oladigan amallar (ko'paytirish, solishtirish, chop etish) bajariladi.
    *   Masalan, agar \(N = 10^9\) bo'lsa, \(\sqrt{10^9} \approx 31622\). Dastur taxminan 31622 ta iteratsiya bajaradi, bu esa zamonaviy kompyuterlarda juda tez (bir necha millisoniya) bajariladi. Test natijasida 7 ms vaqt olinganligi buni tasdiqlaydi.
-   **Xotira murakkabligi**: O(1)
    *   Dastur faqatgina bir nechta o'zgaruvchini (N, k, square, first_output) saqlaydi.
    *   Bu o'zgaruvchilarning soni yoki hajmi \(N\) ning kattaligiga bog'liq emas.
    *   Shuning uchun ishlatiladigan xotira doimiy bo'lib, juda oz miqdorni tashkil etadi (0 KB). Bu 16 MB xotira limiti uchun yetarli.

## Kod izohi
-   `#include <bits/stdc++.h>`: C++ standart kutubxonalarining ko'p qismini o'z ichiga oladigan umumiy header fayl. Competitive programmingda qulaylik uchun keng qo'llaniladi.
-   `using namespace std;`: `std::` nom fazosidagi funksiyalar va sinflarni (masalan, `cin`, `cout`, `endl`) to'g'ridan-to'g'ri, prefikssiz ishlatish imkonini beradi.
-   `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu ikkita qator C++ kirish/chiqish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi. `sync_with_stdio(false)` C++ streamlarini C standart I/O streamlari bilan sinxronizatsiyasini o'chiradi, `cin.tie(0)` esa `cin` ob'ektini `cout` ob'ektidan bog'liqligini uzadi, ya'ni `cin` dan keyin `cout` avtomatik tarzda flush qilinmaydi.
-   `long long n; cin >> n;`: Kirishdan \(N\) sonini o'qiydi. \(N \le 10^9\) bo'lgani uchun, `long long` butun son turidan foydalaniladi, chunki `int` odatda \(2 \cdot 10^9\) gacha bo'lgan qiymatlarni saqlaydi va agar \(N\) juda katta bo'lsa, ba'zi hisob-kitoblar `int`da toshib ketishi mumkin.
-   `bool first_output = true;`: Javoblarni formatlash (bo'sh joylarni to'g'ri joylashtirish) uchun boshlang'ich holat.
-   `for (long long k = 1; ; ++k)`: `k` sonini 1 dan boshlab cheksiz sikl boshlaydi. `++k` har iteratsiyada `k` ni bittaga oshiradi. `k` `long long` deb e'lon qilingan, chunki uning kvadrati (`k*k`) \(N\) ning maksimal qiymatida `long long` bo'lishi kerak.
-   `long long square = k * k;`: `k` ning kvadratini hisoblab `square` o'zgaruvchisiga saqlaydi. `square` ning `long long` bo'lishi shart, chunki `k` ning maksimal qiymati (taxminan 31622) uchun `k*k` (\(31622^2 \approx 999950884\)) `int` ga sig'sa ham, bu holda \(N\) ning o'zi `long long` bo'lganligi sababli, `k*k` ning natijasi ham `long long` bo'lishi xavfsizlik va aniqlikni ta'minlaydi.
-   `if (square > n) { break; }`: Agar hisoblangan kvadrat \(N\) dan oshib ketsa, siklni to'xtatadi.
-   `if (!first_output) { cout << " "; }`: Agar `first_output` `false` bo'lsa (ya'ni, bu birinchi chop etilayotgan son emas), oldingi son bilan orasiga bo'sh joy qo'yiladi.
-   `cout << square;`: Kvadrat sonni chop etadi.
-   `first_output = false;`: Birinchi son chop etilganidan keyin bu o'zgaruvchini `false` ga o'zgartiradi, shu sababli keyingi sonlar orasiga bo'sh joy qo'yiladi.
-   `cout << endl;`: Barcha kvadratlar chop etilgandan so'ng, yangi qatorga o'tadi.
-   `return 0;`: Dastur muvaffaqiyatli yakunlanganini ko'rsatadi.

## Edge case lar va eslatmalar
-   **`N=1` holati**: Agar \(N=1\) bo'lsa, sikl `k=1` uchun `square=1` ni hisoblaydi, chop etadi. Keyin `k=2` uchun `square=4` ni hisoblaydi, bu \(N\) dan katta bo'lgani uchun sikl to'xtaydi. Natija `1` bo'ladi, bu to'g'ri.
-   **Katta `N` qiymatlari**: \(N\) `10^9` gacha bo'lishi mumkin. Shuning uchun `k*k` hisobida integer overflow (butun son toshib ketishi) yuz bermasligi uchun `k`, `square` va `n` o'zgaruvchilari `long long` ma'lumot turida e'lon qilingan. Bu juda muhim qadam.
-   **Chop etish formati**: Masalada javoblar bo'sh joy bilan ajratilgan holda, o'sish tartibida va oxirida yangi qator bilan tugashi talab qilinadi. Koddagi `first_output` mantiqiy o'zgaruvchisi va `cout << endl;` buyrug'i bu format talablarini to'liq qondiradi.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M084A) platformasidagi **M084A** raqamli **Kvadrat sonlar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M084A>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M084A, Kvadrat sonlar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
