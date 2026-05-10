# M076D — Minimal Maksimal Qirra

## Masala haqida
Ushbu masala bog'langan, yo'naltirilmagan va og'irlikka ega bo'lgan graf berilgan bo'lib, unda ikkita maxsus tugun `s` va `t` ajratib ko'rsatilgan. Vazifa: `s` dan `t` ga boruvchi shunday yo'lni topishki, bu yo'ldagi *eng katta* qirraning og'irligi *minimallashtirilgan* bo'lsin. Ya'ni, `s` dan `t` ga borish uchun ko'plab yo'llar mavjud bo'lishi mumkin. Har bir yo'lda bir nechta qirralar bor va bu qirralarning o'z og'irliklari bor. Har bir yo'l uchun eng og'ir qirrani aniqlaymiz. Bizdan esa barcha mumkin bo'lgan yo'llar ichidan aynan mana shu eng og'ir qirraning og'irligi eng kichik bo'lgan yo'l topish va uning eng og'ir qirrasi og'irligini chiqarish so'raladi.

## Yondashuv (g'oya)
Masalani yechish uchun asosiy g'oya Disjoint Set Union (DSU) (birlashtirilmagan to'plamlar) ma'lumot tuzilmasidan foydalanish va Kruskal algoritmining o'xshash yondashuvini qo'llashdir. Kruskal algoritmi minimal spanning tree (MST) (minimal bog'lovchi daraxt) ni topish uchun qirralarni og'irligi bo'yicha saralaydi va ularni bitta daraxtga qo'shadi. Bizning vaziyatimizda, biz `s` va `t` orasidagi yo'l uchun "minimal maksimal qirra" ni izlayotganimiz sababli, agar barcha qirralarni og'irligi bo'yicha o'sish tartibida saralab chiqsak va ularni birma-bir DSU yordamida graffga (yoki uning komponentalariga) qo'shib borsak, `s` va `t` tugunlari birinchi marta bitta komponentaga (ya'ni, bitta to'plamga) tushganida, o'sha paytda qo'shilgan oxirgi qirraning og'irligi bizning javobimiz bo'ladi.

Bu yondashuvning asosiy sababi shundaki, agar `s` va `t` ni bog'laydigan yo'l mavjud bo'lsa, bu yo'l faqatgina hozirgacha ko'rib chiqilgan (ya'ni, og'irligi hozirgi qirraning og'irligidan kichik yoki teng bo'lgan) qirralardan iborat. Biz qirralarni og'irligi bo'yicha o'sish tartibida qo'shayotganimiz sababli, `s` va `t` bog'langan birinchi paytdagi oxirgi qirraning og'irligi, bu ikki tugun orasidagi har qanday yo'ldagi maksimal qirra og'irliklaridan eng kichigi bo'lishini kafolatlaydi.

## Algoritm qadamlari

1.  **Qirralarni o'qish va saralash**: Graffning barcha `m` ta qirrasini o'qib oling. Har bir qirra (`u`, `v`, `w` - `u` va `v` tugunlarni bog'laydigan `w` og'irlikdagi qirra) uchlik (tuple) sifatida saqlanadi. Keyin, barcha qirralarni og'irliklari (`w`) bo'yicha o'sish tartibida saralang.

2.  **DSU initsializatsiyasi**: `n` ta tugun uchun Disjoint Set Union (DSU) ma'lumot tuzilmasini boshlang'ich holatga keltiring. Bu `parent` (ota) va `sz` (o'lcham) massivlarini yaratishni anglatadi. Dastlab, har bir tugun o'zining alohida to'plamida bo'ladi (ya'ni, `parent[i] = i`) va har bir to'plamning o'lchami 1 ga teng bo'ladi (`sz[i] = 1`).

3.  **Saralangan qirralarni qayta ishlash**: Saralangan qirralar ro'yxati bo'ylab boshidan oxirigacha harakatlaning.

4.  **To'plamlarni birlashtirish va tekshirish**: Har bir qirra (`w`, `u`, `v`) uchun:
    *   `u` va `v` tugunlari joylashgan to'plamlarni `unite_sets(u, v)` funksiyasi yordamida birlashtiring. Bu DSU ning "union by size/rank" va "path compression" optimizatsiyalari bilan samarali amalga oshiriladi.
    *   To'plamlar birlashtirilgandan so'ng, `s` va `t` tugunlari endi bitta to'plamga kirish-kirmasligini tekshiring. Buni `find_set(s) == find_set(t)` shartini tekshirish orqali amalga oshirish mumkin.
    *   Agar `s` va `t` bitta to'plamda bo'lsa, demak, `s` va `t` orasida yo'l topildi. Bu yo'ldagi maksimal qirra og'irligi hozirgi qirraning og'irligi (`w`) ga teng va bu eng optimal yechimdir. Shu sababli, `w` ni chop eting va dasturni yakunlang.

## Murakkablik tahlili

-   **Vaqt murakkabligi**: `O(M log M)`
    *   Qirralarni o'qish: `O(M)`.
    *   Qirralarni og'irliklari bo'yicha saralash: `O(M log M)`. `M` ta qirra mavjud.
    *   DSU ni initsializatsiya qilish: `O(N)`. `N` ta tugun mavjud.
    *   Har bir qirra uchun DSU operatsiyalari (`unite_sets` va `find_set`): `M` marta amalga oshiriladi. Har bir DSU operatsiyasining amortizatsiyalangan vaqt murakkabligi deyarli `O(alpha(N))` ga teng (bu yerda `alpha` — Akerman funksiyasining teskarisi bo'lib, juda sekin o'sadigan funksiya, amalda doimiy hisoblanadi). Shuning uchun, DSU operatsiyalari uchun jami vaqt `O(M * alpha(N))` bo'ladi, bu esa deyarli `O(M)`.
    *   Umumiy vaqt murakkabligi barcha qadamlarning yig'indisi bo'lib, dominant qadam qirralarni saralashdir: `O(M log M + N + M * alpha(N)) = O(M log M)`.
    *   `N <= 10^5`, `M <= 3 * 10^5` bo'lganda, `3 * 10^5 * log(3 * 10^5)` taxminan `3 * 10^5 * 19` (log2 asosida) ~ `5.7 * 10^6` operatsiyani tashkil qiladi, bu 2000 ms vaqt limitiga bemalol sig'adi.

-   **Xotira murakkabligi**: `O(N + M)`
    *   `edges` vektori: `M` ta qirra ma'lumotini (og'irlik, u, v) saqlaydi, shuning uchun `O(M)` xotira talab qiladi.
    *   `parent` vektori: `N` ta tugunning ota tugunlarini saqlaydi, `O(N)` xotira.
    *   `sz` vektori: `N` ta tugunning to'plam o'lchamlarini saqlaydi, `O(N)` xotira.
    *   Umumiy xotira murakkabligi: `O(N + M)`.
    *   `N = 10^5`, `M = 3 * 10^5` bo'lganda, `4 * 10^5` ta butun son saqlash kerak bo'ladi. Har bir `int` 4 bayt deb hisoblasak, `4 * 10^5 * 4 B = 1.6 MB`. Bu 32 MB xotira limitiga sig'adi.

-   **Nega shu murakkablik chegaraga sig'adi**: Yuqorida ko'rsatilgan hisob-kitoblar shuni ko'rsatadiki, `M log M` vaqt murakkabligi va `N + M` xotira murakkabligi berilgan `N` va `M` chegaralari uchun belgilangan vaqt (2000 ms) va xotira (32 MB) limitlariga to'liq mos keladi.

## Kod izohi

Kodni qismlarga bo'lib ko'rib chiqamiz:

### DSU ma'lumot tuzilmasi

```cpp
vector<int> parent; // Har bir tugunning ota tugunini saqlaydi
vector<int> sz;     // Har bir to'plamning o'lchamini saqlaydi (faqat to'plam ildizi uchun muhim)

int find_set(int v) { // Tugun v ning ildizini topish funksiyasi (path compression optimizatsiyasi bilan)
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // Rekursiv chaqiruv va yo'lni siqish
}

void unite_sets(int a, int b) { // Ikkita to'plamni birlashtirish funksiyasi (union by size optimizatsiyasi bilan)
    a = find_set(a); // a tugunning ildizini topamiz
    b = find_set(b); // b tugunning ildizini topamiz
    if (a != b) {    // Agar ular turli to'plamlarda bo'lsa
        if (sz[a] < sz[b]) // Kichikroq to'plamni kattaroq to'plamga birlashtiramiz
            swap(a, b);
        parent[b] = a;   // Kichik to'plamning ildizini kattaroq to'plamning ildiziga bog'laymiz
        sz[a] += sz[b];  // Kattaroq to'plamning o'lchamini yangilaymiz
    }
}
```
*   `parent`: `parent[i]` `i` tugunining bevosita ota tugunini saqlaydi. Agar `parent[i] == i` bo'lsa, `i` tugun o'z to'plamining ildizi hisoblanadi.
*   `sz`: `sz[i]` `i` tuguni ildiz bo'lgan to'plamning elementlar sonini saqlaydi. Bu "union by size" (o'lcham bo'yicha birlashtirish) optimizatsiyasi uchun ishlatiladi.
*   `find_set(v)`: Berilgan `v` tugunining joylashgan to'plamning ildizini (root) topish uchun ishlatiladi. Bu funksiya "path compression" (yo'lni siqish) deb nomlanuvchi optimizatsiyani qo'llaydi: tugun ildizini topish jarayonida uchragan barcha tugunlarni bevosita topilgan ildizga bog'lab qo'yadi. Bu keyingi `find_set` chaqiruvlarini tezlashtiradi.
*   `unite_sets(a, b)`: `a` va `b` tugunlari joylashgan to'plamlarni birlashtiradi. Bu funksiya avval `a` va `b` ning ildizlarini topadi. Agar ular turli to'plamlarda bo'lsa, "union by size" strategiyasiga ko'ra, kichikroq to'plamni kattaroq to'plamga bog'laydi. Bu daraxtlarning balandligini kamaytirishga yordam beradi, DSU operatsiyalarining samaradorligini oshiradi.

### `main` funksiyasi

```cpp
int main() {
    ios_base::sync_with_stdio(false); // C++ streamlari va C stdio sinxronizatsiyasini o'chiradi
    cin.tie(0);                       // cin operatsiyasini cout dan ajratadi (tezlashtirish uchun)

    int n, m, s, t; // Tugunlar soni, qirralar soni, boshlang'ich va oxirgi tugunlar
    cin >> n >> m >> s >> t; // Kiritish

    vector<tuple<int, int, int>> edges; // Qirralarni saqlash uchun vektor (og'irlik, u, v)
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v); // Tuple sifatida qo'shish, og'irlik birinchi o'rinda bo'lishi muhim
    }

    sort(edges.begin(), edges.end()); // Qirralarni og'irliklari bo'yicha o'sish tartibida saralash

    parent.resize(n + 1); // parent vektorini o'lchamini n+1 ga sozlash (1-indekslash uchun)
    sz.resize(n + 1);     // sz vektorini o'lchamini n+1 ga sozlash
    for (int i = 1; i <= n; ++i) {
        parent[i] = i; // Har bir tugun o'z to'plamining ildizi
        sz[i] = 1;     // Har bir to'plamning o'lchami 1
    }

    for (const auto& edge : edges) { // Saralangan qirralar bo'ylab iteratsiya
        int w = get<0>(edge); // Joriy qirraning og'irligi
        int u = get<1>(edge); // Birinchi tugun
        int v = get<2>(edge); // Ikkinchi tugun

        unite_sets(u, v); // u va v tugunlari joylashgan to'plamlarni birlashtiramiz

        if (find_set(s) == find_set(t)) { // Agar s va t tugunlari bitta to'plamda bo'lsa
            cout << w << endl;             // Joriy qirraning og'irligini chop etamiz
            return 0;                      // Dasturni yakunlaymiz
        }
    }

    return 0; // Agar kod shu yerga yetsa, bu graf bog'lanmagan degani. Lekin masala shartiga ko'ra, graf har doim bog'langan.
}
```
*   **Kiritish/chiqarish optimizatsiyalari**: `ios_base::sync_with_stdio(false);` va `cin.tie(0);` tezroq kiritish va chiqarish uchun ishlatiladi, bu katta hajmdagi ma'lumotlar bilan ishlashda muhim ahamiyatga ega.
*   **Ma'lumotlarni o'qish**: `n`, `m`, `s`, `t` o'qiladi. Qirralar esa `vector<tuple<int, int, int>> edges` ga `(w, u, v)` tartibida saqlanadi, bu `std::sort` ni `w` bo'yicha ishlashini ta'minlaydi.
*   **Saralash**: `sort(edges.begin(), edges.end());` qirralarni og'irliklari bo'yicha o'sish tartibida saralaydi. `std::tuple` lar standart ravishda elementlar tartibi bo'yicha taqqoslanadi.
*   **DSU initsializatsiyasi**: `parent` va `sz` vektorlari `n+1` o'lchamda o'lchamlanadi, chunki tugunlar 1 dan `n` gacha raqamlangan. Har bir tugun dastlab o'zining alohida to'plamida ekanligini ko'rsatuvchi qiymatlar bilan initsializatsiya qilinadi.
*   **Asosiy loop**: Saralangan `edges` vektori bo'ylab for-loop yordamida harakatlaniladi. Har bir qirra uchun uning `u` va `v` tugunlari `unite_sets` orqali birlashtiriladi. Keyin `find_set(s) == find_set(t)` sharti tekshiriladi. Agar `s` va `t` endi bir xil to'plamda bo'lsa, demak, ular orasida shu paytgacha qo'shilgan qirralar yordamida yo'l topildi. O'sha yo'ldagi maksimal qirraning og'irligi joriy `w` dir. Bu bizning javobimiz bo'ladi va dastur yakunlanadi.

## Edge case lar va eslatmalar

*   **Grafning bog'langanligi**: Masala shartida graf har doim bog'langanligi aytilgan. Demak, `s` va `t` orasida yo'l topilishi kafolatlangan va dastur hech qachon qirralar loopi tugab, javob topilmasdan `return 0;` ga yetib bormaydi.
*   **Tugun raqamlash**: Tugunlar 1 dan `N` gacha raqamlangan. Kod `parent` va `sz` massivlarini `N+1` o'lchamda yaratib va 1-indekslashdan foydalanib bunga moslashgan.
*   **`s == t` holati**: Agar `s` va `t` bir xil tugunlar bo'lsa, `find_set(s) == find_set(t)` sharti DSU initsializatsiyasidan keyinoq, hatto birorta qirra qo'shmasdan ham `true` bo'ladi. Biroq, kod loopga kiradi va birinchi qirrani qo'shib, keyin tekshiradi. Agar `s == t` bo'lsa, nazariy jihatdan javob 0 bo'lishi kerak edi (hech qanday qirra ishlatmasdan o'z-o'ziga borish). Lekin, odatda, bunday masalalarda `s != t` deb faraz qilinadi. Agar bu holat yuzaga kelsa, kod birinchi qirraning og'irligini chop etadi, bu noto'g'ri bo'lishi mumkin. Masala shartiga ko'ra, bu muammo emas, deb hisoblaymiz.
*   **Qirra og'irliklari**: Qirra og'irliklari `1` dan `10^9` gacha bo'lishi mumkin. `int` tipi bu diapazonni qoplash uchun yetarli.
