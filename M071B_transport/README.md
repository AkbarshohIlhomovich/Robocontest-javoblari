---
title: "M071B — Transport | Robocontest.uz Yechimi"
description: "Robocontest.uz M071B (Transport) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 128 MB."
keywords: "robocontest M071B, Transport yechimi, robocontest Transport, M071B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M071B_transport/
lang: uz
---

# M071B — Transport

## Masala haqida
Dadorlandtiria mamlakatida `N+1` ta shahar mavjud bo‘lib, ular 1 dan `N+1` gacha raqamlangan. Mamlakatda 4 xil transport turi (avtobus, taksi, poyezd, samolyot) ishlaydi. Har bir `i`-shahardan `(i+1)`-shaharga o‘tish uchun `t`-transport turining chipta narxi `a[t][i]` massivi orqali berilgan. Agar `a[t][i] = -1` bo‘lsa, bu transport turi bilan ushbu segmentda harakatlanish mumkin emas. Shuningdek, har bir `t`-transport turi uchun `c[t]` narxida oylik abonement sotib olish mumkin. Abonement sotib olinsa, ushbu transport turidan istalgancha bepul foydalanish mumkin. Maqsad — 1-shahardan `(N+1)`-shaharga borish uchun minimal umumiy xarajatni topish. Barcha yo‘llar bir tomonlama, ya’ni faqat `i`-shahardan `(i+1)`-shaharga o‘tish mumkin.

## Yondashuv (g'oya)
Masalada `N` qiymati `10^5` gacha bo‘lishi mumkin bo‘lsa-da, transport turlari soni juda kam — atigi 4 ta. Bu holatda biz barcha mumkin bo‘lgan abonement sotib olish kombinatsiyalarini (qaysi transport turlari uchun abonement sotib olinadi va qaysilari uchun yo‘q) ko‘rib chiqishimiz mumkin.

Har bir transport turi uchun ikkita variant bor: abonement sotib olish yoki olmaslik. 4 ta transport turi bo‘lgani uchun jami `2^4 = 16` ta kombinatsiya mavjud. Biz har bir kombinatsiyani (bitmask yordamida) sinovdan o‘tkazamiz. Har bir kombinatsiya uchun umumiy yo‘l narxini hisoblaymiz. Bu narx abonementlar uchun to‘langan xarajat va abonement olinmagan transportlar uchun segmentlar bo‘ylab minimum chipta narxlaridan iborat bo‘ladi. Barcha kombinatsiyalar ichida eng kam umumiy narx optimal yechim bo‘ladi.

## Algoritm qadamlari
1.  **Kirish ma'lumotlarini o'qish**: `N` (yo'llar soni), shuningdek, 4 ta transport turi uchun abonement narxlari `C[0], C[1], C[2], C[3]` ni o'qib oling. Keyin har bir `t`-transport turi uchun `i`-shahardan `(i+1)`-shaharga borish narxlari `A[t][i]` ni o'qing. Kodda `t` 0 dan 3 gacha, `i` esa 0 dan `N-1` gacha indekslanadi.
2.  **Minimal umumiy narxni boshlang'ich holatga keltirish**: `min_overall_cost` o‘zgaruvchisini `long long` turining eng katta qiymatiga (`numeric_limits<long long>::max()`) sozlang. Bu keyinchalik topiladigan har qanday haqiqiy narxdan kattaroq bo'lishini ta'minlaydi.
3.  **Abonement kombinatsiyalarini takrorlash (Bitmasking)**:
    *   `mask` o‘zgaruvchisi orqali 0 dan `(1 << 4) - 1` gacha (ya'ni, 0 dan 15 gacha) barcha `2^4 = 16` ta bitmaskni takrorlang. Har bir `mask` abonement sotib olinadigan transport turlari kombinatsiyasini ifodalaydi. Masalan, agar `mask` ning `t`-chi biti 1 bo‘lsa, `t`-transport turiga abonement olingan hisoblanadi.
4.  **Har bir `mask` uchun narxni hisoblash**:
    *   `current_total_cost = 0` va `possible_path = true` deb boshlang'ich holatga keltiring.
    *   `mask` bo'yicha abonement narxlarini `current_total_cost` ga qo'shing. Ya'ni, agar `mask` ning `t`-chi biti 1 bo'lsa, `C[t]` ni `current_total_cost` ga qo'shing.
    *   `i = 0` dan `N-1` gacha har bir shahar segmenti (`i`-shahardan `(i+1)`-shaharga) uchun quyidagilarni bajaring:
        *   `min_segment_cost` ni `long long` turining eng katta qiymatiga (`numeric_limits<long long>::max()`) va `segment_possible = false` deb boshlang'ich holatga keltiring.
        *   `t = 0` dan `3` gacha har bir transport turi uchun:
            *   `segment_cost = A[t][i]` ni oling.
            *   Agar `segment_cost == -1` bo'lsa, bu transport turi ushbu segmentda ishlatilmaydi, shuning uchun keyingi transport turiga o'ting.
            *   Agar `mask` ning `t`-chi biti 1 bo'lsa (ya'ni, bu transportga abonement sotib olingan bo'lsa), `segment_cost` ni 0 ga tenglashtiring, chunki u bepul.
            *   `min_segment_cost` ni `segment_cost` va hozirgi `min_segment_cost` ning minimumiga yangilang.
            *   `segment_possible = true` qiling, chunki ushbu segmentdan o'tish mumkin bo'lgan kamida bitta transport topildi.
        *   Agar `segment_possible` `false` bo'lsa (ya'ni, `i`-shahardan `(i+1)`-shaharga borish uchun hech qanday transport mavjud bo'lmasa), `possible_path = false` qiling va joriy segment bo‘yicha takrorlashdan chiqib ketish kerak, chunki bu kombinatsiya to‘liq yo‘lni ta’minlay olmaydi.
        *   Agar `segment_possible` `true` bo'lsa, `min_segment_cost` ni `current_total_cost` ga qo'shing.
5.  **Minimal umumiy narxni yangilash**:
    *   Segmentlar bo‘yicha takrorlash tugagach, agar `possible_path` `true` bo'lsa (ya'ni, bu `mask` bilan 1-shahardan `(N+1)`-shaharga borish mumkin bo‘lsa), `min_overall_cost` ni `current_total_cost` va hozirgi `min_overall_cost` ning minimumiga yangilang.
6.  **Natijani chop etish**: Nihoyat, `min_overall_cost` ni chop eting.

## Murakkablik tahlili
*   **Vaqt**: `O(2^K * N * K)`
    *   Bu yerda `K` transport turlari soni, ya'ni 4.
    *   Tashqi tsikl barcha abonement kombinatsiyalarini ko'rib chiqadi, bu `2^K` marta ishlaydi.
    *   Har bir kombinatsiya uchun biz `N` ta segmentni ko'rib chiqamiz.
    *   Har bir segment uchun biz `K` ta transport turini ko'rib chiqamiz.
    *   Jami amallar soni: `2^4 * N * 4 = 16 * N * 4 = 64 * N`.
    *   `N` ning maksimal qiymati `10^5` bo'lsa, bu `64 * 10^5 = 6.4 * 10^6` ta amalni tashkil etadi. Bu zamonaviy kompyuterlar uchun 1000 ms vaqt chegarasida juda tez bajariladi.
*   **Xotira**: `O(N * K)`
    *   `A` massivi `4 * N` ta `long long` elementni saqlaydi.
    *   `C` massivi `4` ta `long long` elementni saqlaydi.
    *   Boshqa o'zgaruvchilar doimiy xotira egallaydi.
    *   `N = 10^5` bo'lsa, `4 * 10^5` ta `long long` (har biri 8 bayt) taxminan `3.2 * 10^6` bayt = `3.2` MB ni tashkil qiladi. Bu 128 MB xotira chegarasiga bemalol sig'adi.

## Kod izohi

*   `#include <bits/stdc++.h>`: Bu sarlavha fayli C++ da ko'pchilik standart kutubxonalarni (masalan, `iostream` kirish/chiqish uchun, `vector` dinamik massivlar uchun, `algorithm` min/max funksiyalari uchun) o'z ichiga oladi.
*   `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu qatorlar C++ stream (o'tkazish oqimi) I/O operatsiyalarini tezlashtirish uchun ishlatiladi. Ayniqsa, `N` katta bo'lganda kirish/chiqish operatsiyalari vaqt talab qilishi mumkin, shuning uchun bu optimizatsiyalar foydali.
*   `vector<long long> C(4);`: `C` massivi 4 ta `long long` turidagi elementni saqlaydi, bu abonement narxlarini ifodalaydi. `long long` turi narxlar `10^9` gacha bo'lishi mumkinligini hisobga olgan holda tanlangan.
*   `vector<vector<long long>> A(4, vector<long long>(N));`: `A` ikki o'lchamli massivi har bir transport turi (4 tur) va har bir yo'l segmenti (`N` ta segment) uchun chipta narxlarini saqlaydi. Bu ham `long long` turida.
*   `long long min_overall_cost = numeric_limits<long long>::max();`: Eng kam umumiy narxni kuzatib borish uchun o'zgaruvchi. Dastlab `long long` turining maksimal qiymatiga o'rnatiladi, shunda har qanday haqiqiy narx uni yangilashi mumkin.
*   `for (int mask = 0; mask < (1 << 4); ++mask)`: Bu bitmask usulining asosiy qismi. `mask` o'zgaruvchisi 0 dan `2^4 - 1 = 15` gacha bo'lgan butun sonlarni oladi. Har bir `mask` qiymati qaysi transport turiga abonement olinganini bitlar yordamida ifodalaydi. Masalan, `mask = 5` (ikkilikda `0101`) 0-chi va 2-chi transport turlariga abonement olinganligini bildiradi.
*   `if ((mask >> t) & 1)`: Bu ifoda `mask` ning `t`-chi bitini tekshiradi. Agar `t`-chi bit 1 bo'lsa, bu `t`-chi transport turiga abonement sotib olinganligini anglatadi.
    *   `mask >> t`: `mask` ni `t` pozitsiya o'ngga suradi. Bu `t`-chi bitni eng o'ng (0-chi) pozitsiyaga olib keladi.
    *   `& 1`: bitwise AND operatsiyasi 1 bilan. Agar eng o'ng bit 1 bo'lsa, natija 1 bo'ladi; aks holda 0.
*   `min_segment_cost = min(min_segment_cost, segment_cost);`: Har bir segment uchun to'lanadigan minimal narxni topish. Bu har bir segment uchun (abonement sotib olingan transportlar bepul hisobga olingan holda) eng arzon transport turini tanlashni ta'minlaydi.
*   `bool segment_possible = false;` va `bool possible_path = true;`: Bu mantiqiy bayroqlar (flags) yo'lning har bir segmentidan o'tish mumkinligini va umuman 1-shahardan `(N+1)`-shaharga yetib borish mumkinligini tekshirish uchun ishlatiladi. Agar bitta ham segmentdan o'tib bo'lmasa, `possible_path` `false` bo'ladi va ushbu abonement kombinatsiyasi tashlab yuboriladi.

## Edge case lar va eslatmalar
*   **Mavjud bo'lmagan yo'llar (`a[t][i] = -1`)**: Kod `segment_cost == -1` shartini tekshirib, bu yo'llarni hisobga olmaydi. Agar ma'lum bir segmentdan hech qanday transport turida o'tish mumkin bo'lmasa (ya'ni, barcha `A[t][i]` lar -1 bo'lsa), `segment_possible` `false` bo'lib qoladi, bu esa `possible_path` ni `false` ga o'zgartiradi va joriy abonement kombinatsiyasini yaroqsiz deb topadi.
*   **Narxlar oralig'i**: Masala narxlar `10^9` gacha va `N` `10^5` gacha bo'lishini ko'rsatgan. Shuning uchun umumiy narx `N * max_cost = 10^5 * 10^9 = 10^{14}` gacha yetishi mumkin. Bu `int` turining maksimal qiymatidan (taxminan `2 * 10^9`) ancha katta. Shuning uchun `long long` turidan foydalanish zarur. Kodda `long long` tipi to'g'ri ishlatilgan.
*   **Barcha transportlar uchun abonement sotib olish**: `mask = 15` (`1111` ikkilikda) bo‘lgan holatda barcha 4 ta transport turiga abonement sotib olinadi. Bunday holda, segmentlar bo‘ylab harakatlanish tekin bo‘ladi (agar -1 bo‘lmasa), faqat abonement narxlari (`C[0] + C[1] + C[2] + C[3]`) hisobga olinadi.
*   **Hech qanday abonement sotib olmaslik**: `mask = 0` bo‘lgan holatda hech qanday abonement sotib olinmaydi. Bunday holda, har bir segment uchun faqatgina `A[t][i]` qiymatlaridan minimali tanlanadi. Bu holat ham to'g'ri hisobga olinadi.
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M071B) platformasidagi **M071B** raqamli **Transport** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M071B>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M071B, Transport yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
