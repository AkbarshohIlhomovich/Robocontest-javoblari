---
title: "M073E — To'g'ri chiziq | Robocontest.uz Yechimi"
description: "Robocontest.uz M073E (To'g'ri chiziq) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M073E, To'g'ri chiziq yechimi, robocontest To'g'ri chiziq, M073E c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M073E_togri_chiziq/
lang: uz
---

# M073E — To'g'ri chiziq

## Masala haqida
Rustamga $N$ ta nuqta berilgan bo'lib, har bir nuqtaning $x$ va $y$ koordinatalari butun sonlarda ifodalangan. Uning vazifasi bu nuqtalarning barchasi bitta to'g'ri chiziqda yotish-yotmasligini aniqlashdir. Nuqtalar soni 1000 dan oshmaydi, koordinatalarning mutlaq qiymati esa 10000 dan oshmaydi. Agar nuqtalar bir chiziqda yotsa "HA", aks holda "YO'Q" deb chop etish kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi — dastlabki ikkita nuqta yordamida potentsial to'g'ri chiziqni belgilash, so'ngra qolgan barcha nuqtalarning shu chiziqda yotish-yotmasligini tekshirish. Agar barcha nuqtalar bu chiziq shartini qanoatlantirsa, ular bir to'g'ri chiziqda yotadi. Nuqtalarning kolliniyarligini (bir to'g'ri chiziqda yotishini) tekshirish uchun burchak koeffitsiyentlari tengligidan kelib chiqadigan, ammo bo'lish amalisiz bajariladigan geometrik shartdan foydalaniladi. Bu yondashuv nolga bo'lish muammolarining va suzuvchi nuqtali (floating point) hisoblashlardagi noaniqliklarning oldini oladi.

## Algoritm qadamlari
1.  **Koordinatalarni o'qish**: Kirish ma'lumotlari ikki alohida qatorda berilgan. Har bir qatordagi barcha bo'sh joylar bilan ajratilgan sonlarni o'qib, ularni `std::vector` (dinamik massiv) larda `x_coords` va `y_coords` sifatida saqlab olamiz.
2.  **Boshlang'ich holatlarni tekshirish**: Agar nuqtalar soni (`n`) 2 tadan kam yoki teng bo'lsa ($N \le 2$), istalgan ikkita nuqta doimo bir to'g'ri chiziqda yotadi (yoki bitta nuqta cheksiz ko'p to'g'ri chiziqlarda yotadi). Bu holda to'g'ridan-to'g'ri "HA" deb chop etiladi va dastur yakunlanadi.
3.  **To'g'ri chiziqni aniqlash**: Massivdagi birinchi ikki nuqta ($x_0, y_0$) va ($x_1, y_1$) tanlab olinadi. Bu ikki nuqta biz tekshirmoqchi bo'lgan to'g'ri chiziqni belgilaydi. Bu koordinatalar keyinchalik hisob-kitoblarda int turidan toshib ketmasligi uchun `long long` turiga o'tkaziladi.
4.  **Kolliniyarlikni tekshirish**: Uchta nuqta — ($x_0, y_0$), ($x_1, y_1$) va ($x_i, y_i$) bir to'g'ri chiziqda yotishi uchun ulardan hosil bo'lgan uchburchakning yuzasi nolga teng bo'lishi kerak. Bu holat matematik jihatdan quyidagi shart bilan ifodalanadi: $(x_1 - x_0) \cdot (y_i - y_0) = (x_i - x_0) \cdot (y_1 - y_0)$.
    *   Algoritm uchinchi nuqtadan boshlab ($i=2$) barcha qolgan nuqtalar ($x_i, y_i$) uchun shu shartni tekshirib chiqadi. Har bir nuqtaning koordinatalari ham `long long` turiga o'tkaziladi.
    *   Agar bitta nuqta ham bu shartni qanoatlantirmasa (ya'ni tenglik bajarilmasa), bu barcha nuqtalar bir to'g'ri chiziqda yotmasligini anglatadi. Bu holda darhol "YO'Q" deb chop etiladi va dastur yakunlanadi.
5.  **Natijani chiqarish**: Agar `for` sikli hech qanday nuqta shartni buzmasdan yakunlansa, demak barcha nuqtalar berilgan to'g'ri chiziqda yotadi. Bu holda "HA" deb chop etiladi.

## Murakkablik tahlili
-   **Vaqt**: O(N)
    *   `read_coordinates()` funksiyasi kirish qatoridagi belgilar soniga (`L`) proporsional ravishda vaqt oladi. $N$ nuqta uchun $L$ taxminan $O(N)$ ga teng bo'ladi (koordinatalarning maksimal uzunligi cheklangan).
    *   Asosiy `for` sikli $N-2$ marta ishlaydi. Har bir iteratsiyada faqat bir nechta arifmetik amal (ayirish, ko'paytirish, solishtirish) bajariladi, bu doimiy $O(1)$ vaqtni oladi.
    *   Shunday qilib, umumiy vaqt murakkabligi $O(N)$ bo'ladi.
-   **Xotira**: O(N)
    *   `x_coords` va `y_coords` vektorlari har biri $N$ ta butun sonni saqlaydi.
    *   Shunday qilib, umumiy xotira murakkabligi $O(N)$ bo'ladi.
-   **Nega shu murakkablik chegaraga sig'adi**:
    *   $N \le 1000$ bo'lganligi sababli, $O(N)$ vaqt murakkabligi juda tez hisoblanadi (taxminan 1000 ta asosiy operatsiya), bu 1000 ms (1 soniya) vaqt chegarasi uchun bemalol yetarli.
    *   $O(N)$ xotira murakkabligi 1000 ta `int` (har biri 4 bayt) uchun taxminan 8 KB (ikki vektor uchun) xotira talab qiladi, bu esa 32 MB xotira chegarasiga bemalol sig'adi.

## Kod izohi

1.  **Sarlavhalar va nomlar fazosi**:
    ```cpp
    #include <bits/stdc++.h> // Standart kutubxona sarlavhalarini o'z ichiga oladi
    using namespace std;     // 'std::' prefiksisiz standart nomlar fazosidan foydalanishga ruxsat beradi
    ```
    *   `#include <bits/stdc++.h>`: Competitive programmingda tezlik uchun keng qo'llaniladigan sarlavha, C++ standart kutubxonasining ko'pgina komponentlarini (masalan, `vector`, `string`, `iostream`, `sstream`) o'z ichiga oladi.
    *   `using namespace std;`: Bu qator `std` nomlar fazosidagi elementlarga (masalan, `cout`, `cin`, `vector`) bevosita kirish imkonini beradi.

2.  **`read_coordinates()` funksiyasi**:
    ```cpp
    vector<int> read_coordinates() {
        string line;
        getline(cin, line);             // Bir qatorni to'liq string o'laroq o'qiydi
        istringstream iss(line);        // Stringni oqimga (stream) aylantiradi
        vector<int> coords;
        int val;
        while (iss >> val) {            // Oqimdan butun sonlarni bo'sh joy orqali ajratib o'qiydi
            coords.push_back(val);      // O'qilgan sonni vektorga qo'shadi
        }
        return coords;
    }
    ```
    *   Bu yordamchi funksiya kirishdagi har bir qatordan sonlar ketma-ketligini o'qish uchun ishlatiladi.
    *   `getline(cin, line)`: `cin` (standart kiritish oqimi) dan butun bir qatorni `line` nomli `string` o'zgaruvchisiga o'qiydi.
    *   `istringstream iss(line)`: `line` stringini `istringstream` obyektiga o'tkazadi. Bu bizga stringni xuddi `cin` dan o'qiyotgandek, ya'ni bo'sh joylar bilan ajratilgan qiymatlarni bitta-bitta o'qish imkonini beradi.
    *   `while (iss >> val)`: `iss` oqimidan navbatdagi butun sonni `val` o'zgaruvchisiga o'qishga harakat qiladi. Agar o'qish muvaffaqiyatli bo'lsa, sikl davom etadi.
    *   `coords.push_back(val)`: O'qilgan sonni `coords` vektoriga oxiridan qo'shadi.

3.  **`main()` funksiyasi**:
    ```cpp
    int main() {
        ios_base::sync_with_stdio(false); // C++ oqimlari va C stdio sinxronizatsiyasini o'chiradi
        cin.tie(0);                       // `cin` va `cout` orasidagi bog'liqlikni bekor qiladi (tezroq kiritish/chiqarish uchun)

        vector<int> x_coords = read_coordinates(); // x koordinatalarini o'qiydi
        vector<int> y_coords = read_coordinates(); // y koordinatalarini o'qiydi

        int n = x_coords.size(); // Nuqtalar sonini aniqlaydi

        if (n <= 2) {            // Agar 2 yoki undan kam nuqta bo'lsa, ular doimo bir chiziqda yotadi
            cout << "HA\n";
            return 0;
        }

        // Birinchi ikki nuqtani tayanch nuqta sifatida olamiz, 'long long'ga o'tkazamiz
        long long x0 = x_coords[0];
        long long y0 = y_coords[0];
        long long x1 = x_coords[1];
        long long y1 = y_coords[1];

        for (int i = 2; i < n; ++i) { // Uchinchi nuqtadan boshlab har bir nuqtani tekshiramiz
            long long xi = x_coords[i];
            long long yi = y_coords[i];

            // Kolliniyarlik shartini tekshiramiz: (x1 - x0)*(yi - y0) == (xi - x0)*(y1 - y0)
            // Agar bu shart bajarilmasa, nuqtalar bir chiziqda yotmaydi
            if ((x1 - x0) * (yi - y0) != (xi - x0) * (y1 - y0)) {
                cout << "YO'Q\n";
                return 0; // Birorta nuqta chiziqda yotmasa, darhol chiqamiz
            }
        }

        cout << "HA\n"; // Barcha nuqtalar tekshiruvdan o'tsa, ular chiziqda yotadi
        return 0;
    }
    ```
    *   `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu qatorlar C++ streamlarining ishlashini tezlashtirish uchun standart optimizatsiyalardir, ayniqsa katta kirish/chiqarish hajmli masalalar uchun muhim.
    *   `read_coordinates()` funksiyasi chaqirilib, $x$ va $y$ koordinatalari `x_coords` va `y_coords` vektorlariga saqlanadi.
    *   `int n = x_coords.size();`: Vektordagi elementlar soni, ya'ni nuqtalar soni aniqlanadi.
    *   `if (n <= 2)` bloki: Bu yerda yuqorida aytib o'tilgan boshlang'ich holat tekshiriladi.
    *   `long long x0 = x_coords[0];` va boshqalar: Dastlabki ikki nuqtaning koordinatalari `long long` turiga o'tkaziladi. Bu hisoblashlarda int to'lib ketishining (integer overflow) oldini olish uchun juda muhim, chunki koordinatalar ayirmasi 20000 ga, ularning ko'paytmasi esa $4 \times 10^8$ gacha borishi mumkin, bu `int` turining chegarasiga yaqin.
    *   `for (int i = 2; i < n; ++i)` sikli: Bu sikl uchinchi nuqtadan boshlab (indeks 2) barcha qolgan nuqtalar ustida takrorlanadi.
    *   `long long xi = x_coords[i]; long long yi = y_coords[i];`: Joriy tekshirilayotgan nuqtaning koordinatalari ham `long long` turiga o'tkaziladi.
    *   `if ((x1 - x0) * (yi - y0) != (xi - x0) * (y1 - y0))`: Bu blok kolliniyarlik shartini tekshiradi. Agar shart bajarilmasa, joriy nuqta boshlang'ich ikki nuqta aniqlagan to'g'ri chiziqda yotmaydi. Bu holda "YO'Q" chiqarilib, dastur yakunlanadi.
    *   Agar sikl muvaffaqiyatli yakunlansa, demak barcha nuqtalar bir to'g'ri chiziqda yotadi va "HA" chiqariladi.

## Edge case lar va eslatmalar
*   **Kam sonli nuqtalar**: Agar nuqtalar soni 0, 1 yoki 2 bo'lsa, ular har doim bir to'g'ri chiziqda yotadi. Yechim bu holatni `if (n <= 2)` sharti bilan to'g'ri boshqaradi.
*   **Koordinata qiymatlari diapazoni va `long long` dan foydalanish**: Berilgan koordinatalarning mutlaq qiymati 10000 gacha. Ikki koordinata ayirmasi maksimal $10000 - (-10000) = 20000$ bo'lishi mumkin. Bu ayirmalarning ko'paytmasi $20000 \times 20000 = 400,000,000$ (400 million) gacha bo'lishi mumkin. Bu qiymat odatdagi 32-bit `int` turiga sig'sa-da (maksimal qiymat taxminan $2 \times 10^9$), agar koordinatalar kattaroq (masalan, $10^5$) bo'lganda edi, ko'paytma $10^{10}$ bo'lib, `int` dan toshib ketardi. Shuning uchun, bunday ko'paytmalar uchun `long long` turidan foydalanish xavfsizlik va kodning mustahkamligini ta'minlaydi.
*   **Bo'lishdan qochish**: Uchta nuqtaning kolliniyarligini tekshirish uchun burchak koeffitsienti ($k = \frac{y_2 - y_1}{x_2 - x_1}$) formulasidan foydalanishda $x_2 - x_1 = 0$ bo'lganda nolga bo'lish (vertikal chiziqlar) muammosi yuzaga kelishi mumkin. Shuningdek, suzuvchi nuqtali (float/double) sonlar bilan ishlashda hisoblash noaniqliklari ham muammolarga olib kelishi mumkin. Shu sababli, `(x1 - x0) * (yi - y0) = (xi - x0) * (y1 - y0)` ko'paytma shaklidagi shartdan foydalanish eng to'g'ri va xavfsiz yondashuv hisoblanadi.
*   **Bir xil nuqtalar**: Agar dastlabki ikki nuqta `(x0, y0)` va `(x1, y1)` bir xil bo'lsa, ya'ni `x1-x0=0` va `y1-y0=0` bo'lsa ham, kolliniyarlik sharti `0 * (yi - y0) == (xi - x0) * 0`, ya'ni `0 == 0` bo'lib, har doim bajariladi. Bu to'g'ri natijaga olib keladi, chunki barcha nuqtalar bir xil bo'lsa, ular bir to'g'ri chiziqda yotgan hisoblanadi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M073E) platformasidagi **M073E** raqamli **To'g'ri chiziq** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M073E>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M073E, To'g'ri chiziq yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
