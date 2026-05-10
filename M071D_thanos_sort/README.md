---
title: "M071D — Thanos sort | Robocontest.uz Yechimi"
description: "Robocontest.uz M071D (Thanos sort) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1500 ms, xotira: 128 MB."
keywords: "robocontest M071D, Thanos sort yechimi, robocontest Thanos sort, M071D c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M071D_thanos_sort/
lang: uz
---

Mazkur hujjat Thanos sort masalasining C++ tilidagi yechimini chuqur tahlil qiladi va tushuntiradi.

# M071D — Thanos sort

## Masala haqida
Tanosning saralash algoritmi quyidagicha ishlaydi: agar massiv kamaymaslik tartibida saralangan bo'lsa, hech qanday ish qilinmaydi. Aks holda, massiv teng ikkiga bo'linadi va istalgan bir yarmi o'chiriladi. Bu jarayon massiv saralanmagunicha davom etadi. Sizga `N` uzunlikdagi `a` massivi va `Q` ta so'rov beriladi. Har bir so'rovda `l` va `r` indekslari oralig'idagi `a[l...r]` qismmassivni Tanos saralashi uchun cheksizlik toshlarini (ya'ni bo'lish va o'chirish operatsiyalarini) eng kamida necha marta ishlatish kerakligini topish talab qilinadi. Barcha so'rovlar uchun `r - l + 1` qismmassiv uzunligi 2 ning darajasi ekanligi kafolatlanadi.

## Yondashuv (g'oya)
Tanos saralashining maqsadi har doim minimal operatsiyalar bilan massivni saralashdir. Bu degani, u har safar massivni ikkiga bo'lganda, ikki yarimdan eng kattasini va *allaqachon saralangan* qismini saqlab qoladi. Shunday qilib, masalani hal qilish uchun biz `a[l...r]` qismmassividagi *eng uzun* (va albatta 2 ning darajasi bo'lgan) saralangan qismmassivning uzunligini topishimiz kerak. Agar boshlang'ich qismmassiv uzunligi `L_initial` bo'lsa va biz topgan eng uzun saralangan qismmassivning uzunligi `L_final_sorted` bo'lsa, u holda Tanos sort operatsiyalari soni `log2(L_initial) - log2(L_final_sorted)` ga teng bo'ladi. Buning sababi, har bir operatsiya massiv uzunligini ikki barobar qisqartiradi, bu esa `log2` qiymatining 1 ga kamayishiga olib keladi.

Bu turdagi oraliklar bo'yicha maksimal qiymatni topish masalalari odatda **Segment Tree (segmentlar daraxti)** ma'lumotlar tuzilmasi yordamida samarali hal qilinadi. Segment daraxtining har bir tuguni o'zi qamrab olgan `[tl, tr]` oralig'i uchun ikkita muhim ma'lumotni saqlaydi:
1.  `max_len`: Ushbu `[tl, tr]` oralig'ida joylashgan eng uzun saralangan qismmassivning uzunligi (bu uzunlik ham 2 ning darajasi bo'lishi kafolatlangan).
2.  `is_sorted`: Butun `[tl, tr]` oralig'i kamaymaslik tartibida saralanganmi yoki yo'qmi (ya'ni `a[tl] <= a[tl+1] <= ... <= a[tr]`). Bu ikkala qiymat tugunlarni birlashtirishda va so'rovlarga javob berishda hal qiluvchi rol o'ynaydi.

## Algoritm qadamlari

1.  **Tezkor I/O konfiguratsiyasi:** `std::ios_base::sync_with_stdio(false)` va `std::cin.tie(0)` chaqiruvi orqali C++ standart kirish/chiqish (I/O) operatsiyalarini tezlashtiriladi.

2.  **`log2_int` funksiyasi:** Bu funksiya berilgan va 2 ning darajasi bo'lgan `n` sonining ikkilik logarifmini (`log2`) hisoblash uchun optimallashtirilgan usulni taqdim etadi. U GCC/Clang kompilyatorlarining `__builtin_clz` (count leading zeros) intrinsik funksiyasidan foydalanadi. Bu funksiya `n` sonining ikkilik ko'rinishida eng chapdagi (yuqori tartibli) 1 raqamidan oldingi nollarning sonini hisoblaydi. `log2(n)` qiymati 32-bitli butun sonlar uchun `(sizeof(int) * CHAR_BIT - 1) - __builtin_clz(n)` formula bilan topiladi. `CHAR_BIT` bitta baytdagi bitlar sonini bildiradi.

3.  **Massiv va segment daraxti tuzilmasi:**
    *   `a[MAX_ARRAY_SIZE]`: Kirish massivi elementlarini saqlash uchun global massiv. `MAX_ARRAY_SIZE` `N` dan biroz kattaroq, 1-indeksdan foydalanishda xavfsizlik uchun.
    *   `Node` tuzilmasi: Segment daraxtining har bir tuguni uchun `int max_len` va `bool is_sorted` maydonlarini o'z ichiga oladi.
    *   `tree[4 * MAX_ARRAY_SIZE]`: Segment daraxti tugunlarini saqlash uchun massiv. Segment daraxti uchun odatda `4 * N` o'lcham yetarli bo'ladi.

4.  **`build(int v, int tl, int tr)` funksiyasi (Segment daraxtini qurish):**
    *   `v`: Joriy tugunning `tree` massividagi indeksi.
    *   `tl, tr`: Joriy tugun qamrab olgan massivning oralig'i `[tl, tr]`.
    *   **Baza holati:** Agar `tl == tr` bo'lsa (ya'ni, tugun bir elementli oralig'ini qamrab olsa), bu barg tugundir. Bir elementli massiv har doim saralangan hisoblanadi. Shuning uchun `tree[v].max_len = 1` va `tree[v].is_sorted = true` qilib o'rnatiladi.
    *   **Rekursiv holat:** Agar `tl != tr` bo'lsa, oraliq `tm = (tl + tr) / 2` nuqtada ikki qismga bo'linadi. Chap farzand (`2*v`) `[tl, tm]` oralig'ini, o'ng farzand (`2*v+1`) `[tm+1, tr]` oralig'ini qamrab oladi.
        *   Avval chap va o'ng farzandlar rekursiv ravishda quriladi.
        *   Joriy tugunning `max_len` qiymati farzandlarning `max_len` qiymatlari ichidan maksimallisi qilib o'rnatiladi: `tree[v].max_len = std::max(tree[2*v].max_len, tree[2*v+1].max_len)`.
        *   Joriy tugunning `is_sorted` qiymati chap farzandning saralangan bo'lishi, o'ng farzandning saralangan bo'lishi va ikkala qismning birlashgan nuqtasida (`a[tm]` va `a[tm+1]`) `a[tm] <= a[tm+1]` shartining bajarilishi bilan aniqlanadi.
        *   Agar butun `[tl, tr]` oraliq saralangan bo'lsa (`tree[v].is_sorted` `true` bo'lsa), uning uzunligi (`tr - tl + 1`) ham `max_len` uchun nomzod bo'ladi. Shuning uchun `tree[v].max_len` bu qiymat bilan yangilanadi.

5.  **`query(int v, int tl, int tr, int ql, int qr)` funksiyasi (Segment daraxtini so'rash):**
    *   `v, tl, tr`: Joriy tugun va uning qamrab olgan oralig'i.
    *   `ql, qr`: So'rov oralig'i `[ql, qr]`.
    *   **Baza holatlari:**
        *   Agar so'rov oralig'i bo'sh bo'lsa (`ql > qr`) yoki joriy tugun oralig'idan butunlay tashqarida bo'lsa (`tl > qr || tr < ql`), u holda `{0, true}` qaytariladi (uzunlik 0, shuning uchun saralangan deb hisoblanadi).
        *   Agar joriy tugun oralig'i so'rov oralig'ini to'liq qoplashsa (`ql == tl && qr == tr`), u holda `tree[v]` tugunida oldindan hisoblangan `Node` qiymatlari qaytariladi.
    *   **Rekursiv holat:** Joriy tugun oralig'i `tm = (tl + tr) / 2` nuqtada bo'linadi.
        *   Chap va o'ng farzandlar uchun `query` funksiyasi chaqiriladi. Bunda so'rov oralig'i farzandlarning oralig'iga mos ravishda qisqartiriladi: chap farzand uchun `[ql, std::min(qr, tm)]`, o'ng farzand uchun `[std::max(ql, tm + 1), qr]`.
        *   `left_res` va `right_res` natijalari birlashtirilib, `current_res` hosil qilinadi:
            *   `current_res.max_len` ikkala farzandning `max_len` qiymatlaridan maksimallisi qilib o'rnatiladi.
            *   `current_res.is_sorted` ikkala farzandning `is_sorted` qiymatlari `true` bo'lsa, `true` bo'ladi.
            *   **Birlashma nuqtasini tekshirish:** Agar so'rov oralig'i `ql, qr` `tm` va `tm+1` elementlarini o'z ichiga olsa (`ql <= tm && tm + 1 <= qr`), u holda `a[tm] <= a[tm + 1]` sharti ham `current_res.is_sorted` uchun tekshiriladi.
            *   Agar `current_res.is_sorted` `true` bo'lsa, ya'ni butun so'rov oralig'i saralangan bo'lsa, uning uzunligi (`qr - ql + 1`) ham `current_res.max_len` uchun nomzod bo'ladi va `current_res.max_len` yangilanadi.
        *   `current_res` qaytariladi.

6.  **`main()` funksiyasi:**
    *   `fast_io()` chaqiriladi.
    *   `N` (massiv uzunligi) va `Q` (so'rovlar soni) o'qiladi.
    *   `a` massivining elementlari 1-indeksdan boshlab o'qiladi.
    *   `build(1, 1, N)` chaqirib butun massiv uchun segment daraxti quriladi.
    *   `Q` ta so'rov uchun `l` va `r` indekslari o'qiladi.
    *   `query(1, 1, N, l, r)` chaqiriladi va natija `result` ga olinadi.
    *   Boshlang'ich qismmassiv uzunligi `initial_len = r - l + 1` hisoblanadi.
    *   Topilgan maksimal saralangan qismmassivning uzunligi `final_sorted_len = result.max_len`.
    *   Javob `log2_int(initial_len) - log2_int(final_sorted_len)` formula bo'yicha hisoblanadi va ekranga chiqariladi.

## Murakkablik tahlili

*   **Vaqt murakkabligi**:
    *   **Segment daraxtini qurish (`build`):** `O(N)` vaqt oladi, chunki har bir tugun bir marta ko'rib chiqiladi va hisob-kitoblar doimiy vaqtda bajariladi.
    *   **So'rovlarni bajarish (`query`):** Har bir so'rov uchun `O(log N)` vaqt oladi, chunki har bir darajada ko'pi bilan ikkita tugun ko'rib chiqiladi.
    *   **Jami vaqt murakkabligi:** `O(N + Q * log N)`.
    *   Berilgan chegaralar (`N` ≤ 131072, `Q` ≤ 200000) uchun: `131072 + 200000 * log2(131072)` ≈ `1.3 * 10^5 + 2 * 10^5 * 17` ≈ `3.53 * 10^6` operatsiyalar atrofida, bu 1500 ms vaqt chegarasiga sig'adi.

*   **Xotira murakkabligi**:
    *   **`a` massivi:** `O(N)` xotira oladi.
    *   **`tree` massivi (segment daraxti):** Segment daraxti taxminan `4N` ta tugundan iborat bo'ladi. Har bir `Node` tuzilmasi bir `int` va bir `bool` maydoniga ega, bu esa kichik hajmda. Shuning uchun, segment daraxti uchun umumiy xotira `O(N)` bo'ladi.
    *   **Jami xotira murakkabligi:** `O(N)`.
    *   Berilgan chegaralar (`N` ≤ 131072) uchun: `131072 * sizeof(int)` (massiv `a`) + `4 * 131072 * sizeof(Node)` (segment daraxti). Agar `sizeof(int)` 4 bayt va `sizeof(Node)` (padding hisobga olinganda) 8-12 bayt bo'lsa, jami xotira taxminan `0.5 MB + 6 MB` atrofida bo'lib, 128 MB xotira chegarasiga bemalol sig'adi.

*   **Nega shu murakkablik chegaraga sig'adi:** Yuqoridagi tahlillar shuni ko'rsatadiki, algoritmning vaqt va xotira talablari berilgan `N` va `Q` chegaralari uchun doirasida qoladi. Segment daraxti, ayniqsa, massivdagi oralik so'rovlarini logarifmik vaqtda bajarishga imkon berib, masalaning samarali yechimini ta'minlaydi.

## Kod izohi

1.  **`log2_int(int n)`:** Yuqorida tushuntirilganidek, bu funksiya 2 ning darajasi bo'lgan butun sonlar uchun `log2` ni tez hisoblaydi. Bu `std::log2` ning suzuvchi nuqta aniqligi muammolaridan qochishga yordam beradi.

2.  **`fast_io()`:** Kirish/chiqish operatsiyalarini optimallashtiruvchi standart C++ bo'lmagan usullar.

3.  **`a` massivi:** Kirish ma'lumotlarini saqlaydigan global butun sonlar massivi. 1-indeksdan foydalaniladi.

4.  **`Node` tuzilmasi:**
    *   `max_len`: Joriy tugun qamrab olgan oralikdagi eng uzun saralangan qismmassivning uzunligi. Bu qiymat har doim 2 ning darajasi bo'ladi.
    *   `is_sorted`: Joriy tugun qamrab olgan butun oralig'ining saralanganligini ko'rsatuvchi boolean qiymati.

5.  **`tree` massivi:** Segment daraxti tugunlarini saqlash uchun `Node` tipidagi global massiv.

6.  **`build` funksiyasi:**
    *   Rekursiv tarzda massivni bo'lib, eng pastki (barg) tugunlardan boshlab yuqoriga ko'tariladi.
    *   Barg tugunlari uchun `max_len = 1` va `is_sorted = true` (har bir element o'zi saralangan).
    *   Ichki tugunlar uchun `max_len` chap va o'ng farzandlarning `max_len` qiymatlarining maksimumi va agar butun oraliq saralangan bo'lsa, bu oraliqning o'z uzunligi (`tr - tl + 1`) ham hisobga olinadi.
    *   `is_sorted` qiymati chap va o'ng farzandlar saralangan bo'lsa va ularning tutashgan joyi (`a[tm] <= a[tm+1]`) to'g'ri bo'lsa, `true` bo'ladi.

7.  **`query` funksiyasi:**
    *   Berilgan `[ql, qr]` so'rov oralig'i uchun `Node` obyektini qaytaradi.
    *   Barg tugunlari yoki to'liq mos keladigan tugunlar uchun oldindan hisoblangan qiymatlarni qaytaradi.
    *   Qisman mos keladigan tugunlar uchun so'rovni farzandlarga bo'lib, ularning natijalarini birlashtiradi.
    *   Natijalarni birlashtirishda `max_len` maksimumni olish orqali topiladi.
    *   `is_sorted` ni hisoblashda `a[tm] <= a[tm+1]` shartining so'rov oralig'iga tegishli ekanligini tekshirish (`ql <= tm && tm + 1 <= qr`) muhimdir. Agar bu shart bajarilsa va farzandlar ham saralangan bo'lsa, `is_sorted` `true` bo'ladi.
    *   Agar so'rov oralig'ining o'zi to'liq saralangan bo'lsa (`current_res.is_sorted` `true` bo'lsa), uning uzunligi (`qr - ql + 1`) ham `current_res.max_len` uchun nomzod bo'ladi.

8.  **`main` funksiyasi:** Kirishni o'qiydi, daraxtni quradi va har bir so'rov uchun `query` funksiyasini chaqirib, natijani `log2_int` yordamida hisoblab chiqadi.

## Edge case lar va eslatmalar

*   **Uzunlik 2 ning darajasi ekanligi:** Masalada `r - l + 1` qismmassiv uzunligi har doim 2 ning darajasi ekanligi kafolatlanadi. Bu juda muhim, chunki Thanosning bo'lish jarayoni ham doim uzunlikni ikkiga bo'ladi, shuning uchun `L_final_sorted` ham har doim 2 ning darajasi bo'lib qoladi. Bu `log2_int` funksiyasining noto'g'ri qiymatlar uchun chaqirilmasligini va `max_len` nol bo'lmagan holda har doim to'g'ri natija berishini ta'minlaydi.
*   **1-indeksdan foydalanish:** Kodda massiv `a` va so'rov oralig'i `l, r` 1-indeksdan boshlab ishlatilgan. Bu indeksatsiya sxemasiga doimiy ravishda rioya qilish zarur.
*   **`__builtin_clz` ning portativligi:** `__builtin_clz` funksiyasi GCC va Clang kompilyatorlariga xosdir. Agar boshqa kompilyatorlar (masalan, MSVC) ishlatilsa, u ishlamasligi mumkin. Bunday hollarda, `std::log2` (double qabul qiladi, butun sonlarga aylantirish kerak bo'ladi) yoki bitli operatsiyalar bilan `log2` ni hisoblaydigan boshqa butun son funksiyasini yozish kerak bo'ladi. Biroq, competitive programming muhitlarida bu intrinsik funksiyalar keng qo'llaniladi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M071D) platformasidagi **M071D** raqamli **Thanos sort** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M071D>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M071D, Thanos sort yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
