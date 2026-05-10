# M091F — Kanji for king (王)

## Masala haqida
N ta tugunli daraxt berilgan. Sizning vazifangiz, berilgan daraxtda "Kanji for King" (王) shaklidagi nechta alohida (distinct) kichik daraxt (sub-daraxt) mavjudligini topishdan iborat. "Kanji for King" daraxti aniq 9 ta tugundan iborat bo'lib, markaziy tugun, ikkita oddiy shox va ikkita murakkab shoxdan tashkil topgan o'ziga xos tuzilishga ega (masala matnidagi rasmlarga qarang). Agar bitta sub-daraxtda qaysidir tugun mavjud bo'lsa, lekin boshqa sub-daraxtda bo'lmasa, ikkita sub-daraxt har xil hisoblanadi. Yakuniy natijani $10^9+7$ ga bo'lgandagi qoldiqni chop etish kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi – berilgan daraxtdagi har bir tugunni "Kanji for King" shaklining markaziy tuguni sifatida ko'rib chiqish va ushbu markaz atrofida shaklni qanchalik ko'p usulda yasash mumkinligini kombinatorik usullar bilan hisoblash. "Kanji for King" shakli aniq 9 ta tugundan iborat (1 ta markaz, 4 ta markazga ulangan tugun, 4 ta murakkab shoxning barg tugunlari). Shu sababli, biz har bir potensial markaziy tugun uchun uning atrofidagi qo'shnilaridan ikkitasini oddiy shox (simple arm) va ikkitasini murakkab shox (complex arm) sifatida tanlash usullari sonini topamiz. Kombinatorik hisoblashlar uchun $C(n, 2)$ (n elementdan 2 tasini tanlash usullari) formulasi va modular arifmetika qo'llaniladi.

## Algoritm qadamlari
1.  **Dastlabki sozlamalar va ma'lumotlarni o'qish:**
    *   `MOD = 10^9 + 7` va `INV2 = 500000004` (2 ning $10^9+7$ mod bo'yicha modular inversi) konstantalari e'lon qilinadi. `INV2` `C(n, 2) = n * (n-1) / 2` ni hisoblashda bo'lish amalini ko'paytirishga aylantirish uchun ishlatiladi.
    *   `nCr_2(n)` funksiyasi `n` dan 2 ta elementni tanlash usullari sonini `MOD` bo'yicha hisoblash uchun yoziladi. Agar `n < 2` bo'lsa, 0 qaytaradi.
    *   `N` (tugunlar soni) kiritiladi.
    *   Agar `N < 9` bo'lsa, "Kanji for King" shakli kamida 9 tugundan iborat bo'lgani uchun natija 0 bo'ladi va dastur tugatiladi.
    *   Daraxtning qo'shnilik ro'yxati (`adj`) va har bir tugunning darajasi (`deg`) massivlari yaratiladi. Tugunlar 1 dan `N` gacha raqamlanganligi sababli, massivlar `N+1` o'lchamda e'lon qilinadi.
    *   `N-1` ta qirralar o'qiladi va `adj` hamda `deg` massivlari to'ldiriladi.

2.  **Har bir tugunni markaziy tugun sifatida ko'rib chiqish:**
    *   `total_kanji_count` o'zgaruvchisi nolga tenglashtiriladi. Bu jami topilgan "Kanji for King" shakllari sonini saqlaydi.
    *   1 dan `N` gacha bo'lgan har bir `c` tugun uchun tsikl boshlanadi. Har bir `c` tugun "Kanji for King" shaklining markaziy tuguni bo'lishi mumkin deb faraz qilinadi.

3.  **Markaziy tugunning shartlarini tekshirish:**
    *   Agar `deg[c] < 4` bo'lsa, ya'ni `c` tugunining 4 tadan kam qo'shnisi bo'lsa, u markaziy tugun bo'la olmaydi. Chunki "Kanji for King" shaklida markaziy tugunga to'g'ridan-to'g'ri 4 ta shox ulanishi kerak. Bunday tugun tashlab ketiladi (`continue`).

4.  **Murakkab shoxlarni aniqlash va ulash usullarini hisoblash:**
    *   `sum_Wx`, `sum_Wx_sq` (murakkab shox nomzodlari uchun $C(kx,2)$ qiymatlarining yig'indisi va kvadratlari yig'indisi) va `complex_arm_candidate_count` (murakkab shox bo'lishga qodir qo'shnilar soni) o'zgaruvchilari nolga tenglashtiriladi.
    *   `c` tugunining har bir qo'shnisi `n` uchun tsikl boshlanadi:
        *   `kx = deg[n] - 1`: `n` tugunining `c` dan tashqari qo'shnilari soni hisoblanadi. Bu `n` murakkab shox bo'lsa, unga ulanishi mumkin bo'lgan barg tugunlar sonidir.
        *   Agar `kx >= 2` bo'lsa, `n` tuguni murakkab shox bo'lishi mumkin (chunki murakkab shoxdan ikkita barg tugun chiqishi kerak).
        *   `ways_for_k_children = nCr_2(kx)` hisoblanadi. Bu `n` murakkab shox bo'lsa, uning ikki barg tugunini tanlash usullari sonidir.
        *   `sum_Wx`, `sum_Wx_sq` va `complex_arm_candidate_count` shu qiymatlar bilan yangilanadi.

5.  **Ikkita alohida murakkab shoxni tanlash usullarini hisoblash:**
    *   Agar `complex_arm_candidate_count < 2` bo'lsa, ya'ni murakkab shox bo'lishga qodir qo'shnilar soni 2 tadan kam bo'lsa, yetarli murakkab shox nomzodlari yo'q. `c` tuguni markaz bo'la olmaydi. Tashlab ketiladi.
    *   Ikkita alohida murakkab shoxni tanlash va ularning barglarini ulash usullari soni (`ways_for_two_complex_arms_children`) quyidagi formula bo'yicha hisoblanadi: `((sum_Wx * sum_Wx - sum_Wx_sq + MOD) % MOD * INV2) % MOD`. Bu $\sum_{i<j} W_i W_j = ((\sum W_i)^2 - \sum W_i^2) / 2$ formulasining modular aritmetika bo'yicha ko'rinishidir.
    *   Agar `ways_for_two_complex_arms_children == 0` bo'lsa, bunday murakkab shox juftligi yo'q. Tashlab ketiladi.

6.  **Ikkita alohida oddiy shoxni tanlash usullarini hisoblash:**
    *   `c` tugunining jami qo'shnilaridan ikkitasi murakkab shox sifatida tanlab olingani sababli, qolgan `deg[c] - 2` ta qo'shnisi oddiy shox bo'lishga nomzoddir.
    *   `num_available_for_simple_arms = deg[c] - 2` hisoblanadi.
    *   Agar `num_available_for_simple_arms < 2` bo'lsa, yetarli oddiy shox nomzodlari yo'q. Tashlab ketiladi.
    *   `ways_for_simple_arms = nCr_2(num_available_for_simple_arms)` hisoblanadi. Bu qolgan nomzodlardan ikkita oddiy shoxni tanlash usullari sonidir.

7.  **Jami kanji shakllarini hisoblash:**
    *   Joriy `c` markaziy tuguni uchun jami "Kanji for King" shakllari soni `(ways_for_two_complex_arms_children * ways_for_simple_arms) % MOD` ga teng.
    *   Bu qiymat `total_kanji_count` ga qo'shib boriladi.

8.  **Natijani chop etish:**
    *   Barcha tugunlar markaz sifatida ko'rib chiqilgandan so'ng, `total_kanji_count` chop etiladi.

## Murakkablik tahlili
-   **Vaqt**: `O(N)`
    *   Daraxtni o'qish va darajalarni (degree) hisoblash `O(N)` vaqt oladi, chunki `N-1` ta qirra mavjud.
    *   Asosiy tsikl har bir `N` tugun uchun bir marta ishlaydi. Har bir tugun ichida uning qo'shnilari bo'ylab aylaniladi. Daraxtda barcha tugunlarning darajalari yig'indisi (`sum(deg[i])`) `2 * (N-1)` ga teng bo'lgani sababli, markaziy tsikldagi ichki hisoblashlar jami `O(N)` vaqtni oladi.
    *   `nCr_2` funksiyasi `O(1)` vaqtda ishlaydi.
    *   Shunday qilib, umumiy vaqt murakkabligi `O(N)` bo'ladi, bu `N = 10^5` uchun juda samarali va 1000 ms vaqt limitiga osongina sig'adi.
-   **Xotira**: `O(N)`
    *   Qo'shnilik ro'yxati (`std::vector<std::vector<int>> adj`) daraxtni saqlash uchun `O(N + M)` xotira talab qiladi, bu yerda `M` qirralar soni. Daraxtlar uchun `M = N-1` bo'lganligi sababli, bu `O(N)` ga teng.
    *   Darajalar massivi (`std::vector<int> deg`) `O(N)` xotira talab qiladi.
    *   Jami xotira murakkabligi `O(N)` bo'lib, `N = 10^5` uchun `32 MB` chekloviga osongina sig'adi.

## Kod izohi
*   **`MOD` va `INV2` konstantalari:**
    *   `const int MOD = 1e9 + 7;` : Barcha hisoblashlar uchun ishlatiladigan modul. Bu katta tub son bo'lib, natijaning haddan tashqari katta bo'lib ketishining oldini oladi.
    *   `const long long INV2 = 500000004;` : $1/2$ ning $MOD$ bo'yicha modular inversi. $C(n, k)$ formulalarida bo'lish amalini ko'paytirishga aylantirish uchun foydalaniladi. `(MOD + 1) / 2` orqali hisoblanadi.

*   **`long long nCr_2(long long n)` funksiyasi:**
    *   Ushbu yordamchi funksiya `n` elementdan 2 tasini tanlash usullari sonini (`n choose 2` yoki $C(n, 2)$) `MOD` bo'yicha hisoblaydi.
    *   Formula $C(n, 2) = \frac{n \times (n-1)}{2}$ bo'lib, bu yerda bo'lish amali (`/ 2`) modular aritmetikada `INV2` ga ko'paytirish bilan almashtiriladi: `(n * (n - 1) % MOD * INV2) % MOD`.
    *   Agar `n < 2` bo'lsa, 2 ta elementni tanlash mumkin emas, shuning uchun `0` qaytariladi.

*   **`main` funksiyasi:**
    *   `std::ios_base::sync_with_stdio(false); std::cin.tie(0);` : Kiritish va chiqarish (I/O) operatsiyalarini tezlashtirish uchun standart C++ optimizatsiyasi.
    *   **Boshlang'ich `N` tekshiruvi:** `if (N < 9)` bloki "Kanji for King" shaklini yasash uchun yetarli tugunlar bor-yo'qligini tekshiradi. Agar yo'q bo'lsa, `0` chiqariladi va dastur tugaydi.
    *   **Qo'shnilik ro'yxati va darajalarni hisoblash:**
        *   `std::vector<std::vector<int>> adj(N + 1);` : `N+1` o'lchamli adjacency list (qo'shnilik ro'yxati) e'lon qilinadi.
        *   `std::vector<int> deg(N + 1, 0);` : `N+1` o'lchamli darajalar massivi e'lon qilinadi.
        *   `N-1` ta qirra kiritiladi va har bir tugunning qo'shnilari `adj` ga qo'shiladi hamda darajalari `deg` da yangilanadi.
    *   **Asosiy hisoblash tsikli:**
        *   `for (int c = 1; c <= N; ++c)` : Har bir tugun `c` ni markaziy tugun deb hisoblaydi.
        *   `if (deg[c] < 4) { continue; }` : Agar markaziy tugunning darajasi 4 dan kam bo'lsa, u Kanji shaklini hosil qila olmaydi va keyingi tugunga o'tiladi.
        *   **Murakkab shoxlarni qayta ishlash:** Ushbu bo'lim `c` ning qo'shnilari orasidan murakkab shox bo'lishga qodir tugunlarni aniqlaydi.
            *   `long long kx = deg[n] - 1;` : `n` tugunining `c` dan tashqari qo'shnilari soni.
            *   `if (kx >= 2)` : Agar `kx` kamida 2 bo'lsa, `n` murakkab shox bo'lishi mumkin. `C(kx, 2)` hisoblanib, `sum_Wx` va `sum_Wx_sq` ga qo'shiladi.
        *   **Ikkita murakkab shoxni tanlash:** `ways_for_two_complex_arms_children` o'zgaruvchisi murakkab shox nomzodlari orasidan ikkita alohida murakkab shoxni tanlash va ularning barglarini ulash usullarini hisoblaydi. Bu hisob-kitob $\sum_{i<j} W_i W_j = ((\sum W_i)^2 - \sum W_i^2) / 2$ formulasiga asoslangan.
        *   **Ikkita oddiy shoxni tanlash:** `deg[c] - 2` tugunlari (murakkab shoxlar uchun tanlangan 2 ta tugundan keyin) oddiy shox nomzodlari hisoblanadi. Ulardan 2 tasini tanlash usullari `nCr_2(num_available_for_simple_arms)` orqali hisoblanadi.
        *   **Umumiy hisobga qo'shish:** Joriy `c` markaziy tuguni uchun topilgan `ways_for_two_complex_arms_children` va `ways_for_simple_arms` ko'paytmasi `total_kanji_count` ga qo'shiladi.
    *   Dastur oxirida `total_kanji_count` ni chop etadi.

## Edge case lar va eslatmalar
*   **Minimal tugunlar soni:** "Kanji for King" shakli aniq 9 ta tugundan iborat bo'lgani sababli, agar berilgan daraxt `N < 9` tugunga ega bo'lsa, hech qanday shakl topilmaydi. Kod bu holatni boshida tekshirib, `0` chop etadi.
*   **Markaziy tugunning darajasi:** Markaziy tugun shaklan 4 ta shoxga ega bo'lishi kerak. Shuning uchun, uning darajasi kamida 4 bo'lishi shart.
*   **Murakkab shoxlarning tuzilishi:** Murakkab shox sifatida tanlangan tugunning markaziy tugundan tashqari kamida 2 ta qo'shnisi bo'lishi kerak. Bu qo'shnilar murakkab shoxning "barg" tugunlari vazifasini bajaradi. Agar bu shart bajarilmasa, u tugun murakkab shox bo'la olmaydi.
*   **Modular aritmetika:** Natija juda katta son bo'lishi mumkinligi sababli, barcha oraliq hisoblashlar `10^9 + 7` modulida amalga oshiriladi. (`A - B + MOD) % MOD` shaklida manfiy natijalarning oldini olish muhim.
*   **Tugun raqamlash:** Tugunlar 1 dan `N` gacha raqamlangan, shuning uchun massivlar (masalan, `adj` va `deg`) 0-indeksdan foydalanmaslik uchun `N+1` o'lchamda e'lon qilingan.
*   **Sub-daraxtlar farqi:** Masalada ikki sub-daraxt bir-biridan, agar bittasida qaysidir tugun mavjud bo'lsa, lekin boshqasida bo'lmasa, farqli hisoblanishi aytilgan. Bizning yondashuvimiz har bir markaziy tugun atrofida hosil bo'lishi mumkin bo'lgan har bir noyob 9 tugunli to'plamni sanash orqali bu shartni qanoatlantiradi, chunki har xil kombinatsiyalar doimo tugunlarning har xil to'plamiga olib keladi.
