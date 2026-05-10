---
title: "R094D — Teleportatsiya | Robocontest.uz Yechimi"
description: "Robocontest.uz R094D (Teleportatsiya) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Matrix. Vaqt limiti: 2000 ms, xotira: 64 MB."
keywords: "robocontest R094D, Teleportatsiya yechimi, robocontest Teleportatsiya, R094D c++ kod, matrix, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /R094D_teleportatsiya/
lang: uz
---

# R094D — Teleportatsiya

## Masala haqida
Nyuboy "Teleport" o'yinini o'ynayapti, u `n` ta bosqichdan iborat. Uning maqsadi `n`-bosqichga yetib borish. Nyuboy `i`-bosqichda turganida, keyingi `k` ta bosqichdan biriga (ya'ni `i+1, i+2, ..., i+k`) teleportatsiya qila oladi. U o'yinni 1-bosqichdan boshlaydi. Masala Nyuboyning `n`-bosqichga yetib borish variantlar sonini `10^9 + 7` ga bo'lgandagi qoldig'ini topishni so'raydi.

## Yondashuv (g'oya)
Masalani yechish uchun dinamik dasturlash (Dynamic Programming - DP) yondashuvidan foydalanamiz. `dp[i]` ni `i`-bosqichga yetib borish usullari soni deb belgilasak, Nyuboy `i`-bosqichga `i-1, i-2, ..., i-k` bosqichlarning har biridan bir qadamda kelishi mumkin. Shunday qilib, asosiy rekurrent formula quyidagicha bo'ladi:
`dp[i] = dp[i-1] + dp[i-2] + ... + dp[i-k]`
Bu formula `i-k >= 1` bo'lgan holatlarda to'g'ri keladi. Agar `i-j < 1` bo'lsa, `dp[i-j]` ni 0 deb olamiz (yoki faqat 1-bosqichdan kelgan holatni hisoblaymiz).

`n` juda katta (`10^15` gacha) bo'lishi mumkinligi sababli, oddiy DP O(N) vaqtda ishlamaydi. Biroq, `k` qiymati nisbatan kichik (`100` gacha). Bu holatda biz rekurrent formulani matritsa darajasi (Matrix Exponentiation) orqali hisoblashimiz mumkin.

Yaxshilangan rekurrent formula quyidagicha keltirib chiqariladi:
`dp[i] = dp[i-1] + dp[i-2] + ... + dp[i-k]`
`dp[i-1] = dp[i-2] + dp[i-3] + ... + dp[i-k-1]`
Birinchi tenglamadan ikkinchisini ayirsak:
`dp[i] - dp[i-1] = dp[i-1] - dp[i-k-1]`
`dp[i] = 2 * dp[i-1] - dp[i-k-1]`
Bu rekurrent formula `i >= k+2` bo'lgan holatlarda amal qiladi. Biz bu formuladan matritsa darajasi yordamida `dp[n]` ni hisoblash uchun foydalanamiz.

## Algoritm qadamlari
1.  **Dastlabki holatlar (`N` kichik bo'lganda)**:
    *   Agar `N_val = 1` bo'lsa, Nyuboy allaqachon 1-bosqichda, shuning uchun 1 usul bor.
    *   Agar `N_val <= K_val + 1` bo'lsa, bu degani `N_val - 1 <= K_val`. Ya'ni, har bir `i` bosqichdan `j` bosqichga o'tishda, `j-i` har doim `K_val` dan oshmaydi. Bu holatda rekurrent formula soddalashadi:
        `dp[1] = 1`
        `dp[2] = dp[1] = 1`
        `dp[i] = dp[1] + dp[2] + ... + dp[i-1]` (chunki barcha `i-j` lar `K_val` ichiga kiradi)
        `dp[i] = dp[i-1] + (dp[1] + ... + dp[i-2]) = dp[i-1] + dp[i-1] = 2 * dp[i-1]` ( `i >= 3` uchun)
        Shuning uchun `dp[i] = 2^(i-2)` ( `i >= 2` uchun). Bu holatda `power(2, N_val - 2)` funksiyasi chaqiriladi.
2.  **Matritsa darajasi yordamida hisoblash (`N_val > K_val + 1` bo'lganda)**:
    *   `K_val + 1` o'lchamli o'tish matritsasini (transition matrix) hosil qilamiz.
    *   Holat vektori `V_t = [dp[t], dp[t-1], ..., dp[t-K_val]]^T` shaklida bo'ladi.
    *   `dp[t+1]` ni hisoblash uchun `T` matritsaning birinchi qatori `[2, 0, ..., 0, -1]` bo'ladi, bu `dp[t+1] = 2 * dp[t] - dp[t-K_val]` rekurrent formulasini aks ettiradi (`-1` modulo `MOD - 1` ga teng).
    *   Qolgan qatorlar shunchaki siljishni amalga oshiradi: `dp[t-j]` dan `dp[t-(j-1)]` ga o'tkazish uchun `T.mat[i][i-1] = 1` bo'ladi.
    *   Dastlabki holat vektorini `V_{K_val+1} = [dp[K_val+1], dp[K_val], ..., dp[1]]^T` tuzamiz. Bu qiymatlar 1-qadamdagi `dp[i] = 2^(i-2)` formulasi yordamida hisoblanadi.
    *   Biz `V_{N_val}` ni topishimiz kerak, shuning uchun o'tish matritsasini `(N_val - (K_val + 1))` darajasiga ko'taramiz: `T_pow = T^(N_val - (K_val + 1))`.
    *   Yakuniy natija `V_{N_val} = T_pow * V_{K_val+1}` vektorining birinchi elementi (`dp[N_val]`) bo'ladi.
    *   Barcha hisob-kitoblar `MOD = 10^9 + 7` bo'yicha modulyar arifmetika qoidalariga rioya qilgan holda amalga oshiriladi.

## Murakkablik tahlili
-   **Vaqt**: `O((K+1)^3 * log N)`
    *   Matritsa o'lchami `(K+1) x (K+1)`.
    *   Ikkita `(K+1) x (K+1)` matritsani ko'paytirish `O((K+1)^3)` vaqt oladi.
    *   Matritsa darajasi `log N` marta matritsani ko'paytirishni talab qiladi (binar darajaga oshirish usuli - binary exponentiation).
    *   `K_val <= 100` bo'lganligi sababli, matritsa o'lchami eng ko'pi bilan `101 x 101` bo'ladi. `(101)^3` taxminan `10^6` ni tashkil qiladi.
    *   `N <= 10^15` bo'lgani uchun `log N` taxminan `log_2(10^15) ~= 15 * log_2(10) ~= 15 * 3.32 ~= 50` ga teng.
    *   Jami vaqt murakkabligi `10^6 * 50 = 5 * 10^7` operatsiyadan iborat bo'ladi, bu 2 soniya vaqt chegarasiga sig'adi.
-   **Xotira**: `O((K+1)^2)`
    *   Matritsalarni saqlash uchun `(K+1) x (K+1)` o'lchamli xotira talab qilinadi.
    *   `K_val <= 100` bo'lganligi sababli, `(101)^2` taxminan `10^4` elementni tashkil qiladi. Har bir element `long long` bo'lgani uchun `8` bayt joy egallaydi.
    *   Jami xotira `10^4 * 8` bayt = `80 KB` atrofida bo'ladi, bu 64 MB xotira chegarasiga sig'adi.

## Kod izohi

### Global o'zgaruvchilar va modulyar arifmetika
```cpp
long long N_val, K_val;
long long MOD = 1e9 + 7;
```
`N_val` va `K_val` kirish qiymatlarini saqlash uchun. `MOD` esa modulyar qoldiqni hisoblash uchun ishlatiladigan konstanta (`10^9 + 7`).

### `Matrix` strukturasi
```cpp
struct Matrix {
    vector<vector<long long>> mat;
    int size;

    Matrix(int s) : size(s) {
        mat.assign(s, vector<long long>(s, 0));
    }

    static Matrix identity(int s) { /* ... */ }

    Matrix operator*(const Matrix& other) const { /* ... */ }
};
```
Bu struktura kvadrat matritsalarni ifodalaydi.
*   Konstruktor `Matrix(int s)`: `s x s` o'lchamli nol matritsani yaratadi.
*   `static Matrix identity(int s)`: `s x s` o'lchamli birlik matritsasini (diagonalida 1, boshqa joylarida 0 bo'lgan matritsa) qaytaradi. Birlik matritsasi ko'paytirishda neytral element hisoblanadi.
*   `Matrix operator*(const Matrix& other) const`: Matritsani ko'paytirish amalini ortiqcha yuklaydi (overload). Ikki matritsani ko'paytiradi va natijani qaytaradi. Har bir ko'paytirish va qo'shish amali `MOD` ga bo'lingan holda amalga oshiriladi. Shuni unutmang, bu matritsa ko'paytirish `(K+1)^3` murakkablikka ega.

### Matritsani darajaga oshirish funksiyasi (`matrix_pow`)
```cpp
Matrix matrix_pow(Matrix base, long long exp) {
    Matrix res = Matrix::identity(base.size); // Natija matritsasi birlik matritsa sifatida boshlanadi
    
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base; // Agar daraja toq bo'lsa, natijani asosga ko'paytiramiz
        base = base * base;                // Asosni kvadratga oshiramiz
        exp /= 2;                          // Darajani ikkiga bo'lamiz
    }
    return res;
}
```
Bu funksiya matritsani `exp` darajaga oshirish uchun binar darajaga oshirish (binary exponentiation) usulini qo'llaydi. `log(exp)` marta matritsa ko'paytirish amalga oshiriladi.

### Sonni darajaga oshirish funksiyasi (`power`)
```cpp
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD; // Asosni MOD ga bo'lingan qoldig'ini olamiz
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD; // Agar daraja toq bo'lsa, natijani asosga ko'paytiramiz
        base = (base * base) % MOD;                // Asosni kvadratga oshiramiz
        exp /= 2;                                  // Darajani ikkiga bo'lamiz
    }
    return res;
}
```
Bu funksiya `base` sonini `exp` darajaga oshirish uchun binar darajaga oshirish usulini qo'llaydi. `matrix_pow` dan farqli o'laroq, bu funksiya oddiy sonlar bilan ishlaydi va kichik `N` holatlari uchun `2^(N-2)` ni hisoblashda ishlatiladi.

### Asosiy logika (`main` funksiyasi)
```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N_val >> K_val;

    if (N_val == 1) { // 1-bosqich - bazis holat
        cout << 1 << endl;
        return 0;
    }

    if (N_val <= K_val + 1) { // N kichik bo'lganda maxsus holat
        cout << power(2, N_val - 2) << endl;
        return 0;
    }

    // N_val > K_val + 1 bo'lgan holat - matritsa darajasi
    int mat_size = K_val + 1;
    Matrix T(mat_size); // O'tish matritsasi

    // O'tish matritsasini qurish
    // Birinchi qator: dp[t+1] = 2*dp[t] - dp[t-K_val]
    T.mat[0][0] = 2;              // dp[t] uchun koeffitsient
    T.mat[0][K_val] = MOD - 1;    // dp[t-K_val] uchun koeffitsient (-1)

    // Qolgan qatorlar: holatni siljitish
    for (int i = 1; i < mat_size; ++i) {
        T.mat[i][i-1] = 1; // dp[t-j] -> dp[t-(j-1)]
    }

    // Dastlabki holat vektorini (V_{K_val+1}) qurish
    vector<long long> initial_vec(mat_size);
    initial_vec[K_val] = 1; // dp[1]
    
    // dp[j] = 2^(j-2) formulasidan foydalanib
    for (int i = K_val - 1; i >= 0; --i) {
        initial_vec[i] = power(2, (K_val + 1 - i) - 2);
    }

    // Matritsani N_val - (K_val+1) darajaga oshirish
    long long exponent = N_val - (K_val + 1);
    Matrix T_pow = matrix_pow(T, exponent);

    // Yakuniy javobni hisoblash
    long long ans = 0;
    for (int i = 0; i < mat_size; ++i) {
        ans = (ans + T_pow.mat[0][i] * initial_vec[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
```
*   **Tezlashtirish**: `ios_base::sync_with_stdio(false); cin.tie(0);` - C++ oqimlarini tezlashtirish uchun standart optimizatsiya.
*   **`N_val == 1` holati**: Agar `N_val` 1 ga teng bo'lsa, Nyuboy allaqachon maqsad bosqichda. Shuning uchun 1 usul bor.
*   **`N_val <= K_val + 1` holati**: Bu erda `N_val` `K_val` ga nisbatan kichik. Yuqorida tushuntirilganidek, `dp[i] = 2^(i-2)` formula qo'llaniladi (N=2 dan boshlab). `power` funksiyasi yordamida hisoblanadi.
*   **Matritsa darajasi holati**: Agar `N_val > K_val + 1` bo'lsa, matritsa darajasi ishlatiladi.
    *   `mat_size = K_val + 1`: Holat vektorining o'lchami.
    *   **O'tish matritsasi `T`**: `dp[t+1] = 2 * dp[t] - dp[t-K_val]` rekurrent formulasiga mos keladigan matritsa yaratiladi. Birinchi qator `dp[t]` uchun 2 va `dp[t-K_val]` uchun -1 (ya'ni `MOD - 1`) koeffitsientlarini o'z ichiga oladi. Qolgan qatorlar pastki diagonaldagi 1 lar bilan holat vektorini siljitishni ta'minlaydi.
    *   **Dastlabki holat vektori `initial_vec`**: `V_{K_val+1} = [dp[K_val+1], dp[K_val], ..., dp[1]]^T` vektorini hosil qilamiz. `dp[1]` esa `initial_vec` ning oxirgi elementi bo'ladi. Qolgan `dp` qiymatlari (2 dan `K_val+1` gacha) `dp[i] = 2^(i-2)` formulasi yordamida hisoblanadi.
    *   **Daraja `exponent`**: Biz `V_{K_val+1}` dan `V_{N_val}` ga o'tishimiz kerak, bu esa `N_val - (K_val + 1)` qadamni talab qiladi.
    *   **Hisoblash**: `T` matritsa `exponent` darajaga oshiriladi (`T_pow`). Keyin `T_pow` matritsasining birinchi qatorini `initial_vec` bilan dot product qilib, `dp[N_val]` ning qiymati topiladi.

## Edge case lar va eslatmalar
*   **Modulyar arifmetika**: `10^9 + 7` moduli bo'yicha hisoblashlar har bir qo'shish va ko'paytirish amali bajarilgandan so'ng amalga oshirilishi shart. Ayniqsa, `MOD - 1` ishlatilishi `(A - B) % MOD` ni `(A - B + MOD) % MOD` kabi hisoblash kerakligini anglatadi, bu `A - B` natijasi manfiy bo'lsa to'g'ri ishlaydi.
*   **`K_val` ning kichikligi**: Matritsa darajasi faqat `K_val` kichik bo'lganda samarali ishlaydi. Agar `K_val` katta bo'lsa, matritsa juda katta bo'lib, vaqt chegarasiga sig'maydi.
*   **DP bazis holatlari**: `N_val <= K_val + 1` holatining to'g'ri aniqlanishi va `dp[i] = 2^(i-2)` ning to'g'ri qo'llanilishi muhim. DP ni boshidan boshlab qo'lda hisoblab ko'rish bu bazis holatlarning to'g'riligini tasdiqlashga yordam beradi.
*   **Indekslar bilan ehtiyot bo'lish**: Matritsa va vektor indekslari, ayniqsa `dp[t-K_val]` kabi atamalar bilan ishlaganda (ular vektorning qaysi indeksiga to'g'ri kelishi) diqqat talab qiladi. Kodda `initial_vec[i]` ning `dp[K_val + 1 - i]` ga mos kelishi to'g'ri qabul qilingan.
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/R094D) platformasidagi **R094D** raqamli **Teleportatsiya** masalasi. U **Matrix** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/R094D>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest R094D, Teleportatsiya yechimi, robocontest masalalari, c++17, olimpiada yechimi, matrix, dasturlash uzbek, competitive programming O'zbekiston.</sub>
