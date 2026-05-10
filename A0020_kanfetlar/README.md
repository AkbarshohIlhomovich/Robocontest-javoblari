---
title: "A0020 — Kanfetlar | Robocontest.uz Yechimi"
description: "Robocontest.uz A0020 (Kanfetlar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Dinamik dasturlash. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0020, Kanfetlar yechimi, robocontest Kanfetlar, A0020 c++ kod, dinamik dasturlash, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /A0020_kanfetlar/
lang: uz
---

# A0020 — Kanfetlar

## Masala haqida
Bu masala sizdan N xil turdagi kanfetlarning har biridan cheksiz miqdorda bo'lgan qopdan K ta kanfetni necha xil usulda tanlash mumkinligini topishni so'raydi. Javob juda katta bo'lishi mumkinligi sababli, uni `10^9 + 7` ga bo'lgandagi qoldig'ini (modulosini) chiqarishingiz kerak.

## Yondashuv (g'oya)
Masala klassik **"Stars and Bars" (yulduzlar va ustunlar)** muammosiga teng. Bu yerda biz K ta "yulduz" (tanlangan kanfetlar) va N-1 ta "ustun" (kanfet turlarini ajratuvchi chegaralar) joylashish usullarini topishimiz kerak. Natijada, bu K ta elementni N guruhga bo'lishning usullarini topishga teng bo'ladi, bunda har bir guruhda nol yoki undan ko'p element bo'lishi mumkin.

Bunday muammolar uchun umumiy formula quyidagicha: `C(K + N - 1, K)` yoki `C(K + N - 1, N - 1)`, bu yerda `C(n, r)` "n dan r ni tanlash" kombinatorik funksiyasidir.

Biz `C(n, r)` ni `10^9 + 7` (tub son) moduli bo'yicha hisoblashimiz kerak. Tub modul bo'yicha kombinatsiyalarni hisoblash uchun Fermatning Kichik Teoremasidan foydalanamiz:
`C(n, r) = n! / (r! * (n-r)!) % MOD`.
Modul bo'yicha bo'lishni bajarish uchun `a / b % MOD` ni `a * b^(MOD-2) % MOD` shaklida yozish mumkin, bu yerda `b^(MOD-2)` `b` ning modul bo'yicha teskari qiymati (multiplicative inverse) hisoblanadi.
Bir nechta so'rovlar (test case'lar) mavjud bo'lgani uchun, faktoriallarni (n!) va ularning teskari qiymatlarini (invFact[n] = (n!)^(-1) % MOD) oldindan hisoblab qo'yish optimal yechim hisoblanadi.

## Algoritm qadamlari
1.  **Modul konstantasini aniqlash**: `MOD = 1000000007` qiymatini global o'zgaruvchi sifatida belgilash.
2.  **`power(base, exp)` funksiyasi**: Modul bo'yicha darajani (`base^exp % MOD`) tez hisoblash uchun rekursiv yoki iterativ usulda (binary exponentiation - ikkilik darajalash) funksiya yaratish.
3.  **`modInverse(n)` funksiyasi**: Fermatning Kichik Teoremasidan foydalanib `n` ning `MOD` bo'yicha teskari qiymatini hisoblash (`n^(MOD-2) % MOD`), buning uchun `power` funksiyasidan foydalaniladi.
4.  **Faktoriallar uchun massivlarni tayyorlash**:
    *   `MAX_COMB_N` konstantasini aniqlash. `N, K < 1000` bo'lganligi sababli, `K + N - 1` ning maksimal qiymati `999 + 999 - 1 = 1997` bo'ladi. Shuning uchun `MAX_COMB_N = 1999` yetarli.
    *   `fact[]` massivini 0 dan `MAX_COMB_N` gacha faktoriallarni ( `i! % MOD` ) saqlash uchun e'lon qilish.
    *   `invFact[]` massivini 0 dan `MAX_COMB_N` gacha teskari faktoriallarni ( `(i!)^(-1) % MOD` ) saqlash uchun e'lon qilish.
5.  **`precompute_factorials()` funksiyasi**:
    *   `fact[0] = 1` deb boshlash.
    *   1 dan `MAX_COMB_N` gacha `i` sonlari uchun `fact[i] = (fact[i-1] * i) % MOD` formulasi yordamida `fact` massivini to'ldirish.
    *   `invFact[MAX_COMB_N]` ni `modInverse(fact[MAX_COMB_N])` yordamida hisoblash.
    *   `MAX_COMB_N - 1` dan 0 gacha `i` sonlari uchun `invFact[i] = (invFact[i+1] * (i+1)) % MOD` formulasi yordamida `invFact` massivini to'ldirish. (Bu teskari faktoriallarni tez hisoblash usuli).
6.  **`nCr_mod_p(n, r)` funksiyasi**:
    *   Agar `r < 0` yoki `r > n` bo'lsa, 0 qaytarish (chunki bunday kombinatsiya mavjud emas).
    *   Aks holda, `C(n, r) = (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD` formulasi bo'yicha hisoblab natijani qaytarish.
7.  **`main` funksiyasi**:
    *   Kiritish/chiqarish operatsiyalarini tezlashtirish uchun `ios_base::sync_with_stdio(false); cin.tie(0);` qatorlarini qo'shish.
    *   `precompute_factorials()` funksiyasini bir marta chaqirish.
    *   `T` testlar sonini o'qish.
    *   Har bir test uchun:
        *   `N` va `K` ni o'qish.
        *   `n_val = K + N - 1` va `r_val = K` deb hisoblash.
        *   `nCr_mod_p(n_val, r_val)` ni chaqirib, natijani chop etish.

## Murakkablik tahlili
*   **Vaqt murakkabligi**:
    *   `precompute_factorials()` funksiyasi: Faktoriallarni hisoblash `O(MAX_COMB_N)` vaqt oladi. `invFact[MAX_COMB_N]` ni hisoblash `O(log MOD)` vaqt oladi (modular exponentiation tufayli). Qolgan teskari faktoriallarni hisoblash `O(MAX_COMB_N)` vaqt oladi. Jami: `O(MAX_COMB_N + log MOD)`.
    *   Har bir test holati uchun `nCr_mod_p()` funksiyasi: massivdan qiymatlarni olish va bir nechta arifmetik amallar tufayli `O(1)` vaqt oladi.
    *   Jami vaqt murakkabligi: `O(MAX_COMB_N + log MOD + T)`.
    *   `MAX_COMB_N` taxminan 2000 ga, `log MOD` taxminan 30 ga, `T` esa 200 ga teng. Demak, umumiy operatsiyalar soni taxminan `2000 + 30 + 200 = 2230` atrofida bo'lib, bu 1000 ms vaqt limiti uchun juda tezdir.
*   **Xotira murakkabligi**:
    *   `fact[]` va `invFact[]` massivlari har biri `MAX_COMB_N + 1` ta `long long` elementini saqlaydi.
    *   Jami xotira murakkabligi: `O(MAX_COMB_N)`.
    *   `MAX_COMB_N` taxminan 2000 bo'lganligi sababli, `2 * (2000 + 1) * sizeof(long long)` = `4002 * 8` bayt = `32016` bayt ~ `32 KB`. Bu 16 MB xotira limiti uchun juda kam hisoblanadi.

*   **Nega shu murakkablik chegaraga sig'adi**: Yuqorida ko'rsatilganidek, operatsiyalar soni bir necha mingdan oshmaydi, bu zamonaviy protsessorlar uchun juda tez bajariladigan ishdir. Xotira hajmi esa bir necha o'n KB bo'lib, bu berilgan 16 MB limitidan ancha kichik.

## Kod izohi

### Konstanta va global massivlar

```cpp
const long long MOD = 1000000007; // Natijani hisoblash uchun modul qiymati
const int MAX_COMB_N = 1999;     // Maksimal n qiymati (K + N - 1)
long long fact[MAX_COMB_N + 1];  // Faktoriallarni (i! % MOD) saqlovchi massiv
long long invFact[MAX_COMB_N + 1]; // Teskari faktoriallarni ((i!)^-1 % MOD) saqlovchi massiv
```
*   `MOD`: Masalada so'ralgan modulo qiymati (`10^9 + 7`).
*   `MAX_COMB_N`: `N` va `K` ning maksimal qiymati 999 bo'lganligi sababli, `K + N - 1` ning maksimal qiymati `999 + 999 - 1 = 1997` bo'ladi. `1999` esa xavfsiz yuqori chegara. Bu massivlarning o'lchamini belgilaydi.
*   `fact[]`: Har bir `i` uchun `i!` ning `MOD` bo'yicha qoldig'ini saqlaydi.
*   `invFact[]`: Har bir `i` uchun `(i!)^(-1)` ning `MOD` bo'yicha qoldig'ini saqlaydi. Bu `(i!)^(MOD-2) % MOD` ga teng.

### Modul bo'yicha daraja (Modular Exponentiation)

```cpp
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD; // Asosiy sonni modul bo'yicha kamaytirish
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD; // Agar daraja toq bo'lsa, natijaga qo'shish
        base = (base * base) % MOD; // Asosiy sonni kvadratga ko'tarish
        exp /= 2; // Darajani yarmiga kamaytirish
    }
    return res;
}
```
`power` funksiyasi `base` ni `exp` darajaga ko'tarib, natijani `MOD` bo'yicha qaytaradi. Bu jarayon "ikkilik darajalash" (binary exponentiation) deb ataladi va `O(log exp)` vaqt ichida ishlaydi. U `exp` ni ikkilik ko'rinishida yoyishga asoslangan.

### Modul bo'yicha teskari qiymat (Modular Inverse)

```cpp
long long modInverse(long long n) {
    return power(n, MOD - 2); // Fermatning Kichik Teoremasi: n^(MOD-2) % MOD
}
```
`modInverse` funksiyasi `n` ning `MOD` bo'yicha multiplikativ teskarisini qaytaradi. `MOD` tub son bo'lgani uchun, Fermatning Kichik Teoremasi bo'yicha `n^(MOD-2) % MOD` hisoblanadi.

### Faktoriallarni oldindan hisoblash

```cpp
void precompute_factorials() {
    fact[0] = 1; // 0! = 1
    for (int i = 1; i <= MAX_COMB_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD; // faktoriallarni ketma-ket hisoblash
    }
    
    // Eng katta faktorialning teskari qiymatini hisoblash
    invFact[MAX_COMB_N] = modInverse(fact[MAX_COMB_N]); 
    // Qolgan teskari faktoriallarni orqaga qarab hisoblash
    for (int i = MAX_COMB_N - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD; 
    }
}
```
`precompute_factorials` funksiyasi `fact` va `invFact` massivlarini to'ldiradi.
*   `fact` massivi `0!` dan `MAX_COMB_N!` gacha hisoblab chiqiladi.
*   `invFact` massivi uchun avval eng katta qiymat (`(MAX_COMB_N!)^(-1)`) hisoblanadi. Keyin, `(i!)^(-1) = ((i+1)!)^(-1) * (i+1)` formulasi yordamida orqaga qarab hisoblab chiqiladi. Bu usul bitta `modInverse` chaqirig'i bilan barcha teskari faktoriallarni topish imkonini beradi.

### Kombinatsiyani hisoblash

```cpp
long long nCr_mod_p(int n, int r) {
    if (r < 0 || r > n) return 0; // Invalid r qiymati uchun 0 qaytarish
    // C(n, r) = n! / (r! * (n-r)!) % MOD
    // = n! * (r!)^(-1) * ((n-r)!)^(-1) % MOD
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}
```
`nCr_mod_p` funksiyasi `C(n, r)` ni `MOD` bo'yicha hisoblaydi. Agar `r` noto'g'ri bo'lsa (manfiy yoki `n` dan katta), 0 qaytaradi. Aks holda, oldindan hisoblangan faktoriallar va teskari faktoriallardan foydalanib kombinatsiya formulasini qo'llaydi.

### Asosiy funksiya

```cpp
int main() {
    ios_base::sync_with_stdio(false); // C++ oqimlarini C oqimlari bilan sinxronizatsiyani o'chirish
    cin.tie(0); // cin va cout o'rtasidagi bog'lanishni uzish (tezroq I/O)

    precompute_factorials(); // Faktoriallarni oldindan hisoblash

    int T;
    cin >> T; // Testlar sonini o'qish
    while (T--) { // Har bir test uchun takrorlash
        int N, K;
        cin >> N >> K; // N va K ni o'qish
        
        int n_val = K + N - 1; // Formula bo'yicha n qiymatini hisoblash
        int r_val = K;         // Formula bo'yicha r qiymatini hisoblash
        
        cout << nCr_mod_p(n_val, r_val) << "\n"; // Natijani chop etish
    }

    return 0;
}
```
`main` funksiyasi dasturning asosiy ishini bajaradi:
1.  Tez kiritish/chiqarish (I/O) uchun sozlamalar.
2.  `precompute_factorials()` funksiyasini bir marta chaqirib, faktoriallar va teskari faktoriallarni tayyorlash.
3.  `T` test holatlari bo'yicha takrorlash.
4.  Har bir testda `N` va `K` ni o'qish.
5.  "Stars and Bars" formulasi bo'yicha `n_val` (`K + N - 1`) va `r_val` (`K`) ni aniqlash.
6.  `nCr_mod_p` funksiyasini chaqirib, javobni chop etish.

## Edge case lar va eslatmalar
*   **Kombinatorik qiymatlarning chegaralari**: `N` va `K` kamida 1 bo'lishi mumkin. Bu degani `K + N - 1` kamida `1 + 1 - 1 = 1` bo'ladi. `r_val` (`K`) ham kamida 1 bo'ladi. `nCr_mod_p` funksiyasidagi `r < 0` yoki `r > n` tekshiruvi muhim bo'lib, kombinatsiyalar mantiqiy bo'lmagan holatlar (masalan, 5 ta elementdan 6 tasini tanlash) uchun 0 qaytarilishini ta'minlaydi.
*   **Modul arifmetikasi**: Barcha oraliq hisob-kitoblarda `% MOD` operatorini ishlatish muhim. Aks holda, sonlar `long long` tipidan oshib ketishi va noto'g'ri natijaga olib kelishi mumkin.
*   **`MAX_COMB_N` ni to'g'ri tanlash**: Bu qiymat `K + N - 1` ning maksimal mumkin bo'lgan qiymatidan kichik bo'lmasligi kerak. Bizning holatda `999 + 999 - 1 = 1997` bo'lganligi sababli `1999` xavfsiz tanlangan.
*   **Tez I/O**: `ios_base::sync_with_stdio(false); cin.tie(0);` kod qatorlari katta kiritish/chiqarish hajmlari bo'lgan musobaqa dasturlash masalalarida vaqtni tejash uchun standart amaliyot hisoblanadi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0020) platformasidagi **A0020** raqamli **Kanfetlar** masalasi. U **Dinamik dasturlash** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0020>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0020, Kanfetlar yechimi, robocontest masalalari, c++17, olimpiada yechimi, dinamik dasturlash, dasturlash uzbek, competitive programming O'zbekiston.</sub>
