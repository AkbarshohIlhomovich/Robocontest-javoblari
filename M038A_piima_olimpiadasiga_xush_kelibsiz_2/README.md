---
title: "M038A — PIIMA olimpiadasiga xush kelibsiz #2 | Robocontest.uz Yechimi"
description: "Robocontest.uz M038A (PIIMA olimpiadasiga xush kelibsiz #2) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M038A, PIIMA olimpiadasiga xush kelibsiz #2 yechimi, robocontest PIIMA olimpiadasiga xush kelibsiz #2, M038A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M038A_piima_olimpiadasiga_xush_kelibsiz_2/
lang: uz
---

# M038A — PIIMA olimpiadasiga xush kelibsiz #2

## Masala haqida
Ushbu masalada biz maktab robotiga o'quvchi bilan salomlashishni o'rgatamiz. Dastur kirish sifatida o'quvchining ismini (uzunligi 5 dan 15 belgigacha) oladi va "PIIMA olimpiadasiga xush kelibsiz, X!" ko'rinishida salomlashish xabarini chiqarishi kerak, bu yerda X o'quvchining ismidir. Masala asosan kiritish-chiqarish operatsiyalarini o'zlashtirishga qaratilgan.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juda sodda: dastur kirish oqimidan (odatda konsoldan) o'quvchining ismini o'qib olishi va keyin bu ismni ma'lum bir shablon matniga joylashtirib, chiqish oqimiga (konsolga) chop etishi kerak. Bu masala hech qanday murakkab algoritm yoki ma'lumot tuzilmasini talab qilmaydi, balki dasturlashning eng asosiy qismlaridan biri bo'lgan matnni kiritish va chiqarish (Input/Output) operatsiyalarini namoyish etadi.

## Algoritm qadamlari
1.  **Ismni saqlash uchun o'zgaruvchi e'lon qilish**: O'quvchining ismini saqlash uchun `string` (matn qatori) turidagi o'zgaruvchi e'lon qilinadi.
2.  **Ismni o'qish**: Standart kirish oqimidan (masalan, klaviatura orqali kiritilgan) o'quvchining ismi `string` o'zgaruvchiga o'qib olinadi.
3.  **Xabarni chop etish**: Berilgan shablon matnini ("PIIMA olimpiadasiga xush kelibsiz, ") o'qib olingan ism bilan birlashtirib, so'ngra yakunlovchi belgi ("!") bilan birga standart chiqish oqimiga chop etiladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi (Time Complexity)**: O(L)
    *   Bu yerda `L` o'quvchining ismining uzunligi. Ismni o'qish va chop etish operatsiyalari asosan ismning uzunligiga to'g'ridan-to'g'ri bog'liq. Masala shartiga ko'ra, `L` qiymati 5 dan 15 gacha bo'lganligi sababli, bu juda kichik va amalda doimiy vaqt murakkabligi (O(1)) deb qaralishi mumkin.
-   **Xotira murakkabligi (Space Complexity)**: O(L)
    *   Ismni saqlash uchun `L` belgi joy talab qilinadi. Xuddi vaqt murakkabligida bo'lgani kabi, `L` ning kichik qiymati tufayli bu ham amalda doimiy xotira murakkabligi (O(1)) deb hisoblanadi.
-   **Nega shu murakkablik chegaraga sig'adi**: Masala shartidagi ismning maksimal uzunligi (15 belgi) juda kichik. Shuning uchun, dastur juda tez ishlaydi (natija 1 ms) va juda kam xotira sarflaydi (natija 0 KB), bu belgilangan 1000 ms va 16 MB limitlariga osongina sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // 1
using namespace std;     // 2

int main() {             // 3
    ios_base::sync_with_stdio(false); // 4
    cin.tie(0);                     // 5

    string name;                    // 6
    cin >> name;                    // 7

    cout << "PIIMA olimpiadasiga xush kelibsiz, " << name << "!" << endl; // 8

    return 0;                       // 9
}
```

1.  `#include <bits/stdc++.h>`: Bu qator C++ dasturlash tilida tez-tez ishlatiladigan standart kutubxonalarning deyarli barchasini o'z ichiga oluvchi sarlavha faylidir. Bu masalada bizga asosan matn qatorlari bilan ishlash uchun `string` va kiritish/chiqarish operatsiyalari uchun `iostream` kutubxonalari kerak bo'ladi.
2.  `using namespace std;`: Bu qator `std` (standard) nomfazosidagi (namespace) elementlarga (`cout`, `cin`, `string`, `endl` kabi) bevosita kirish imkonini beradi. Ya'ni, ularni ishlatishda oldidan `std::` prefiksini yozmasdan foydalanish mumkin.
3.  `int main() { ... }`: Har qanday C++ dasturining asosiy kirish nuqtasi. Dastur ishga tushganda, eng avvalo shu funksiya bajariladi.
4.  `ios_base::sync_with_stdio(false);`: Bu buyruq C++ va C tilining standart kiritish/chiqarish (I/O) oqimlari (stream) o'rtasidagi sinxronizatsiyani o'chiradi. Bu katta hajmdagi ma'lumotlar bilan ishlashda I/O operatsiyalarini sezilarli darajada tezlashtiradi.
5.  `cin.tie(0);`: Bu buyruq `cin` (kiritish oqimi) ni `cout` (chiqarish oqimi) dan ajratadi. Odatiy holda, har qanday `cin` operatsiyasidan oldin `cout` avtomatik ravishda tozalangan (flushed) bo'ladi. Bu aloqani uzish I/O tezligini yanada oshiradi. Ushbu masalada kiritish hajmi juda kichik bo'lganligi sababli bu qatorlar unchalik muhim emas, lekin bu samaradorlikni oshirish uchun yaxshi odat (best practice).
6.  `string name;`: Bu yerda `name` nomli `string` (matn qatori) turidagi o'zgaruvchi e'lon qilinadi. Bu o'zgaruvchi o'quvchining ismini saqlash uchun ishlatiladi.
7.  `cin >> name;`: Standart kirish oqimidan (masalan, konsoldan) kiritilgan matnni `name` o'zgaruvchisiga o'qiydi. `cin >>` operatori bo'shliq (space), tab yoki yangi qator (newline) belgisigacha bo'lgan bitta so'zni o'qiydi.
8.  `cout << "PIIMA olimpiadasiga xush kelibsiz, " << name << "!" << endl;`: Bu qator standart chiqish oqimiga (konsolga) xabarni chop etadi.
    *   `"PIIMA olimpiadasiga xush kelibsiz, "`: Doimiy matn qatori.
    *   `name`: Oldin o'qib olingan o'quvchi ismi.
    *   `"!"`: Xabarni yakunlovchi undov belgisi.
    *   `endl`: Yangi qatorga o'tish (newline character) belgisini chiqaradi va chiqish buferini tozalaydi (flush). Bu keyingi chiqishlar yangi qatordan boshlanishini ta'minlaydi.
9.  `return 0;`: `main` funksiyasi muvaffaqiyatli yakunlanganini va hech qanday xatolik yuz bermaganligini bildiruvchi qiymat.

## Edge case lar va eslatmalar
*   **Ism uzunligi cheklovlari**: Masalada ismning uzunligi 5 dan kam emas va 15 belgidan oshmasligi aytilgan. `string` ma'lumot turi bu kabi cheklovlar bilan osongina ishlay oladi va bu masalada hech qanday maxsus ishlov berishni talab qilmaydi.
*   **Bo'shliqli ismlar**: `cin >> name;` operatori faqat bo'shliqgacha bo'lgan bitta so'zni o'qiydi. Agar o'quvchining ismi bo'shliqlarni o'z ichiga olgan bo'lsa (masalan, "Alijon Valiev"), bu operator faqat "Alijon" qismini o'qigan bo'lar edi. Biroq, odatda bu kabi masalalarda ism bir so'zdan iborat bo'lishi nazarda tutiladi. Agar bo'shliqli ismlar kiritilishi mumkin bo'lsa, `getline(cin, name);` funksiyasidan foydalanish kerak bo'ladi.
*   **Maxsus belgilar**: Masala matnida ismda maxsus belgilar bo'lishi haqida hech qanday cheklov yo'q. C++ ning `string` turi har qanday UTF-8 (yoki boshqa kodlashdagi) belgilarni qo'llab-quvvatlaydi, shuning uchun bu muammo tug'dirmaydi.
*   **Katta/kichik harflar**: Dastur kiritilgan ismni aynan o'sha katta/kichik harflar bilan chop etadi. Masalada bu haqda hech qanday talab bo'lmagani uchun, o'zgartirish shart emas.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M038A) platformasidagi **M038A** raqamli **PIIMA olimpiadasiga xush kelibsiz #2** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M038A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M038A, PIIMA olimpiadasiga xush kelibsiz #2 yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
