# R059E — Ajoyib o'yin

## Masala haqida
Azimjon `[a, b]` butun sonlar oralig'idan bir sonni o'ylaydi va uni Davlatbekka aytmaydi. Davlatbekning vazifasi shunday taxminiy sonlarni aytishki, u Azimjon o'ylagan son o'zining taxminlari orasida ekanligiga 100% ishonch hosil qilsin. Masala Davlatbek bu ishonchni hosil qilish uchun eng kamida nechta urunish qilishi kerakligini aniqlashni talab qiladi. Kirish sifatida `a` va `b` butun sonlari beriladi, bu yerda `1 <= a <= b <= 1000`.

## Yondashuv (g'oya)
Davlatbekning Azimjon o'ylagan sonni 100% topganiga ishonch hosil qilishi uchun, u `[a, b]` oralig'idagi har qanday mumkin bo'lgan sonni o'zining taxminlari orasiga kiritgan bo'lishi kerak. Bu degani, Davlatbek Azimjon o'ylagan son `a` bo'lsa ham, `a+1` bo'lsa ham, yoki `b` bo'lsa ham uni topishga tayyor bo'lishi lozim. Shunday qilib, Davlatbekning urinishlari soni `[a, b]` oralig'idagi barcha butun sonlar soniga teng bo'lishi kerak. Masalan, agar Azimjon `[3, 5]` oralig'ida son o'ylagan bo'lsa, Davlatbek `3, 4, 5` sonlarini taxmin qilgan bo'lishi shart, ya'ni uchta urinish.

Bu turdagi oraliqdagi butun sonlar sonini hisoblash uchun umumiy formula `oxirgi_son - birinchi_son + 1` dir. Bizning holatimizda, bu `b - a + 1` bo'ladi.

## Algoritm qadamlari
1. Kirish oqimidan `a` va `b` butun sonlarini o'qing.
2. `[a, b]` oralig'idagi butun sonlar sonini `b - a + 1` formulasi yordamida hisoblang.
3. Hisoblangan natijani konsolga chop eting.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(1)
    -   Sababi: Algoritm kirish sifatida ikkita butun sonni o'qish va bitta arifmetik amal (ayirish va qo'shish) bajarishdan iborat. Bu operatsiyalar soni `a` va `b` ning qiymatidan qat'i nazar doimiy bo'lib qoladi.
-   **Xotira murakkabligi**: O(1)
    -   Sababi: Dastur faqatgina `a` va `b` o'zgaruvchilari uchun kichik, doimiy miqdordagi xotira ishlatadi. Kirish hajmi ortib borgan sari (agar `a` va `b` ning diapazoni kengaysa ham) qo'shimcha xotira talab qilinmaydi.
-   Nega shu murakkablik chegaraga sig'adi: Berilgan vaqt limiti 1000 ms va xotira limiti 16 MB ni tashkil etadi. O(1) vaqt va xotira murakkabligiga ega bo'lgan yechim ushbu cheklovlar ichida mutlaqo minimal resurslarni talab qiladi va juda tez ishlaydi. `a` va `b` ning maksimal qiymati 1000 bo'lganligi sababli, `b - a + 1` ning eng katta natijasi (`1000 - 1 + 1 = 1000`) ham butun son turiga (int) bemalol sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Bu qator standart C++ kutubxonalarini o'z ichiga oladi.
                         // Competitive programmingda tezlikni oshirish uchun keng qo'llaniladi.
                         // Aslida faqat <iostream> (kiritish/chiqarish uchun) yetarli bo'lar edi.

using namespace std; // std nomlar fazosidan (namespace) foydalanishni belgilaydi.
                     // Bu std::cin va std::cout o'rniga faqat cin va cout yozish imkonini beradi.

int main() { // Har qanday C++ dasturining boshlanish nuqtasi.
    // Kiritish/chiqarish (I/O) tezligini optimallashtirish uchun quyidagi ikki qator ishlatiladi:
    ios_base::sync_with_stdio(false); // C++ oqimlarini C oqimlari bilan sinxronizatsiyasini o'chiradi.
                                     // Bu katta hajmdagi kiritish/chiqarishda dastur ishini tezlashtiradi.
    cin.tie(0); // 'cin' (kiritish oqimi) va 'cout' (chiqarish oqimi) o'rtasidagi bog'liqlikni bekor qiladi.
                // 'cout' 'cin' dan oldin avtomatik tarzda bo'shatilishini kutmaydi, bu ham tezlikni oshiradi.

    int a, b; // Masalada berilgan oraliqning boshlanishi va oxiri uchun ikkita butun sonli o'zgaruvchi e'lon qilinadi.
    cin >> a >> b; // Konsoldan 'a' va 'b' o'zgaruvchilariga qiymatlarni o'qiydi.

    cout << b - a + 1 << endl; // Hisoblangan natijani konsolga chop etadi.
                              // 'b - a + 1' formulasi '[a, b]' oralig'idagi butun sonlar sonini aniqlaydi.
                              // 'endl' belgisini qo'shib, yangi qatorga o'tadi va chiqarish buferini bo'shatadi.

    return 0; // Dastur muvaffaqiyatli yakunlanganligini bildiruvchi qiymat.
}
```

## Edge case lar va eslatmalar
-   **Bitta sonli oraliq (a=b)**: Agar Azimjon `5` va `5` oralig'ida son o'ylagan bo'lsa, bu faqat `5` raqamini anglatadi. Davlatbek bitta urinishda (ya'ni `5` deb) 100% ishonch hosil qiladi. Formula `5 - 5 + 1 = 1` ni qaytaradi, bu to'g'ri.
-   **Chegaraviy qiymatlar**: `a` va `b` ning maksimal qiymati `1000` bo'lishi mumkin. Eng katta oraliq `[1, 1000]` bo'lib, uning uzunligi `1000 - 1 + 1 = 1000` ga teng. `int` ma'lumot turi bu qiymatni bemalol saqlay oladi.
-   **Ma'lumot turlari**: `a` va `b` ning qiymati ham, natija ham (`b - a + 1`) `int` ma'lumot turiga sig'adi, chunki ular 1000 dan oshmaydi.
-   **Tezlik va xotira samaradorligi**: `O(1)` murakkablikdagi bu yechim berilgan vaqt va xotira cheklovlari doirasida eng optimal hisoblanadi.
