---
title: "M070B — Fruits (Mevalar) | Robocontest.uz Yechimi"
description: "Robocontest.uz M070B (Fruits (Mevalar)) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 512 MB."
keywords: "robocontest M070B, Fruits (Mevalar) yechimi, robocontest Fruits (Mevalar), M070B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M070B_fruits_mevalar/
lang: uz
---

# M070B — Fruits (Mevalar)

## Masala haqida
Gavhar `N` dona meva terib, ularni bir qatorga tergan. Har bir meva Apelsin ('a') yoki Banan ('b') bo'lishi mumkin. Gavhar apelsinlarni ko'proq yoqtirgani sababli, u shunday mevalar oralig'ini tanlamoqchiki, bunda ushbu oraliqning har qanday qismida chapdan kelganda ham, o'ngdan kelganda ham Apelsinlar soni Bananlar sonidan kam bo'lmasligi kerak. Bunday oraliqlar ichidan Gavhar uzunligi maksimal bo'lganini topishi lozim.

## Yondashuv (g'oya)
Masalani samarali yechish uchun biz stringni `(Apelsinlar soni - Bananlar soni)` ko'rinishiga o'tkazishimiz kerak. 'a' belgisi uchun +1, 'b' belgisi uchun -1 qiymatlarini belgilaymiz. Keyin `P` nomli `prefix sum (oldindan yig'indi)` massivini hosil qilamiz. `P[k]` qiymati `S` satrining dastlabki `k` ta belgisidagi (ya'ni `S[0...k-1]` dagi) `(Apelsinlar soni - Bananlar soni)` ga teng bo'ladi. `P[0] = 0` deb olamiz.

Shundan so'ng, masalaning ikkita shartini `P` massivi yordamida ifodalashimiz mumkin:
Agar biz `S[i...j]` oraliqni tanlasak, bu `P` massivida `P[i]` va `P[j+1]` indekslariga to'g'ri keladi. Uzunligi `j - i + 1` bo'lgan `S[i...j]` oraliq, `P` massivida `P[i...j+1]` oraliqqa mos keladi.

1.  **Chapdan kelganda shart**: `S[i...j]` oraliqning har qanday prefiksi uchun apelsinlar soni bananlar sonidan kam emas. Bu `P` massivida `P[i]` ning `P[i...j+1]` oraliqdagi minimum qiymat bo'lishini anglatadi. Ya'ni, `P[k] >= P[i]` barcha `k` ∈ `[i, j+1]` uchun.
2.  **O'ngdan kelganda shart**: `S[i...j]` oraliqning har qanday suffiksi uchun apelsinlar soni bananlar sonidan kam emas. Bu `P` massivida `P[j+1]` ning `P[i...j+1]` oraliqdagi maksimum qiymat bo'lishini anglatadi. Ya'ni, `P[k] <= P[j+1]` barcha `k` ∈ `[i, j+1]` uchun.

Ushbu shartlarni samarali tekshirish uchun biz `L_idx` (stringning boshlanish indeksi `i` ga mos) va `R_idx` (stringning tugash indeksi `j+1` ga mos) lar bo'yicha iteratsiya qilamiz.

*   `P[L_idx]` minimum bo'lish shartini tekshirish uchun `right_min_P` massividan foydalanamiz. `right_min_P[k]` — `P[x] < P[k]` bo'ladigan eng kichik `x > k` indeks. Agar `P[L_idx]` tanlangan `[L_idx, R_idx]` oraliqda minimum bo'lishi kerak bo'lsa, u holda `R_idx` ning qiymati `right_min_P[L_idx]` dan kichik bo'lishi kerak. Bu massivni `monotonik stek (tartiblangan stek)` yordamida `O(N)` vaqtda hisoblash mumkin.

*   `P[R_idx]` maksimum bo'lish shartini tekshirish uchun `left_max_P_values` massividan foydalanamiz. `left_max_P_values[k]` — `P[x] > P[k]` bo'ladigan eng katta `x < k` indeks. Agar `P[R_idx]` tanlangan `[L_idx, R_idx]` oraliqda maksimum bo'lishi kerak bo'lsa, u holda `L_idx` ning qiymati `left_max_P_values[R_idx]` dan katta bo'lishi kerak. Bu massivni ham `monotonik stek` yordamida `O(N)` vaqtda hisoblash mumkin.

`L_idx` ni iterate qilib, `right_min_P[L_idx]` yordamida `R_idx` uchun yuqori chegarani topamiz. Keyin berilgan oraliqda `left_max_P_values[R_idx] < L_idx` shartini qanoatlantiradigan eng katta `R_idx` ni topishimiz kerak. Bu yerda `segment daraxti (segment tree)` ma'lumotlar tuzilmasidan foydalanamiz. Segment daraxti `left_max_P_values` massivi ustida quriladi va berilgan oraliqdagi minimum qiymatni qaytaradi. Bizning `query_max_idx` funksiyamiz esa oraliqda `threshold` (bu yerda `L_idx`) dan kichikroq `left_max_P_values[R_idx]` qiymatga ega bo'lgan eng katta `R_idx` ni topadi.

## Algoritm qadamlari
1.  **`P` massivini hisoblash**:
    *   `N+1` o'lchamli `P` massivini yaratamiz.
    *   `P[0] = 0` deb boshlaymiz.
    *   `k = 0` dan `N-1` gacha `S[k]` belgisiga qarab `P[k+1] = P[k] + (S[k] == 'a' ? 1 : -1)` formulasi bilan `P` massivini to'ldiramiz.

2.  **`right_min_P` massivini hisoblash**:
    *   `N+1` o'lchamli `right_min_P` massivini yaratamiz.
    *   Bo'sh `stek (stack)` yaratamiz.
    *   `k = N` dan `0` gacha teskari tartibda iteratsiya qilamiz:
        *   Stek bo'sh bo'lmaguncha va `P[st.top()] >= P[k]` bo'lsa, stekdan elementlarni chiqaramiz.
        *   `right_min_P[k]` ga stek bo'sh bo'lsa `N+1`, aks holda `st.top()` ni tayinlaymiz.
        *   `k` ni stekka joylaymiz.

3.  **`left_max_P_values` massivini hisoblash**:
    *   `N+1` o'lchamli `left_max_P_values` massivini yaratamiz.
    *   Stekni tozalaymiz.
    *   `k = 0` dan `N` gacha to'g'ri tartibda iteratsiya qilamiz:
        *   Stek bo'sh bo'lmaguncha va `P[st.top()] <= P[k]` bo'lsa, stekdan elementlarni chiqaramiz.
        *   `left_max_P_values[k]` ga stek bo'sh bo'lsa `-1`, aks holda `st.top()` ni tayinlaymiz.
        *   `k` ni stekka joylaymiz.

4.  **Segment daraxtini qurish**:
    *   `left_max_P_values` massivi ustida `segment daraxti` ni qurish uchun `build` funksiyasini chaqiramiz. Bu daraxt berilgan oraliqdagi minimum `left_max_P_values` indeksini saqlaydi.

5.  **Maksimal uzunlikni topish**:
    *   `max_len = 0` deb boshlang'ich qiymat beramiz.
    *   `L_idx = 0` dan `N` gacha iteratsiya qilamiz (har bir mumkin bo'lgan boshlanish nuqtasi uchun):
        *   `R_idx` uchun oraliqni aniqlaymiz:
            *   `query_L_for_R_idx = L_idx + 1` (chunki `R_idx` har doim `L_idx` dan katta bo'lishi kerak).
            *   `query_R_for_R_idx = right_min_P[L_idx] - 1` (chunki `P[L_idx]` minimum bo'lishi uchun `R_idx` `right_min_P[L_idx]` dan kichik bo'lishi kerak).
        *   Agar `query_L_for_R_idx` `query_R_for_R_idx` dan katta bo'lsa, bu `L_idx` uchun mos `R_idx` topilmaydi, keyingi `L_idx` ga o'tamiz.
        *   `segment daraxti` yordamida `query_max_idx` funksiyasini chaqiramiz. Bu funksiya `[query_L_for_R_idx, query_R_for_R_idx]` oraliqda `left_max_P_values[R_idx] < L_idx` shartini qanoatlantiradigan eng katta `R_idx` ni topadi.
        *   Agar `R_found` (topilgan `R_idx`) `-1` bo'lmasa, `max_len = max(max_len, R_found - L_idx)` ni yangilaymiz.
    *   Natijada `max_len` ni chop etamiz.

## Murakkablik tahlili
-   **Vaqt**: `O(N log N)`
    *   `P` massivini hisoblash: `O(N)`.
    *   `right_min_P` massivini hisoblash (stek yordamida): Har bir element stekka bir marta kiradi va bir marta chiqadi, shuning uchun `O(N)`.
    *   `left_max_P_values` massivini hisoblash (stek yordamida): Xuddi shunday, `O(N)`.
    *   Segment daraxtini qurish (`build` funksiyasi): `O(N)`.
    *   Asosiy sikl: `L_idx` uchun `N+1` marta iteratsiya qilinadi. Har bir iteratsiyada `segment daraxti` ga so'rov yuboriladi (`query_max_idx` funksiyasi). Segment daraxti so'rovi `O(log N)` vaqt oladi. Shunday qilib, umumiy hisobda `O(N log N)`.
    *   Jami vaqt murakkabligi: `O(N + N + N + N + N log N) = O(N log N)`.
    *   `N ≤ 10^6` bo'lgan holda `N log N` taxminan `10^6 * log_2(10^6) ≈ 10^6 * 20 ≈ 2 * 10^7` operatsiyani tashkil qiladi, bu 1000 ms vaqt limiti ichida bemalol bajariladi.

-   **Xotira**: `O(N)`
    *   `P` massivi: `N+1` ta `int` element, `O(N)`.
    *   `right_min_P` massivi: `N+1` ta `int` element, `O(N)`.
    *   `left_max_P_values` massivi: `N+1` ta `int` element, `O(N)`.
    *   `segment_tree_data` massivi: Segment daraxti uchun odatda bazaviy massivning `4N` ga yaqin o'lchamda bo'ladi, shuning uchun `O(N)`.
    *   Stek: Eng yomon holatda `N` ta elementni saqlashi mumkin, `O(N)`.
    *   Jami xotira murakkabligi: `O(N)`.
    *   `N ≤ 10^6` bo'lgan holda `N` ta `int` taxminan 4 MB xotira oladi. Umumiy `O(N)` massivlar va segment daraxti birgalikda taxminan `(4 + 4 + 4 + 16 + 4) = 32 MB` atrofida xotira talab qiladi, bu 512 MB xotira limiti ichida bemalol joylashadi.

## Kod izohi

### 1. Global o'zgaruvchilar va `main` funksiyasining boshlanishi
```cpp
std::vector<int> segment_tree_data;
std::vector<int> left_max_P_values; 
int N_plus_1_size; 

// ... build va query funksiyalari ...

int main() {
    std::ios_base::sync_with_stdio(false); // C++ oqimlarini C oqimlari bilan sinxronizatsiyani o'chiradi
    std::cin.tie(0); // cin/cout operatsiyalarini tezlashtiradi

    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    N_plus_1_size = N + 1;
    // ...
}
```
*   `segment_tree_data`: Segment daraxtining tugunlarini saqlovchi vektor. Har bir tugun o'z oralig'idagi `left_max_P_values` ning minimum qiymatini saqlaydi.
*   `left_max_P_values`: `P` massividagi har bir `k` indeksi uchun `P[x] > P[k]` shartini qanoatlantiradigan eng katta `x < k` indeksni saqlaydi. Bu massiv segment daraxti uchun asos bo'lib xizmat qiladi.
*   `N_plus_1_size`: `P` massivi va unga tegishli yordamchi massivlarning o'lchamini (ya'ni `N+1` ni) saqlovchi o'zgaruvchi.
*   `std::ios_base::sync_with_stdio(false);` va `std::cin.tie(0);`: Kirish/chiqish operatsiyalarini tezlashtirish uchun ishlatiladi, bu katta `N` qiymatlari uchun muhim.

### 2. `P` massivini hisoblash
```cpp
    std::vector<int> P(N_plus_1_size);
    P[0] = 0;
    for (int k = 0; k < N; ++k) {
        P[k + 1] = P[k] + (S[k] == 'a' ? 1 : -1);
    }
```
*   `P` massivi `N+1` o'lchamda bo'lib, `P[k]` stringning `S[0...k-1]` qismidagi `(apelsinlar soni - bananlar soni)` ni bildiradi. `P[0]` esa bo'sh prefiks uchun 0 ga teng.

### 3. `right_min_P` massivini hisoblash (Monotonik kamayuvchi stek)
```cpp
    std::vector<int> right_min_P(N_plus_1_size);
    std::stack<int> st; // Stek indekslarni saqlaydi
    for (int k = N; k >= 0; --k) { // Teskari tartibda yurish
        while (!st.empty() && P[st.top()] >= P[k]) { // P[k] dan katta yoki teng elementlarni chiqarish
            st.pop();
        }
        right_min_P[k] = st.empty() ? N_plus_1_size : st.top(); // Agar stek bo'sh bo'lsa, N+1 ni, aks holda eng yaqin kichik element indeksini saqlash
        st.push(k); // Hozirgi indeksni stekka joylash
    }
```
*   Bu qism `P[k]` dan o'ngda joylashgan va `P[k]` dan qat'iy kichik bo'lgan birinchi elementning indeksini `right_min_P[k]` ga saqlaydi. Bu **monotonik kamayuvchi stek** yordamida amalga oshiriladi. Stekning tepasida har doim kichik qiymatlar indekslari turadi. Agar yangi element `P[k]` stekdagi elementdan kichik bo'lsa, u to'g'ridan-to'g'ri unga to'g'ri keladigan joyga joylashadi. Aks holda, stekdagi katta elementlar chiqariladi.

### 4. `left_max_P_values` massivini hisoblash (Monotonik o'suvchi stek)
```cpp
    left_max_P_values.resize(N_plus_1_size); 
    while (!st.empty()) st.pop(); // Stekni qayta ishlatish uchun tozalash
    for (int k = 0; k < N_plus_1_size; ++k) { // To'g'ri tartibda yurish
        while (!st.empty() && P[st.top()] <= P[k]) { // P[k] dan kichik yoki teng elementlarni chiqarish
            st.pop();
        }
        left_max_P_values[k] = st.empty() ? -1 : st.top(); // Agar stek bo'sh bo'lsa, -1 ni, aks holda eng yaqin katta element indeksini saqlash
        st.push(k); // Hozirgi indeksni stekka joylash
    }
```
*   Bu qism `P[k]` dan chapda joylashgan va `P[k]` dan qat'iy katta bo'lgan birinchi elementning indeksini `left_max_P_values[k]` ga saqlaydi. Bu **monotonik o'suvchi stek** yordamida amalga oshiriladi. Stekning tepasida har doim katta qiymatlar indekslari turadi.

### 5. Segment daraxtini qurish (`build` funksiyasi)
```cpp
void build(int node_idx, int start, int end) {
    if (start == end) { // Barg tuguni
        segment_tree_data[node_idx] = left_max_P_values[start];
    } else { // Ichki tugun
        int mid = (start + end) / 2;
        build(2 * node_idx, start, mid); // Chap bolani qurish
        build(2 * node_idx + 1, mid + 1, end); // O'ng bolani qurish
        segment_tree_data[node_idx] = std::min(segment_tree_data[2 * node_idx], segment_tree_data[2 * node_idx + 1]); // Bolalarning minimumini saqlash
    }
}
```
*   `build` funksiyasi `left_max_P_values` massivi ustida segment daraxtini quradi. Har bir tugun o'ziga mos keladigan oraliqdagi `left_max_P_values` ning minimum qiymatini saqlaydi. Segment daraxti to'liq `4 * N_plus_1_size` o'lchamli vektorga joylashtiriladi.

### 6. Segment daraxtiga so'rov berish (`query_max_idx` funksiyasi)
```cpp
int query_max_idx(int node_idx, int start, int end, int query_L, int query_R, int threshold) {
    // Agar oraliq so'rov oraliqdan tashqarida bo'lsa yoki barcha qiymatlar chegaradan katta bo'lsa
    if (start > query_R || end < query_L || segment_tree_data[node_idx] >= threshold) {
        return -1; // Topilmadi
    }

    if (start == end) { // Barg tuguniga yetib keldik va shart qanoatlantirildi
        return start; // Bu indeksni qaytarish
    }

    int mid = (start + end) / 2;
    int res = -1;

    // Eng KATTA R_idx ni topish uchun o'ng boladan boshlab qidiriladi
    if (mid + 1 <= query_R) { // Agar o'ng bola so'rov oralig'i bilan kesishsa
        res = query_max_idx(2 * node_idx + 1, mid + 1, end, query_L, query_R, threshold);
    }
    
    if (res != -1) { // Agar o'ng boladan topilsa, darhol qaytarish
        return res;
    }

    if (mid >= query_L) { // Agar chap bola so'rov oralig'i bilan kesishsa
        res = query_max_idx(2 * node_idx, start, mid, query_L, query_R, threshold);
    }
    
    return res;
}
```
*   `query_max_idx` funksiyasi `[query_L, query_R]` oraliqda `left_max_P_values[R_idx] < threshold` shartini qanoatlantiradigan eng katta `R_idx` ni topadi.
*   Bu funksiya odatdagi segment daraxti so'rovidan farqli o'laroq, eng katta indeksni topish uchun **o'ng bolani birinchi tekshiradi**. Agar o'ng boladan mos keladigan indeks topilsa, u darhol qaytariladi. Agar topilmasa, chap boladan qidiriladi. Bu strategiya eng katta `R_idx` ni topishni ta'minlaydi.
*   `threshold` parametri bu yerda `L_idx` ning qiymatini bildiradi. Shuning uchun `left_max_P_values[R_idx] < L_idx` sharti tekshiriladi, bu esa `P[R_idx]` ni `P[L_idx...R_idx]` oraliqning maksimumi bo'lishini ta'minlaydi.

### 7. Maksimal uzunlikni topish uchun asosiy sikl
```cpp
    int max_len = 0;
    for (int L_idx = 0; L_idx < N_plus_1_size; ++L_idx) {
        int query_L_for_R_idx = L_idx + 1;
        int query_R_for_R_idx = right_min_P[L_idx] - 1;

        if (query_L_for_R_idx > query_R_for_R_idx) { 
            continue;
        }
        
        int R_found = query_max_idx(1, 0, N, query_L_for_R_idx, query_R_for_R_idx, L_idx);

        if (R_found != -1) {
            max_len = std::max(max_len, R_found - L_idx);
        }
    }
    std::cout << max_len << std::endl;
```
*   Bu sikl har bir mumkin bo'lgan `L_idx` (ya'ni `S` dagi `i` indeksi) uchun iteratsiya qiladi.
*   `right_min_P[L_idx]` yordamida `R_idx` (ya'ni `S` dagi `j+1` indeksi) uchun cheklangan oraliq `[query_L_for_R_idx, query_R_for_R_idx]` aniqlanadi. Bu `P[L_idx]` minimum bo'lish shartini ta'minlaydi.
*   So'ngra, bu cheklangan oraliq ichida `left_max_P_values[R_idx] < L_idx` shartini qanoatlantiradigan eng katta `R_idx` ni topish uchun `query_max_idx` chaqiriladi. Bu `P[R_idx]` maksimum bo'lish shartini ta'minlaydi.
*   Agar mos `R_idx` topilsa, `(R_found - L_idx)` uzunligi hisoblanadi va `max_len` yangilanadi. `R_found - L_idx` string `S[L_idx...R_found-1]` ning uzunligidir.

## Edge case lar va eslatmalar
*   **Bo'sh stek holatlari**: `right_min_P` va `left_max_P_values` ni hisoblashda stek bo'sh bo'lishi mumkin. Bunday holatlarda `right_min_P` uchun `N_plus_1_size` va `left_max_P_values` uchun `-1` qiymatlari mos ravishda ishlatilgan. Bu keyinchalik oraliq hisoblashda to'g'ri cheklovlarni ta'minlaydi.
*   **`N=1` holati**: Agar `N=1` va `S="a"` bo'lsa, `P=[0, 1]`. `L_idx=0` va `R_idx=1` bo'ladi. `R_idx - L_idx = 1`. Natija 1 bo'ladi. Agar `S="b"` bo'lsa, `P=[0, -1]`. `L_idx=0` uchun `right_min_P[0]=1` bo'ladi. `R_idx` oralig'i `[1, 0]` bo'lib, noqonuniy bo'ladi. Natija 0 bo'ladi. Algoritm bu holatlarni to'g'ri ishladi.
*   **Barcha Apelsinlar (`"aaa..."`) yoki Barcha Bananlar (`"bbb..."`)**: Bu holatlarda ham algoritm to'g'ri ishlaydi. Masalan, `"aaa"` uchun `P=[0,1,2,3]`. `max_len = 3` bo'ladi. `"bbb"` uchun `P=[0,-1,-2,-3]`, `max_len = 0` bo'ladi.
*   **Indeks chegaralari**: `P` massivi `N+1` elementga ega (`0` dan `N` gacha indekslar). Asl stringning `S[i...j]` oraliqi `P` massivida `P[i...j+1]` ga mos keladi. Uzunlik `(j+1) - i = R_idx - L_idx`. Bu hisob-kitoblar kodda to'g'ri aks etgan.
*   **Tez I/O**: `std::ios_base::sync_with_stdio(false);` va `std::cin.tie(0);` qatorlari `N=10^6` bo'lganda kirish/chiqish operatsiyalarining sekinligini oldini olish uchun zarur.
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M070B) platformasidagi **M070B** raqamli **Fruits (Mevalar)** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M070B>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M070B, Fruits (Mevalar) yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
