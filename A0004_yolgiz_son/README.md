# A0004 — Yolg'iz son

## Masala haqida
Sizga `N` ta butun sondan iborat to'plam berilgan bo'lib, uning ichida bitta sondan tashqari barcha sonlarning jufti (ya'ni, xuddi shu son yana bir marta) mavjud. Sizning vazifangiz — to'plamdagi yagona jufti bo'lmagan, ya'ni "yolg'iz" sonni topish va uni chiqarish. Masalan, `[1, 2, 3, 4, 3, 2, 1]` to'plamida `4` soni yolg'izdir.

## Yondashuv (g'oya)
Bu masalani yechishning asosiy g'oyasi **bitwise XOR** (bitli mantiqiy XOR) operatorining xususiyatlaridan foydalanishdir. XOR operatorining quyidagi muhim xususiyatlari mavjud:
1.  **O'zgaruvchanlik (Commutativity)**: `A ^ B = B ^ A`
2.  **Birikma (Associativity)**: `(A ^ B) ^ C = A ^ (B ^ C)`
3.  **Nol bilan XOR**: `X ^ 0 = X` (Har qanday sonni `0` bilan XORlaganda sonning o'zi qaytadi)
4.  **O'zi bilan XOR**: `X ^ X = 0` (Har qanday sonni o'zi bilan XORlaganda `0` qaytadi)

Agar biz to'plamdagi barcha sonlarni ketma-ket bir-biri bilan XOR qilsak, jufti bor bo'lgan sonlar bir-birini bekor qiladi (`X ^ X = 0`). Natijada faqat jufti bo'lmagan yolg'iz son qoladi, chunki `0` bilan XORlangan har qanday son o'zini beradi (`0 ^ Y = Y`).

Masalan, `[1, 2, 3, 4, 3, 2, 1]` to'plami uchun:
`0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 3 ^ 2 ^ 1`
XOR operatorining o'zgaruvchanlik va birikma xususiyatlari tufayli biz buni quyidagicha qayta guruhlashimiz mumkin:
`(1 ^ 1) ^ (2 ^ 2) ^ (3 ^ 3) ^ 4`
`0 ^ 0 ^ 0 ^ 4`
`4`
Shunday qilib, yolg'iz son `4` ni topamiz.

## Algoritm qadamlari
1.  **Boshlang'ich sozlash**: C++ standart kirish/chiqish oqimlarini tezlashtirish uchun `ios_base::sync_with_stdio(false);` va `cin.tie(0);` buyruqlarini ishlatiladi.
2.  **`N` ni o'qish**: To'plamdagi elementlar soni `N` ni kirishdan o'qib olinadi.
3.  **Natijaviy o'zgaruvchini ishga tushirish**: `lonely_number` nomli butun sonli o'zgaruvchi `0` qiymati bilan e'lon qilinadi. Bu o'zgaruvchi XOR operatsiyalari natijasini saqlaydi.
4.  **Elementlarni qayta ishlash**: `0` dan `N-1` gacha bo'lgan tsikl (loop) yordamida:
    *   Har safar to'plamdan bitta `num` soni o'qib olinadi.
    *   O'qilgan `num` soni `lonely_number` o'zgaruvchisi bilan XORlanadi (`lonely_number ^= num;`).
5.  **Natijani chiqarish**: Tsikl tugagach, `lonely_number` o'zgaruvchisida qolgan qiymat to'plamdagi yolg'iz son bo'ladi. Shu qiymat konsolga chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(N)`
    *   Algoritm massivdagi har bir elementni bir marta o'qiydi va u bilan bitta bitwise XOR operatsiyasini bajaradi. Bu `N` ta operatsiyani talab qiladi. Shuning uchun, vaqt murakkabligi massiv elementlari soni `N` ga to'g'ri proportsionaldir.
-   **Xotira murakkabligi**: `O(1)`
    *   Algoritm faqat bir nechta o'zgaruvchini ( `n`, `lonely_number`, `num` ) saqlash uchun doimiy miqdorda xotiradan foydalanadi. Massivning barcha elementlarini xotirada saqlashga hojat yo'q. Shuning uchun, xotira murakkabligi `N` ga bog'liq emas.
-   **Nega shu murakkablik chegaraga sig'adi**:
    *   Masala shartlariga ko'ra `N < 100` va elementlar qiymati `[0, 100]` oralig'ida.
    *   `O(N)` vaqt murakkabligi `N < 100` uchun juda samarali hisoblanadi (taxminan 100 ta operatsiya). Berilgan 1000 ms vaqt limiti uchun bu juda tez bajariladi (kod 1 ms da ishlagan).
    *   `O(1)` xotira murakkabligi berilgan 16 MB xotira limiti uchun ham juda samarali va deyarli xotira ishlatmaydi (kod 0 KB xotira ishlatgan).

## Kod izohi
```cpp
#include <bits/stdc++.h> // Ko'p standart kutubxonalarni o'z ichiga olgan umumiy sarlavha

using namespace std; // std nomlar fazosidan foydalanishni osonlashtiradi

int main() {
    // Tezkor kirish/chiqish uchun sozlamalar.
    // Bu C++ iostream funksiyalarini C standart I/O funksiyalaridan ajratadi
    // va cin/cout ni bufferlashni o'chiradi, bu katta hajmdagi ma'lumotlar bilan ishlashda tezlikni oshiradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; // Elementlar sonini saqlash uchun o'zgaruvchi
    cin >> n; // N qiymatini o'qish

    int lonely_number = 0; // Yolg'iz sonni saqlaydigan o'zgaruvchi.
                           // Boshlang'ich qiymat 0, chunki X ^ 0 = X
    
    // N ta elementni o'qib chiqish uchun tsikl
    for (int i = 0; i < n; ++i) {
        int num; // Joriy elementni saqlash uchun o'zgaruvchi
        cin >> num; // Elementni o'qish
        lonely_number ^= num; // O'qilgan elementni lonely_number bilan XORlash
                              // Har bir juft son bir-birini bekor qiladi (X ^ X = 0)
                              // Yolg'iz son oxirida lonely_numberda qoladi.
    }

    cout << lonely_number << endl; // Topilgan yolg'iz sonni chop etish

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi
}

```

## Edge case lar va eslatmalar
*   **`N=1` holati**: Agar kirish `N=1` bo'lsa, tsikl bir marta ishlaydi. Masalan, `lonely_number = 0 ^ 5 = 5` bo'ladi. Natija to'g'ri, chunki yagona son o'zi yolg'izdir.
*   **Sonlarning qiymati `0` dan `100` gacha**: Bu chegaralar XOR operatsiyasining ishlashiga ta'sir qilmaydi, chunki XOR butun sonlar ustida samarali ishlaydi va kattaroq qiymatlarni ham xatosiz ishlashga qodir. `0` ham XOR operatsiyasida to'g'ri ishtirok etadi (`X ^ 0 = X`).
*   **Xotira va vaqt cheklovlari**: Berilgan `N < 100` cheklovlari va algoritmning `O(N)` vaqt va `O(1)` xotira murakkabligi tufayli masala cheklovlaridan ancha past ko'rsatkichlar bilan yechim AC (Accepted) oladi.
*   **Texnik atama "bitwise XOR"**: Bu ikki butun sonning ikkilik (binary) ko'rinishidagi tegishli bitlarini taqqoslash orqali yangi butun son hosil qiluvchi mantiqiy operatsiyadir. Agar ikkita bit har xil bo'lsa (0 va 1 yoki 1 va 0), natija 1 bo'ladi; agar bir xil bo'lsa (0 va 0 yoki 1 va 1), natija 0 bo'ladi.
