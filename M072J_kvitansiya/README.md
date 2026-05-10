# M072J — Kvitansiya

## Masala haqida
Bu masala butun son ko'rinishidagi pul miqdorini odamlar o'qishi uchun qulay formatga o'tkazishni talab qiladi. Ya'ni, katta sonlarni har uch xonali guruhga bo'lib, ular orasiga bo'sh joy qo'yish va oxiriga ",00" ni qo'shish kerak. Misol uchun, `10000` soni `10 000,00` ko'rinishida chop etilishi lozim. Kiruvchi son 0 dan 10^15 gacha bo'lishi mumkin.

## Yondashuv (g'oya)
Masalani yechishning asosiy g'oyasi - berilgan butun sonni satr (string) ko'rinishiga o'tkazish va keyin bu satr bo'ylab harakatlanib, kerakli joylarga bo'sh joy (separator) qo'yishdir. Sonlarni uch xonali guruhlarga bo'lish o'ng tomondan boshlanadi. Bu degani, har bir raqamni chop etishdan oldin, undan keyin qancha raqam qolganini hisoblash va agar bu qolgan raqamlar soni 3 ga karrali bo'lsa (va bu birinchi raqam bo'lmasa), bo'sh joy qo'yish kerak.

## Algoritm qadamlari
1.  **Kirish ma'lumotini o'qish**: `long long` turidagi `X` butun sonini kirish oqimidan o'qib oling. `long long` tipi `10^15` gacha bo'lgan qiymatlarni saqlash uchun yetarli.
2.  **Sonni satrga o'tkazish**: `std::to_string(X)` funksiyasi yordamida `X` sonini `std::string` turiga o'tkazing. Bu bizga sonning raqamlariga alohida-alohida kirish imkonini beradi.
3.  **Satr uzunligini aniqlash**: `len = s.length()` yordamida hosil bo'lgan satrning uzunligini (raqamlar sonini) aniqlang.
4.  **Satr bo'ylab takrorlash**: Satrning birinchi raqamidan boshlab oxirgisigacha (ya'ni `i` indeks 0 dan `len - 1` gacha) for siklida har bir raqamni ko'rib chiqing.
5.  **Bo'sh joy qo'yish shartini tekshirish**: Har bir `s[i]` raqamini chop etishdan oldin, quyidagi ikki shartni tekshiring:
    *   `i > 0`: Joriy raqam birinchi raqam emasligiga ishonch hosil qiling, chunki birinchi raqamdan oldin bo'sh joy qo'yilmaydi.
    *   `(len - i) % 3 == 0`: Joriy raqamdan keyin qolgan raqamlar soni (joriy raqamni ham hisobga olgan holda) 3 ga karrali bo'lishi kerak. Misol uchun, `1234567` soni uchun, agar `i=1` bo'lsa (`'2'` raqami), undan keyin `234567` (6 ta raqam) qolgan. 6 soni 3 ga karrali, demak `1` dan keyin bo'sh joy qo'yiladi. Bu shart joriy raqam yangi uch xonali guruhning boshi ekanligini bildiradi.
6.  **Raqamni chop etish**: Yuqoridagi shartlar bajarilsa, avval bo'sh joy (`' '`), so'ngra `s[i]` raqamini chop eting.
7.  **Oxirgi qo'shimchani chop etish**: For sikli tugagach, masalada talab qilinganidek, sonning oxiriga `",00"` va yangi qator (`\n`) belgisini chop eting.

## Murakkablik tahlili
-   **Vaqt**: `O(L)`, bu yerda `L` kiruvchi `X` sonining raqamlari soni. `long long` sonini `std::string`ga o'tkazish `O(L)` vaqt talab qiladi. Keyin, hosil bo'lgan satr bo'ylab bitta sikl (loop) yuguriladi, bu ham `O(L)` vaqt oladi. `X` maksimal `10^15` bo'lishi mumkin, bu esa `L` ning maksimal qiymati taxminan 16-17 raqam bo'lishini bildiradi. Shunday qilib, algoritm juda tez ishlaydi.
-   **Xotira**: `O(L)`, bu yerda `L` kiruvchi `X` sonining raqamlari soni. Yagona sezilarli xotira sarfi `X` sonini `std::string` ko'rinishida saqlashga ketadi. `L` kichik bo'lganligi sababli (maksimal 16-17 belgili satr), xotira sarfi juda kam va `32 MB` xotira limitiga bemalol sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi, shu jumladan <string> va <iostream>

int main() {
    // Kirish/chiqish operatsiyalarini tezlashtirish uchun standart optimizatsiyalar.
    // std::ios_base::sync_with_stdio(false) C++ streamlarini C standart I/O bilan sinxronizatsiyasini o'chiradi.
    // std::cin.tie(0) esa std::cin va std::cout o'rtasidagi bog'liqlikni bekor qiladi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long x; // Katta butun sonni saqlash uchun long long tipidan foydalaniladi.
    std::cin >> x; // To'lov miqdorini o'qish.

    std::string s = std::to_string(x); // Butun sonni satrga aylantirish.
    int len = s.length(); // Satrning uzunligini (raqamlar sonini) olish.

    // Satrning har bir raqami bo'ylab takrorlash.
    for (int i = 0; i < len; ++i) {
        // Bo'sh joy qo'yish sharti:
        // 1. i > 0: Bu birinchi raqam emasligini tekshiradi (chunki sonning boshida bo'sh joy bo'lmaydi).
        // 2. (len - i) % 3 == 0: Joriy raqamdan (s[i]) keyin qolgan raqamlar soni (o'zini ham qo'shib hisoblaganda) 3 ga karrali bo'lsa.
        // Bu shart, agar biz 3 xonali guruhni boshlamoqchi bo'lsak, bo'sh joy qo'yish kerakligini bildiradi.
        if (i > 0 && (len - i) % 3 == 0) {
            std::cout << ' '; // Bo'sh joyni chop etish.
        }
        std::cout << s[i]; // Joriy raqamni chop etish.
    }

    std::cout << ",00\n"; // Talab qilingan ",00" qo'shimchasini va yangi qatorni chop etish.

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildirish.
}
```

## Edge case lar va eslatmalar
*   **Minimal qiymat (X = 0)**: Agar `X` nol bo'lsa, `std::to_string(0)` "0" satrini hosil qiladi. `len=1`. For siklida `i=0` bo'ladi, `i > 0` sharti bajarilmaydi, shuning uchun bo'sh joy qo'yilmaydi va "0" chop etiladi. Natijada `0,00` chiqadi, bu to'g'ri.
*   **Qisqa sonlar (masalan, 1, 12, 123)**: Bu sonlar uchun `len` qiymati 1, 2 yoki 3 bo'ladi. `(len - i) % 3 == 0` sharti hech qachon `i > 0` bilan birga to'g'ri bo'lmaydi, chunki bu sonlarda 3 xonali guruhlarga ajratish uchun bo'sh joy kerak emas. Natijada, sonning o'zi va `,00` chop etiladi (masalan, `1,00`, `12,00`, `123,00`), bu ham to'g'ri.
*   **Maksimal qiymat (10^15)**: Bu 16 xonali son. `long long` tipi uni bemalol saqlay oladi. Satrga o'tkazish va sikl bu uzunlikdagi sonni ham to'g'ri qayta ishlaydi va spaces to'g'ri joylarga qo'yiladi (masalan, `1 000 000 000 000 000,00`).
*   **Vaqt va xotira samaradorligi**: Yondashuv `O(L)` vaqt va `O(L)` xotira murakkabligiga ega bo'lib, `L` (raqamlar soni) juda kichik bo'lganligi sababli, bu yechim berilgan vaqt va xotira chegaralariga bemalol mos keladi.
