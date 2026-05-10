---
title: "M087E — Permutatsiya | Robocontest.uz Yechimi"
description: "Robocontest.uz M087E (Permutatsiya) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M087E, Permutatsiya yechimi, robocontest Permutatsiya, M087E c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M087E_permutatsiya/
lang: uz
---

# M087E — Permutatsiya

## Masala haqida
Bu masala sizdan 1 dan N gacha bo'lgan natural sonlarning permutatsiyasini topishingizni so'raydi. Masalada, Alijon dastlabki permutatsiyasidagi sonlar orasidagi bo'shliqlarni olib tashlab, katta bir son hosil qilgan. Bizning vazifamiz, berilgan ushbu katta sondan asl permutatsiyani qayta tiklash. Permutatsiyadagi sonlar soni (N) kamida 1 va ko'pi bilan 50 ta bo'lishi mumkin.

## Yondashuv (g'oya)
Masalani yechish uchun **backtracking (orqaga qaytish)** algoritmidan foydalaniladi. Asosiy g'oya — berilgan ulkan sonni string (matn) sifatida qabul qilib, uni turli usullar bilan bo'laklarga ajratishga urinish va har bir bo'lakni permutatsiyaning bir elementi sifatida ko'rib chiqish. N (permutatsiyaning o'lchami) maksimal 50 bo'lganligi sababli, har bir son 1 xonali (masalan, 5) yoki 2 xonali (masalan, 12, 45) bo'lishi mumkin. Uch xonali sonlar bo'lmaydi, chunki ular 50 dan oshib ketadi.

Algoritm stringning boshidan boshlab, har bir qadamda 1 yoki 2 xonali sonni ajratib olishga harakat qiladi. Agar ajratib olingan son 1 dan 50 gacha bo'lsa va hali permutatsiyada ishlatilmagan bo'lsa, u permutatsiyaga qo'shiladi va qolgan string uchun rekursiv ravishda jarayon davom ettiriladi. Agar butun string shunday bo'laklarga ajratilsa va yakuniy tekshiruv (topilgan elementlar soni maksimal elementga teng bo'lsa) ijobiy natija bersa, yechim topilgan hisoblanadi. Agar bitta yo'l yechimga olib kelmasa, algoritm orqaga qaytadi (backtrack) va boshqa variantlarni sinab ko'radi.

## Algoritm qadamlari

1.  **Kirish ma'lumotlarini o'qish**: Katta son `std::string` tipida `s` o'zgaruvchisiga o'qiladi.
2.  **Yordamchi ma'lumot tuzilmalari**:
    *   `bool visited[51]`: 1 dan 50 gacha bo'lgan sonlarning har biri permutatsiyada ishlatilganligini kuzatish uchun boolean (mantiqiy) massiv. `visited[num]` `true` bo'lsa, `num` soni allaqachon ishlatilgan.
    *   `std::vector<int> result_permutation`: Hozirgi rekursiv yo'lda topilgan sonlarni saqlash uchun vektor.
3.  **`find_permutation` rekursiv funksiyasi**: Bu funksiya stringni indeks `idx` dan boshlab ajratishga harakat qiladi. U uchta parametr qabul qiladi:
    *   `idx`: Hozirgi string indeksi.
    *   `max_val_so_far`: Hozirgacha topilgan sonlar orasidagi eng kattasi.
    *   `num_elements_so_far`: Hozirgacha topilgan elementlar (sonlar) soni.
4.  **Baza holati**: Agar `idx` stringning oxiriga yetib borsa (`idx == s.length()`), bu butun string muvaffaqiyatli ajratilganini bildiradi. Endi haqiqiy permutatsiya ekanligini tekshirish kerak:
    *   Agar `max_val_so_far == num_elements_so_far` bo'lsa, bu degani biz `num_elements_so_far` ta son topdik va ularning eng kattasi `max_val_so_far` ga teng. Misol uchun, agar `max_val_so_far` 5 bo'lsa va biz 5 ta son topgan bo'lsak, demak bu 1 dan 5 gacha bo'lgan sonlarning permutatsiyasi (chunki `visited` massivi yordamida takrorlanishlar oldi olingan). Bunday holda, `result_permutation` vektoridagi sonlar chop etiladi va `true` qiymat qaytariladi.
    *   Aks holda, `false` qaytariladi, chunki bu to'liq permutatsiya emas.
5.  **Optimallashtirish (Pruning)**: Agar `max_val_so_far` yoki `num_elements_so_far` 50 dan oshib ketsa, bu yo'l bekor qilinadi, chunki N maksimal 50 bo'lishi kerak.
6.  **1 xonali sonni ajratib ko'rish**:
    *   Agar `idx` string chegarasida bo'lsa, `s[idx]` belgisidan 1 xonali son (`num1`) hosil qilinadi.
    *   Agar `num1` 1 dan 50 gacha bo'lsa va `!visited[num1]` (ya'ni, hali ishlatilmagan) bo'lsa:
        *   `visited[num1] = true` qilib belgilanadi.
        *   `num1` `result_permutation` ga qo'shiladi.
        *   `find_permutation(idx + 1, std::max(max_val_so_far, num1), num_elements_so_far + 1)` chaqiriladi.
        *   Agar bu rekursiv chaqiruv `true` qaytarsa, yechim topilgan hisoblanadi va shu `true` qiymat yuqoriga uzatiladi.
        *   Aks holda (yechim topilmasa), **backtrack** qilinadi: `result_permutation.pop_back()` va `visited[num1] = false`.
7.  **2 xonali sonni ajratib ko'rish**:
    *   Agar `idx + 1` string chegarasida bo'lsa va `s[idx]` "0" bo'lmasa (ikki xonali son "0" bilan boshlanmaydi), `s[idx]` va `s[idx+1]` belgilaridan 2 xonali son (`num2`) hosil qilinadi.
    *   Agar `num2` 10 dan 50 gacha bo'lsa va `!visited[num2]` bo'lsa:
        *   `visited[num2] = true` qilib belgilanadi.
        *   `num2` `result_permutation` ga qo'shiladi.
        *   `find_permutation(idx + 2, std::max(max_val_so_far, num2), num_elements_so_far + 1)` chaqiriladi.
        *   Agar bu rekursiv chaqiruv `true` qaytarsa, yechim topilgan hisoblanadi va shu `true` qiymat yuqoriga uzatiladi.
        *   Aks holda (yechim topilmasa), **backtrack** qilinadi: `result_permutation.pop_back()` va `visited[num2] = false`.
8.  **Natija chiqarish**: Agar `find_permutation` funksiyasi `main` dan chaqirilganda `true` qaytarsa, yechim allaqachon chop etilgan bo'ladi.

## Murakkablik tahlili

*   **Vaqt**: `O(2^L)` bu yerda `L` kiruvchi stringning uzunligi. Nazariy jihatdan, har bir indeksda biz 1 xonali yoki 2 xonali sonni ajratishga harakat qilamiz, bu qidiruv daraxtida har bir tugundan 2 ta yo'nalishni anglatadi. Biroq, `N` ning maksimal qiymati 50 ekanligi va `visited` massividan foydalanish, shuningdek `max_val_so_far` va `num_elements_so_far` cheklovlari juda kuchli **pruning (kesish)** mexanizmini ta'minlaydi. Natijada, ko'plab rekursiv yo'llar tezda bekor qilinadi. Shuning uchun amalda algoritm juda tez ishlaydi (namuna testlarda 2 ms). Eng yomon holatda, string uzunligi `L` taxminan 91 (9 ta bir xonali va 41 ta ikki xonali sonlar uchun). Shunga qaramay, samarali kesish tufayli vaqt limiti 1000 ms ichida qoladi.
*   **Xotira**: `O(N)` + `O(Max_N)`.
    *   `visited` massivi doimiy 51 elementdan iborat, bu `O(1)` (aniqrog'i `O(Max_N)`) xotira talab qiladi.
    *   `result_permutation` vektori va rekursiv funksiya chaqiruvlar steki chuqurligi maksimal `N` gacha bo'ladi (chunki biz `N` ta elementli permutatsiyani qidiramiz). Shuning uchun bu `O(N)` xotira talab qiladi. Maksimal `N` 50 bo'lgani uchun, umumiy xotira `O(50)` ga teng, ya'ni doimiy va juda kam xotira sarfi. Bu 32 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun
#include <string>   // String ma'lumot turi uchun
#include <vector>   // Dinamik massiv (vektor) uchun
#include <algorithm> // std::max funksiyasi uchun

std::string s; // Kirish stringini saqlash uchun global o'zgaruvchi
bool visited[51]; // 1 dan 50 gacha bo'lgan sonlarning ishlatilganligini kuzatish uchun. Indekslar 1 dan 50 gacha ishlatiladi.
std::vector<int> result_permutation; // Hozirgi permutatsiya elementlarini saqlash uchun vektor

// idx: kirish stringidagi joriy indeks
// max_val_so_far: hozirgacha topilgan permutatsiya elementlari orasidagi maksimal qiymat
// num_elements_so_far: hozirgacha ajratib olingan va permutatsiyaga qo'shilgan sonlar soni
bool find_permutation(int idx, int max_val_so_far, int num_elements_so_far) {
    // Baza holati: Agar butun string tahlil qilingan bo'lsa.
    if (idx == s.length()) {
        // 1 dan N gacha bo'lgan yaroqli permutatsiya aynan N ta elementga ega bo'lishi va ularning eng kattasi N ga teng bo'lishi kerak.
        // Agar max_val_so_far == num_elements_so_far bo'lsa, bu biz N ta turli sonlarni topganimizni
        // va ularning eng kattasi N ekanligini bildiradi.
        // Biz faqat ishlatilmagan va 1-50 oralig'idagi sonlarni qo'shganimiz sababli,
        // bu shart to'plangan sonlarning aynan 1, 2, ..., N ekanligini kafolatlaydi.
        if (max_val_so_far == num_elements_so_far) {
            for (size_t i = 0; i < result_permutation.size(); ++i) {
                std::cout << result_permutation[i] << (i == result_permutation.size() - 1 ? "" : " ");
            }
            std::cout << std::endl;
            return true; // Yechim topildi, keyingi qidiruvlarni to'xtatish uchun true qaytariladi
        }
        return false; // String oxiriga yetib kelindi, ammo yaroqli permutatsiya emas
    }

    // Pruning (kesish): Agar max_val_so_far 50 dan oshsa, bu 50 gacha bo'lgan sonlar permutatsiyasi bo'la olmaydi.
    // Yoki agar num_elements_so_far 50 dan oshsa.
    if (max_val_so_far > 50 || num_elements_so_far > 50) {
        return false;
    }

    // 1 xonali sonni ajratib ko'rish
    // 'idx' string chegaralari ichida ekanligiga ishonch hosil qilish
    if (idx < s.length()) {
        int num1 = s[idx] - '0'; // Belgini raqamga o'tkazish
        // num1 yaroqli son (1-50) ekanligini va hali ishlatilmaganligini tekshirish
        if (num1 >= 1 && num1 <= 50 && !visited[num1]) {
            visited[num1] = true; // Ishlatilgan deb belgilash
            result_permutation.push_back(num1); // Hozirgi permutatsiyaga qo'shish
            if (find_permutation(idx + 1, std::max(max_val_so_far, num1), num_elements_so_far + 1)) {
                return true; // Agar yechim topilsa, true qaytarish
            }
            result_permutation.pop_back(); // Backtrack (orqaga qaytish): permutatsiyadan olib tashlash
            visited[num1] = false; // Backtrack: ishlatilgan belgisini olib tashlash
        }
    }

    // 2 xonali sonni ajratib ko'rish
    // 'idx + 1' string chegaralari ichida ekanligiga VA son '0' bilan boshlanmasligiga ishonch hosil qilish
    // (masalan, "01" ni 1 deb qabul qilish mumkin emas).
    if (idx + 1 < s.length() && s[idx] != '0') {
        int num2 = (s[idx] - '0') * 10 + (s[idx+1] - '0'); // Ikki belgini ikki xonali raqamga o'tkazish
        // num2 yaroqli son (10-50) ekanligini va hali ishlatilmaganligini tekshirish
        if (num2 >= 10 && num2 <= 50 && !visited[num2]) {
            visited[num2] = true; // Ishlatilgan deb belgilash
            result_permutation.push_back(num2); // Hozirgi permutatsiyaga qo'shish
            if (find_permutation(idx + 2, std::max(max_val_so_far, num2), num_elements_so_far + 1)) {
                return true; // Agar yechim topilsa, true qaytarish
            }
            result_permutation.pop_back(); // Backtrack: permutatsiyadan olib tashlash
            visited[num2] = false; // Backtrack: ishlatilgan belgisini olib tashlash
        }
    }

    return false; // Bu yo'ldan yechim topilmadi
}

int main() {
    // C++ standart oqimlarini (stream) musobaqa dasturlash uchun optimallashtirish
    std::ios_base::sync_with_stdio(false); // C style I/O (printf/scanf) bilan C++ style I/O (cout/cin) sinxronizatsiyasini o'chirish
    std::cin.tie(0); // cout bufferini cin kirishidan oldin yuvishni o'chirish

    // Kirish stringini o'qish
    std::cin >> s;

    // 'visited' massivi global statik saqlash muddatiga ega o'zgaruvchi bo'lib,
    // u nolga (false) avtomatik tarzda initsializatsiya qilinadi.
    // Backtracking qidiruvini stringning boshidan (idx=0), hali hech qanday son topilmagan holatdan (max_val_so_far=0, num_elements_so_far=0) boshlaymiz.
    find_permutation(0, 0, 0);

    return 0;
}
```

## Edge case lar va eslatmalar

*   **1 xonali permutatsiyalar**: Masalan, `s = "1"`. Algoritm `idx=0` dan `num1=1` ni ajratadi. `idx` 1 ga, `max_val_so_far` 1 ga, `num_elements_so_far` 1 ga aylanadi. Baza holatida `idx == s.length()` (1==1) va `max_val_so_far == num_elements_so_far` (1==1) shartlari bajariladi va "1" chop etiladi.
*   **Ikki xonali sonlar uchun "0" bilan boshlanish**: `s[idx] != '0'` tekshiruvi muhim. Masalan, "05" ni 5 deb ajratib bo'lmaydi. Faqat "5" deb ajratish kerak.
*   **`visited` massivi va permutatsiya sharti**: `visited` massivi har bir sonning permutatsiyada faqat bir marta ishlatilishini ta'minlaydi. `max_val_so_far == num_elements_so_far` sharti esa topilgan sonlar 1 dan N gacha bo'lgan to'liq to'plamni tashkil etishini tasdiqlaydi. Bu ikkita mexanizm birgalikda, agar yechim topilsa, u haqiqatan ham 1 dan N gacha bo'lgan sonlarning permutatsiyasi ekanligini kafolatlaydi.
*   **Maksimal N = 50**: Bu cheklov juda muhim, chunki u har bir sonning maksimal 2 xonali bo'lishini (10 dan 50 gacha) yoki 1 xonali bo'lishini (1 dan 9 gacha) anglatadi. Agar N kattaroq bo'lganda, 3 xonali sonlarni ham ko'rib chiqish kerak bo'lar edi.
*   **I/O optimallashtirish**: `std::ios_base::sync_with_stdio(false);` va `std::cin.tie(0);` qatorlari C++ oqimlarining tezligini oshirish uchun ishlatiladi, bu musobaqa dasturlashda katta kirish ma'lumotlari uchun muhim.
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M087E) platformasidagi **M087E** raqamli **Permutatsiya** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M087E>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M087E, Permutatsiya yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
