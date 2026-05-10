---
title: "M074D — Xor va summa | Robocontest.uz Yechimi"
description: "Robocontest.uz M074D (Xor va summa) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M074D, Xor va summa yechimi, robocontest Xor va summa, M074D c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M074D_xor_va_summa/
lang: uz
---

# M074D — Xor va summa

## Masala haqida
Bu masala `L` soni berilganda, ikkita `a` va `b` butun sonlari juftliklari sonini topishni talab qiladi. Bu juftliklar ikki shartni qanoatlantirishi kerak: `a + b <= L` va `a + b = a XOR b`. `L` soni binar qator shaklida beriladi va juda katta bo'lishi mumkin (2^100001 gacha). Javobni `10^9+7` ga bo'lgandagi qoldiqni chop etish kerak.

## Yondashuv (g'oya)
Masalaning yechimi bitlar bo'yicha dinamik dasturlash (Digit DP) g'oyasiga asoslangan. Avvalo, `a + b = a XOR b` shartini tahlil qilamiz. Binary arifmetika qoidasiga ko'ra, `a + b = (a XOR b) + 2 * (a AND b)` tengligi mavjud. Shartga ko'ra `a + b = a XOR b` bo'lishi uchun, `2 * (a AND b)` ifodasi `0` ga teng bo'lishi kerak. Bu esa `a AND b = 0` degan ma'noni anglatadi.

`a AND b = 0` sharti har qanday bit pozitsiyasida `a` va `b` ning tegishli bitlari bir vaqtning o'zida `1` bo'la olmasligini bildiradi. Ya'ni, har bir bit pozitsiyasi uchun `(a_i, b_i)` juftligi `(0,0)`, `(0,1)` yoki `(1,0)` bo'lishi mumkin, ammo `(1,1)` bo'la olmaydi.
Endi masala `a AND b = 0` va `a XOR b <= L` shartlarini qanoatlantiradigan juftliklar sonini topishga o'zgaradi. `L` sonining kattaligi sababli, uning binar ko'rinishidagi bitlar bo'ylab iteratsiya qilib, dinamik dasturlash usuli qo'llaniladi.

## Algoritm qadamlari
1.  **Shartni soddalashtirish**: Yuqorida tushuntirilganidek, `a + b = a XOR b` sharti `a AND b = 0` shartiga teng ekanligi aniqlanadi. Demak, biz `a AND b = 0` va `a XOR b <= L` shartlarini qanoatlantiradigan juftliklarni topishimiz kerak.
2.  **Dinamik dasturlash holati (DP state)**:
    *   `dp[idx][tight]` — bu `idx` (joriy bit pozitsiyasi, chapdan o'ngga, eng muhim bitdan boshlab) dan oxirigacha `a` va `b` ni qurish mumkin bo'lgan usullar sonini saqlaydigan massiv.
    *   `idx`: joriy bit pozitsiyasi (0 dan `N-1` gacha, bu yerda `N` - `L` ning binar qator uzunligi).
    *   `tight` (qattiqlik): mantiqiy flag.
        *   `true` bo'lsa, bu degani `a XOR b` ning hozirgacha hosil bo'lgan prefiksi `L` ning prefiksi bilan *aynan bir xil*. Shu sababli, joriy `idx` bitida `a XOR b` ning qiymati `L` ning `idx`-bitidan oshib ketmasligi kerak.
        *   `false` bo'lsa, bu degani `a XOR b` ning hozirgacha hosil bo'lgan prefiksi `L` ning prefiksidan *allaqachon kichik*. Bu holatda, kelajakdagi bitlar uchun `L` ning cheklovlari mavjud emas.
3.  **Boshlang'ich holat (Base case)**: Agar `idx == N` bo'lsa (barcha bitlar qayta ishlangan bo'lsa), bu bitta to'g'ri juftlik topilganini bildiradi, shuning uchun `1` qaytariladi.
4.  **Memoizatsiya**: Agar `dp[idx][tight]` allaqachon hisoblangan bo'lsa (qiymati `-1` emas), saqlangan natija qaytariladi.
5.  **O'tishlar (Transitions)**: `solve(idx, tight)` funksiyasida joriy `idx` bit pozitsiyasi uchun `a_idx` va `b_idx` bitlarini tanlash kerak.
    *   `limit_L_digit`: `a XOR b` ning `idx`-bitidagi maksimal qiymat. Agar `tight` `true` bo'lsa, bu `L_str[idx]` (raqamga o'tkazilgan) ga teng bo'ladi. Aks holda (`tight` `false` bo'lsa), `1` ga teng bo'ladi (chunki `a XOR b` allaqachon `L` dan kichik bo'lgani sababli, `0` yoki `1` ni tanlash mumkin).
    *   Biz `a_idx AND b_idx = 0` shartini qanoatlantiradigan `(a_idx, b_idx)` juftliklarini tanlaymiz: `(0,0)`, `(0,1)`, `(1,0)`.
    *   **Holat 1: `a_idx = 0, b_idx = 0`**:
        *   Bu holatda `a_idx XOR b_idx = 0`.
        *   Bu tanlov har doim mumkin, chunki `0 <= limit_L_digit`.
        *   Yangi `tight` holati: `tight && (0 == limit_L_digit)`. Agar `tight` `true` bo'lib, `L_str[idx]` `0` bo'lsa, keyingi bosqichda ham `tight` `true` bo'ladi. Agar `L_str[idx]` `1` bo'lsa, `tight` `false` bo'ladi (chunki `a XOR b` hozir `0` bo'lib, `L_str[idx]` `1` bo'lgani uchun allaqachon kichikroq bo'ldi).
        *   `ans` ga `solve(idx + 1, new_tight)` ni qo'shamiz.
    *   **Holat 2: `a_idx = 0, b_idx = 1` yoki `a_idx = 1, b_idx = 0`**:
        *   Bu holatda `a_idx XOR b_idx = 1`.
        *   Bu tanlov faqat `1 <= limit_L_digit` bo'lsa mumkin. Ya'ni, agar `L_str[idx]` `1` bo'lsa yoki biz allaqachon `not tight` holatda bo'lsak.
        *   Agar mumkin bo'lsa, yangi `tight` holati: `tight && (1 == limit_L_digit)`. Agar `tight` `true` bo'lib, `L_str[idx]` `1` bo'lsa, keyingi bosqichda ham `tight` `true` bo'ladi. (Agar `L_str[idx]` `0` bo'lsa, bu holatga kirmaymiz).
        *   Bu `a XOR b = 1` holatiga erishishning 2 xil usuli mavjud: `(0,1)` va `(1,0)`. Shuning uchun `ans` ga `2 * solve(idx + 1, new_tight)` ni qo'shamiz.
6.  **Modul arifmetika**: Har bir yig'indini `10^9+7` moduliga bo'lish orqali amalga oshiramiz, chunki javob juda katta bo'lishi mumkin.

## Murakkablik tahlili
-   **Vaqt**: `dp` jadvalining o'lchami `N * 2` (bu yerda `N` - `L` ning binar qator uzunligi). Har bir `dp` holatini hisoblash doimiy vaqt (bir nechta arifmetik amallar va rekursiv chaqiruvlar) oladi. Shuning uchun umumiy vaqt murakkabligi `O(N)`. `N` ning maksimal qiymati 100,001 bo'lgani sababli, bu `100,001` ga yaqin operatsiyani bildiradi, bu 1000 ms vaqt limitiga bemalol sig'adi.
-   **Xotira**: `dp` jadvali `N * 2` o'lchamda `long long` tipli elementlarni saqlaydi. Shuning uchun xotira murakkabligi `O(N)`. `N = 100,001` bo'lganda, `100,001 * 2 * sizeof(long long)` (ya'ni, `100,001 * 2 * 8` bayt = taxminan 1.6 MB) xotira talab qilinadi, bu 32 MB xotira limitiga bemalol sig'adi.
-   Nega shu murakkablik chegaraga sig'adi: Berilgan `N` (100001) qiymati uchun `O(N)` vaqt va xotira murakkabligi yuqoridagi hisob-kitoblarga ko'ra, belgilangan limitlarga to'liq mos keladi.

## Kod izohi

### Standard kutubxonalarni kiritish va global o'zgaruvchilar
```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun
#include <string>   // String ma'lumot turlari uchun
#include <cstring>  // memset funksiyasi uchun (DP jadvalini -1 bilan to'ldirish)

using namespace std;

long long dp[100001][2]; // Dinamik dasturlash jadvali.
                         // dp[idx][tight]: idx-bitdan boshlab, tight sharti ostida hisoblangan usullar soni.
string L_str;            // L sonining binar qator ko'rinishi.
int N;                   // L_str uzunligi.
const long long MOD = 1e9 + 7; // Modulo qiymati.
```
Bu qismda kerakli kutubxonalar kiritiladi va `dp` jadvali, `L_str`, `N` va `MOD` kabi global o'zgaruvchilar e'lon qilinadi. `dp` jadvalining o'lchami `L` ning maksimal uzunligini (100001) hisobga olgan holda tanlangan.

### `solve` rekursiv funksiyasi
```cpp
long long solve(int idx, bool tight) {
    // Boshlang'ich holat: Agar barcha bitlar qayta ishlangan bo'lsa, bitta to'g'ri yo'l topildi.
    if (idx == N) {
        return 1; 
    }
    // Memoizatsiya: Agar bu holat avval hisoblangan bo'lsa, saqlangan natijani qaytar.
    if (dp[idx][tight] != -1) {
        return dp[idx][tight];
    }

    long long ans = 0;
    // Joriy bit pozitsiyasidagi a XOR b summasi uchun yuqori chegarani aniqlash.
    // Agar tight true bo'lsa, sum_bit L_str[idx] dan oshmasligi kerak.
    // Agar tight false bo'lsa, sum_bit 0 yoki 1 bo'lishi mumkin (L dan allaqachon kichik, shuning uchun istalgan bit yaxshi).
    int limit_L_digit = (tight ? (L_str[idx] - '0') : 1);

    // a_idx AND b_idx = 0 shartini qanoatlantiruvchi bit juftliklarini tanlash kerak.
    // Mumkin bo'lgan (a_idx, b_idx) juftliklari: (0,0), (0,1), (1,0).

    // Holat 1: (a_idx, b_idx) = (0,0). Bu pozitsiya uchun yig'indi biti 0.
    // Bu tanlov har doim to'g'ri, chunki 0 <= limit_L_digit (limit_L_digit 0 yoki 1 bo'ladi).
    // Yangi 'tight' holati: agar biz tight bo'lsak va L_str[idx] 0 bo'lsa, tight qolamiz.
    // Agar L_str[idx] 1 bo'lsa, tight holati false bo'ladi (chunki 0 < 1).
    ans = (ans + solve(idx + 1, tight && (0 == limit_L_digit))) % MOD;

    // Holat 2 & 3: (a_idx, b_idx) = (0,1) yoki (1,0). Bu pozitsiya uchun yig'indi biti 1.
    // Bu tanlovlar faqat yig'indi biti (ya'ni 1) limit_L_digit dan kichik yoki unga teng bo'lsa to'g'ri.
    if (1 <= limit_L_digit) {
        // Agar yig'indi biti 1 bo'lishi mumkin bo'lsa, bunga erishishning 2 yo'li bor: (0,1) va (1,0).
        // Yangi 'tight' holati: agar biz tight bo'lsak va L_str[idx] 1 bo'lsa, tight qolamiz.
        // Agar L_str[idx] 0 bo'lsa, bu shart bajarilmaydi (1 > 0).
        long long ways_for_one_bit = solve(idx + 1, tight && (1 == limit_L_digit));
        ans = (ans + (2 * ways_for_one_bit) % MOD) % MOD;
    }

    // Hisoblangan natijani qaytarishdan oldin saqlash.
    return dp[idx][tight] = ans;
}
```
`solve` funksiyasi dinamik dasturlashning asosiy mantig'ini o'z ichiga oladi. U `idx` va `tight` holatlariga asoslanib, juftliklar sonini rekursiv tarzda hisoblaydi va natijalarni `dp` jadvalida saqlaydi (memoizatsiya). Funksiyadagi `limit_L_digit` o'zgaruvchisi `L` ning cheklovlarini boshqaradi. Ikkita asosiy holat (joriy bit `0` yoki `1` bo'lishi) tahlil qilinib, tegishli rekursiv chaqiruvlar amalga oshiriladi.

### `main` funksiyasi
```cpp
int main() {
    // C++ standart oqimlarini tezlashtirish.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> L_str; // L ni binar qator sifatida o'qish.
    N = L_str.length(); // L qatorining uzunligini aniqlash.

    // DP jadvalini -1 bilan boshlash (hisoblanmagan holatlarni ko'rsatish uchun).
    memset(dp, -1, sizeof(dp));

    // DP hisoblashni eng muhim bitdan (index 0) boshlash.
    // Dastlabki 'tight' holati true bo'ladi, chunki a+b L ning prefiksi bilan aynan mos kelishi kerak.
    cout << solve(0, true) << endl;

    return 0;
}
```
`main` funksiyasi kiritish/chiqarishni tezlashtirishni yoqadi, `L` ni o'qiydi, `N` ni hisoblaydi va `dp` jadvalini `-1` bilan initsializatsiya (boshlang'ich holatga keltirish) qiladi. Keyin u `solve(0, true)` funksiyasini chaqirib, eng muhim bitdan boshlab va `tight` cheklovini `true` qilib DP hisoblashni boshlaydi. Yakuniy natija ekranga chiqariladi.

## Edge case lar va eslatmalar
*   `L` binar qator sifatida berilgani uchun, uning uzunligi 100,001 gacha bo'lishi mumkin. Bu shuni anglatadiki, `L` ga `long long` yoki `int` kabi standart butun son turlarida sig'maydi. Shuning uchun binar qator bilan ishlash muhim.
*   `a + b = a XOR b` shartining `a AND b = 0` ga ekvivalentligi masala yechimining asosiy g'oyasi hisoblanadi. Bu bitlar bo'yicha DP qo'llash imkonini beradi.
*   `tight` (qattiqlik) cheklovi digit DP (raqamlar bo'yicha dinamik dasturlash) ning muhim qismidir. U joriy hosil bo'layotgan sonning `L` ga nisbatan qanday holatda ekanligini (kichikroq, teng) kuzatib boradi va keyingi bitlarni tanlashda to'g'ri cheklovlarni qo'llashga yordam beradi.
*   Javobni `10^9+7` ga bo'lgandagi qoldiqni chop etish talab qilinadi, shuning uchun har bir qo'shish operatsiyasidan keyin modulo (qoldiq) olishni unutmaslik kerak.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M074D) platformasidagi **M074D** raqamli **Xor va summa** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M074D>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M074D, Xor va summa yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
