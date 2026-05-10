---
title: "M040D — Yong’oqlar | Robocontest.uz Yechimi"
description: "Robocontest.uz M040D (Yong’oqlar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M040D, Yong’oqlar yechimi, robocontest Yong’oqlar, M040D c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M040D_yongoqlar/
lang: uz
---

# M040D — Yong’oqlar

## Masala haqida
Ushbu masalada uch do'st — Dilshod, Sardor va Rustamlar ma'lum bir miqdordagi umumiy `S` yong'oqni o'zaro bo'lishishlari kerak. Taqsimot shartlariga ko'ra, Sardor Dilshod va Rustam olgan yong'oqlar yig'indisidan ikki barobar ko'p oladi. Rustam esa Dilshod bilan teng miqdorda yong'oq olishga rozi bo'lgan. Bizga yong'oqlarning umumiy soni (`S`) beriladi va har bir do'st qancha yong'oq olganini topishimiz talab qilinadi.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi – berilgan shartlar asosida har bir do'st olgan yong'oqlar sonini umumiy yong'oqlar soni (`S`) orqali ifodalaydigan tenglamalar sistemasini tuzish va uni yechish. Masalaning shartlari aniq va doimiy bo'lganligi sababli, har bir do'stning yong'oq sonini `S` ning ma'lum bir ulushi sifatida ifodalash mumkin. Bu esa to'g'ridan-to'g'ri hisoblash (direct computation) yondashuvini qo'llash imkonini beradi.

## Algoritm qadamlari
1.  Dilshod olgan yong'oqlar sonini `D`, Sardornikini `Sar` va Rustamnikini `R` deb belgilaymiz.
2.  Masala shartlariga ko'ra tenglamalar tuzamiz:
    *   **Rustam Dilshod bilan teng olgan:** `R = D`
    *   **Sardor Dilshod va Rustamning yig'indisidan 2 barobar ko'p olgan:** `Sar = 2 * (D + R)`
    *   **Umumiy yong'oqlar soni:** `S = D + Sar + R`
3.  Bu tenglamalar sistemasini yechamiz:
    *   Birinchi tenglamani (`R = D`) ikkinchi tenglamaga qo'yamiz:
        `Sar = 2 * (D + D)`
        `Sar = 2 * (2 * D)`
        `Sar = 4 * D`
    *   Endi `R = D` va `Sar = 4 * D` ifodalarini uchinchi tenglamaga (umumiy yong'oqlar soni) qo'yamiz:
        `S = D + (4 * D) + D`
    *   Tenglamani soddalashtiramiz:
        `S = 6 * D`
    *   Bundan Dilshod olgan yong'oqlar sonini topamiz:
        `D = S / 6`
4.  Dilshodning yong'oq soni (`D = S / 6`) topilgach, qolgan do'stlarnikini ham topamiz:
    *   **Rustam:** `R = D`
    *   **Sardor:** `Sar = 4 * D`
5.  Kiruvchi ma'lumot, ya'ni `S` sonini o'qib olamiz.
6.  Yuqoridagi formulalar bo'yicha `D`, `Sar` va `R` qiymatlarini hisoblaymiz.
7.  Natijalarni (Dilshod, Sardor, Rustam tartibida) probel bilan ajratib chop etamiz.

## Murakkablik tahlili
-   **Vaqt**: O(1)
    *   Kod doimiy vaqtda ishlaydi, chunki u faqat bir nechta arifmetik amal (bo'lish, ko'paytirish, qo'shish) va kirish/chiqish operatsiyalarini bajaradi. Kiruvchi `S` ning qiymatidan qat'i nazar, amallar soni o'zgarmaydi.
-   **Xotira**: O(1)
    *   Kod faqat bir nechta butun son (integer) o'zgaruvchisini (`S`, `D`, `Sar`, `R`) saqlash uchun doimiy miqdordagi xotiradan foydalanadi. Bu o'zgaruvchilarning hajmi kiruvchi ma'lumotlarning kattaligiga bog'liq emas.
-   **Nega shu murakkablik chegaraga sig'adi**: `S` ning qiymati `10^6` dan kichik ekanligi `int` turidagi o'zgaruvchilardan foydalanishga imkon beradi, chunki `int` odatda `2 * 10^9` gacha qiymatlarni saqlay oladi. O(1) vaqt va xotira murakkabligi berilgan 1000 ms va 16 MB limitlar ichida eng tez va samarali yechim hisoblanadi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // 1
using namespace std;     // 2

int main() {             // 3
    ios_base::sync_with_stdio(false); // 4
    cin.tie(0);                       // 5

    int S;                            // 6
    cin >> S;                         // 7

    int D = S / 6;                    // 8
    int Sar = 4 * D;                  // 9
    int R = D;                        // 10

    cout << D << " " << Sar << " " << R << endl; // 11

    return 0;                         // 12
}
```

1.  `#include <bits/stdc++.h>`: Bu satr C++ standart kutubxonasining barcha asosiy sarlavha fayllarini (masalan, kirish/chiqish funksiyalari uchun `iostream`, matematik funksiyalar uchun `cmath` va hokazo) o'z ichiga oladi. Bu competitive programmingda dasturchining ishini tezlashtirish uchun keng qo'llaniladi.
2.  `using namespace std;`: Bu nom fazosi (namespace) deklaratsiyasi `std` prefiksini yozmasdan (masalan, `std::cout` o'rniga `cout`) standart kutubxona elementlaridan foydalanish imkonini beradi.
3.  `int main() { ... }`: Bu dasturning asosiy funksiyasi bo'lib, C++ dasturlari ijrosi aynan shu yerdan boshlanadi.
4.  `ios_base::sync_with_stdio(false);`: Bu satr C++ oqimlari (`cin`, `cout`) va C standart kirish/chiqish funksiyalari (`scanf`, `printf`) o'rtasidagi sinxronizatsiyani o'chiradi. Bu kirish/chiqish operatsiyalarini sezilarli darajada tezlashtiradi.
5.  `cin.tie(0);`: Bu satr `cin` (kirish oqimi) ni `cout` (chiqish oqimi) dan ajratadi. Odatda `cin` har bir kiritish operatsiyasidan oldin `cout` ni tozalaydi, bu esa sekinlashishga olib kelishi mumkin. Ajratish orqali bu xatti-harakat bekor qilinadi va I/O tezligi oshiriladi.
6.  `int S;`: Yong'oqlarning umumiy sonini saqlash uchun `S` nomli `int` (butun son) turidagi o'zgaruvchi e'lon qilinadi. `int` turi `10^6` dan kichik bo'lgan `S` qiymatini saqlash uchun yetarlidir.
7.  `cin >> S;`: Standart kirish oqimidan (`stdin`) `S` o'zgaruvchisiga qiymat o'qib olinadi.
8.  `int D = S / 6;`: Dilshod olgan yong'oqlar soni hisoblanadi. Yuqorida yechilgan tenglamalar sistemasiga ko'ra, `D` qiymati `S` ni 6 ga bo'lish orqali topiladi. Masala shartiga ko'ra yechim doim mavjudligi kafolatlangan, shuning uchun `S` har doim 6 ga qoldiqsiz bo'linadi.
9.  `int Sar = 4 * D;`: Sardor olgan yong'oqlar soni hisoblanadi. U Dilshod olganining (ya'ni `D` ning) 4 barobari.
10. `int R = D;`: Rustam olgan yong'oqlar soni hisoblanadi. U Dilshod bilan teng yong'oq olgan.
11. `cout << D << " " << Sar << " " << R << endl;`: Hisoblangan `D`, `Sar` va `R` qiymatlari probel (`" "`) bilan ajratilgan holda standart chiqish oqimiga (`stdout`) yoziladi. `endl` belgisi kursorning keyingi qatorga o'tishini va chiqish buferining tozalanishini ta'minlaydi.
12. `return 0;`: `main` funksiyasi 0 qiymatini qaytarish orqali dasturning muvaffaqiyatli yakunlanganligini bildiradi.

## Edge case lar va eslatmalar
*   **Yechim mavjudligi kafolati**: Masala matnida "Yechim mavjudligi kafolatlanadi" deyilgan. Bu `S` har doim 6 ga qoldiqsiz bo'linadigan son bo'ladi degan ma'noni anglatadi. Shuning uchun `S / 6` amali har doim butun son natijasini beradi va biz yong'oqlar soni kasr bo'lishi mumkinligi haqida tashvishlanishimiz shart emas.
*   **Ma'lumotlar diapazoni**: `S < 10^6` sharti `int` turidagi o'zgaruvchilardan foydalanishga imkon beradi, chunki `int` tipi C++ da odatda `2 * 10^9` gacha bo'lgan butun sonlarni saqlay oladi. Hisoblashlarda (masalan, `4 * D`) ham qiymatlar `int` chegarasidan chiqib ketmaydi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M040D) platformasidagi **M040D** raqamli **Yong’oqlar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M040D>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M040D, Yong’oqlar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
