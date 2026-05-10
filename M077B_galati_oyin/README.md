# M077B — G'alati o'yin

## Masala haqida
Ushbu masalada Shohruh va Shaxboz ishtirokidagi "G'alati o'yin" ta'riflanadi. O'yin `n` butun son bilan boshlanib, har bir o'yinchi navbatma-navbat `n` ga 1 qo'shadi yoki 1 ayiradi. Agar Shaxbozning yurishidan so'ng `n` soni 3 ga bo'linsa, u g'olib chiqadi. Aks holda, 10 ta yurishdan keyin ham Shaxboz g'alaba qozona olmasa, Shohruh g'olib hisoblanadi. Ikkala o'yinchi ham optimal o'ynaganda kim g'olib bo'lishini aniqlash talab etiladi.

## Yondashuv (g'oya)
Masalaning yechimi sonning 3 ga bo'linmasi (modulus 3) ustiga qurilgan. O'yinchilarning harakati faqat sonning 3 ga bo'linmasini o'zgartirishi mumkin. Masalan, agar son `3k` bo'lsa, uni `3k-1` yoki `3k+1` ga o'zgartirish mumkin. Agar son `3k+1` bo'lsa, uni `3k` yoki `3k+2` ga o'zgartirish mumkin. Agar son `3k+2` bo'lsa, uni `3k+1` yoki `3k+3` (ya'ni `3(k+1)`) ga o'zgartirish mumkin.

O'yinning g'oyasi quyidagicha:
- Shaxbozning maqsadi: o'z yurishidan so'ng `n` sonini 3 ga bo'linadigan qilish.
- Shohruhning maqsadi: Shaxbozning yurishidan so'ng `n` soni 3 ga bo'linmasligini ta'minlash.

Optimal o'yinchi har doim g'alaba qozonish uchun eng yaxshi yurishni tanlaydi. Agar `n` boshida 3 ga bo'linsa (`n % 3 == 0`), Shohruh qanday yurish qilmasin, son 3 ga bo'linmaydigan bo'ladi (`n % 3 == 1` yoki `n % 3 == 2`). Shaxbozga navbat kelganida, u 3 ga bo'linmaydigan sonni oladi va uni 3 ga bo'linadigan qilib o'zgartira oladi. Shu sababli Shaxboz g'alaba qozonadi.

Agar `n` boshida 3 ga bo'linmasa (`n % 3 != 0`), Shohruh o'z yurishi bilan `n` sonini 3 ga bo'linadigan qila oladi. Shaxbozga navbat kelganida, u 3 ga bo'linadigan sonni oladi. U +1 yoki -1 qo'shsa, son endi 3 ga bo'linmaydigan bo'ladi. Shu tariqa, Shaxboz hech qachon o'z yurishi bilan 3 ga bo'linadigan son hosil qila olmaydi. Bu holatda Shohruh g'alaba qozonadi.

"10 yurish" cheklovi bu masalada ahamiyatsiz, chunki g'olib birinchi yoki ikkinchi yurishdan keyin aniq bo'ladi.

## Algoritm qadamlari
1. Kiruvchi `n` butun sonini o'qing.
2. `n` sonining 3 ga bo'linmasini (`n % 3`) hisoblang.
3. Agar `n % 3` nolga teng bo'lsa, ya'ni `n` soni 3 ga bo'linsa, "Shaxboz" deb chop eting.
4. Aks holda (`n % 3` nolga teng bo'lmasa), "Shohruh" deb chop eting.

## Murakkablik tahlili
- **Vaqt**: O(1) — Algoritm faqat bitta kirish sonini o'qish, bitta modulo hisoblash va bitta shartni tekshirish kabi doimiy vaqt oladigan operatsiyalarni bajaradi. Kiruvchi `n` sonining kattaligidan qat'i nazar, bu operatsiyalar bir xil vaqtni talab qiladi.
- **Xotira**: O(1) — Algoritm faqat bitta butun son (`n`) uchun xotira ajratadi. Bu ham doimiy xotira talabini bildiradi.
- Bu murakkablik chegaraga sig'adi, chunki `n` soni `10^9` gacha bo'lishiga qaramay, uning faqat 3 ga bo'linmasi hisobga olinadi, bu esa tez va minimal resurslar bilan amalga oshiriladi.

## Kod izohi

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 3 == 0) {
        cout << "Shaxboz\n";
    } else {
        cout << "Shohruh\n";
    }

    return 0;
}
```

1.  `#include <bits/stdc++.h>`: Bu qator C++ dasturlash tilidagi ko'pgina standart kutubxonalarni (masalan, kiritish/chiqarish, matematika funksiyalari va hokazo) o'z ichiga oladi. Competitive programming'da tezlikni oshirish uchun keng qo'llaniladi.
2.  `using namespace std;`: Bu qator `std` (standard) nomfazosidagi funksiyalar va obyektlarga bevosita murojaat qilish imkonini beradi (masalan, `cout` o'rniga `std::cout` yozish shart emas).
3.  `int main() { ... }`: Dasturning asosiy ishga tushish nuqtasi.
4.  `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu qatorlar C++'da kiritish/chiqarish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi. Katta hajmdagi ma'lumotlar bilan ishlaganda muhim ahamiyatga ega.
5.  `int n; cin >> n;`: `n` nomli butun son turidagi o'zgaruvchi e'lon qilinadi va unga kiritish ma'lumotlaridan qiymat o'qiladi.
6.  `if (n % 3 == 0) { ... } else { ... }`: Bu shart operatori masalaning asosiy mantiqini amalga oshiradi:
    -   `n % 3 == 0`: Agar `n` sonining 3 ga bo'linmasidan qolgan qoldiq nolga teng bo'lsa (ya'ni, `n` 3 ga to'liq bo'linsa), `if` bloki bajariladi. Yuqoridagi tahlilga ko'ra, bu holatda Shaxboz g'olib chiqadi, shuning uchun "Shaxboz" chop etiladi.
    -   `else`: Aks holda (agar `n % 3` nolga teng bo'lmasa, ya'ni 1 yoki 2 ga teng bo'lsa), `else` bloki bajariladi. Bu holatda Shohruh g'olib chiqadi, shuning uchun "Shohruh" chop etiladi.
7.  `cout << "..." << "\n";`: Natijani konsolga chop etadi va yangi qatorga o'tadi (`\n`).
8.  `return 0;`: Dastur muvaffaqiyatli yakunlanganligini bildiradi.

## Edge case lar va eslatmalar
-   **Minimum `n` qiymati**: `n=1`. `1 % 3 = 1` bo'lgani uchun, dastur "Shohruh" chiqishini beradi, bu to'g'ri.
-   **3 ga bo'linadigan `n` qiymati**: `n=3`. `3 % 3 = 0` bo'lgani uchun, dastur "Shaxboz" chiqishini beradi, bu to'g'ri.
-   **Maksimum `n` qiymati**: `n=10^9`. Bu kabi katta sonlar uchun ham 3 ga bo'linmani tekshirish faqat doimiy vaqt oladi, chunki operatsiya `n` ning qiymatiga emas, balki bitlar soniga bog'liq.
-   **"10 yurish" cheklovi**: Masalada berilgan "10 yurishdan keyin ham Shaxboz g'olib bo'la olmasa Shohruh g'olib bo'ladi" jumlasi odatda o'yin nazariyasida "red herring" (chalg'ituvchi ma'lumot) deb ataladi. Haqiqatda, o'yin natijasi birinchi ikki yurish (ya'ni, Shohruhning birinchi yurishi va Shaxbozning birinchi yurishi) doirasida aniqlanadi. Optimal o'yin tufayli, Shaxboz birinchi imkoniyatdagi g'alabasini qo'ldan boy bermaydi yoki aksincha, Shohruh Shaxbozning g'alabasiga yo'l qo'ymaydi.
