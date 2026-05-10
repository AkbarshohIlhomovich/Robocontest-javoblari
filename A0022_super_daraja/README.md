---
title: "A0022 — Super daraja | Robocontest.uz Yechimi"
description: "Robocontest.uz A0022 (Super daraja) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Sonlar nazariyasi. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0022, Super daraja yechimi, robocontest Super daraja, A0022 c++ kod, sonlar nazariyasi, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /A0022_super_daraja/
lang: uz
---

# A0022 — Super daraja

## Masala haqida
Ushbu masala sizdan \(2^{(2^a)}\) ifodasining `b` modulidagi qoldig'ini topishni so'raydi. `a` va `b` sonlari \(1 \le a, b \le 10^6\) oraliqda berilgan. Bu yerda asosiy qiyinchilik, tashqi daraja \(2^a\) juda katta son bo'lishi mumkinligidadir, shuning uchun uni to'g'ridan-to'g'ri hisoblash imkonsiz.

## Yondashuv (g'oya)
Masalani yechish uchun biz modulli daraja hisoblashda ishlatiladigan Eylerning Totient Teoremasidan (Euler's Totient Theorem) foydalanamiz. Bu teorema quyidagicha ifodalanadi:
Agar `gcd(X, M) = 1` bo'lsa, \(X^Y \equiv X^{Y \pmod{\phi(M)}} \pmod M\).
Lekin umumiy holatda, agar `gcd(X, M) \ne 1` bo'lsa yoki \(Y < \phi(M)\) bo'lsa, teoremaning kengaytirilgan shakli qo'llaniladi:
\(X^Y \equiv X^{(Y \pmod{\phi(M)}) + \phi(M)} \pmod M\), bu yerda \(Y \ge \phi(M)\) bo'lishi shart.
Bizning masalamizda \(X=2\), \(Y=2^a\), \(M=b\). Demak, biz \(2^{(2^a \pmod{\phi(b)}) + \phi(b)} \pmod b\) ni hisoblashimiz kerak bo'ladi, agar \(2^a \ge \phi(b)\) bo'lsa. Aks holda, ya'ni \(2^a < \phi(b)\) bo'lsa, shunchaki \(2^{(2^a)} \pmod b\) ni hisoblaymiz.

Bu yerda asosiy qadamlar:
1.  `b` soni uchun Eylerning totient funksiyasi \(\phi(b)\) ni hisoblash.
2.  Tashqi daraja \(2^a\) ni \(\phi(b)\) moduli bo'yicha hisoblash. Bu yerda \(2^a\) sonining o'zi juda katta bo'lishi mumkin, shuning uchun biz yana modulli daraja hisoblashdan foydalanamiz.
3.  Yuqoridagi natijaga \(\phi(b)\) ni qo'shish kerakmi yoki yo'qmi, aniqlash. Bu \(2^a \ge \phi(b)\) shartiga bog'liq.
4.  Nihoyat, \(2\) ning hisoblangan darajasi bo'yicha `b` moduli bo'yicha yakuniy natijani hisoblash.

## Algoritm qadamlari
1.  **`b=1` holatini tekshirish**: Agar `b=1` bo'lsa, har qanday sonning 1 modulidagi qoldig'i 0 ga teng bo'ladi. Bu edge case ni alohida qaraymiz, chunki \(\phi(1)\) ning aniq ta'rifi biroz boshqacha.
2.  **\(\phi(b)\) ni hisoblash**: `phi(b)` funksiyasini chaqirib, `b` ning Eyler totient funksiyasi qiymatini topamiz. Bu funksiya berilgan sondan kichik va u bilan o'zaro tub bo'lgan musbat butun sonlar sonini qaytaradi. U sonning tub ko'paytuvchilarini topish orqali hisoblanadi.
3.  **Tashqi darajani (\(2^a\)) \(\phi(b)\) moduli bo'yicha hisoblash**:
    *   `exponent_for_outer_val` o'zgaruvchisi keyinchalik asosiy darajaning darajasi sifatida ishlatiladi.
    *   `is_exponent_large_enough_for_phi_rule` mantiqiy o'zgaruvchi \(2^a \ge \phi(b)\) shartini kuzatib boradi.
    *   Agar `a` juda katta bo'lsa (masalan, `a >= 20`), \(2^a\) soni `long long` tipidan oshib ketishi mumkin. Bunday hollarda, \(2^a\) soni deyarli har doim `phi_b` dan katta bo'ladi. Shuning uchun, `is_exponent_large_enough_for_phi_rule` ni `true` qilib belgilaymiz va `exponent_for_outer_val` ni `power(2, a, phi_b)` (tez modular exponentiation (modulli daraja) funksiyasi yordamida) hisoblaymiz.
    *   Agar `a` kichikroq bo'lsa (masalan, `a < 20`), \(2^a\) ni `(1LL << a)` bit siljitish (bit shift) orqali to'g'ridan-to'g'ri hisoblaymiz. Keyin bu qiymatni `phi_b` bilan solishtiramiz:
        *   Agar `actual_2_pow_a >= phi_b` bo'lsa, `is_exponent_large_enough_for_phi_rule` ni `true` qilamiz va `exponent_for_outer_val` ni `actual_2_pow_a % phi_b` sifatida belgilaymiz.
        *   Aks holda, `exponent_for_outer_val` ni shunchaki `actual_2_pow_a` deb olamiz.
4.  **Darajani tuzatish (Euler's Totient Theorem kengaytmasi bo'yicha)**: Agar `is_exponent_large_enough_for_phi_rule` `true` bo'lsa, bu degani asl daraja \(2^a\) \(\phi(b)\) dan katta yoki unga teng bo'lgan. Eylerning kengaytirilgan teoremasini to'g'ri qo'llash uchun `exponent_for_outer_val` ga \(\phi(b)\) ni qo'shamiz. Bu agar \(2^a \pmod{\phi(b)}\) natijasi 0 bo'lsa, aslida daraja \(\phi(b)\) bo'lishi kerakligini ta'minlaydi, 0 emas. Shuningdek, qoldiqning qiymati kichik bo'lib, xato natija bermasligi uchun ham qo'shiladi.
5.  **Yakuniy natijani hisoblash**: `power(2, exponent_for_outer_val, b)` funksiyasini chaqirib, \(2\) ning `exponent_for_outer_val` darajasini `b` moduli bo'yicha hisoblaymiz va natijani chiqaramiz.

## Murakkablik tahlili
-   **Vaqt**:
    *   `phi(n)` funksiyasi `n` ning kvadrat ildizigacha bo'lgan sonlarni tekshirganligi sababli, uning murakkabligi O(\(\sqrt{n}\)) ni tashkil qiladi. Bizning holatimizda `n=b` bo'lgani uchun, bu O(\(\sqrt{b}\)).
    *   `power(base, exp, mod)` funksiyasi binary exponentiation (ikkilik darajaga ko'tarish) usulini ishlatganligi sababli, uning murakkabligi O(log `exp`) ni tashkil qiladi.
    *   Asosiy `main` funksiyada:
        *   \(\phi(b)\) ni hisoblash O(\(\sqrt{b}\)) vaqt oladi.
        *   Ichki daraja `exponent_for_outer_val` ni hisoblash:
            *   Agar `a < 20` bo'lsa, O(1).
            *   Agar `a >= 20` bo'lsa, `power(2, a, phi_b)` chaqiriladi, bu esa O(log `a`) vaqt oladi.
        *   Yakuniy `power(2, exponent_for_outer_val, b)` chaqiruvi, `exponent_for_outer_val` \(\approx 2 \times \phi(b)\) bo'lishi mumkinligini hisobga olsak, O(log \(\phi(b)\)) yoki O(log `b`) vaqt oladi.
    *   **Umumiy vaqt murakkabligi**: O(\(\sqrt{b} + \log a + \log b\)). `b` maksimal \(10^6\), \(\sqrt{10^6} = 1000\). `a` maksimal \(10^6\), log `a` taxminan 20. `b` log `b` ham taxminan 20. Shuning uchun, \(1000 + 20 + 20 \approx 1040\) operatsiya miqdori vaqt limiti (1000 ms) ichiga bemalol sig'adi.

-   **Xotira**:
    *   `power` va `phi` funksiyalari rekursiyadan foydalanmaydi (yoki tail recursion (oxirgi rekursiya) optimallashtiriladi) va doimiy miqdordagi o'zgaruvchilardan foydalanadi.
    *   **Umumiy xotira murakkabligi**: O(1) (doimiy xotira). 16 MB xotira limitiga bemalol sig'adi.

-   **Nega shu murakkablik chegaraga sig'adi**: Yuqorida tahlil qilinganidek, vaqt murakkabligi eng yomon holatda \(\approx 1000\) operatsiya darajasida bo'lib, bu 1000 ms vaqt limiti uchun juda tezdir. Xotira murakkabligi doimiy bo'lgani uchun u ham chegaraga sig'adi.

## Kod izohi

### `power` funksiyasi (Modular Exponentiation - Modulli darajaga ko'tarish)
```cpp
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod; // Asosiy sonni modulga qisqartirish
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod; // Agar daraja toq bo'lsa, hozirgi asosiyni natijaga ko'paytiramiz
        base = (base * base) % mod; // Asosiy sonni kvadratga ko'tarib, modulga qisqartiramiz
        exp /= 2; // Darajani yarmiga kamaytiramiz
    }
    return res;
}
```
Bu funksiya \( (base^{exp}) \pmod{mod} \) ni tez hisoblaydi. U binary exponentiation (ikkilik darajaga ko'tarish) yoki "exponentiation by squaring" (kvadratlash orqali darajaga ko'tarish) deb nomlanuvchi usuldan foydalanadi. Bu usul `exp` darajasini ikkilik ko'rinishda tahlil qilib, har bir bit uchun asosiy sonni kvadratlab boradi va faqat 1 bo'lgan bitlar uchun natijaga ko'paytmani qo'shadi.

### `phi` funksiyasi (Euler's Totient Function - Eylerning Totient Funksiyasi)
```cpp
long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) { // n ning tub ko'paytuvchilarini topish
        if (n % i == 0) {
            while (n % i == 0)
                n /= i; // barcha i ko'paytuvchilarini yo'q qilish
            result -= result / i; // Formula bo'yicha hisoblash
        }
    }
    if (n > 1) // Agar n qolgan qismi tub son bo'lsa
        result -= result / n; // O'sha tub sonni ham hisobga olish
    return result;
}
```
Bu funksiya berilgan `n` sonining Eylerning totient funksiyasi \(\phi(n)\) ni hisoblaydi. Formula \(\phi(n) = n \times \prod_{p|n} (1 - \frac{1}{p})\) ga asoslangan, bu yerda \(p\) `n` ning har bir tub ko'paytuvchisidir. Algoritm `n` ning barcha tub ko'paytuvchilarini iterativ ravishda topadi va `result` dan `result / p` ni ayirib boradi.

### `main` funksiyasi
```cpp
int main() {
    ios_base::sync_with_stdio(false); // Kirish/chiqish operatsiyalarini tezlashtirish
    cin.tie(0); // cin va cout ni sinxronizatsiyadan chiqarish

    long long a, b;
    cin >> a >> b;

    if (b == 1) { // Edge case: b=1
        cout << 0 << endl;
        return 0;
    }

    long long phi_b = phi(b); // phi(b) ni hisoblash

    long long exponent_for_outer_val;
    bool is_exponent_large_enough_for_phi_rule = false; // 2^a >= phi(b) shartini kuzatish

    if (a >= 20) { // Agar a katta bo'lsa, 2^a juda katta bo'ladi va phi_b dan katta bo'lish ehtimoli yuqori
        is_exponent_large_enough_for_phi_rule = true;
        exponent_for_outer_val = power(2, a, phi_b); // 2^a ni phi_b moduli bo'yicha hisoblash
    } else { // Agar a kichik bo'lsa, 2^a ni to'g'ridan-to'g'ri hisoblaymiz
        long long actual_2_pow_a = (1LL << a); // 2^a ni bit siljitish orqali hisoblash
        if (actual_2_pow_a >= phi_b) { // Haqiqiy 2^a ni phi_b bilan solishtirish
            is_exponent_large_enough_for_phi_rule = true;
            exponent_for_outer_val = actual_2_pow_a % phi_b;
        } else {
            exponent_for_outer_val = actual_2_pow_a;
        }
    }

    if (is_exponent_large_enough_for_phi_rule) {
        exponent_for_outer_val += phi_b; // Eyler teoremasining kengaytirilgan shakli uchun tuzatish
    }
    
    cout << power(2, exponent_for_outer_val, b) << endl; // Yakuniy natijani hisoblash va chiqarish

    return 0;
}
```
`main` funksiyasi yuqorida tushuntirilgan algoritm qadamlarini amalga oshiradi. U `b=1` holatini tekshiradi, \(\phi(b)\) ni hisoblaydi, keyin \(2^a\) ni \(\phi(b)\) moduli bo'yicha hisoblashda `a` ning kattaligiga qarab ikki xil yondashuvdan birini tanlaydi. `is_exponent_large_enough_for_phi_rule` flagi yordamida Eyler teoremasining kengaytirilgan shaklini qo'llash zarurligini aniqlaydi va agar kerak bo'lsa, darajaga \(\phi(b)\) ni qo'shadi. Nihoyat, yakuniy modulli darajani hisoblab, natijani chop etadi.

## Edge case lar va eslatmalar
*   **`b = 1` holati**: Agar `b` 1 ga teng bo'lsa, har qanday sonning 1 modulidagi qoldig'i har doim 0 ga teng bo'ladi. Bu holatni dastlab tekshirish zarur, chunki \(\phi(1)\) ning ba'zi ta'riflari \(\phi(1)=1\) deb qabul qilsa-da, umumiy Eyler teoremasi `M > 1` uchun ishlaydi va 1 modulida 0 qoldig'i odatda xususiy holat sifatida ko'riladi.
*   **Eylerning Totient Teoremasi kengaytmasi**: Kodda `if (is_exponent_large_enough_for_phi_rule) { exponent_for_outer_val += phi_b; }` qismi juda muhim. Agar `X^Y \pmod M` ni hisoblayotgan bo'lsak va `Y \ge \phi(M)` bo'lsa, Eyler teoremasining kengaytirilgan shakli \(X^Y \equiv X^{(Y \pmod{\phi(M)}) + \phi(M)} \pmod M\) bo'ladi. Agar \(Y \pmod{\phi(M)}\) qiymati 0 ga teng bo'lsa (yoki kichik son), lekin asl `Y` qiymati \(\phi(M)\) dan katta bo'lsa, faqat qoldiqni ishlatish xato natija berishi mumkin. Masalan, \(2^4 \pmod 6\). \(\phi(6) = 2\). \(4 \pmod 2 = 0\). Agar faqat \(2^0 \pmod 6\) ni hisoblasak, 1 ni olamiz, aslida \(2^4 = 16 \equiv 4 \pmod 6\). Kengaytirilgan teoremaga ko'ra, \(2^{(4 \pmod 2) + 2} \pmod 6 = 2^{0+2} \pmod 6 = 2^2 \pmod 6 = 4 \pmod 6\), bu to'g'ri. `is_exponent_large_enough_for_phi_rule` flagi aynan shu holatni qamrab oladi.
*   **`a >= 20` sharti**: Bu shart \(2^a\) sonining kattaligini taxmin qilish uchun ishlatilgan. `a` qiymati 20 dan katta bo'lsa, \(2^a\) soni juda katta bo'lib, `long long` tipida ham to'g'ri saqlab bo'lmasligi mumkin (masalan, `a=63` da `2^63` `long long` dan oshib ketadi). Bunday hollarda, \(2^a\) deyarli har doim `phi_b` dan katta bo'ladi. Shu sababli, uning `phi_b` modulidagi qoldig'ini `power` funksiyasi yordamida hisoblash xavfsizroq va to'g'riroqdir.
*   **`long long` ishlatilishi**: Barcha hisob-kitoblar, ayniqsa oraliq ko'paytmalar `long long` tipida bajariladi. Bu 0 dan \(10^6\) gacha bo'lgan `a` va `b` qiymatlari uchun mumkin bo'lgan overflow (to'lib ketish) xavfini oldini oladi.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0022) platformasidagi **A0022** raqamli **Super daraja** masalasi. U **Sonlar nazariyasi** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0022>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0022, Super daraja yechimi, robocontest masalalari, c++17, olimpiada yechimi, sonlar nazariyasi, dasturlash uzbek, competitive programming O'zbekiston.</sub>
