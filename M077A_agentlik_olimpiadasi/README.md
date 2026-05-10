---
title: "M077A — Agentlik olimpiadasi | Robocontest.uz Yechimi"
description: "Robocontest.uz M077A (Agentlik olimpiadasi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M077A, Agentlik olimpiadasi yechimi, robocontest Agentlik olimpiadasi, M077A c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M077A_agentlik_olimpiadasi/
lang: uz
---

# M077A — Agentlik olimpiadasi

## Masala haqida
Ushbu masalada bizga "Agentlik olimpiadasiga xush kelibsiz" satri beriladi. Kirish qismida esa bitta belgi (char) kiritiladi. Bizning vazifamiz kiritilgan ushbu belgining berilgan satr ichida mavjud yoki mavjud emasligini aniqlash. Agar belgi satrda topilsa, "YES" aks holda "NO" chiqarish kerak.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi juda sodda: berilgan satrni belgilar bo'yicha ketma-ket ko'rib chiqish va har bir belgini kiritilgan belgi bilan solishtirish. Agar mos keladigan belgi topilsa, qidiruvni to'xtatish va natijani bildirish. Bu to'g'ridan-to'g'ri (brute-force) qidirish yondashuvi bo'lib, satrning kichikligi tufayli juda samarali ishlaydi.

## Algoritm qadamlari
1.  **Dastlabki satrni aniqlash**: "Agentlik olimpiadasiga xush kelibsiz" satrini `string` turidagi o'zgaruvchiga saqlab olamiz.
2.  **Kirishni o'qish**: Foydalanuvchi kiritgan bitta belgini `char` turidagi o'zgaruvchiga o'qiymiz.
3.  **Qidiruv holatini belgilash**: Belgining topilganligini ko'rsatuvchi `bool` turidagi `found` (topildi) deb nomlangan o'zgaruvchi yaratamiz va uni dastlab `false` (yolg'on) qiymatiga o'rnatamiz.
4.  **Satr bo'ylab takrorlash**: Satrdagi har bir belgini boshidan oxirigacha ko'rib chiqamiz.
5.  **Belgilarni solishtirish**: Har bir ko'rib chiqilayotgan satr belgisini kirishda berilgan belgi bilan solishtiramiz.
6.  **Topilganda**: Agar satr belgisining kiritilgan belgi bilan mos kelishini aniqlasak, `found` o'zgaruvchini `true` (rost) qiymatiga o'rnatamiz va qidiruvni darhol to'xtatamiz (chunki belgi topildi va boshqa tekshirish shart emas).
7.  **Natijani chiqarish**: Takrorlash (loop) tugagandan so'ng, agar `found` o'zgaruvchisi `true` bo'lsa, "YES" deb chiqaramiz. Aks holda, ya'ni `found` o'zgaruvchisi `false` bo'lib qolgan bo'lsa, "NO" deb chiqaramiz.

## Murakkablik tahlili
-   **Vaqt**: O(L)
    *   Bu yerda `L` — "Agentlik olimpiadasiga xush kelibsiz" satrining uzunligi (36 ta belgi).
    *   Algoritm satrdagi har bir belgini ko'pi bilan bir marta ko'rib chiqadi. Agar belgi satrning boshida topilsa, qidiruv tezroq tugaydi. Agar satrda umuman bo'lmasa yoki oxirida joylashgan bo'lsa, barcha belgilar tekshiriladi. Shuning uchun vaqt murakkabligi satr uzunligiga proporsionaldir.
    *   Satr uzunligi doimiy va juda kichik bo'lganligi sababli (36), amalda bu O(1) doimiy vaqt murakkabligidir. Bu 1000 ms vaqt limitiga juda bemalol sig'adi.

-   **Xotira**: O(L)
    *   Bu yerda `L` — "Agentlik olimpiadasiga xush kelibsiz" satrining uzunligi (36 ta belgi).
    *   Biz satrning o'zini va bir nechta qo'shimcha o'zgaruvchilarni (kirish belgisi, `found` flagi) saqlashimiz kerak. Bu ham satr uzunligiga proporsional xotira talab qiladi.
    *   Satr uzunligi doimiy va juda kichik bo'lganligi sababli (36), amalda bu ham O(1) doimiy xotira murakkabligidir. Bu 32 MB xotira limitiga juda bemalol sig'adi (ko'pi bilan bir necha o'nlab bayt).

-   **Nega shu murakkablik chegaraga sig'adi**: Masala kiritilgan satrning uzunligi doimiy va juda kichik bo'lganligi sababli, O(1) doimiy vaqt va xotira murakkabligi hech qanday muammosiz berilgan limitlarga sig'adi. Hatto eng yomon holatda ham (belgi topilmasa), algoritm juda kam operatsiyalarni bajaradi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Barcha standart kutubxonalarni o'z ichiga oladi.
                         // C++ da odatda <iostream> va <string> yetarli bo'ladi.

using namespace std; // Standart nomfazodan foydalanish. std:: prefiksini yozmaslik uchun.

int main() {
    // I/O optimizatsiyasi: C++ iostream sinflari va C standart I/O funksiyalari o'rtasidagi
    // sinxronizatsiyani o'chiradi va cin hamda cout ni bir-biriga bog'lanishini bekor qiladi.
    // Bu katta hajmli kirish/chiqarish operatsiyalarida dastur tezligini oshiradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 1. Dastlabki satrni aniqlash
    string s = "Agentlik olimpiadasiga xush kelibsiz";
    
    // 2. Kirishni o'qish
    char target_char; // Kirishdagi belgini saqlash uchun o'zgaruvchi.
    cin >> target_char; // Konsoldan bitta belgini o'qiymiz.

    // 3. Qidiruv holatini belgilash
    bool found = false; // Belgining topilganligini ko'rsatuvchi flag (bayroq). Dastlab topilmadi deb hisoblaymiz.

    // 4-5. Satr bo'ylab takrorlash va belgilarni solishtirish
    // 'for-each' sikli: s satridagi har bir 'c' belgisini ko'rib chiqadi.
    for (char c : s) { 
        if (c == target_char) { // Agar satrdagi joriy belgi (c) kiritilgan belgi (target_char) bilan bir xil bo'lsa:
            found = true;       // 'found' flagini 'true' ga o'rnatamiz.
            break;              // Belgi topilganligi sababli qidiruvni to'xtatamiz.
        }
    }

    // 7. Natijani chiqarish
    if (found) { // Agar 'found' 'true' bo'lsa (ya'ni belgi topilgan bo'lsa):
        cout << "YES\n"; // "YES" ni yangi qatordan chiqaramiz.
    } else {          // Aks holda (belgi topilmagan bo'lsa):
        cout << "NO\n";  // "NO" ni yangi qatordan chiqaramiz.
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Kichik/katta harflar sezgirligi (Case-sensitivity)**: Masala matnida va berilgan satrda faqat kichik harflar va bo'sh joylar mavjud. Agar siz 'a' kiritsangiz, "YES" olasiz, lekin 'A' kiritsangiz, "NO" olasiz, chunki kod katta va kichik harflarni farqlaydi. Masala bunga aniqlik kiritmagani uchun, odatiy holatda, C++ da `char` solishtirish `case-sensitive` (harf registriga sezgir) bo'ladi.
*   **Kiruvchi belgi turi**: Masala ASCII jadvalidan chop etish mumkin bo'lgan belgilardan biri berilishini ta'kidlagan. Bu xususiy (special) belgilar, masalan, raqamlar, punktuatsiya belgilari va boshqalar ham kiritilishi mumkinligini bildiradi. Kod barcha shu turdagi belgilarni to'g'ri ishlata oladi.
*   **Satrning o'zgarmasligi**: "Agentlik olimpiadasiga xush kelibsiz" satri masalada qat'iy belgilab qo'yilgan. Bu uning uzunligi va mazmuni o'zgarmasligini anglatadi, bu esa vaqt va xotira murakkabligini doimiy O(1) darajasiga tushiradi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M077A) platformasidagi **M077A** raqamli **Agentlik olimpiadasi** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M077A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M077A, Agentlik olimpiadasi yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
