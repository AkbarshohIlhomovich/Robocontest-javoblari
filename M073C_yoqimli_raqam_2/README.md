---
title: "M073C — Yoqimli raqam #2 | Robocontest.uz Yechimi"
description: "Robocontest.uz M073C (Yoqimli raqam #2) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M073C, Yoqimli raqam #2 yechimi, robocontest Yoqimli raqam #2, M073C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M073C_yoqimli_raqam_2/
lang: uz
---

# M073C — Yoqimli raqam #2

## Masala haqida
Diyorbek "yoqimli raqamlar" deb ataydigan, faqatgina 0 va 1 raqamlaridan tashkil topgan mashina raqamlarini yoqtiradi. Unga 1 dan $N$ gacha bo'lgan natural sonlar orasida nechta shunday yoqimli son mavjudligini topish kerak. $N$ soni $10^9$ gacha bo'lishi mumkin.

## Yondashuv (g'oya)
Masalani hal qilish uchun biz 1 dan $N$ gacha bo'lgan barcha "yoqimli" sonlarni tizimli ravishda hosil qilishimiz va ularni sanab chiqishimiz kerak. "Yoqimli" sonlar faqat 0 va 1 raqamlaridan tashkil topganligi sababli, biz ularni daraxt shaklida generatsiya qilishimiz mumkin. Boshlang'ich nuqta 1 bo'lsin. Har bir mavjud "yoqimli" sondan biz ikkita yangi "yoqimli" son hosil qilishimiz mumkin: sonning oxiriga 0 ni qo'shish va sonning oxiriga 1 ni qo'shish. Bu jarayonni Breadth-First Search (BFS) – Kenglik bo'yicha qidirish algoritmi yordamida, navbat (queue) ma'lumotlar tuzilmasidan foydalanib samarali amalga oshirish mumkin. Navbat yordamida sonlar o'sish tartibida hosil bo'ladi, bu esa $N$ chegarasidan oshib ketmaslikni osonlikcha tekshirish imkonini beradi.

## Algoritm qadamlari

1.  **Kirishni o'qish**: $N$ sonini kirishdan `n_input` o'zgaruvchisiga o'qib olinadi. Keyinchalik xatoliklarning oldini olish uchun uni `long long` turidagi `n` o'zgaruvchisiga o'zlashtiramiz.
2.  **Boshlang'ich holat**:
    *   `count` (sana'gich) o'zgaruvchisini `0` ga tenglashtiramiz. Bu 1 dan $N$ gacha bo'lgan yoqimli sonlar sonini saqlaydi.
    *   `queue<long long>` turidagi `q` nomli navbatni yaratamiz.
    *   Navbatga birinchi "yoqimli" son bo'lgan `1` ni qo'shamiz (chunki savolda natural sonlar orasida deyilgan, 0 yoqimli son emas, chunki u ikki raqamli bo'lolmaydi, faqat 0 dan iborat bo'lsa yoqimli emas).
3.  **BFS sikli**: Navbat bo'sh bo'lmaguncha siklni davom ettiramiz:
    a.  Navbatning boshidagi sonni (`current_num`) olamiz va uni navbatdan chiqaramiz (`q.front()`, `q.pop()`).
    b.  `count` ni bittaga oshiramiz, chunki `current_num` $N$ dan oshmagan (aks holda u navbatga qo'shilmasdi) va u "yoqimli" hisoblanadi.
    c.  `current_num` dan ikkita yangi nomzod son hosil qilamiz:
        *   `next_num_0 = current_num * 10`: `current_num` oxiriga `0` qo'shilgan son.
        *   `next_num_1 = current_num * 10 + 1`: `current_num` oxiriga `1` qo'shilgan son.
    d.  Agar `next_num_0` $N$ dan kichik yoki teng bo'lsa, uni navbatga qo'shamiz (`q.push(next_num_0)`).
    e.  Agar `next_num_1` $N$ dan kichik yoki teng bo'lsa, uni navbatga qo'shamiz (`q.push(next_num_1)`).
4.  **Natijani chop etish**: Sikl tugagach (ya'ni, $N$ dan katta sonlar hosil bo'lishni boshlagach), `count` o'zgaruvchisining qiymatini chop etamiz.

## Murakkablik tahlili

*   **Vaqt murakkabligi**: `O(N_yoqimli)`
    *   Bu yerda `N_yoqimli` $N$ dan kichik yoki teng bo'lgan yoqimli sonlar sonini bildiradi.
    *   $N$ $10^9$ gacha bo'lishi mumkin. Eng katta yoqimli son $N \le 10^9$ bo'lgan holatda `1,111,111,111` (10 ta bir) bo'lishi mumkin, ammo bu $N$ dan oshib ketadi. Eng katta yoqimli son `1,000,000,000` (bir milliard) bo'lib, u $10$ xonali.
    *   $k$ xonali yoqimli sonlar soni taxminan $2^{k-1}$ ga teng (birinchi raqam har doim 1, qolgan $k-1$ raqam 0 yoki 1 bo'lishi mumkin).
    *   $N=10^9$ uchun maksimal xonalar soni 10.
    *   Demak, jami yoqimli sonlar soni $2^1 + 2^2 + \dots + 2^9 \approx 1022$ dan oshmaydi.
    *   Har bir sonni generatsiya qilish va navbatga qo'yish doimiy vaqt (`O(1)`) oladi. Shuning uchun umumiy vaqt murakkabligi $N$ dan kichik yoki teng bo'lgan yoqimli sonlar soniga proporsional bo'ladi, bu esa juda kichik raqam (`~1000`). Bu `log N` ga yaqin bo'lib, $10^9$ uchun `log_10(10^9) = 9` xonali sonlarni generatsiya qilish degani. Har bir xona uchun 2 ta branch hosil bo'ladi.
    *   $1000$ son uchun $2 \times 1000$ dan ortiqroq arifmetik amal bajariladi, bu juda tez.
*   **Xotira murakkabligi**: `O(N_yoqimli)`
    *   Navbatda saqlanadigan maksimal sonlar soni ham $N$ dan kichik yoki teng bo'lgan yoqimli sonlar sonidan oshmaydi.
    *   Eng yomon holatda, navbatda bir xil xonali barcha yoqimli sonlar saqlanishi mumkin, bu ham taxminan $2^9 \approx 512$ ta `long long` son degani.
    *   $512 \times \text{sizeof(long long)}$ (odatda 8 bayt) $= 512 \times 8 = 4096$ bayt $= 4$ KB atrofida, bu berilgan $32$ MB xotira chegarasidan ancha kichik.

Ikkala murakkablik ham berilgan vaqt (`1000 ms`) va xotira (`32 MB`) chegaralariga to'liq mos keladi.

## Kod izohi

*   `#include <bits/stdc++.h>`: Bu satr C++ standart kutubxonasining deyarli barcha bosh fayllarini o'z ichiga oladi, bu esa dasturlash tanlovlarida tez kod yozish uchun qulaydir. Bu yerda `iostream` (kirish/chiqish uchun) va `queue` (navbat ma'lumot tuzilmasi uchun) ishlatilgan.
*   `using namespace std;`: `std` nom fazosidagi funksiyalarni (`cin`, `cout`, `queue` va boshqalar) bevosita `std::` prefiksisiz ishlatish imkonini beradi.
*   `int main() { ... }`: Dasturning asosiy funksiyasi.
*   `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu ikki qator C++ `iostream` kirish/chiqish operatsiyalarini tezlashtirish uchun ishlatiladi. `sync_with_stdio(false)` C uslubidagi I/O (stdio) va C++ uslubidagi I/O (iostream) o'rtasidagi sinxronizatsiyani o'chiradi. `cin.tie(0)` `cin` ning `cout` bilan bog'lanishini bekor qiladi, ya'ni `cin` dan oldin `cout` buferini tozalashni kutmaydi.
*   `int n_input; cin >> n_input;`: Kirish faylidan `N` sonini `n_input` o'zgaruvchisiga o'qiydi.
*   `long long n = n_input;`: `n_input` `int` diapazonida (10^9) bo'lsa ham, keyinchalik generatsiya qilinadigan sonlar `current_num * 10` amali natijasida `int` diapazonidan oshib ketishi mumkin. Shuning uchun `n` ni `long long` (uzun butun son) turida saqlash xavfsizlikni ta'minlaydi va hisoblashlarda to'g'rilikni kafolatlaydi.
*   `int count = 0;`: `N` gacha bo'lgan yoqimli sonlar sonini saqlaydigan o'zgaruvchi.
*   `queue<long long> q;`: Yoqimli sonlarni saqlash uchun navbat. `long long` turi raqamlarning kattalashishini hisobga oladi.
*   `q.push(1);`: Birinchi yoqimli son — `1` ni navbatga qo'shadi.
*   `while (!q.empty()) { ... }`: Navbat bo'sh bo'lmaguncha davom etadigan asosiy BFS sikli.
*   `long long current_num = q.front(); q.pop();`: Navbatning boshidagi sonni oladi va uni navbatdan olib tashlaydi.
*   `count++;`: Olingan sonni yoqimli sonlar ro'yxatiga qo'shadi.
*   `long long next_num_0 = current_num * 10;`: `current_num` ning oxiriga `0` qo'shib yangi son hosil qiladi.
*   `if (next_num_0 <= n) { q.push(next_num_0); }`: Agar yangi hosil bo'lgan son `N` dan oshmasa, uni navbatga qo'shadi.
*   `long long next_num_1 = current_num * 10 + 1;`: `current_num` ning oxiriga `1` qo'shib yangi son hosil qiladi.
*   `if (next_num_1 <= n) { q.push(next_num_1); }`: Agar bu son ham `N` dan oshmasa, uni navbatga qo'shadi.
*   `cout << count << endl;`: Sikl tugagandan so'ng, topilgan yoqimli sonlar umumiy sonini chop etadi.
*   `return 0;`: Dasturning muvaffaqiyatli yakunlanganini bildiradi.

## Edge case lar va eslatmalar

*   **$N=1$ bo'lgan holat**: Masalaning minimal kirish qiymati `N=1`. Algoritm `1` ni navbatga qo'yadi, keyin uni chiqaradi, `count` `1` bo'ladi. `10` va `11` ikkalasi ham `1` dan katta bo'lganligi sababli navbatga qo'shilmaydi. Natijada `count` `1` bo'lib chop etiladi, bu to'g'ri (1 dan 1 gacha faqat 1 ning o'zi yoqimli son).
*   **Raqam turlari (`long long`)**: `N` ning maksimal qiymati $10^9$ bo'lganligi sababli, hosil bo'ladigan sonlar (`current_num * 10` va `current_num * 10 + 1`) `int` (odatda $2 \times 10^9$ atrofida) chegarasidan oshib ketishi mumkin. Shu sababli, `n`, `current_num`, `next_num_0`, `next_num_1` o'zgaruvchilarini `long long` turida e'lon qilish muhimdir. Yechimda bu to'g'ri qilingan.
*   **0 soni**: Masalada 1 dan $N$ gacha natural sonlar orasida deyilganligi sababli, `0` soni yoqimli hisoblanmaydi. Algoritm ham `1` dan boshlanganligi sababli, bu holat to'g'ri boshqariladi.
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M073C) platformasidagi **M073C** raqamli **Yoqimli raqam #2** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M073C>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M073C, Yoqimli raqam #2 yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
