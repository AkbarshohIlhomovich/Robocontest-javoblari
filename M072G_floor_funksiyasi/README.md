---
title: "M072G — Floor funksiyasi | Robocontest.uz Yechimi"
description: "Robocontest.uz M072G (Floor funksiyasi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M072G, Floor funksiyasi yechimi, robocontest Floor funksiyasi, M072G c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M072G_floor_funksiyasi/
lang: uz
---

# M072G — Floor funksiyasi

## Masala haqida
Bu masala `A`, `B` va `N` butun sonlari berilganda, \(floor(Ax/B) - A \cdot floor(x/B)\) ifodasining maksimum qiymatini topishni talab qiladi. Bu yerda `x` manfiy bo'lmagan butun son bo'lib, `0 \le x \le N` shartini qanoatlantirishi kerak. `floor(t)` funksiyasi `t` dan katta bo'lmagan eng katta butun sonni anglatadi.

## Yondashuv (g'oya)
Masalaning yechimi berilgan ifodani soddalashtirishga asoslangan.
`floor(t)` funksiyasining ta'rifiga ko'ra, har qanday `t` haqiqiy son uchun `t = floor(t) + {t}` yozish mumkin, bu yerda `{t}` — `t` ning kasr qismi (`0 \le \{t\} < 1`).

Ifodani ko'rib chiqamiz:
\(floor(Ax/B) - A \cdot floor(x/B)\)

Bo'lish algoritmidan foydalanamiz: `x` ni `B` ga bo'lganda `x = q \cdot B + r` deb yozish mumkin, bu yerda `q = floor(x/B)` va `r = x \% B` (qoldiq), `0 \le r < B`.

Endi `x` ning qiymatini ifodaga qo'yamiz:
\(floor(A \cdot (qB + r)/B) - A \cdot floor((qB + r)/B)\)
\(floor(Aq + Ar/B) - A \cdot floor(q + r/B)\)

`q` butun son bo'lgani uchun, `floor(Aq + Ar/B) = Aq + floor(Ar/B)` va `floor(q + r/B) = q + floor(r/B)`.
`0 \le r < B` bo'lgani uchun, `0 \le r/B < 1`. Demak, `floor(r/B)` har doim `0` ga teng.
Shunday qilib, ifoda quyidagicha soddalashadi:
\(Aq + floor(Ar/B) - A \cdot (q + 0)\)
\(Aq + floor(Ar/B) - Aq\)
\(floor(Ar/B)\)

Demak, berilgan ifoda \(floor(A \cdot (x \% B) / B)\) ga teng ekan.
Bu ifodaning maksimum qiymatini topish uchun, biz \(x \% B\) ning qiymatini maksimallashtirishimiz kerak, chunki `A` va `B` musbat konstantalar.
`x \% B` ning eng katta mumkin bo'lgan qiymati `B - 1` dir (agar `x` kamida `B - 1` bo'lsa).
Ammo, `x` ning `N` dan katta bo'lmasligi (`x \le N`) cheklovi bor.
Shunday qilib, `x \% B` ning maksimal qiymati `min(N, B - 1)` ga teng bo'ladi.
Ya'ni, agar `N \ge B-1` bo'lsa, biz `x = B-1` ni tanlab, `x \% B = B-1` ga erisha olamiz.
Agar `N < B-1` bo'lsa, `x` ning maksimal qiymati `N` bo'ladi. Bu holda, `x \% B = N \% B = N` (chunki `N < B`).
Ikkala holatni ham qamrab olgan holda, optimal `x \% B` qiymati `r_{optimal} = \min(N, B-1)` bo'ladi.

Endi bu `r_{optimal}` qiymatini soddalashtirilgan ifodaga qo'yamiz:
\(floor(A \cdot r_{optimal} / B)\)
Butun sonlar bo'lishi sababli, bu C++ tilida oddiy butun bo'lish `(A * r_{optimal}) / B` orqali hisoblanadi.

## Algoritm qadamlari
1.  Kirish ma'lumotlari `A, B, N` ni o'qing. `B` va `N` juda katta bo'lishi mumkinligi sababli, ularni `long long` turida saqlang. `A` ham `long long` bo'lishi maqsadga muvofiq, chunki u `x_val_for_max_remainder` bilan ko'paytiriladi.
2.  `x` ning `B` ga bo'linganidagi qoldig'ini maksimallashtiruvchi optimal qiymatni toping. Bu qiymat `min(N, B - 1)` ga teng. Uni `long long x_val_for_max_remainder` o'zgaruvchisiga saqlang.
3.  Yuqorida soddalashtirilgan formulani qo'llang: `(A * x_val_for_max_remainder) / B` (bu yerda C++ dagi butun bo'lish avtomatik tarzda `floor` vazifasini bajaradi, chunki barcha sonlar musbat). Natijani `long long result` o'zgaruvchisiga saqlang.
4.  `result` ni ekranga chop eting.

## Murakkablik tahlili
-   **Vaqt**: O(1)
    *   Algoritm kirish ma'lumotlarining hajmiga bog'liq bo'lmagan doimiy sondagi arifmetik amallar (o'qish, `min` funksiyasi, ko'paytirish, bo'lish) va tayinlashlardan iborat. Shuning uchun, vaqt murakkabligi doimiy bo'lib, `O(1)` ga teng.
-   **Xotira**: O(1)
    *   Algoritm faqat bir nechta o'zgaruvchini saqlash uchun doimiy miqdorda xotiradan foydalanadi (`A, B, N, x_val_for_max_remainder, result`). Kirish hajmi qanchalik katta bo'lishidan qat'i nazar, talab qilinadigan xotira miqdori o'zgarmaydi.

-   **Nega shu murakkablik chegaraga sig'adi**:
    Vaqt limiti 1000 ms, xotira limiti 32 MB. O(1) vaqt va xotira murakkabligiga ega bo'lgan algoritm ushbu cheklovlarga bemalol sig'adi, chunki u juda tez ishlaydi va juda kam xotira sarflaydi. Masalan, `10^6 * 10^12 = 10^18` gacha bo'lgan oraliqdagi sonlar uchun `long long` tipidan foydalanish ham xotira va vaqt bo'yicha cheklovlarga muvofiq keladi.

## Kod izohi
```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun kerak
#include <algorithm> // std::min funksiyasi uchun kerak

int main() {
    // Standard I/O (kirish/chiqish) tezligini oshirish
    // std::ios_base::sync_with_stdio(false) C++ streamlarini C standart I/O bilan sinxronizatsiyasini o'chiradi.
    // std::cin.tie(0) esa std::cin ning std::cout bilan bog'lanishini bekor qiladi, bu esa cin dan oldin cout ni flush qilishni oldini oladi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // A, B, N o'zgaruvchilarini e'lon qilish.
    // B va N 10^12 gacha bo'lishi mumkin, shuning uchun long long tipidan foydalanish shart.
    // A * x_val_for_max_remainder ko'paytmasi 10^6 * 10^12 = 10^18 gacha bo'lishi mumkin,
    // bu ham long long diapazoniga sig'adi (taxminan 9*10^18).
    long long A, B, N;
    // Kirish ma'lumotlarini o'qish
    std::cin >> A >> B >> N;

    // x % B ning maksimal qiymatini topish.
    // Bu min(N, B - 1) ga teng.
    // Misol: Agar B=7, N=4 bo'lsa, min(4, 7-1) = min(4, 6) = 4.
    // Agar B=10, N=9 bo'lsa, min(9, 10-1) = min(9, 9) = 9.
    long long x_val_for_max_remainder = std::min(N, B - 1);

    // Yakuniy natijani hisoblash.
    // O'tkazilgan formulaga ko'ra, bu floor(A * (x % B) / B) ga teng.
    // C++ da musbat butun sonlarni bo'lishda "/" operatori avtomatik ravishda floor funksiyasini bajaradi.
    long long result = (A * x_val_for_max_remainder) / B;

    // Natijani ekranga chop etish
    std::cout << result << std::endl;

    // Dastur muvaffaqiyatli yakunlanganini bildirish
    return 0;
}
```

## Edge case lar va eslatmalar
*   **`x = 0` holati**: Agar `x = 0` bo'lsa, ifoda `floor(0) - A * floor(0) = 0 - A * 0 = 0` ga teng. Bizning algoritmda `x_val_for_max_remainder = min(N, B-1)`. Agar `N=0` bo'lsa, `x_val_for_max_remainder = min(0, B-1) = 0` bo'ladi, natija `(A*0)/B = 0`. Agar `B=1` bo'lsa, `x_val_for_max_remainder = min(N, 0) = 0` bo'ladi, natija `(A*0)/1 = 0`. Ikkala holatda ham to'g'ri ishlaydi.
*   **`B = 1` holati**: Agar `B = 1` bo'lsa, `x \% B = x \% 1 = 0`. Bizning algoritmda `x_val_for_max_remainder = min(N, 1 - 1) = min(N, 0) = 0` bo'ladi. Natija `(A * 0) / 1 = 0`. Asl ifodaga ko'ra `floor(Ax/1) - A*floor(x/1) = Ax - A*x = 0`. To'g'ri ishlaydi.
*   **Katta sonlar (`long long`)**: `A \cdot x_val_for_max_remainder` ko'paytmasi `10^6 \cdot 10^{12} = 10^{18}` gacha qiymatga ega bo'lishi mumkin. C++ dagi `int` tipi odatda `2 \cdot 10^9` atrofida maksimal qiymatni saqlaydi, bu esa yetarli emas. Shuning uchun barcha tegishli o'zgaruvchilar (ayniqsa `B, N` va ularning ishtirokidagi hisob-kitoblar) `long long` tipida e'lon qilinishi muhim.
*   **`floor` va butun bo'lish**: C++ da musbat butun sonlarni bo'lish (`/` operatori) natijani har doim nolga qarab yaxlitlaydi (truncation). Musbat sonlar uchun bu `floor` funksiyasining vazifasini bajaradi. Masalan, `20 / 7` natijasi `2` bo'ladi, bu `floor(2.85...)` ga teng. Bu masalada barcha sonlar musbat bo'lgani uchun, oddiy butun bo'lish operatoridan foydalanish to'g'ri yechim beradi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M072G) platformasidagi **M072G** raqamli **Floor funksiyasi** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M072G>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M072G, Floor funksiyasi yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
