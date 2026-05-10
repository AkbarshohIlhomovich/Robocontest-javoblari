# M047C — Taqqoslash

## Masala haqida
Ushbu masalada sizga uchta butun son beriladi. Sizning vazifangiz bu uchta son orasida nechta turli (noyob) son borligini aniqlash va chop etishdir. Kiruvchi sonlarning absolyut qiymati 1000 dan oshmaydi.

## Yondashuv (g'oya)
Masalaning asosiy talabi – berilgan sonlar orasidagi noyob elementlar sonini topish. Bu turdagi muammolar uchun eng samarali va toza yechim bu noyob elementlarni avtomatik ravishda saqlaydigan ma'lumotlar tuzilmasidan foydalanishdir. C++ tilida `std::set` konteyneri aynan shu maqsadga xizmat qiladi. `std::set` ga element qo'shilganda, agar u element allaqachon setda mavjud bo'lsa, u qayta qo'shilmaydi va setning o'lchami o'zgarmaydi. Natijada, setda faqat noyob elementlar qoladi.

## Algoritm qadamlari
1.  Kirish ma'lumotlarini tez o'qish va chiqarish (Fast I/O) uchun standart kutubxonalar sozlamalarini o'rnatamiz.
2.  Uchta `a`, `b`, `c` butun sonlarni kirishdan o'qiymiz.
3.  `std::set<int>` turidagi `distinct_numbers` nomli bo'sh to'plam (set) yaratamiz. `set` — bu elementlarni tartiblangan holda saqlaydigan va faqat noyob (takrorlanmaydigan) elementlarga ruxsat beradigan ma'lumotlar tuzilmasi.
4.  `a` sonini `distinct_numbers` to'plamiga kiritamiz (`insert`).
5.  `b` sonini `distinct_numbers` to'plamiga kiritamiz.
6.  `c` sonini `distinct_numbers` to'plamiga kiritamiz.
7.  Uchta son kiritilgach, `distinct_numbers` to'plamida faqat noyob sonlar qoladi. To'plamning `size()` metodi orqali uning o'lchamini (ya'ni, noyob sonlar sonini) topamiz.
8.  Topilgan o'lchamni chiqishga chop etamiz.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(1) (Doimiy vaqt)
    *   Uchta sonni o'qish O(1) vaqt oladi.
    *   `std::set` ga element kiritish o'rtacha O(log N) vaqt oladi, bu yerda N — setdagi elementlar soni. Bizning holatimizda setga maksimal 3 ta element kiritiladi. Demak, har bir `insert` operatsiyasi O(log 3) vaqt oladi, bu esa amalda doimiy O(1) vaqtga teng.
    *   Setning o'lchamini topish (`size()`) O(1) vaqt oladi.
    *   Natijani chop etish O(1) vaqt oladi.
    *   Shunday qilib, umumiy vaqt murakkabligi O(1) ni tashkil etadi. Bu berilgan 1000 ms vaqt limitiga juda yaxshi mos keladi.

-   **Xotira murakkabligi**: O(1) (Doimiy xotira)
    *   `std::set` faqat uchta butun sonni saqlaydi (maksimal). Bu miqdor kirish ma'lumotlari hajmiga bog'liq emas, shuning uchun xotira sarfi doimiy bo'lib, O(1) ga teng. Bu berilgan 16 MB xotira limitiga juda yaxshi mos keladi.

-   **Nega shu murakkablik chegaraga sig'adi**: Masala bo'yicha kirish ma'lumotlarining hajmi juda kichik (faqat 3 ta son). Shuning uchun doimiy vaqt va xotira murakkabligiga ega bo'lgan bu yechim berilgan vaqt va xotira chegaralarida juda tez va samarali ishlaydi.

## Kod izohi

```cpp
#include <bits/stdc++.h>
```
Bu qator C++ ning deyarli barcha standart kutubxonalarini o'z ichiga oladi. `set` konteyneridan foydalanish uchun `set` sarlavhasini (`<set>`) kiritish kifoya edi, lekin `bits/stdc++.h` ko'pincha musobaqa dasturlashida qulaylik uchun ishlatiladi.

```cpp
using namespace std;
```
Bu qator `std` nomfazasidagi (namespace) barcha elementlarni (masalan, `cin`, `cout`, `set`) `std::` prefiksini ishlatmasdan to'g'ridan-to'g'ri ishlatishga imkon beradi.

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
```
Bu ikki qator C++ dasturlarida kirish-chiqish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi.
*   `ios_base::sync_with_stdio(false);` C++ ning standart I/O oqimlarini C tilining standart I/O oqimlari bilan sinxronizatsiyasini o'chiradi. Bu I/O operatsiyalarini tezlashtiradi.
*   `cin.tie(0);` `cin` (kirish oqimi) ni `cout` (chiqish oqimi) dan ajratadi. Odatiy holda, `cin` har safar ishlatilishidan oldin `cout` ni tozalaydi, bu esa sekinlashishga olib kelishi mumkin. Ajratish bu xatti-harakatni bekor qiladi.

```cpp
    int a, b, c;
    cin >> a >> b >> c;
```
Bu yerda `a`, `b`, `c` nomli uchta butun son turidagi o'zgaruvchilar e'lon qilingan va `cin` yordamida kirish faylidan ushbu uchta son o'qib olinadi.

```cpp
    set<int> distinct_numbers;
```
`distinct_numbers` nomli `std::set` obyekti yaratiladi. Bu `set` faqat butun sonlarni (`int`) saqlaydi va unga kiritilgan elementlarning faqat noyoblarini saqlab qoladi.

```cpp
    distinct_numbers.insert(a);
    distinct_numbers.insert(b);
    distinct_numbers.insert(c);
```
`insert()` metodi yordamida `a`, `b`, `c` sonlari `distinct_numbers` to'plamiga kiritiladi. Agar biror son allaqachon setda mavjud bo'lsa, `insert` operatsiyasi uni qayta qo'shmaydi va setning o'lchami o'zgarmaydi.

```cpp
    cout << distinct_numbers.size() << endl;
```
`distinct_numbers.size()` bu setdagi elementlarning (ya'ni, noyob sonlarning) umumiy sonini qaytaradi. Bu qiymat `cout` yordamida chiqishga chop etiladi. `endl` keyingi chiqishni yangi qatordan boshlash uchun qator oxiriga yangi qator belgisini qo'shadi.

```cpp
    return 0;
}
```
`main` funksiyasi 0 qiymatini qaytarishi dasturning muvaffaqiyatli yakunlanganligini bildiradi.

## Edge case lar va eslatmalar
*   **Manfiy sonlar**: Masala matnida sonlarning absolyut qiymati 1000 dan oshmasligi aytilgan, bu degani manfiy sonlar ham bo'lishi mumkin (masalan, -7). `std::set` butun sonlarni, shu jumladan manfiy sonlarni ham hech qanday muammosiz saqlay oladi.
*   **Bir xil sonlar**: Barcha sonlar bir xil bo'lishi mumkin (masalan, `1 1 1`). `std::set` o'zining noyob elementlar qoidasi tufayli faqat bitta `1` ni saqlaydi va natija `1` bo'ladi.
*   **Ikki xil sonlar**: Ikkita son bir xil bo'lib, uchinchisi farq qilishi mumkin (masalan, `1 1 2`). `std::set` `1` va `2` ni saqlaydi, natija `2` bo'ladi.
*   **Barcha sonlar turli**: Barcha uchta son turli bo'lishi mumkin (masalan, `-7 264 -584`). `std::set` barcha uchala sonni saqlaydi, natija `3` bo'ladi.

`std::set` dan foydalanish ushbu barcha holatlarni avtomatik tarzda hal qiladi va qo'shimcha shartli ifodalarni (if-else) yozish zaruratini yo'q qiladi, bu esa kodni juda sodda va tushunarli qiladi.
