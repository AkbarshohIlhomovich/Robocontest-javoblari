# M072H — +1

## Masala haqida
Abdullohga berilgan juda katta tabiiy son mavjud bo'lib, u oson o'qilishi uchun har uchta raqamini bo'sh joy (probel) bilan ajratib yozgan. Sizdan bu songa 1 ni qo'shib, natijani odatiy (bo'sh joysiz) formatda chiqarish so'raladi. Sonning qiymati $10^{18}$ gacha bo'lishi mumkin.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi – berilgan raqamni to'g'ri o'qish, undagi keraksiz bo'sh joylarni olib tashlash, butun son turiga o'tkazish, 1 qo'shish va yakuniy natijani standart formatda chop etishdan iborat. Sonning $10^{18}$ gacha bo'lishi mumkinligini hisobga olsak, uni `long long` ma'lumot turida saqlashimiz kerak, chunki `int` ma'lumot turi bu qadar katta sonni saqlay olmaydi. Input string ko'rinishida va bo'sh joylar bilan ajratilganligi sababli, uni avval string sifatida o'qish va keyin bo'sh joylardan tozalash maqsadga muvofiqdir.

## Algoritm qadamlari
1.  **Kirishni o'qish**: Berilgan sonni butun bir qator (string) sifatida o'qib olish, chunki son raqamlari orasida bo'sh joylar mavjud. Oddiy `cin >> int` yoki `cin >> long long` funksiyalari birinchi bo'sh joyga yetganda o'qishni to'xtatadi.
2.  **Bo'sh joylarni olib tashlash**: O'qilgan stringdan barcha bo'sh joylarni o'chirib tashlash.
3.  **Son turiga o'tkazish**: Bo'sh joylardan tozalangan stringni `long long` (uzun butun son) ma'lumot turiga o'tkazish.
4.  **1 qo'shish**: Son qiymatiga 1 qo'shish.
5.  **Natijani chiqarish**: Hosil bo'lgan sonni odatiy (bo'sh joysiz) formatda ekranga chop etish.

## Murakkablik tahlili
-   **Vaqt**: `O(L)`
    -   `getline(cin, s)`: Kirish qatorini o'qish string uzunligiga (L) proporsional vaqt talab qiladi.
    -   `s.erase(remove(s.begin(), s.end(), ' '), s.end())`: Bo'sh joylarni olib tashlash uchun string bo'ylab bir marta iteratsiya (aylanish) talab etiladi, bu ham `O(L)` vaqt.
    -   `stoll(s)`: Stringni `long long` ga o'tkazish string uzunligiga proporsional vaqt oladi, `O(L)`.
    -   `num++`: Bir butun songa 1 qo'shish doimiy vaqtda bajariladi, `O(1)`.
    -   `cout << num`: Sonni ekranga chop etish uning raqamlari soniga (log(N)) proporsional vaqt oladi, bu ham L ga yaqin.
    -   Umumiy hisobda, eng yomon holatda ham (L input stringining uzunligi) vaqt murakkabligi `O(L)` bo'ladi. $N \le 10^{18}$ bo'lgani uchun L juda kichik bo'ladi (taxminan 19-20 raqam + bir nechta bo'sh joy, ya'ni L ~ 25-30 belgidan oshmaydi). Bu juda samarali.

-   **Xotira**: `O(L)`
    -   `string s`: Kirish qatorini saqlash uchun `O(L)` xotira talab qilinadi.
    -   `long long num`: Bir `long long` sonni saqlash uchun doimiy `O(1)` xotira talab qilinadi.
    -   Umumiy hisobda, xotira murakkabligi `O(L)` bo'ladi. L juda kichik bo'lgani sababli, xotira talabi ham juda kam (bir necha bayt).

-   **Nega shu murakkablik chegaraga sig'adi**:
    Kirish soni $10^{18}$ gacha bo'lishi mumkin bo'lsa-da, uning string ko'rinishidagi uzunligi (L) maksimal 19 ta raqam va 6 ta bo'sh joydan iborat bo'ladi (masalan, "999 999 999 999 999 999" - jami 25 ta belgi). Shuning uchun L ning kichik qiymati tufayli `O(L)` vaqt va xotira murakkabligi juda tez va berilgan 1000 ms vaqt limiti hamda 32 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi.

using namespace std; // std nom fazosini ishlatish uchun.

int main() {
    // Kiritish/chiqarish (I/O) operatsiyalarini tezlashtirish.
    // std::ios_base::sync_with_stdio(false) C++ streamlarini C standart I/O bilan sinxronlashni o'chiradi.
    // std::cin.tie(0) cin dan keyin cout ni avtomatik ravishda tozalashni bekor qiladi.
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    string s; // Kirishni saqlash uchun string e'lon qilish.
    getline(cin, s); // Kirish qatorini, shu jumladan bo'sh joylarni ham o'qiydi.

    // Stringdan barcha bo'sh joylarni olib tashlash.
    // remove() funksiyasi stringdagi barcha ' ' (bo'sh joy) belgilarini oxiriga suradi
    // va birinchi bo'sh joy belgisiga ishora qiluvchi iteratorni qaytaradi.
    // s.erase() funksiyasi esa bu iteratordan string oxirigacha bo'lgan qismni o'chirib tashlaydi.
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    // Tozalangan stringni long long (uzun butun son) turiga aylantirish.
    // stoll() funksiyasi stringni long long ga konvertatsiya qiladi.
    long long num = stoll(s);

    num++; // Songa 1 qo'shish.

    cout << num << endl; // Natijani ekranga chiqarish va qator oxirida yangi qatorga o'tish.

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Katta sonlar**: Masala shartida berilgan $N \le 10^{18}$ sharti, `int` ma'lumot turi yetarli emasligini anglatadi. `long long` ma'lumot turi $9 \times 10^{18}$ gacha bo'lgan sonlarni saqlay oladi, shuning uchun bu masala uchun to'g'ri tanlov hisoblanadi.
*   **Kirish formatlash**: Input soni bo'sh joylar bilan ajratilganligi sababli, `cin >> s` o'rniga `getline(cin, s)` dan foydalanish juda muhim. `cin >> s` faqat birinchi bo'sh joygacha bo'lgan qismni o'qib, qolganini o'qimaydi.
*   **Oxirgi raqam 9 bo'lsa**: Agar sonning oxirgi raqami 9 bo'lsa (masalan, "123 456 789"), unga 1 qo'shganda raqamlar o'zgarishi ("123456790") yoki hattoki xonalar soni ortishi (masalan, "999 999" ga 1 qo'shganda "1000000") mumkin. `long long` ma'lumot turi bu hisob-kitoblarni avtomatik tarzda to'g'ri bajaradi.
*   **Bo'sh joylarni olib tashlash usuli**: `remove` va `erase` funksiyalarining birgalikda ishlatilishi C++ da stringdagi ma'lum belgilarni samarali olib tashlashning standart va tavsiya etilgan usullaridan biridir.
