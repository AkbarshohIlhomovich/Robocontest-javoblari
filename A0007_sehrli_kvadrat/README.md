---
title: "A0007 — Sehrli kvadrat | Robocontest.uz Yechimi"
description: "Robocontest.uz A0007 (Sehrli kvadrat) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0007, Sehrli kvadrat yechimi, robocontest Sehrli kvadrat, A0007 c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# A0007 — Sehrli kvadrat

## Masala haqida
Ushbu masala 3-tartibli (ya'ni 3x3 o'lchamli) sehrli kvadratlar bilan bog'liq. Sehrli kvadrat deb, elementlari 1 dan $N^2$ gacha bo'lgan har xil sonlardan tashkil topgan, har bir satr, har bir ustun, hamda asosiy va qo'shimcha diagonallari yig'indisi teng bo'lgan matritsaga aytiladi. Berilgan 3x3 matritsani sehrli kvadratga aylantirish uchun minimal qancha energiya sarflanishini topish kerak. Element $a$ ni $b$ ga almashtirish uchun $|a-b|$ energiya sarflanadi.

## Yondashuv (g'oya)
Masala 3x3 o'lchamli sehrli kvadrat haqida bo'lganligi sababli, uning o'lchami kichik va doimiydir. 1 dan 9 gacha bo'lgan sonlardan tashkil topgan barcha 3x3 sehrli kvadratlarning soni juda oz, aniqrog'i 8 tadir. Bu holatda, barcha mumkin bo'lgan sehrli kvadratlarni oldindan aniqlab (yoki kod ichiga kiritib) olish va berilgan matritsani ularning har biriga aylantirish uchun sarflanadigan energiyani hisoblash mumkin. Natijada, ushbu hisoblangan energiya qiymatlari orasidagi eng kichigini topib, javob sifatida chiqarish eng maqbul yondashuv hisoblanadi. Bu yondashuv "exhaustive search" (to'liq qidiruv) deb ataladi, chunki barcha mumkin bo'lgan holatlar ko'rib chiqiladi.

## Algoritm qadamlari
1.  **Kirishni o'qish**: Berilgan 3x3 matritsa (input\_matrix) o'qib olinadi.
2.  **Sehrli kvadratlarni oldindan e'lon qilish**: 1 dan 9 gacha bo'lgan sonlardan tashkil topgan, barcha satrlari, ustunlari va diagonallari yig'indisi 15 ga teng bo'lgan 8 ta noyob 3x3 sehrli kvadratlar ro'yxati (magic\_squares) kod ichida `vector<vector<vector<int>>>` turida e'lon qilinadi.
3.  **Minimal energiyani boshlang'ich holatga keltirish**: Eng kam energiya sarfini saqlash uchun `min_energy` nomli butun son o'zgaruvchisi `INT_MAX` (eng katta butun son) qiymati bilan boshlang'ich holatga keltiriladi.
4.  **Har bir sehrli kvadratni tekshirish**: `magic_squares` ro'yxatidagi har bir sehrli kvadrat uchun quyidagi amallar bajariladi:
    *   **Joriy energiya sarfini hisoblash**: `current_energy` nomli butun son o'zgaruvchisi 0 ga o'rnatiladi.
    *   Berilgan `input_matrix` ning har bir elementi va joriy tekshirilayotgan sehrli kvadratning mos keluvchi elementi orasidagi farqning mutlaq qiymati (`abs(input_matrix[i][j] - current_magic_square[i][j])`) hisoblanadi va `current_energy` ga qo'shib boriladi. Bu jarayon matritsaning barcha 9 ta elementi uchun takrorlanadi.
    *   **Minimal energiyani yangilash**: `min_energy` o'zgaruvchisi `min(min_energy, current_energy)` funksiyasi yordamida yangilanadi. Ya'ni, topilgan eng kichik energiya qiymati saqlab qolinadi.
5.  **Natijani chiqarish**: Barcha sehrli kvadratlar tekshirib bo'lingach, `min_energy` o'zgaruvchisida saqlangan qiymat (eng kam energiya sarfi) ekranga chiqariladi.

## Murakkablik tahlili
-   **Vaqt**: O(1)
    *   Kirish matritsasini o'qish doimiy vaqt oladi (3x3).
    *   Sehrli kvadratlar ro'yxati oldindan aniqlangan va doimiy hajmli (8 ta kvadrat, har biri 3x3).
    *   Asosiy sikl doimiy ravishda 8 marta takrorlanadi. Har bir takrorlashda 3x3 matritsaning 9 ta elementini taqqoslash va farqni hisoblash doimiy vaqt oladi.
    *   Shunday qilib, umumiy vaqt murakkabligi kirish o'lchamiga bog'liq emas va doimiy hisoblanadi.
-   **Xotira**: O(1)
    *   `input_matrix` 3x3 butun sonlar saqlaydi (doimiy xotira).
    *   `magic_squares` 8 ta 3x3 butun sonlar matritsasini saqlaydi (doimiy xotira).
    *   Boshqa o'zgaruvchilar ham doimiy xotira egallaydi.
    *   Shunday qilib, umumiy xotira murakkabligi doimiy hisoblanadi.
-   **Nega shu murakkablik chegaraga sig'adi**: Berilgan vaqt (1000 ms) va xotira (16 MB) limitlari uchun O(1) vaqt va xotira murakkabligi mutlaqo yetarli. Amalda kod bir necha millisekundda ishlaydi va juda oz xotira ishlatadi.

## Kod izohi
-   `#include <bits/stdc++.h>`: C++ standart kutubxonalarining ko'pini o'z ichiga oluvchi sarlavha fayl. `vector`, `abs`, `min`, `INT_MAX` kabi funksiyalar va turlar uchun kerak.
-   `using namespace std;`: `std` nomlar fazosidagi obyekt va funksiyalarni bevosita ishlatish imkonini beradi.
-   `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu qatorlar C++ kirish/chiqish oqimlarini (standart C funksiyalari bilan) sinxronizatsiyani o'chiradi va `cin` ning `cout` bilan bog'lanishini bekor qiladi. Bu katta hajmli kirish/chiqish operatsiyalarida dastur tezligini oshirishga yordam beradi, garchi bu masala uchun unchalik muhim bo'lmasa-da, bu competitive programmingda standart amaliyotdir.
-   `vector<vector<int>> input_matrix(3, vector<int>(3));`: 3x3 o'lchamli, butun sonlardan iborat ikki o'lchamli `vector` (matritsa) e'lon qilinadi. Bu kirish matritsasini saqlash uchun ishlatiladi.
-   `for (int i = 0; i < 3; ++i) { for (int j = 0; j < 3; ++j) { cin >> input_matrix[i][j]; } }`: Ichki va tashqi sikllar yordamida kirish matritsasining 9 ta elementi o'qib olinadi.
-   `vector<vector<vector<int>>> magic_squares = { ... };`: Bu yerda 8 ta mumkin bo'lgan 3x3 sehrli kvadratlar (har biri 1 dan 9 gacha bo'lgan sonlardan iborat, sehrli yig'indi 15 ga teng) `vector`lar `vector`i sifatida e'lon qilingan. Bu C++11 va undan keyingi versiyalarda mavjud bo'lgan initializer list (boshlang'ich qiymatlar ro'yxati) sintaksisidan foydalanib amalga oshiriladi.
-   `int min_energy = INT_MAX;`: `min_energy` o'zgaruvchisi `INT_MAX` bilan boshlang'ich holatga keltiriladi. Bu natijaning to'g'ri minimal qiymat bilan boshlanishini ta'minlaydi.
-   `for (const auto& ms : magic_squares) { ... }`: Bu `for-each` sikli `magic_squares` kolleksiyasining har bir elementini (ya'ni har bir sehrli kvadratni) ketma-ket `ms` o'zgaruvchisiga o'zgartirilmaydigan referans (`const auto&`) sifatida o'tkazib chiqadi.
-   `int current_energy = 0;`: Har bir sehrli kvadrat uchun unga o'zgartirish uchun kerak bo'ladigan energiya hisobini saqlash uchun `current_energy` o'zgaruvchisi e'lon qilinadi va 0 ga o'rnatiladi.
-   `current_energy += abs(input_matrix[i][j] - ms[i][j]);`: Bu ichki sikllarda `input_matrix` ning $(i, j)$-elementi va joriy `ms` sehrli kvadratining $(i, j)$-elementi orasidagi farqning mutlaq qiymati hisoblanib, `current_energy` ga qo'shiladi. `abs()` funksiyasi mutlaq qiymatni qaytaradi.
-   `min_energy = min(min_energy, current_energy);`: Hisoblangan `current_energy` va hozirgi `min_energy` orasidagi kichigini topib, `min_energy` ni yangilaydi.
-   `cout << min_energy << endl;`: Oxirgi natija, ya'ni eng kam energiya sarfi ekranga chiqariladi.
-   `return 0;`: Dasturning muvaffaqiyatli yakunlanganini bildiradi.

## Edge case lar va eslatmalar
-   **Kichik va doimiy o'lcham**: Masala faqat 3x3 matritsalar uchun berilganligi, umumiy N-tartibli sehrli kvadratlar generatsiyasi algoritmlarini talab qilmasligi uni ancha soddalashtiradi. Bu juda muhim cheklashdir.
-   **Oldindan belgilangan sehrli kvadratlar**: 3x3 o'lchamli va 1 dan 9 gacha bo'lgan sonlardan tashkil topgan barcha sehrli kvadratlar oldindan ma'lum. Kodda ularning barchasi ro'yxat sifatida kiritilgan. Bu ro'yxatning to'g'riligi va to'liqligi yechimning aniqligini ta'minlaydi.
-   **Elementlarning o'zgarishi**: Kirish matritsasidagi elementlar 1 dan 9 gacha bo'lmasligi mumkin (faqat misollarda shu oraliq berilgan, masala matnida `[1...9]` oraliq deb yozilgan, lekin bu shart *natijaviy* sehrli kvadratga tegishli). Energiya hisoblash faqat elementlar orasidagi mutlaq farqqa asoslanadi, shuning uchun kirishdagi qiymatlar 1..9 oralig'idan tashqariga chiqsa ham algoritm to'g'ri ishlaydi. Masala matnida kiruvchi ma'lumotlar `[1...9]` oralig'idagi butun sonlar kiritiladi deb aniq ko'rsatilgan.
-   **Sehrli yig'indi**: 3x3 o'lchamli va 1 dan 9 gacha bo'lgan elementlarga ega sehrli kvadratlarning sehrli yig'indisi har doim $(1+2+...+9)/3 = 45/3 = 15$ ga teng bo'ladi. Bu hisoblashda ishlatilgan sehrli kvadratlarning barchasi bu xususiyatga javob beradi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0007) platformasidagi **A0007** raqamli **Sehrli kvadrat** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0007>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0007, Sehrli kvadrat yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
