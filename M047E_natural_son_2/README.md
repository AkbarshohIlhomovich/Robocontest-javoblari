---
title: "M047E — Natural son #2 | Robocontest.uz Yechimi"
description: "Robocontest.uz M047E (Natural son #2) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M047E, Natural son #2 yechimi, robocontest Natural son #2, M047E c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# M047E — Natural son #2

## Masala haqida
Bu masala sizdan 1 dan 1000 gacha bo'lgan natural sonni o'zbek lotin yozuvida so'z bilan ifodalashni talab qiladi. Kirish sifatida bitta butun son `N` beriladi va chiqishda uning so'z bilan yozilgan shakli chop etilishi kerak. Masalan, 595 uchun "besh yuz to'qson besh" chiqishi kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi — berilgan sonni raqamlarga yoki xona birliklariga (birlik, o'nlik, yuzlik) ajratish va har bir qismni oldindan tayyorlangan so'zlar ro'yxatidan foydalanib yozish. Bu yondashuv juda kichik diapazondagi (1-1000) sonlar uchun juda samarali hisoblanadi. Sonni 1000, 100-999 va 1-99 kabi asosiy diapazonlarga ajratib, har birini alohida shartlar bilan qayta ishlaymiz. Ikki xonali sonlarni (1-99) yozish uchun yordamchi funksiya yaratish kod takrorlanishining oldini oladi.

## Algoritm qadamlari
1.  **So'zlar lug'atini tayyorlash:**
    *   `ones` nomli `string` massivi (array) e'lon qilinadi. Bu massiv 0 dan 9 gacha bo'lgan raqamlarning o'zbekcha nomlarini saqlaydi (0-bo'sh, 1-"bir", ..., 9-"to'qqiz").
    *   `tens` nomli `string` massivi e'lon qilinadi. Bu massiv 0 dan 90 gacha bo'lgan o'nliklarning o'zbekcha nomlarini saqlaydi (0-bo'sh, 10-"o'n", ..., 90-"to'qson").
2.  **`spellTwoDigits` yordamchi funksiyasini yaratish:**
    *   Bu funksiya 0 dan 99 gacha bo'lgan butun sonni qabul qiladi va uning o'zbekcha yozuvini `string` sifatida qaytaradi.
    *   Agar son 0 bo'lsa, bo'sh satr qaytariladi.
    *   Agar son 10 dan kichik bo'lsa (birliklar), `ones` massividan to'g'ri so'z qaytariladi.
    *   Agar son 10 ga karrali bo'lsa (o'nliklar, masalan 20, 30), `tens` massividan to'g'ri so'z qaytariladi (`num / 10` indeks sifatida ishlatiladi).
    *   Agar son ikki xonali va 10 ga karrali bo'lmasa (masalan, 25), `tens` massividan o'nlik qismi (`num / 10`) va `ones` massividan birlik qismi (`num % 10`) olinib, ular orasiga bo'sh joy qo'shib birlashtiriladi.
3.  **Asosiy (`main`) funksiya:**
    *   Kirish/chiqish oqimini tezlashtirish uchun standart optimizatsiyalar (`ios_base::sync_with_stdio(false); cin.tie(0);`) ishlatiladi.
    *   `n` soni kiritiladi.
    *   **Maxsus holat: `n = 1000`**
        *   Agar `n` aynan 1000 ga teng bo'lsa, "bir ming" yozuvi chop etiladi.
    *   **Ikki xonali sonlar: `n < 100`**
        *   Agar `n` 100 dan kichik bo'lsa, `spellTwoDigits(n)` funksiyasi chaqiriladi va uning natijasi chop etiladi.
    *   **Uch xonali sonlar: `n >= 100` (ya'ni 100 dan 999 gacha)**
        *   Sonning yuzlik raqami topiladi: `hundreds_digit = n / 100`.
        *   Sonning qolgan qismi (oxirgi ikki raqam) topiladi: `remainder = n % 100`.
        *   `ones` massividan `hundreds_digit`ga mos keluvchi so'z ("bir", "ikki" va h.k.) chop etiladi, keyin " yuz" so'zi qo'shiladi.
        *   Agar `remainder` (qolgan qism) 0 dan katta bo'lsa, ya'ni sonning oxirgi ikki raqami 00 dan farqli bo'lsa:
            *   Chop etilgan yuzlik qismidan keyin bo'sh joy qo'yiladi.
            *   `spellTwoDigits(remainder)` funksiyasi chaqiriladi va uning natijasi chop etiladi.
        *   Natija yakunida yangi qatorga o'tish belgisi (`\n`) chop etiladi.

## Murakkablik tahlili
-   **Vaqt**: O(1) (Doimiy vaqt murakkabligi)
    -   Sababi: Kiritiladigan `N` sonining diapazoni (1 dan 1000 gacha) juda cheklangan. Algoritm doimiy miqdordagi amallarni bajaradi: massivlarga murojaat qilish, arifmetik amallar (bo'lish, qoldiq olish), string (satr) birlashtirish. Bularning barchasi sonning qiymati o'zgargani bilan murakkablashmaydi, chunki sonning xonalar soni (eng ko'pi 4 xona) va so'zlarning uzunligi chegaralangan. Shuning uchun, algoritm ishlash vaqti doimiy hisoblanadi.
-   **Xotira**: O(1) (Doimiy xotira murakkabligi)
    -   Sababi: Dasturda ishlatiladigan `ones` va `tens` string massivlari doimiy (fixed) o'lchamga ega. Kiritiladigan `N` soni qanchalik katta bo'lmasin (belgilangan chegara ichida), dasturning xotira talabi o'zgarmaydi. Qo'shimcha o'zgaruvchilar ham doimiy xotira egallaydi.
-   Yuqoridagi murakkablik chegaraga to'liq sig'adi, chunki bu eng optimal holat bo'lib, juda katta hajmdagi ma'lumotlar bilan ishlashga mo'ljallanmagan, balki aniq va cheklangan sonlar diapazoni uchun mo'ljallangan.

## Kod izohi

### `ones` va `tens` string massivlari
```cpp
const string ones[] = {
    "", "bir", "ikki", "uch", "to'rt", "besh", "olti", "yetti", "sakkiz", "to'qqiz"
};

const string tens[] = {
    "", "o'n", "yigirma", "o'ttiz", "qirq", "ellik", "oltmish", "yetmish", "sakson", "to'qson"
};
```
Bu massivlar raqamlarning va o'nliklarning so'z bilan yozilishini saqlash uchun ishlatiladi. `ones` massivi indeks 0 dan 9 gacha bo'lgan birliklarni, `tens` massivi esa indeks 0 dan 9 gacha bo'lgan o'nliklarni (masalan, `tens[1]` "o'n", `tens[2]` "yigirma") saqlaydi. Massivlarning 0-indeksida bo'sh satr ("") mavjud bo'lib, bu ba'zi holatlarda (masalan, 100, 200 kabi yuzliklar oxirida birlik yoki o'nlik qismi nol bo'lganida) ortiqcha bo'sh joylar yoki so'zlarni chop etishni oldini olishga yordam beradi.

### `spellTwoDigits` funksiyasi
```cpp
string spellTwoDigits(int num) {
    if (num == 0) {
        return "";
    }
    if (num < 10) {
        return ones[num];
    }
    if (num % 10 == 0) {
        return tens[num / 10];
    }
    return tens[num / 10] + " " + ones[num % 10];
}
```
Bu yordamchi funksiya 0 dan 99 gacha bo'lgan sonlarni so'z bilan yozadi.
*   `if (num == 0)`: Agar son 0 bo'lsa, hech narsa chop etmaslik uchun bo'sh satr qaytaradi. Bu, masalan, "besh yuz nol" emas, "besh yuz" deb yozish uchun muhim.
*   `if (num < 10)`: Agar son bir xonali bo'lsa, `ones` massividan tegishli so'zni oladi.
*   `if (num % 10 == 0)`: Agar son 10 ga karrali bo'lsa (masalan, 20, 30), `tens` massividan tegishli o'nlik so'zni oladi. `num / 10` sonning o'nlik raqamini beradi.
*   `return tens[num / 10] + " " + ones[num % 10];`: Agar son ikki xonali va 10 ga karrali bo'lmasa (masalan, 59), o'nlik qismini (`num / 10` orqali) va birlik qismini (`num % 10` orqali) `tens` va `ones` massivlaridan olib, ularni bo'sh joy bilan birlashtiradi.

### `main` funksiyasi
```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1000) {
        cout << "bir ming\n";
    } else if (n < 100) { // Sonlar 1 dan 99 gacha
        cout << spellTwoDigits(n) << "\n";
    } else { // Sonlar 100 dan 999 gacha
        int hundreds_digit = n / 100;
        int remainder = n % 100;

        cout << ones[hundreds_digit] << " yuz";

        if (remainder > 0) {
            cout << " " << spellTwoDigits(remainder);
        }
        cout << "\n";
    }

    return 0;
}
```
`main` funksiyasi sonni turli diapazonlarga ajratib ishlaydi:
*   `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu qatorlar C++ standart kirish/chiqish operatsiyalarini (cin/cout) tezlashtiradi, ayniqsa katta hajmdagi ma'lumotlar bilan ishlashda foydali. Bu masalada unchalik muhim bo'lmasada, yaxshi odat hisoblanadi.
*   `if (n == 1000)`: 1000 soni uchun maxsus holat. Uni to'g'ridan-to'g'ri "bir ming" deb chop etadi.
*   `else if (n < 100)`: Agar `n` 1 dan 99 gacha bo'lsa, buni yozish uchun `spellTwoDigits` funksiyasidan foydalaniladi.
*   `else` (ya'ni `n` 100 dan 999 gacha):
    *   `hundreds_digit = n / 100;`: Sonning yuzlik raqamini ajratib oladi (masalan, 595 uchun 5).
    *   `remainder = n % 100;`: Sonning yuzlikdan keyingi qismini ajratib oladi (masalan, 595 uchun 95).
    *   `cout << ones[hundreds_digit] << " yuz";`: Yuzlik raqamini (`ones` massividan) va " yuz" so'zini chop etadi (masalan, "besh yuz").
    *   `if (remainder > 0)`: Agar `remainder` noldan katta bo'lsa, ya'ni sonning oxirgi ikki raqami noldan farqli bo'lsa (masalan, 500 emas, 595), unda yuzlik qismidan keyin bo'sh joy qoldirib, qolgan qism (`remainder`) `spellTwoDigits` yordamida yoziladi. Bu "besh yuz to'qson besh" yoki "ikki yuz ellik" kabi ifodalarni beradi. "Besh yuz" kabi holatlarda `remainder` 0 bo'ladi va bu blok ishga tushmaydi, natijada "besh yuz" to'g'ri chop etiladi.

## Edge case lar va eslatmalar
*   **1000 soni**: Masalaning sharti bo'yicha `N` 1000 dan oshmaydi. 1000 soni algoritmda alohida holat sifatida ko'rib chiqilgan ("bir ming").
*   **100 ga karrali sonlar (100, 200, ..., 900)**: Misol uchun, `n = 200` bo'lsa, `hundreds_digit = 2`, `remainder = 0`. `ones[2]` ("ikki") va " yuz" chop etiladi ("ikki yuz"). `remainder > 0` sharti qanoatlantirilmaydi, shuning uchun ortiqcha so'zlar qo'shilmaydi.
*   **O'nliklarsiz sonlar (101, 203, ...)**: Misol uchun, `n = 101` bo'lsa, `hundreds_digit = 1`, `remainder = 1`. `ones[1]` ("bir") va " yuz" chop etiladi ("bir yuz"). Keyin `remainder > 0` bo'lgani uchun, `spellTwoDigits(1)` ("bir") chop etiladi. Natija: "bir yuz bir".
*   **To'g'ri bo'sh joylar**: `spellTwoDigits` funksiyasining 0 uchun bo'sh satr qaytarishi va `main` funksiyasidagi `if (remainder > 0)` sharti, shuningdek, `tens` va `ones` massivlarining 0-indeksida bo'sh satr bo'lishi ortiqcha bo'sh joylarni yoki "besh yuz nol" kabi noto'g'ri yozuvlarni oldini oladi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M047E) platformasidagi **M047E** raqamli **Natural son #2** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M047E>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M047E, Natural son #2 yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
