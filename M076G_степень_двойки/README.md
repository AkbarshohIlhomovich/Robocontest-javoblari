# M076G — Ikki darajasi

## Masala haqida
Bu masala `f(x)` funksiyasini minimal darajalar yig'indisi ko'rinishida berilgan `x` sonini ifodalash uchun zarur bo'ladigan hadlar soni deb ta'riflaydi. Misol uchun, 6 sonini 4+2 ko'rinishida yozish mumkin, bu yerda 2 ta had ishlatilgan. Shuning uchun `f(6) = 2`. Aslida, `f(x)` bu `x` sonining ikkilik ko'rinishidagi birlar soniga (popcount) tengdir. Masala `n` natural soni berilganida, `f(m) = f(n)` shartini qanoatlantiruvchi va `n` dan katta bo'lgan eng kichik `m` natural sonini topishni talab qiladi.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi `n` natural sonining ikkilik ko'rinishida bir xil miqdordagi birlarga (set bits) ega bo'lgan, `n` dan katta eng kichik `m` sonini topishdan iborat. Bu masalani bit operatsiyalari yordamida samarali hal qilish mumkin. Bunday yechim "keyingi raqamni topish" ("next number with same number of set bits") deb nomlanuvchi klassik bit manipulyatsiya algoritmlaridan biridir.

## Algoritm qadamlari
Berilgan C++ yechimi standart bit manipulyatsiya algoritmini qo'llaydi:

1. **Eng o'ngdagi o'rnatilgan bitni topish**: `c = n & -n` orqali `n` ning ikkilik ko'rinishidagi eng o'ngdagi (eng past razryaddagi) `1` bitning qiymati (`2^p`) aniqlanadi. Misol uchun, agar `n = 6 (0110_2)` bo'lsa, `c = 2 (0010_2)` bo'ladi.
2. **"Tashuvchi" qiymatni hisoblash**: `r = n + c` hisoblanadi. Bu qadam `n` dan keyingi bir qator bitlar o'zgarishini boshlaydi. `r` qiymati `n` ning eng o'ngdagi nol bitini `1` ga o'zgartiradi va shu nol bitdan o'ngdagi barcha `1` bitlarni `0` ga aylantiradi. Misol uchun, agar `n = 6 (0110_2)` va `c = 2 (0010_2)` bo'lsa, `r = 6 + 2 = 8 (1000_2)` bo'ladi. Bu holatda, `n` ning 2-pozitsiyasidagi `0` (o'ngdan 0-indeksli) `1` ga aylanadi va 1-pozitsiyasidagi `1` o'chiriladi.
3. **O'zgaruvchi bitlarni ajratib olish**: `n ^ r` ifodasi `n` va `r` orasidagi farqli bitlarni ajratib oladi. Bu qiymat `r` da `0` dan `1` ga o'zgargan bitni va `n` da mavjud bo'lib, `r` da `0` ga aylangan barcha `1` bitlarni o'z ichiga oladi. Misol uchun, `n = 6 (0110_2)` va `r = 8 (1000_2)` bo'lsa, `n ^ r = 0110_2 ^ 1000_2 = 1110_2` (ya'ni 14) bo'ladi.
4. **O'zgartirilgan bitlarni joylashishini sozlash**: `(((n ^ r) >> 2) / c)` qismi o'zgaruvchi bitlarni qayta tartiblash va ularni `m` ning eng past razryadlariga joylashtirish uchun ishlatiladi.
    - `(n ^ r) >> 2` bitlarni ikki pozitsiya o'ngga suradi.
    - `/ c` operatsiyasi `c` qiymatiga bo'lish (u `2^p` ko'rinishida bo'lgani uchun o'ngga `p` pozitsiya surish bilan barobar) yordamida bitlarni yanada o'ngga suradi. Bu qadam birgalikda `n` dan yo'qolgan `1` bitlarni `r` ning yangi shakllangan `1` bitidan so'ng eng past razryadlarga joylashtirishni ta'minlaydi.
5. **Yakuniy natijani olish**: Yuqoridagi qadamda hisoblangan qiymat `r` bilan "bitwise OR" (`|`) operatsiyasi orqali birlashtiriladi. Bu `r` ning yangi, yuqori tartibli `1` bitini va `n` ning popcountini saqlab qolish uchun qayta joylashtirilgan past tartibli `1` bitlarni birlashtiradi. Natijada `n` dan katta bo'lgan va `f(m) = f(n)` shartini qanoatlantiruvchi eng kichik `m` soni olinadi.

## Murakkablik tahlili
- **Vaqt**: `O(1)`. Algoritm faqat bir nechta bitwise (bitli) operatsiyalardan iborat bo'lib, ular kompyuter arxitekturasida doimiy vaqtda bajariladi. Shuning uchun, hisoblash vaqti `n` ning kattaligiga bog'liq emas.
- **Xotira**: `O(1)`. Algoritm faqat bir nechta o'zgaruvchilarni saqlash uchun doimiy miqdordagi xotiradan foydalanadi.
- **Chegaraga sig'ishi**: Masalada `n` ning qiymati `1` dan `2^30` gacha bo'lishi aytilgan. C++ dagi `unsigned int` ma'lumot turi `2^32 - 1` gacha bo'lgan qiymatlarni saqlay oladi, shuning uchun `n` va oraliq hisob-kitoblar ushbu turga sig'adi. Bit operatsiyalari ham `unsigned int` uchun to'g'ri ishlaydi va yuqoridagi vaqt/xotira murakkabliklari berilgan chegaralarga to'liq mos keladi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi, bunda barcha kerakli funksiyalar mavjud.

using namespace std; // std nomlar fazosidan foydalanishni osonlashtiradi.

int main() {
    // Kiritish/chiqarish (I/O) tezligini oshirish uchun standart kod
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    unsigned int n; // n natural sonini saqlash uchun unsigned int turidagi o'zgaruvchi
    cin >> n; // n qiymatini kiritish

    // 1. Eng o'ngdagi (eng past razryaddagi) o'rnatilgan bitning qiymatini (2^p) topish.
    // Misol: n=6 (0110_2). -n ikkilik to'ldiruvchida ~n+1 = (1001_2)+1 = 1010_2.
    // c = 0110_2 & 1010_2 = 0010_2 (ya'ni 2).
    unsigned int c = n & -n; 
    
    // 2. n ga c ni qo'shib, keyingi "kattaroq" bit patternini hisoblash.
    // Bu n dagi eng o'ngdagi 0 bitni 1 ga aylantiradi va undan o'ngdagi barcha 1 bitlarni 0 ga aylantiradi.
    // Misol: n=6 (0110_2), c=2 (0010_2). r = 6+2 = 8 (1000_2).
    unsigned int r = n + c; 
    
    // 3. Yakuniy natija m ni hisoblash.
    // (n ^ r) n va r orasidagi farqli bitlarni (o'zgargan bitlarni) ajratadi.
    // (n ^ r) >> 2 bu bitlarni 2 pozitsiya o'ngga suradi.
    // / c (yoki >> log2(c)) bu bitlarni c ning qiymatiga qarab yana o'ngga suradi.
    // Bu qadam n ning popcountini saqlab qolish uchun o'chirilgan 1 bitlarni qayta joylashtiradi.
    // Yakunda bu qayta joylashtirilgan bitlar r bilan OR (|) qilinib, natijaviy m soni hosil qilinadi.
    unsigned int next = (((n ^ r) >> 2) / c) | r; 

    cout << next << endl; // Hisoblangan m sonini chiqarish

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildirish
}
```

## Edge case lar va eslatmalar
- **`unsigned int`dan foydalanish**: `n` natural son bo'lganligi va bit manipulyatsiyalari bilan ishlayotganimiz sababli, `unsigned int` ma'lumot turidan foydalanish maqsadga muvofiq. Bu musbat sonlar bilan ishlashda va bit operatsiyalarining kutilgan xatti-harakatini ta'minlashda yordam beradi. Xususan, `-n` ni hisoblashda `unsigned int` ikki to'ldiruvchining standart xatti-harakatini ta'minlaydi.
- **`n` ning maksimal qiymati**: `n` `2^30` gacha bo'lishi mumkin. Bu qiymat `unsigned int` sig'imiga to'liq mos keladi va hisoblash jarayonida hech qanday to'lib ketish (overflow) muammosi yuzaga kelmaydi.
- **Popcount 1 bo'lgan holatlar**: Agar `n` o'zi ikki darajasi bo'lsa (masalan, `n = 2^k`), uning popcounti 1 ga teng bo'ladi. Algoritm bu holatda ham to'g'ri ishlaydi va keyingi `2^(k+1)` sonini qaytaradi (uning ham popcounti 1).
    - Misol: `n = 4 (0100_2)`. `c = 4`. `r = 4+4 = 8 (1000_2)`. `n^r = 1100_2`. `((1100_2 >> 2) / 4) | 8 = (0011_2 / 4) | 8 = (3 / 4) | 8 = 0 | 8 = 8`.
- **Barcha bitlar o'rnatilgan holatlar**: Agar `n = 2^k - 1` (masalan, `n = 7 (0111_2)`) bo'lsa, algoritm keyingi `2^k + 2^(k-2) + ... + 2^0` turdagi sonni topadi. Bu ham to'g'ri ishlaydi, chunki bu sonning popcounti `n` ning popcounti bilan bir xil bo'ladi.
    - Misol: `n = 7 (0111_2)`. `c = 1`. `r = 7+1 = 8 (1000_2)`. `n^r = 1111_2`. `((1111_2 >> 2) / 1) | 8 = (0011_2 / 1) | 8 = 3 | 8 = 11 (1011_2)`. `popcount(7)=3`, `popcount(11)=3`.
