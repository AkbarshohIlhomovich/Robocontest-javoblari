---
title: "M071E — Two Trees (Ikki daraxt) | Robocontest.uz Yechimi"
description: "Robocontest.uz M071E (Two Trees (Ikki daraxt)) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 512 MB."
keywords: "robocontest M071E, Two Trees (Ikki daraxt) yechimi, robocontest Two Trees (Ikki daraxt), M071E c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M071E_two_trees_ikki_daraxt/
lang: uz
---

# M071E — Two Trees (Ikki daraxt)

## Masala haqida
Ushbu masalada bizga $N$ ta tugunli ikkita ildizli daraxt berilgan. Birinchi daraxtning ildizi $r_1$, ikkinchi daraxtniki esa $r_2$. $S_1(v)$ deb birinchi daraxtda $r_1$ dan $u$ tuguniga boradigan yoʻl $v$ tugunidan oʻtadigan barcha $u$ tugunlar toʻplamiga aytiladi. Bu, aslida, $v$ tugunining birinchi daraxtdagi ost-daraxtidir. Xuddi shunday, $S_2(v)$ ikkinchi daraxtdagi $v$ tugunining ost-daraxtini bildiradi. Bizdan har bir $1 \le v \le N$ tugun uchun $S_1(v) \cap S_2(v)$ toʻplam kesishmalarining oʻlchamini topish talab qilinadi.

## Yondashuv (g'oya)
Masala har bir $v$ tuguni uchun ikkala daraxtda ham $v$ ning ost-daraxtida joylashgan $u$ tugunlari sonini topishni so'raydi.

Daraxtda $u$ tuguni $v$ tugunining ost-daraxtida ekanligini samarali tekshirish uchun Depth First Search (DFS — chuqurlik bo'yicha qidiruv) algoritmidan foydalanish mumkin. DFS jarayonida har bir tugun uchun ikkita muhim qiymatni hisoblaymiz:
1.  `tin[x]` (entry time — kirish vaqti): DFS tugunga birinchi marta kirgan vaqt.
2.  `sz[x]` (subtree size — ost-daraxt hajmi): $x$ tuguni o'z ichiga olgan ost-daraxtdagi tugunlar soni.

Agar $u$ tuguni $v$ tugunining ost-daraxtida bo'lsa (yoki $u=v$ bo'lsa), u holda quyidagi shart bajariladi:
`tin[v] <= tin[u]` va `tin[u] < tin[v] + sz[v]`.

Shunday qilib, har bir $v$ tuguni uchun biz quyidagi shartlarni qanoatlantiruvchi $u$ tugunlari sonini topishimiz kerak:
1.  `tin1[v] <= tin1[u] < tin1[v] + sz1[v]` (birinchi daraxtda $u$ $v$ ning ost-daraxtida)
2.  `tin2[v] <= tin2[u] < tin2[v] + sz2[v]` (ikkinchi daraxtda $u$ $v$ ning ost-daraxtida)

Bu masala 2D sohadagi nuqtalarni sanash (2D range counting) muammosiga aylanadi. Har bir $u$ tugunini $(tin1[u], tin2[u])$ koordinatali nuqta sifatida qaraymiz. Har bir $v$ tuguni uchun esa biz ushbu nuqtalardan $(tin1[v], tin2[v])$ va $(tin1[v] + sz1[v] - 1, tin2[v] + sz2[v] - 1)$ burchaklari bilan cheklangan to'g'ri to'rtburchak ichiga tushadiganlarini sanashimiz kerak.

Bunday turdagi masalalarni samarali hal qilish uchun "sweep-line" (sudrab o'tish chizig'i) algoritmi Fenwick Tree (BIT — Binary Indexed Tree, binar indekslangan daraxt) bilan birgalikda ishlatiladi.

## Algoritm qadamlari
1.  **Daraxtlarni qurish:** Kiritilgan $p_1$ va $p_2$ massivlaridan foydalanib, ikkita daraxtning qo'shnilik ro'yxatlarini (adjacency lists) `adj1` va `adj2` hosil qilamiz.
2.  **DFS yordamida `tin` va `sz` hisoblash:**
    *   Birinchi daraxtning ildizi $r_1$ dan boshlab DFS ni amalga oshiramiz. Bu jarayonda har bir $u$ tuguni uchun `tin1[u]` (kirish vaqti) va `sz1[u]` (ost-daraxt hajmi) qiymatlarini hisoblaymiz.
    *   `timer_dfs` hisoblagichini nolga qaytaramiz (chunki ikkinchi daraxt uchun `tin` qiymatlari birinchisidan mustaqil bo'lishi kerak).
    *   Ikkinchi daraxtning ildizi $r_2$ dan boshlab yana bir DFS ni amalga oshiramiz va har bir $u$ tuguni uchun `tin2[u]` va `sz2[u]` qiymatlarini hisoblaymiz.
3.  **Hodisalarni (events) shakllantirish:** Biz barcha $N$ ta tugun uchun nuqtalarni qo'shish va so'rovlarni bajarish uchun hodisalar ro'yxatini (`events` vektori) tuzamiz.
    *   **Nuqta qo'shish hodisalari (ADD_POINT):** Har bir $u$ tuguni uchun $(tin1[u], tin2[u])$ nuqtasini ifodalovchi hodisa yaratamiz. Bu hodisaning turi `0` (ADD_POINT) bo'ladi, `x = tin1[u]`, `y = tin2[u]`, `weight = 1`.
    *   **So'rov hodisalari (QUERY):** Har bir $v$ tuguni uchun uning ost-daraxtlarining kesishmasida nechta tugun borligini hisoblash uchun so'rovlar yaratamiz. Bu so'rov $2D$ to'rtburchak ichidagi nuqtalarni sanashga teng. $2D$ inklyuziya-eksklyuziya prinsipidan foydalanib, har bir $v$ tuguni uchun to'rtta so'rov hodisasi yaratamiz. $v$ ning birinchi daraxtdagi ost-daraxti `X` o'qi bo'yicha $[tin1[v], tin1[v] + sz1[v] - 1]$ oralig'ini, ikkinchi daraxtdagi ost-daraxti esa `Y` o'qi bo'yicha $[tin2[v], tin2[v] + sz2[v] - 1]$ oralig'ini tashkil qiladi.
        *   `f(X, Y)` funksiyasi $x \le X$ va $y \le Y$ shartlarini qanoatlantiruvchi nuqtalar sonini ifodalasa, to'rtburchakdagi nuqtalar soni $f(X_2, Y_2) - f(X_1-1, Y_2) - f(X_2, Y_1-1) + f(X_1-1, Y_1-1)$ formula bilan topiladi. Shu formuladagi har bir $f(\cdot, \cdot)$ chaqirig'i uchun bitta `QUERY` hodisasi yaratiladi, tegishli `x` koordinatasi, `y` chegarasi va `weight` (+1 yoki -1) bilan.
4.  **Hodisalarni saralash:** Barcha `ADD_POINT` va `QUERY` hodisalarini `x` koordinatasi bo'yicha o'sish tartibida saralaymiz. Agar `x` koordinatalari teng bo'lsa, `ADD_POINT` hodisalari `QUERY` hodisalaridan oldin qayta ishlanishi uchun `type` bo'yicha saralaymiz (0 < 1). Bu shu `x` koordinatasidagi nuqtalarning Fenwick Treega avval qo'shilishini, keyin esa shu `x` koordinatasidagi so'rovlarning bajarilishini ta'minlaydi.
5.  **Sweep-line algoritmini Fenwick Tree bilan bajarish:**
    *   Saralangan hodisalar ro'yxati bo'yicha iteratsiya qilamiz.
    *   Agar hodisa `ADD_POINT` bo'lsa (`event.type == 0`): `event.y` (ya'ni `tin2[u]`) qiymatini `event.weight` (+1) bilan Fenwick Treega qo'shamiz (`bit_update(event.y, event.weight)`).
    *   Agar hodisa `QUERY` bo'lsa (`event.type == 1`): Fenwick Tree yordamida `1` dan `event.y` gacha bo'lgan yig'indini so'raymiz (`bit_query(event.y)`). Bu natijani `event.weight` (+1 yoki -1) ga ko'paytirib, `ans[event.node_idx]` (bu yerda `event.node_idx` so'rov qaysi $v$ tuguniga tegishli ekanligini bildiradi) ga qo'shamiz.
6.  **Natijani chiqarish:** `ans` massividagi $N$ ta natijani 1 dan $N$ gacha tartibda chop etamiz.

## Murakkablik tahlili
*   **Vaqt murakkabligi**: `O(N log N)`
    *   Adjacency listlarni qurish: `O(N)`.
    *   Ikki marta DFS (har biri `O(N)`): Jami `O(N)`.
    *   Hodisalarni yaratish: $N$ ta `ADD_POINT` hodisasi va har bir $N$ ta $v$ tuguni uchun maksimal to'rtta `QUERY` hodisasi. Jami `O(N)` hodisa.
    *   Hodisalarni saralash: `O(N log N)`.
    *   Sweep-line algoritmi: Har bir hodisa uchun Fenwick Treeda bitta `update` yoki `query` operatsiyasi bajariladi. Har bir operatsiya `O(log N)` vaqt oladi. Jami `O(N log N)`.
    *   Umumiy hisobda: `O(N log N)`. $N = 3 \cdot 10^5$ bo'lganda, $N \log N$ taxminan $5.4 \cdot 10^6$ operatsiyani tashkil etadi, bu 1000 ms vaqt chegarasiga sig'adi.
*   **Xotira murakkabligi**: `O(N)`
    *   `adj1`, `adj2` (qo'shnilik ro'yxatlari): `O(N)` (har bir qirra ikki marta saqlanadi).
    *   `tin1`, `sz1`, `tin2`, `sz2`: `O(N)`.
    *   `bit` (Fenwick Tree): `O(N)`.
    *   `events` (hodisalar ro'yxati): `O(N)` (maksimal 5N ta hodisa).
    *   `ans`: `O(N)`.
    *   Umumiy hisobda: `O(N)`. $N = 3 \cdot 10^5$ bo'lganda, bir nechta $N$ hajmli int massivlari taxminan bir necha MB xotira talab qiladi, bu 512 MB chegarasiga sig'adi.

## Kod izohi

*   `const int MAXN = 300005;`: Tugunlarning maksimal soni uchun konstanta.
*   `std::vector<int> adj1[MAXN], adj2[MAXN];`: Ikkala daraxt uchun qo'shnilik ro'yxatlari.
*   `int tin1[MAXN], sz1[MAXN], tin2[MAXN], sz2[MAXN];`: Har bir tugunning kirish vaqti (`tin`) va ost-daraxt hajmini (`sz`) saqlash uchun massivlar.
*   `int timer_dfs;`: DFS paytida vaqt hisoblagichi.
*   `void dfs_tree(int u, int p, const std::vector<int> adj[], int tin[], int sz[])`: Rekursiv DFS funksiyasi.
    *   `tin[u] = ++timer_dfs;`: Tugunning kirish vaqtini belgilaydi.
    *   `sz[u] = 1;`: Tugunning o'zini hisobga olib, ost-daraxt hajmini 1 ga o'rnatadi.
    *   Bolalar tugunlari bo'ylab iteratsiya qilib, rekursiv chaqiruvlar qiladi va bolalar ost-daraxtlarining hajmini joriy tugunnikiga qo'shadi.
*   `int bit[MAXN]; int bit_max_coord;`: Fenwick Tree massivi va undagi maksimal indeks.
*   `void bit_update(int idx, int delta)`: Fenwick Treeda `idx` indeksidagi qiymatga `delta`ni qo'shadi.
*   `int bit_query(int idx)`: Fenwick Treeda 1 dan `idx` gacha bo'lgan qiymatlar yig'indisini qaytaradi.
*   `struct Event { ... };`: Sweep-line algoritmi uchun hodisalarni ifodalovchi struktura. `x`, `type`, `node_idx`, `y`, `weight` maydonlariga ega. `operator<` overloadingi hodisalarni avval `x`, so'ng `type` bo'yicha saralashni ta'minlaydi.
*   `long long ans[MAXN];`: Har bir tugun uchun yakuniy javoblarni saqlovchi massiv. `long long` qilib e'lon qilingan, garchi $N$ (3e5) intga sig'sa ham, xavfsizlik uchun.
*   `main` funksiyasi:
    *   `std::ios_base::sync_with_stdio(false); std::cin.tie(0);`: Tezkor kiritish/chiqarish uchun optimizatsiyalar.
    *   `N, r1, r2` qiymatlari o'qiladi.
    *   `bit_max_coord = N;`: Fenwick Tree maksimal indeksini `N` ga o'rnatadi, chunki `tin` qiymatlari 1 dan `N` gacha bo'ladi.
    *   $p_1$ va $p_2$ massivlaridan `adj1` va `adj2` qo'shnilik ro'yxatlari quriladi. `p = -1` bo'lsa, bu ildiz tuguni ekanligini bildiradi va uning ota-onasi yo'q.
    *   Ikkala daraxt uchun `dfs_tree` funksiyasi chaqiriladi. Ikkinchi DFS dan oldin `timer_dfs` nolga qaytariladi.
    *   Barcha `ADD_POINT` va `QUERY` hodisalari `events` vektoriga qo'shiladi. `QUERY` hodisalari inklyuziya-eksklyuziya prinsipiga asosan $2D$ to'rtburchak so'rovlarini ifodalaydi. `X1-1` va `Y1-1` qiymatlari 0 dan kichik bo'lmasligi uchun shartlar qo'yilgan.
    *   `events` vektori saralanadi.
    *   Saralangan `events` bo'ylab iteratsiya qilinib, `ADD_POINT` lar uchun `bit_update` va `QUERY` lar uchun `bit_query` chaqiriladi, natijalar `ans` massiviga qo'shiladi.
    *   Yakuniy javoblar formatlangan holda (sonlar orasida bo'sh joy, oxirgisidan keyin yo'q) chop etiladi.

## Edge case lar va eslatmalar
*   **1-indekslanish:** Masala va yechim tugunlarni 1 dan $N$ gacha indekslaydi. DFS natijalari va Fenwick Tree ham 1-indeksli bo'lib ishlatiladi. `tin1[v] - 1` kabi qiymatlar eng kamida 0 bo'lishi mumkin. `bit_query(0)` 0 ni qaytarishi kerak.
*   **DFS `p` parametri:** DFS funksiyasida `p` (ota tugun) parametri yo'naltirilmagan daraxtlarda cheksiz tsikllarning oldini oladi.
*   **`timer_dfs` ni nolga qaytarish:** Ikkinchi daraxt uchun DFS ni ishga tushirishdan oldin `timer_dfs` ni qayta nolga o'rnatish muhimdir, chunki `tin1` va `tin2` qiymatlari bir-biridan mustaqil bo'lishi kerak.
*   **Optimal I/O:** `std::ios_base::sync_with_stdio(false); std::cin.tie(0);` qatorlari C++ oqimlarining standart kirish/chiqarish operatsiyalarini tezlashtirish uchun ishlatiladi, bu katta hajmdagi kiritish/chiqarishga ega bo'lgan raqobatbardosh dasturlash masalalarida muhim.
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M071E) platformasidagi **M071E** raqamli **Two Trees (Ikki daraxt)** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M071E>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M071E, Two Trees (Ikki daraxt) yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
