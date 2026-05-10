---
title: "M072A — Robocontestdagi rating tizimi | Robocontest.uz Yechimi"
description: "Robocontest.uz M072A (Robocontestdagi rating tizimi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M072A, Robocontestdagi rating tizimi yechimi, robocontest Robocontestdagi rating tizimi, M072A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M072A_robocontestdagi_rating_tizimi/
lang: uz
---

# M072A — Robocontestdagi rating tizimi

## Masala haqida
Bu masalada Robocontest.uz platformasidagi foydalanuvchining butun son ko'rinishidagi reytingi (`X`) beriladi. Vazifa esa berilgan reyting qiymatiga mos keluvchi darajani (Division) aniqlab, uni chop etishdan iborat. Darajalar belgilangan reyting diapazonlariga mos keladi: Master (2000-2199), Candidate Master (1800-1999), Expert (1700-1799), Specialist (1600-1699), va Pupil (0-1599).

## Yondashuv (g'oya)
Masalani hal qilishning asosiy g'oyasi – berilgan reytingni belgilangan diapazonlar bilan solishtirish. Bu jarayonni eng samarali tarzda bajarish uchun shartli operatorlar, xususan `if-else if-else` zanjiridan foydalanamiz. Diapazonlarni eng yuqori reytingdan boshlab tekshirish mantiqiy xatoliklarni oldini oladi, chunki shartlar bir-biriga zid kelmasdan, har bir reytingni faqat bitta to'g'ri darajaga moslashtiradi.

## Algoritm qadamlari
1.  **Kirishni o'qish**: Foydalanuvchining `X` reytingini kirishdan butun son sifatida o'qib olinadi.
2.  **Master darajasi tekshiruvi**: Agar `X` reyting 2000 yoki undan katta bo'lsa, "Master" chop etiladi.
3.  **Candidate Master darajasi tekshiruvi**: Aks holda (ya'ni, `X` 2000 dan kichik bo'lsa), agar `X` reyting 1800 yoki undan katta bo'lsa, "Candidate Master" chop etiladi.
4.  **Expert darajasi tekshiruvi**: Aks holda, agar `X` reyting 1700 yoki undan katta bo'lsa, "Expert" chop etiladi.
5.  **Specialist darajasi tekshiruvi**: Aks holda, agar `X` reyting 1600 yoki undan katta bo'lsa, "Specialist" chop etiladi.
6.  **Pupil darajasi tekshiruvi**: Yuqoridagi shartlarning hech biri bajarilmasa (ya'ni, `X` reyting 1600 dan kichik bo'lsa), "Pupil" chop etiladi.

## Murakkablik tahlili
-   **Vaqt**: O(1) (Doimiy vaqt). Algoritm doimiy miqdordagi amallarni bajaradi. Kirish sonidan qat'i nazar (bu yerda bitta butun son), har doim bir xil, cheklangan sonli taqqoslashlar (if-else if shartlari) amalga oshiriladi.
-   **Xotira**: O(1) (Doimiy xotira). Dastur bitta butun sonli o'zgaruvchi (`X`) uchun doimiy miqdorda xotira ishlatadi. Bu xotira miqdori kiritilgan `X` qiymatiga bog'liq emas.
-   **Nega shu murakkablik chegaraga sig'adi**: Berilgan 1000 ms vaqt va 32 MB xotira limiti uchun O(1) vaqt va xotira murakkabligi eng optimal hisoblanadi. Dastur bir necha millisekund ichida tugaydi va bir necha kilobayt xotira ishlatadi, bu berilgan cheklovlardan ancha past.

## Kod izohi

```cpp
#include <bits/stdc++.h>
using namespace std;
```
Bu qism C++ dasturlash tilidagi standart kutubxonalarni o'z ichiga oladi. `#include <bits/stdc++.h>` barcha standart kutubxonalarni (masalan, kiritish/chiqarish uchun `iostream`) o'z ichiga oluvchi to'plam hisoblanadi. `using namespace std;` esa standart nomlar maydonidan (namespace) elementlarga (`cout`, `cin` kabi) to'g'ridan-to'g'ri kirish imkonini beradi.

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
```
`main` funksiyasi C++ dasturining asosiy bajariladigan qismidir.
`ios_base::sync_with_stdio(false);` va `cin.tie(0);` qatorlari C++ dagi kiritish/chiqarish (I/O) amallarini tezlashtirish uchun ishlatiladi. `sync_with_stdio(false)` C tilining standart I/O kutubxonalari bilan sinxronizatsiyani o'chiradi, bu esa `cin` va `cout` ning tezroq ishlashiga yordam beradi. `cin.tie(0)` esa `cout` ni `cin` ga bog'lashni bekor qiladi, ya'ni `cin` chaqirilganda `cout` buferini avtomatik tozalash (flush) shart emas. Bu, ayniqsa, katta hajmdagi kiritish/chiqarish operatsiyalarida dasturning ishlash tezligini oshiradi.

```cpp
    int X;
    cin >> X;
```
Bu qismda `X` nomli butun son (integer) turidagi o'zgaruvchi e'lon qilinadi. So'ngra `cin >> X;` operatori yordamida foydalanuvchi tomonidan kiritilgan reyting qiymati shu `X` o'zgaruvchisiga o'qib olinadi.

```cpp
    if (X >= 2000) {
        cout << "Master\n";
    } else if (X >= 1800) {
        cout << "Candidate Master\n";
    } else if (X >= 1700) {
        cout << "Expert\n";
    } else if (X >= 1600) {
        cout << "Specialist\n";
    } else {
        cout << "Pupil\n";
    }
```
Bu kod bloki dasturning asosiy mantiqiy qismidir. U `if-else if-else` shartli operatorlar zanjiri yordamida `X` reytingiga qarab mos darajani aniqlaydi va chop etadi:
-   Birinchi `if (X >= 2000)` sharti agar `X` 2000 dan katta yoki unga teng bo'lsa, "Master" darajasini chop etadi.
-   Agar birinchi shart bajarilmasa, keyingi `else if (X >= 1800)` sharti tekshiriladi. Bu holatda, `X` 1800 dan katta yoki teng, lekin 2000 dan kichik bo'ladi (chunki birinchi `if` bajarilmagan). Bu "Candidate Master" ga mos keladi.
-   Shu tarzda, keyingi `else if` shartlari "Expert" (1700-1799 diapazoni uchun) va "Specialist" (1600-1699 diapazoni uchun) darajalarini aniqlaydi.
-   Agar yuqoridagi `if` va barcha `else if` shartlari bajarilmasa, bu `X` ning 1600 dan kichik ekanligini bildiradi. Bu holda eng oxirgi `else` bloki bajariladi va "Pupil" darajasi (0-1599 diapazoni uchun) chop etiladi.

```cpp
    return 0;
}
```
`return 0;` qatori `main` funksiyasi muvaffaqiyatli yakunlanganligini bildiradi va dasturni tugatadi.

## Edge case lar va eslatmalar
-   **Chegara qiymatlari (Boundary values)**: Masalaning shartlarida `0 <= X <= 2199` ekanligi berilgan. Yechim bu chegaralarni to'g'ri qamrab oladi:
    -   `X = 0`, `X = 1599`: `Pupil` darajasini to'g'ri aniqlaydi.
    -   `X = 1600`: `Specialist` darajasini to'g'ri aniqlaydi.
    -   `X = 1799`: `Expert` darajasini to'g'ri aniqlaydi.
    -   `X = 1800`: `Candidate Master` darajasini to'g'ri aniqlaydi.
    -   `X = 1999`: `Candidate Master` darajasini to'g'ri aniqlaydi.
    -   `X = 2000`, `X = 2199`: `Master` darajasini to'g'ri aniqlaydi.
-   **Shartlarning tartibi**: `if-else if` shartlari eng yuqori reyting diapazonidan (Master) boshlab pastga qarab tekshirilgani juda muhimdir. Bu tartib har bir reytingni faqat bitta, to'g'ri darajaga moslashini ta'minlaydi. Agar shartlar teskari tartibda yozilganda edi (masalan, `if (X >= 0)` bilan boshlanganda), dastur har doim "Pupil" darajasini chiqarib yuborgan bo'lar edi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M072A) platformasidagi **M072A** raqamli **Robocontestdagi rating tizimi** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M072A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M072A, Robocontestdagi rating tizimi yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
