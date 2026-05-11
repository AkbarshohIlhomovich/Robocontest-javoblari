---
title: "M075E — 3 ta har xil belgi | Robocontest.uz Yechimi"
description: "Robocontest.uz M075E (3 ta har xil belgi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M075E, 3 ta har xil belgi yechimi, robocontest 3 ta har xil belgi, M075E c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M075E_3_ta_har_xil_belgi/
lang: uz
---

```markdown
# M075E — 3 ta har xil belgi

## Masala haqida
Ravshanjonda boshlangʻich uzunligi 9 ga teng boʻlgan noyob satr mavjud. Bu satr uch xil harfdan iborat boʻlib, har bir harf satrda aynan 3 martadan qatnashadi. Ravshanjon satrdagi barcha belgilarni oʻchirib tashlashni xohlaydi. U bitta oʻchirishda, ketma-ket joylashgan bir xil belgilardan tashkil topgan blokni oʻchira oladi. Agar u bir urinishda aynan 3 ta bir xil harfdan iborat blokni oʻchira olsa, uning xursandligi 1 ga ortadi. Masalaning maqsadi — Ravshanjon erishishi mumkin boʻlgan maksimal xursandlikni topish.

## Yondashuv (g'oya)
Bu masala dinamik dasturlash (Dynamic Programming, DP) yordamida yechiladi, aniqrogʻi, memoizatsiya (natijalarni xotirada saqlash) bilan rekursiv yondashuv qoʻllaniladi. Asosiy gʻoya shundan iboratki, berilgan satr holatidan boshlab, mumkin boʻlgan barcha oʻchirish variantlarini sinab koʻrish va har bir oʻchirishdan keyin qolgan satr uchun maksimal baxtni rekursiv ravishda hisoblash. Har bir satr holati uchun hisoblangan natijalar `unordered_map` yordamida saqlanadi, bu takroriy hisoblashlarning oldini oladi. Yechimning samaradorligini oshirish uchun satrdagi harflar standart 'a', 'b', 'c' belgilarga almashtirilib, holatlar soni kamaytiriladi.

## Algoritm qadamlari
1.  **Karakterlarni almashtirish (kanonizatsiya)**: Har bir test holati uchun, kiruvchi satrdagi uch xil belgi ('h', 'l', 'k' yoki 's', 'r', 't' kabi) 'a', 'b', 'c' kabi standart belgilarga almashtiriladi. Bu `memo` xaritasida kalitlar (satr holatlari) sonini sezilarli darajada kamaytiradi va hisob-kitoblarni tezlashtiradi. Misol uchun, "hhhlllkkk" satri "aaabbbccc" ga aylanadi.
2.  **Memoizatsiya xaritasini tozalash**: Har bir yangi test holati boshlanishidan oldin, `memo` deb nomlangan `unordered_map` tozalab turiladi, chunki oldingi test holatining natijalari hozirgi testga taalluqli emas.
3.  **`solve(string s)` funksiyasi**: Bu funksiya berilgan `s` satri uchun erishish mumkin boʻlgan maksimal baxtni hisoblaydi.
    *   **Bazaviy holat**: Agar `s` satri boʻsh boʻlsa (`s.empty()`), hech qanday belgi qolmagan boʻladi, shuning uchun baxt 0 ga teng.
    *   **Memoizatsiya tekshiruvi**: Agar `s` satri uchun natija `memo` xaritasida mavjud boʻlsa, u toʻgʻridan-toʻgʻri qaytariladi.
    *   **Maksimumni topish**: `max_happiness_for_this_state` oʻzgaruvchisi joriy holat uchun maksimal baxtni saqlab boradi va dastlab 0 ga tenglashtiriladi.
    *   **Iteratsiya va bloklarni topish**: Satrning boshidan oxirigacha ( `i` indeksi orqali) harakatlanib, ketma-ket kelgan bir xil belgilar bloklari topiladi. `j` indeksi shu blokning oxirini bildiradi.
    *   **Blokni oʻchirish va yangi holat yaratish**:
        *   `block_len = j - i + 1` orqali topilgan blokning uzunligi aniqlanadi.
        *   Blokni olib tashlab, yangi `next_s` satri hosil qilinadi. Bu `s` satrining `0` dan `i-1` gacha boʻlgan qismi bilan `j+1` dan oxirigacha boʻlgan qismini birlashtirish orqali amalga oshiriladi.
        *   **Baxtni hisoblash**: Agar `block_len` aynan 3 ga teng boʻlsa, `current_happiness_gain` 1 ga teng boʻladi, aks holda 0 ga.
        *   **Rekursiv chaqiruv**: `max_happiness_for_this_state` oʻzgaruvchisi `current_happiness_gain + solve(next_s)` (yaʼni, joriy oʻchirishdan olingan baxt va qolgan satr uchun maksimal baxt yigʻindisi) va hozirgi `max_happiness_for_this_state` orasidagi maksimumni olib yangilanadi.
    *   **Natijani saqlash**: Hisoblangan `max_happiness_for_this_state` `memo` xaritasiga `s` satri kaliti bilan saqlanadi va qaytariladi.
4.  **Natijani chop etish**: Har bir test holati uchun `solve(s)` funksiyasi chaqiriladi va qaytarilgan natija alohida qatorda chop etiladi.

## Murakkablik tahlili
-   **Vaqt**: `O(S * N^2)`
    *   Bu yerda `S` – memoizatsiya xaritasida saqlanadigan noyob satr holatlari soni, `N` – maksimal satr uzunligi (9).
    *   Satr uzunligi `N=9` boʻlganligi sababli, `S` unchalik katta emas. Har bir belgi 3 martadan takrorlanishi va kanonizatsiya (faqat 'a', 'b', 'c' belgilari ishlatilishi) tufayli noyob satr holatlari soni juda cheklangan (taxminan bir necha ming).
    *   Har bir `solve` chaqiruvida:
        *   `N` ta belgi boʻylab iteratsiya qilinadi.
        *   Har bir iteratsiyada blok topiladi (`O(N)`).
        *   `next_s` satrini yaratish (`substr` va `+` operatsiyalari) `O(N)` vaqt oladi.
        *   `N` ta blok bo'lishi mumkinligi sababli, har bir `solve` chaqiruvining ichki hisoblashlari `O(N*N)` vaqt oladi.
    *   Shunday qilib, umumiy vaqt murakkabligi `S * N^2` ga teng. `N=9` va `S` bir necha ming atrofida boʻlgani uchun, bu juda tez ishlaydi (masalan, 5000 * 9^2 = 405,000 operatsiya), bu 1000 ms vaqt limitiga bemalol sigʻadi.

-   **Xotira**: `O(S * N)`
    *   `memo` xaritasi `S` ta noyob satr holatini saqlaydi. Har bir satr maksimal `N` ta belgidan iborat.
    *   Shunday qilib, xaritada saqlanadigan umumiy belgilar soni `S * N` ga teng.
    *   `S` taxminan bir necha ming, `N=9` boʻlsa, `5000 * 9 = 45000` belgiga yaqin maʼlumot saqlanadi, bu 32 MB xotira limitiga bemalol sigʻadi (45 KB atrofida).

## Kod izohi

-   `#include <bits/stdc++.h>`: C++ standart kutubxonasining koʻpgina bosh fayllarini oʻz ichiga oladigan qulay fayl.
-   `using namespace std;`: `std::` prefiksini yozmasdan standart nomlar fazosidagi elementlardan foydalanish imkonini beradi.
-   `unordered_map<string, int> memo;`: Bu xarita memoizatsiya uchun ishlatiladi. Kalit `string` (satr holati), qiymat esa shu satr holati uchun erishish mumkin boʻlgan maksimal baxtni bildiruvchi `int`.
-   `int solve(string s)` funksiyasi:
    -   `if (s.empty()) { return 0; }`: Agar satr boʻsh boʻlsa, baxt 0 ga teng. Bu rekursiyaning tugash holati (bazaviy holat).
    -   `if (memo.count(s)) { return memo[s]; }`: Agar joriy `s` satri uchun natija `memo`da allaqachon hisoblangan boʻlsa, uni qaytaradi.
    -   `int max_happiness_for_this_state = 0;`: Joriy `s` satri uchun maksimal baxtni saqlaydigan oʻzgaruvchi.
    -   `int n = s.length();`: Satr uzunligi.
    -   `int i = 0; while (i < n) { ... i = j + 1; }`: Bu tsikl satrdagi barcha mumkin boʻlgan ketma-ket bir xil belgilar bloklarini topish uchun ishlatiladi.
    -   `int j = i; while (j + 1 < n && s[j+1] == s[i]) { j++; }`: `i` indeksidan boshlab, `s[i]` bilan bir xil boʻlgan belgilar blokining oxirgi indeksini (`j`) topadi.
    -   `int block_len = j - i + 1;`: Topilgan blokning uzunligi.
    -   `string next_s = ""; if (i > 0) { next_s += s.substr(0, i); } if (j + 1 < n) { next_s += s.substr(j + 1); }`: Topilgan blokni (`s[i...j]`) `s` satridan olib tashlab, qolgan qismlarni birlashtirib, yangi `next_s` satrini hosil qiladi.
    -   `int current_happiness_gain = (block_len == 3) ? 1 : 0;`: Agar blokning uzunligi aynan 3 boʻlsa, 1 baxt beriladi, aks holda 0.
    -   `max_happiness_for_this_state = max(max_happiness_for_this_state, current_happiness_gain + solve(next_s));`: Bu yerda asosiy DP qadami amalga oshiriladi: joriy oʻchirishdan keladigan baxtga `next_s` satri uchun rekursiv ravishda hisoblangan maksimal baxtni qoʻshib, joriy holat uchun maksimal baxtni yangilaydi.
    -   `return memo[s] = max_happiness_for_this_state;`: Hisoblangan natijani `memo`ga saqlaydi va qaytaradi.
-   `void process_test_case()` funksiyasi:
    -   `string s; cin >> s;`: Kirish satrini oʻqiydi.
    -   `map<char, char> char_mapping; char next_char_alias = 'a';`: Bu kod qismi belgilarni kanonizatsiya qilish uchun ishlatiladi. `char_mapping` xaritasi har bir noyob kirish belgisini ('a', 'b', 'c' kabi) standart belgilarga moslashtiradi.
    -   `for (char c : s) { ... }`: Satrdagi har bir belgini kanonizatsiya xaritasidan foydalanib oʻzgartiradi.
    -   `memo.clear();`: Har bir test holati uchun `memo` xaritasini tozalaydi.
    -   `cout << solve(s) << '\n';`: Kanonizatsiya qilingan satrni `solve` funksiyasiga uzatadi va natijani yangi qatordan chop etadi.
-   `int main()` funksiyasi:
    -   `ios_base::sync_with_stdio(false); cin.tie(0);`: Tezroq kirish-chiqish operatsiyalari uchun standart C++ I/O ni sinxronizatsiyadan chiqaradi.
    -   `int T; cin >> T; while (T--) { process_test_case(); }`: Test holatlari sonini oʻqiydi va har bir test holati uchun `process_test_case()` funksiyasini chaqiradi.

## Edge case lar va eslatmalar

-   **Karakterlarni almashtirish (kanonizatsiya)**: Bu yechimdagi eng muhim optimizatsiyalardan biridir. Agar bu amal bajarilmaganida, "hhhlllkkk" va "aaabbbccc" kabi bir xil tuzilishga ega, ammo turli belgilardan iborat satrlar `memo` xaritasida ikkita alohida holat sifatida saqlanib, hisob-kitoblarni sekinlashtirgan boʻlar edi. Kanonizatsiya `memo` xaritasining hajmini va qidiruv vaqtini sezilarli darajada kamaytiradi.
-   **Satr uzunligi**: Boshlangʻich satr uzunligi doim 9 ga teng. Har bir oʻchirish operatsiyasidan soʻng satr uzunligi kamayib boradi va oxir-oqibat boʻsh satrga aylanadi. Bu rekursiv jarayonning cheksiz davom etmasligini taʼminlaydi.
-   **3 ta har xil belgi, har biri 3 martadan**: Bu shart faqat *boshlangʻich* satr uchun muhim. Keyinchalik, satrni qayta ishlash jarayonida (bloklar oʻchirilgandan soʻng) har bir belgining soni yoki satrdagi har xil belgilar soni oʻzgarishi mumkin. Kod faqat ketma-ket joylashgan bir xil belgilar bloklarini topish va ularni oʻchirishga eʼtibor qaratadi.
-   **`unordered_map`dan foydalanish**: `string` kalitlari bilan ishlashda `std::map` oʻrniga `std::unordered_map`dan foydalanish, odatda, hashlash mexanizmi tufayli tezroq ishlaydi. Kichik `N` va cheklangan holatlar sonida ikkalasi ham ishlasa-da, `unordered_map` biroz tezroq natija berishi mumkin.
```
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M075E) platformasidagi **M075E** raqamli **3 ta har xil belgi** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M075E>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M075E, 3 ta har xil belgi yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
