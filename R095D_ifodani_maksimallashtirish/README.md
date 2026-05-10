---
title: "R095D — Ifodani maksimallashtirish | Robocontest.uz Yechimi"
description: "Robocontest.uz R095D (Ifodani maksimallashtirish) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 512 MB."
keywords: "robocontest R095D, Ifodani maksimallashtirish yechimi, robocontest Ifodani maksimallashtirish, R095D c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /R095D_ifodani_maksimallashtirish/
lang: uz
---

# R095D — Ifodani maksimallashtirish

## Masala haqida
Sizga `n` ta butun sondan iborat `a` massivi beriladi. Siz massiv ustida ko'pi bilan bitta amal bajarishingiz mumkin: `i` va `j` indekslarini tanlab, `a[i]` qiymatini `a[j]` ga o'zgartirish (`a[i] = a[j]`). Bu amalning maqsadi — 1 dan `n` gacha bo'lgan `k` butun sonini tanlab, `(a_1 & a_2 & ... & a_k) + (a_{k+1} & a_{k+2} & ... & a_n)` ifodaning qiymatini maksimallashtirish. Bu yerda `&` belgisi bitwise AND (bitli VA) operatorini anglatadi.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi – massivdagi har qanday diapazon uchun bitwise AND amalini samarali hisoblash va bitta elementni o'zgartirish imkoniyatini hisobga olgan holda maksimal yig'indini topish. Diapazonli bitwise AND so'rovlari uchun **Sparse Table (siyrak jadval)** ma'lumotlar tuzilmasidan foydalanish eng optimal yechimlardan biridir.

Bitwise AND operatorining muhim xususiyatlari:
1.  **Monotonlik**: Diapazon kengaygani sari AND qiymati hech qachon oshmaydi (kamayishi yoki bir xil qolishi mumkin). Misol uchun, `(X & Y & Z) <= (X & Y)`.
2.  **Idempotentlik**: Bir xil qiymatni bir necha marta ANDlash natijani o'zgartirmaydi: `X & X = X`. Shuning uchun Sparse Table kabi tuzilmalarda ustma-ust tushadigan diapazonlar bilan ishlash mumkin.
3.  **Bitlar o'chishi**: `X & Y` amali faqat `X` va `Y` da ham 1 bo'lgan bitlarni saqlaydi. Bu shuni anglatadiki, bir diapazondagi bitwise AND qiymati, diapazon kattalashgani sari, maksimal `log(MAX_VAL)` marta o'zgarishi mumkin (chunki har bir o'zgarishda kamida bitta bit 0 ga aylanadi). Bu `MAX_VAL` 10^9 bo'lsa, taxminan 30 ta bitga to'g'ri keladi. Bu xususiyat potentsial `i` va `k` indekslari sonini sezilarli darajada kamaytirishga yordam beradi.

Yechim ikki asosiy holatni ko'rib chiqadi:
1.  **Hech qanday o'zgartirish kiritilmagan holat**: Bu oddiygina `k` ni 0 dan `n` gacha iteratsiya qilib, har bir bo'linish nuqtasi uchun ifoda qiymatini hisoblash.
2.  **Bitta `a[i] = a[j]` o'zgartirish kiritilgan holat**: Bu murakkabroq qism. `i` ni (`a[i]` o'zgartiriladigan indeks) va `k` ni (bo'linish nuqtasi) samarali tanlash kerak. `j` (`a[j]` yangi qiymat) uchun massivdagi barcha noyob qiymatlarni sinab ko'rish yetarli. `i` va `k` uchun esa yuqorida aytib o'tilgan bitlar o'chishi xususiyatiga asoslangan holda, faqat muhim (relevant) indekslarni tanlash mumkin.

## Algoritm qadamlari

1.  **Sparse Table (Siyrak jadval) qurish**:
    *   Massivdagi har qanday `[l, r]` diapazon uchun bitwise AND qiymatini `O(1)` vaqtda olish uchun Sparse Table quriladi.
    *   `log_table` (logarifm jadvali) oldindan hisoblab chiqiladi. `log_table[x]` qiymati `floor(log2(x))` ni beradi. Bu diapazon uzunligiga mos keladigan Sparse Table ustunini topish uchun ishlatiladi.
    *   `st[i][j]` Sparse Table jadvali `i` indeksidan boshlanuvchi va `2^j` uzunlikdagi diapazonning bitwise AND qiymatini saqlaydi. Jadval ikki for sikli yordamida `O(N * log N)` vaqtda to'ldiriladi.

2.  **Sparse Table so'rovlari (Query Sparse Table)**:
    *   `query_sparse_table(l, r)` funksiyasi `[l, r]` (0-indeksli) diapazonidagi elementlarning bitwise AND qiymatini `O(1)` vaqtda qaytaradi.
    *   Agar diapazon bo'sh bo'lsa (`l > r`), u holda bitwise AND amali uchun neytral element bo'lgan `~0u` (barcha bitlar 1 ga teng bo'lgan `unsigned int`) qaytariladi.
    *   `get_actual_segment_and_value_for_sum(l, r, total_n)` yordamchi funksiyasi esa yig'indiga qo'shish uchun segment qiymatini qaytaradi. Agar segment mantiqan bo'sh bo'lsa (masalan, `l >= total_n` yoki `l > r`), u holda 0 qiymatini qaytaradi, chunki bo'sh segment yig'indiga 0 hissa qo'shadi.

3.  **Asl prefix/suffix AND qiymatlarini hisoblash**:
    *   `p_orig_for_sum[k_split]` massivi `a[0] & ... & a[k_split-1]` qiymatlarini saqlaydi. `p_orig_for_sum[0]` bo'sh prefix uchun 0 ga teng.
    *   `s_orig_for_sum[k_split]` massivi `a[k_split] & ... & a[n-1]` qiymatlarini saqlaydi. `s_orig_for_sum[n]` bo'sh suffix uchun 0 ga teng.
    *   Bu massivlar `O(N)` vaqtda Sparse Table so'rovlari yordamida to'ldiriladi.

4.  **Birinchi holat: O'zgartirishsiz maksimallashtirish**:
    *   `max_val` o'zgaruvchisi hozirgacha topilgan maksimal qiymatni saqlaydi.
    *   `k_split` ni `0` dan `n` gacha iteratsiya qilib, har bir bo'linish nuqtasi uchun `p_orig_for_sum[k_split] + s_orig_for_sum[k_split]` ni hisoblaymiz va `max_val` ni yangilaymiz.

5.  **Ikkinchi holat: Bitta `a[i] = a[j]` o'zgartirish bilan maksimallashtirish**:
    *   **Relevant `i_idx` kandidatlarini aniqlash**: Massivni chapdan o'ngga va o'ngdan chapga bir marta o'tib, `query_sparse_table(0, i)` va `query_sparse_table(i, n-1)` ning qiymati o'zgaradigan barcha `i` indekslarini `std::set` ga yig'amiz. Bu indekslar soni `O(log(MAX_VAL))` dan oshmaydi.
    *   **Relevant `k_split` kandidatlarini aniqlash**: Xuddi shu mantiq bilan, `p_orig_for_sum[k]` va `s_orig_for_sum[k]` ning qiymati o'zgaradigan barcha `k` bo'linish nuqtalarini `std::set` ga yig'amiz. Bu ham `O(log(MAX_VAL))` sonli nuqtalar bo'ladi.
    *   **Noyob `a` qiymatlarini yig'ish**: `std::set` dan foydalanib, massivdagi barcha noyob qiymatlarni (`a[j]` ning mumkin bo'lgan qiymatlari) to'playmiz. Bu `O(N)` gacha noyob qiymatlarni berishi mumkin.
    *   **Asosiy sikllar**: Uchta ichki sikl yordamida barcha relevant `i_idx` lar, relevant `k_split` lar va noyob `a` qiymatlari (`val_to_insert`) bo'yicha iteratsiya qilinadi:
        *   Har bir `i_idx` uchun: `a[i_idx]` o'zgartiriladi.
        *   Har bir `k_split` uchun: massiv ikki qismga bo'linadi.
        *   Har bir `val_to_insert` uchun: `a[j]` dan olingan yangi qiymat.
        *   Agar `a[i_idx]` birinchi qismda joylashgan bo'lsa (`i_idx < k_split`):
            *   Birinchi qismning yangi AND qiymati: `(AND(a[0]...a[i_idx-1])) & val_to_insert & (AND(a[i_idx+1]...a[k_split-1]))`. Bu yerda `mask_for_inserted_val` `(AND(a[0]...a[i_idx-1])) & (AND(a[i_idx+1]...a[k_split-1]))` ga teng bo'ladi.
            *   Ikkinchi qism (`a[k_split]...a[n-1]`) asl holicha qoladi va uning AND qiymati `s_orig_for_sum[k_split]` dan olinadi.
        *   Agar `a[i_idx]` ikkinchi qismda joylashgan bo'lsa (`i_idx >= k_split`):
            *   Ikkinchi qismning yangi AND qiymati: `(AND(a[k_split]...a[i_idx-1])) & val_to_insert & (AND(a[i_idx+1]...a[n-1]))`. Bu yerda `mask_for_inserted_val` `(AND(a[k_split]...a[i_idx-1])) & (AND(a[i_idx+1]...a[n-1]))` ga teng bo'ladi.
            *   Birinchi qism (`a[0]...a[k_split-1]`) asl holicha qoladi va uning AND qiymati `p_orig_for_sum[k_split]` dan olinadi.
        *   `val_to_insert` uchun `(mask_for_inserted_val & val_to_insert)` ning maksimal qiymatini topamiz.
        *   `max_val` ni yangilaymiz: `max_val = max(max_val, other_part_and_val + max_and_with_val_to_insert)`.

6.  **Natijani chiqarish**: Eng yuqori `max_val` ni chop etish.

## Murakkablik tahlili

*   **Vaqt murakkabligi**: `O(N * log N + (log MAX_VAL)^2 * N)`
    *   Sparse Table qurish: `O(N * LOGN_MAX)`, bu `O(N log N)` ga teng, chunki `LOGN_MAX` ~ `log N`.
    *   `log_table` qurish: `O(N)`.
    *   Prefix/suffix AND massivlarini hisoblash: `O(N)` (har bir `query_sparse_table` `O(1)`).
    *   Birinchi holatni tekshirish: `O(N)`.
    *   Relevant `i_idx` va `k_split` indekslarini topish: `O(N)` vaqt oladi, chunki `N` ta element bo'yicha bir marta iteratsiya qilinadi va `set`ga `O(log MAX_VAL)` element qo'shiladi. Relevant indekslar soni `O(log MAX_VAL)` (taxminan 30) bo'ladi.
    *   Noyob `a` qiymatlarini to'plash: `std::set` yordamida `O(N log N)` yoki `std::sort` va `std::unique` bilan `O(N log N)`.
    *   Asosiy uchta sikl: `(relevant_i_indices.size()) * (relevant_k_splits.size()) * (unique_a_values.size())`.
        *   `relevant_i_indices.size()`: `O(log MAX_VAL)`.
        *   `relevant_k_splits.size()`: `O(log MAX_VAL)`.
        *   `unique_a_values.size()`: `O(N)` (eng yomon holatda, barcha elementlar noyob bo'lsa).
        *   Har bir iteratsiya ichida Sparse Table so'rovi `O(1)`.
        *   Demak, bu qismning murakkabligi `O((log MAX_VAL)^2 * N)`.
    *   Misol uchun `N = 10^5`, `log N ~ 17`, `log MAX_VAL ~ 30`. Umumiy murakkablik taxminan `10^5 * 17 + 30 * 30 * 10^5 = 1.7 * 10^6 + 9 * 10^7` operatsiyalarni tashkil etadi, bu `10^8` operatsiyadan kam va 1 soniya vaqt chegarasiga sig'adi.

*   **Xotira murakkabligi**: `O(N * log N)`
    *   `a` massivi: `O(N)`.
    *   Sparse Table `st`: `O(N * LOGN_MAX)`, bu `O(N log N)` ga teng.
    *   `log_table`, `p_orig_for_sum`, `s_orig_for_sum`: `O(N)`.
    *   `set`lar va `vector`lar (kandidatlar uchun): `O(log MAX_VAL)` va `O(N)` (`unique_a_values` uchun).
    *   `N = 10^5`, `LOGN_MAX = 17` uchun Sparse Table taxminan `10^5 * 17 * 4` bayt = `6.8` MB joy egallaydi. Boshqa massivlar bilan birga umumiy xotira `512` MB chegarasiga sig'adi.

## Kod izohi

*   **`LOGN_MAX` va `log_table`**: `N=10^5` bo'lganda `log2(10^5)` taxminan 16.6 ni tashkil qiladi, shuning uchun `LOGN_MAX = 17` etarli. `log_table` esa oldindan `log2` qiymatlarini hisoblab, Sparse Table so'rovlarini tezlashtirish uchun ishlatiladi.
*   **`build_sparse_table(const std::vector<int>& a)`**: Bu funksiya berilgan `a` massivi uchun Sparse Table ni quradi. `st[i][0]` bitta elementning o'zini (uzunligi 2^0 = 1 bo'lgan diapazon) saqlaydi. Keyingi `j` qadamlarida esa `2^j` uzunlikdagi diapazonni ikki `2^(j-1)` uzunlikdagi diapazonga bo'lib, ularning bitwise AND natijasini oladi.
*   **`query_sparse_table(int l, int r)`**: Bu funksiya `[l, r]` diapazoni uchun bitwise AND ni qaytaradi. `j = log_table[r - l + 1]` yordamida diapazonni ikkita kesishgan `2^j` uzunlikdagi qismga bo'ladi va ularning bitwise AND natijasini beradi. Bo'sh diapazonlar uchun `~0u` (barcha bitlar 1 ga teng `unsigned int`) qaytaradi, chunki bu bitwise AND amali uchun neytral element.
*   **`get_actual_segment_and_value_for_sum(int l, int r, int total_n)`**: Bu yordamchi funksiya hisoblashlarda segment bo'sh bo'lsa (masalan, prefix yoki suffix bo'sh bo'lsa), uning hissasini 0 deb qaytaradi. Bu `p_orig_for_sum` va `s_orig_for_sum` ni to'g'ri to'ldirishda va maxsus holatlarda (masalan, `k_split = 0` yoki `k_split = n` da) foydali.
*   **`main()` funksiyasi**:
    *   Kiritish/chiqarish operatsiyalarini tezlashtirish uchun `std::ios_base::sync_with_stdio(false); std::cin.tie(0);` ishlatilgan.
    *   Massiv o'qilgach, Sparse Table quriladi.
    *   `p_orig_for_sum` va `s_orig_for_sum` massivlari boshlang'ich prefix va suffix AND qiymatlarini saqlaydi.
    *   Birinchi holatda (`a[i]=a[j]` amal bajarilmaganida) maksimal qiymat hisoblanadi.
    *   Ikkinchi holatni samarali hal qilish uchun `i_idx_candidate_set` va `k_split_candidate_set` larni `std::set` yordamida to'ldiriladi. Bu setlarga faqatgina prefix/suffix AND qiymati o'zgaradigan muhim indekslar qo'shiladi. Bu indekslar soni `O(log MAX_VAL)` tartibida bo'ladi.
    *   `distinct_a_values_set` massivdagi barcha noyob qiymatlarni saqlaydi, chunki `a[j]` ning qiymati shu noyob qiymatlardan biri bo'lishi mumkin.
    *   Uchta ichki sikl `relevant_i_indices`, `relevant_k_splits` va `unique_a_values` bo'yicha iteratsiya qilib, `mask_for_inserted_val` ni hisoblaydi. Bu maska `a[i_idx]` ni o'zgartirishdan oldin segmentning qolgan qismidagi bitwise AND ni ifodalaydi. Keyin `val_to_insert` bilan ANDlab, maksimal natija olinadi.
    *   Oxirida `max_val` chop etiladi.

## Edge case lar va eslatmalar

*   **Bo'sh diapazonlar**: `query_sparse_table` funksiyasi `l > r` bo'lganda `~0u` qaytarishi, bitwise AND amali uchun neytral elementni ifodalaydi. Ammo yig'indi hisob-kitoblarida bo'sh segmentning hissasi 0 bo'lishi kerak, shuning uchun `get_actual_segment_and_value_for_sum` funksiyasi bu holatni boshqaradi.
*   **`a_i = 0` holati**: Agar massivda 0 qiymat mavjud bo'lsa, u bitwise AND natijasini tezda 0 ga aylantirishi mumkin (`X & 0 = 0`). Bu holatlar algoritmda to'g'ri hisobga olingan.
*   **Minimal `n` qiymati**: `n=2` bo'lgan holatda ham (masalan, `a[0] & a[1]` yoki `a[0] + (a[1])`) algoritm to'g'ri ishlaydi, chunki Sparse Table va prefix/suffix hisob-kitoblari kichik massivlar uchun ham mo'ljallangan.
*   **`long long` dan foydalanish**: Masala matnida `a_i <= 10^9` berilgan. Ikki `int` qiymatining yig'indisi (`10^9 + 10^9 = 2 * 10^9`) `int` tipiga sig'adi (odatda `INT_MAX` ~ `2.1 * 10^9`). Shunday bo'lsa ham, `long long` dan foydalanish xatolikka yo'l qo'ymaslik uchun xavfsizroq yondashuv hisoblanadi.
*   **Kandidat indekslar soni**: `O(log MAX_VAL)` ga teng bo'lgan `relevant_i_indices` va `relevant_k_splits` soni, `std::set` larga kiritilgan vaqtlar hisobga olinganda ham, umumiy vaqt murakkabligiga katta ta'sir qilmaydi.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/R095D) platformasidagi **R095D** raqamli **Ifodani maksimallashtirish** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/R095D>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest R095D, Ifodani maksimallashtirish yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
