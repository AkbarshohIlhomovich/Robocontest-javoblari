Bu masala bo'yicha toza, batafsil va o'rgatuvchi documentation quyida keltirilgan:

# M070E — MEX-xe-xe

## Masala haqida
Masalada `N` ta elementdan iborat `a` massivi beriladi. Bizdan `1 <= k <= N` bo'lgan har bir `k` uchun `f(k)` ni topish talab qilinadi. `f(k)` — bu `a` massivini bir nechta bo'laklarga (segmentlarga) ajratishdagi minimal bo'laklar soni bo'lib, har bir bo'lakning `MEX` (Minimum Excluded - massivda mavjud bo'lmagan eng kichik nomanfiy butun son) qiymati `k` dan oshmasligi kerak. Misol uchun, `MEX([1, 2, 0, 5]) = 3` va `MEX([1, 3]) = 0`.

## Yondashuv (g'oya)
Masalani yechish uchun `f(k)` ni hisoblashda "greedy" (ochko'z) yondashuvdan foydalanamiz. Minimal bo'laklar sonini olish uchun har bir bo'lakni iloji boricha uzun qilishimiz kerak.
Berilgan `k` uchun, agar biror segmentning `MEX` qiymati `k` dan oshmasligi kerak bo'lsa, bu degani o'sha segmentda `0, 1, ..., k` sonlarining hammasi bir vaqtning o'zida mavjud bo'lmasligi kerak. Boshqacha qilib aytganda, `0` dan `k` gacha bo'lgan sonlardan kamida bittasi segmentda uchramasligi lozim.

Shu g'oyadan kelib chiqib, hozirgi `current_pos` indeksidan boshlab eng uzun "yaxshi" segmentni topamiz. Bu segmentning oxirgi indeksi `j` bo'lsin. Keyingi segment `j+1` indeksidan boshlanadi.

Eng uzun "yaxshi" segmentni topish uchun, biz `current_pos` dan boshlab, `0` dan `k` gacha bo'lgan barcha sonlar qaysi eng kichik indeksgacha uchraydiganini topishimiz kerak. Aniqlik kiritadigan bo'lsak, `R_k[i]` ni `max_{x=0..k} (next_occurrence(x, i))` deb belgilaymiz, bu yerda `next_occurrence(x, i)` - `i` yoki undan katta bo'lgan eng kichik indeks, bu yerda `a[p] == x` bo'ladi.
Agar `R_k[current_pos]` `N` ga teng bo'lmasa, bu degani `0` dan `k` gacha bo'lgan barcha sonlar `a[current_pos...N-1]` oraliqda mavjud. Bunday holda, eng uzoq "yaxshi" segment `a[current_pos ... R_k[current_pos]-1]` bo'ladi, chunki `R_k[current_pos]` indeksida `0...k` sonlarining hammasi birinchi marta to'liq uchraydi va bu nuqtadan boshlab `MEX` qiymati `k` dan oshib ketadi. Keyingi segment `R_k[current_pos]` dan boshlanadi.
Agar `R_k[current_pos]` `N` ga teng bo'lsa (ya'ni `0` dan `k` gacha bo'lgan sonlarning kamida bittasi `a[current_pos...N-1]` oraliqda umuman uchramasa), u holda butun qolgan massiv `a[current_pos...N-1]` ni bitta segment sifatida olishimiz mumkin, chunki uning `MEX` qiymati `k` dan oshmaydi.

`next_occurrence(x, i)` qiymatlarini samarali topish uchun, har bir `x` qiymati massivda qaysi indekslarda uchraganini `pos_list[x]` massivida saqlab olamiz. Keyin `lower_bound` (pastki chegara) funksiyasi yordamida `current_pos` dan katta yoki teng bo'lgan birinchi uchrashuv indeksini topamiz.

## Algoritm qadamlari
1.  **Massiv elementlarining joylashuvini saqlash**:
    *   `pos_list` nomli `std::vector<std::vector<int>>` tuzilmasini yaratamiz. `pos_list[val]` har bir `val` qiymati `a` massivida uchragan barcha indekslarni o'z ichiga oladi. Massivni bir marta aylanish orqali barcha joylashuvlarni to'ldiramiz.

2.  **`f(k)` ni hisoblash**:
    *   `answers` nomli `std::vector<int>` massivini yaratamiz, bu yerda `answers[k]` `f(k)` qiymatini saqlaydi.
    *   `k_val` ni `1` dan `N` gacha takrorlaymiz (har bir `k` qiymati uchun `f(k)` ni hisoblash maqsadida).
        *   Har bir `k_val` uchun:
            *   `current_pos = 0` (joriy segment boshlanadigan indeks) va `segments = 0` (segmentlar soni) ni boshlang'ich holatga keltiramiz.
            *   `current_pos < N` ekan, quyidagi siklni takrorlaymiz:
                *   `segments` ni bittaga oshiramiz.
                *   `max_next_idx_among_0_to_k = -1` (0 dan `k_val` gacha bo'lgan sonlarning eng uzoq uchrashuv indeksini saqlash uchun) va `found_missing_in_range_0_to_k = false` (0 dan `k_val` gacha sonlardan birortasi umuman uchramasligini tekshirish uchun) o'zgaruvchilarini boshlang'ich holatga keltiramiz.
                *   `x` ni `0` dan `k_val` gacha takrorlaymiz:
                    *   `std::lower_bound` funksiyasi yordamida `pos_list[x]` ichidan `current_pos` dan katta yoki unga teng bo'lgan birinchi indeksni (ya'ni `next_occurrence(x, current_pos)` ni) topamiz.
                    *   Agar `std::lower_bound` `pos_list[x].end()` ni qaytarsa, bu degani `x` qiymati `current_pos` dan `N-1` gacha bo'lgan oraliqda umuman uchramaydi. Bunday holda, `found_missing_in_range_0_to_k = true` ni o'rnatamiz, `max_next_idx_among_0_to_k` ni `N` ga tenglashtiramiz va ichki `x` siklini tugatamiz (boshqa `x` qiymatlarini tekshirish shart emas).
                    *   Aks holda, `max_next_idx_among_0_to_k` ni topilgan indeks bilan `std::max` funksiyasi orqali yangilaymiz.
                *   `x` sikli tugaganidan so'ng:
                    *   Agar `found_missing_in_range_0_to_k` `true` bo'lsa, bu segment massiv oxirigacha borishi mumkin, chunki `0..k_val` sonlaridan bittasi umuman yo'q. Shuning uchun `current_pos` ni `N` ga tenglashtiramiz.
                    *   Aks holda, `current_pos` ni `max_next_idx_among_0_to_k` ga tenglashtiramiz. Bu `0..k_val` sonlarining hammasi uchragan eng kichik indeks, shuning uchun keyingi segment shu indeksdan boshlanishi kerak.
            *   `current_pos >= N` bo'lganda `while` sikli tugaydi va `answers[k_val]` ga topilgan `segments` sonini yozamiz.

3.  **Natijani chop etish**:
    *   `answers` massividagi `f(1), f(2), ..., f(N)` qiymatlarini chop etamiz.

## Murakkablik tahlili
-   **Vaqt**: `N` gacha bo'lgan `k_val` qiymatlari uchun hisoblash kerak. Har bir `k_val` uchun `f(k_val)` ta segment hosil bo'ladi. Har bir segmentning boshlanishida `0` dan `k_val` gacha bo'lgan `k_val + 1` ta qiymat uchun `pos_list` da `std::lower_bound` chaqiriladi. `std::lower_bound` `log N` vaqtda ishlaydi.
    Shunday qilib, umumiy vaqt murakkabligi eng yomon holatda `sum_{k=1 to N} (f(k) * (k+1) * log N)` bo'ladi. `f(k)` maksimal `N` bo'lishi mumkin, `k` maksimal `N` bo'lishi mumkin. Bu to'g'ridan-to'g'ri hisoblanganda `O(N^3 log N)` ga teng bo'lishi mumkin.

    **Izoh**: Nazariy jihatdan bu murakkablik `N = 10^6` uchun juda sekin hisoblanadi. Biroq, berilgan yechim 0ms vaqt ichida AC (Accepted) olgan. Bu shuni ko'rsatadiki:
    1.  Test holatlari eng yomon holatni (ya'ni `f(k)` va `k` bir vaqtning o'zida katta bo'lishini) ko'p sinamaydi.
    2.  `f(k)` qiymati katta `k` uchun juda tez kichik (masalan, 1 yoki 2) bo'lib qoladi, kichik `k` uchun esa `k` ning o'zi kichik bo'ladi. Natijada `f(k) * (k+1)` yig'indisi amalda ancha kichik bo'ladi.
    3.  `std::lower_bound`ning `std::vector` ustida ishlashi amalda juda tez bo'lishi mumkin, ayniqsa u ko'plab kichik vektorlarda ishlasa.

-   **Xotira**:
    *   `a` massivi: `O(N)` butun son saqlaydi.
    *   `pos_list` massivi: Bu `N` ta `std::vector` dan iborat. Ulardagi jami butun sonlar soni `N` ga teng (chunki har bir `a[i]` elementining indeksi bir marta saqlanadi). Shuning uchun umumiy xotira `O(N)` ni tashkil qiladi.
    *   `answers` massivi: `O(N)` butun son saqlaydi.
    *   Jami xotira murakkabligi: `O(N)`. `N = 10^6` uchun bu `512MB` xotira chegarasiga sig'adi.

## Kod izohi
Kodda `SegmentTree` struct` va undan keyingi ba'zi kommentlar bor, ammo ular asosiy `main` funksiyada ishlatilmagan. Demak, yakuniy yechimda bu ma'lumot tuzilmalaridan foydalanilmagan.

1.  **Kutubxonalarni kiritish va optimallash**:
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>

    // ... SegmentTree struct (ishlatilmagan) ...

    int main() {
        std::ios_base::sync_with_stdio(false); // Kirish/chiqish operatsiyalarini tezlashtirish.
        std::cin.tie(0);                      // std::cin va std::cout sinxronizatsiyasini o'chirish.
    ```

2.  **Kiritish ma'lumotlarini o'qish**:
    ```cpp
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    ```
    `N` soni va `a` massivi o'qib olinadi.

3.  **`pos_list` ni yaratish**:
    ```cpp
    std::vector<std::vector<int>> pos_list(N);
    for (int i = 0; i < N; ++i) {
        pos_list[a[i]].push_back(i);
    }
    ```
    `pos_list[val]` massivida `val` qiymatining `a` massividagi barcha indekslari ketma-ket joylashadi. Bu tez qidirish (binary search orqali) uchun qulay.

4.  **`f(k)` qiymatlarini hisoblash va saqlash**:
    ```cpp
    std::vector<int> answers(N + 1); // f(k) natijalarini saqlash uchun.
                                      // answers[0] ishlatilmaydi, answers[1]...answers[N] foydalaniladi.

    for (int k_val = 1; k_val <= N; ++k_val) {
        int current_pos = 0;
        int segments = 0;
        while (current_pos < N) {
            segments++;
            int max_next_idx_among_0_to_k = -1; // R_k[current_pos] ni hisoblash uchun
            bool found_missing_in_range_0_to_k = false; // 0..k_val dan birortasi yo'qligini tekshirish

            for (int x = 0; x <= k_val; ++x) {
                // current_pos dan katta yoki teng x ning birinchi uchrashuvini topish
                auto it = std::lower_bound(pos_list[x].begin(), pos_list[x].end(), current_pos);
                if (it == pos_list[x].end()) {
                    // Agar x qiymati current_pos dan N-1 gacha uchramasa
                    max_next_idx_among_0_to_k = N; // Segment massiv oxirigacha borishi mumkin
                    found_missing_in_range_0_to_k = true;
                    break; // Boshqa x qiymatlarini tekshirish shart emas
                }
                max_next_idx_among_0_to_k = std::max(max_next_idx_among_0_to_k, *it);
            }

            if (found_missing_in_range_0_to_k) {
                // Agar 0..k_val dan kamida bittasi qolgan massivda yo'q bo'lsa,
                // joriy segment massiv oxirigacha davom etishi mumkin.
                current_pos = N;
            } else {
                // Agar 0..k_val ning hammasi current_pos dan keyin uchrasa,
                // joriy segment max_next_idx_among_0_to_k - 1 da tugashi kerak,
                // keyingi segment esa max_next_idx_among_0_to_k dan boshlanadi.
                current_pos = max_next_idx_among_0_to_k;
            }
        }
        answers[k_val] = segments; // f(k_val) ni saqlash
    }
    ```
    Bu qism algoritmning asosiy hisoblash qismi bo'lib, yuqorida tushuntirilgan "greedy" yondashuvni amalga oshiradi.

5.  **Natijalarni chop etish**:
    ```cpp
    for (int k_val = 1; k_val <= N; ++k_val) {
        std::cout << answers[k_val] << (k_val == N ? "" : " ");
    }
    std::cout << std::endl;
    ```
    `f(1)` dan `f(N)` gacha bo'lgan barcha hisoblangan qiymatlar probellar bilan ajratib chop etiladi.

## Edge case lar va eslatmalar
*   **`k=N` holati**: `a[i]` elementlari `0` dan `N-1` gacha bo'lishi mumkin. Bu degani `N` qiymati `a` massivining hech bir joyida uchramaydi. Shuning uchun har qanday segmentning `MEX` qiymati `N` dan oshmaydi (chunki `N` doim "excluded" bo'ladi). Natijada `f(N) = 1` bo'ladi, chunki butun massivni bitta segmentga bo'lish mumkin.
*   **`k=1` holati**: Bu holatda segmentda `0` va `1` qiymatlari bir vaqtning o'zida bo'lmasligi kerak. Bu `f(k)` ning eng katta qiymatlaridan birini berishi mumkin.
*   **Bo'sh `pos_list[x]`**: Agar `x` qiymati massivda umuman uchramasa, `pos_list[x]` bo'sh bo'ladi. `std::lower_bound` chaqirilganda `pos_list[x].end()` ni qaytaradi, bu `found_missing_in_range_0_to_k = true` holatiga olib keladi va to'g'ri ishlaydi.
*   `std::ios_base::sync_with_stdio(false); std::cin.tie(0);` qatorlari C++ da katta kirish/chiqish hajmlari bilan ishlaganda vaqtni optimallashtirish uchun ishlatiladi.
