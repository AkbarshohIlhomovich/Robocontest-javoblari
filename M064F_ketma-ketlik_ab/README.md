# M064F — Ketma-ketlik a/b

## Masala haqida
Berilgan masala murakkab tuzilgan ratsional sonlar ketma-ketligida \(\frac{a}{b}\) ko'rinishidagi berilgan kasrning nechanchi o'rinda joylashganini topishni talab qiladi. Ketma-ketlik: \(\frac{1}{1}, \frac{2}{1}, \frac{1}{2}, \frac{3}{1}, \frac{2}{2}, \frac{1}{3}, \frac{4}{1}, \frac{3}{2}, \dots \frac{a}{b}, \dots\). \(a\) va \(b\) sonlari \(10^9\) gacha bo'lishi mumkinligi tufayli, yechim samarali va katta sonlar bilan ishlashga mos bo'lishi kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi berilgan ketma-ketlikdagi elementlarning tuzilishini kuzatishdir. Elementlarni maxraj (denominator) va surat (numerator) yig'indisi \((a+b)\) bo'yicha guruhlash orqali aniq bir tartibni payqash mumkin. Bu tartibdan foydalanib, berilgan kasrning umumiy pozitsiyasini hisoblash uchun oldingi guruhlardagi elementlar sonini va joriy guruhdagi pozitsiyasini aniqlash mumkin.

## Algoritm qadamlari

1.  **Guruhni aniqlash:** Berilgan \(\frac{a}{b}\) kasrining surat va maxraj yig'indisi \(S = a + b\) ni hisoblaymiz. Bu yig'indi kasr qaysi guruhga tegishli ekanligini ko'rsatadi. Masalan, \(1/1\) uchun \(S=2\); \(2/1, 1/2\) uchun \(S=3\); \(3/1, 2/2, 1/3\) uchun \(S=4\) va hokazo.

2.  **Oldingi guruhlardagi elementlar sonini hisoblash:** Har bir guruhda \(S-1\) ta element mavjud. Masalan, \(S=2\) bo'lgan guruhda \(2-1=1\) ta element; \(S=3\) bo'lgan guruhda \(3-1=2\) ta element. Shunday qilib, \(S\) guruhidan oldingi barcha guruhlardagi umumiy elementlar soni quyidagi yig'indidan iborat:
    \((2-1) + (3-1) + \dots + ((S-1)-1)\)
    Bu \(1 + 2 + \dots + (S-2)\) yig'indisiga teng. Bu arifmetik progressiyaning yig'indisi bo'lib, formulasi \(\frac{(N) \times (N+1)}{2}\) dir, bu yerda \(N = S-2\). Demak, \(S\) guruhidan oldingi umumiy elementlar soni \(\frac{(S-2) \times (S-1)}{2}\) ga teng bo'ladi.

3.  **Joriy guruhdagi pozitsiyani aniqlash:** Har bir guruhda kasrlar suratning kamayish tartibida joylashgan: \(\frac{S-1}{1}, \frac{S-2}{2}, \frac{S-3}{3}, \dots, \frac{1}{S-1}\).
    Qo'yilgan \(a/b\) kasri uchun joriy guruhdagi pozitsiya \(S-a\) formulasi orqali topiladi. Misol uchun, \(S=9\) guruhida \(a=4\) bo'lsa, kasr \(\frac{4}{5}\) guruh ichida \(9-4=5\)-o'rinda turadi (\(\frac{8}{1}, \frac{7}{2}, \frac{6}{3}, \frac{5}{4}, \underline{\frac{4}{5}}, \dots\)).

4.  **Yakuniy pozitsiyani hisoblash:** Oldingi guruhlardagi elementlar soniga joriy guruhdagi pozitsiyani qo'shish orqali \(\frac{a}{b}\) kasrining ketma-ketlikdagi umumiy o'rni (indeksi) topiladi.
    `Umumiy pozitsiya = (oldin kgan guruhlardagi elementlar soni) + (joriy guruhdagi pozitsiya)`

## Murakkablik tahlili
-   **Vaqt**: O(1) — Algoritm faqat bir nechta arifmetik amallarni (qo'shish, ayirish, ko'paytirish, bo'lish) bajaradi, bu kirish hajmidan qat'i nazar doimiy vaqt oladi.
-   **Xotira**: O(1) — Algoritm faqat bir nechta o'zgaruvchilarni (masalan, `a`, `b`, `s`, `total_terms_before_s_group`, `position_in_s_group`, `result`) saqlash uchun doimiy miqdordagi xotiradan foydalanadi.
-   **Nega shu murakkablik chegaraga sig'adi**: Kirishdagi \(a, b\) qiymatlari \(10^9\) gacha bo'lishi mumkin. Natijada \(S = a+b\) \(2 \times 10^9\) gacha, va yakuniy pozitsiya \((S-2) \times (S-1) / 2\) hisobida taxminan \((2 \times 10^9)^2 / 2 \approx 2 \times 10^{18}\) gacha bo'lishi mumkin. C++ dagi `long long` ma'lumot turi \(\approx 9 \times 10^{18}\) gacha bo'lgan butun sonlarni saqlay oladi, shuning uchun barcha hisob-kitoblar `long long` yordamida overflow (to'lib ketish) bo'lmasdan amalga oshiriladi va chegaralarga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h>

int main() {
    // Standart I/O (kirish/chiqish) sinxronizatsiyasini o'chirish va cin/cout ni tezlashtirish.
    // Bu katta kirish/chiqish operatsiyalari mavjud bo'lganda dastur tezligini oshirishga yordam beradi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // a va b ni long long tipida e'lon qilish, chunki ularning qiymatlari juda katta (10^9 gacha) bo'lishi mumkin.
    long long a, b;
    // a va b qiymatlarini kiritish faylidan o'qish.
    std::cin >> a >> b;

    // Surat va maxraj yig'indisini hisoblash. Bu kasr tegishli bo'lgan guruhni belgilaydi.
    long long s = a + b;

    // Joriy guruhdan (s) oldingi barcha guruhlardagi elementlar sonini hisoblash.
    // Bu (S-2) gacha bo'lgan barcha natural sonlarning yig'indisidir: 1 + 2 + ... + (S-2).
    // Arifmetik progressiya yig'indisi formulasi: N * (N + 1) / 2, bu yerda N = S-2.
    long long total_terms_before_s_group = (s - 2) * (s - 1) / 2;
    
    // Joriy guruh ichida berilgan kasrning pozitsiyasini hisoblash.
    // Guruhlar surat kamayish tartibida joylashgan: (S-1)/1, (S-2)/2, ..., a/b, ...
    // Kasrning surati 'a' bo'lsa, uning guruh ichidagi pozitsiyasi (S - a) ga teng.
    long long position_in_s_group = s - a;

    // Yakuniy natijani, ya'ni berilgan kasrning umumiy ketma-ketlikdagi o'rnini hisoblash.
    // Oldingi guruhlardagi elementlar soniga joriy guruhdagi pozitsiya qo'shiladi.
    long long result = total_terms_before_s_group + position_in_s_group;

    // Natijani chiqish fayliga chop etish.
    std::cout << result << std::endl;

    // Dasturning muvaffaqiyatli yakunlanganini bildiradi.
    return 0;
}
```

## Edge case lar va eslatmalar

*   **Katta sonlar (Large numbers):** Masala shartiga ko'ra \(a, b \le 10^9\). Bu degani \(a+b\) va yakuniy natija `long long` (yoki 64-bit butun son) tipida saqlanishi kerak, aks holda "integer overflow" (butun son to'lib ketishi) xatosi yuzaga kelishi mumkin. Kodda `long long` ishlatilgani uchun bu muammo hal qilingan.
*   **Birinchi element (1/1):** Agar \(a=1, b=1\) bo'lsa, \(S=2\).
    `total_terms_before_s_group = (2-2)*(2-1)/2 = 0*1/2 = 0`.
    `position_in_s_group = 2-1 = 1`.
    `result = 0 + 1 = 1`. Natija to'g'ri, chunki \(1/1\) ketma-ketlikdagi birinchi element.
*   **Tezlik:** `std::ios_base::sync_with_stdio(false);` va `std::cin.tie(0);` qatorlari C++ dagi standart kirish/chiqish operatsiyalarini sezilarli darajada tezlashtiradi. Bu juda katta hajmdagi ma'lumotlarni o'qish yoki yozish talab qilinadigan musobaqa dasturlash masalalarida muhim. Ushbu masalada kirish hajmi kichik bo'lsa-da, bu yaxshi amaliyotdir.
*   **Umumiylik:** Yechim ketma-ketlikdagi har qanday \(\frac{a}{b}\) kasri uchun ishlaydi, chunki u ketma-ketlikning tuzilishidagi umumiy naqshga asoslangan.
