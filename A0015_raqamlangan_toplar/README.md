---
title: "A0015 — Raqamlangan to'plar | Robocontest.uz Yechimi"
description: "Robocontest.uz A0015 (Raqamlangan to'plar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0015, Raqamlangan to'plar yechimi, robocontest Raqamlangan to'plar, A0015 c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /A0015_raqamlangan_toplar/
lang: uz
---

# A0015 — Raqamlangan to'plar

## Masala haqida
Bu masalada Hasan va Husan o'yin o'ynashadi. Ularda 0 dan `N-1` gacha raqamlangan to'plar mavjud. O'yin bir necha bosqichdan iborat: avval barcha to'plar tartibi teskarisiga o'zgartiriladi (0,1,2,3 dan 3,2,1,0 ga). Keyin, har bir keyingi bosqichda, tartibni o'zgartirish (teskariga burish) diapazoni bir pozitsiya o'ngdan boshlab qisqarib boradi, ammo oxirgi pozitsiya (`N-1`) har doim o'zgarmas qoladi. O'yin yakunida, Husan Hasandan dastlab `K`-chi o'rinda turgan to'p oxirida qaysi o'rinda bo'lishini so'raydi. Biz Hasanga g'alaba qozonishiga yordam berishimiz kerak.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi — butun to'plar ro'yxatini (massivni) har bir bosqichda simulyatsiya qilib o'zgartirish o'rniga, faqatgina dastlabki `K`-chi pozitsiyada joylashgan bitta to'pning oxirgi holatini kuzatib borishdir. Har bir teskariga burish (reverse) operatsiyasi massivning ma'lum bir segmentiga ta'sir qiladi. Agar biz kuzatayotgan to'p shu segment ichida bo'lsa, uning yangi pozitsiyasini matematik formula yordamida tezda hisoblay olamiz. Aks holda, uning pozitsiyasi o'zgarmaydi. Bu yondashuv massivning har bir elementini qayta ishlash zaruratini yo'q qilib, vaqt murakkabligini sezilarli darajada kamaytiradi.

## Algoritm qadamlari

1.  **Dastlabki holatni aniqlash**: Berilgan `K` qiymatini `current_pos` (joriy pozitsiya) deb nomlangan o'zgaruvchiga o'zlashtiramiz. Bu dastlabki `K`-chi to'pning boshlang'ich pozitsiyasidir.
2.  **Operatsiyalarni takrorlash**: `i` ni 0 dan `N-1` gacha oshirib boradigan sikl boshlaymiz. Bu `N` marta takrorlanadigan teskariga burish operatsiyalarining har birini ifodalaydi:
    *   `i = 0`: Birinchi operatsiya, massivni `[0, N-1]` diapazonida teskariga buradi.
    *   `i = 1`: Ikkinchi operatsiya, massivni `[1, N-1]` diapazonida teskariga buradi.
    *   ...
    *   `i = N-1`: Oxirgi operatsiya, massivni `[N-1, N-1]` diapazonida teskariga buradi (bu aslida hech qanday o'zgarishga olib kelmaydi, chunki faqat bitta elementdan iborat segment).
3.  **Diapazonni belgilash**: Har bir `i`-chi operatsiya uchun teskariga burish diapazonining boshlanishi `start_index = i` va oxiri `end_index = N-1` deb belgilanadi.
4.  **To'p pozitsiyasini tekshirish**: `current_pos` ni shu `[start_index, end_index]` diapazonida joylashganligini tekshiramiz. Ya'ni, `current_pos >= start_index` va `current_pos <= end_index` shartlari bajarilsa.
5.  **Pozitsiyani yangilash**: Agar `current_pos` belgilangan diapazon ichida bo'lsa, uning yangi pozitsiyasini quyidagi formula yordamida hisoblaymiz:
    `new_pos = start_index + (end_index - current_pos)`.
    Bu formula, `start_index` va `end_index` orasidagi elementni teskari qilib, uning yangi joyini topadi. Misol uchun, `start_index` dagi element `end_index` ga, `end_index` dagi element `start_index` ga o'tadi. `current_pos` ni bu `new_pos` ga o'zlashtiramiz.
6.  **Natijani chop etish**: `N` ta operatsiya tugaganidan so'ng, `current_pos` o'zgaruvchisida dastlabki `K`-chi to'pning o'yin oxiridagi yakuniy pozitsiyasi saqlanadi. Bu qiymatni chop etamiz.

## Murakkablik tahlili

*   **Vaqt**: `O(T * N)`
    Har bir test holati (`solve()` funksiyasi) uchun, biz `N` marta takrorlanadigan bir siklni bajaramiz. Sikl ichidagi operatsiyalar (pozitsiyani tekshirish va hisoblash) doimiy vaqt (`O(1)`) oladi. Demak, har bir test holati uchun vaqt murakkabligi `O(N)` ni tashkil qiladi. Umumiy `T` ta test holati uchun umumiy vaqt murakkabligi `O(T * N)` bo'ladi.
    Masalada berilgan cheklovlar: `N <= 10^5` va `T <= 50`. Eng yomon holatda, `50 * 10^5 = 5 * 10^6` operatsiya bajariladi. Zamonaviy kompyuterlar odatda bir soniyada taxminan `10^8` operatsiyani bajarishga qodir, shuning uchun `5 * 10^6` operatsiya `1000 ms` vaqt chegarasiga bemalol sig'adi.

*   **Xotira**: `O(1)`
    Algoritm faqat bir nechta butun son o'zgaruvchilarni (masalan, `n, k, current_pos, i, start_index, end_index`) ishlatadi. Bu o'zgaruvchilarning xotira hajmi `N` va `K` qiymatlariga bog'liq emas, doimiy hisoblanadi. Demak, xotira murakkabligi `O(1)` ni tashkil qiladi.
    16 MB xotira chegarasi uchun `O(1)` juda kichik va hech qanday muammo tug'dirmaydi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Umumiy kutubxonalarni o'z ichiga oladi, shu jumladan iostream

// Function to solve a single test case
void solve() {
    int n, k;
    std::cin >> n >> k; // N va K qiymatlarini o'qiymiz

    int current_pos = k; // Dastlab K-chi o'rinda turgan to'pning hozirgi pozitsiyasi

    // Bu for sikli N ta teskariga burish (reverse) operatsiyalarini simulyatsiya qiladi.
    // 'i' o'zgaruvchisi har bir operatsiya uchun boshlang'ich indeksni (start_index) bildiradi.
    // Har doim oxirgi indeks (end_index) N-1 bo'ladi.
    for (int i = 0; i < n; ++i) {
        int start_index = i; // Teskariga burish diapazonining boshlanishi
        int end_index = n - 1; // Teskariga burish diapazonining oxiri (massiv oxiri)

        // Agar biz kuzatayotgan to'p (current_pos) joriy teskariga burish diapazoniga
        // [start_index, end_index] tushsa...
        if (current_pos >= start_index && current_pos <= end_index) {
            // ...uning yangi pozitsiyasini hisoblaymiz.
            // Segment ichidagi 'p' pozitsiyadagi element 'start + (end - p)' pozitsiyaga o'tadi.
            current_pos = start_index + (end_index - current_pos);
        }
        // Agar current_pos diapazon tashqarisida bo'lsa, uning pozitsiyasi o'zgarmaydi.
    }
    
    std::cout << current_pos << std::endl; // Yakuniy pozitsiyani chop etamiz
}

int main() {
    // C++ standart oqimlarini (cin/cout) raqobatli dasturlash uchun optimallashtirish.
    // Bu C'ning stdio kutubxonasi bilan bog'lanishni bekor qiladi (sync_with_stdio(false))
    // va har bir cout'dan oldin cin'ni avtomatik tozalashni oldini oladi (cin.tie(0)),
    // shu bilan kirish/chiqish (I/O) operatsiyalarini sezilarli darajada tezlashtiradi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t; // Test holatlari sonini o'qiymiz
    while (t--) { // Har bir test holati uchun
        solve();   // solve() funksiyasini chaqiramiz
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi
}

```

## Edge case lar va eslatmalar

*   **`N = 1` bo'lgan holat**: Faqat bitta to'p bo'lsa (`0` raqami bilan), `K` albatta `0` ga teng bo'ladi. Birinchi operatsiyada (`i=0`) `[0,0]` diapazon teskariga buriladi, bu `0` raqamli to'pning o'rnini o'zgartirmaydi. Keyingi operatsiyalar (`i=1` dan `N-1` gacha) uchun teskariga burish diapazoni `[i, N-1]` bo'lib, `N-1` ham `0` ga teng bo'lgani sababli `[i,0]` bo'ladi. `i` har doim `0` dan katta yoki teng bo'ladi, shuning uchun `current_pos` (0) bu diapazonlarga tushmaydi. Natija `0` bo'ladi, bu to'g'ri.
*   **`K = 0` bo'lgan holat**: Dastlabki `0`-chi to'pning harakatini kuzatish.
    *   Birinchi qadamda (`i=0`) `[0, N-1]` diapazon teskariga buriladi. `0` raqamli to'p `N-1` pozitsiyaga o'tadi. `current_pos` endi `N-1`.
    *   Keyingi qadamda (`i=1`) `[1, N-1]` diapazon teskariga buriladi. `current_pos` (`N-1`) bu diapazonga tushadi. Uning yangi pozitsiyasi `1 + ((N-1) - (N-1)) = 1` bo'ladi.
    *   Umuman olganda, `current_pos` teskari aylantirish diapazonining `start_index` va `end_index` orasida bo'lganida, u `start_index + (end_index - current_pos)` formulasi bo'yicha harakat qiladi. Bu `K`-chi to'pning pozitsiyasini doimiy ravishda to'g'ri kuzatib borishimizni ta'minlaydi.
*   **`K = N-1` bo'lgan holat**: Dastlabki `N-1`-chi to'pning harakatini kuzatish.
    *   Birinchi qadamda (`i=0`) `[0, N-1]` diapazon teskariga buriladi. `N-1` raqamli to'p `0` pozitsiyaga o'tadi. `current_pos` endi `0`.
    *   Keyingi qadamda (`i=1`) `[1, N-1]` diapazon teskariga buriladi. `current_pos` (`0`) bu diapazonga tushmaydi (chunki `0 < 1`). Uning pozitsiyasi `0` da qoladi.
    *   Keyingi barcha qadamlarda ham `current_pos` (`0`) har doim `[i, N-1]` diapazoniga tushmaydi (chunki `i` har doim `0` dan katta yoki teng, shuning uchun `0 < i` bo'ladi). Demak, `N-1`-chi to'p o'yin oxirida `0`-chi pozitsiyada bo'ladi.
*   **`std::ios_base::sync_with_stdio(false); std::cin.tie(0);`**: Ushbu qatorlar C++ standart kirish/chiqish (I/O) oqimlarini raqobatli dasturlash muhitida tezlashtirish uchun juda muhimdir. Ular `std::cin` va `std::cout` ning C tilining `stdio` kutubxonasi bilan sinxronizatsiyasini o'chiradi va `std::cin` ning har bir kiritish operatsiyasidan oldin `std::cout` buferini tozalashini bekor qiladi. Bu katta miqdordagi kiritish/chiqish operatsiyalari mavjud bo'lgan masalalarda dasturning umumiy ish vaqtini sezilarli darajada qisqartirishi mumkin.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0015) platformasidagi **A0015** raqamli **Raqamlangan to'plar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0015>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0015, Raqamlangan to'plar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
