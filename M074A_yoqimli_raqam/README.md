---
title: "M074A — Yoqimli raqam | Robocontest.uz Yechimi"
description: "Robocontest.uz M074A (Yoqimli raqam) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M074A, Yoqimli raqam yechimi, robocontest Yoqimli raqam, M074A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M074A_yoqimli_raqam/
lang: uz
---

# M074A — Yoqimli raqam

## Masala haqida
Diyorbek faqat 5 va 7 raqamlaridan tashkil topgan mashina raqamlarini "yoqimli" deb hisoblaydi. U 1 dan `n` gacha bo'lgan natural sonlar orasida nechta shunday yoqimli son borligini bilmoqchi. Bizning vazifamiz, berilgan `n` (1 dan $10^9$ gacha) uchun 1 va `n` oralig'idagi yoqimli sonlar sonini topish.

## Yondashuv (g'oya)
Masalani yechish uchun kenglik bo'yicha qidiruv (Breadth-First Search - BFS) ga o'xshash yondashuvdan foydalaniladi. Asosiy g'oya — barcha mumkin bo'lgan "yoqimli" sonlarni kichikdan kattaga qarab, raqamlarni birma-bir qo'shish orqali generatsiya qilish. Boshlang'ich nuqta sifatida 0 olinadi va undan 5 hamda 7 bilan tugaydigan sonlar hosil qilinadi. Har bir generatsiya qilingan son `n` dan oshmasa va musbat bo'lsa, uni hisoblab, keyingi sonlarni generatsiya qilish uchun navbatga qo'shamiz. Bu usul, faqat 5 va 7 raqamlaridan tashkil topgan sonlar daraxtini (masalan, 5 dan 55 va 57; 7 dan 75 va 77 kabi) samarali ravishda o'rganish imkonini beradi.

## Algoritm qadamlari
1.  `long long` turidagi `n` sonini kirishdan o'qib oling. Natijani saqlash uchun `int` turidagi `count` (sanoqchi) o'zgaruvchisini 0 ga tenglang.
2.  `long long` turidagi elementlarni saqlaydigan `queue` (navbat) yaratiladi. Dastlab, navbatga `0` raqami kiritiladi. Bu boshlang'ich nuqta bo'lib, keyinchalik birinchi "yoqimli" sonlar (5 va 7) ni hosil qilish uchun "ota" vazifasini bajaradi.
3.  Navbat bo'sh bo'lmaguncha quyidagi qadamlarni takrorlang:
    a.  Navbatning birinchi elementini (`current_num`) oling va uni navbatdan chiqarib tashlang.
    b.  `current_num` dan ikkita yangi son generatsiya qiling:
        i.  `next_num_5 = current_num * 10 + 5` (5 bilan tugaydigan yangi son)
        ii. `next_num_7 = current_num * 10 + 7` (7 bilan tugaydigan yangi son)
    c.  `next_num_5` soni uchun shartni tekshiring: Agar `next_num_5` soni `n` dan kichik yoki teng bo'lsa VA u musbat son bo'lsa (`next_num_5 > 0`):
        i.  `count` ni 1 ga oshiring.
        ii. `next_num_5` ni navbatga qo'shing.
    d.  `next_num_7` soni uchun shartni tekshiring: Agar `next_num_7` soni `n` dan kichik yoki teng bo'lsa VA u musbat son bo'lsa (`next_num_7 > 0`):
        i.  `count` ni 1 ga oshiring.
        ii. `next_num_7` ni navbatga qo'shing.
4.  Navbat bo'sh bo'lgach, `count` ning oxirgi qiymatini chop eting.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(D) yoki aniqrog'i O($2^D$), bu yerda D — `n` dagi raqamlar soni.
    -   `n` ning maksimal qiymati $10^9$ bo'lganligi sababli, "yoqimli" sonlar ko'pi bilan 9 ta raqamdan iborat bo'lishi mumkin (masalan, 777,777,777).
    -   Har bir "yoqimli" son (masalan, 5, 7, 55, 57, ...) bir marta navbatga qo'yiladi va bir marta undan chiqariladi. Chiqarilgan har bir son uchun ikkita yangi son generatsiya qilinadi va chegaraga mos kelish-kelmasligi tekshiriladi.
    -   1 raqamli: 2 ta son (5, 7)
    -   2 raqamli: $2^2 = 4$ ta son
    -   ...
    -   9 raqamli: $2^9 = 512$ ta son
    -   Jami "yoqimli" sonlar soni $2^1 + 2^2 + \dots + 2^9 = 1022$ dan oshmaydi.
    -   Demak, algoritm generatsiya qiladigan va tekshiradigan sonlar soni har doim juda kichik (taxminan 2000 ga yaqin operatsiya). Shuning uchun vaqt murakkabligi amalda O(1) (doimiy vaqt) hisoblanadi.
-   **Xotira murakkabligi**: O(D) yoki O($2^D$)
    -   Navbatda saqlanadigan maksimal sonlar soni, eng uzun "yoqimli" sonlar generatsiya qilinayotgan paytda (masalan, 9 xonali sonlar paydo bo'lganda) sodir bo'ladi.
    -   Navbatda bir vaqtning o'zida maksimal 9 xonali sonlarning barchasi yoki ularning yarmidan ko'pi ($2^8 = 256$ ga yaqin) bo'lishi mumkin.
    -   Bu ham doimiy va juda kichik miqdordagi xotiradan foydalanishni anglatadi, ya'ni amalda O(1) (doimiy xotira).

-   Nega shu murakkablik chegaraga sig'adi: `n` qiymati $10^9$ gacha bo'lsa ham, faqat 5 va 7 raqamlaridan tashkil topgan sonlar soni juda kam. Yuqorida tushuntirilganidek, bunday sonlar atigi 1022 tagacha bo'lishi mumkin. Bu esa algoritmning juda tez ishlashini va minimal xotira talab qilishini ta'minlaydi.

## Kod izohi
-   **Standart kutubxonalar va tezlashtirish**:
    ```cpp
    #include <bits/stdc++.h> // Ko'plab standart kutubxonalarni o'z ichiga oladi
    using namespace std;     // std nom fazosidan foydalanish
    
    int main() {
        ios_base::sync_with_stdio(false); // C++ oqimlari va C stdio o'rtasidagi sinxronizatsiyani o'chiradi
        cin.tie(0); // cin operatsiyasini cout bilan bog'lanishini bekor qiladi
        // Bu qatorlar kirish/chiqish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi.
    ```
    Bu qism, ayniqsa katta hajmdagi ma'lumotlar bilan ishlashda, dasturning tezligini oshirish uchun standart amaliyotdir.

-   **O'zgaruvchilarni e'lon qilish va boshlash**:
    ```cpp
    long long n;     // n sonini saqlash uchun. 10^9 gacha bo'lishi mumkin.
    cin >> n;        // n ni kirishdan o'qiymiz.
    
    queue<long long> q; // Yoqimli sonlarni generatsiya qilish uchun navbat ma'lumot tuzilmasi.
    int count = 0;   // Topilgan yoqimli sonlar soni.
    ```
    `n` va navbatdagi sonlar `long long` turida e'lon qilingan, chunki ular $10^9$ gacha bo'lgan qiymatlarni qabul qilishi mumkin. `count` esa topilgan sonlar soni juda ko'p bo'lmagani uchun `int` bo'lishi yetarli.

-   **Boshlang'ich navbatga qo'shish**:
    ```cpp
    q.push(0); // Dastlabki 5 va 7 ni hosil qilish uchun "placeholder" sifatida 0 ni navbatga qo'shamiz.
    ```
    Bu qadam algoritmning "ildiz" tugunini tashkil qiladi. `0` raqami o'zi "yoqimli" son emas va hisoblanmaydi, lekin u `0 * 10 + 5 = 5` va `0 * 10 + 7 = 7` kabi ilk yoqimli sonlarni samarali yaratish uchun xizmat qiladi.

-   **BFS sikli (sonlarni generatsiya qilish)**:
    ```cpp
    while (!q.empty()) { // Navbat bo'sh bo'lmaguncha siklni davom ettiramiz.
        long long current_num = q.front(); // Navbatning birinchi elementini olamiz.
        q.pop(); // Uni navbatdan chiqarib tashlaymiz.

        // 5 bilan tugaydigan yangi sonni generatsiya qilish
        long long next_num_5 = current_num * 10 + 5;
        // Agar generatsiya qilingan son n dan oshmasa va musbat bo'lsa
        if (next_num_5 <= n && next_num_5 > 0) {
            count++;           // Sanog'ini oshiramiz.
            q.push(next_num_5); // Keyingi generatsiyalar uchun navbatga qo'shamiz.
        }

        // 7 bilan tugaydigan yangi sonni generatsiya qilish
        long long next_num_7 = current_num * 10 + 7;
        // Agar generatsiya qilingan son n dan oshmasa va musbat bo'lsa
        if (next_num_7 <= n && next_num_7 > 0) {
            count++;           // Sanog'ini oshiramiz.
            q.push(next_num_7); // Keyingi generatsiyalar uchun navbatga qo'shamiz.
        }
    }
    ```
    Bu `while` sikli BFS ning asosiy qismidir. Har bir `current_num` dan ikkita yangi son hosil qilinadi (`...5` va `...7`). `next_num_X <= n` sharti sonning `n` chegarasidan oshib ketmasligini tekshiradi. `next_num_X > 0` sharti esa dastlabki `0` raqamini (yoki g'ayritabiiy salbiy sonlarni, bu holatda ro'y bermaydi) hisobga olmaslikni ta'minlaydi. Agar shartlar bajarilsa, `count` oshiriladi va yangi son navbatga kiritiladi.

-   **Natijani chop etish**:
    ```cpp
    cout << count << endl; // Jami topilgan yoqimli sonlar sonini chop etamiz.
    
    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
    ```
    Barcha generatsiya jarayoni tugagach, `count` o'zgaruvchisida to'plangan "yoqimli" sonlar soni chop etiladi.

## Edge case lar va eslatmalar
-   **Kichik `n` qiymatlari**: Masala shartiga ko'ra `1 <= n`. Agar `n` 5 dan kichik bo'lsa (masalan, `n=4`), `count` 0 bo'lib qoladi, chunki eng kichik "yoqimli" son 5. Kod bu holatni to'g'ri boshqaradi.
-   **Sonlarning to'lib ketishi (overflow)**: `n` ning maksimal qiymati $10^9$ bo'lganligi sababli, generatsiya qilinadigan sonlar ham shu chegarada bo'ladi. `long long` ma'lumot turi $9 \times 10^{18}$ gacha bo'lgan sonlarni saqlay oladi, shuning uchun $10^9$ dan oshadigan "yoqimli" sonlar uchun ham to'lib ketish xavfi yo'q.
-   **Boshlang'ich `0` ni kiritish**: `q.push(0)` dan boshlash standart BFS yondashuvida "ildiz" tugunini ifodalaydi. `next_num_X > 0` sharti tufayli bu `0` hech qachon hisobga olinmaydi, lekin u 5 va 7 ni samarali yaratishga yordam beradi.
-   **Optimal tezlik**: `ios_base::sync_with_stdio(false);` va `cin.tie(0);` qatorlari C++ oqimlarining ishlashini sezilarli darajada tezlashtirishi mumkin, ayniqsa katta kirish/chiqish operatsiyalari bo'lgan masalalarda. Ushbu masalada kirish juda kichik bo'lsa-da, bu yaxshi amaliyot.
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M074A) platformasidagi **M074A** raqamli **Yoqimli raqam** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M074A>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M074A, Yoqimli raqam yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
