---
title: "M047B — Juft karrali | Robocontest.uz Yechimi"
description: "Robocontest.uz M047B (Juft karrali) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Oson. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M047B, Juft karrali yechimi, robocontest Juft karrali, M047B c++ kod, oson, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M047B_juft_karrali/
lang: uz
---

# M047B — Juft karrali

## Masala haqida
Ushbu masalada bizga `n` natural soni beriladi. Bizning vazifamiz `n` ning eng kichik juft karralisini (ko'paytmasini) topish va uni chiqarish. Kiruvchi son 1000 dan oshmaydi.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi juft va toq sonlarning xossalariga asoslangan. Har qanday sonning eng kichik karralisi bu sonning o'zidir. Agar berilgan `n` sonining o'zi juft bo'lsa, u holda uning eng kichik juft karralisi `n` ning o'zi bo'ladi. Agar `n` soni toq bo'lsa, u holda `n` ning o'zi juft emas. Bu holda biz `n` ni shunday eng kichik butun songa ko'paytirishimiz kerakki, natija juft bo'lsin. Toq sonni juft qilishning eng oddiy va eng kichik usuli uni 2 ga ko'paytirishdir. Har qanday toq sonni 2 ga ko'paytirsak, natija juft bo'ladi. Shuning uchun, agar `n` toq bo'lsa, uning eng kichik juft karralisi `2 * n` bo'ladi.

## Algoritm qadamlari
1. Kirish faylidan `n` butun sonini o'qing.
2. `n` soni juft ekanligini tekshiring. Buning uchun `n % 2 == 0` (ya'ni `n` ni 2 ga bo'lgandagi qoldiq 0 ga teng) shartini tekshiramiz.
3. Agar `n` juft bo'lsa, uni to'g'ridan-to'g'ri chiqish fayliga chop eting.
4. Agar `n` juft bo'lmasa (ya'ni toq bo'lsa), `2 * n` ni hisoblang va natijani chiqish fayliga chop eting.

## Murakkablik tahlili
- **Vaqt**: O(1) — doimiy vaqt.
  Sababi: Algoritm kirish sonining qiymatiga qarab takrorlanishlar sonini o'zgartirmaydi. Bir nechta asosiy arifmetik amallar (o'qish, mod (qoldiq topish), ko'paytirish, chop etish) bajariladi, ular doimiy vaqt oladi.
- **Xotira**: O(1) — doimiy xotira.
  Sababi: Algoritm faqat bitta butun son (`n`) ni saqlash uchun oz miqdordagi xotiradan foydalanadi. Bu xotira miqdori kirish sonining qiymatiga bog'liq emas.
- Berilgan `n <= 1000` chegarasi uchun O(1) murakkablik juda samarali hisoblanadi va belgilangan vaqt (1000 ms) hamda xotira (16 MB) limitlariga to'liq sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi. Odatda competitive programmingda tezkorlik uchun ishlatiladi.

int main() {
    // Kiritish/chiqarish (I/O) operatsiyalarini tezlashtirish uchun standart C++ optimizatsiyalari.
    // std::ios_base::sync_with_stdio(false) - C uslubidagi I/O bilan C++ uslubidagi I/O sinxronizatsiyasini o'chiradi.
    // std::cin.tie(0) - std::cin va std::cout o'rtasidagi bog'lanishni bekor qiladi, bu esa std::cin dan keyin std::cout ni avtomatik ravishda tozalashni oldini oladi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n; // Kiruvchi sonni saqlash uchun 'n' nomli butun son (integer) tipidagi o'zgaruvchi e'lon qilish.
    std::cin >> n; // Foydalanuvchidan 'n' sonini o'qish.
    
    // 'n' sonining 2 ga bo'lgandagi qoldig'ini tekshirish.
    // Agar qoldiq 0 ga teng bo'lsa, 'n' juft son hisoblanadi.
    if (n % 2 == 0) {
        std::cout << n << std::endl; // Agar 'n' juft bo'lsa, 'n' ning o'zini chop etish.
    } else {
        // Agar 'n' juft bo'lmasa (ya'ni toq bo'lsa),
        // 'n' ni 2 ga ko'paytirib, natijani chop etish.
        std::cout << 2 * n << std::endl; 
    }
    
    return 0; // Dastur muvaffaqiyatli yakunlanganligini bildirish.
}
```

## Edge case lar va eslatmalar
- **Kichik sonlar**: Agar `n=1` bo'lsa (toq son), kod `2 * 1 = 2` ni chiqaradi, bu to'g'ri. Agar `n=2` bo'lsa (juft son), kod `2` ni chiqaradi, bu ham to'g'ri.
- **Natural sonlar**: Masala matnida `n` ning natural son ekanligi ko'rsatilgan. Natural sonlar odatda 1 dan boshlab musbat butun sonlarni anglatadi. Shuning uchun `n` hech qachon 0 yoki manfiy bo'lmaydi.
- **Maksimal qiymat**: `n` ning maksimal qiymati 1000. Agar `n=1000` bo'lsa (juft), javob 1000 bo'ladi. Agar `n=999` bo'lsa (toq), javob `2 * 999 = 1998` bo'ladi. Bu qiymatlar `int` turiga sig'adi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M047B) platformasidagi **M047B** raqamli **Juft karrali** masalasi. U **Oson** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M047B>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M047B, Juft karrali yechimi, robocontest masalalari, c++17, olimpiada yechimi, oson, dasturlash uzbek, competitive programming O'zbekiston.</sub>
