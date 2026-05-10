---
title: "M058B — Magnit raqamlar | Robocontest.uz Yechimi"
description: "Robocontest.uz M058B (Magnit raqamlar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M058B, Magnit raqamlar yechimi, robocontest Magnit raqamlar, M058B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# M058B — Magnit raqamlar

## Masala haqida
Nurmuhammad doskaga N sonini magnitli raqamlar yordamida yozadi. U do'konga ketganida, Dilnura bu sonning raqamlari o'rnini almashtirib, boshqa son hosil qila oladimi yoki yo'qmi, aniqlash kerak. Agar N sonining raqamlari o'rnini almashtirib boshqa son hosil qilish mumkin bo'lsa, "YES", aks holda "NO" chiqarish talab etiladi. N soni 1 dan 99 gacha bo'lgan butun son.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi N sonining raqamlari soni va ularning o'zaro teng yoki farqli ekanligini tahlil qilishga asoslanadi. Agar sonning raqamlari joyini almashtirganda asl sondan farqli boshqa son hosil bo'lishi kerak bo'lsa, bu faqat ikki shart bajarilgandagina mumkin:
1.  Son birdan ortiq raqamdan iborat bo'lishi kerak.
2.  Sonning raqamlari o'zaro farqli bo'lishi kerak.

Shu sababli, biz N sonining bir xonali yoki ikki xonali ekanligini, va agar ikki xonali bo'lsa, uning raqamlari bir xil yoki har xil ekanligini tekshiramiz.

## Algoritm qadamlari
1.  Kiritilgan `N` butun sonini o'qing.
2.  Agar `N` soni 10 dan kichik bo'lsa (ya'ni, u bir xonali son bo'lsa, 1 dan 9 gacha), uning faqat bitta raqami bor. Bu holatda raqamlar o'rnini almashtirib boshqa son hosil qilishning iloji yo'q. Dastur "NO" deb chiqarsin va tugasin.
3.  Agar `N` soni 10 dan katta yoki teng bo'lsa (ya'ni, u ikki xonali son bo'lsa, 10 dan 99 gacha):
    *   `N` sonining birinchi raqamini (o'nliklar xonasidagi raqamni) butun bo'lish (`/`) amali yordamida toping: `d1 = N / 10`.
    *   `N` sonining ikkinchi raqamini (birliklar xonasidagi raqamni) qoldiq (`%`) amali yordamida toping: `d2 = N % 10`.
    *   Agar `d1` va `d2` raqamlari bir-biriga teng bo'lsa (masalan, N=33 bo'lsa, d1=3, d2=3), raqamlar o'rnini almashtirganimizda ham xuddi shu son hosil bo'ladi, boshqa son emas. Bu holatda "NO" deb chiqaring.
    *   Agar `d1` va `d2` raqamlari bir-biriga teng bo'lmasa (masalan, N=54 bo'lsa, d1=5, d2=4), raqamlar o'rnini almashtirib boshqa son hosil qilish mumkin (masalan, 45). Bu holatda "YES" deb chiqaring.

## Murakkablik tahlili
-   **Vaqt**: O(1)
    *   Algoritm doimiy (constant) miqdordagi arifmetik amallar (bo'lish, qoldiq olish) va taqqoslashlarni bajaradi. Kiruvchi `N` sonining kattaligidan (1 dan 99 gacha) qat'i nazar, bajariladigan qadamlar soni o'zgarmaydi. Shu sababli, vaqt murakkabligi O(1) ga teng.
-   **Xotira**: O(1)
    *   Algoritm faqat bir nechta o'zgaruvchini (`n`, `d1`, `d2`) saqlash uchun doimiy miqdordagi xotiradan foydalanadi. Bu o'zgaruvchilarning xotira talabi `N` ning qiymatiga bog'liq emas. Shu sababli, xotira murakkabligi O(1) ga teng.
-   **Nega shu murakkablik chegaraga sig'adi**: Berilgan vaqt (1000 ms) va xotira (16 MB) limitlari uchun O(1) vaqt va xotira murakkabligiga ega bo'lgan yechim mutlaqo tez va samarali hisoblanib, belgilangan cheklovlarga osongina sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi, bu yerda asosan I/O uchun kerak

using namespace std; // std nomlar fazosidan foydalanishni osonlashtiradi

int main() {
    // I/O optimizatsiyasi:
    // Bu qatorlar C++ streamlar (cin, cout) bilan C tilining
    // standart I/O funksiyalari (printf, scanf) o'rtasidagi sinxronizatsiyani o'chiradi.
    // Shuningdek, `cin.tie(0)` buyrug'i `cin` va `cout` o'rtasidagi bog'liqlikni bekor qilib,
    // kirish/chiqish operatsiyalarini tezlashtiradi. Katta ma'lumotlar bilan ishlaganda muhim.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; // Kiritiladigan N sonini saqlash uchun 'n' nomli butun son o'zgaruvchisi
    cin >> n; // Foydalanuvchidan N sonini o'qish

    // Kiritilgan sonni tahlil qilish logikasi
    if (n < 10) { // Agar N soni 10 dan kichik bo'lsa (ya'ni, bir xonali son, masalan: 5)
        cout << "NO" << endl; // Faqat bitta raqam bor, o'rnini almashtirib boshqa son hosil qilib bo'lmaydi
    } else { // Agar N soni 10 yoki undan katta bo'lsa (ya'ni, ikki xonali son, masalan: 54, 33)
        int d1 = n / 10; // N ning birinchi raqamini (o'nliklar xonasini) topish (masalan: 54/10 = 5)
        int d2 = n % 10; // N ning ikkinchi raqamini (birliklar xonasini) topish (masalan: 54%10 = 4)
        
        if (d1 == d2) { // Agar ikkala raqam ham bir xil bo'lsa (masalan: 33 da d1=3, d2=3)
            cout << "NO" << endl; // Raqamlarni almashtirsak ham son o'zgarmaydi
        } else { // Agar ikkala raqam har xil bo'lsa (masalan: 54 da d1=5, d2=4)
            cout << "YES" << endl; // Raqamlarni almashtirib boshqa son hosil qilish mumkin (54 -> 45)
        }
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganligini bildiradi
}
```

## Edge case lar va eslatmalar
*   **Bir xonali sonlar**: Masala shartiga ko'ra `N` 1 dan 9 gacha bo'lishi mumkin. Bir xonali sonlarning raqamlari o'rnini almashtirib boshqa son hosil qilishning iloji yo'q, chunki ularda faqat bitta raqam bor. Kodning `if (n < 10)` sharti aynan shu holatni to'g'ri boshqaradi va "NO" chiqaradi.
*   **Ikki xonali sonlar, bir xil raqamlar bilan**: Masalan, 11, 22, ..., 99. Bu sonlarning raqamlari o'rnini almashtirsak ham, avvalgi sonning o'zi hosil bo'ladi. Kodning `if (d1 == d2)` sharti bu holatni aniqlab, "NO" chiqaradi.
*   **Ikki xonali sonlar, har xil raqamlar bilan**: Masalan, 10, 23, 54. Bu sonlarning raqamlari o'rnini almashtirsak, har doim avvalgi sondan farqli boshqa son hosil bo'ladi. Kodning `else { cout << "YES" << endl; }` qismi bu holatni to'g'ri ishladi.
*   **Kirish cheklovlari**: `1 <= N < 100` sharti masalaning murakkabligini sezilarli darajada kamaytiradi. Sonning uzunligi doimiy (bir yoki ikki raqamli) bo'lganligi sababli, murakkab algoritm yoki ma'lumotlar tuzilmalaridan foydalanishga hojat qolmaydi, to'g'ridan-to'g'ri raqamlarni ajratib olish va taqqoslash kifoya.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M058B) platformasidagi **M058B** raqamli **Magnit raqamlar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M058B>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M058B, Magnit raqamlar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
