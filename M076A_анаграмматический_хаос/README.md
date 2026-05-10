---
title: "M076A — Анаграмматический Хаос | Robocontest.uz Yechimi"
description: "Robocontest.uz M076A (Анаграмматический Хаос) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M076A, Анаграмматический Хаос yechimi, robocontest Анаграмматический Хаос, M076A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M076A_анаграмматический_хаос/
lang: uz
---

# M076A — Anagrammatik Xaos

## Masala haqida
Ushbu masalada bizga `k` xil harfdan tashkil topgan `s` satri beriladi. Bir operatsiya orqali satrdagi ikkita qo'shni harfning o'rnini almashtirish mumkin. `d(x, y)` funksiyasi `x` satrni `y` satrga aylantirish uchun zarur bo'lgan minimal operatsiyalar sonini anglatadi. `P(s)` esa `s` satrining barcha mumkin bo'lgan o'rin almashtirishlari (permutatsiyalari) to'plamidir. Bizning vazifamiz `s` satrining barcha mumkin bo'lgan `s'` permutatsiyalari orasida `d(s, s')` qiymatining maksimumini topish. `k` harflar soni kichik (`2 <= k <= 10`), satr uzunligi `N` esa katta (`|s| <= 10^5`).

## Yondashuv (g'oya)
Asosiy g'oya Dinamik Dasturlash (DD) va bitmaskadan foydalanishdir. Ikki satr `x` va `y` (agar ular bir-birining permutatsiyasi bo'lsa) orasidagi `d(x, y)` minimal operatsiyalar soni `x` satrida `y` satriga nisbatan hosil bo'lgan inversiyalar (teskari tartibda joylashgan juftliklar) soniga tengdir. Masalani yechish uchun biz `s` satrining shunday `s'` permutatsiyasini topishimiz kerakki, `s` satrida `s'` ga nisbatan eng ko'p inversiyalar hosil bo'lsin.

Eng ko'p inversiyalar hosil qilish uchun, biz `s'` satrida bir xil turdagi harflarni guruhlab joylashtirishimiz kerak. Ya'ni, `s'` satri `[birinchi tur harflari][ikkinchi tur harflari]...[k-chi tur harflari]` ko'rinishida bo'ladi. Harf turlarining bu tartibi `(T_1, T_2, ..., T_k)` bizning permutatsiyamizni aniqlaydi. Agar `s` satrida `T_B` turidagi harf `T_A` turidagi harfdan oldin kelgan bo'lsa, va `s'` satrida `T_A` turidagi harf `T_B` turidagi harfdan oldin kelgan bo'lsa, bu holat inversiya hisoblanadi. Shuning uchun, biz `T_A` `T_B` dan oldin keladigan va `s` da `T_B` `T_A` dan oldin kelgan juftliklar sonini hisoblashimiz kerak.

Biz `pairwise_inversions[char_type_X][char_type_Y]` massivida `s` satrida `char_type_X` turidagi harflar `char_type_Y` turidagi harflardan necha marta oldin kelganini saqlaymiz. Keyin, `k` ning kichikligi sababli, barcha `k` harf turlarini qanday tartibda joylashtirish kerakligini aniqlash uchun bitmaskali DDdan foydalanamiz. `dp[mask][last_char_type]` holati `mask` bitmaskasi bilan ifodalangan harf turlari to'plamining barcha permutatsiyalari orasida, `last_char_type` (oxirgi joylashtirilgan harf turi) bilan tugaydigan eng ko'p inversiya sonini saqlaydi.

## Algoritm qadamlari

1.  **Kiritishni optimallashtirish**: `std::ios_base::sync_with_stdio(false); std::cin.tie(0);` buyruqlari C++ standart oqimlarining ishlashini tezlashtiradi.
2.  **Global massivlarni e'lon qilish va boshlang'ich holatga keltirish**:
    *   `pairwise_inversions[k][k]`: `s` satrida `i`-chi turdagi harf `j`-chi turdagi harfdan necha marta oldin kelganini hisobga oladi. `long long` turida bo'ladi, chunki inversiyalar soni `N*N` darajasiga yetishi mumkin.
    *   `count_seen[k]`: Hozirga qadar har bir harf turidan nechta uchraganini saqlaydi.
    *   `dp[(1 << k)][k]`: Dinamik dasturlash jadvali. `dp[mask][last_char_type]` `mask` bilan ifodalangan harf turlari to'plami uchun, `last_char_type` bilan tugaydigan eng ko'p inversiya sonini saqlaydi.
    *   Barcha massivlar `memset` yordamida `0` yoki `-1` ga (DD uchun erishib bo'lmaydigan holatlarni bildirish uchun) boshlang'ich holatga keltiriladi.
3.  **Oldindan hisoblash (`pairwise_inversions`)**:
    *   `s` satrining har bir belgisi bo'yicha `char_idx` orqali yurib chiqiladi.
    *   Joriy belgi `current_char_type` ga o'tkaziladi (masalan, 'a' -> 0, 'b' -> 1).
    *   `current_char_type` dan oldin kelgan har bir `prev_char_type` uchun `pairwise_inversions[prev_char_type][current_char_type]` qiymatiga `count_seen[prev_char_type]` qo'shiladi. Bu shuni anglatadiki, `char_idx` gacha bo'lgan `prev_char_type` ning barcha uchragan joylari `current_char_type` dan oldin kelgan va shuning uchun juftlik hosil qilgan.
    *   `current_char_type` uchun `count_seen[current_char_type]` qiymati bittaga oshiriladi.
4.  **Dinamik dasturlash (DD) baza holatlari**:
    *   Har bir harf turi o'z-o'zidan bitta permutatsiya bo'lishi mumkin. Bunday hollarda inversiya yo'q. Shuning uchun, `dp[1 << i][i] = 0` qilib o'rnatiladi, bu yerda `1 << i` `i`-chi bit o'rnatilgan maskadir (faqat `i`-chi harf turi mavjud).
5.  **DD o'tishlari**:
    *   `mask` bitmaskalari bo'yicha `1` dan `(1 << k) - 1` gacha iteratsiya qilinadi.
    *   Har bir `mask` uchun, `mask` ga kiruvchi barcha `last_char_type` bo'yicha iteratsiya qilinadi. Agar `dp[mask][last_char_type]` holati erishib bo'lmaydigan (`-1`) bo'lsa, o'tkazib yuboriladi.
    *   `mask` ga hali kiritilmagan barcha `next_char_type` bo'yicha iteratsiya qilinadi.
    *   `current_cost_for_next_block` hisoblanadi: bu yangi `next_char_type` blokini `mask` dagi barcha harf bloklaridan keyin joylashtirishdan kelib chiqadigan qo'shimcha inversiyalar sonidir. U `mask` dagi har bir `prev_char_in_mask` uchun `pairwise_inversions[next_char_type][prev_char_in_mask]` yig'indisi sifatida hisoblanadi.
    *   Yangi `new_mask = mask | (1 << next_char_type)` ni hosil qilib, `dp[new_mask][next_char_type]` holati `std::max` yordamida yangilanadi: `dp[mask][last_char_type] + current_cost_for_next_block`.
6.  **Maksimal natijani topish**:
    *   Barcha `mask` lar hisoblab bo'lingach, eng oxirgi to'liq `mask = (1 << k) - 1` (barcha harf turlarini o'z ichiga olgan) uchun barcha `last_char_type` lar orasida `dp` qiymatlarining maksimumi topiladi. Bu bizning yakuniy javobimizdir.
7.  **Natijani chiqarish**.

## Murakkablik tahlili

-   **Vaqt**: `O(N * k + 2^k * k^3)`
    *   `pairwise_inversions` massivini oldindan hisoblash `N` (satr uzunligi) va `k` (harf turlari soni) ga bog'liq bo'lib, `O(N * k)` vaqt talab qiladi. (`10^5 * 10 = 10^6` operatsiya)
    *   Dinamik dasturlash qismi: `2^k` maskalar, har bir maskada `k` ta `last_char_type`, har bir `next_char_type` uchun yana `k` ta iteratsiya va `current_cost_for_next_block` ni hisoblash uchun yana `k` ta iteratsiya, shuning uchun `O(2^k * k^3)` vaqt talab qiladi. (`2^10 * 10^3 = 1024 * 1000 ~= 10^6` operatsiya)
    *   Jami vaqt murakkabligi `10^6 + 10^6 = 2 * 10^6` atrofida bo'lib, `1000 ms` vaqt chegarasiga osongina sig'adi.

-   **Xotira**: `O(k^2 + 2^k * k + N)`
    *   `pairwise_inversions`: `k * k` `long long` turidagi elementlar (`10 * 10 * 8` bayt).
    *   `count_seen`: `k` `int` turidagi elementlar (`10 * 4` bayt).
    *   `dp`: `(1 << k) * k` `long long` turidagi elementlar (`2^10 * 10 * 8` bayt = `1024 * 10 * 8 = 81920` bayt ~ `80 KB`).
    *   `s` satri: `N` belgilar (`10^5` bayt ~ `100 KB`).
    *   Jami xotira `N` va `2^k * k` ga bog'liq bo'ladi. (`100 KB + 80 KB = 180 KB` atrofida).
    *   `32 MB` (32768 KB) xotira chegarasiga bemalol sig'adi.

## Kod izohi

1.  **Kutubxonalar va optimallashtirish**:
    ```cpp
    #include <iostream> // Kirish/chiqish uchun
    #include <vector>   // Dinamik massivlar, ammo bu yerda ishlatilmagan
    #include <string>   // Satrlar bilan ishlash uchun
    #include <algorithm>// std::max uchun
    #include <numeric>  // std::iota, std::accumulate kabi funksiyalar (bu yerda ishlatilmagan)
    #include <cstring>  // memset uchun

    // Global massivlar (kichik k uchun tezlikni oshiradi)
    long long pairwise_inversions[10][10]; // pairwise_inversions[X][Y] - X Y dan necha marta oldin kelgan
    int count_seen[10];                     // Har bir harf turi necha marta uchragan
    long long dp[1 << 10][10];              // dp[mask][last_char_type]

    int main() {
        std::ios_base::sync_with_stdio(false); // C++ oqimlarini C oqimlari bilan sinxronizatsiyani o'chirish
        std::cin.tie(0);                        // cin va cout ni bog'liqligini uzish
    ```
    Bu qism kirish/chiqish operatsiyalarini tezlashtirish va kerakli kutubxonalarni qo'shish uchun xizmat qiladi. Global massivlar kichik `k` qiymatlari uchun xotira ustidan to'g'ridan-to'g'ri nazoratni ta'minlaydi va `memset` bilan tezroq initsializatsiyaga imkon beradi.

2.  **Kiritma va boshlang'ich sozlashlar**:
    ```cpp
        int k; 
        std::cin >> k;
        std::string s;
        std::cin >> s;

        int n = s.length(); 

        memset(pairwise_inversions, 0, sizeof(pairwise_inversions)); // 0 ga to'ldirish
        memset(count_seen, 0, sizeof(count_seen));                   // 0 ga to'ldirish
    ```
    `k` (harf turlari soni) va `s` (kiritma satri) o'qiladi. Satr uzunligi `n` olinadi. `pairwise_inversions` va `count_seen` massivlari `0` qiymatlar bilan to'ldiriladi.

3.  **`pairwise_inversions`ni hisoblash (Oldindan hisoblash)**:
    ```cpp
        for (int char_idx = 0; char_idx < n; ++char_idx) {
            int current_char_type = s[char_idx] - 'a'; 

            for (int prev_char_type = 0; prev_char_type < k; ++prev_char_type) {
                if (prev_char_type == current_char_type) {
                    continue; // Bir xil harf turlarini sanamaymiz
                }
                pairwise_inversions[prev_char_type][current_char_type] += count_seen[prev_char_type];
            }
            count_seen[current_char_type]++; // Joriy harf turining sonini oshirish
        }
    ```
    Bu sikl `s` satrining har bir belgisini birma-bir ko'rib chiqadi. Joriy belgi (masalan, `s[char_idx] = 'c'` bo'lsa, `current_char_type = 2`) dan oldin kelgan har bir boshqa harf turi (`prev_char_type`) uchun `pairwise_inversions[prev_char_type][current_char_type]` ni yangilaydi. Masalan, agar `s = "bca"` bo'lsa:
    - `s[0] = 'b'`: `count_seen['b']` = 1.
    - `s[1] = 'c'`: `pairwise_inversions['b']['c']` += `count_seen['b']` (ya'ni 1). `count_seen['c']` = 1.
    - `s[2] = 'a'`: `pairwise_inversions['b']['a']` += `count_seen['b']` (ya'ni 1). `pairwise_inversions['c']['a']` += `count_seen['c']` (ya'ni 1). `count_seen['a']` = 1.
    Natijada, `pairwise_inversions[X][Y]` satr `s` da `X` harfining `Y` harfidan oldin kelgan juftliklari sonini saqlaydi.

4.  **Dinamik dasturlashni boshlang'ich holatga keltirish va baza holatlari**:
    ```cpp
        memset(dp, -1, sizeof(dp)); // DD jadvalini -1 bilan to'ldirish (erishilmagan holat)

        for (int i = 0; i < k; ++i) {
            dp[1 << i][i] = 0; // Har bir harf turi yakka o'zi 0 inversiya beradi
        }
    ```
    `dp` jadvali `-1` bilan to'ldiriladi, bu holatga hali erishilmaganligini bildiradi. Har bir harf turi (`i`) uchun, faqat shu harf turini o'z ichiga olgan permutatsiya (`mask = 1 << i`) uchun inversiyalar soni `0` deb belgilanadi.

5.  **DD o'tishlari (asosiy hisoblash)**:
    ```cpp
        long long max_total_inversions = 0; 

        for (int mask = 1; mask < (1 << k); ++mask) {
            for (int last_char_type = 0; last_char_type < k; ++last_char_type) {
                if (!((mask >> last_char_type) & 1) || dp[mask][last_char_type] == -1) {
                    continue; // Agar last_char_type maskada bo'lmasa yoki holatga erishilmagan bo'lsa
                }

                for (int next_char_type = 0; next_char_type < k; ++next_char_type) {
                    if (!((mask >> next_char_type) & 1)) { // Agar next_char_type maskada bo'lmasa
                        long long current_cost_for_next_block = 0;

                        for (int prev_char_in_mask = 0; prev_char_in_mask < k; ++prev_char_in_mask) {
                            if (((mask >> prev_char_in_mask) & 1)) { // Agar prev_char_in_mask maskada bo'lsa
                                current_cost_for_next_block += pairwise_inversions[next_char_type][prev_char_in_mask];
                            }
                        }

                        int new_mask = mask | (1 << next_char_type); 
                        dp[new_mask][next_char_type] = std::max(dp[new_mask][next_char_type],
                                                                 dp[mask][last_char_type] + current_cost_for_next_block);
                    }
                }
            }
        }
    ```
    Bu qism barcha mumkin bo'lgan harf turlari permutatsiyalarini quradi va har bir qadamda maksimal inversiyalar sonini hisoblaydi. `dp[mask][last_char_type]` holatidan `dp[new_mask][next_char_type]` holatiga o'tishda, `next_char_type` turidagi barcha harflar `mask` dagi barcha harf turlaridan keyin joylashtiriladi. Yangi inversiyalar soni `next_char_type` va `mask` dagi har bir `prev_char_in_mask` orasidagi `pairwise_inversions[next_char_type][prev_char_in_mask]` yig'indisi sifatida hisoblanadi. Chunki `next_char_type` bloklari `prev_char_in_mask` bloklaridan keyin joylashtiriladi, lekin asl satrda `next_char_type` ba'zan `prev_char_in_mask` dan oldin kelgan bo'lishi mumkin - bu holat inversiyani beradi.

6.  **Yakuniy natijani topish va chiqarish**:
    ```cpp
        for (int i = 0; i < k; ++i) {
            max_total_inversions = std::max(max_total_inversions, dp[(1 << k) - 1][i]);
        }

        std::cout << max_total_inversions << std::endl;
    ```
    Barcha `k` harf turlarini o'z ichiga olgan `mask` (`(1 << k) - 1`) uchun barcha `last_char_type` lar bo'yicha `dp` qiymatlari orasidan eng kattasi topiladi va natija sifatida chop etiladi.

## Edge case lar va eslatmalar
*   **`k` kichikligi**: `k` ning kichik (maksimal 10) bo'lishi bitmaskali Dinamik Dasturlashni samarali qiladi. Agar `k` katta bo'lganda, boshqa yondashuvlar (masalan, flow algoritm) kerak bo'lishi mumkin edi.
*   **Inversiya hisoblash**: `d(x, y)` ning inversiyalar soniga tengligi algoritming asosiy qismidir. Qo'shni elementlarni almashtirish orqali satrni permutatsiyaga aylantirish uchun zarur bo'lgan minimal operatsiyalar soni aynan inversiyalar soniga teng.
*   **Ma'lumot turlari**: `pairwise_inversions` va `dp` jadvalidagi qiymatlar `long long` bo'lishi muhim, chunki inversiyalar soni `N * N / 2` gacha yetishi mumkin, bu `(10^5)^2 / 2 = 5 * 10^9` ga teng bo'lishi mumkin, `int` diapazonidan tashqarida.
*   **`memset`dan foydalanish**: `memset` tezkor initsializatsiya uchun qulay, lekin u faqat baytlarda bir xil qiymat (masalan, `0` yoki `-1` uchun barcha bitlari `1`) bilan to'ldirishda ishlaydi. Boshqa qiymatlar uchun `std::fill` yoki sikldan foydalanish kerak bo'ladi. Bu holatda `0` va `-1` (barcha bitlari 1, ya'ni `0xFFFFFFFF` to'ldiriladi) uchun to'g'ri ishlaydi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M076A) platformasidagi **M076A** raqamli **Анаграмматический Хаос** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M076A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M076A, Анаграмматический Хаос yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
