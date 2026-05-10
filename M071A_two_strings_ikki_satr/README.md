---
title: "M071A — Two strings (Ikki Satr) | Robocontest.uz Yechimi"
description: "Robocontest.uz M071A (Two strings (Ikki Satr)) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 128 MB."
keywords: "robocontest M071A, Two strings (Ikki Satr) yechimi, robocontest Two strings (Ikki Satr), M071A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M071A_two_strings_ikki_satr/
lang: uz
---

# M071A — Two strings (Ikki Satr)

## Masala haqida
Sizga `N` uzunlikdagi ikkita `S` va `T` satrlari berilgan. Siz `S` satridagi harflarni xohlagan tartibda joylashtirishingiz mumkin. Sizning vazifangiz `S[i] = T[i]` sharti bajariladigan indekslar (`i`) sonini maksimal darajaga yetkazishdir. Masalaning maqsadi `S` satrini qanday tartiblasak, `T` satri bilan maksimal darajada bir xil belgilar joyida turishini topish.

## Yondashuv (g'oya)
Masalani yechishning asosiy g'oyasi shundaki, `S` satrining belgilarini istalgancha joylashtirish mumkin bo'lganligi sababli, belgilarning asl o'rni emas, balki ularning *soni* (chastotalari) muhimdir. Agar biz `S[i] = T[i]` shartini bajarishni istasak, u holda `S` satridagi biror belgi `T` satridagi xuddi shu belgi joylashgan o'ringa qo'yilishi kerak.

Masalan, agar `S` satrida 5 ta 'a' harfi va `T` satrida 3 ta 'a' harfi mavjud bo'lsa, biz maksimal 3 ta 'a' harfi uchun moslik hosil qilishimiz mumkin. `S` dagi qolgan 2 ta 'a' harfi `T` dagi boshqa belgilar bilan mos kela olmaydi. Bu har bir harf turi (masalan, 'a', 'b', 'c', va hokazo) uchun mustaqil ravishda amalga oshiriladi. Shunday qilib, har bir harf uchun `S` va `T` dagi chastotalarni hisoblab, ularning minimumini olish kerak. Ushbu minimumlarning yig'indisi umumiy maksimal mosliklar sonini beradi.

## Algoritm qadamlari
1.  **Kiritma ma'lumotlarini o'qish**: `N` butun sonini (satrlar uzunligi) va `S`, `T` satrlarini o'qib oling.
2.  **Chastotalarni saqlash uchun massivlar**: `freqS` va `freqT` nomli ikkita massivni (yoki xarita) yarating. Bu massivlar har bir kichik ingliz harfining (umumiy 26 ta harf: 'a' dan 'z' gacha) `S` va `T` satrlaridagi uchrashish sonini (chastotalarini) saqlaydi. Massivlar 26 elementli bo'lib, barcha elementlarning boshlang'ich qiymatini 0 ga tenglashtiring.
    *   `freqS[0]` 'a' harfining chastotasini, `freqS[1]` 'b' harfining chastotasini va hokazo, `freqS[25]` 'z' harfining chastotasini saqlaydi.
3.  **`S` satri uchun chastotalarni hisoblash**: `S` satrining har bir belgisi (`c`) bo'ylab yuring. Har bir belgi uchun `freqS[c - 'a']` elementining qiymatini bittaga oshiring. (Misol uchun, agar belgi 'b' bo'lsa, `freqS['b' - 'a']` ya'ni `freqS[1]` ni oshirasiz.)
4.  **`T` satri uchun chastotalarni hisoblash**: Xuddi shu tarzda, `T` satrining har bir belgisi (`c`) bo'ylab yuring va har bir belgi uchun `freqT[c - 'a']` elementining qiymatini bittaga oshiring.
5.  **Maksimal mosliklarni hisoblash**: `total_matches` nomli butun sonli o'zgaruvchi yarating va unga 0 qiymatini bering. So'ngra, `i` ni 0 dan 25 gacha (ya'ni barcha 26 ta harf uchun) takrorlab, har bir `i` uchun quyidagilarni bajaring:
    *   `total_matches` ga `min(freqS[i], freqT[i])` ni qo'shing. Bu qadam `S` va `T` satrlarida ma'lum bir harfning qaysi biri kamroq bo'lsa, o'sha sonicha moslik hosil qilish mumkinligini bildiradi.
6.  **Natijani chiqarish**: `total_matches` o'zgaruvchisining oxirgi qiymatini ekranga chop eting.

## Murakkablik tahlili
*   **Vaqt murakkabligi**: `O(N)`
    *   `N`, `S`, `T` satrlarini o'qish `O(N)` vaqt oladi.
    *   `freqS` massivini `S` satri bo'yicha to'ldirish `N` marta iteratsiya qilishni talab qiladi, bu `O(N)` vaqt.
    *   `freqT` massivini `T` satri bo'yicha to'ldirish ham `O(N)` vaqt oladi.
    *   `total_matches` ni hisoblash uchun 26 ta harf bo'yicha iteratsiya qilinadi. Bu doimiy (o'zgarmas) son bo'lganligi uchun `O(26)` yoki `O(1)` vaqt oladi.
    *   Shunday qilib, umumiy vaqt murakkabligi `O(N + N + 1)` ga teng bo'lib, bu `O(N)` ga soddalashadi. `N` <= 1000 bo'lgani uchun, bu yechim 1000 ms vaqt chegarasiga bemalol sig'adi.

*   **Xotira murakkabligi**: `O(1)`
    *   `freqS` va `freqT` massivlari har biri 26 ta butun sonni saqlaydi. Bu `O(26)` yoki `O(1)` (doimiy) xotira talab qiladi, chunki alifbodagi harflar soni o'zgarmas.
    *   `S` va `T` satrlarining o'zlari `O(N)` xotira talab qiladi, ammo competitive programming da odatda "qo'shimcha xotira" hisobga olinadi, bu holda u `O(1)`.
    *   Bu yechim 128 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart C++ kutubxonalarini o'z ichiga oladi (masalan, iostream, string, vector, algorithm).

using namespace std; // std nomlar fazosidan foydalanishni osonlashtiradi.

int main() {
    // Kirish/chiqish operatsiyalarini tezlashtirish uchun optimizatsiyalar.
    // C++ oqimlari (cin/cout) va C oqimlari (scanf/printf) orasidagi sinxronizatsiyani o'chiradi.
    ios_base::sync_with_stdio(false);
    // cin operatsiyasidan keyin cout buferini bo'shatishni bekor qiladi, bu ham tezlikni oshiradi.
    cin.tie(0);

    int N; // Satrlarning uzunligini saqlash uchun o'zgaruvchi.
    cin >> N; // N ni kiritish.
    string S, T; // S va T satrlarini saqlash uchun o'zgaruvchilar.
    cin >> S >> T; // S va T satrlarini kiritish.

    // freqS va freqT massivlari har bir kichik harfning chastotasini saqlash uchun ishlatiladi.
    // 26 - ingliz alifbosidagi harflar soni. Boshlang'ich qiymatlar 0 ga teng.
    vector<int> freqS(26, 0); 
    vector<int> freqT(26, 0);

    // S satridagi harflarning chastotasini hisoblash.
    // S satridagi har bir 'c' belgisi uchun takrorlash.
    for (char c : S) { 
        // 'c' belgisini 0-25 oralig'idagi indeksga o'tkazadi ('a' -> 0, 'b' -> 1, ..., 'z' -> 25)
        // va uning chastotasini oshiradi.
        freqS[c - 'a']++; 
    }

    // T satridagi harflarning chastotasini hisoblash.
    // T satridagi har bir 'c' belgisi uchun takrorlash.
    for (char c : T) { 
        // Xuddi S satridagidek, T satri uchun chastotalarni hisoblaydi.
        freqT[c - 'a']++; 
    }

    int total_matches = 0; // Maksimal mosliklar sonini saqlash uchun o'zgaruvchi.
    // Har bir harf uchun mumkin bo'lgan mosliklar sonini hisoblash va umumiy natijaga qo'shish.
    // 0 dan 25 gacha bo'lgan barcha indekslar (harflar) uchun takrorlash.
    for (int i = 0; i < 26; ++i) { 
        // S va T dagi harf chastotalarining minimumini olib, 'total_matches' ga qo'shadi.
        // Chunki S va T da berilgan harfning qaysi biri kamroq bo'lsa, shuncha marta moslik hosil qilish mumkin.
        total_matches += min(freqS[i], freqT[i]); 
    }

    cout << total_matches << endl; // Umumiy maksimal mosliklar sonini chop etish.

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Bo'sh satrlar**: Masala shartiga ko'ra `N` har doim 1 dan katta yoki teng bo'ladi (`1 <= N`), shuning uchun satrlar hech qachon bo'sh bo'lmaydi.
*   **Bir xil satrlar**: Agar `S` va `T` satrlari aynan bir xil bo'lsa, algoritm `N` ni natija sifatida qaytaradi, bu to'g'ri. Har bir harf uchun `freqS[i]` va `freqT[i]` bir xil bo'ladi va ularning minimumi ham shu qiymatga teng bo'ladi, natijada umumiy yig'indi `N` ga teng bo'ladi.
*   **Harflarning yo'qligi**: Agar biror harf (`'x'`) `S` satrida umuman mavjud bo'lmasa (`freqS['x'-'a'] == 0`) yoki `T` satrida mavjud bo'lmasa (`freqT['x'-'a'] == 0`), bu harf uchun `min(0, ...)` natijasi 0 bo'ladi va u `total_matches` ga ta'sir qilmaydi. Bu ham algoritm tomonidan to'g'ri ishladi.
*   **Alifbo cheklovi**: Masala sharti bo'yicha faqat kichik ingliz harflari ("a" dan "z" gacha) ishlatiladi. Bu `freqS` va `freqT` massivlarining hajmini aniq 26 ta element bilan cheklashga imkon beradi, bu esa algoritmning `O(1)` xotira murakkabligini ta'minlaydi.
*   **Kirish/chiqish optimizatsiyalari**: `ios_base::sync_with_stdio(false);` va `cin.tie(0);` qatorlari C++ dasturlashda katta hajmdagi kirish/chiqish ma'lumotlari bilan ishlashda dastur ish faoliyatini sezilarli darajada yaxshilash uchun keng qo'llaniladigan standart amaliyotdir.
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M071A) platformasidagi **M071A** raqamli **Two strings (Ikki Satr)** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M071A>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M071A, Two strings (Ikki Satr) yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
