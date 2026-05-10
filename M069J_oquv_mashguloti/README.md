---
title: "M069J — O'quv mashg'uloti | Robocontest.uz Yechimi"
description: "Robocontest.uz M069J (O'quv mashg'uloti) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M069J, O'quv mashg'uloti yechimi, robocontest O'quv mashg'uloti, M069J c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M069J_oquv_mashguloti/
lang: uz
---

# M069J — O'quv mashg'uloti

## Masala haqida
Bu masala askarlarning o'quv mashg'ulotlari jarayonida qurollar omborxonasiga borish sonini minimallashtirishni talab qiladi. `N` ta askar `M` turdagi qurollardan foydalanadi. Mashg'ulot maydonchasida `K` ta otish maydonchasi mavjud bo'lib, har birida faqat bitta qurol turishi mumkin. Askarlar navbati bilan mashg'ulot o'tkazadi va har biri ma'lum turdagi qurolni talab qiladi. Agar talab qilingan qurol maydonchada mavjud bo'lsa, askar undan foydalanadi; aks holda, u omborxonaga borib, kerakli qurolni olib keladi. Agar barcha maydonchalar band bo'lsa, askar mavjud qurollardan birini omborxonaga qaytarib, o'ziga kerakli qurolni olib keladi. Maqsad – omborxonaga borish sonini minimal qilish.

## Yondashuv (g'oya)
Bu masala "Optimal Page Replacement Algorithm" (Optimal sahifa almashtirish algoritmi) muammosining klassik variantidir. Optimal strategiya har doim maydonchalarda kelajakda eng uzoq vaqtda ishlatiladigan (yoki umuman ishlatilmaydigan) qurollarni almashtirishdan iborat. Bu ochko'z (greedy) algoritm deb ataladi va bunday turdagi masalalar uchun optimal yechim hisoblanadi.

Algoritmning asosiy g'oyasi:
1.  Har bir askar uchun uning talab qilgan quroli `A[i]` keyingi qachon (qaysi askar tomonidan) yana talab qilinishini oldindan aniqlab olamiz.
2.  `K` ta maydonchani boshqarish uchun ma'lumot tuzilmasidan foydalanamiz, bu bizga maydonchadagi qurollar orasidan kelajakda eng uzoq ishlatiladigani (yoki umuman ishlatilmaydigani) tezda topish imkonini beradi. `std::set` bu vazifani samarali bajaradi.

## Algoritm qadamlari
1.  **Kiruvchi ma'lumotlarni o'qish**: `M` (qurol turlari soni), `K` (maydonchalar soni), `N` (askarlar soni) va `A` massivi (har bir askarning talab qilgan qurol turi) o'qiladi.
2.  **`next_occurrence` massivini hisoblash**:
    *   `last_seen` nomli yordamchi massiv yaratiladi, bu massiv `M+1` o'lchamda bo'lib, har bir qurol turining eng so'nggi ko'rinish indeksini saqlaydi. Dastlab barcha qiymatlari `N` ga tenglashtiriladi (bu qurol keyin ishlatilmaydi degani).
    *   `next_occurrence` nomli massiv yaratiladi, bu `N` o'lchamda bo'lib, `next_occurrence[i]` askar `i` talab qilgan `A[i]` qurol turining keyingi ko'rinish indeksini saqlaydi.
    *   `A` massivi bo'yicha `N-1` dan `0` gacha orqaga yuriladi:
        *   Har bir `i` uchun `next_occurrence[i]` ga `last_seen[A[i]]` qiymati beriladi.
        *   `last_seen[A[i]]` esa joriy `i` indeksiga yangilanadi.
    *   Bu bosqichda `next_occurrence[i]` qiymati `N` bo'lsa, demak `A[i]` quroli `i`-askardan keyin boshqa hech qachon ishlatilmaydi.
3.  **Asosiy sikl (askarlar bo'yicha)**:
    *   `trips` (omborxonaga borishlar soni) 0 ga tenglashtiriladi.
    *   `active_guns` nomli `std::set` yaratiladi. Bu `set` ichida `pair<int, int>` (birinchi qiymat: qurolning keyingi ishlatilish indeksi, ikkinchi qiymat: qurol turi) saqlanadi. `set` avtomatik ravishda elementlarni birinchi juftlik qiymati (keyingi ishlatilish indeksi) bo'yicha o'sish tartibida saralaydi.
    *   `current_gun_next_occurrence` nomli yordamchi massiv yaratiladi, bu `M+1` o'lchamda bo'lib, agar qurol maydonchada bo'lsa, uning keyingi ishlatilish indeksini saqlaydi. Dastlab barcha qiymatlari `N` ga teng.
    *   `i = 0` dan `N-1` gacha (har bir askar uchun) sikl boshlanadi:
        a.  `current_gun_type` joriy askarning talab qilgan qurol turi (`A[i]`) va `next_use_for_current_gun` ushbu qurolning keyingi ishlatilish indeksi (`next_occurrence[i]`) qabul qilinadi.
        b.  **Agar `current_gun_type` maydonchada mavjud bo'lsa** (ya'ni `current_gun_next_occurrence[current_gun_type] != N`):
            *   `active_guns` dan ushbu qurolning eski yozuvi (`{current_gun_next_occurrence[current_gun_type], current_gun_type}`) o'chiriladi.
            *   `active_guns` ga ushbu qurolning yangi yozuvi (`{next_use_for_current_gun, current_gun_type}`) qo'shiladi.
            *   `current_gun_next_occurrence[current_gun_type]` yangi `next_use_for_current_gun` qiymatiga yangilanadi.
            *   Bu holatda omborxonaga borish shart emas.
        c.  **Agar `current_gun_type` maydonchada mavjud bo'lmasa**:
            *   `trips` hisoblagichi 1 ga oshiriladi.
            *   **Agar bo'sh maydonchalar bo'lsa** (`active_guns.size() < K`):
                *   `current_gun_type` omborxonadan olinib, bo'sh maydonchaga joylashtiriladi.
                *   `active_guns` ga `{next_use_for_current_gun, current_gun_type}` qo'shiladi.
                *   `current_gun_next_occurrence[current_gun_type]` yangi `next_use_for_current_gun` qiymatiga yangilanadi.
            *   **Aks holda (hamma maydonchalar band bo'lsa)**:
                *   `active_guns` dan kelajakda eng uzoq muddatda ishlatiladigan qurol topiladi. `set`ning xususiyatidan foydalanib, bu qurol `*active_guns.rbegin()` orqali olinadi (ya'ni `set`ning oxirgi elementi, chunki u `next_occurrence` bo'yicha eng katta qiymatga ega).
                *   Bu qurol (masalan, `gun_to_evict`) `active_guns` dan o'chiriladi.
                *   `current_gun_next_occurrence[gun_to_evict.second]` qiymati `N` ga o'rnatiladi (bu qurol endi maydonchada emas).
                *   `current_gun_type` omborxonadan olinib, bo'shagan maydonchaga joylashtiriladi.
                *   `active_guns` ga `{next_use_for_current_gun, current_gun_type}` qo'shiladi.
                *   `current_gun_next_occurrence[current_gun_type]` yangi `next_use_for_current_gun` qiymatiga yangilanadi.
4.  **Natijani chop etish**: `trips` qiymati ekranga chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(N log K)`
    *   `A` massivini o'qish: `O(N)`.
    *   `next_occurrence` massivini hisoblash: `N` marta sikl ichida massivga kirish `O(N)` vaqt oladi.
    *   Asosiy sikl `N` marta takrorlanadi. Har bir iteratsiyada:
        *   `std::set` ga element qo'shish yoki undan element o'chirish `O(log K)` vaqt oladi, chunki `set` ning o'lchami ko'pi bilan `K` bo'lishi mumkin.
        *   `std::vector` ga murojaat qilish `O(1)` vaqt oladi.
    *   Shuning uchun umumiy vaqt murakkabligi `O(N + N log K)` bo'lib, bu `O(N log K)` ga soddalashadi.
    *   Berilgan `N <= 100 000` va `K <= N` bo'lsa, `log K` eng yomon holatda `log 100 000` taxminan `17` ni tashkil qiladi. Demak, `100 000 * 17` taxminan `1.7 * 10^6` operatsiyalar bajariladi, bu `1000 ms` vaqt limiti uchun juda tez.

-   **Xotira murakkabligi**: `O(N + M)`
    *   `A` massivi: `O(N)` butun son.
    *   `next_occurrence` massivi: `O(N)` butun son.
    *   `last_seen` massivi: `O(M)` butun son.
    *   `active_guns` `std::set`: ko'pi bilan `K` ta `pair<int, int>` saqlaydi, bu `O(K)` xotira oladi.
    *   `current_gun_next_occurrence` massivi: `O(M)` butun son.
    *   Shuning uchun umumiy xotira murakkabligi `O(N + M + K)` bo'lib, bu `O(N + M)` ga soddalashadi, chunki `K <= N`.
    *   Berilgan `N <= 100 000` va `M <= 500 000` bo'lsa, jami `(100 000 + 500 000)` ta `int` (4 bayt) ~ `600 000 * 4 = 2.4 MB` ni tashkil qiladi. Bu 32 MB xotira limiti uchun bemalol yetarli. `std::set` ichidagi `pair`lar ham qo'shimcha xotira olsa-da, umumiy hajmi chegaradan oshmaydi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi (vector, set va hokazo)

using namespace std; // std nom fazosidan foydalanish

int main() {
    // Kiritish/chiqarish operatsiyalarini tezlashtirish uchun optimizatsiyalar
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    int M, K, N; // M: qurol turlari, K: maydonchalar soni, N: askarlar soni
    cin >> M >> K >> N; // Kiruvchi ma'lumotlarni o'qish

    vector<int> A(N); // Askarlar talab qilgan qurollar ro'yxati
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Har bir askarning talab qilgan qurolini o'qish
    }

    // next_occurrence va last_seen massivlarini hisoblash
    // Bu qism har bir qurol turining keyingi qachon ishlatilishini topadi.
    vector<int> next_occurrence(N); // next_occurrence[i] = A[i] qurolining i-dan keyingi keyingi ishlatilish indeksi
    vector<int> last_seen(M + 1, N); // last_seen[type] = type qurolining oxirgi ko'rilgan indeksi. Dastlab N (umuman ishlatilmaydi)

    // A massivi bo'yicha orqaga yurish
    for (int i = N - 1; i >= 0; --i) {
        next_occurrence[i] = last_seen[A[i]]; // A[i] qurolining keyingi ishlatilishini topamiz
        last_seen[A[i]] = i; // A[i] quroli oxirgi marta i-da ko'rildi, shuni yangilaymiz
    }

    int trips = 0; // Omborxonaga borishlar soni
    // active_guns: Maydonchalarda turgan qurollarning next_occurrence qiymati va qurol turini saqlaydi.
    // std::set elementlarni avtomatik saralaydi, bu bizga eng katta next_occurrence (ya'ni kelajakda eng uzoq ishlatiladigan)
    // qurolni tezda topish imkonini beradi.
    set<pair<int, int>> active_guns; // {next_occurrence_index, gun_type}
    // current_gun_next_occurrence[type] = type quroli maydonchada bo'lsa, uning next_occurrence qiymati.
    // Agar N bo'lsa, qurol maydonchada emas degani.
    vector<int> current_gun_next_occurrence(M + 1, N); 

    // Askarlar bo'yicha asosiy sikl
    for (int i = 0; i < N; ++i) {
        int current_gun_type = A[i]; // Joriy askarning talab qilgan qurol turi
        int next_use_for_current_gun = next_occurrence[i]; // Bu qurolning keyingi ishlatilish indeksi

        // Agar joriy qurol maydonchalarning birida allaqachon mavjud bo'lsa
        if (current_gun_next_occurrence[current_gun_type] != N) { 
            // set'dan eski yozuvni o'chiramiz
            active_guns.erase({current_gun_next_occurrence[current_gun_type], current_gun_type});
            // set'ga yangi next_occurrence bilan yozuvni qo'shamiz (chunki bu qurol endi hozirgi askar tomonidan ishlatildi va uning keyingi ishlatilishi o'zgardi)
            active_guns.insert({next_use_for_current_gun, current_gun_type});
            // current_gun_next_occurrence ni ham yangilaymiz
            current_gun_next_occurrence[current_gun_type] = next_use_for_current_gun;
        } else { // Agar joriy qurol maydonchada mavjud bo'lmasa
            trips++; // Omborxonaga borish kerak, hisoblagichni oshiramiz

            // Agar bo'sh maydonchalar bo'lsa (K dan kam qurol turgan bo'lsa)
            if (active_guns.size() < K) { 
                // Yangi qurolni maydonchaga qo'yamiz
                active_guns.insert({next_use_for_current_gun, current_gun_type});
                current_gun_next_occurrence[current_gun_type] = next_use_for_current_gun;
            } else { // Agar hamma maydonchalar band bo'lsa
                // Maydonchadan chiqarilishi kerak bo'lgan qurolni topamiz.
                // Bu active_guns set'ining oxirgi elementi bo'ladi (eng katta next_occurrence, ya'ni eng uzoqda ishlatiladigani).
                pair<int, int> gun_to_evict = *active_guns.rbegin();
                
                // Uni set'dan o'chiramiz
                active_guns.erase(gun_to_evict);
                // current_gun_next_occurrence da ushbu qurolni maydonchada emasligini belgilaymiz
                current_gun_next_occurrence[gun_to_evict.second] = N; 

                // Joriy qurolni maydonchaga qo'yamiz
                active_guns.insert({next_use_for_current_gun, current_gun_type});
                current_gun_next_occurrence[current_gun_type] = next_use_for_current_gun;
            }
        }
    }

    cout << trips << endl; // Minimal borishlar sonini chop etish

    return 0; // Dasturni yakunlash
}
```

## Edge case lar va eslatmalar
*   **`next_occurrence` qiymati `N` bo'lganda**: Bu degani, ushbu qurol tipi joriy askardan keyin boshqa hech qachon talab qilinmaydi. Bu holatda, `N` qiymati eng katta `next_occurrence` deb hisoblanadi, ya'ni bu qurolni maydonchadan chiqarish uchun eng yaxshi nomzodlardan biri bo'ladi, chunki u kelajakda boshqa kerak bo'lmaydi.
*   **`K=1` holati**: Agar faqat bitta maydoncha bo'lsa, har safar yangi qurol kerak bo'lganda, avvalgi qurol omborxonaga qaytariladi va yangisi olinadi. Bu algoritm bu holatni ham to'g'ri boshqaradi.
*   **`std::set<pair<int, int>>` ning ishlashi**: `std::set` elementlarni avtomatik ravishda saralaydi. `pair<int, int>` holatida, avval `first` (birinchi) element bo'yicha, keyin `second` (ikkinchi) element bo'yicha saralaydi. Bizning holatda `first` element `next_occurrence` bo'lgani uchun, `set.begin()` eng kichik `next_occurrence`ga ega qurolni (eng tezda kerak bo'ladigani), `set.rbegin()` esa eng katta `next_occurrence`ga ega qurolni (eng uzoqda kerak bo'ladigani) beradi. Bu bizga almashtirish uchun optimal qurolni `O(log K)` vaqtda topish imkonini beradi.
*   **Optimal harakat**: Masala shartida "optimal harakat qilishsa" deb aytilgan. Bu aynan yuqorida tavsiflangan "kelajakda eng uzoq ishlatiladigan qurolni almashtirish" strategiyasini anglatadi, chunki bu greedy yechim ushbu turdagi muammolar uchun optimal ekanligi isbotlangan.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M069J) platformasidagi **M069J** raqamli **O'quv mashg'uloti** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M069J>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M069J, O'quv mashg'uloti yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
