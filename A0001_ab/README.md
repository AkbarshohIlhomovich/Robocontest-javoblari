---
title: "A0001 — A+B | Robocontest.uz Yechimi"
description: "Robocontest.uz A0001 (A+B) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Uzun sonlar arifmetikasi. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0001, A+B yechimi, robocontest A+B, A0001 c++ kod, uzun sonlar arifmetikasi, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# A0001 — A+B

## Masala haqida
Ushbu masalada ikkita juda katta, manfiy bo'lmagan butun sonni qo'shish talab etiladi. Berilgan sonlar 10^100 gacha bo'lishi mumkin, bu esa standart `int`, `long long` kabi ma'lumot turlari doirasidan ancha kattadir. Kiruvchi sonlar va ularning yig'indisi boshlang'ich nollarsiz (agar sonning o'zi nol bo'lmasa) chop etilishi kerak.

## Yondashuv (g'oya)
Berilgan sonlar standart butun son ma'lumot turlariga sig'maydigan darajada katta bo'lganligi sababli, biz "uzun sonlar arifmetikasi" (ingl. *big integer arithmetic*) yondashuvidan foydalanamiz. Bu shuni anglatadiki, sonlar raqamlar qatori sifatida, ya'ni `string` ma'lumot turi yordamida saqlanadi. Qo'shish jarayoni xuddi qog'ozda qo'lda qo'shishga o'xshash tarzda, o'ngdan chapga qarab, har bir raqamni ketma-ket qo'shib va o'tkaziluvchi qoldiqni (ingl. *carry*) hisobga olgan holda amalga oshiriladi.

## Algoritm qadamlari
1.  **Kirishni o'qish**: Ikki son A va B `string` (satr) ma'lumot turi sifatida `cin` yordamida o'qiladi.
2.  **Stringlarni teskariga aylantirish**: Qo'shish jarayonini soddalashtirish uchun har ikki sonni ifodalovchi stringlar teskari tartibga o'tkaziladi. Masalan, "123" -> "321" bo'ladi. Bu bizga sonlarning eng kichik raqamidan boshlab qo'shish imkonini beradi, xuddi qog'ozda qo'lda qo'shishda bo'lgani kabi.
3.  **Qo'shish jarayoni**:
    *   Natijani saqlash uchun bo'sh `result` stringi va `carry` (o'tkazma) uchun nolga teng `int` o'zgaruvchisi e'lon qilinadi.
    *   Tsikl har ikki sonning barcha raqamlarini yoki `carry` o'zgaruvchisida nolga teng bo'lmagan qoldiq bo'lsa, davom etadi.
    *   Har bir iteratsiyada:
        *   Birinchi sondan (teskari tartibda) joriy raqam (`digit1`) olinadi. Agar birinchi son tugagan bo'lsa, uning qiymati 0 deb olinadi. Belgilar (`char`) raqamlarga (`int`) `char - '0'` orqali o'tkaziladi.
        *   Ikkinchi sondan (teskari tartibda) joriy raqam (`digit2`) olinadi. Agar ikkinchi son tugagan bo'lsa, uning qiymati 0 deb olinadi.
        *   `digit1`, `digit2` va oldingi `carry` qiymatlari qo'shiladi va `current_sum` o'zgaruvchisiga joylashtiriladi.
        *   Yangi `carry` keyingi iteratsiya uchun `current_sum / 10` (butun bo'lish) orqali hisoblanadi.
        *   `current_sum` ning oxirgi raqami (`current_sum % 10`) `result` stringiga qo'shiladi.
4.  **Natijani teskariga aylantirish**: Qo'shish jarayoni stringlar teskari tartibda bo'lgani uchun `result` stringi ham teskari tartibda hosil bo'ladi. Shu sababli, yakuniy natijani olish uchun `result` stringi yana bir bor teskari tartibga o'tkaziladi.
5.  **Natijani chiqarish**: Hosil bo'lgan `result` stringi `cout` yordamida chop etiladi.

## Murakkablik tahlili
-   **Vaqt**: O(max(N, M))
    *   Bu yerda N va M kiruvchi `string`larning uzunligi.
    *   Kirish stringlarini teskariga aylantirish O(N) va O(M) vaqt oladi.
    *   Qo'shish tsikli maksimal N yoki M marta (yoki bitta qo'shimcha iteratsiya agar oxirgi `carry` bo'lsa) bajariladi. Har bir iteratsiyada raqamlarni olish, qo'shish va `result` stringiga qo'shish doimiy vaqt (O(1)) operatsiyalari hisoblanadi.
    *   Yakuniy natija stringini teskariga aylantirish O(max(N, M)) vaqt oladi.
    *   Shuning uchun umumiy vaqt murakkabligi eng uzun kirish sonining uzunligiga proporsional bo'ladi. 100 belgilik sonlar uchun bu juda tez bajariladi.
-   **Xotira**: O(max(N, M))
    *   Kirish sonlari uchun N+M bayt xotira kerak bo'ladi.
    *   Natija `string`ini saqlash uchun maksimal max(N, M) + 1 bayt xotira kerak bo'ladi (agar 99+99=198 bo'lsa, 3 xonali son, ya'ni uzunlik 1 ga ortishi mumkin).
    *   Bu murakkablik berilgan 16 MB xotira chegarasiga bemalol sig'adi, chunki 100 belgilik string juda oz joy egallaydi.

## Kod izohi
```cpp
#include <iostream>
#include <string>
#include <algorithm> // For std::reverse
using namespace std;
```
Bu qismda kerakli kutubxonalar kiritiladi. `iostream` kirish-chiqish uchun, `string` stringlar bilan ishlash uchun, `algorithm` esa `std::reverse` funksiyasi uchun kerak. `using namespace std;` esa `std::` prefiksini yozmasdan standart nom fazosidagi funksiyalardan foydalanish imkonini beradi.

```cpp
string big_int_add(string num1, string num2) {
    // Sonlarni teskari tartibda saqlash, bu qo'shishni birinchi (eng kichik) raqamdan boshlash imkonini beradi.
    // Bu qo'lda qo'shish usuliga o'xshaydi.
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result = ""; // Natijani saqlash uchun string
    int carry = 0;      // Qoldiq (o'tkazish)
    int i = 0;          // Birinchi sonning indeks bo'yicha yuruvchi pointeri
    int j = 0;          // Ikkinchi sonning indeks bo'yicha yuruvchi pointeri
```
`big_int_add` funksiyasi ikkita `string`ni qabul qiladi va yig'indini `string` sifatida qaytaradi. Avval kiruvchi `num1` va `num2` stringlari `std::reverse` funksiyasi yordamida teskari tartibga o'tkaziladi. `result` stringi va `carry` (o'tkazma) nolga teng qilib boshlang'ich holatga keltiriladi. `i` va `j` indekslari mos ravishda `num1` va `num2` bo'ylab yurish uchun ishlatiladi.

```cpp
    // Ikkala sonning barcha raqamlarini yoki qoldiq mavjud bo'lsa, davom etamiz
    while (i < num1.length() || j < num2.length() || carry) {
        // Birinchi sondan raqamni olish, agar son tugagan bo'lsa 0 deb hisoblaymiz
        int digit1 = (i < num1.length()) ? (num1[i] - '0') : 0;
        // Ikkinchi sondan raqamni olish, agar son tugagan bo'lsa 0 deb hisoblaymiz
        int digit2 = (j < num2.length()) ? (num2[j] - '0') : 0;

        // Joriy raqamlar va qoldiqni qo'shamiz
        int current_sum = digit1 + digit2 + carry;
        
        // Yangi qoldiqni hisoblaymiz
        carry = current_sum / 10;
        
        // Joriy yig'indining oxirgi raqamini natijaga qo'shamiz
        result += to_string(current_sum % 10);

        // Keyingi raqamga o'tish
        i++;
        j++;
    }
```
Bu asosiy qo'shish tsikli. `while` sharti `num1` yoki `num2` da hali raqamlar qolgan bo'lsa yoki `carry` o'zgaruvchisida nolga teng bo'lmagan qoldiq bo'lsa, davom etadi.
`digit1` va `digit2` joriy raqamlarni olish uchun ishlatiladi. Agar stringning uzunligi tugagan bo'lsa (ya'ni `i` yoki `j` tegishli string uzunligiga yetgan bo'lsa), u holda raqam 0 deb hisoblanadi. Belgilar (`char`) to'g'ridan-to'g'ri butun sonlarga (`int`) `-'0'` belgisi orqali o'tkaziladi (ASCII kodlaridan foydalanib). Masalan, '5' - '0' = 5.
`current_sum` joriy raqamlar va `carry` ning yig'indisi.
`carry` keyingi bosqichga o'tadigan qoldiqni saqlaydi (`current_sum` ni 10 ga butun bo'lish natijasi).
`result` stringiga esa `current_sum` ning 10 ga bo'lishdan qolgan qoldig'i (ya'ni birlik xonasidagi raqam) qo'shiladi. `to_string` funksiyasi `int`ni `string`ga aylantiradi.
`i` va `j` indekslari har bir iteratsiyadan so'ng bittaga oshiriladi.

```cpp
    // Natija stringi teskari tartibda bo'lgani uchun uni to'g'irlash
    reverse(result.begin(), result.end());

    // Agar natija "00", "0123" kabi boshlang'ich nollarga ega bo'lsa, ularni olib tashlaymiz.
    // Biroq, bizning algoritmimizda, agar kirish "0" bo'lmasa, yakuniy natijada boshlang'ich nol bo'lmaydi.
    // Yagona istisno: agar natija "0" bo'lsa (masalan, 0+0), u holda "0" chiqishi kerak.
    // Bizning algoritm "0" ni to'g'ri qaytaradi, "00" kabi narsalarni yaratmaydi.
    // Shuning uchun bu yerda maxsus boshlang'ich nollarni o'chirishga hojat yo'q.

    return result;
}
```
Tsikl tugagandan so'ng, `result` stringi teskari tartibda bo'ladi, shuning uchun u yana `std::reverse` yordamida to'g'ri tartibga qaytariladi. Kodda boshlang'ich nollarni olib tashlash haqida izoh berilgan, ammo bu algoritm `0`dan tashqari boshlang'ich nol hosil qilmaydi, shuning uchun bu qismga ehtiyoj yo'q. Funksiya yakuniy `result` stringini qaytaradi.

```cpp
int main() {
    // Standart I/O (cin/cout) bilan C++ streamlarini sinxronizatsiyasini o'chirish
    // Bu kirish/chiqish operatsiyalarini tezlashtiradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0); // cin va cout o'rtasidagi bog'liqlikni bekor qilish

    string a, b; // Kiruvchi sonlar uchun stringlar
    cin >> a >> b; // Sonlarni string sifatida o'qish

    // Qo'shish funksiyasini chaqirish va natijani chop etish
    cout << big_int_add(a, b) << endl;

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
```
`main` funksiyasida eng avvalo kirish/chiqish operatsiyalarini tezlashtirish uchun `ios_base::sync_with_stdio(false);` va `cin.tie(0);` qatorlari ishlatilgan. Bu raqobatbardosh dasturlashda standart amaliyot hisoblanadi. Keyin `a` va `b` stringlarga kirish sonlari o'qiladi. `big_int_add` funksiyasi chaqiriladi va uning qaytargan natijasi (`string`) `cout` yordamida ekranga chop etiladi, oxirida `endl` bilan yangi qatorga o'tiladi. `return 0;` dasturning muvaffaqiyatli yakunlanganligini bildiradi.

## Edge case lar va eslatmalar
*   **Manfiy bo'lmagan sonlar**: Masala shartida kiruvchi sonlar manfiy bo'lmagani aytilgan. Bu yechimni ancha soddalashtiradi, chunki manfiy sonlar bilan ishlash uchun qo'shimcha logika talab qilinmaydi.
*   **0 qiymati**: Agar kirish sonlaridan biri yoki ikkalasi ham "0" bo'lsa (masalan, "0" + "0" yoki "123" + "0"), algoritm natijani to'g'ri qaytaradi ("0" yoki "123"). Boshlang'ich nollarni olib tashlashga ehtiyoj yo'q.
*   **Vaqt va xotira chegaralari**: 10^100 gacha bo'lgan sonlar (`string` uzunligi maksimal 100) uchun algoritm juda samarali ishlaydi va berilgan 1000 ms va 16 MB xotira chegarasiga bemalol sig'adi.
*   **`char`dan `int`ga o'tkazish**: `num1[i] - '0'` iborasi `char` turidagi raqam belgisini (masalan, '5') uning `int` turidagi qiymatiga (ya'ni 5) o'tkazishning standart va samarali usuli hisoblanadi.
*   **I/O optimallashtirish**: `ios_base::sync_with_stdio(false);` va `cin.tie(0);` qatorlari C++ stream (oqim)larining tezligini oshirish uchun juda muhim, ayniqsa katta hajmli kirish/chiqish ma'lumotlari bo'lganda.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0001) platformasidagi **A0001** raqamli **A+B** masalasi. U **Uzun sonlar arifmetikasi** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0001>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0001, A+B yechimi, robocontest masalalari, c++17, olimpiada yechimi, uzun sonlar arifmetikasi, dasturlash uzbek, competitive programming O'zbekiston.</sub>
