---
title: "M080H — Merlin | Robocontest.uz Yechimi"
description: "Robocontest.uz M080H (Merlin) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 3000 ms, xotira: 132 MB."
keywords: "robocontest M080H, Merlin yechimi, robocontest Merlin, M080H c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M080H_merlin/
lang: uz
---

# M080H — Merlin

## Masala haqida
Bir kuni minorasiga qaytayotgan Merlin Morgana uning barcha donolik eliksiri solingan idishlariga la'nat solganini payqadi. Merlin la'natni qanday olib tashlashni biladi, ammo tegishli sehrni qo'llash uchun u qo'llaniladigan barcha idishlarda bir xil miqdorda eliksir bo'lishi kerak. Bunga erishish uchun Merlin quyidagicha harakat qilishga qaror qildi: u bir nechta idishni tanlaydi va tanlangan idishlardagi butun eliksirni qolganlariga quyadi. Quyilgan eliksirni qolgan idishlar orasida istalgancha taqsimlashi mumkin. Tanlangan idishlardan barcha eliksir olib tashlangach, Merlin bo'shagan idishlarni sindirib tashlaydi, parchalarni uloqtiradi va qolgan idishlarga la'natni olib tashlash sehrini qo'llaydi. Sehrgarga Morgananing la'natini olib tashlash uchun sindirishi kerak bo'lgan idishlarning eng kam sonini topishga yordam bering.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi shundan iboratki, Merlin sindirishi kerak bo'lgan idishlar sonini minimallashtirish uchun u saqlab qoladigan idishlar sonini maksimallashtirishi kerak. Aytaylik, u `k` ta idishni saqlab qolishga qaror qildi. Bu `k` ta idishning har birida eliksir miqdori teng bo'lishi kerak, deylik, har birida `X` litrdan. Barcha `n` ta idishdagi umumiy eliksir miqdori `total_sum` bo'lsa, unda `X = total_sum / k` bo'ladi.

Eng muhim cheklov shundaki, saqlab qolinadigan `k` ta idishning har birining dastlabki eliksir miqdori (`a_i`) `X` dan oshmasligi kerak. Buning sababi, biz faqatgina eliksirni *qo'sha olamiz*, *olib tashlay olmaymiz*. Agar biror idishda dastlabki `a_i` miqdor `X` dan katta bo'lsa, u idishni `k` ta saqlanib qoladigan idishlar qatoriga kiritish imkonsiz, chunki uning miqdorini `X` ga tenglashtirish uchun eliksirni kamaytirish talab qilinadi. Shunday qilib, saqlanib qoladigan har bir idish uchun `a_i <= X` sharti bajarilishi shart.

Yechim `k` ning maksimal qiymatini topishga asoslangan. Biz `k` ni `n` dan `1` gacha kamayib borish tartibida tekshiramiz. Birinchi bo'lib `k` ta idishni saqlab qolish mumkin bo'lgan holatni topganimizda, bu bizning maksimal `k` bo'ladi.

## Algoritm qadamlari
1.  **Umumiy yig'indini hisoblash**: Barcha idishlardagi eliksir miqdorini (`a_i`) o'qing va ularning umumiy yig'indisini (`total_sum`) `long long` turida saqlang. `long long` ishlatish muhim, chunki yig'indi juda katta bo'lishi mumkin.
2.  **Massivni saralash**: `a` massividagi eliksir miqdorlarini o'sish tartibida saralang. Bu keyinchalik ma'lum miqdordan kichik yoki teng bo'lgan idishlar sonini tezda topishga yordam beradi.
3.  **`k` ni topish uchun iteratsiya**: Saqlanib qoladigan idishlar soni (`k`) `n` dan `1` gacha kamayib borish tartibida tekshiriladi (`for (int k = n; k >= 1; --k)`). Bu yondashuv eng katta `k` ni topishni kafolatlaydi, chunki agar biror `k` uchun shart bajarilsa, bu topilgan `k` maksimal `k` bo'ladi.
4.  **Maqsad miqdorini hisoblash**: Har bir `k` uchun, agar `k` ta idish saqlab qolinadigan bo'lsa, har birida qancha eliksir bo'lishi kerakligini (`target_X_val = total_sum / k`) hisoblang. Bu qiymat `double` turida bo'ladi, chunki bo'linma kasrli bo'lishi mumkin.
5.  **Chegara miqdorini aniqlash**: `target_X_val` ni `long long` turiga o'tkazib, pastga qarab yaxlitlash (`floor`) orqali `threshold` qiymatini aniqlang. Barcha `k` ta idishning dastlabki eliksir miqdori (`a_i`) shu `threshold` dan oshmasligi kerak. Ya'ni, `a_i <= threshold` sharti bajarilishi lozim.
6.  **Mos idishlar sonini hisoblash**: Saralangan `a` massivida `threshold` dan kichik yoki teng bo'lgan idishlar sonini (`count_le_threshold`) ikkilik qidiruv (binary search) yordamida (`upper_bound` funksiyasi bilan) toping. `upper_bound(a.begin(), a.end(), threshold)` funksiyasi `threshold` dan *katta* bo'lgan birinchi elementga ishorachini qaytaradi. Bu ishorachigacha bo'lgan elementlar soni esa `threshold` dan kichik yoki teng bo'lgan elementlar sonini beradi.
7.  **Shartni tekshirish**: Agar `count_le_threshold >= k` bo'lsa, ya'ni `threshold` dan kichik yoki teng bo'lgan idishlar soni `k` dan ko'proq yoki teng bo'lsa, biz `k` ta idishni tanlashimiz mumkin. Bu holda, joriy `k` eng katta mumkin bo'lgan qiymatdir (`max_k`). Shu qiymatni saqlab, siklni to'xtating (`break`).
8.  **Natijani chiqarish**: `n - max_k` ni chop eting. Bu sindirilishi kerak bo'lgan idishlarning minimal sonidir.

## Murakkablik tahlili
-   **Vaqt**: `O(N log N)`
    -   `a` massividagi `N` ta eliksir miqdorini o'qish va `total_sum` ni hisoblash `O(N)` vaqtni oladi.
    -   `a` massivini saralash `O(N log N)` vaqtni oladi.
    -   `max_k` ni topish uchun for sikli `N` marta (eng yomon holatda) bajariladi.
    -   Sikl ichida `upper_bound` funksiyasi saralangan massivda ikkilik qidiruvni amalga oshiradi, bu esa `O(log N)` vaqtni talab qiladi.
    -   Shunday qilib, umumiy vaqt murakkabligi `O(N + N log N + N * log N) = O(N log N)` ga teng.
-   **Xotira**: `O(N)`
    -   Eliksir miqdorlarini saqlash uchun `vector<long long> a` massivi `N` ta `long long` elementni talab qiladi. Bu `O(N)` xotira murakkabligini bildiradi.
-   **Nega shu murakkablik chegaraga sig'adi**:
    `N` ning maksimal qiymati `10^5` bo'lganda, `N log N` taxminan `10^5 * log_2(10^5) \approx 10^5 * 17 = 1.7 \times 10^6` amaliyotni anglatadi. Bu `3000 ms` (3 soniya) vaqt chegarasi ichida bemalol bajariladi. `O(N)` xotira esa `10^5` ta `long long` element uchun `10^5 \times 8` bayt = `0.8` MB ni tashkil etadi, bu `132 MB` xotira chegarasidan ancha kam.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Bu qator standart C++ kutubxonalarini (vector, algorithm, iostream, va boshqalar) o'z ichiga oladi.

using namespace std; // std namespace'ini ishlatish, shuning uchun std::oldidan yozish shart emas.

int main() {
    ios_base::sync_with_stdio(false); // C++ oqimlari (cin/cout) va C standart kiritish/chiqarish (scanf/printf) orasidagi sinxronizatsiyani o'chiradi.
    cin.tie(0); // cin ob'ektining cout ob'ekti bilan bog'lanishini bekor qiladi. Bu ikki qator kirish/chiqish operatsiyalarini tezlashtirish uchun ishlatiladi.

    int n; // Idishlar sonini saqlash uchun o'zgaruvchi.
    cin >> n; // n qiymatini kiritishdan o'qib oladi.

    vector<long long> a(n); // Har bir idishdagi eliksir miqdorini saqlash uchun dinamik massiv (vektor).
                           // Eliksir miqdorlari katta bo'lishi mumkinligi sababli 'long long' turi ishlatilgan.
    long long total_sum = 0; // Barcha idishlardagi eliksirning umumiy yig'indisini saqlash uchun o'zgaruvchi.
                             // Bu ham katta qiymat bo'lishi mumkinligi sababli 'long long'.
    for (int i = 0; i < n; ++i) { // n ta eliksir miqdorini o'qish uchun sikl.
        cin >> a[i]; // Joriy idishdagi eliksir miqdorini o'qib, 'a' massiviga saqlaydi.
        total_sum += a[i]; // O'qilgan miqdorni umumiy yig'indiga qo'shadi.
    }

    sort(a.begin(), a.end()); // 'a' massividagi elementlarni o'sish tartibida saralaydi.
                              // Bu keyinchalik ikkilik qidiruvdan foydalanish uchun zarur.

    int max_k = 0; // Saqlab qolinishi mumkin bo'lgan maksimal idishlar sonini saqlash uchun o'zgaruvchi.
    for (int k = n; k >= 1; --k) { // 'k' (saqlanib qoladigan idishlar soni) ni 'n' dan '1' gacha kamayib borish tartibida tekshirish uchun sikl.
                                  // Eng katta 'k' ni topish uchun 'n' dan boshlaymiz.
        double target_X_val = static_cast<double>(total_sum) / k; // Agar 'k' ta idish qolsa, har birida bo'lishi kerak bo'lgan eliksirning maqsadli miqdori.
                                                                  // 'total_sum' ni 'double' turiga o'tkazish bo'linmaning aniqligini saqlaydi.

        long long threshold = static_cast<long long>(floor(target_X_val)); // Maqsadli miqdordan kichik yoki teng bo'lishi kerak bo'lgan eliksirning yuqori chegarasi.
                                                                         // 'floor()' funksiyasi kasrli sonni pastga qarab eng yaqin butun songa yaxlitlaydi.
                                                                         // Bu idishlardagi eliksir miqdorlari butun son ekanligini hisobga olgan holda.
        
        // 'upper_bound(a.begin(), a.end(), threshold)' saralangan 'a' massivida 'threshold' dan qat'iy katta
        // bo'lgan birinchi elementga ishorachini qaytaradi.
        // Bu ishorachigacha bo'lgan elementlar (ya'ni, 'a.begin()' dan 'it' gacha) 'threshold' dan kichik yoki tengdir.
        auto it = upper_bound(a.begin(), a.end(), threshold); 
        int count_le_threshold = distance(a.begin(), it); // 'threshold' dan kichik yoki teng bo'lgan elementlar soni.

        if (count_le_threshold >= k) { // Agar 'threshold' dan kichik yoki teng bo'lgan idishlar soni 'k' dan katta yoki teng bo'lsa,
                                       // demak, biz 'k' ta idishni tanlashimiz mumkin.
            max_k = k; // Joriy 'k' ni 'max_k' sifatida saqlaymiz.
            break; // Chunki biz 'k' ni kamayib borish tartibida tekshirganimiz uchun,
                   // birinchi topilgan 'k' maksimal mumkin bo'lgan 'k' bo'ladi. Shu sababli siklni to'xtatamiz.
        }
    }

    cout << n - max_k << endl; // Merlin sindirishi kerak bo'lgan idishlarning minimal sonini (umumiy idishlar soni minus saqlangan maksimal idishlar soni) chop etadi.

    return 0; // Dastur muvaffaqiyatli yakunlanganligini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Minimal `n` qiymati**: Masala matniga ko'ra, `n` ning minimal qiymati `2` ga teng. Bu kamida ikkita idish mavjudligini anglatadi. Algoritm bu cheklovni qo'llab-quvvatlaydi.
*   **`total_sum` ning ma'lumot turi**: `total_sum` ning qiymati `n * max(a_i)` gacha bo'lishi mumkin. Eng yomon holatda `10^5 * 10^9 = 10^14` ni tashkil etishi mumkin, bu `int` ma'lumot turining chegarasidan oshib ketadi. Shuning uchun `long long` ma'lumot turidan foydalanish shart.
*   **`target_X_val` va `threshold` ni hisoblashdagi aniqlik**: `total_sum / k` bo'linmasi butun son bo'lmasligi mumkin. Shuning uchun `double` turidan foydalanib hisoblash, keyin esa `floor()` funksiyasi yordamida pastga qarab butun songa yaxlitlash kerak. Bu `a_i <= X` shartini `a_i <= floor(X)` shartiga o'tkazish uchun to'g'ri usuldir, chunki `a_i` butun sonlardir.
*   **`std::upper_bound` funksiyasi**: Bu funksiya saralangan diapazonda berilgan qiymatdan *qat'iy katta* bo'lgan birinchi elementga ishorachini qaytaradi. Shuning uchun `distance(a.begin(), it)` orqali hisoblangan qiymat berilgan `threshold` dan *kichik yoki teng* bo'lgan elementlar sonini ifodalaydi.
*   **Kirish/chiqishni tezlashtirish**: `ios_base::sync_with_stdio(false);` va `cin.tie(0);` qatorlari `N = 10^5` kabi katta kirish hajmi bo'lgan masalalarda C++ oqimlarining ishlash tezligini sezilarli darajada oshiradi va vaqt limitini oshmaslikka yordam beradi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M080H) platformasidagi **M080H** raqamli **Merlin** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M080H>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M080H, Merlin yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
