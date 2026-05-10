---
title: "M054E — Damino toshlari | Robocontest.uz Yechimi"
description: "Robocontest.uz M054E (Damino toshlari) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M054E, Damino toshlari yechimi, robocontest Damino toshlari, M054E c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M054E_damino_toshlari/
lang: uz
---

# M054E — Damino toshlari

## Masala haqida
Ushbu masalada sizga N x M o'lchamli to'rtburchak doska beriladi. Sizning vazifangiz 2 x 1 o'lchamli damino toshlarini bu doskaga eng ko'pi bilan nechta joylashtirish mumkinligini aniqlash. Damino toshlari bir-birini yopmasligi va doskaning tashqarisiga chiqmasligi shart. Kirish ma'lumotlarida doskaning N va M o'lchamlari (1 ≤ M ≤ N ≤ 16) beriladi.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi juda sodda. Har bir damino toshi 2 x 1 o'lchamda bo'lib, doskaning 2 ta katakchasini (kvadratini) qoplaydi. Bizning maqsadimiz doskaning iloji boricha ko'proq qismini qoplash orqali eng ko'p sonli damino toshlarini joylashtirishdir. Bu esa shuni anglatadiki, biz doskaning umumiy kataklari sonini (N * M) har bir damino toshi qoplaydigan kataklar soniga (ya'ni, 2 ga) bo'lishimiz kerak. Natija butun sonli bo'linma (integer division) bo'ladi, chunki daminoning bir qismini joylashtirish mumkin emas.

## Algoritm qadamlari
1.  Kirishdan doskaning N va M o'lchamlarini o'qing.
2.  Doskaning umumiy kataklari sonini hisoblang: `total_squares = N * M`.
3.  Har bir damino 2 ta katakni qoplashini inobatga olgan holda, doskaga joylashtirish mumkin bo'lgan maksimal damino toshlari sonini toping: `max_dominoes = total_squares / 2`. Bu yerda C++ da butun sonli bo'linma (integer division) avtomatik ravishda amalga oshiriladi, ya'ni agar `total_squares` toq son bo'lsa, natija pastga qarab yaxlitlanadi.
4.  Hisoblangan `max_dominoes` qiymatini chiqishga chop eting.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(1) — Konstant vaqt.
    Nega: Algoritm faqat bir nechta arifmetik amal (ko'paytirish va bo'lish) va kirish/chiqish amallarini bajaradi. N va M ning qiymatlari qanchalik bo'lishidan qat'i nazar (belgilangan chegaralar doirasida), bajariladigan amallar soni o'zgarmaydi. Shu sababli, algoritmning ishlash vaqti konstant hisoblanadi.
-   **Xotira murakkabligi**: O(1) — Konstant xotira.
    Nega: Dastur faqat N, M va natija (result) kabi bir nechta o'zgaruvchilarni saqlash uchun xotira ishlatadi. Bu o'zgaruvchilar soni kiritilayotgan ma'lumotlar hajmiga bog'liq emas va har doim bir xil, shuning uchun xotira sarfi ham konstantdir.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Barcha standart kutubxonalarni o'z ichiga oluvchi sarlavha fayli. Kirish/chiqish (iostream) uchun kerak.

int main() {
    // Standart kirish/chiqish (I/O) oqimlarini tezlashtirish uchun buyruqlar.
    // std::ios_base::sync_with_stdio(false) C standart I/O kutubxonalari bilan sinxronizatsiyani o'chiradi.
    // std::cin.tie(0) esa std::cin dan keyin std::cout ni avtomatik tozalashni (flush) bekor qiladi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    long long n, m; // N va M o'lchamlarini saqlash uchun 'long long' turidagi o'zgaruvchilarni e'lon qilish.
                    // Garchi N, M kichik bo'lsada (16 gacha), N*M ning qiymati ham intga sig'adi,
                    // ammo 'long long' katta sonlar bilan ishlashda xatoliklarning oldini oladigan yaxshi amaliyotdir.
    
    std::cin >> n >> m; // Kirish oqimidan N va M qiymatlarini o'qish.
    
    long long result = (n * m) / 2; // Doskaning umumiy kataklari sonini (n * m) hisoblaydi,
                                    // so'ngra har bir damino 2 katakni qoplashini hisobga olib,
                                    // 2 ga bo'ladi. C++ da bu butun sonli bo'linma (integer division) bo'lib,
                                    // natija har doim butun qismi olinadi (pastga qarab yaxlitlanadi).
    
    std::cout << result << std::endl; // Hisoblangan natijani (maksimal damino sonini) chiqish oqimiga chop etish.
                                     // std::endl yangi qatorga o'tib, oqimni tozalaydi (flush).
    
    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}

```

## Edge case lar va eslatmalar
*   **Minimum o'lchamlar**: Agar doska 1x1 o'lchamda bo'lsa, `(1 * 1) / 2 = 0`. Bu to'g'ri, chunki 1x1 doskaga 2x1 damino joylashtirib bo'lmaydi.
*   **Maksimum o'lchamlar**: N va M ning maksimal qiymatlari 16 ga teng. Agar doska 16x16 o'lchamda bo'lsa, `(16 * 16) / 2 = 256 / 2 = 128`. Bu ham to'g'ri. `long long` dan foydalanish hatto bunday kichik sonlar uchun ortiqcha bo'lsa-da, katta qiymatlar bilan ishlashda doim xavfsizlikni ta'minlaydi.
*   **Toq sonli kataklar**: Agar doskaning umumiy kataklar soni toq bo'lsa (masalan, 3x3 doska: `(3 * 3) / 2 = 9 / 2 = 4`), javob butun sonli bo'linma tufayli pastga qarab yaxlitlanadi. Bu to'g'ri, chunki toq sonli kataklar bo'lganda, bitta katak har doim qoplanmay qoladi va biz faqat butun daminolarni joylashtirishimiz mumkin.
*   **Xotira cheklovi**: Masalada xotira cheklovi 16 MB qilib belgilangan. O(1) xotira murakkabligiga ega bo'lgan ushbu yechim ushbu cheklovga bemalol sig'adi, chunki u faqat bir nechta o'zgaruvchini saqlaydi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M054E) platformasidagi **M054E** raqamli **Damino toshlari** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M054E>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M054E, Damino toshlari yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
