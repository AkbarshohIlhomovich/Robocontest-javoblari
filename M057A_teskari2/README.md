---
title: "M057A — Teskari^2 | Robocontest.uz Yechimi"
description: "Robocontest.uz M057A (Teskari^2) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Oson. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M057A, Teskari^2 yechimi, robocontest Teskari^2, M057A c++ kod, oson, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M057A_teskari2/
lang: uz
---

# M057A — Teskari^2

## Masala haqida
Ushbu masalada bizga butun son beriladi va uning "yaxshi son" ekanligini aniqlash so'raladi. Yaxshi son deganda, agar sonni ikki marta teskari tartibda joylashtirganda yana o'ziga teng bo'lsa, shunday son tushuniladi. Misol uchun, `123` soni yaxshi son, chunki `teskari(123) → 321`, `teskari(321) → 123`. Lekin `3400` yaxshi son emas, chunki `teskari(3400) = 43`, `teskari(43) → 34`, va `3400 != 34`.

## Yondashuv (g'oya)
Masalaning kalit qismi sonni teskariga aylantirish (reverse) operatsiyasining xususiyatini tushunishdir. Odatda, sonni teskariga aylantirishda uning oxiridagi nollar (trailing zeros) yo'qolib ketadi. Masalan, `teskari(3400) = 43`. Ushbu xususiyat yechimning asosiy g'oyasini tashkil etadi.

Agar son `N` ning oxirida nol bo'lmasa, uni teskariga aylantirganimizda raqamlari tartibi o'zgaradi, lekin hech qanday raqam yo'qolmaydi. Ikkinchi marta teskariga aylantirganimizda esa asl son `N` qaytadi.
Agar son `N` ning oxirida nol bo'lsa (va son 0 dan katta bo'lsa), birinchi teskariga aylantirishda bu nollar yo'qolib ketadi. Ikkinchi marta teskariga aylantirganimizda ham bu nollar qayta tiklanmaydi. Natijada, `teskari(teskari(N))` asl `N` dan kichikroq son bo'ladi va unga teng bo'lmaydi.
Alohida holat — `N = 0`. `teskari(0) = 0` va `teskari(0) = 0`, demak `0` yaxshi son hisoblanadi.

Shunday qilib, algoritm quyidagi mantiqqa asoslanadi:
1. Agar son `0` ga teng bo'lsa, u yaxshi son.
2. Agar son `0` ga teng bo'lmasa va uning oxirida nol bo'lsa (`N % 10 == 0`), u yaxshi son emas.
3. Agar son `0` ga teng bo'lmasa va uning oxirida nol bo'lmasa (`N % 10 != 0`), u yaxshi son.

## Algoritm qadamlari
1. Kiruvchi `n` sonini o'qing.
2. Agar `n` soni `0` ga teng bo'lsa, `1` ni chop eting (chunki 0 yaxshi son).
3. Aks holda (ya'ni, `n != 0` bo'lsa):
    a. Agar `n` sonining oxirgi raqami `0` bo'lsa (`n % 10 == 0` sharti orqali tekshiriladi), `0` ni chop eting (chunki teskari operatsiyada oxirgi nollar yo'qoladi va son o'ziga qaytmaydi).
    b. Aks holda (ya'ni, `n % 10 != 0` bo'lsa), `1` ni chop eting (chunki sonning oxirida nol yo'q bo'lsa, teskari operatsiyada raqamlar yo'qolmaydi va son o'ziga qaytadi).

## Murakkablik tahlili
- **Vaqt murakkabligi**: O(1) (Doimiy vaqt).
    Algoritm bir nechta arifmetik amal (taqqoslash, qoldiqni hisoblash) va shartli tekshiruvlardan iborat. Sonning kattaligidan qat'i nazar, bu amallar doimiy vaqtda bajariladi.
- **Xotira murakkabligi**: O(1) (Doimiy xotira).
    Algoritm faqat bir nechta o'zgaruvchini saqlash uchun doimiy miqdordagi xotiradan foydalanadi.

Bu murakkablik chegaralari berilgan `N` ning `10000` gacha bo'lgan qiymatlari va 1000 ms vaqt, 32 MB xotira limitlariga to'liq mos keladi va juda samarali hisoblanadi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarning barchasini o'z ichiga oladi. Odatda competitive programmingda tezlik uchun ishlatiladi.

using namespace std; // Standart nomfazodan foydalanish.

int main() {
    // Kiritish/chiqarish operatsiyalarini tezlashtirish uchun ishlatiladi.
    // sync_with_stdio(false) C++ streamlarini C standart I/O bilan sinxronizatsiyani o'chiradi.
    // cin.tie(0) cin dan keyin cout flush bo'lishini oldini oladi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; // Kiruvchi sonni saqlash uchun 'n' butun son o'zgaruvchisini e'lon qilish.
    cin >> n; // 'n' sonini kiritish.

    if (n == 0) { // Birinchi holat: agar 'n' nolga teng bo'lsa.
        cout << 1 << endl; // Nol yaxshi son bo'lgani uchun 1 ni chop etamiz.
    } else if (n % 10 == 0) { // Ikkinchi holat: agar 'n' noldan katta bo'lsa va 10 ga qoldiqsiz bo'linsa (ya'ni, oxirgi raqami 0 bo'lsa).
        cout << 0 << endl; // Teskari operatsiyada oxirgi nollar yo'qoladi, shuning uchun 0 ni chop etamiz.
    } else { // Uchinchi holat: agar 'n' noldan katta bo'lsa va 10 ga qoldiqsiz bo'linmasa (ya'ni, oxirgi raqami 0 bo'lmasa).
        cout << 1 << endl; // Oxirgi nollar yo'qolmasligi sababli, son yaxshi son bo'ladi, 1 ni chop etamiz.
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
- **Nol soni (`n = 0`)**: Nol soni o'ziga xos holat hisoblanadi. `teskari(0)` baribir `0` bo'ladi, shuning uchun `0` yaxshi son. Bu holat kodda alohida `if (n == 0)` sharti bilan qoplanadi.
- **`N` ning chegarasi**: Masala shartida `N` ning `10000` dan oshmasligi ko'rsatilgan. Bu `int` turiga bemalol sig'adi, shu sababli ma'lumot turlari bilan bog'liq muammolar yo'q.
- **`reverse` funksiyasining ta'siri**: Bu masalaning eng muhim jihati sonni teskariga aylantirish funksiyasi qanday ishlashini bilishdir. Aksariyat programmalash tillarida yoki raqamni stringga o'tkazib teskariga aylantirganda, keyin uni qayta int/long ga o'tkazganda oxiridagi nollar yo'qoladi (masalan, "3400" -> "0043" (string) -> 43 (int)). Aynan shu xususiyat yechimning samarali bo'lishini ta'minlaydi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M057A) platformasidagi **M057A** raqamli **Teskari^2** masalasi. U **Oson** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M057A>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M057A, Teskari^2 yechimi, robocontest masalalari, c++17, olimpiada yechimi, oson, dasturlash uzbek, competitive programming O'zbekiston.</sub>
