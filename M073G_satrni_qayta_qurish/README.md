---
title: "M073G — Satrni qayta qurish | Robocontest.uz Yechimi"
description: "Robocontest.uz M073G (Satrni qayta qurish) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M073G, Satrni qayta qurish yechimi, robocontest Satrni qayta qurish, M073G c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M073G_satrni_qayta_qurish/
lang: uz
---

# M073G — Satrni qayta qurish

## Masala haqida
Bu masalada bizga bir xil uzunlikdagi `S` va `T` nomli ikkita satr beriladi, ular kichik ingliz harflaridan tashkil topgan. `S` satrini "oxirgi belgini olib boshiga qo'yish" operatsiyasi yordamida istalgancha o'zgartirish mumkin. Bizning vazifamiz `S` satrini ushbu operatsiyalar yordamida `T` satriga teng qilish mumkinmi yoki yo'qmi aniqlashdir.

## Yondashuv (g'oya)
Masalaning kalit g'oyasi shundaki, berilgan operatsiya ("oxirgi belgini olib boshiga qo'yish") aslida satrni *siklik siljitish* (cyclic shift) orqali o'zgartiradi. Agar `S` satri `S_1 S_2 ... S_k` ko'rinishida bo'lsa, bir operatsiyadan so'ng u `S_k S_1 S_2 ... S_{k-1}` ko'rinishini oladi. Bu esa satrning barcha belgilarining tartibi o'zgarishsiz qolib, shunchaki boshlanish nuqtasi o'zgarishini anglatadi.

Agar `T` satrini `S` satridan siklik siljitishlar orqali hosil qilish mumkin bo'lsa, unda `T` satri `S` satrining qandaydir bir siklik almashtirilgan versiyasi hisoblanadi. Bunday holatlarni tekshirishning oson yo'li `S` satrini o'zi bilan ikki marta yozib, `S_double = S + S` yangi satrni hosil qilishdir. Agar `T` satri `S` ning siklik siljitishi bo'lsa, u holda `T` satri albatta `S_double` satrining ichida (qism satr sifatida) mavjud bo'ladi.

Misol uchun, agar `S = "kyoto"` va `T = "tokyo"` bo'lsa:
`S_double = "kyotokyoto"`
`T` ("tokyo") satri `S_double` ichida mavjud, shuning uchun javob "Yes".
Agar `S = "abc"` va `T = "abd"` bo'lsa:
`S_double = "abcabc"`
`T` ("abd") satri `S_double` ichida mavjud emas, shuning uchun javob "No".

## Algoritm qadamlari
1. **Kirish ma'lumotlarini o'qish:** `S` va `T` satrlarini kirituvchi oqimdan (input stream) o'qib olish.
2. **`S_double` satrini hosil qilish:** `S` satrini o'zi bilan ketma-ket qo'shib, yangi `s_double` satrini yaratish. Ya'ni, `s_double = s + s`.
3. **Qidiruvni amalga oshirish:** `s_double` satri ichida `T` satrining bor-yo'qligini tekshirish.
4. **Natijani chiqarish:** Agar `T` satri `s_double` ichida topilsa, "Yes" yozuvini chop etish. Aks holda, "No" yozuvini chop etish.

## Murakkablik tahlili
- **Vaqt murakkabligi**: `O(|S|)`
  - `S` va `T` satrlarini o'qish `O(|S|)` vaqt oladi.
  - `s_double = s + s` operatsiyasi satrni birlashtirish bo'lib, bu `O(|S|)` vaqt talab qiladi, chunki `s_double` uzunligi `2 * |S|` bo'ladi.
  - `std::string::find` metodi, odatda, optimallashtirilgan algoritm (masalan, Boyer-Moore yoki Knuth-Morris-Pratt) yordamida amalga oshiriladi. Bu esa `O(|S_double| + |T|)` yoki `O(|S|)` vaqt murakkabligini beradi, chunki `|S_double| = 2 * |S|` va `|T| = |S|`.
  - Natijada, umumiy vaqt murakkabligi `O(|S|)` bo'ladi.
- **Xotira murakkabligi**: `O(|S|)`
  - Biz `s_double` deb nomlangan yangi satrni yaratamiz, uning uzunligi `2 * |S|` ga teng.
  - Shuning uchun qo'shimcha xotira `O(|S|)` ga teng bo'ladi.
- **Chegaralarga sig'ishi**: Masala shartiga ko'ra `|S| <= 100`.
  - Vaqt murakkabligi `O(100)` bo'lib, bu juda kichik va berilgan 1000 ms vaqt limitiga bemalol sig'adi (1 ms natija ham buni tasdiqlaydi).
  - Xotira murakkabligi `O(100)` bo'lib, `2 * 100 = 200` belgini saqlash uchun juda kam xotira talab qilinadi (0 KB natija ham buni tasdiqlaydi, chunki kichik hajmdagi o'zgaruvchilar operatsion tizim tomonidan ajratilgan umumiy xotira bloklari ichida joylashadi).

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi

using namespace std; // std nomlar fazosidan foydalanish uchun

int main() {
    // Kiritish/chiqarish (I/O) tezligini oshirish
    ios_base::sync_with_stdio(false); // C style I/O (stdio) va C++ style I/O (iostream) sinxronizatsiyasini o'chiradi
    cin.tie(0); // cin operatsiyasidan keyin cout buferini avtomatik tozalashni o'chiradi

    string s, t; // s va t nomli string (satr) turidagi o'zgaruvchilarni e'lon qilish
    cin >> s >> t; // s va t satrlarini kiritish oqimidan o'qish

    string s_double = s + s; // s satrini o'zi bilan birlashtirib, s_double nomli yangi satr hosil qilish

    // s_double satri ichida t satri mavjudligini tekshirish
    // find() metodi t satrini s_double ichidan qidiradi.
    // Agar topilsa, t ning boshlanish indeksini qaytaradi.
    // Agar topilmasa, string::npos maxsus qiymatini qaytaradi.
    if (s_double.find(t) != string::npos) {
        cout << "Yes" << endl; // Agar t topilsa, "Yes" chiqarish
    } else {
        cout << "No" << endl; // Agar t topilmasa, "No" chiqarish
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildirish
}
```

## Edge case lar va eslatmalar
- **Satr uzunligi:** Masala shartida `|S| >= 2` deb berilgan, bu degani bo'sh satrlar (`""`) yoki bitta belgidan iborat satrlar (`"a"`) bilan ishlash kerak emas. Bu `s + s` operatsiyasining har doim kamida 4 belgidan iborat satr hosil qilishini ta'minlaydi.
- **Faqat kichik harflar:** `S` va `T` satrlari faqat kichik ingliz harflaridan iborat bo'lgani uchun boshqa turdagi belgilar (raqamlar, maxsus belgilar, katta harflar) yoki katta-kichik harflar sezgirligi (case sensitivity) kabi holatlarni hisobga olish shart emas.
- **Teng uzunlik:** `|S| = |T|` sharti juda muhim. Agar `S` va `T` satrlarining uzunligi har xil bo'lsa, ularni hech qanday operatsiyalar bilan tenglashtirib bo'lmaydi, chunki berilgan operatsiya satrning uzunligini o'zgartirmaydi. Masala sharti bu holatni kafolatlagani uchun qo'shimcha tekshiruv talab qilinmaydi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M073G) platformasidagi **M073G** raqamli **Satrni qayta qurish** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M073G>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M073G, Satrni qayta qurish yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
