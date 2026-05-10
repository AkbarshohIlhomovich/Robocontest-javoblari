---
title: "M070C — Aliens (O'zga sayyoraliklar) | Robocontest.uz Yechimi"
description: "Robocontest.uz M070C (Aliens (O'zga sayyoraliklar)) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 4000 ms, xotira: 512 MB."
keywords: "robocontest M070C, Aliens (O'zga sayyoraliklar) yechimi, robocontest Aliens (O'zga sayyoraliklar), M070C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M070C_aliens_ozga_sayyoraliklar/
lang: uz
---

# M070C — Aliens (O'zga sayyoraliklar)

## Masala haqida
Gulnozaning `N × M` o'lchamli bog'ida daraxtlar (`'T'`) va bo'sh kataklar (`'.'`) mavjud. Uning ukasi Yahyo koinotga romb shaklida xabar yuborishni istaydi. Buning uchun u bog'dagi bo'sh kataklarga toshlar o'rnatishi kerak, lekin daraxtlarga ziyon yetkazmasligi lozim. Maqsad — eng ko'p tosh joylashtirish mumkin bo'lgan rombni topish va undagi toshlar sonini chiqarish. Romb markazi `(r, c)` va o'lchami `k` bo'lsa, u `|x - r| + |y - c| <= k` shartini qanoatlantiruvchi barcha `(x, y)` kataklarni o'z ichiga oladi.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi — eng katta rombni topish uchun uning markazini va o'lchamini (yoki "radiusi"ni, bu yerda `k` bilan belgilangan) aniqlash. Rombning o'lchami `k` qancha katta bo'lsa, undagi toshlar soni ham shuncha ko'p bo'ladi. Shuning uchun biz maksimal `k` ni topishga harakat qilamiz.
Romb joylashtirishda ikkita asosiy cheklov mavjud:
1.  **Panjara chegaralari**: Romb butunlay bog'ning `N x M` o'lchami ichida joylashishi kerak.
2.  **Daraxtlarga ziyon yetkazmaslik**: Romb toshlari daraxtlar joylashgan kataklarga o'rnatilmasligi kerak. Bu shartni qanoatlantirish uchun, har bir bo'sh katakdan eng yaqin daraxtgacha bo'lgan masofani bilishimiz kerak.

Yechimning strategiyasi quyidagicha:
1.  Barcha daraxtlardan boshlab, har bir katakgacha bo'lgan eng qisqa Manhattan masofasini hisoblaymiz. Bu Multi-source Breadth-First Search (BFS) yordamida amalga oshiriladi. `dist_tree[i][j]` massivi `(i, j)` katakdan eng yaqin daraxtgacha bo'lgan Manhattan masofasini saqlaydi.
2.  Har bir bo'sh katakni romb markazi sifatida ko'rib chiqamiz. Har bir potensial markaz `(r, c)` uchun uning panjara chegaralari ichida joylashishi mumkin bo'lgan eng katta `k_boundary` radiusini topamiz.
3.  `dist_tree[r][c]` qiymatidan foydalanib, rombning markazi daraxtga tegmasligini ta'minlaydigan maksimal `k` ni topamiz. Ya'ni, agar `(r,c)` katak eng yaqin daraxtdan `D` masofada bo'lsa, bu rombning o'lchami `k` ko'pi bilan `D-1` bo'lishi mumkin. Ushbu cheklovni `dist_tree[r][c] - 1` deb hisoblaymiz.
4.  Yuqoridagi ikkala cheklov (panjara chegarasi va daraxtdan uzoqlik) ichida eng kichigini olib, `current_k` ni topamiz. Barcha bo'sh kataklar uchun topilgan `current_k` larning maksimumi `max_k` bo'ladi.
5.  Nihoyat, topilgan `max_k` yordamida rombdagi toshlar sonini `2k^2 + 2k + 1` formulasi bo'yicha hisoblaymiz.

## Algoritm qadamlari

1.  **Kiritmalarni o'qish va daraxtlarni aniqlash**:
    *   `N` va `M` (bog' o'lchamlari) o'qiladi.
    *   `grid` (panjara) `N` qator va `M` ustundan iborat `char` matrisiga o'qiladi.
    *   `dist_tree` deb nomlangan `N x M` o'lchamli `int` massivi yaratiladi va barcha qiymatlari cheksizlik (`INF`) bilan to'ldiriladi. Bu massiv har bir katakdan eng yaqin daraxtgacha bo'lgan masofani saqlaydi.
    *   `q` (navbat) deb nomlangan `std::queue<std::pair<int, int>>` yaratiladi. Bu Multi-source BFS uchun ishlatiladi.
    *   Panjara bo'ylab yurib chiqiladi:
        *   Agar `grid[i][j]` daraxt (`'T'`) bo'lsa, `dist_tree[i][j]` ga `0` qiymati beriladi va `(i, j)` koordinatalari `q` navbatiga qo'shiladi.

2.  **Eng yaqin daraxtgacha masofani hisoblash (Multi-source BFS)**:
    *   `dr` va `dc` massivlari qo'shni kataklarga o'tish uchun yo'nalishlarni (`yuqori, past, chap, o'ng`) saqlaydi.
    *   `q` navbati bo'sh bo'lmaguncha tsikl davom etadi:
        *   Navbatdan birinchi `(r, c)` katak olinadi va olib tashlanadi.
        *   Ushbu katakning 4 ta qo'shnisi (`nr, nc`) tekshiriladi.
        *   Agar qo'shni katak panjara chegaralari ichida bo'lsa (`0 <= nr < N` va `0 <= nc < M`):
            *   Agar qo'shni katakgacha `(nr, nc)` daraxtdan borish masofasi `dist_tree[nr][nc]`, joriy katak `(r, c)` orqali borish masofasidan (`dist_tree[r][c] + 1`) katta bo'lsa:
                *   `dist_tree[nr][nc]` qiymati yangilanadi (`dist_tree[r][c] + 1`).
                *   ` (nr, nc)` katagi `q` navbatiga qo'shiladi.
    *   Bu bosqich oxirida `dist_tree[i][j]` har bir katakdan eng yaqin daraxtgacha bo'lgan Manhattan masofasini saqlaydi.

3.  **Maksimal `k` ni topish**:
    *   `max_k` nomli o'zgaruvchi `0` ga tenglashtiriladi. Bu topilishi mumkin bo'lgan eng katta rombning radiusini saqlaydi.
    *   Panjara bo'ylab har bir `(r, c)` katak tekshiriladi:
        *   Agar `grid[r][c]` bo'sh katak (`'.'`) bo'lsa:
            *   **Panjara chegarasi bo'yicha `k` ni hisoblash (`k_boundary`)**: `(r, c)` markazli rombning panjara ichida qolishi uchun maksimal `k` ni topamiz. Bu `min(r, N - 1 - r, c, M - 1 - c)` ga teng. Masalan, agar katak `(r,c)` panjaraning yuqori chetidan `r` qadam, pastki chetidan `N-1-r` qadam, chap chetidan `c` qadam va o'ng chetidan `M-1-c` qadam uzoqda bo'lsa, `k` shu qiymatlarning eng kichigidan oshmasligi kerak.
            *   **Daraxtdan uzoqlik bo'yicha `k` ni hisoblash (`current_k`)**: `dist_tree[r][c]` romb markazining daraxtdan uzoqligini bildiradi. Agar romb markazi `(r,c)` daraxtga tegmasligi kerak bo'lsa, rombning o'lchami `k` `dist_tree[r][c] - 1` dan katta bo'lmasligi kerak. Shu sababli, `current_k` ni `std::min(k_boundary, dist_tree[r][c] - 1)` deb olamiz.
            *   Agar `current_k` manfiy chiqsa (nazariy jihatdan bo'sh katak uchun `dist_tree` kamida 1 bo'lgani uchun bunday bo'lmasligi kerak, ammo ehtiyot chorasi), uni `0` ga tenglaymiz.
            *   `max_k` ni `current_k` va `max_k` ning maksimalligi bilan yangilaymiz.

4.  **Maksimal toshlar sonini hisoblash**:
    *   Topilgan `max_k` qiymatidan foydalanib, rombdagi toshlar soni `2 * max_k^2 + 2 * max_k + 1` formulasi bilan hisoblanadi. Natija `long long` turida saqlanadi, chunki `max_k` ning katta qiymatlarida kvadrat katta son berishi mumkin (garchi bu masala uchun `int` sig'adigan bo'lsa ham, `long long` xavfsizroq).
    *   Hisoblangan toshlar soni ekranga chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(N * M)
    *   Kiritmalarni o'qish va daraxtlarni navbatga qo'yish: `O(N*M)` vaqt oladi.
    *   Multi-source BFS: Har bir katak va har bir qirra (qo'shnilik aloqasi) BFS jarayonida ko'pi bilan bir marta ko'rib chiqiladi. `N x M` panjarada `N*M` ta katak va `4*N*M` atrofida qirralar mavjud. Shuning uchun BFS `O(N*M)` vaqt oladi.
    *   Maksimal `k` ni hisoblash: Har bir bo'sh katak uchun `O(1)` operatsiya bajariladi. Jami `O(N*M)` vaqt oladi.
    *   Umuman olganda, algoritming umumiy vaqt murakkabligi `O(N*M)` ni tashkil etadi. `N, M <= 5000` bo'lganligi sababli, `N*M` eng yomon holatda `2.5 * 10^7` ga yetadi, bu 4 soniya vaqt limitiga sig'adi.

-   **Xotira murakkabligi**: O(N * M)
    *   `grid` massivi panjara ma'lumotlarini saqlash uchun `O(N*M)` xotira talab qiladi.
    *   `dist_tree` massivi masofalarni saqlash uchun `O(N*M)` xotira talab qiladi.
    *   `q` navbati eng yomon holatda (agar barcha kataklar navbatga tushishi kerak bo'lsa) `O(N*M)` xotira talab qilishi mumkin.
    *   Umuman olganda, algoritming umumiy xotira murakkabligi `O(N*M)` ni tashkil etadi. `N, M <= 5000` bo'lganligi sababli, bu `2 * (5000 * 5000 * sizeof(int))` atrofida bo'lib, `2 * 2.5 * 10^7 * 4` bayt = `200 MB` ga yaqin bo'ladi, bu 512 MB xotira limitiga sig'adi.

## Kod izohi

```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun
#include <vector>   // Dinamik massivlar (vektorlar) uchun
#include <string>   // Satrlar bilan ishlash uchun
#include <queue>    // Navbat (queue) ma'lumot tuzilmasi uchun
#include <algorithm> // min, max kabi funksiyalar uchun

const int INF = 1e9; // Cheksizlik qiymati, masofalar uchun boshlang'ich holat

int main() {
    // I/O operatsiyalarini tezlashtirish
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M; // Bog' o'lchamlari
    std::cin >> N >> M;

    std::vector<std::string> grid(N); // Panjara ma'lumotlarini saqlovchi vektor
    // dist_tree: har bir katakdan eng yaqin daraxtgacha bo'lgan masofani saqlaydi
    std::vector<std::vector<int>> dist_tree(N, std::vector<int>(M, INF));
    std::queue<std::pair<int, int>> q; // Multi-source BFS uchun navbat

    // Panjarani o'qish va daraxtlarni BFS navbatiga qo'shish
    for (int i = 0; i < N; ++i) {
        std::cin >> grid[i]; // Joriy qatorni o'qish
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'T') { // Agar katakda daraxt bo'lsa
                dist_tree[i][j] = 0; // Unga masofa 0
                q.push({i, j});      // Navbatga qo'shish
            }
        }
    }

    // Qo'shni kataklarga o'tish uchun yo'nalishlar (yuqori, past, chap, o'ng)
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Multi-source BFS algoritmi
    while (!q.empty()) {
        std::pair<int, int> curr = q.front(); // Navbatdan katakni olish
        q.pop();                             // Olingan katakni o'chirish
        int r = curr.first;
        int c = curr.second;

        // 4 ta qo'shni katakni tekshirish
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i]; // Yangi qator indeksi
            int nc = c + dc[i]; // Yangi ustun indeksi

            // Agar qo'shni katak panjara chegaralari ichida bo'lsa
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                // Agar joriy yo'l orqali borish masofasi avvalgisidan qisqaroq bo'lsa
                if (dist_tree[nr][nc] > dist_tree[r][c] + 1) {
                    dist_tree[nr][nc] = dist_tree[r][c] + 1; // Masofani yangilash
                    q.push({nr, nc}); // Qo'shni katakni navbatga qo'shish
                }
            }
        }
    }

    int max_k = 0; // Topilgan eng katta rombning radiusi (o'lchami)

    // Har bir bo'sh katakni romb markazi deb hisoblab, maksimal k ni topish
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (grid[r][c] == '.') { // Agar katak bo'sh bo'lsa
                // k_boundary: rombning panjara chegarasidan chiqib ketmasligi uchun maksimal k
                int k_boundary = std::min({r, N - 1 - r, c, M - 1 - c});
                // current_k: k_boundary va daraxtdan uzoqlik bo'yicha cheklangan k
                // dist_tree[r][c] - 1: agar markaz (r,c) daraxtdan D masofada bo'lsa,
                // romb radiusi k ko'pi bilan D-1 bo'lishi mumkin (markaz daraxtga tegmasligi uchun)
                int current_k = std::min(k_boundary, dist_tree[r][c] - 1);
                
                // Agar hisoblangan k manfiy bo'lsa (ehtimol dist_tree[r][c] = 0 yoki 1 bo'lsa), uni 0 ga tenglash
                if (current_k < 0) { 
                    current_k = 0;
                }
                max_k = std::max(max_k, current_k); // Eng katta k ni yangilash
            }
        }
    }
    
    // Rombdagi toshlar sonini hisoblash formulasi: 2k^2 + 2k + 1
    // 2LL: natijaning long long turida hisoblanishini ta'minlaydi
    long long result_stones = 2LL * max_k * max_k + 2LL * max_k + 1LL;
    std::cout << result_stones << std::endl; // Natijani chiqarish

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
```

## Edge case lar va eslatmalar

*   **Rombning o'lchami `k`**: Masalada romb "radiusi" `k` deyiladi. `k=0` bo'lsa, romb faqat bitta markaziy katakdan iborat bo'ladi. `k=1` bo'lsa, markaz va unga qo'shni 4 ta katakdan iborat (jami 5 ta). `k=2` bo'lsa, 13 ta katak. Rombdagi toshlar soni `2k^2 + 2k + 1` formulasi bilan hisoblanadi.
*   **Bo'sh katak kafolati**: Masala shartida "Kamida bitta katak bo'sh ekanligi kafolatlanadi" deyilgan, shuning uchun hech qanday romb joylashtirish mumkin bo'lmagan holat (`max_k = 0` bo'lishi mumkin) ham kamida bitta tosh (markaz) joylashtirish imkonini beradi.
*   **`dist_tree[r][c] - 1` ning ma'nosi**: Ushbu qism rombning markazi `(r, c)` daraxtga tegmasligi uchun `k` radiusini cheklaydi. Agar `(r, c)` katakning eng yaqin daraxtgacha bo'lgan masofasi `D` bo'lsa, romb radiusi `k` `D-1` dan oshmasligi kerak. Aks holda, `k` radiusli rombning markazidan `D` masofadagi nuqtalari daraxtga to'g'ri kelishi mumkin. Test holatlari va AC olgan yechim shartni shu tarzda talqin qilganini ko'rsatadi. Aslida rombning *barcha* kataklari daraxtsiz bo'lishi kerak bo'lsa, yechim biroz murakkabroq bo'lar edi.
*   **`long long` dan foydalanish**: `max_k` ning maksimal qiymati `min(N, M)/2` atrofida bo'ladi, ya'ni `5000/2 = 2500` atrofida. Bunday `k` uchun `2k^2 + 2k + 1` qiymati `int` turiga sig'ishi mumkin (`2 * 2500^2 = 12.5 * 10^6`, bu `2 * 10^9` dan kichik). Biroq, `2LL * max_k * max_k` kabi `long long` literallarini ishlatish, agar `max_k` kelajakda yanada kattaroq bo'lishi mumkin bo'lgan masalalar uchun umumiyroq yechim yozishda xavfsizlikni ta'minlaydi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M070C) platformasidagi **M070C** raqamli **Aliens (O'zga sayyoraliklar)** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M070C>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M070C, Aliens (O'zga sayyoraliklar) yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
