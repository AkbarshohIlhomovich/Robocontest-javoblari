---
title: "M069F — Batalyon | Robocontest.uz Yechimi"
description: "Robocontest.uz M069F (Batalyon) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M069F, Batalyon yechimi, robocontest Batalyon, M069F c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# M069F — Batalyon

## Masala haqida
Ushbu masalada N ta batalyon va Q kun davom etadigan dushman hujumlari tasvirlangan. Har bir batalyonda ma'lum miqdordagi askarlar mavjud bo'lib, ular dushmanga ketma-ket qarshi chiqadi. Agar dushman soni batalyon askarlari sonidan ko'p yoki teng bo'lsa, batalyon butunlay yo'q qilinadi va keyingi batalyon jang maydoniga kiradi. Agar dushman soni kam bo'lsa, batalyon tirik qoladi va dushman hujumi shu kun uchun to'xtaydi. Agar barcha batalyonlar yo'q qilinsa, kun oxirida ular o'z holiga qayta tiklanadi. Har bir kun oxirida nechta batalyon tirik qolganini aniqlash talab etiladi.

## Yondashuv (g'oya)
Masalani oddiy simulyatsiya qilish, ya'ni har bir kun uchun barcha batalyonlarni birma-bir tekshirib chiqish, `N` va `Q` ning katta qiymatlari (`10^5`) tufayli juda sekin bo'ladi (`O(N*Q)`). Bu esa vaqt limitidan oshib ketishiga olib keladi.

Asosiy g'oya — dushmanlarning katta soni qancha batalyonni to'liq yo'q qila olishini tezda aniqlash uchun `prefix sum (oldindan yig'indi)` texnikasini `binary search (ikkilik qidiruv)` bilan birgalikda ishlatish. Biz har bir kun uchun o'zgaruvchilarni (qaysi batalyon hozir jang qilayotganini va unda qancha askar qolganini) saqlab boramiz va dushman hujumini samarali qayta ishlaymiz. Agar barcha batalyonlar yo'q qilinsa, ularni kun oxirida qayta tiklash shartini ham e'tiborga olishimiz kerak.

## Algoritm qadamlari
1.  **Kiritish va `prefix sum` hisoblash**:
    *   `N` (batalyonlar soni) va `Q` (hujum kunlari soni) o'qiladi.
    *   `A` massiviga `N` ta batalyonning har biridagi askarlar soni kiritiladi. Askarlar soni `10^9` gacha bo'lgani va ularning yig'indisi `long long` tipida saqlanishi kerak.
    *   `P` nomli `prefix sum (oldindan yig'indi)` massivi yaratiladi. `P[i]` `A[0]` dan `A[i-1]` gacha bo'lgan askarlar yig'indisini saqlaydi. `P` massivi `N+1` o'lchamda bo'ladi, `P[0] = 0` va `P[i+1] = P[i] + A[i]` tarzida hisoblanadi. Bu `upper_bound` (ikkilik qidiruv) funksiyasi bilan ishlashda qulaylik yaratadi.

2.  **Boshlang'ich holat**:
    *   `current_idx` o'zgaruvchisi hozirda qisman yo'q qilingan yoki jang qilishga tayyor bo'lgan birinchi batalyonning indeksini saqlaydi. Dastlab `current_idx = 0` (birinchi batalyon).
    *   `current_rem_soldiers` o'zgaruvchisi `A[current_idx]` batalyonida qolgan askarlar sonini saqlaydi. Dastlab `current_rem_soldiers = A[0]`.

3.  **Har bir hujum kuni uchun sikl (`Q` marta)**:
    *   Joriy kun uchun dushmanlar soni `enemies` o'qiladi.
    *   **Batalyonlarni qayta tiklash**: Agar oldingi kun barcha batalyonlar yo'q qilingan bo'lsa (`current_idx == N`), ular joriy kunning boshida qayta tiklanadi. Buning uchun `current_idx` `0` ga va `current_rem_soldiers` `A[0]` ga tiklanadi.
    *   **Joriy batalyon bilan kurash**:
        *   Agar `enemies >= current_rem_soldiers` bo'lsa: Joriy (`current_idx`) batalyon to'liq yo'q qilinadi. `enemies` dan `current_rem_soldiers` soni ayiriladi. `current_idx` bittaga oshiriladi. `current_rem_soldiers` 0 ga tenglashtiriladi (chunki keyingi batalyon dastlab to'liq askarlar bilan bo'ladi).
            *   Agar bu operatsiyadan so'ng `current_idx == N` bo'lsa, barcha batalyonlar yo'q qilingan va kun uchun jang tugaydi.
            *   Aks holda (`current_idx < N`): Hali dushmanlar bor va batalyonlar qolgan. `prefix sum` va `binary search` yordamida dushmanlar qancha qo'shimcha batalyonni to'liq yo'q qila olishini aniqlaymiz:
                *   `target_sum_for_prefix_search = enemies + P[current_idx]` hisoblanadi. Bu, `current_idx` dan boshlab, dushmanlar yo'q qila oladigan jami askarlar sonini (oldingi yo'q qilingan batalyonlar askarlari bilan birga) ifodalaydi.
                *   `P` massivining `P[current_idx]` dan `P[N]` gacha bo'lgan qismida `target_sum_for_prefix_search` dan qat'iy katta bo'lgan birinchi elementni `upper_bound` funksiyasi yordamida topamiz. Bu funksiya iterator qaytaradi.
                *   `distance(P.begin(), it) - 1` yordamida `upper_bound` qaytargan iteratorning indeksini topamiz. Bu indeks `new_current_idx` deb o'zlashtiriladi. `new_current_idx` - bu joriy hujumdan keyin birinchi bo'lib qisman tirik qolgan yoki jang qilishga tayyor bo'lgan batalyonning indeksidir.
                *   Yo'q qilingan butun batalyonlardagi jami askarlar soni `P[new_current_idx] - P[current_idx]` hisoblanadi va bu son `enemies` dan ayiriladi.
                *   `current_idx` `new_current_idx` ga yangilanadi.
                *   Agar `current_idx < N` bo'lsa: `A[current_idx]` batalyonida qolgan askarlar soni hisoblanadi: `current_rem_soldiers = A[current_idx] - enemies`.
                *   Aks holda (`current_idx == N`): Barcha batalyonlar yo'q qilingan.
        *   Agar `enemies < current_rem_soldiers` bo'lsa: Joriy (`current_idx`) batalyon barcha dushmanlarni mag'lub etadi va o'zi tirik qoladi. `current_rem_soldiers` dan `enemies` soni ayiriladi. Dushmanlar tugaganligi sababli, kun uchun jang tugaydi.

    *   **Kun oxiridagi natijani chop etish**:
        *   Agar `current_idx == N` bo'lsa (ya'ni, joriy kun hujumi natijasida barcha batalyonlar yo'q qilingan bo'lsa), masala shartiga ko'ra ular kun oxirida qayta tiklanadi. Shuning uchun `N` soni chop etiladi.
        *   Aks holda (`current_idx < N`), `N - current_idx` ta batalyon tirik qolgan bo'ladi. Bu son chop etiladi.

## Murakkablik tahlili
-   **Vaqt**: `O(N + Q log N)`
    *   `P` (prefix sum) massivini hisoblash `O(N)` vaqt oladi.
    *   Har bir `Q` so'rov (hujum kuni) uchun:
        *   Batalyonlarni qayta tiklash va dastlabki batalyon bilan kurashish `O(1)` vaqt oladi.
        *   `upper_bound` (ikkilik qidiruv) funksiyasini chaqirish `O(log N)` vaqt oladi.
    *   Shunday qilib, umumiy vaqt murakkabligi `O(N + Q log N)` ga teng. `N, Q <= 100,000` bo'lgan holda, `10^5 + 10^5 * log(10^5) approx 10^5 + 10^5 * 17` bu `1.8 * 10^6` operatsiya atrofida bo'lib, 1000 ms vaqt limiti ichida bemalol ishlashi mumkin.

-   **Xotira**: `O(N)`
    *   `A` (batalyon askarlari) va `P` (prefix sum) massivlari `N` elementdan iborat bo'ladi.
    *   `N <= 100,000` va har bir element `long long` (8 bayt) bo'lgani uchun, jami xotira `2 * N * 8` baytni tashkil qiladi.
    *   `2 * 100,000 * 8` bayt = `1,600,000` bayt = `1.6 MB`. Bu 32 MB xotira limitiga sig'adi.

## Kod izohi

-   `#include <bits/stdc++.h>`: C++ standart kutubxonalarining ko'pini o'z ichiga oladi.
-   `using namespace std;`: `std` nomfazasini ishlatish uchun.
-   `ios_base::sync_with_stdio(false); cin.tie(0);`: Tezroq kiritish/chiqarish uchun optimizatsiyalar. Bu C++ iostream funksiyalarini C standart I/O dan ajratib, `cin` va `cout` ning buferini bo'shatadi.
-   `vector<long long> A(N);`: `N` ta batalyonning askarlar sonini saqlash uchun `long long` tipidagi dinamik massiv. Askarlar soni `10^9` gacha bo'lganligi sababli `long long` ishlatish shart.
-   `vector<long long> P(N + 1, 0);`: `Prefix sum` massivi. `long long` tipida, chunki yig'indilar `N * max(A_i) = 10^5 * 10^9 = 10^14` gacha bo'lishi mumkin. `N+1` o'lchamda ekanligi `P[0]` ni 0 qilish va `P[i+1]` ni `A[0]`...`A[i]` yig'indisini ifodalash uchun.
-   `current_idx`, `current_rem_soldiers`: Yuqorida "Algoritm qadamlari" bo'limida tushuntirilganidek, joriy jang holatini saqlovchi o'zgaruvchilar.
-   `if (current_idx == N) { current_idx = 0; current_rem_soldiers = A[0]; }`: Bu qism oldingi kun barcha batalyonlar yo'q qilingan bo'lsa, ularni joriy kun boshida qayta tiklash mantiqini amalga oshiradi.
-   `if (enemies >= current_rem_soldiers) { ... }`: Birinchi batalyonning to'liq yo'q qilinishini tekshiruvchi blok.
-   `long long target_sum_for_prefix_search = enemies + P[current_idx];`: Bu eng muhim qadamlardan biri. Bu, `current_idx` dan boshlab, joriy dushmanlar qancha askarni yo'q qila olishini (ya'ni, dushmanlarning yo'q qilish quvvatini oldingi yo'q qilingan batalyonlar askarlari summasiga qo'shish orqali) umumiy summani topish.
-   `auto it = upper_bound(P.begin() + current_idx, P.begin() + N + 1, target_sum_for_prefix_search);`: `upper_bound` funksiyasi `P` massivining ma'lum bir oralig'ida (`P[current_idx]` dan `P[N]` gacha) berilgan `target_sum_for_prefix_search` qiymatidan qat'iy katta bo'lgan birinchi elementga ishora qiluvchi iteratorni topadi.
-   `int new_current_idx = distance(P.begin(), it) - 1;`: `distance` funksiyasi iteratorlar orasidagi masofani (indekslar farqini) hisoblaydi. `-1` esa bizga `target_sum_for_prefix_search` ni qamrab olgan *eng oxirgi* prefix sum `P[k-1]` ning indeksini (`k-1`) beradi, bu esa `new_current_idx` ga mos keladi.
-   `long long soldiers_consumed_by_full_battalions = P[new_current_idx] - P[current_idx];`: `current_idx` dan `new_current_idx-1` gacha bo'lgan barcha to'liq yo'q qilingan batalyonlardagi jami askarlar sonini hisoblaydi.
-   `if (current_idx == N) { cout << N << "\n"; } else { cout << N - current_idx << "\n"; }`: Kun oxirida qolgan batalyonlar sonini chop etish mantiqi. Agar barcha batalyonlar yo'q qilingan bo'lsa (`current_idx == N`), ular qayta tiklanganligi sababli `N` chop etiladi. Aks holda `N - current_idx` chop etiladi.

## Edge case lar va eslatmalar
*   **Ma'lumot turlari**: `A[i]` va `B[j]` ning qiymatlari juda katta bo'lishi mumkin (`10^9`, `10^18`), shuning uchun askarlar soni va dushmanlar soni, shuningdek `prefix sum` hisob-kitoblari uchun `long long` tipidan foydalanish shart.
*   **Batalyonlarning qayta tiklanishi**: Masala shartida "Agar barcha batalyon qirilib ketsa... kun oxirida ular o'rniga xuddi shuncha askarlardan tashkil topgan batalyonlar tashkil qilinadi" deyilgan. Bu ikkita joyda hisobga olinadi:
    1.  Agar oldingi kun barcha batalyonlar yo'q qilingan bo'lsa (`current_idx == N`), joriy kun boshida ular qayta tiklanadi (`current_idx = 0`, `current_rem_soldiers = A[0]`).
    2.  Agar joriy kunning o'zida barcha batalyonlar yo'q qilingan bo'lsa (`current_idx == N`), kun oxirida ular qayta tiklanganligi sababli `N` soni chop etiladi.
*   **`upper_bound` ning ishlatilishi**: `upper_bound(begin, end, val)` `[begin, end)` oraliqda `val` dan qat'iy katta bo'lgan birinchi elementni topadi. Bizning holatda, `P[k] > target_sum_for_prefix_search` bo'lgan birinchi `P[k]` ni topib, uning indeksini (va shundan kelib chiqib `-1` qilib) batalyonlar chegarasini aniqlaymiz.
*   **Minimal N, Q**: `N=1`, `Q=1` kabi holatlar ham to'g'ri ishlashini ta'minlash kerak. Algoritm bu holatlarda ham to'g'ri ishlaydi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M069F) platformasidagi **M069F** raqamli **Batalyon** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M069F>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M069F, Batalyon yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
