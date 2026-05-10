# M041A — Gulliver

## Masala haqida
Bu masala Jonatan Sviftning "Gulliverning sayohatlari" kitobidan ilhomlanib yaratilgan. Lilliputiyaliklar Gulliver uchun o'zlarining kichik matraslaridan foydalanib to'shak yasashlari kerak. Gulliver Lilliputlardan `K` marta katta va to'shak `M` qatlamdan iborat bo'lishi kerak. Bizning vazifamiz Gulliver uchun to'shak qurish uchun kamida nechta kichik matras kerakligini topish.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi – Gulliverning o'lchamlarini Lilliput matraslarining o'lchamlari bilan bog'lashdir. Agar Gulliver Lilliputlardan `K` marta katta bo'lsa, uning to'shagi uzunligi va kengligi bo'yicha ham `K` marta katta bo'lishi kerak. Bundan tashqari, to'shak bir nechta qatlamdan (`M` qatlam) iborat bo'lishini hisobga olish kerak.

Faraz qilaylik, Lilliputiyaliklarning bitta matrasi 1x1 birlik o'lchamga ega. Agar Gulliver `K` marta katta bo'lsa, uning to'shagining har bir tomoni (uzunligi va kengligi) `K` ta matrasga teng bo'lishi kerak. Bu degani, bitta qatlamli to'shak `K` uzunlikka va `K` kenglikka ega bo'ladi. Matraslar sonini topish uchun biz shunchaki uzunlikni kenglikka ko'paytiramiz, ya'ni `K * K`. Agar to'shak `M` qatlamdan iborat bo'lsa, umumiy matraslar soni `(K * K) * M` formulasi orqali hisoblanadi.

## Algoritm qadamlari
1.  Kirish ma'lumotlari — `K` (Gulliverning nisbiy kattaligi) va `M` (matras qatlamlari soni) o'zgaruvchilarni butun son sifatida o'qib oling.
2.  Bitta qatlamdagi matraslar sonini hisoblang. Gulliverning to'shagi har bir tomoni bo'yicha `K` marta katta bo'lgani uchun, bitta qatlam uchun `K * K` ta matras kerak bo'ladi.
3.  Jami matraslar sonini hisoblang. To'shak `M` qatlamdan iborat bo'lgani sababli, 2-qadamda topilgan qiymatni `M` ga ko'paytiring: `M * K * K`.
4.  Hisoblangan natijani chiqishga chop eting.

## Murakkablik tahlili
-   **Vaqt murakkabligi (Time Complexity)**: O(1)
    *   Algoritm faqat bir nechta o'zgaruvchini o'qiydi va bitta arifmetik hisoblash (uchta butun sonni ko'paytirish) amalga oshiradi. Kirish ma'lumotlarining hajmidan (bu yerda `K` va `M` faqat o'zgaruvchilarning qiymatlari, loop yoki rekursiya yo'q) qat'i nazar, operatsiyalar soni doimiy bo'lib qoladi. Shuning uchun vaqt murakkabligi doimiy — O(1).
-   **Xotira murakkabligi (Space Complexity)**: O(1)
    *   Dastur faqat bir nechta o'zgaruvchini (`k`, `m`, `result`) saqlash uchun doimiy miqdordagi xotiradan foydalanadi. Kirish ma'lumotlari hajmi qanchalik katta bo'lmasin (chegaralar ichida), dastur tomonidan ishlatiladigan xotira miqdori o'zgarmaydi. Shuning uchun xotira murakkabligi ham doimiy — O(1).
-   **Nega shu murakkablik chegaraga sig'adi**:
    Berilgan `K` va `M` chegaralari (2 dan 100 gacha) juda kichik. Eng katta natija `100 * 100 * 100 = 1,000,000` bo'ladi, bu `long long` (yoki hatto `int`) turiga osongina sig'adi. O(1) vaqt va xotira murakkabligi esa deyarli har qanday vaqt va xotira cheklovlariga bemalol mos keladi, ayniqsa 1000 ms va 16 MB kabi standart cheklovlar uchun. Hisoblash bir necha nanosekundda bajariladi va minimal xotira ishlatiladi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // 1

using namespace std; // 2

int main() { // 3
    ios_base::sync_with_stdio(false); // 4
    cin.tie(0); // 4

    long long k, m; // 5
    cin >> k >> m; // 6

    long long result = m * k * k; // 7

    cout << result << endl; // 8

    return 0; // 9
}
```

1.  `#include <bits/stdc++.h>`: Bu satr C++ dasturlash tilidagi ko'plab standart kutubxonalarni (masalan, kirish/chiqish operatsiyalari uchun `iostream`, matematik funksiyalar va hokazo) o'z ichiga oladi. Competitive programmingda tezlikni ta'minlash uchun ko'pincha barcha standart kutubxonalarni shu tarzda birma-bir emas, balki birgalikda qo'shish amaliyoti keng tarqalgan.
2.  `using namespace std;`: Bu nomlar makonidan (namespace) foydalanishni bildiradi. Bu orqali biz `std::` prefiksini yozmasdan, `cout`, `cin`, `endl` kabi standart funksiya va obyektlardan to'g'ridan-to'g'ri foydalanishimiz mumkin.
3.  `int main() { ... }`: Har qanday C++ dasturining asosiy kirish nuqtasi hisoblanadi. Dastur mana shu funksiyadan boshlab ishga tushadi.
4.  `ios_base::sync_with_stdio(false); cin.tie(0);`: Ushbu ikki qator C++ ning kirish/chiqish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi. `sync_with_stdio(false)` C uslubidagi I/O (printf, scanf) bilan C++ uslubidagi I/O (cout, cin) o'rtasidagi sinxronizatsiyani o'chiradi, bu esa tezlikni oshiradi. `cin.tie(0)` esa `cin` obyekti `cout` bilan bog'lanmasligini ta'minlaydi, ya'ni `cin` dan oldin `cout` buferini tozalashni kutmaydi. Kichik masalalarda unchalik ahamiyatli bo'lmasa-da, katta kirish/chiqish ma'lumotlari bo'lgan masalalarda bu juda muhimdir.
5.  `long long k, m;`: Bu yerda `k` va `m` nomli ikkita o'zgaruvchi e'lon qilingan. Ularning turi `long long` qilib belgilangan. Garchi `K` va `M` ning maksimal qiymati (100) natija `int` turiga sig'sa ham (`100 * 100 * 100 = 1,000,000`), `long long` ishlatish xavfsizroq amaliyotdir va natijaning haddan tashqari katta bo'lishi ehtimolini oldini oladi (agar chegaralar kelajakda kattalashtirilsa).
6.  `cin >> k >> m;`: Kirish faylidan ikki butun sonni o'qib oladi va ularni mos ravishda `k` va `m` o'zgaruvchilariga joylashtiradi.
7.  `long long result = m * k * k;`: Matraslar sonini hisoblaydi. `k * k` bitta qatlam uchun kerak bo'ladigan matraslar sonini ifodalaydi (K uzunlik, K kenglik). Bu sonni qatlamlar soni (`m`) ga ko'paytirish Gulliver uchun jami kerak bo'ladigan matraslar sonini beradi. Natija `result` o'zgaruvchisiga `long long` turida saqlanadi.
8.  `cout << result << endl;`: Hisoblangan `result` (jami matraslar soni) qiymatini chiqishga chop etadi. `endl` yangi qatorga o'tishni ta'minlaydi.
9.  `return 0;`: `main` funksiyasi muvaffaqiyatli yakunlanganini va dastur xatolarsiz ishlaganini ko'rsatadi.

## Edge case lar va eslatmalar
*   **Minimal qiymatlar**: Masala shartiga ko'ra `K` va `M` ning minimal qiymati 2 ga teng. Agar `K=2, M=2` bo'lsa, formula `2 * 2 * 2 = 8` natijasini beradi, bu birinchi sample testiga mos keladi. Bu shuni ko'rsatadiki, formula eng kichik mumkin bo'lgan holatlar uchun ham to'g'ri ishlaydi.
*   **Maksimal qiymatlar**: `K` va `M` ning maksimal qiymati 100 ga teng. Agar `K=100, M=100` bo'lsa, natija `100 * 100 * 100 = 1,000,000` bo'ladi. Bu qiymat `int` turiga (odatda 2 milliardgacha) sig'sa ham, `long long` turidan foydalanish amalda katta natijalar bilan ishlayotganda xavfsizroq va odatiy yondashuv hisoblanadi.
*   **Matematik formulaning soddaligi**: Masala hech qanday murakkab algoritm yoki ma'lumotlar tuzilmalarini talab qilmaydi. Bu oddiy arifmetik formulaga asoslangan bo'lib, uning yechimi to'g'ridan-to'g'ri hisoblashdan iborat. Bu turdagi masalalar ko'pincha "to'g'ridan-to'g'ri amalga oshirish" (direct implementation) yoki "matematika" kategoriyasiga kiradi.
