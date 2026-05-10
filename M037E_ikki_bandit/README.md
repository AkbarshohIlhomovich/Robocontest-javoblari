---
title: "M037E — Ikki bandit | Robocontest.uz Yechimi"
description: "Robocontest.uz M037E (Ikki bandit) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M037E, Ikki bandit yechimi, robocontest Ikki bandit, M037E c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M037E_ikki_bandit/
lang: uz
---

# M037E — Ikki bandit

## Masala haqida
Ushbu masalada Garri va Larri ismli ikki bandit ma'lum sondagi Coca-Cola qutilarini bir qatorga terib, ularga o'q otishadi. Garri chap tomondan, Larri esa o'ng tomondan otishni boshlaydi. Muhim ma'lumot shundaki, ular bir vaqtning o'zida aynan bitta oxirgi qutini otishgan. Bizga Garri va Larri otgan qutilar soni berilgan bo'lib, vazifamiz Garri nechta qutini otmaganligini va Larri nechta qutini otolmaganligini aniqlash.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi — bu ikki banditning "bir xil so'nggi qutini otishganligi" shartidan kelib chiqadi. Bu shart shuni anglatadiki, ular o'qlagan jami qutilar sonida bitta quti ikki marta hisoblangan.
Demak, Garri otgan qutilar (H) va Larri otgan qutilar (L) ma'lum bo'lsa:
1. Garri otmagan qutilar — bu Larri otgan qutilarning sonidan umumiy qutini ayirib tashlaganimizda qoladigan qutilardir. Ya'ni, Larri o'ziga tegishli bo'lgan, Garri esa o'qlamagan qutilar soni.
2. Larri otmagan qutilar — bu Garri otgan qutilarning sonidan umumiy qutini ayirib tashlaganimizda qoladigan qutilardir. Ya'ni, Garri o'ziga tegishli bo'lgan, Larri esa o'qlamagan qutilar soni.

Agar Garri `H` ta qutini va Larri `L` ta qutini otgan bo'lsa, va ular bitta qutini birga otishgan bo'lsa, unda Garri otmagan qutilar soni `L - 1` ga, Larri otmagan qutilar soni esa `H - 1` ga teng bo'ladi.

## Algoritm qadamlari
1. Kirish ma'lumotlarini o'qish: Garri otgan qutilar soni (`H`) va Larri otgan qutilar soni (`L`) butun sonlar sifatida o'qiladi.
2. Garri otmagan qutilar sonini hisoblash: Larri otgan qutilar sonidan 1 ni ayirish orqali topiladi. Bu `L - 1` ga teng.
3. Larri otmagan qutilar sonini hisoblash: Garri otgan qutilar sonidan 1 ni ayirish orqali topiladi. Bu `H - 1` ga teng.
4. Hisoblangan ikki qiymat (Garri otmagan va Larri otmagan qutilar soni) chiqish fayliga chop etiladi.

## Murakkablik tahlili
- **Vaqt**: O(1)
- **Xotira**: O(1)
- Nega: Algoritm faqat ikkita butun sonni o'qish, ikkita oddiy arifmetik ayirish amalini bajarish va ikki natijani chop etishdan iborat. Bu amallar soni kirish ma'lumotlarining hajmiga bog'liq emas va har doim doimiy miqdorda vaqt va xotira talab qiladi. Masalada qutilar soni maksimal 10 ta ekanligi aytilgan, bu ham doimiy murakkablik chegaraga bemalol sig'ishini tasdiqlaydi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Bu qator standart C++ kutubxonalarini (masalan, iostream, algorithm, vector va boshqalar) o'z ichiga oladi. Odatda, bu faqat kerakli kutubxonalarni qo'shish o'rniga tezkor yechimlarda ishlatiladi.

int main() {
    // I/O (kirish/chiqish) tezligini optimallashtirish uchun ishlatiladigan qatorlar:
    std::ios_base::sync_with_stdio(false); // C++ dagi 'iostream' kutubxonasini C tilining standart I/O kutubxonalari bilan sinxronizatsiyasini o'chiradi. Bu katta miqdordagi kirish/chiqish operatsiyalarida tezlikni oshiradi.
    std::cin.tie(0); // 'std::cin' oqimini 'std::cout' oqimi bilan bog'lanishini bekor qiladi. Odatda, 'std::cin' dan o'qishdan oldin 'std::cout' buferini tozalaydi, bu esa vaqtni oladi. Bu qator esa bu xatti-harakatni o'chirib, tezlikni oshiradi.
    
    int H, L; // Garri (H) va Larri (L) tomonidan otilgan qutilar sonini saqlash uchun ikkita butun sonli o'zgaruvchilar e'lon qilinadi.
    std::cin >> H >> L; // Kirish oqimidan (standart kiritishdan) H va L o'zgaruvchilariga mos ravishda qiymatlarni o'qiydi.
    
    int harry_not_shot = L - 1; // Garri tomonidan otilmagan qutilar sonini hisoblaydi. Agar Larri L ta quti otgan bo'lsa va ulardan bittasi Garri bilan umumiy bo'lsa, qolgan L-1 tasi faqat Larri otgan va Garri otmagan qutilardir.
    int larry_not_shot = H - 1; // Larri tomonidan otilmagan qutilar sonini hisoblaydi. Xuddi shunday, agar Garri H ta quti otgan bo'lsa va ulardan bittasi Larri bilan umumiy bo'lsa, qolgan H-1 tasi faqat Garri otgan va Larri otmagan qutilardir.
    
    std::cout << harry_not_shot << " " << larry_not_shot << std::endl; // Hisoblangan natijalarni (Garri otmagan qutilar soni, keyin bo'sh joy, keyin Larri otmagan qutilar soni) standart chiqish oqimiga (konsolga) chop etadi. 'std::endl' belgisi qator yakunini qo'shib, chiqish buferini tozalaydi.
    
    return 0; // Dastur muvaffaqiyatli yakunlanganligini ko'rsatuvchi qiymatni qaytaradi.
}
```

## Edge case lar va eslatmalar
- **Minimal qutilar soni**: Masala shartiga ko'ra, Garri va Larri "bir xil so'nggi qutini otishgan". Bu shuni anglatadiki, `H` va `L` kamida 1 ga teng bo'lishi kerak. Agar `H=1` va `L=1` bo'lsa (ya'ni, jami bitta quti bor va ikkalasi ham uni otgan), unda Garri otmagan qutilar `1-1=0` va Larri otmagan qutilar `1-1=0` bo'ladi. Bu holat ham algoritm bilan to'g'ri hisoblanadi.
- **Maksimal qutilar soni**: Masala matnida "10 tadan ko'p emas" deb berilgan. Bu cheklov juda kichik bo'lib, hisoblashda hech qanday muammoga olib kelmaydi va `int` turining diapazoniga bemalol sig'adi.
- **Tezlashtirish uchun kod**: `std::ios_base::sync_with_stdio(false);` va `std::cin.tie(0);` qatorlari odatda katta kirish ma'lumotlariga ega bo'lgan masalalarda C++ I/O operatsiyalarini tezlashtirish uchun ishlatiladi. Ushbu masala uchun, kirish hajmi juda kichik bo'lgani sababli, bu optimizatsiyalar shart emas, lekin zarar ham qilmaydi.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M037E) platformasidagi **M037E** raqamli **Ikki bandit** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M037E>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M037E, Ikki bandit yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
