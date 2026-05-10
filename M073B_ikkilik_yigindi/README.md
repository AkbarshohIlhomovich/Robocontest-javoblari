---
title: "M073B — Ikkilik yig'indi | Robocontest.uz Yechimi"
description: "Robocontest.uz M073B (Ikkilik yig'indi) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M073B, Ikkilik yig'indi yechimi, robocontest Ikkilik yig'indi, M073B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M073B_ikkilik_yigindi/
lang: uz
---

# M073B — Ikkilik yig'indi

## Masala haqida
G'ishmat dasturlashni yaqinda boshlagani uchun sanoq sistemalari bilan hali tanish emas. U ikkilik (binary) sanoq sistemasidagi sonlarni xuddi o'nlik (decimal) sanoq sistemasidagidek qo'shib yuboradi (masalan, "10" + "11" = "21"). Bizga G'ishmat hosil qilgan xato yig'indi (`S`) berilgan. U bu yig'indini hosil qilish uchun minimal nechta haqiqiy ikkilik sondan foydalanganini topishimiz kerak.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi G'ishmatning noto'g'ri yig'indisi qanday hosil bo'lishini tushunishga asoslangan. Ikkilik sonlar faqat "0" va "1" raqamlaridan iborat bo'ladi. G'ishmat bu sonlarni o'nlik kabi qo'shganida, natijadagi har bir raqam (masalan, birlar xonasi, o'nlar xonasi va hokazo) qo'shilgan sonlarning mos raqamlari yig'indisidan iborat bo'ladi.

Misol uchun, agar G'ishmat "10" va "11" ni qo'shgan bo'lsa:
*   Birlar xonasi: "10" ning birlar xonasi "0", "11" ning birlar xonasi "1". Yig'indi: 0 + 1 = 1.
*   O'nlar xonasi: "10" ning o'nlar xonasi "1", "11" ning o'nlar xonasi "1". Yig'indi: 1 + 1 = 2.
Natija "21".

Endi, bizga "21" berilgan bo'lsa, uni hosil qilish uchun minimal nechta ikkilik son kerakligini topishimiz kerak.
*   Birlar xonasidagi "1" ni hosil qilish uchun: qo'shilgan sonlardan faqat bittasining birlar xonasida "1" bo'lishi va qolganlarida "0" bo'lishi kerak.
*   O'nlar xonasidagi "2" ni hosil qilish uchun: qo'shilgan sonlardan ikkitasining o'nlar xonasida "1" bo'lishi va qolganlarida "0" bo'lishi kerak.

Ko'rinib turibdiki, yig'indi `S` ning har bir raqami (`d`) qo'shilgan sonlarning mos xonalaridagi "1" larning sonini bildiradi. Agar `S` ning biror xonasida `d` raqami mavjud bo'lsa, demak shu xonada `d` ta sonning "1" raqami bo'lgan, qolganlarida esa "0". Bu shuni anglatadiki, yig'indi `S` ni hosil qilish uchun kamida `d` ta son kerak bo'ladi. Shuning uchun, `S` sonining eng katta raqami (`max_digit`) bizga kerak bo'lgan minimal sonlar sonini beradi. Chunki biz har doim `max_digit` ta ikkilik sonni shu tarzda yarata olamizki, ularni "o'nlik usulida" qo'shsak, `S` hosil bo'ladi.

## Algoritm qadamlari
1.  Kirishdan berilgan `S` butun sonini o'qib oling.
2.  `max_digit` nomli butun son o'zgaruvchisini yarating va uni 0 ga tenglang. Bu o'zgaruvchi `S` ning eng katta raqamini saqlaydi.
3.  `S` nolga teng bo'lmaguncha quyidagi qadamlarni takrorlang:
    a.  `S % 10` (qoldiq) amalini bajarib, `S` ning oxirgi raqamini oling.
    b.  Topilgan oxirgi raqamni `max_digit` bilan solishtiring va ulardan kattasini `max_digit` ga yangi qiymat qilib yozing (ya'ni, `max_digit = max(max_digit, S % 10)`).
    c.  `S /= 10` (butun bo'lish) amalini bajarib, `S` ning oxirgi raqamini olib tashlang.
4.  Tsikl (loop) tugagandan so'ng, `max_digit` o'zgaruvchisining qiymatini chop eting. Bu G'ishmat ishlatgan bo'lishi mumkin bo'lgan sonlar sonining minimal qiymati bo'ladi.

## Murakkablik tahlili
*   **Vaqt**: `S` sonining raqamlari soniga bog'liq. `S` maksimal `10^9` bo'lishi mumkin, bu esa ko'pi bilan 10 ta raqamdan iborat bo'ladi. Algoritm har bir raqam uchun doimiy vaqt (qoldiqni hisoblash, bo'lish, taqqoslash) sarflaydi. Shuning uchun vaqt murakkabligi `O(log S)` (yoki `S` ning raqamlari soni) bo'ladi. Bu `10^9` gacha bo'lgan sonlar uchun juda tez.
*   **Xotira**: Algoritm faqat bir nechta butun son o'zgaruvchilaridan (`s`, `max_digit`) foydalanadi. Shu sababli, xotira murakkabligi `O(1)` (doimiy) bo'ladi.
*   **Nega shu murakkablik chegaraga sig'adi**: `O(log S)` vaqt murakkabligi `S = 10^9` uchun juda kichik (taxminan 10 ta operatsiya) va `O(1)` xotira murakkabligi ham juda kam xotira talab qiladi. Shuning uchun berilgan vaqt (1000 ms) va xotira (32 MB) chegaralariga bemalol sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi (bu masala uchun asosan <iostream> kerak)
using namespace std; // std:: prefiksini ishlatmaslik uchun

int main() {
    // Kirish/chiqish (I/O) operatsiyalarini tezlashtirish uchun
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int s; // G'ishmat hosil qilgan yig'indi S ni saqlash uchun o'zgaruvchi
    cin >> s; // S ni kirishdan o'qib olish

    int max_digit = 0; // S ning eng katta raqamini saqlash uchun o'zgaruvchi, boshida 0 ga teng
    
    // S ni raqamlariga ajratib, eng katta raqamni topamiz.
    // 1 <= S <= 10^9 sharti tufayli S har doim musbat bo'ladi.
    while (s > 0) { // S nolga teng bo'lmaguncha tsiklni davom ettiramiz
        // s % 10 - S ning oxirgi raqamini beradi.
        // max() funksiyasi max_digit va s % 10 dan kattasini qaytaradi.
        max_digit = max(max_digit, s % 10); 
        s /= 10; // S ni 10 ga bo'lib, oxirgi raqamini olib tashlaymiz
    }

    cout << max_digit << endl; // Topilgan eng katta raqamni chop etamiz

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi
}

```

## Edge case lar va eslatmalar
*   **Minimal `S` qiymati (`S = 1`):** Agar `S = 1` bo'lsa, `max_digit` 1 bo'ladi. Bu to'g'ri, chunki "1" ikkilik sonining o'zi birinchi raqamni 1 qiladi.
*   **`S` natural son:** Masala shartida `1 <= S <= 10^9` ekanligi aytilgan. Bu shuni anglatadiki, `S` har doim musbat bo'ladi va kamida bitta raqamdan iborat bo'ladi. Shuning uchun `max_digit` hech qachon 0 bo'lmaydi, har doim kamida 1 bo'ladi.
*   **Ikkilik sonlarning tabiati:** Yechimning asosiy sharti shundaki, G'ishmat qo'shgan sonlar "ikkilik" sonlardir, ya'ni ularning har bir raqami faqat "0" yoki "1" bo'lishi mumkin. Bu shart masalaning mohiyatini tashkil qiladi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M073B) platformasidagi **M073B** raqamli **Ikkilik yig'indi** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M073B>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M073B, Ikkilik yig'indi yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
