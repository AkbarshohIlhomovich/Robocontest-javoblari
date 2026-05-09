# A0006 — O'yin

## Masala haqida
Ali va Bobur o'yin o'ynashadi, o'yin `n` butun soni bilan boshlanadi, bu son `{1, 2, ..., n}` to'plamini shakllantirish uchun ishlatiladi. Har bir navbatda o'yinchi to'plamdan bitta tub sonni tanlab oladi va to'plamdan shu tub songa bo'linadigan barcha sonlarni olib tashlaydi. O'z navbatida yurish qila olmagan o'yinchi yutqazadi. Bizning vazifamiz `n` soni berilganda o'yinda kim g'olib bo'lishini aniqlash.

## Yondashuv (g'oya)
Bu masala, asosan, o'yin nazariyasiga oid muammo bo'lib, o'yinda mumkin bo'lgan harakatlar sonini aniqlashga asoslanadi. Har bir yurishda o'yinchi to'plamdan tub son tanlaydi va uning barcha karralilarini o'chiradi. Muhim jihati shundaki, bir marta tanlangan tub son qayta tanlana olmaydi. Boshqa tub sonlarning karralilarini olib tashlash ularning o'zini tub son sifatida tanlash imkoniyatiga ta'sir qilmaydi (chunki tub sonlar faqat o'ziga va 1 ga bo'linadi, shuning uchun boshqa tub sonning karralisi bo'lmaydi).

Shu sababli, o'yinda qilinishi mumkin bo'lgan jami harakatlar soni `n` dan katta bo'lmagan tub sonlar soniga teng bo'ladi. Har bir harakat bitta tub sonni iste'mol qiladi. Bu o'yin shundayki, birinchi o'yinchi (Ali) g'alaba qozonadi, agar jami harakatlar soni (ya'ni, tub sonlar soni) toq bo'lsa, va ikkinchi o'yinchi (Bobur) g'alaba qozonadi, agar jami harakatlar soni juft bo'lsa. Bu klassik kombinatorik o'yin bo'lib, g'olibni umumiy harakatlar sonining juft/toqligiga qarab aniqlaydi.

Yechim g'oyasi: `n` gacha bo'lgan barcha tub sonlarni Sieve of Eratosthenes (Eratosfen g'alviri) algoritmi yordamida topish va ularning sonini sanash. Keyin, bu hisoblangan tub sonlar sonining juft yoki toq ekanligiga qarab g'olibni aniqlash.

## Algoritm qadamlari
1.  **Kirishni o'qish**: `n` butun sonini kirish oqimidan o'qib olish.
2.  **Sievni boshlash**: `n+1` o'lchamli `vector<bool> is_prime` massivini yaratish va barcha elementlarini `true` ga o'rnatish. Bu massiv `i`-indeksdagi sonning tub (true) yoki murakkab (false) ekanligini ko'rsatadi.
3.  **Boshlang'ich qiymatlarni belgilash**: `0` va `1` sonlari tub emasligini hisobga olib, `is_prime[0]` va `is_prime[1]` qiymatlarini `false` ga o'rnatish.
4.  **Eratosfen g'alvirini qo'llash**:
    *   `p = 2` dan boshlab, `p * p <= n` sharti bajarilguncha takrorlash (iteratsiya qilish).
    *   Agar `is_prime[p]` `true` bo'lsa (ya'ni, `p` tub son bo'lsa):
        *   `p` ning barcha karralilarini (o'zidan kattalarini) `is_prime` massivida `false` ga o'rnatish. Ya'ni, `i = p * p` dan boshlab `n` gacha `p` qadam bilan `is_prime[i] = false` deb belgilash.
5.  **Tub sonlar sonini sanash**: `prime_count` nomli butun sonli o'zgaruvchini `0` ga tenglashtirish. `p = 2` dan `n` gacha bo'lgan barcha sonlar bo'yicha takrorlash. Agar `is_prime[p]` `true` bo'lsa, `prime_count` ni bittaga oshirish.
6.  **G'olibni aniqlash**:
    *   Agar `prime_count` toq son bo'lsa (`prime_count % 2 == 1`), "Ali" ni chop etish.
    *   Aks holda (agar `prime_count` juft son bo'lsa), "Bobur" ni chop etish.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(`N log log N`)
    *   Asosiy vaqt sarfi Eratosfen g'alviri (Sieve of Eratosthenes) algoritmini bajarishga ketadi. Bu algoritmni `N` gacha bo'lgan sonlar uchun ishlash vaqti `O(N log log N)` ga teng.
    *   `N = 10^5` bo'lganda, `log N` taxminan `17` ga, `log log N` taxminan `2-3` ga teng. Demak, `10^5 * 2-3` operatsiyalar qilinadi, bu juda tez va `1000 ms` vaqt chegarasiga bemalol sig'adi.
-   **Xotira murakkabligi**: O(`N`)
    *   Algoritm `is_prime` nomli `vector<bool>` massivini saqlash uchun `N+1` boolean qiymatini talab qiladi.
    *   `N = 10^5` bo'lganda, bu taxminan `10^5` bit (yoki `12.5 KB`) xotira talab qiladi. `16 MB` xotira chegarasiga juda osongina sig'adi.
-   **Nega shu murakkablik chegaraga sig'adi**: Berilgan `N` qiymati (`10^5`) uchun `O(N log log N)` vaqt murakkabligi va `O(N)` xotira murakkabligi zamonaviy kompyuterlarda juda samarali hisoblanadi va belgilangan vaqt (1000 ms) va xotira (16 MB) chegaralariga osongina mos keladi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi, shu jumladan vector va iostream

using namespace std; // std nomlar fazosidan foydalanishni osonlashtiradi

int main() {
    // Kiritish/chiqarish operatsiyalarini tezlashtirish.
    // C standart kirish/chiqarish (stdio) bilan C++ ning iostream ni sinxronizatsiyasini o'chiradi.
    // Cin va cout oqimlarini bog'lamaydi, bu ularni tezroq ishlashiga yordam beradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0); // Cin dan keyin cout flush bo'lishini o'chiradi, bu ham tezlikni oshiradi.

    int n;
    cin >> n; // N sonini kiritish.

    // N+1 o'lchamli boolean vector yaratish va barcha elementlarini true (tub) deb boshlash.
    // is_prime[i] = true bo'lsa, i soni tub degani.
    vector<bool> is_prime(n + 1, true); 

    // 0 va 1 sonlari tub emas. Shuning uchun ularni false deb belgilaymiz.
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    // Eratosfen g'alviri algoritmi.
    // p = 2 dan boshlab, p*p <= n sharti bajarilguncha takrorlanadi.
    for (int p = 2; p * p <= n; ++p) {
        // Agar p soni hali ham tub deb belgilangan bo'lsa (ya'ni, u tub son bo'lsa).
        if (is_prime[p]) {
            // p ning barcha karralilarini (p*p dan boshlab) tub emas deb belgilaymiz.
            // Chunki p*p dan kichik karralilari allaqachon avvalgi tub sonlar tomonidan belgilangan bo'ladi.
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    // N gacha bo'lgan tub sonlar sonini sanash.
    int prime_count = 0;
    // 2 dan N gacha bo'lgan barcha sonlarni tekshiramiz.
    for (int p = 2; p <= n; ++p) {
        // Agar is_prime[p] true bo'lsa, p soni tub hisoblanadi.
        if (is_prime[p]) {
            prime_count++; // Tub sonlar sonini bittaga oshiramiz.
        }
    }

    // O'yinning g'olibini aniqlash.
    // Agar tub sonlar soni toq bo'lsa, birinchi o'yinchi (Ali) yutadi.
    if (prime_count % 2 == 1) {
        cout << "Ali" << endl;
    } 
    // Aks holda (tub sonlar soni juft bo'lsa), ikkinchi o'yinchi (Bobur) yutadi.
    else {
        cout << "Bobur" << endl;
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **`n = 1` holati**: Agar `n = 1` bo'lsa, `{1}` to'plamida tub sonlar yo'q. `prime_count` `0` ga teng bo'ladi. `0` juft son bo'lgani uchun "Bobur" g'olib chiqadi, bu to'g'ri, chunki Ali hech qanday yurish qila olmaydi.
*   **`n = 2` holati**: Agar `n = 2` bo'lsa, `{1, 2}` to'plamida yagona tub son `2` mavjud. `prime_count` `1` ga teng bo'ladi. `1` toq son bo'lgani uchun "Ali" g'olib chiqadi, bu to'g'ri, chunki Ali `2` ni tanlab oladi va Boburga yurishga hech narsa qoldirmaydi.
*   **Xotira optimizatsiyasi**: C++ dagi `vector<bool>` xususan bit-packing (bitlarni yig'ish) mexanizmi orqali juda samarali xotiradan foydalanadi, ya'ni har bir `bool` uchun 1 bayt emas, balki 1 bit ishlatadi. Bu `N=10^5` kabi katta `N` qiymatlarida `16 MB` kabi kichik xotira chegaralariga sig'ishga yordam beradi.
