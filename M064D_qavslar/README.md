---
title: "M064D — Qavslar | Robocontest.uz Yechimi"
description: "Robocontest.uz M064D (Qavslar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M064D, Qavslar yechimi, robocontest Qavslar, M064D c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M064D_qavslar/
lang: uz
---

Bu dokumentatsiya `M064D — Qavslar` masalasining C++ tilidagi AC (Accepted) yechimini chuqur tushuntirish uchun mo'ljallangan.

# M064D — Qavslar

## Masala haqida
Masala matn muharriridagi uchta amal (`(`, `)`, `-`) yordamida hosil bo'lgan satr ustida ishlashni talab qiladi. `(` belgisi qo'shadi, `)` belgisi qo'shadi, `-` esa oxirgi belgini o'chiradi. Har bir amaldan so'ng, joriy satrdagi barcha "yaxshi qism-satrlar" (Regular Bracket Sequence – RBS) sonini topish kerak. Yaxshi satrlar: `()`, `(X)` (bu yerda X yaxshi satr) va `XY` (bu yerda X va Y yaxshi satrlar) qoidalariga ko'ra aniqlanadi.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi – satr va undagi yaxshi qism-satrlar sonini har bir amal (`(`, `)`, `-`) uchun dinamik ravishda yangilab borish. Har bir buyruqdan so'ng satrni butunlay qayta qurish va qayta hisoblash o'rniga, faqat oxirgi o'zgarishga mos ravishda hisob-kitoblar yangilanadi.

Buni amalga oshirish uchun stek (stack) ma'lumotlar tuzilmasi ochilmagan qavslarni kuzatib borishda yordam beradi. Dinamik dasturlash (dynamic programming) yondashuvi esa har bir indeksda tugaydigan yaxshi qism-satrlar sonini samarali hisoblash imkonini beradi. Yechim `dp[k]` ni `k` indeksida tugaydigan yaxshi qism-satrlar soni sifatida belgilaydi. Bu mos keladigan yopuvchi qavs `)` qo'shilganda yangi yaxshi qism-satrlarni hisoblashni osonlashtiradi.

Qo'shimcha ravishda, `paren_match_idx` nomli massiv har bir yopuvchi qavsga `)` mos keluvchi ochuvchi qavs `(` ning indeksini saqlaydi. Bu, `-` (o'chirish) amali bajarilganda hisob-kitoblarni tezda qaytarish imkonini beradi.

## Algoritm qadamlari

Algoritm berilgan `s` buyruqlar qatoridagi har bir belgini birma-bir qayta ishlaydi va har bir buyruqdan so'ng jami yaxshi qism-satrlar sonini chiqaradi:

1.  **Satrni va yordamchi massivlarni boshlash**:
    *   `str_vec`: Joriy satrni saqlaydigan `char` tipidagi vektor (dinamik massiv).
    *   `open_paren_indices_stack`: Ochilmagan `(` qavslarning indekslarini saqlaydigan vektor (stek sifatida ishlaydi).
    *   `dp`: `dp[k]` – `k` indeksida tugaydigan yaxshi qism-satrlar sonini saqlovchi `long long` tipidagi vektor.
    *   `paren_match_idx`: `paren_match_idx[k]` – agar `str_vec[k]` yopuvchi qavs bo'lsa, unga mos keluvchi ochuvchi qavsning indeksini saqlovchi `int` tipidagi vektor. Agar ochuvchi qavs bo'lsa yoki mos kelmas bo'lsa, `-1` qiymatni oladi.
    *   `total_rbs_count`: Jami yaxshi qism-satrlar sonini saqlovchi `long long` o'zgaruvchi.

2.  **Buyruqni qayta ishlash (`for` sikl ichida)**:

    *   **Agar buyruq `'('` bo'lsa**:
        *   `'('` belgisi `str_vec` ga qo'shiladi.
        *   Ushbu yangi belgining joriy indeksi `open_paren_indices_stack` ga qo'shiladi.
        *   `dp` va `paren_match_idx` massivlari uchun yangi indeksga mos keluvchi elementlar qo'shiladi (mos ravishda `0` va `-1` bilan boshlanadi).

    *   **Agar buyruq `')'` bo'lsa**:
        *   `')'` belgisi `str_vec` ga qo'shiladi.
        *   `dp` va `paren_match_idx` massivlari uchun yangi elementlar qo'shiladi.
        *   `open_paren_indices_stack` bo'sh emasligini tekshiriladi:
            *   Agar bo'sh bo'lmasa:
                *   `open_paren_indices_stack` dan eng oxirgi ochuvchi qavsning `match_idx` indeksi olinadi va u stekdan chiqariladi.
                *   `paren_match_idx[current_idx]` ga `match_idx` saqlanadi.
                *   `dp[current_idx]` qiymati hisoblanadi:
                    *   `dp[current_idx] = 1`: `str_vec[match_idx...current_idx]` qism-satrining o'zi birinchi turdagi yaxshi qism-satr (masalan, `()` yoki `(())`).
                    *   Agar `match_idx > 0` bo'lsa: `dp[current_idx]` ga `dp[match_idx - 1]` qo'shiladi. Sababi, `match_idx - 1` indeksida tugaydigan har qanday yaxshi qism-satr (Y) `str_vec[match_idx...current_idx]` (X) bilan birlashib, `YX` turidagi yangi yaxshi qism-satrlarni hosil qiladi.
                *   `total_rbs_count` ga `dp[current_idx]` qo'shiladi.
            *   Agar `open_paren_indices_stack` bo'sh bo'lsa, bu yopuvchi qavs mos kelmaydi va `dp[current_idx]` `0` bo'lib qoladi. `total_rbs_count` ga hech narsa qo'shilmaydi.

    *   **Agar buyruq `'-'` bo'lsa**:
        *   O'chiriladigan belgi `str_vec` ning eng oxirgi elementi (`removed_char`) aniqlanadi.
        *   **Agar `removed_char` `'('` bo'lsa**:
            *   Bu ochuvchi qavs ochilmagan bo'lgan, shuning uchun u `open_paren_indices_stack` dan chiqariladi.
        *   **Agar `removed_char` `')'` bo'lsa**:
            *   Ushbu yopuvchi qavsga mos kelgan ochuvchi qavsning `match_idx` indeksi `paren_match_idx[current_idx]` dan olinadi.
            *   Agar `match_idx != -1` bo'lsa (ya'ni, bu yopuvchi qavs avval mos kelgan juftlikning bir qismi bo'lgan):
                *   `total_rbs_count` dan `dp[current_idx]` ayiriladi, chunki bu yopuvchi qavs bilan tugaydigan yaxshi qism-satrlar endi mavjud emas.
                *   `match_idx` dagi ochuvchi qavs endi mos kelmagan holatga qaytadi, shuning uchun u `open_paren_indices_stack` ga qayta qo'shiladi.
        *   `str_vec`, `dp`, va `paren_match_idx` massivlarining eng oxirgi elementlari o'chiriladi.

3.  Har bir buyruqdan keyin, joriy `total_rbs_count` qiymati chop etiladi.

## Murakkablik tahlili

-   **Vaqt**: `O(L)`, bu yerda `L` kiruvchi buyruqlar qatorining uzunligi.
    *   Har bir buyruq (char) bir marta qayta ishlanadi.
    *   `std::vector` (dinamik massiv) ning oxiriga element qo'shish (`push_back`) yoki o'chirish (`pop_back`) o'rtacha (amortizatsiyalangan) `O(1)` vaqtni oladi.
    *   Stek operatsiyalari (masalan, `push_back`, `pop_back`, `empty`, `back`) `O(1)` vaqtni oladi.
    *   Shunday qilib, har bir buyruq `O(1)` doimiy vaqtda bajariladi.
    *   Umumiy vaqt murakkabligi `L * O(1) = O(L)`.
    *   `L` ning maksimal qiymati 200,000 bo'lganligi sababli, 1000 ms vaqt limitiga bemalol sig'adi.

-   **Xotira**: `O(L)`, bu yerda `L` kiruvchi buyruqlar qatorining uzunligi.
    *   `str_vec`: Eng yomon holatda (faqat `(` va `)`) `L` tagacha belgi saqlashi mumkin.
    *   `open_paren_indices_stack`: Eng yomon holatda (faqat `(`) `L` tagacha indeks saqlashi mumkin.
    *   `dp`: Eng yomon holatda `L` tagacha `long long` qiymat saqlashi mumkin.
    *   `paren_match_idx`: Eng yomon holatda `L` tagacha `int` qiymat saqlashi mumkin.
    *   Bu massivlarning barchasi satrning maksimal uzunligi `L` gacha o'sishi mumkin.
    *   `L = 200,000` bo'lganda, taxminan `200,000 * (1 byte (char) + 4 bytes (int) + 8 bytes (long long) + 4 bytes (int))` = `200,000 * 17 bytes = 3.4 MB` xotira talab qilinadi. Bu 32 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart C++ kutubxonalarini o'z ichiga oladi.
                      // Raqobatli dasturlashda qulaylik uchun ishlatiladi.

using namespace std; // `std::` prefiksini ishlatmasdan standart nom fazosidagi funksiyalardan foydalanish imkonini beradi.

int main() {
    // Kiritish/chiqarish (input/output) operatsiyalarini tezlashtirish.
    // cin va cout ni C standart I/O bilan sinxronizatsiyadan chiqaradi.
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    string s; // Kiruvchi buyruqlar qatorini saqlash.
    cin >> s;

    vector<char> str_vec; // Joriy satrni saqlash uchun dinamik massiv (vektor).
    vector<int> open_paren_indices_stack; // Ochilmagan '(' qavslarning indekslarini saqlaydigan stek.
    vector<long long> dp; // dp[k] — k indeksida tugaydigan yaxshi qism-satrlar sonini saqlaydi.
    vector<int> paren_match_idx; // paren_match_idx[k] — agar str_vec[k] yopuvchi qavs bo'lsa,
                                // unga mos keluvchi ochuvchi qavsning indeksini saqlaydi.
                                // Aks holda -1.
    long long total_rbs_count = 0; // Jami yaxshi qism-satrlar sonini saqlovchi hisoblagich.

    // Har bir buyruqni iteratsiya qilish.
    for (char command : s) {
        if (command == '(' || command == ')') {
            // Belgini qo'shish amali
            str_vec.push_back(command); // Belgini satr oxiriga qo'shish.
            int current_idx = str_vec.size() - 1; // Yangi qo'shilgan belgining indeksi.
            
            dp.push_back(0); // Yangi indeks uchun dp qiymatini 0 bilan boshlash.
            paren_match_idx.push_back(-1); // Yangi indeks uchun match_idx qiymatini -1 bilan boshlash.

            if (command == '(') {
                // Ochuvchi qavs bo'lsa, uning indeksini stekga qo'shish.
                open_paren_indices_stack.push_back(current_idx);
            } else { // command == ')' (Yopuvchi qavs)
                // Agar stekda ochilmagan qavslar bo'lsa (ya'ni, mos keluvchi ochuvchi qavs topilsa).
                if (!open_paren_indices_stack.empty()) {
                    // Stekning eng yuqorisidagi ochuvchi qavs indeksini olib, stekdan chiqarish.
                    int match_idx = open_paren_indices_stack.back();
                    open_paren_indices_stack.pop_back();
                    
                    paren_match_idx[current_idx] = match_idx; // Mos keluvchi indeksni saqlash.
                    
                    // str_vec[match_idx...current_idx] qism-satrining o'zi yaxshi qism-satr.
                    dp[current_idx] = 1; 
                    if (match_idx > 0) {
                        // Agar match_idx > 0 bo'lsa, match_idx - 1 indeksida tugaydigan
                        // yaxshi qism-satrlar (Y) str_vec[match_idx...current_idx] (X) bilan
                        // birlashib, YX turidagi yangi yaxshi qism-satrlar hosil qiladi.
                        dp[current_idx] += dp[match_idx - 1];
                    }
                    total_rbs_count += dp[current_idx]; // Yangi topilgan yaxshi qism-satrlarni umumiy hisobga qo'shish.
                }
                // Agar stek bo'sh bo'lsa, bu yopuvchi qavs mos kelmaydi.
                // U bilan tugaydigan yaxshi qism-satrlar yo'q, dp[current_idx] 0 bo'lib qoladi.
            }
        } else { // command == '-' (Belgini o'chirish amali)
            int current_idx = str_vec.size() - 1; // O'chiriladigan belgining indeksi.
            char removed_char = str_vec[current_idx]; // O'chiriladigan belgi.

            if (removed_char == '(') {
                // Agar o'chiriladigan belgi ochuvchi qavs bo'lsa, uni stekdan chiqarish.
                open_paren_indices_stack.pop_back(); 
            } else { // removed_char == ')' (O'chiriladigan belgi yopuvchi qavs)
                // Mos keluvchi ochuvchi qavsning indeksini olish.
                int match_idx = paren_match_idx[current_idx];
                
                // Agar bu yopuvchi qavs avval mos kelgan juftlikning bir qismi bo'lsa.
                if (match_idx != -1) { 
                    // Mos kelgan ochuvchi qavsni stekga qaytarish, chunki u endi mos kelmagan holatda.
                    open_paren_indices_stack.push_back(match_idx); 
                    // Bu yopuvchi qavs bilan tugaydigan yaxshi qism-satrlar endi mavjud emas,
                    // ularning sonini umumiy hisobdan ayirish.
                    total_rbs_count -= dp[current_idx]; 
                }
            }
            // Satr va yordamchi massivlarning oxirgi elementlarini o'chirish.
            str_vec.pop_back();
            dp.pop_back();
            paren_match_idx.pop_back();
        }
        cout << total_rbs_count << "\n"; // Har bir buyruqdan so'ng jami sonni chop etish.
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildirish.
}
```

## Edge case lar va eslatmalar

*   **Bo'sh satrga `-` buyrug'i:** Masala shartiga ko'ra, `'-'` buyrug'i kelgan vaqtda satr bo'sh bo'lmasligi kafolatlanadi. Bu holatni qo'shimcha tekshirish shart emas.
*   **Mos kelmaydigan qavslar:** Agar `')'` kelganda `open_paren_indices_stack` bo'sh bo'lsa, bu yopuvchi qavsga mos keluvchi ochuvchi qavs yo'q degani. Bunday holatda `dp[current_idx]` `0` bo'lib qoladi va `total_rbs_count` ga hech narsa qo'shilmaydi. Bu to'g'ri, chunki mos kelmaydigan qavs bilan tugaydigan yaxshi qism-satr bo'lishi mumkin emas.
*   **`match_idx > 0` sharti:** `dp[current_idx] += dp[match_idx - 1]` qismida `match_idx - 1` indeksining haqiqiy ekanligini ta'minlash uchun `match_idx > 0` sharti juda muhim. Agar `match_idx` `0` bo'lsa, `str_vec[0]` ochuvchi qavs bo'ladi va undan oldin hech qanday belgi mavjud emas, shuning uchun `dp[-1]` ga murojaat qilish xato bo'ladi. Kod bu holatni to'g'ri boshqaradi.
*   **`long long` ishlatish:** `total_rbs_count` va `dp` massividagi qiymatlar katta sonlarga yetishi mumkin (200,000 uzunlikdagi satrda potentsial yaxshi qism-satrlar soni juda ko'p bo'lishi mumkin), shuning uchun `int` o'rniga `long long` ma'lumot turini ishlatish to'g'ri tanlov.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M064D) platformasidagi **M064D** raqamli **Qavslar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M064D>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M064D, Qavslar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
