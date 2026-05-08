# A0014 — Ketma-ketlik yig'indisi

## Masala haqida
Bu masala `T_n = n^2 - (n-1)^2` formulasi bilan berilgan ketma-ketlikning dastlabki `n` ta hadi yig'indisini (`S_n`) hisoblashni talab qiladi. `S_n` ning qiymatini `10^9 + 7` ga bo'lgandagi qoldig'ini topish kerak. `N` soni juda katta bo'lishi mumkin (`10^{16}` gacha), testlar soni esa `T` (1 dan 10 gacha) bilan cheklangan.

## Yondashuv (g'oya)
Masalaning yechimi ikki asosiy g'oyaga tayanadi:
1.  **Algebraik soddalashtirish**: `T_n` formulasini soddalashtirish orqali uning aniq shaklini topish va keyin `S_n` yig'indisini hisoblash uchun aniq formula hosil qilish.
2.  **Modulyar arifmetika**: `N` ning juda katta qiymati tufayli `N^2` ni to'g'ridan-to'g'ri hisoblash `long long` turidan ham oshib ketishi mumkin. Shu sababli, yakuniy natijani `10^9 + 7` ga bo'lgandagi qoldiqni topishda modulyar arifmetika qoidalaridan foydalanish zarur.

## Algoritm qadamlari
1.  **`T_n` ni soddalashtirish**:
    `T_n = n^2 - (n-1)^2` formulasini algebraik jihatdan soddalashtiramiz.
    `T_n = n^2 - (n^2 - 2n + 1)`
    `T_n = n^2 - n^2 + 2n - 1`
    `T_n = 2n - 1`

2.  **`S_n` ni topish**:
    `S_n = T_1 + T_2 + T_3 + \dots + T_n` ekanligini bilgan holda, `T_n = 2n-1` formulasini o'rniga qo'yamiz:
    `S_n = (2 \cdot 1 - 1) + (2 \cdot 2 - 1) + (2 \cdot 3 - 1) + \dots + (2n - 1)`
    `S_n = 1 + 3 + 5 + \dots + (2n - 1)`
    Bu birinchi `n` ta toq sonning yig'indisidir. Matematikada ma'lumki, birinchi `n` ta toq sonning yig'indisi `n^2` ga teng.
    Demak, `S_n = N^2`.

3.  **Modulyar arifmetika yordamida natijani hisoblash**:
    Bizdan `S_n` ning `10^9 + 7` ga bo'lgandagi qoldig'ini topish talab qilingan. `S_n = N^2` bo'lgani uchun, biz `N^2 \pmod{10^9+7}` ni hisoblashimiz kerak.
    Modulyar arifmetikaning asosiy xossasidan foydalanamiz: `(A \cdot B) \pmod M = ((A \pmod M) \cdot (B \pmod M)) \pmod M`.
    Bu yerda `A = N`, `B = N`, `M = 10^9 + 7`.
    Shunday qilib, `(N \cdot N) \pmod{MOD} = ((N \pmod{MOD}) \cdot (N \pmod{MOD})) \pmod{MOD}`.
    Avval `N` ni `MOD` ga bo'lgandagi qoldiqni topamiz (`N_mod = N % MOD`). Bu qiymat `MOD` dan kichik bo'ladi (taxminan `10^9`).
    Keyin `N_mod \cdot N_mod` ni hisoblaymiz. Bu qiymat maksimal `(10^9)^2 = 10^{18}` atrofida bo'ladi, bu esa C++ dagi `long long` (odatda `~9 \cdot 10^{18}` gacha) turiga sig'adi.
    Nihoyat, `(N_mod \cdot N_mod)` ni yana `MOD` ga bo'lgandagi qoldiqni topamiz.

## Murakkablik tahlili
-   **Vaqt**: `O(T)`
    Har bir test holati uchun faqat bir nechta arifmetik amallar bajariladi (ikkita modulo operatsiyasi va bitta ko'paytirish). Bu amallar doimiy vaqtda (ya'ni `O(1)`) bajariladi. `T` ta test holati bo'lgani sababli, umumiy vaqt murakkabligi `O(T)` bo'ladi. `T` ning maksimal qiymati 10 bo'lganligi sababli, bu yechim juda tez ishlaydi.
-   **Xotira**: `O(1)`
    Dastur faqatgina bir nechta o'zgaruvchilarni (masalan, `T`, `N`, `N_mod`, `result`) saqlash uchun xotira ishlatadi. Bu o'zgaruvchilar soni `N` ning qiymatiga bog'liq emas va doimiy. Shu sababli, xotira murakkabligi `O(1)` hisoblanadi.
-   **Nega shu murakkablik chegaraga sig'adi**:
    Yuqoridagi soddalashtirishlar tufayli, har bir test holati uchun faqatgina `N` ni o'qib, uni `MOD` ga bo'lib, natijani kvadratga oshirib, yana `MOD` ga bo'lish kerak bo'ladi. Bu operatsiyalar juda tez bajariladi va berilgan vaqt (`1000 ms`) hamda xotira (`16 MB`) chegaralariga bemalol sig'adi.

## Kod izohi

### Modul konstantasi
```cpp
const long long MOD = 1e9 + 7; // 10^9 + 7
```
Bu qator modulyar arifmetika operatsiyalarida ishlatiladigan `10^9 + 7` sonini `MOD` nomli `const long long` turidagi o'zgarmas (konstanta) sifatida belgilaydi. Konstanta ishlatish kodni yanada o'qishli qiladi va xatoliklarni kamaytiradi. `10^9 + 7` ko'p hollarda ishlatiladigan tub sondir.

### Kirish/chiqishni optimallashtirish
```cpp
ios_base::sync_with_stdio(false);
cin.tie(0);
```
Ushbu ikki qator C++ standart kirish/chiqish (I/O) oqimlarini ( `cin`, `cout`) optimallashtiradi. `ios_base::sync_with_stdio(false)` C++ standart kutubxonasining I/O oqimlarini C tilining standart I/O oqimlari bilan sinxronizatsiyani o'chiradi. `cin.tie(0)` esa `cin` operatsiyasidan oldin `cout` buferini tozalashni bekor qiladi. Bu katta hajmdagi kirish ma'lumotlari bilan ishlashda dastur ish vaqtini sezilarli darajada qisqartirishi mumkin.

### Test holatlarini qayta ishlash
```cpp
int T;
cin >> T; // Test holatlari sonini o'qiymiz

while (T--) {
    long long N;
    cin >> N; // Har bir test holati uchun N sonini o'qiymiz
    // ... hisoblashlar ...
    cout << result << "\n"; // Natijani alohida qatorda chiqaramiz
}
```
Dastur avval test holatlari soni `T` ni o'qiydi. So'ngra `while (T--)` tsikli yordamida har bir test holati uchun takroriy hisoblashlarni amalga oshiradi. Har bir iteratsiyada `N` qiymati o'qiladi va hisoblangan natija yangi qatorga (`\n`) chiqariladi.

### `S_n` ni hisoblash va modulyar arifmetika
```cpp
// Masaladagi ketma-ketlikni soddalashtiramiz:
// ... (izohlar `T_n` va `S_n` soddalashganini ko'rsatadi) ...
// Demak, S_n = N^2.

long long N_mod = N % MOD; // N ni MOD ga bo'lgandagi qoldiqni hisoblaymiz.
long long result = (N_mod * N_mod) % MOD; // N_mod^2 ni MOD ga bo'lgandagi qoldiqni hisoblaymiz.
```
Kodning ushbu qismida yuqorida tushuntirilgan algebraik soddalashtirish va modulyar arifmetika qo'llaniladi.
1.  `N % MOD` yordamida `N` ning `MOD` ga bo'lgandagi qoldig'i topiladi va `N_mod` o'zgaruvchisiga saqlanadi. Bu qiymat hech qachon `MOD` dan oshmaydi, ya'ni `10^9 + 7` dan kichik bo'ladi.
2.  `N_mod * N_mod` hisoblanadi. Maksimal `N_mod` qiymati `MOD-1` bo'lishi mumkin, shuning uchun `(MOD-1)^2` taxminan `(10^9)^2 = 10^{18}` ga teng bo'ladi. Bu qiymat `long long` turiga sig'adi.
3.  Ushbu ko'paytmadan chiqqan natija yana `MOD` ga bo'linib, qoldiq `result` o'zgaruvchisiga saqlanadi. Bu yakuniy natijadir.

## Edge case lar va eslatmalar
*   **`N=1` holati**: Agar `N=1` bo'lsa, `S_1 = T_1 = 1^2 - (1-1)^2 = 1`. Bizning formula bo'yicha `S_1 = 1^2 = 1`. `1 \pmod{10^9+7} = 1`. Natija to'g'ri.
*   **`N` ning kattaligi**: `N` `10^{16}` gacha bo'lishi mumkin. Bu `long long` turiga sig'adi, ammo `N^2` `10^{32}` bo'lib, `long long` (maks. `~9 \cdot 10^{18}`) dan oshib ketadi. Shuning uchun `(N % MOD) * (N % MOD) % MOD` yondashuvi juda muhim. Agar bu qoida e'tiborga olinmasa, `overflow` (qiymatning turga sig'masligi) sodir bo'lib, xato natijalarga olib kelishi mumkin.
*   **Modulning tub sonligi**: `10^9 + 7` tub son hisoblanadi. Garchi bu masala uchun unchalik kritik bo'lmasa-da, ko'plab modulyar arifmetika masalalarida (masalan, modulyar inversiya, Fermatning kichik teoremasi) modulning tub sonligi muhim rol o'ynaydi. Bu yerda esa faqat modulyar ko'paytirish qoidasidan foydalanilgan.
