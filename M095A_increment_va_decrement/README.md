---
title: "M095A — Increment va Decrement | Robocontest.uz Yechimi"
description: "Robocontest.uz M095A (Increment va Decrement) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M095A, Increment va Decrement yechimi, robocontest Increment va Decrement, M095A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# M095A — Increment va Decrement

## Masala haqida
Bu masala `N` ta butun sonlardan iborat massivni qayta ishlashni talab qiladi, massivning dastlabki barcha elementlari 0 ga teng. `N` qiymati juda katta bo'lishi mumkin (`10^9` gacha). `Q` ta so'rov beriladi, bunda har bir so'rov massivning bir qismini oshiradi yoki kamaytiradi. Birinchi turdagi so'rovlar massivning dastlabki `X` ta elementini `Y` ga oshiradi. Ikkinchi turdagi so'rovlar esa massivning oxirgi `X` ta elementini `Y` ga kamaytiradi. Barcha so'rovlar bajarilgach, massivning har bir elementi o'zining mutlaq qiymati (`abs(A[i])`) bilan almashtiriladi. Yakuniy vazifa — hosil bo'lgan massivdagi eng katta elementning qiymatini topish.

## Yondashuv (g'oya)
`N` massiv o'lchami juda katta bo'lganligi sababli, biz butun massivni xotirada saqlay olmaymiz. Bunday holatlarda, biz *farq massivi* (difference array) konseptsiyasini `std::map` bilan birgalikda ishlatamiz. Asosiy g'oya shundan iboratki, biz faqatgina massiv elementlarining qiymati o'zgaradigan (farq kiritiladigan) nuqtalarni qayd etamiz. Diapazonli yangilash (range update) operatsiyalarini faqat boshlang'ich va tugash nuqtalarida o'zgarishlarni qayd etish orqali samarali bajaramiz. Massivning istalgan `i`-indeksdagi qiymatini esa shu nuqtagacha bo'lgan barcha "farqlarning" yig'indisi (ya'ni, *oldindan yig'indi* - prefix sum) orqali hisoblaymiz. Keyin bu oldindan yig'indilarning mutlaq qiymatlarini ko'rib chiqib, ulardan eng kattasini topamiz.

## Algoritm qadamlari
1.  **Dastlabki sozlash:** `std::map<long long, long long> diff_map` nomli xaritani (map) e'lon qiling. Bu xarita `(indeks, farq qiymati)` juftliklarini saqlaydi. `diff_map[i]` qiymati `i`-indeksda massiv elementining qiymatiga qanday o'zgarish (delta) ta'sir qilganini ko'rsatadi.
2.  **So'rovlarni qayta ishlash:** Barcha `Q` so'rovni ketma-ket qayta ishlash uchun tsikl (loop) yarating:
    *   Agar so'rov turi `1 X Y` bo'lsa (massivning dastlabki `X` ta elementini `Y` ga oshirish):
        *   `diff_map[0]` ga `Y` ni qo'shing. Bu `0`-indeksdan boshlab massiv elementlariga `Y` qo'shilishini anglatadi.
        *   `diff_map[X]` dan `Y` ni ayiring. Bu `X`-indeksdan boshlab `Y` ni qo'shish effektini to'xtatishni anglatadi. Natijada, `A[0]` dan `A[X-1]` gacha bo'lgan elementlar `Y` ga oshadi, `A[X]` va undan keyingi elementlarga esa ta'sir qilmaydi.
    *   Agar so'rov turi `2 X Y` bo'lsa (massivning oxirgi `X` ta elementini `Y` ga kamaytirish):
        *   Kamaytirish boshlanadigan indeks `N - X` hisoblanadi (ya'ni, `A[N-X]` dan `A[N-1]` gacha).
        *   `diff_map[N - X]` dan `Y` ni ayiring. Bu `N - X` indeksdan boshlab massiv elementlaridan `Y` ni ayirishni boshlaydi.
        *   `diff_map[N]` ga `Y` ni qo'shing. Bu `N`-indeksda `Y` ni ayirish effektini to'xtatadi. `N`-indeks massivning chegarasidan tashqarida bo'lganligi sababli, bu `A[N-1]` gacha bo'lgan elementlarga ta'sir qilishni kafolatlaydi.
3.  **Maksimal mutlaq qiymatni hisoblash:** Barcha so'rovlar bajarilgandan so'ng, `diff_map` ni kalitlar (indekslar) bo'yicha o'sish tartibida (std::map buni avtomatik tarzda ta'minlaydi) aylanib chiqing:
    *   `current_cumulative_value` nomli `long long` o'zgaruvchini `0` ga tenglang. Bu joriy segmentdagi massiv elementlarining oldindan yig'indi qiymatini saqlaydi.
    *   `max_absolute_value` nomli `long long` o'zgaruvchini `0` ga tenglang. Bu topilgan maksimal mutlaq qiymatni saqlaydi.
    *   `diff_map` dagi har bir `(indeks, delta)` juftligi uchun:
        *   `max_absolute_value` ni joriy `max_absolute_value` va `std::abs(current_cumulative_value)` orasidagi maksimumga yangilang. Bu `indeks` dan oldingi barcha elementlarning (oldingi `diff_map` kalitidan hozirgi `indeks-1` gacha bo'lgan segmentdagi) qiymatini ko'rib chiqadi.
        *   `current_cumulative_value` ga `delta` ni qo'shing. Bu keyingi segment uchun oldindan yig'indi qiymatini yangilaydi.
4.  **Natijani chop etish:** Barcha iteratsiyalar yakunlangach, `max_absolute_value` o'zgaruvchisi massivdagi eng katta mutlaq qiymatni saqlaydi. Shu qiymatni chop eting.

## Murakkablik tahlili
-   **Vaqt**: `O(Q log Q)`
    -   `Q` ta so'rov mavjud. Har bir so'rovda `diff_map` ga ikkita operatsiya (element qo'shish yoki mavjudini yangilash) bajariladi. `std::map` dagi bu operatsiyalar logarifmik vaqt (`O(log K)`) oladi, bu yerda `K` xaritadagi elementlar soni. Eng yomon holatda `K` qiymati `2Q` gacha yetishi mumkin. Demak, so'rovlarni bajarish umumiy `O(Q log Q)` vaqtni oladi.
    -   So'rovlardan keyin `diff_map` ni aylanib chiqish `O(K)` yoki `O(Q)` vaqtni oladi, chunki xaritadagi elementlar soni maksimal `2Q` bo'lishi mumkin.
    -   Shunday qilib, umumiy vaqt murakkabligi `O(Q log Q)` bo'lib, `Q = 10^5` uchun taxminan `10^5 * log2(10^5)` ≈ `10^5 * 17` ≈ `1.7 * 10^6` amallarni tashkil etadi. Bu `1000 ms` vaqt chegarasiga bemalol sig'adi.
-   **Xotira**: `O(Q)`
    -   `diff_map` xaritasi maksimal `2Q` ta juftlik (entry) saqlashi mumkin, chunki har bir so'rov eng ko'pi bilan ikkita yangi o'zgarish nuqtasini hosil qilishi mumkin.
    -   Har bir juftlik `long long` kalit va `long long` qiymatdan iborat. `Q = 10^5` bo'lganda, `2 * 10^5` juftlik uchun taxminan `2 * 10^5 * (8 + 8) = 3.2 MB` xotira talab qilinadi. Bu `32 MB` xotira chegarasiga bemalol sig'adi.
-   **Nega shu murakkablik chegaraga sig'adi:** Yuqorida keltirilgan tahlillar shuni ko'rsatadiki, algoritmik vaqt va xotira murakkabliklari berilgan cheklovlar doirasida bo'lib, samarali ishlaydi. Ayniqsa, `N` ning kattaligini hisobga olsak, `std::map` yordamida farq massivi yondashuvi bu turdagi masalalar uchun eng maqbul yechimlardan biridir, chunki u massivning faqat kerakli qismlarini (o'zgarish nuqtalarini) xotirada saqlaydi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart C++ kutubxonalarini o'z ichiga oladi.
                         // std::map, std::cin, std::cout, std::abs, std::max kabi funksiyalar va ma'lumot turlari uchun.

int main() {
    std::ios_base::sync_with_stdio(false); // C++ kirish/chiqish (I/O) oqimlarini C tilining standart I/O'si bilan
                                            // sinxronizatsiyani o'chiradi. Bu I/O operatsiyalarini tezlashtiradi.
    std::cin.tie(0);                      // std::cin va std::cout orasidagi bog'liqlikni bekor qiladi.
                                            // Bu std::cin dan keyin std::cout ni avtomatik ravishda tozalashni to'xtatadi
                                            // va yana I/O tezligini oshiradi.

    long long N; // Massivning o'lchami. U juda katta bo'lishi mumkin (10^9 gacha).
    int Q;       // So'rovlar soni (10^5 gacha).
    std::cin >> N >> Q;

    // diff_map (farq xaritasi) elementlar qiymati o'zgaradigan nuqtalarni saqlash uchun ishlatiladi.
    // Kalit (long long) - bu massiv indeksi, qiymat (long long) - bu shu indeksdagi o'zgarish miqdori (delta).
    // Massivning A[i] elementining haqiqiy qiymati A[0] dan A[i] gacha bo'lgan barcha diff_map dagi delta_value larning yig'indisi.
    std::map<long long, long long> diff_map;

    for (int i = 0; i < Q; ++i) { // Barcha Q ta so'rovni birma-bir qayta ishlash uchun tsikl.
        int T;                    // So'rov turi: 1 - oshirish, 2 - kamaytirish.
        long long X, Y;           // So'rov parametrlari. X - ta'sir qiladigan elementlar soni, Y - o'zgarish miqdori.
        std::cin >> T >> X >> Y;
        if (T == 1) {
            // "1 X Y" so'rovi: dastlabki X ta elementning qiymatini Y ga oshirish.
            // Bu A[0], A[1], ..., A[X-1] elementlarga ta'sir qiladi.
            diff_map[0] += Y;   // 0-indeksdan boshlab (ya'ni, massiv boshidan) Y qiymatini qo'shishni boshlaymiz.
            diff_map[X] -= Y;   // X-indeksda bu qo'shilish effekti to'xtatiladi.
                                // Ya'ni, X-indeksdan boshlab Y qiymati ayirib tashlanadi, natijada A[X] va undan keyingi
                                // elementlarga Y qo'shilmaydi.
        } else {
            // "2 X Y" so'rovi: oxirgi X ta elementning qiymatini Y ga kamaytirish.
            // Bu A[N-X], A[N-X+1], ..., A[N-1] elementlarga ta'sir qiladi.
            // Kamaytirishning boshlang'ich indeksi N-X.
            diff_map[N - X] -= Y; // N-X indeksdan boshlab Y qiymatini ayirishni boshlaymiz.
            diff_map[N] += Y;     // N-indeksda bu ayirish effekti to'xtatiladi.
                                  // N-indeks massivning oxiridan (N-1) keyingi birinchi joy bo'lib,
                                  // kamaytirish diapazonini to'g'ri yopish uchun ishlatiladi.
        }
    }

    long long current_cumulative_value = 0; // Joriy ko'rib chiqilayotgan segmentdagi massiv elementlarining qiymati (oldindan yig'indi).
    long long max_absolute_value = 0;       // Barcha segmentlar ichidagi topilgan maksimal mutlaq qiymat.

    // diff_map orqali iteratsiya qilish. std::map kalitlarni avtomatik ravishda o'sish tartibida saqlaydi va iteratsiya qiladi.
    // Har bir 'entry' (kirish) massiv qiymatining potentsial o'zgarish nuqtasini bildiradi.
    // 'current_cumulative_value' ni 'delta' bilan yangilashdan oldin, u oldingi kalitdan joriy 'entry.first' (indeks) - 1 gacha
    // bo'lgan massiv elementlarining qiymatini ifodalaydi.
    for (auto const& entry : diff_map) {
        // long long index = entry.first; // Bu o'zgarish sodir bo'lgan indeks.
        long long delta = entry.second; // Shu indeksdagi o'zgarish qiymati.

        // current_cumulative_value ni 'delta' bilan yangilashdan oldin,
        // bu qiymat massivning oldingi segmenti (oldingi 'diff_map' kalitidan 'index - 1' gacha) uchun amal qiladi.
        // Biz bu qiymatning mutlaqini joriy maksimal mutlaq qiymat bilan solishtirishimiz kerak.
        // Agar 'entry.first' (indeks) massiv chegarasi 'N' ga teng bo'lsa, bu oldingi segment [prev_index, N-1] gacha bo'lgan
        // qiymatni to'g'ri ifodalagan bo'ladi.
        max_absolute_value = std::max(max_absolute_value, std::abs(current_cumulative_value));
        
        // Keyingi segment uchun current_cumulative_value ni yangilash.
        // Bu nuqtada delta qiymati qo'shiladi va keyingi segment uchun qiymat o'zgaradi.
        current_cumulative_value += delta;
    }
    // Tsikldan so'ng, max_absolute_value barcha massiv elementlari orasidagi eng katta mutlaq qiymatni saqlaydi.

    std::cout << max_absolute_value << std::endl; // Yakuniy maksimal mutlaq qiymatni chop etish.

    return 0; // Dastur muvaffaqiyatli yakunlandi.
}
```

## Edge case lar va eslatmalar
*   **`N` ning juda katta bo'lishi:** Masalaning asosiy xususiyati `N` ning `10^9` gacha bo'lishi, bu massivni to'liq xotirada saqlashni imkonsiz qiladi. `std::map` bilan farq massivi texnikasi aynan shu kabi katta hajmli, ammo siyrak (sparse) yangilanishlar bo'ladigan massivlar uchun ideal yechimdir.
*   **Indekslar diapazoni:** Massiv elementlari `A[0]` dan `A[N-1]` gacha indekslanadi. Farq massivi mexanizmida esa, diapazonlarni to'g'ri yopish uchun massivning chegarasidan tashqaridagi `N`-indeks ham ishlatiladi. Masalan, `diff_map[N] += Y` kabi operatsiyalar `N`-indeksdan boshlab ta'sirni bekor qilish uchun xizmat qiladi va to'g'ri hisoblanadi.
*   **`std::map` xususiyatlari:** `std::map` ma'lumot tuzilmasi kalitlarni avtomatik ravishda o'sish tartibida saqlaydi va iteratsiya (aylanib chiqish) paytida shu tartibni ta'minlaydi. Bu bizga *oldindan yig'indi* (prefix sum) ni to'g'ri hisoblash va har bir segmentning haqiqiy qiymatini ketma-ket aniqlash imkonini beradi.
*   **`long long` dan foydalanish:** `N`, `X`, `Y` va massiv elementlarining yakuniy qiymatlari juda katta bo'lishi mumkin (`10^9` gacha). Bir nechta `Y` qiymatlari qo'shilganda yoki ayirilganda `int` turining chegaralaridan (taxminan `±2 * 10^9`) chiqib ketishi mumkin, shuning uchun barcha tegishli o'zgaruvchilar va qiymatlar uchun `long long` turidan foydalanish shart.
*   **Mutlaq qiymat:** So'nggi natijada massiv elementlarining mutlaq qiymati (`std::abs()`) hisobga olinadi. Bu muhim, chunki, masalan, `-100` va `50` ni solishtirganda, `-100` ning mutlaq qiymati `100` bo'lib, u `50` dan katta hisoblanadi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M095A) platformasidagi **M095A** raqamli **Increment va Decrement** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M095A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M095A, Increment va Decrement yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
