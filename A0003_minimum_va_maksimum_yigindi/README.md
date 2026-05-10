---
title: "A0003 — Minimum va maksimum yig'indi | Robocontest.uz Yechimi"
description: "Robocontest.uz A0003 (Minimum va maksimum yig'indi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Oson. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0003, Minimum va maksimum yig'indi yechimi, robocontest Minimum va maksimum yig'indi, A0003 c++ kod, oson, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /A0003_minimum_va_maksimum_yigindi/
lang: uz
---

# A0003 — Minimum va maksimum yig'indi

## Masala haqida
Bu masala beshta musbat butun son berilganda, ulardan to'rttasini tanlab olinganda hosil bo'lishi mumkin bo'lgan eng kichik va eng katta yig'indini topishni talab qiladi. Kirish ma'lumotlari beshta butun sondan iborat bo'lib, ular `1` dan `10^9` gacha oraliqda bo'lishi mumkin. Natija esa ikkita sonni, ya'ni minimum va maksimum yig'indini bo'sh joy bilan ajratib chiqarishdan iborat.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juda sodda va mantiqiy. Agar bizga beshta son berilgan bo'lsa va ulardan to'rttasini tanlab yig'indi hosil qilishimiz kerak bo'lsa, bu degani biz aslida bitta sonni "tashlab yuborishimiz" kerak.
*   Minimum yig'indini olish uchun, biz umumiy yig'indidan eng katta sonni olib tashlashimiz kerak.
*   Maksimum yig'indini olish uchun, biz umumiy yig'indidan eng kichik sonni olib tashlashimiz kerak.

Shu sababli, algoritm barcha sonlarning umumiy yig'indisini hisoblaydi, so'ngra berilgan sonlar ichidagi eng kichik va eng katta qiymatni topadi.

## Algoritm qadamlari
1.  `std::ios_base::sync_with_stdio(false);` va `std::cin.tie(0);` buyruqlari I/O (kirish/chiqish) operatsiyalarini tezlashtirish uchun ishlatiladi, bu katta hajmdagi ma'lumotlar bilan ishlaganda muhim. Ushbu masala uchun unchalik muhim bo'lmasa-da, bu yaxshi odat.
2.  Besh sonni saqlash uchun `long long` turidagi `std::vector` (dinamik massiv) yaratiladi. `long long` turi tanlanishining sababi shundaki, kiruvchi sonlar `10^9` gacha bo'lishi mumkin, va ularning yig'indisi `5 * 10^9` gacha yetishi mumkin, bu esa `int` turining maksimal qiymatidan (taxminan `2 * 10^9`) oshib ketadi.
3.  Tsikl yordamida beshta son kiritilib, `nums` vektoriga joylashtiriladi.
4.  Barcha sonlarning umumiy yig'indisi (`total_sum`) hisoblanadi.
5.  `min_val` va `max_val` o'zgaruvchilari birinchi son bilan boshlang'ich qiymatga ega bo'ladi.
6.  Ikkinchi tsikl yordamida `nums` vektoridagi qolgan sonlar bo'yicha iteratsiya qilinadi (birma-bir ko'rib chiqiladi). Har bir son `min_val` va `max_val` bilan solishtirilib, eng kichik va eng katta qiymatlar topiladi.
7.  Minimum yig'indi (`min_sum_of_four`) `total_sum` dan `max_val` ni ayirish orqali hisoblanadi.
8.  Maksimum yig'indi (`max_sum_of_four`) `total_sum` dan `min_val` ni ayirish orqali hisoblanadi.
9.  Natijalar (`min_sum_of_four` va `max_sum_of_four`) bo'sh joy bilan ajratilgan holda ekranga chiqariladi.

## Murakkablik tahlili
*   **Vaqt murakkabligi**: O(1)
    *   Masala kirish hajmi doimiy (5 ta son) bo'lganligi sababli, algoritm bajaradigan operatsiyalar soni ham doimiy hisoblanadi.
    *   Besh sonni o'qish, ularning yig'indisini hisoblash va eng kichik/eng katta qiymatni topish har biri doimiy sonli amallarni talab qiladi. Shuning uchun umumiy vaqt murakkabligi O(1) ga teng.
*   **Xotira murakkabligi**: O(1)
    *   Biz faqat beshta sonni saqlash uchun `std::vector` dan foydalanamiz, bu ham doimiy hajmda (5 ta `long long`). Bir nechta yordamchi o'zgaruvchilar ( `total_sum`, `min_val`, `max_val` ) ham doimiy miqdordagi xotirani egallaydi. Shuning uchun umumiy xotira murakkabligi O(1) ga teng.
*   **Nega shu murakkablik chegaraga sig'adi**: Berilgan vaqt (1000 ms) va xotira (16 MB) limitlari uchun O(1) vaqt va xotira murakkabligiga ega bo'lgan yechim mutlaqo yetarli. Bu yechim juda tez va minimal xotira resurslarini talab qiladi.

## Kod izohi

```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun (std::cin, std::cout)
#include <vector>   // Dinamik massiv (std::vector) uchun
#include <numeric>  // Bu masalada ishlatilmagan, lekin ba'zi hollarda yig'indi hisoblash uchun kerak bo'lishi mumkin (std::accumulate)
#include <algorithm> // Bu masalada ishlatilmagan, lekin ba'zi hollarda min/max topish uchun kerak bo'lishi mumkin (std::min, std::max)

int main() {
    // I/O (kirish/chiqish) tezligini oshirish.
    // std::ios_base::sync_with_stdio(false) C++ streamlarini C standart I/O bilan sinxronizatsiyadan chiqaradi.
    // std::cin.tie(0) std::cin ni std::cout bilan bog'lanishini bekor qiladi, bu esa std::cin dan oldin std::cout ni flush qilishni oldini oladi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // Beshta sonni saqlash uchun long long turidagi vector yaratish.
    // Sonlar 10^9 gacha bo'lishi mumkinligi sababli, yig'indi int chegarasidan oshib ketishi mumkin.
    std::vector<long long> nums(5);
    // Beshta sonni o'qish va vectorga joylash.
    for (int i = 0; i < 5; ++i) {
        std::cin >> nums[i];
    }

    // Barcha sonlarning umumiy yig'indisini hisoblash.
    long long total_sum = 0;
    for (long long num : nums) { // Range-based for loop yordamida vector elementlari bo'ylab iteratsiya qilish.
        total_sum += num;
    }

    // Eng kichik va eng katta sonni topish uchun boshlang'ich qiymatlarni belgilash.
    // Birinchi elementni boshlang'ich min va max deb olamiz.
    long long min_val = nums[0];
    long long max_val = nums[0];

    // Vectorning qolgan elementlari (ikkinchisidan boshlab) bo'ylab iteratsiya qilib,
    // eng kichik va eng katta qiymatlarni yangilash.
    for (int i = 1; i < 5; ++i) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }

    // To'rtta sonning minimum yig'indisini hisoblash: umumiy yig'indidan eng katta sonni ayirish.
    long long min_sum_of_four = total_sum - max_val;
    // To'rtta sonning maksimum yig'indisini hisoblash: umumiy yig'indidan eng kichik sonni ayirish.
    long long max_sum_of_four = total_sum - min_val;

    // Natijalarni ekranga chiqarish.
    std::cout << min_sum_of_four << " " << max_sum_of_four << std::endl;

    return 0; // Dasturning muvaffaqiyatli yakunlanganligini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Musbat butun sonlar**: Masala shartida faqat musbat butun sonlar berilishi aytilgan, shuning uchun nol yoki manfiy sonlar bilan bog'liq maxsus holatlarni ko'rib chiqish shart emas.
*   **Katta sonlar va `long long`**: Sonlar `10^9` gacha bo'lganligi sababli, ularning yig'indisi `int` ma'lumot turining sig'imidan oshib ketishi mumkin. Shu sababli, barcha yig'indi va individual sonlarni saqlash uchun `long long` ma'lumot turidan foydalanish muhimdir. Aks holda, overflow (qiymat chegarasidan chiqib ketish) sodir bo'lishi va noto'g'ri natijalar berilishi mumkin.
*   **Bitta sonni tashlab yuborish mantiqi**: Bu masala uchun eng muhim tushuncha, to'rtta sonni tanlash — bu bitta sonni tashlab yuborishga teng ekanligidir. Bu tushuncha yechimni juda soddalashtiradi.
*   **Kod samaradorligi**: Kod `std::min_element` va `std::max_element` kabi standart kutubxona funksiyalaridan foydalanmasdan min/max qiymatlarini topadi. Bu unchalik farq qilmasa-da, doimiy kichik hajmli ma'lumotlar bilan ishlaganda o'zimizning oddiy tsikl yozish kutubxona funksiyalarini chaqirishdan biroz tezroq bo'lishi mumkin. Umumiy samaradorlik O(1) bo'lib qoladi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0003) platformasidagi **A0003** raqamli **Minimum va maksimum yig'indi** masalasi. U **Oson** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0003>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0003, Minimum va maksimum yig'indi yechimi, robocontest masalalari, c++17, olimpiada yechimi, oson, dasturlash uzbek, competitive programming O'zbekiston.</sub>
