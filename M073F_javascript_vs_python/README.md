---
title: "M073F — JavaScript vs Python | Robocontest.uz Yechimi"
description: "Robocontest.uz M073F (JavaScript vs Python) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M073F, JavaScript vs Python yechimi, robocontest JavaScript vs Python, M073F c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M073F_javascript_vs_python/
lang: uz
---

# M073F — JavaScript vs Python

## Masala haqida
Ushbu masalada dasturchilar orasida tez-tez munozaralarga sabab bo'ladigan, o'zgaruvchilarni nomlash uslublari haqida gap ketadi. Xususan, Python tilidagi `snake_case` (masalan, `complexity_of_problem`) va JavaScript tilidagi `camelCase` (masalan, `complexityOfProblem`) nomlash uslublari orasida "tarjimon" yaratish talab etiladi. Kirish sifatida berilgan o'zgaruvchi nomi qaysi uslubga mos kelishini aniqlab, ikkinchi uslubga o'tkazish kerak. Agar berilgan nom ikkala uslub qoidalariga ham to'g'ri kelmasa, "Xatolik" xabarini chop etish lozim. Ba'zan o'zgaruvchi nomi "=" belgisidan keyin qiymat bilan birga berilishi mumkin, bu holda "=" dan keyingi qism saqlanishi kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi – berilgan o'zgaruvchi nomining `snake_case` (Python) yoki `camelCase` (JavaScript) uslubida ekanligini aniqlash va tegishli konversiyani amalga oshirishdir. Agar nom ikkala uslubning ham qoidalariga zid bo'lsa, xatolik qaytariladi. Konversiya jarayonini aniqroq boshqarish uchun, ikkita alohida funksiya yaratiladi: biri Python nomini JavaScript nomiga, ikkinchisi esa JavaScript nomini Python nomiga o'girish uchun. Har bir funksiya berilgan nomning tegishli til qoidalariga mos kelishini tekshiradi va agar mos kelsa, o'girilgan nomni, aks holda esa xatolikni (C++ da `std::optional` orqali `nullopt` qiymatini) qaytaradi.

## Algoritm qadamlari

1.  **Kirishni o'qish va ajratish**:
    *   `getline(cin, full_line)` yordamida butun bir qator o'qib olinadi.
    *   O'qilgan qatorda `=` belgisi bormi, tekshiriladi (`full_line.find('=')`).
    *   Agar `=` belgisi mavjud bo'lsa, o'zgaruvchi nomi (belgidan oldingi qism) va o'zlashtirish qismi (belgining o'zi va undan keyingi qism) ajratiladi. O'zgaruvchi nomi oxiridagi bo'sh joylar olib tashlanadi.
    *   Agar `=` belgisi mavjud bo'lmasa, butun qator o'zgaruvchi nomi deb hisoblanadi.

2.  **`convert_python_to_js` funksiyasi (`snake_case` dan `camelCase` ga o'girish)**:
    *   **Tekshiruvlar**:
        *   Bo'sh satrlar noto'g'ri hisoblanadi.
        *   O'zgaruvchi nomi `_` (pastki chiziq) bilan boshlanishi yoki tugashi mumkin emas.
        *   Bir nechta ketma-ket `_` belgisi bo'lishi mumkin emas (`__`).
        *   `_` belgisidan keyin doim kichik harf kelishi shart.
        *   O'zgaruvchi nomida faqat kichik lotin harflari va `_` belgisi bo'lishi mumkin. Katta harflar paydo bo'lsa, bu Python qoidalariga zid hisoblanadi.
    *   **Konversiya**:
        *   Satr bo'ylab harflar bo'yicha harakatlaniladi.
        *   Agar `_` belgisi uchrasa, keyingi harfni katta harfga aylantirish uchun bayroq (`next_char_upper`) o'rnatiladi.
        *   Agar harf uchrasa va `next_char_upper` bayrog'i o'rnatilgan bo'lsa, harf katta harfga aylantiriladi va natijaga qo'shiladi. Bayroq o'chiriladi.
        *   Aks holda (harf uchrasa va bayroq o'rnatilmagan bo'lsa), harf kichikligicha natijaga qo'shiladi.
    *   Agar biron bir tekshiruvdan o'ta olmasa, `nullopt` qaytariladi. Aks holda, konvertatsiya qilingan `camelCase` satri qaytariladi.

3.  **`convert_js_to_python` funksiyasi (`camelCase` dan `snake_case` ga o'girish)**:
    *   **Tekshiruvlar**:
        *   Bo'sh satrlar noto'g'ri hisoblanadi.
        *   O'zgaruvchi nomi `_` belgisi saqlashi mumkin emas.
        *   O'zgaruvchi nomi katta harf bilan boshlanishi mumkin emas.
        *   O'zgaruvchi nomida faqat lotin harflari bo'lishi mumkin (raqamlar yoki boshqa belgilar yo'q).
    *   **Konversiya**:
        *   Satr bo'ylab harflar bo'yicha harakatlaniladi.
        *   Agar katta harf uchrasa, uning oldidan `_` belgisi qo'shiladi, so'ngra katta harf kichik harfga aylantirilib natijaga qo'shiladi.
        *   Agar kichik harf uchrasa, u shundayligicha natijaga qo'shiladi.
    *   Agar biron bir tekshiruvdan o'ta olmasa, `nullopt` qaytariladi. Aks holda, konvertatsiya qilingan `snake_case` satri qaytariladi.

4.  **Asosiy mantiq (`main` funksiyasida)**:
    *   Olingan `variable_name_str` ni avval `convert_python_to_js` funksiyasi yordamida o'girishga harakat qilinadi.
    *   Agar muvaffaqiyatli bo'lsa (ya'ni, `python_to_js_result.has_value()` rost bo'lsa), natija va o'zlashtirish qismi (agar mavjud bo'lsa) chop etiladi.
    *   Aks holda, `convert_js_to_python` funksiyasi yordamida o'girishga harakat qilinadi.
    *   Agar bu ham muvaffaqiyatli bo'lsa, natija va o'zlashtirish qismi chop etiladi.
    *   Agar ikkala urinish ham muvaffaqiyatsiz bo'lsa, "Xatolik" so'zi chop etiladi.

## Murakkablik tahlili
-   **Vaqt**: `O(L)`, bu yerda `L` kirish satrining uzunligi (maksimal 100).
    *   Kirishni o'qish va ajratish `O(L)` vaqtni oladi (qidirish va `substr` operatsiyalari).
    *   `convert_python_to_js` funksiyasi satr bo'ylab bir marta iteratsiya qiladi, bu `O(L)` vaqtni anglatadi.
    *   `convert_js_to_python` funksiyasi ham satr bo'ylab bir marta iteratsiya qiladi, bu ham `O(L)` vaqtni anglatadi.
    *   Demak, umumiy vaqt murakkabligi `O(L)` bo'ladi.
-   **Xotira**: `O(L)`, bu yerda `L` kirish satrining uzunligi.
    *   Kirish satrini saqlash uchun `O(L)` xotira talab qilinadi.
    *   Konvertatsiya qilingan natija satrini saqlash uchun ham `O(L)` xotira kerak bo'ladi (eng yomon holatda Python dan JS ga o'tishda `my_long_variable_name` => `myLongVariableName` uzunlik o'zgarmaydi, JS dan Python ga o'tishda `myLongVariableName` => `my_long_variable_name` uzunlik oshishi mumkin, lekin baribir `O(L)` chegarasida qoladi).
-   **Nega shu murakkablik chegaraga sig'adi**: `L` ning maksimal qiymati 100 bo'lganligi sababli, `O(100)` operatsiyalar soni juda tez hisoblanadi va 1000 ms vaqt chekloviga osongina sig'adi. Xuddi shunday, `100` belgili satrlar uchun xotira sarfi ham juda kam (bir necha kilobayt) bo'lib, 32 MB xotira chekloviga bemalol sig'adi.

## Kod izohi

### Standart kutubxonalar va tezkor I/O
```cpp
#include <bits/stdc++.h> // Ko'pgina standart kutubxonalarni o'z ichiga oladi
using namespace std;     // std namespace'dan foydalanish
// main funksiyasida:
ios_base::sync_with_stdio(false); // C++ oqimlari va C stdio o'rtasidagi sinxronizatsiyani o'chiradi
cin.tie(0);                       // cin operatsiyalarini cout operatsiyalari bilan bog'lamaydi
```
Bu qismlar C++ dasturlashda, ayniqsa raqobatbardosh dasturlashda tezkor kirish/chiqish (I/O) uchun standart amaliyot hisoblanadi.

### `convert_python_to_js` funksiyasi
```cpp
optional<string> convert_python_to_js(const string& s) {
    if (s.empty() || s[0] == '_' || s.back() == '_') { // Bo'sh, _ bilan boshlangan/tugagan satrlar
        return nullopt;
    }
    string result = "";
    bool next_char_upper = false; // Keyingi harfni katta qilish kerakmi bayrog'i

    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '_') {
            if (i + 1 < s.length() && s[i+1] == '_') { // Ketma-ket _
                return nullopt;
            }
            // _ dan keyin kichik harf kelishi shart. islower tekshiruvi.
            if (i + 1 >= s.length() || !islower(static_cast<unsigned char>(s[i+1]))) {
                 return nullopt;
            }
            next_char_upper = true; // Keyingi harf katta bo'ladi
        } else if (isalpha(static_cast<unsigned char>(c))) {
            if (isupper(static_cast<unsigned char>(c))) { // Python nomida katta harf bo'lmasligi kerak
                return nullopt;
            }
            if (next_char_upper) { // Agar _ dan keyin kelgan bo'lsa, katta qilib qo'sh
                result += static_cast<char>(toupper(static_cast<unsigned char>(c)));
                next_char_upper = false;
            } else { // Aks holda shundayligicha qo'sh
                result += c;
            }
        } else { // Harf yoki _ dan boshqa belgi
            return nullopt;
        }
    }
    return result; // Muvaffaqiyatli konvertatsiya
}
```
Bu funksiya `snake_case` (Python uslubi) nomni qabul qilib, uni `camelCase` (JavaScript uslubi) ga o'girishga urinadi. U Python o'zgaruvchi nomining barcha qoidalariga rioya qilinganligini tekshiradi: nom boshida/oxirida `_` yo'qligi, ketma-ket `_` yo'qligi, `_` dan keyin doim kichik harf kelishi va nomda katta harflar bo'lmasligi kabi. Agar biron bir qoida buzilsa, `nullopt` (ma'no yo'qligini bildiruvchi `std::optional` qiymati) qaytaradi. Aks holda, `_` dan keyingi harflarni katta qilib, natijani hosil qiladi. `static_cast<unsigned char>` dan foydalanish, `is*` (masalan, `islower`, `isupper`) funksiyalarining noto'g'ri ishlashini oldini oladi, chunki `char` tipi ba'zi tizimlarda signed bo'lishi mumkin.

### `convert_js_to_python` funksiyasi
```cpp
optional<string> convert_js_to_python(const string& s) {
    if (s.empty()) { // Bo'sh satr
        return nullopt;
    }
    string result = "";
    if (s.find('_') != string::npos) { // JS nomida _ bo'lmasligi kerak
        return nullopt;
    }
    if (isupper(static_cast<unsigned char>(s[0]))) { // JS nomida birinchi harf kichik bo'lishi kerak
        return nullopt;
    }

    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (isalpha(static_cast<unsigned char>(c))) { // Faqat harflar ruxsat etiladi
            if (isupper(static_cast<unsigned char>(c))) { // Katta harf bo'lsa
                result += '_'; // Oldidan _ qo'sh
                result += static_cast<char>(tolower(static_cast<unsigned char>(c))); // Kichikka aylantirib qo'sh
            } else { // Kichik harf bo'lsa
                result += c; // Shundayligicha qo'sh
            }
        } else { // Harfdan boshqa belgi
            return nullopt;
        }
    }
    return result; // Muvaffaqiyatli konvertatsiya
}
```
Bu funksiya `camelCase` (JavaScript uslubi) nomni qabul qilib, uni `snake_case` (Python uslubi) ga o'girishga urinadi. U JavaScript o'zgaruvchi nomining qoidalariga rioya qilinganligini tekshiradi: nomda `_` belgisi yo'qligi, nomning kichik harf bilan boshlanishi va faqat harflardan iboratligi kabi. Agar biron bir qoida buzilsa, `nullopt` qaytaradi. Aks holda, har bir katta harfdan oldin `_` qo'shib, uni kichik harfga aylantirib, natijani hosil qiladi.

### `main` funksiyasi
```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string full_line;
    getline(cin, full_line); // Butun qatorni o'qiymiz

    string variable_name_str;
    string assignment_suffix_str = ""; 

    size_t eq_pos = full_line.find('='); // '=' belgisini qidiramiz
    if (eq_pos != string::npos) { // Agar topilsa
        size_t var_name_end_idx = eq_pos;
        while (var_name_end_idx > 0 && isspace(static_cast<unsigned char>(full_line[var_name_end_idx - 1]))) {
            var_name_end_idx--; // O'zgaruvchi nomi oxiridagi bo'sh joylarni olib tashlaymiz
        }
        variable_name_str = full_line.substr(0, var_name_end_idx); // O'zgaruvchi nomi
        assignment_suffix_str = full_line.substr(var_name_end_idx); // '=' va undan keyingi qism
    } else {
        variable_name_str = full_line; // '=' yo'q bo'lsa, butun qator nom hisoblanadi
    }

    // Konvertatsiyalarni sinab ko'ramiz
    optional<string> python_to_js_result = convert_python_to_js(variable_name_str);
    optional<string> js_to_python_result = convert_js_to_python(variable_name_str);

    if (python_to_js_result.has_value()) { // Agar Python-JS konvertatsiya muvaffaqiyatli bo'lsa
        cout << python_to_js_result.value() << assignment_suffix_str << endl;
    } else if (js_to_python_result.has_value()) { // Aks holda, JS-Python konvertatsiya muvaffaqiyatli bo'lsa
        cout << js_to_python_result.value() << assignment_suffix_str << endl;
    } else { // Ikkala konvertatsiya ham muvaffaqiyatsiz bo'lsa
        cout << "Xatolik" << endl;
    }

    return 0;
}
```
`main` funksiyasi kirishni o'qish, o'zgaruvchi nomini ajratib olish va ikkala konvertatsiya funksiyasini chaqirish uchun javobgardir. U konvertatsiya natijalarini `std::optional` orqali tekshiradi va birinchi muvaffaqiyatli natijani chop etadi. Agar ikkala konvertatsiya ham `nullopt` qaytarsa, "Xatolik" xabarini chiqaradi.

## Edge case lar va eslatmalar
*   **Bo'sh satr**: `s.empty()` tekshiruvi har ikkala funksiyada ham bo'sh satrlarni noto'g'ri deb hisoblaydi.
*   **O'zgaruvchi nomining boshlanishi/tugashi**: Python `snake_case` qoidasiga ko'ra, nom `_` bilan boshlanishi yoki tugashi mumkin emas. (`bad_example_` yoki `_bad_example`)
*   **Ketma-ket `_` belgilari**: Python qoidalariga ko'ra `__` kabi ketma-ket `_` belgilari nomda bo'lishi mumkin emas.
*   **`_` dan keyingi harf**: Python `snake_case` da `_` dan keyin doim kichik harf kelishi shart. (`bad_Style` bu Python emas).
*   **Python nomida katta harflar**: `badStyle` kabi nom Python `snake_case` qoidalariga zid.
*   **JavaScript nomida `_` belgilari**: `my_var` kabi nom JavaScript `camelCase` qoidalariga zid.
*   **JavaScript nomining boshlanishi**: `Java` kabi katta harf bilan boshlangan nom JavaScript `camelCase` qoidalariga zid (JavaScript `camelCase` odatda kichik harf bilan boshlanadi).
*   **Faqat bitta harfli nom**: `a` kabi nomlar ikkala holatda ham o'z qoidalariga mos keladi va o'zgarmasdan qaytadi.
*   **`static_cast<unsigned char>` ishlatilishi**: `cctype` kutubxonasidagi `is*` (masalan, `islower`, `isupper`, `isspace`) funksiyalari `int` turidagi argumentni qabul qiladi. `char` turidagi o'zgaruvchini to'g'ridan-to'g'ri yuborish, agar `char` tipi `signed` bo'lsa va uning qiymati manfiy bo'lsa, xato yoki aniqlanmagan xatti-harakatga olib kelishi mumkin. `static_cast<unsigned char>` ga o'girish bu muammoni hal qiladi, chunki `unsigned char` diapazoni har doim manfiy bo'lmaydi va ushbu funksiyalar kutgan qiymatlar oralig'iga to'g'ri keladi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M073F) platformasidagi **M073F** raqamli **JavaScript vs Python** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M073F>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M073F, JavaScript vs Python yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
