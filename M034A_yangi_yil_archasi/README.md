---
title: "M034A — Yangi yil archasi | Robocontest.uz Yechimi"
description: "Robocontest.uz M034A (Yangi yil archasi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M034A, Yangi yil archasi yechimi, robocontest Yangi yil archasi, M034A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M034A_yangi_yil_archasi/
lang: uz
---

# M034A — Yangi yil archasi

## Masala haqida
Asliddin Yangi yil archasini tanlashda o'ziga xos talablarga ega. U tanlaydigan archa balandligi 200 sm dan kam va 300 sm dan ortiq bo'lmasligi kerak. Shuningdek, uning diametri kamida 50 sm va shoxlari soni kamida 150 ta bo'lishi lozim. Sizning vazifangiz, berilgan archa ma'lumotlari (balandligi, diametri va shoxlar soni) asosida Asliddinning talablariga javob beradimi yoki yo'qligini aniqlashdir.

## Yondashuv (g'oya)
Masala juda oddiy shartli tekshirishga asoslangan. Berilgan har bir archa uchun uning balandligi, diametri va shoxlari soni Asliddin tomonidan belgilangan minimal va maksimal chegaralarga mos kelishini tekshirish kifoya. Agar barcha shartlar bajarilsa, archa mos keladi ("Yes"), aks holda mos kelmaydi ("No").

## Algoritm qadamlari
1.  Birinchi navbatda, `N` – test holatlari sonini (ya'ni, tekshirilishi kerak bo'lgan archalar sonini) o'qib olamiz.
2.  `N` marta takrorlanadigan tsikl (loop) boshlaymiz. Har bir iteratsiyada bitta archa ma'lumotlarini qayta ishlaymiz.
3.  Tsikl ichida, joriy archa uchun balandlik (`h`), diametr (`d`) va shoxlar soni (`g`) qiymatlarini o'qib olamiz.
4.  Quyidagi shartlarni tekshiramiz:
    *   Archaning balandligi (`h`) 200 sm dan kam emasmi (`h >= 200`)?
    *   Archaning balandligi (`h`) 300 sm dan katta emasmi (`h <= 300`)?
    *   Archaning diametri (`d`) 50 sm dan kam emasmi (`d >= 50`)?
    *   Archaning shoxlari soni (`g`) 150 tadan kam emasmi (`g >= 150`)?
5.  Agar yuqoridagi **barcha** shartlar bir vaqtning o'zida to'g'ri bo'lsa, konsolga "Yes" so'zini chiqaramiz.
6.  Agar shartlardan birontasi bajarilmasa, konsolga "No" so'zini chiqaramiz.
7.  Tsikl tugagach, dastur ishini yakunlaydi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(N)
    *   Biz `N` marta tsikl yordamida takrorlaymiz. Har bir takrorlashda, kirish ma'lumotlarini o'qish (3 ta butun son) va bir nechta shartlarni tekshirish kabi doimiy vaqt oladigan (constant time) operatsiyalarni bajaramiz.
    *   Demak, umumiy vaqt murakkabligi kirish ma'lumotlari (`N`) soniga chiziqli ravishda bog'liq bo'ladi, ya'ni O(N). `N` ning maksimal qiymati 10000 bo'lganligi sababli, bu operatsiyalar tezkor tarzda bajariladi va berilgan 1000 ms vaqt limitiga bemalol sig'adi.
-   **Xotira murakkabligi**: O(1)
    *   Dastur kirish ma'lumotlarini (N, h, d, g) saqlash uchun faqat bir nechta o'zgaruvchilardan foydalanadi. Bu o'zgaruvchilar soni `N` ga bog'liq emas va doimiy miqdordagi xotirani talab qiladi.
    *   Shuning uchun xotira murakkabligi doimiy bo'lib, O(1) ga teng. Berilgan 16 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> 
// Bu qator C++ standart kutubxonalarining ko'pchiligini o'z ichiga oladi.
// Competitive programmingda tezlikni oshirish uchun keng qo'llaniladi.

using namespace std;
// std (standard) nomfazodan foydalanishni bildiradi,
// shunda biz std::cout, std::cin kabi ob'ektlarni shunchaki cout, cin deb yozishimiz mumkin.

int main() {
    // Dasturning asosiy ishga tushish nuqtasi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // Ushbu ikki qator kirish/chiqish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi.
    // sync_with_stdio(false) C++ streamlarini C standart I/O streamlari bilan sinxronizatsiyasini o'chiradi.
    // cin.tie(0) esa cin operatsiyasidan keyin cout buferini tozalashni bekor qiladi, bu ham tezlikni oshiradi.

    int N;
    // Test holatlari sonini saqlash uchun N butun sonli o'zgaruvchisi e'lon qilinadi.
    cin >> N;
    // N ning qiymati kiritish faylidan o'qib olinadi.

    for (int i = 0; i < N; ++i) {
        // N marta takrorlanadigan tsikl. Har bir takrorlash bitta archani tekshirishga mos keladi.
        int h, d, g;
        // Archa balandligi (h), diametri (d) va shoxlari sonini (g) saqlash uchun o'zgaruvchilar e'lon qilinadi.
        cin >> h >> d >> g;
        // Joriy archa uchun h, d, g qiymatlari o'qib olinadi.

        if (h >= 200 && h <= 300 && d >= 50 && g >= 150) {
            // Bu yerda Asliddinning barcha talablari tekshiriladi:
            // h >= 200: balandlik kamida 200 sm.
            // h <= 300: balandlik ko'pi bilan 300 sm.
            // d >= 50: diametr kamida 50 sm.
            // g >= 150: shoxlar soni kamida 150 ta.
            // "&&" (mantiqiy AND) operatori barcha shartlar bir vaqtning o'zida to'g'ri bo'lishi kerakligini bildiradi.
            cout << "Yes\n";
            // Agar barcha shartlar bajarilsa, "Yes" chiqariladi va yangi qatorga o'tiladi.
        } else {
            // Agar yuqoridagi shartlardan birontasi ham bajarilmasa:
            cout << "No\n";
            // "No" chiqariladi va yangi qatorga o'tiladi.
        }
    }

    return 0;
    // Dastur muvaffaqiyatli yakunlanganligini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Chegaraviy qiymatlar (Edge cases)**: Masalada berilgan shartlar inklyuzivdir (ya'ni, `>=` va `<=` ishlatiladi). Misol uchun, balandlik 200 sm bo'lsa ham, 300 sm bo'lsa ham qabul qilinadi. Xuddi shunday diametr 50 sm, shoxlar soni 150 ta bo'lsa ham qabul qilinadi. Kod bu inklyuziv shartlarni to'g'ri tekshiradi.
*   **Kirish ma'lumotlari diapazoni**: `h, d, g` qiymatlari 0 dan 5000 gacha, `N` esa 0 dan 10000 gacha. Bu qiymatlar `int` turidagi o'zgaruvchilarga bemalol sig'adi va butun sonlar (integer) bilan ishlashda toshib ketish (overflow) muammosi yuzaga kelmaydi.
*   **Tezlik**: Yuqorida tushuntirilgan I/O optimizatsiyalari ( `ios_base::sync_with_stdio(false); cin.tie(0);` ) ko'p miqdordagi kiritish/chiqarish operatsiyalari mavjud bo'lgan masalalarda sezilarli tezlikni oshirishga yordam beradi. Garchi bu masala uchun juda muhim bo'lmasada, bu amaliyotni odat tusiga kiritish tavsiya etiladi.
*   **Oddiylik**: Bu masala shartli operatorlar (`if-else`) va mantiqiy operatorlar (`&&`) dan foydalanishning eng asosiy namunasi hisoblanadi. Unda murakkab algoritm yoki ma'lumotlar tuzilmasiga ehtiyoj yo'q.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M034A) platformasidagi **M034A** raqamli **Yangi yil archasi** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M034A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M034A, Yangi yil archasi yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
