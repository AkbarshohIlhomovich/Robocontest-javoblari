---
title: "M057B — Operatsiyalar soni | Robocontest.uz Yechimi"
description: "Robocontest.uz M057B (Operatsiyalar soni) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M057B, Operatsiyalar soni yechimi, robocontest Operatsiyalar soni, M057B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M057B_operatsiyalar_soni/
lang: uz
---

# M057B — Operatsiyalar soni

## Masala haqida
Bu masala sizga ikkita nomanfiy son berilganda, ulardan birini nolga aylantirish uchun bajariladigan minimal operatsiyalar sonini topishni talab qiladi. Bir operatsiyada siz ikki sondan kattasidan kichigini ayirib, kattasining qiymatini o'sha natija bilan almashtirasiz. Masalaning asosiy maqsadi — Evklid algoritmining (eng katta umumiy bo'luvchini topish algoritmi) kengaytirilgan shaklidan foydalanib, tezkor yechim topishdir.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi Evklid algoritmining operatsiyalarini optimallashtirishga asoslangan. Evklid algoritmi ikki sondan kattasidan kichigini takroran ayirib borish orqali ishlaydi. Bizning holatimizda, agar `a` soni `b` dan katta yoki teng bo'lsa, `a` dan `b` ni `a / b` marta ayirish mumkin. Bu `a` ni `a % b` ga (qoldiqqa) o'zgartirish bilan bir xil, va biz `a / b` ta operatsiyani hisoblaymiz. Xuddi shunday, agar `b` soni `a` dan katta bo'lsa, `b` dan `a` ni `b / a` marta ayirib, `b` ni `b % a` ga o'zgartiramiz va `b / a` ta operatsiyani hisoblaymiz. Bu jarayon sonlardan biri nolga teng bo'lguncha davom etadi.

## Algoritm qadamlari
1.  **Kirishni o'qish:** `a` va `b` ikki butun sonni kirish faylidan `long long` turida o'qib olinadi. Optimal ishlash uchun `ios_base::sync_with_stdio(false);` va `cin.tie(0);` buyruqlari ishlatiladi. Bu C++ kirish/chiqish (I/O) operatsiyalarini tezlashtiradi.
2.  **Operatsiyalar sonini hisoblagichni ishga tushirish:** `operations` nomli `long long` turidagi o'zgaruvchi `0` ga tenglashtiriladi. Bu jami bajarilgan operatsiyalar sonini saqlaydi.
3.  **Takroriy jarayon (tsikl):** `a` ham, `b` ham nolga teng bo'lmaguncha tsikl davom etadi (`while (a != 0 && b != 0)`).
4.  **Sonlarni solishtirish va operatsiya bajarish:**
    *   Agar `a` `b` dan katta yoki teng bo'lsa (`if (a >= b)`):
        *   `operations` ga `a / b` qiymati qo'shiladi. Bu `a` ni `b` dan necha marta ayirish mumkinligini ko'rsatadi.
        *   `a` ning qiymati `a % b` ga almashtiriladi (qoldiq).
    *   Aks holda (ya'ni `b` `a` dan katta bo'lsa):
        *   `operations` ga `b / a` qiymati qo'shiladi.
        *   `b` ning qiymati `b % a` ga almashtiriladi.
5.  **Natijani chiqarish:** Tsikl tugagach (ya'ni sonlardan biri nolga aylanganda), `operations` o'zgaruvchisining oxirgi qiymati konsolga chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi (Time Complexity)**: $O(\log(\min(a,b)))$
    *   Algoritm Evklid algoritmining optimallashtirilgan shakli bo'lib, har bir qadamda ikkala sondan kamida bittasi sezilarli darajada kamayadi. Evklid algoritmining iteratsiyalar soni ikki sondan kichigining logarifmiga proporsionaldir. Shuning uchun, bu yechim juda tez ishlaydi.
-   **Xotira murakkabligi (Space Complexity)**: $O(1)$
    *   Algoritm faqat bir nechta o'zgaruvchilarni (`a`, `b`, `operations`) saqlash uchun doimiy (constant) miqdordagi xotiradan foydalanadi. Kirish sonlarining kattaligiga qarab qo'shimcha xotira talab qilinmaydi.
-   **Nega shu murakkablik chegaraga sig'adi**: Kirish sonlari $10^{18}$ gacha bo'lishi mumkinligi sababli, oddiy "birma-bir ayirish" yondashuvi vaqt limiti (1000 ms) ichida ishlamaydi. $O(\log(\min(a,b)))$ vaqt murakkabligi esa $10^{18}$ kabi katta sonlar uchun ham atigi 60-70 ta iteratsiya atrofida bajariladi, bu esa belgilangan vaqt limiti ichida bemalol ishlashini ta'minlaydi. Xotira $O(1)$ bo'lgani sababli, 32 MB xotira limiti ham muammo tug'dirmaydi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi.
using namespace std;     // 'std' nomfazosidan foydalanishni osonlashtiradi.

int main() {
    // Kirish/chiqish operatsiyalarini tezlashtirish.
    // 'sync_with_stdio(false)' C++ oqimlarini C standart oqimlari bilan sinxronizatsiyasini o'chiradi.
    // 'cin.tie(0)' 'cin' ni 'cout' dan uzadi, shu bilan 'cin' dan keyin 'cout' ning avtomatik tozalanishini oldini oladi.
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    long long a, b; // Katta sonlarni saqlash uchun 'long long' turidan foydalaniladi (10^18 gacha).
    cin >> a >> b;  // Ikki sonni kiritish.

    long long operations = 0; // Bajarilgan operatsiyalar sonini hisoblash uchun o'zgaruvchi.

    // Sonlardan biri nolga teng bo'lmaguncha davom etadigan tsikl.
    // Bu Evklid algoritmining takrorlanishini ifodalaydi.
    while (a != 0 && b != 0) {
        if (a >= b) {
            // Agar 'a' 'b' dan katta yoki teng bo'lsa
            operations += a / b; // 'a' dan 'b' ni necha marta ayirish mumkinligini hisoblab, operatsiyalarga qo'shish.
            a %= b;              // 'a' ni 'b' ga bo'lgandagi qoldiq bilan almashtirish (bir nechta ayirish o'rniga bitta qadam).
        } else {
            // Agar 'b' 'a' dan katta bo'lsa
            operations += b / a; // 'b' dan 'a' ni necha marta ayirish mumkinligini hisoblab, operatsiyalarga qo'shish.
            b %= a;              // 'b' ni 'a' ga bo'lgandagi qoldiq bilan almashtirish.
        }
    }

    cout << operations << endl; // Jami operatsiyalar sonini chiqarish.

    return 0; // Dastur muvaffaqiyatli yakunlanganligini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Nol sonlar:** Agar kirishda `a` yoki `b` (yoki ikkalasi ham) nol bo'lsa, `while (a != 0 && b != 0)` sharti bajarilmaydi va `operations` o'zgaruvchisi o'zgarmagan holda `0` ni qaytaradi. Bu to'g'ri, chunki sonlardan biri allaqachon nol bo'lsa, operatsiya qilish shart emas.
*   **Katta sonlar:** Kirish sonlari $10^{18}$ gacha bo'lishi mumkinligi sababli, `long long` ma'lumot turi ishlatilgan. Bu integer (butun son) toshib ketishining (overflow) oldini oladi. `operations` o'zgaruvchisi ham `long long` bo'lishi muhim, chunki ba'zi holatlarda u ham juda katta qiymatlarga yetishi mumkin (masalan, `a = 1`, `b = 10^18` bo'lsa, birinchi qadamda `operations` ga `10^18` qo'shiladi).
*   **Evklid algoritmi bilan bog'liqlik:** Bu masala Evklid algoritmining "ayirish usuli" ni umumlashtiradi. Evklid algoritmi ikki sonning eng katta umumiy bo'luvchisini (GCD) topish uchun ishlatiladi. Bizning holatimizda, biz GCD ni topmaymiz, balki nolga erishish uchun bajarilgan operatsiyalar sonini hisoblaymiz.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M057B) platformasidagi **M057B** raqamli **Operatsiyalar soni** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M057B>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M057B, Operatsiyalar soni yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
