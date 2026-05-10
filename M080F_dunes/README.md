---
title: "M080F — Dunes | Robocontest.uz Yechimi"
description: "Robocontest.uz M080F (Dunes) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M080F, Dunes yechimi, robocontest Dunes, M080F c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M080F_dunes/
lang: uz
---

# M080F — Dunes

## Masala haqida
Geograf Grigoriy Georgiyevich qumtepalarning shakllanishini o'rganadi. U 1 dan $10^9$ gacha raqamlangan juda uzun qumtepa uchastkalarini ajratib olgan. Dastlab, barcha uchastkalardagi qum balandligi nolga teng edi. Keyin, landshaftni o'zgartirishi mumkin bo'lgan $n$ ta kuchli shamol zarbasi sodir bo'ldi. Har bir $i$-chi shamol zarbasi $x_i$ kuchga ega bo'lib, $l_i$ dan $r_i$ gacha bo'lgan uchastkalarga ta'sir ko'rsatdi. Bu zarba natijasida $l_i$-chi uchastkaning balandligi $x_i$ ga oshdi, $l_i+1$-chi uchastkaning balandligi $x_i$ ga kamaydi, keyingi uchastka yana $x_i$ ga oshdi va hokazo, $r_i$-chi uchastkagacha (shu jumladan). Grigoriy Georgiyevich barcha $n$ ta shamol zarbasi haqidagi ma'lumotlarni bilgan holda, o'zini qiziqtirgan $m$ ta uchastkaning yakuniy barqaror balandligini aniqlamoqchi.

## Yondashuv (g'oya)
Masalaning asosiy qiyinligi — uchastkalar soni (koordinatalar) $10^9$ gacha bo'lishi mumkin. Bu degani, barcha uchastkalarning balandligini to'g'ridan-to'g'ri massivda saqlash mumkin emas. Biroq, shamol zarbalari soni ($n$) va so'rovlar soni ($m$) atigi 1000 gacha. Bu esa, biz faqatgina ahamiyatli nuqtalarda, ya'ni shamol zarbalari boshlanadigan ($l_i$), tugaydigan ($r_i+1$) joylarda va so'rov berilgan ($q_j$) nuqtalarda balandlikni hisoblashimiz kerakligini anglatadi.

Shamol zarbasining ta'sirini ko'rib chiqaylik: $l_i$-dan $r_i$-gacha bo'lgan uchastkalarda balandlik $x_i, -x_i, x_i, \dots$ tartibda o'zgaradi.
Agar $k$-chi uchastkaning balandligi o'zgarishini yozsak, u $x_i \cdot (-1)^{k-l_i}$ bo'ladi.
Bu ifodani quyidagicha yozish mumkin: $x_i \cdot (-1)^k \cdot (-1)^{-l_i} = x_i \cdot (-1)^k \cdot (-1)^{l_i}$.
Demak, barcha shamol zarbalari ta'siridan keyingi $k$-chi uchastkaning yakuniy balandligi $H(k)$ quyidagicha bo'ladi:
$H(k) = \sum_{i: l_i \le k \le r_i} x_i \cdot (-1)^k \cdot (-1)^{l_i}$
$H(k) = (-1)^k \cdot \sum_{i: l_i \le k \le r_i} (x_i \cdot (-1)^{l_i})$

Biz $S(k) = \sum_{i: l_i \le k \le r_i} (x_i \cdot (-1)^{l_i})$ deb belgilasak, u holda $H(k) = (-1)^k \cdot S(k)$ bo'ladi.
$S(k)$ qiymati $k$ nuqtada qaysi shamol zarbalari faol (ya'ni, $l_i \le k \le r_i$ shart bajariladi) bo'lsa, ularning $x_i \cdot (-1)^{l_i}$ qiymatlarining yig'indisidir. Bu umumiy "sweep line" (supurish chizig'i) yondashuviga to'g'ri keladi. Biz barcha $l_i, r_i+1$ va $q_j$ nuqtalarni "hodisalar" (events) sifatida to'playmiz, ularni koordinata bo'yicha saralaymiz va chiziq bo'ylab harakatlanayotganda `current_S_sum` ni yangilab boramiz.

## Algoritm qadamlari

1.  **Hodisalarni shakllantirish**:
    *   Har bir $n$ ta shamol zarbasi $(l_i, r_i, x_i)$ uchun ikkita hodisa (event) yaratiladi:
        *   Birinchi hodisa: `coord = l_i`, `type = 1` (boshlash), `value = x_i \cdot (-1)^{l_i}`. Bu hodisa `l_i` nuqtasida `current_S_sum` ga $x_i \cdot (-1)^{l_i}$ qo'shilishini bildiradi.
        *   Ikkinchi hodisa: `coord = r_i + 1`, `type = 0` (tugatish), `value = -(x_i \cdot (-1)^{l_i})`. Bu hodisa `r_i + 1` nuqtasida (ya'ni $r_i$-chi uchastkadan keyin) `current_S_sum` dan $x_i \cdot (-1)^{l_i}$ ayirilishini bildiradi. `value` ni manfiy qilib saqlash orqali har doim `current_S_sum` ga qo'shish operatsiyasini bajarish mumkin.
    *   Har bir $m$ ta so'rov $q_j$ uchun bitta hodisa yaratiladi:
        *   Hodisa: `coord = q_j`, `type = 2` (so'rov), `value = j` (so'rovning original indeksi).

2.  **Hodisalarni saralash**:
    *   Yaratilgan barcha hodisalarni `coord` (koordinata) bo'yicha o'sish tartibida saralanadi.
    *   Agar ikkita hodisaning `coord` qiymatlari teng bo'lsa, ularning `type` (turi) bo'yicha saralanadi:
        *   `type = 0` (tugatish hodisasi)
        *   `type = 1` (boshlash hodisasi)
        *   `type = 2` (so'rov hodisasi)
    *   Bu tartib muhimdir, chunki bir xil koordinatada: avval tugagan oraliqlar hisobdan chiqarilishi, keyin yangi boshlangan oraliqlar hisobga olinishi va oxirida shu nuqtadagi `current_S_sum` asosida so'rov bajarilishi kerak.

3.  **Hodisalarni qayta ishlash**:
    *   `current_S_sum` deb nomlangan o'zgaruvchi yaratiladi va unga 0 qiymati beriladi. Bu o'zgaruvchi joriy `coord` nuqtasidagi $S(coord)$ qiymatini saqlaydi.
    *   Saralangan hodisalar ketma-ketligi bo'yicha iteratsiya qilinadi:
        *   Agar hodisa `type = 0` (tugatish) bo'lsa: `current_S_sum` ga hodisaning `value` si (manfiy) qo'shiladi.
        *   Agar hodisa `type = 1` (boshlash) bo'lsa: `current_S_sum` ga hodisaning `value` si (musbat) qo'shiladi.
        *   Agar hodisa `type = 2` (so'rov) bo'lsa: `q_coord` va `query_index` (original indeks) olinadi. Yakuniy balandlik $H(q\_coord) = (-1)^{q\_coord} \cdot current\_S\_sum$ formula bo'yicha hisoblanadi. Natija `answers[query_index]` massiviga saqlanadi.

4.  **Natijalarni chop etish**:
    *   `answers` massivida saqlangan barcha natijalar original so'rov tartibida chop etiladi.

## Murakkablik tahlili
-   **Vaqt**:
    *   `N` shamol zarbasi va `M` so'rovlar uchun jami $2N+M$ ta hodisa yaratiladi.
    *   Hodisalarni saralash `O((2N+M) \log (2N+M))` vaqt oladi.
    *   Saralangan hodisalar bo'yicha iteratsiya qilish `O(2N+M)` vaqt oladi.
    *   Shunday qilib, umumiy vaqt murakkabligi `O((N+M) \log (N+M))` ni tashkil qiladi.
    *   `N, M \le 1000` bo'lganligi sababli, $2000 \cdot \log(2000) \approx 2000 \cdot 11 = 22000$ operatsiya juda tez bajariladi va berilgan 1000 ms vaqt limitiga bemalol sig'adi.

-   **Xotira**:
    *   Hodisalar vektorida $2N+M$ ta `Event` strukturalari saqlanadi. Har bir `Event` taxminan 20 bayt (2 `long long` va 1 `int`). Jami $3000 \cdot 20$ bayt = 60 KB.
    *   Javoblar vektorida `M` ta `long long` qiymatlar saqlanadi. Jami $1000 \cdot 8$ bayt = 8 KB.
    *   Umumiy xotira murakkabligi `O(N+M)` bo'lib, bu taxminan 70 KB ni tashkil etadi. Bu berilgan 32 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi (vektor, sort, iostream)

using namespace std; // std nom fazosidan foydalanishni osonlashtiradi

// Event (hodisa) strukturasini aniqlaymiz
struct Event {
    long long coord; // Hodisa sodir bo'ladigan koordinata (uchastka raqami)
    int type;        // Hodisa turi: 0 (tugatish), 1 (boshlash), 2 (so'rov)
    long long value; // Hodisaning qiymati: boshlash/tugatish uchun S(k) ga ta'sir, so'rov uchun original indeks

    // Hodisalarni saralash uchun maxsus solishtiruvchi (operator overloading)
    // 1. Birinchi navbatda koordinata bo'yicha saralanadi.
    // 2. Agar koordinatalar teng bo'lsa, type bo'yicha: 0 (tugatish) < 1 (boshlash) < 2 (so'rov).
    // Bu tartib: avval tugagan oraliqlarni yo'q qilish, keyin boshlanganlarni qo'shish, eng oxirida so'rovni bajarishni ta'minlaydi.
    bool operator<(const Event& other) const {
        if (coord != other.coord) {
            return coord < other.coord;
        }
        return type < other.type;
    }
};

int main() {
    // Kiritish/chiqarish operatsiyalarini tezlashtirish
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; // Shamol zarbalari va so'rovlar soni
    cin >> n >> m;

    vector<Event> events; // Barcha hodisalarni saqlaydigan vektor
    // Vektorga oldindan xotira ajratish (optimallashtirish uchun)
    events.reserve(2 * n + m); 

    // Shamol zarbalarini qayta ishlash
    for (int i = 0; i < n; ++i) {
        long long l, r, x; // Shamol zarbasining chap chegarasi, o'ng chegarasi, kuchi
        cin >> l >> r >> x;

        long long val_contribution = x; // S(k) ga ta'sir qiluvchi qiymatning asosiy qismi
        // (-1)^(l_i) qismini hisoblash: agar l_i toq bo'lsa, ishorani o'zgartiramiz
        if (l % 2 != 0) { // Agar l_i toq bo'lsa
            val_contribution *= -1; // val_contribution = -x
        }
        // Agar l_i juft bo'lsa, val_contribution = x qoladi.
        // Demak, bu val_contribution aslida x_i * (-1)^(l_i) dir.

        // Boshlash hodisasini qo'shamiz: l koordinatada, type 1, val_contribution qiymati bilan
        events.push_back({l, 1, val_contribution});

        // Tugatish hodisasini qo'shamiz: r+1 koordinatada, type 0, -val_contribution qiymati bilan
        // val_contribution manfiy qilib beriladi, shunda current_S_sum ga doim qo'shish mumkin
        events.push_back({r + 1, 0, -val_contribution});
    }

    // So'rovlar uchun javoblarni saqlash uchun vektor
    // original so'rovlar tartibida natijalarni saqlash uchun
    vector<long long> answers(m); 

    // So'rovlarni qayta ishlash
    for (int i = 0; i < m; ++i) {
        long long q_coord; // So'ralayotgan uchastka koordinatasi
        cin >> q_coord;
        // So'rov hodisasini qo'shamiz: q_coord koordinatada, type 2, original indeks `i` ni value sifatida saqlaymiz
        events.push_back({q_coord, 2, (long long)i});
    }

    // Barcha hodisalarni yuqorida aniqlangan qoidalar bo'yicha saralash
    sort(events.begin(), events.end());

    long long current_S_sum = 0; // Joriy nuqtadagi S(k) qiymati (sum_{i: l_i <= k <= r_i} x_i * (-1)^(l_i))

    // Saralangan hodisalar bo'yicha iteratsiya qilish
    for (const auto& event : events) {
        if (event.type == 0) { // Agar hodisa tugatish turida bo'lsa
            // Oraliqning ta'sirini tugatamiz. event.value allaqachon manfiy (original contribution ga nisbatan)
            current_S_sum += event.value; 
        } else if (event.type == 1) { // Agar hodisa boshlash turida bo'lsa
            // Oraliqning ta'sirini boshlaymiz
            current_S_sum += event.value;
        } else { // Agar hodisa so'rov turida bo'lsa (type == 2)
            long long q_coord = event.coord; // So'rov koordinatasi
            int query_index = event.value;   // So'rovning original indeksi

            // Balandlik H(q_coord) = (-1)^(q_coord) * S(q_coord) formula bo'yicha hisoblanadi
            long long H_q = current_S_sum; // S(q_coord)
            // (-1)^(q_coord) faktorini qo'llash: agar q_coord toq bo'lsa, ishorani o'zgartiramiz
            if (q_coord % 2 != 0) { // Agar q_coord toq bo'lsa
                H_q *= -1; // Balandlikning ishorasini teskarisiga o'zgartiramiz
            }
            // Hisoblangan balandlikni original so'rov indeksiga mos joyga saqlaymiz
            answers[query_index] = H_q;
        }
    }

    // Saqlangan javoblarni original so'rov tartibida chop etish
    for (int i = 0; i < m; ++i) {
        cout << answers[i] << "\n";
    }

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
```

## Edge case lar va eslatmalar

1.  **Teng koordinatadagi hodisalar tartibi**: Bu algoritmning eng muhim qismi. Agar bir xil koordinatada tugatish, boshlash va so'rov hodisalari mavjud bo'lsa, ularni to'g'ri tartibda (tugatish -> boshlash -> so'rov) qayta ishlash `current_S_sum` ning so'rov paytida to'g'ri bo'lishini ta'minlaydi. Kodda `Event` strukturasining `operator<` funksiyasi aynan shu tartibni amalga oshiradi.
2.  **`r_i+1` da tugatish**: Shamol zarbasi `r_i` gacha bo'lgan uchastkalarga ta'sir qiladi. Demak, uning ta'siri `r_i` dan keyin, ya'ni `r_i+1` koordinatasidan boshlab tugaydi. Shuning uchun tugatish hodisasini `r_i+1` ga joylashtirish muhim.
3.  **`long long` dan foydalanish**: Koordinatalar $10^9$ gacha, balandliklar $n \cdot x_{max} = 1000 \cdot 1000 = 10^6$ gacha bo'lishi mumkin. Bu qiymatlar `int` turiga sig'ishi mumkin bo'lsa-da, `x_i \cdot (-1)^{l_i}` yig'indisi va `current_S_sum` kabi oraliq hisob-kitoblar `long long` da bo'lishi xavfsizroq, ayniqsa qiymatlar kattalashsa. `coord` (koordinata) ham $10^9$ gacha bo'lgani uchun `long long` turida saqlangan.
4.  **`(-1)^K` ni hisoblash**: Kodda $K \% 2 \ne 0$ sharti orqali $K$ ning toq yoki juft ekanligini tekshirish usuli qulay va samarali hisoblanadi.
5.  **I/O optimallashtirish**: `ios_base::sync_with_stdio(false); cin.tie(0);` qatori katta kirish/chiqish ma'lumotlari (garchi $N, M=1000$ uchun unchalik katta bo'lmasa ham) bilan ishlashda dastur ishini tezlashtiradi.
6.  **`reserve` dan foydalanish**: `events.reserve(2 * n + m);` qatori `vector` ga oldindan yetarli xotira ajratish orqali, `push_back` operatsiyalari paytida vektorning qayta hajmlanishi (reallocation) va ma'lumotlarni ko'chirish bilan bog'liq xarajatlarni kamaytiradi. Bu katta miqdordagi elementlar uchun samaradorlikni oshirishi mumkin.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M080F) platformasidagi **M080F** raqamli **Dunes** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M080F>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M080F, Dunes yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
