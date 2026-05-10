---
title: "M077E — Navbat | Robocontest.uz Yechimi"
description: "Robocontest.uz M077E (Navbat) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M077E, Navbat yechimi, robocontest Navbat, M077E c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M077E_navbat/
lang: uz
---

# M077E — Navbat

## Masala haqida
Bu masala navbatda turgan ishtirokchilarga yangi ishtirokchilarni maksimal darajada qo'shishni talab qiladi. Navbat 0 va 1 lardan iborat satr sifatida beriladi, bu yerda 0 bo'sh joyni, 1 esa band joyni anglatadi. Yangi kelgan ishtirokchilar navbatga qo'shilish uchun yagona shartga ega: ular yonma-yon turishni istamaydi, ya'ni navbatda ularning ikki yonida (chapda va o'ngda) hech kim bo'lmasligi, kamida bitta bo'sh joy bo'lishi shart. Bizning vazifamiz — ushbu shartlarga rioya qilgan holda, navbatga eng ko'p nechta ishtirokchini qo'shish mumkinligini aniqlash.

## Yondashuv (g'oya)
Masalani yechish uchun "greedy" (ochko'z) yondashuvdan foydalanamiz. Maqsadimiz maksimal sonli ishtirokchilarni qo'shish bo'lganligi sababli, har bir mavjud imkoniyatdan foydalanishga harakat qilamiz. Asosiy g'oya shundaki, agar biror joyga yangi ishtirokchi qo'yish mumkin bo'lsa, biz uni qo'yamiz va keyin bu qarorning keyingi joylarga ta'sirini hisobga olamiz. Yangi ishtirokchi o'zi joylashgan joyni va uning yonidagi joylarni (qo'shnilari) bo'sh emasligini ta'minlagani uchun, biz joylashtirgan ishtirokchining o'ng tomonidagi joyni (agar u mavjud bo'lsa) keyingi tekshirishdan o'tkazib yuborishimiz kerak. Sababi, bu joy yangi qo'yilgan ishtirokchiga qo'shni bo'lib qoladi va unga boshqa ishtirokchi qo'yib bo'lmaydi. Bu usul bizga eng optimal yechimni topishga imkon beradi, chunki biz imkoniyatlarni chapdan o'ngga qarab maksimal darajada samarali ishlatamiz.

## Algoritm qadamlari
1.  **Kirish ma'lumotlarini o'qish**: `n` butun sonini (navbatdagi joylar soni) va `s` satrini (navbatning joriy holati) o'qiymiz.
2.  **Hisoblagichni boshlash**: `count` nomli butun sonli o'zgaruvchini 0 ga tenglashtiramiz. Bu o'zgaruvchi navbatga qo'shiladigan maksimal ishtirokchilar sonini saqlaydi.
3.  **Navbatni skanerlash**: `i` indeksini 0 dan `n-1` gacha oshirib, navbatni boshidan oxirigacha aylanib chiqamiz.
4.  **Bo'sh joyni tekshirish**: Har bir `s[i]` joyini tekshiramiz. Agar `s[i]` `'0'` (bo'sh joy) bo'lsa, bu joyga ishtirokchi qo'yish imkoniyatini ko'rib chiqamiz.
5.  **Qo'shnilar shartini tekshirish**:
    *   **Chap qo'shni**: `left_ok` mantiqiy o'zgaruvchisi `i == 0` (ya'ni bu joy navbatning eng boshida turgan bo'lsa, chap qo'shni yo'q) yoki `s[i-1] == '0'` (chap qo'shni bo'sh bo'lsa) qiymatini oladi.
    *   **O'ng qo'shni**: `right_ok` mantiqiy o'zgaruvchisi `i == n - 1` (ya'ni bu joy navbatning eng oxirida turgan bo'lsa, o'ng qo'shni yo'q) yoki `s[i+1] == '0'` (o'ng qo'shni bo'sh bo'lsa) qiymatini oladi.
6.  **Ishtirokchini joylashtirish**: Agar `s[i]` bo'sh bo'lsa VA `left_ok` (`chap qo'shni sharti bajarilsa`) VA `right_ok` (`o'ng qo'shni sharti bajarilsa`), demak, `i`-chi joyga yangi ishtirokchi qo'yish mumkin.
    *   `count` ni bittaga oshiramiz.
    *   **Keyingi joyni o'tkazib yuborish**: `i` indeksini qo'shimcha ravishda bittaga oshiramiz (`i++`). Bu amaliyot `i+1` indeksidagi joyni ataylab tekshirmasdan o'tkazib yuborishga yordam beradi. Chunki `i`-chi joyga ishtirokchi qo'yilgandan so'ng, `i+1`-chi joy endi `i`-chi joyga qo'shni bo'lib qoladi va shartga ko'ra unga yangi ishtirokchi qo'yib bo'lmaydi. For-siklning o'zida `++i` ham ishga tushganida, `i` umumiy hisobda 2 ga oshadi va keyingi iteratsiya `i+2` indeksidan boshlanadi.
7.  **Natijani chiqarish**: For-sikl tugagandan so'ng, `count` o'zgaruvchisining qiymatini chop etamiz.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(N)`. Algoritm navbat satri (uzunligi `N`) bo'ylab faqat bir marta iteratsiya qiladi. Har bir indeksda bajariladigan amallar (tekshirishlar, o'zgaruvchilarni yangilash) doimiy vaqtda (ya'ni `O(1)`) bajariladi. Shuning uchun umumiy vaqt murakkabligi `N` ga proporsional bo'ladi. `N` ning maksimal qiymati 20000 bo'lgani uchun, bu vaqt chegaraga (1000 ms) sig'adi.
-   **Xotira murakkabligi**: `O(N)`. Biz navbat satrini `s` o'zgaruvchisida saqlashimiz kerak, bu `N` o'lchamdagi xotira talab qiladi. Boshqa o'zgaruvchilar ( `n`, `count`, `i`, `left_ok`, `right_ok`) doimiy miqdorda (ya'ni `O(1)`) xotira egallaydi. `N` ning maksimal qiymati 20000 bo'lgani uchun, bu xotira chegaraga (32 MB) sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Standart C++ kutubxonalarini o'z ichiga oladi. Odatda, bu barcha kerakli kutubxonalarni tezda kiritish uchun ishlatiladi.

using namespace std; // std nom fazosidagi funksiyalar va sinflardan to'g'ridan-to'g'ri foydalanish uchun.

int main() {
    // Kirish/chiqish operatsiyalarini tezlashtirish uchun optimizatsiyalar.
    // stdio sinxronizatsiyasini o'chiradi va cin/cout ni NULL ga bog'laydi.
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n; // Navbatdagi jami joylar soni.
    cin >> n; // n ni o'qish.
    string s; // Navbatning holatini ifodalovchi satr (0lar va 1lar).
    cin >> s; // s satrini o'qish.

    int count = 0; // Navbatga qo'shilishi mumkin bo'lgan maksimum ishtirokchilar sonini saqlaydigan hisoblagich.
    
    // Navbat satri bo'ylab iteratsiya (takrorlash).
    for (int i = 0; i < n; ++i) {
        // Faqat bo'sh joylar (0) yangi ishtirokchilar uchun ko'rib chiqiladi.
        if (s[i] == '0') { 
            // Chap qo'shni shartini tekshirish:
            // Agar joriy joy birinchi joy bo'lsa (chap qo'shni yo'q) yoki chap qo'shni bo'sh bo'lsa.
            bool left_ok = (i == 0 || s[i - 1] == '0');
            
            // O'ng qo'shni shartini tekshirish:
            // Agar joriy joy oxirgi joy bo'lsa (o'ng qo'shni yo'q) yoki o'ng qo'shni bo'sh bo'lsa.
            bool right_ok = (i == n - 1 || s[i + 1] == '0');

            // Agar joriy joy bo'sh bo'lsa va uning ikkala qo'shnisi ham bo'sh bo'lsa (yoki chegaralar bo'lsa),
            // bu joyga yangi ishtirokchi qo'yish mumkin.
            if (left_ok && right_ok) {
                count++; // Ishtirokchini joylashtiramiz.
                
                // Muhim qadam: Agar 'i' indeksiga ishtirokchi qo'yilgan bo'lsa,
                // bu joy effektiv ravishda '1' ga aylanadi.
                // Qoidaga ko'ra, yangi ishtirokchi boshqa ishtirokchiga qo'shni bo'lishi mumkin emas.
                // Demak, 'i+1' indeksidagi joyga endi yangi ishtirokchi qo'yib bo'lmaydi,
                // chunki uning chap qo'shnisi (indeks 'i', endi band) shartni buzadi.
                // Shuning uchun, 'i+1' indeksini tekshirishdan o'tkazib yuborishimiz shart.
                // Bu yerda 'i' ni bittaga oshirib, va keyin for-sikldagi '++i' ham ishlaganda,
                // 'i' jami ikki marta oshiriladi (ya'ni, i -> i+1 -> i+2),
                // effektiv ravishda keyingi tekshirish 'i+2' indeksidan boshlanadi.
                i++; 
            }
        }
    }

    cout << count << endl; // Maksimal ishtirokchilar sonini chop etish.

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildirish.
}
```

## Edge case lar va eslatmalar
*   **Navbatning qisqa uzunligi**: Agar `n=1` bo'lsa ("0" yoki "1"), kod to'g'ri ishlaydi. Masalan, `s="0"` bo'lsa, `i=0` da `left_ok` va `right_ok` ham `true` bo'ladi, `count` 1 ga aylanadi. Agar `s="1"` bo'lsa, `if (s[i] == '0')` sharti bajarilmaydi, `count` 0 bo'ladi.
*   **Faqat band joylar**: Agar navbatda faqat 1 lar bo'lsa (masalan, "111"), `count` 0 bo'lib qoladi, chunki `s[i] == '0'` sharti hech qachon bajarilmaydi.
*   **Faqat bo'sh joylar**: Agar navbatda faqat 0 lar bo'lsa (masalan, "00000"), algoritm har bir ikkinchi joyga ishtirokchi qo'yib boradi: 0-joyga, keyin 2-joyga, keyin 4-joyga va hokazo. Bu "greedy" strategiya to'g'ri natijani beradi.
*   **Algoritmning asosi — greedy tanlov**: Har doim birinchi mavjud shartlarni qanoatlantiruvchi joyga ishtirokchi qo'yishimiz, keyingi joyni o'tkazib yuborish orqali eng optimal yechimga erishiladi. Bu shuning uchunki, joylashtirish har doim eng chapdagi birinchi imkoniyatda amalga oshiriladi va bu keyingi imkoniyatlarni kamaytirishi mumkin bo'lgan ta'sirlarni minimallashtiradi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M077E) platformasidagi **M077E** raqamli **Navbat** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M077E>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M077E, Navbat yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
