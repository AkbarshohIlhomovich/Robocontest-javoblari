---
title: "M073A — Vazifalar | Robocontest.uz Yechimi"
description: "Robocontest.uz M073A (Vazifalar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M073A, Vazifalar yechimi, robocontest Vazifalar, M073A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M073A_vazifalar/
lang: uz
---

# M073A — Vazifalar

## Masala haqida
Ushbu masalada sizga uchta vazifa berilgan bo'lib, ularning har biri `A1, A2, A3` qiymatlari bilan ifodalanadi. Birinchi vazifani bajarish uchun hech qanday to'lov olinmaydi. Keyingi har bir vazifani (`j`) avvalgi bajarilgan vazifadan (`i`) keyin bajarish to'lovi `|A_i - A_j|` mutlaq farqiga teng. Sizning vazifangiz barcha uchta vazifani bajarish uchun kerak bo'ladigan minimal umumiy to'lovni topishdir.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi shundaki, biz uchta nuqtani (vazifalarni) joylashuvi bo'yicha bog'laydigan eng qisqa yo'lni topishimiz kerak. Dastlabki vazifa bepul bo'lgani uchun, biz uni istalgan tartibda tanlashimiz mumkin. Keyingi har bir harakat uchun to'lov oldingi vazifa joylashuvi va hozirgi vazifa joylashuvi o'rtasidagi masofaga (mutlaq farqqa) teng.

Agar bizda uchta son bo'lsa, ularni son o'qida tasavvur qilish mumkin. Eng kichik qiymatdan eng katta qiymatgacha bo'lgan masofa har doim barcha uchta nuqtani qamrab oluvchi minimal yo'lni beradi. Chunki, agar biz eng kichik nuqtadan boshlab eng katta nuqtaga borsak (yoki aksincha), bu ikki nuqta orasidagi barcha nuqtalar avtomatik ravishda "bosib o'tilgan" bo'ladi. Vazifalarning qaysi tartibda bajarilishidan qat'i nazar, eng kam umumiy to'lov bu uchta qiymat orasidagi eng katta va eng kichik qiymatning farqiga teng bo'ladi. Masalan, agar vazifalar `2, 5, 6` bo'lsa, eng kichik qiymat `2`, eng katta qiymat `6`. Minimal to'lov `6 - 2 = 4` ga teng bo'ladi. Bunga erishish mumkin, masalan, `2` dan boshlab `6` ga boramiz (to'lov `|2-6|=4`), `5` esa shu orada joylashgan bo'ladi. Yoki `2` dan `5` ga boramiz (to'lov `|2-5|=3`), keyin `5` dan `6` ga boramiz (to'lov `|5-6|=1`). Jami to'lov `3+1=4`.

Shuning uchun, bizga faqat berilgan uchta son orasidan minimum va maksimum qiymatni topib, ularning farqini hisoblash kifoya.

## Algoritm qadamlari
1.  Kirish ma'lumotlaridan `A1, A2, A3` qiymatlarini o'qing.
2.  Uchta `A1, A2, A3` soni orasidan eng kichik qiymatni (minimum) toping.
3.  Uchta `A1, A2, A3` soni orasidan eng katta qiymatni (maksimum) toping.
4.  Eng katta qiymatdan eng kichik qiymatni ayirib, natijani hisoblang.
5.  Hisoblangan natijani chop eting.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(1)`
    Algoritm doimiy vaqtda ishlaydi, chunki u har doim uchta sonni o'qish, ularning minimum va maksimumini topish, hamda bitta ayirish amalini bajaradi. Bu operatsiyalar soni kiritilgan ma'lumotlar hajmiga bog'liq emas (doimiy 3 ta son uchun amalga oshiriladi).
-   **Xotira murakkabligi**: `O(1)`
    Algoritm doimiy xotira maydonidan foydalanadi, chunki u faqat bir nechta butun sonli o'zgaruvchilarni (input sonlari, minimum, maksimum, natija) saqlash uchun ishlatadi. Bu o'zgaruvchilar soni kiritilgan ma'lumotlar hajmiga bog'liq emas.
-   **Nega shu murakkablik chegaraga sig'adi**:
    Berilgan vaqt limiti 1000 ms va xotira limiti 32 MB. `O(1)` vaqt va `O(1)` xotira murakkabligiga ega bo'lgan algoritm ushbu chegaralardan ancha past hisoblanadi (kod 1 ms va 0 KB xotira ishlatgan).

## Kod izohi

```cpp
#include <bits/stdc++.h> // 1
using namespace std;       // 2

int main() {
    ios_base::sync_with_stdio(false); // 3
    cin.tie(0);                        // 4

    int a1, a2, a3; // 5
    cin >> a1 >> a2 >> a3; // 6

    int minimum = min({a1, a2, a3}); // 7
    int maximum = max({a1, a2, a3}); // 8

    int result = maximum - minimum; // 9

    cout << result << endl; // 10

    return 0; // 11
}
```

1.  `#include <bits/stdc++.h>`: Bu qator C++ standart kutubxonasining deyarli barcha bosh fayllarini o'z ichiga oladi. Competitive programmingda tezlikni oshirish uchun keng qo'llaniladi. Bu yerda asosan `iostream` (kirish/chiqish uchun) va `algorithm` (min/max funksiyalari uchun) kerak bo'ladi.
2.  `using namespace std;`: Bu qator `std` nomlar fazosidagi funksiyalar va ob'ektlarga bevosita murojaat qilish imkonini beradi (masalan, `cout` o'rniga `std::cout`).
3.  `ios_base::sync_with_stdio(false);`: C++ `iostream` kutubxonasi (masalan, `cin`, `cout`) va C standart I/O kutubxonasi (masalan, `scanf`, `printf`) o'rtasidagi sinxronizatsiyani o'chiradi. Bu I/O operatsiyalarini tezlashtirishga yordam beradi.
4.  `cin.tie(0);`: Bu qator `cin` ob'ektining `cout` ob'ekti bilan bog'liqligini uzadi. Odatiy holda, har bir `cin` dan oldin `cout` buferini tozalaydi, bu esa sekinlashishga olib kelishi mumkin. Bog'liqlikni uzish I/O ni yanada tezlashtiradi.
5.  `int a1, a2, a3;`: Uchta vazifa qiymatini saqlash uchun uchta `int` (butun son) turidagi o'zgaruvchi e'lon qilinadi.
6.  `cin >> a1 >> a2 >> a3;`: Kirish oqimidan uchta butun sonni o'qib, ularni `a1, a2, a3` o'zgaruvchilariga yuklaydi.
7.  `int minimum = min({a1, a2, a3});`: Bu qator `min` funksiyasidan foydalanib, `a1, a2, a3` qiymatlari orasidagi eng kichikini topadi va uni `minimum` o'zgaruvchisiga saqlaydi. `{a1, a2, a3}` bu `initializer_list` bo'lib, `min` va `max` funksiyalari C++11 standartidan boshlab bunday ro'yxatlar bilan ishlay oladi.
8.  `int maximum = max({a1, a2, a3});`: Xuddi shunday, `max` funksiyasidan foydalanib, `a1, a2, a3` qiymatlari orasidagi eng kattasini topadi va uni `maximum` o'zgaruvchisiga saqlaydi.
9.  `int result = maximum - minimum;`: Eng katta qiymatdan eng kichik qiymatni ayirish orqali yakuniy natijani hisoblaydi va uni `result` o'zgaruvchisiga saqlaydi.
10. `cout << result << endl;`: `result` o'zgaruvchisining qiymatini ekranga (chiqish oqimiga) chop etadi, so'ngra yangi qatorga o'tadi (`endl`).
11. `return 0;`: Dasturning muvaffaqiyatli yakunlanganini bildirib, bosh funksiyadan chiqadi.

## Edge case lar va eslatmalar
*   **Bir xil qiymatlar**: Agar kiritilgan uchta sonning hammasi bir xil bo'lsa (masalan, `5 5 5`), algoritm to'g'ri ishlaydi. `minimum` 5, `maximum` 5 bo'ladi, natija esa `5 - 5 = 0` bo'ladi. Bu mantiqan to'g'ri, chunki barcha vazifalar bir joyda joylashgan bo'lsa, ularni bajarish uchun harakatlanishga to'lov olinmaydi.
*   **Natural sonlar va kichik diapazon**: Masala shartiga ko'ra, `A_i` qiymatlari natural sonlar va 100 dan oshmaydi. Bu `int` turining chegaralariga to'liq mos keladi, shuning uchun butun sonlarning to'lib ketishi (integer overflow) xavfi yo'q. Mutlaq farq `|A_i - A_j|` ham musbat bo'ladi va 100 dan oshmaydi.
*   **Vazifalar tartibi**: Yechim vazifalarning dastlabki tartibiga bog'liq emas. Faqat ularning qiymatlari muhimdir. Algoritm vazifalar orasidan eng kichik va eng kattasini topish orqali barcha mumkin bo'lgan tartiblar orasidagi optimal yechimni bilvosita topadi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M073A) platformasidagi **M073A** raqamli **Vazifalar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M073A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M073A, Vazifalar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
