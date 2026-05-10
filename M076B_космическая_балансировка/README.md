---
title: "M076B — Космическая Балансировка | Robocontest.uz Yechimi"
description: "Robocontest.uz M076B (Космическая Балансировка) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M076B, Космическая Балансировка yechimi, robocontest Космическая Балансировка, M076B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M076B_космическая_балансировка/
lang: uz
---

# M076B — Kosmik Balanslash

## Masala haqida
Galaktik arxitektor Erkin `n` ta yulduzdan `k` ta galaktika yaratishi kerak. Har bir yulduzning o'z massasi (`m_i`) bor. Kosmik balans qonuniga ko'ra, hosil bo'lgan barcha `k` ta galaktika bir xil umumiy massaga ega bo'lishi kerak. Erkinga buni amalga oshirish mumkinmi yoki yo'qligini aniqlashda yordam bering.

## Yondashuv (g'oya)
Masala berilgan `n` ta elementni (yulduz massalari) `k` ta to'plamga ajratish mumkinmi, bunda har bir to'plamning (galaktikaning) yig'indisi bir xil bo'lishi kerakligini so'raydi. Bu klassik `Subset Sum` (kichik to'plamlar yig'indisi) masalasining umumiyroq versiyasi bo'lib, `NP-complete` (Natijani tekshirish tez, lekin yechimini topish qiyin) sinfiga kiradi. `n` ning kichik qiymati (20 gacha) rekursiv, bitmaskli va memoizatsiyali (eslab qolish) yechimdan foydalanish mumkinligini ko'rsatadi.

Asosiy g'oya — rekursiv funksiya yordamida har bir galaktika uchun yulduzlarni tanlab olishga urinish va bu jarayonda hisoblangan natijalarni `memoizatsiya` (eslab qolish) orqali takroriy hisoblashdan qochish.

## Algoritm qadamlari

1.  **Dastlabki tekshiruv**: Barcha yulduzlarning umumiy massasi (`total_mass`) hisoblanadi. Agar `total_mass` soni `k` ga bo'linmasa, `k` ta bir xil massali galaktika yaratish imkonsiz. Bu holda, darhol "NO" chop etiladi va dastur yakunlanadi.
2.  **Maqsadli yig'indi**: Har bir galaktikaning massasi `target_sum_per_galaxy = total_mass / k` sifatida hisoblanadi.
3.  **Yulduzlarni saralash (optimallash)**: `m_stars` massivini kamayish tartibida (descending order) saralash. Bu optimizatsiya rekursiya jarayonida keraksiz shoxlarni tezroq kesishga (pruning) yordam beradi, chunki katta massali yulduzlarni birinchi bo'lib qo'shish, `target_sum_per_galaxy` dan oshib ketishini tezroq aniqlashga imkon beradi.
4.  **Memoizatsiya jadvalini initsializatsiya qilish**: `memo[k_qolgan_galaktikalar_soni][mavjud_yulduzlar_bitmaskasi]` ko'rinishidagi 2 o'lchamli jadval `-1` (bu holat hali ko'rib chiqilmagan) qiymati bilan to'ldiriladi. `0` noto'g'ri, `1` to'g'ri degan ma'noni anglatadi.
5.  **Rekursiv funksiyani chaqirish**: `can_partition(k_galaxies, (1 << N_stars) - 1, 0, 0)` funksiyasi chaqiriladi.
    *   Birinchi parametr: `K_galaxies` — shakllantirilishi kerak bo'lgan galaktikalar soni.
    *   Ikkinchi parametr: `(1 << N_stars) - 1` — barcha yulduzlar mavjudligini bildiruvchi bitmaska.
    *   Uchinchi parametr: `0` — hozirgi shakllantirilayotgan galaktikaning joriy massasi (dastlab 0).
    *   To'rtinchi parametr: `0` — yulduzlarni qidirishni boshlash uchun indeks.

6.  **`can_partition` rekursiv funksiyasi ichida**:
    *   **Tag holatlar (Base cases)**:
        *   Agar `k_remaining == 0` bo'lsa (hamma galaktikalar shakllantirildi), `true` (ha, mumkin) qaytariladi.
        *   Agar `current_bucket_sum == target_sum_per_galaxy` bo'lsa (joriy galaktika to'liq), yangi galaktikani shakllantirish uchun `can_partition(k_remaining - 1, available_mask, 0, 0)` chaqiriladi. `k_remaining` bittaga kamayadi, `current_bucket_sum` nolga tiklanadi va `available_mask`dan joriy galaktikada ishlatilgan yulduzlar olib tashlangan bo'ladi.
        *   Agar `current_bucket_sum > target_sum_per_galaxy` bo'lsa (joriy galaktika massasi maqsaddan oshib ketdi), `false` (yo'q, bu yo'l yaramaydi) qaytariladi.
        *   Agar `available_mask == 0` bo'lsa (barcha yulduzlar ishlatib bo'lingan) lekin `k_remaining > 0` bo'lsa (hali galaktikalar shakllantirilishi kerak), `false` qaytariladi.
    *   **Memoizatsiya tekshiruvi**: Agar `current_bucket_sum == 0` bo'lsa (ya'ni, biz yangi galaktikani shakllantirishni boshlayotgan bo'lsak) va `memo[k_remaining][available_mask]` qiymati `-1` dan farqli bo'lsa, oldindan hisoblangan natija qaytariladi. Bu `(k_remaining, available_mask)` juftligi uchun barcha keyingi galaktikalarni shakllantirish mumkinmi-yo'qmi degan savolga javob beradi.
    *   **Rekursiv qadam**: Mavjud yulduzlar (`available_mask`) ichidan bittadan tanlab, ularni hozirgi galaktikaga qo'shishga uriniladi. `start_idx_for_inner` parametri yordamida yulduzlarni `start_idx_for_inner` dan boshlab qidiriladi, bu takroriy permutatsiyalarning oldini oladi (masalan, A+B yig'indisi B+A yig'indisi bilan bir xil).
        *   Agar `m_stars[i]` yulduzi mavjud bo'lsa (`(available_mask >> i) & 1` bit operatori orqali tekshiriladi):
            *   Ushbu yulduzni joriy galaktikaga qo'shishga uriniladi: `can_partition(k_remaining, available_mask ^ (1 << i), current_bucket_sum + m_stars[i], i + 1)`.
            *   Agar bu rekursiv chaqiriq `true` qaytarsa, `possible = true` o'rnatiladi va joriy tsikl to'xtatiladi (`break`), chunki maqbul yechim topildi.
    *   **Memoizatsiya natijasi**: Agar `current_bucket_sum == 0` bo'lsa, `possible` qiymati `memo[k_remaining][available_mask]` ga saqlanadi.
    *   `possible` qiymati qaytariladi.

7.  **Yakuniy natija**: Agar dastlabki `can_partition` chaqirig'i `true` qaytarsa, "YES" chop etiladi, aks holda "NO".

## Murakkablik tahlili

-   **Vaqt**: `O(K * N * 2^N)`
    *   Bu yerda `K` galaktikalar soni, `N` yulduzlar soni.
    *   `memo` jadvali `K * 2^N` ta holatga ega. Har bir holat `(k_remaining, available_mask)` ni ifodalaydi.
    *   Har bir holat uchun (faqat `current_bucket_sum == 0` bo'lganda memoizatsiya qilinadi) biz keyingi yulduzni tanlash uchun `N` gacha iteratsiya qilamiz.
    *   `target_sum_per_galaxy` ni to'ldirish uchun ichki rekursiv chaqiriqlar `N` chuqurlikkacha borishi mumkin. Biroq, memoizatsiya samarali pruning (shoxlarni kesish) bilan birgalikda ishlaydi, shuning uchun amalda ko'pgina holatlar qayta hisoblanmaydi yoki tezda noto'g'ri deb topiladi.
    *   `N=20` va `K=20` bo'lganda, `20 * 20 * 2^20` taxminan `400 * 10^6` operatsiyani tashkil qiladi. Qattiq qilib aytganda bu yuqori ko'rsatkich bo'lsa-da, masala turida va optimizatsiyalar (saralash, `start_idx_for_inner` va memoizatsiya) tufayli tezroq ishlaydi. Masala yechimining 7 ms ichida bajarilganligi buni tasdiqlaydi.

-   **Xotira**: `O(K * 2^N)`
    *   `memo` jadvali `(K_galaxies + 1)` qatorni o'z ichiga oladi, har bir qatorda `(1 << N_stars)` ta element mavjud.
    *   `char` turidan foydalanilgani sababli (1 bayt), `memo` jadvalining hajmi `21 * (1 << 20)` baytni tashkil qiladi, bu taxminan `21 * 1 MB = 21 MB`.
    *   `N <= 20` uchun bu `32 MB` xotira chegarasiga sig'adi. Rekursiya stakining chuqurligi ham `N` va `K` ga bog'liq, ammo bu ham chegaralar ichida.

-   **Nega shu murakkablik chegaraga sig'adi**:
    *   `N` ning kichikligi (`N <= 20`) `2^N` omiliga qaramay, bitmasklardan foydalanishga imkon beradi.
    *   Memoizatsiya, ayniqsa `current_bucket_sum == 0` holatida qo'llanilishi, takroriy hisoblashlarni oldini oladi.
    *   Yulduzlarni kamayish tartibida saralash kuchli `pruning` effektini beradi; katta yulduz massalari tezda `target_sum_per_galaxy` dan oshib ketishi mumkin bo'lgan yo'llarni aniqlab, izlash daraxtining ko'p qismini kesadi.
    *   `start_idx_for_inner` parametrining ishlatilishi bir galaktikani shakllantirishda elementlarni tanlash permutatsiyalarini sezilarli darajada kamaytiradi, chunki `(a, b)` va `(b, a)` bir xil yig'indi beradi va faqat bir yo'l hisoblanadi.

## Kod izohi

1.  **Global o'zgaruvchilar**:
    *   `m_stars`: `vector<int>` turidagi massiv, yulduz massalarini saqlaydi.
    *   `target_sum_per_galaxy`: `long long` turidagi o'zgaruvchi, har bir galaktika uchun kerakli umumiy massani saqlaydi.
    *   `N_stars`, `K_galaxies`: `int` turidagi o'zgaruvchilar, mos ravishda yulduzlar va galaktikalar sonini saqlaydi.
    *   `memo[21]`: `vector<char> memo[21]` turidagi 2D massiv. Memoizatsiya jadvali sifatida ishlatiladi. `memo[i]` har bir `available_mask` uchun `char` (1 bayt) turidagi qiymatlarni saqlaydi, bu xotira samaradorligini oshiradi. Qiymatlar: `-1` (ko'rilmagan), `0` (imkonsiz), `1` (mumkin).

2.  **`can_partition` funksiyasi**:
    *   Bu rekursiv funksiya qolgan yulduzlarni (`available_mask`) `k_remaining` galaktikaga, har birining massasi `target_sum_per_galaxy` bo'lishi sharti bilan bo'lish mumkinligini aniqlaydi.
    *   **Parametrlar**:
        *   `k_remaining`: Hali shakllantirilishi kerak bo'lgan galaktikalar soni.
        *   `available_mask`: Mavjud yulduzlarni ifodalovchi bitmaska. Agar `i`-chi bit 1 bo'lsa, `m_stars[i]` mavjud.
        *   `current_bucket_sum`: Hozirgi galaktikaga yig'ilayotgan yulduzlarning massalar yig'indisi.
        *   `start_idx_for_inner`: Takroriy yulduz tanlashning oldini olish uchun joriy galaktikaga keyingi yulduzni qidirishni boshlash indeksi.
    *   **Tag holatlar (Base cases)**: Yuqoridagi "Algoritm qadamlari" bo'limida batafsil tushuntirilgan. Ular rekursiyani to'xtatish shartlari hisoblanadi.
    *   **Memoizatsiya**: Agar `current_bucket_sum == 0` bo'lsa (ya'ni, biz yangi galaktikani to'ldirishni boshlayotgan bo'lsak), `(k_remaining, available_mask)` holati uchun `memo` jadvalini tekshiradi va agar oldin hisoblangan bo'lsa, natijani qaytaradi.
    *   **Rekursiv qadam**: `for` tsikli yordamida `start_idx_for_inner` dan boshlab barcha mavjud yulduzlarni ko'rib chiqadi. Agar yulduz mavjud bo'lsa, uni joriy galaktikaga qo'shib, rekursiv chaqiruv qiladi. Agar bu chaqiruv `true` qaytarsa, `possible` flagini o'rnatib, tsiklni to'xtatadi.
    *   **Natijani saqlash**: Agar `current_bucket_sum == 0` bo'lsa, yakuniy `possible` qiymatini `memo` jadvaliga saqlaydi.

3.  **`main` funksiyasi**:
    *   Kirish/chiqish operatsiyalarini tezlashtirish uchun `ios_base::sync_with_stdio(false); cin.tie(0);` ishlatilgan.
    *   `N_stars` va `K_galaxies` o'qiladi.
    *   Yulduz massalari o'qilib, `total_mass` hisoblanadi.
    *   `total_mass % K_galaxies != 0` holati uchun dastlabki tekshiruv amalga oshiriladi.
    *   `target_sum_per_galaxy` hisoblanadi.
    *   `m_stars` kamayish tartibida saralanadi (`sort(m_stars.rbegin(), m_stars.rend())`).
    *   `memo` jadvali `-1` qiymati bilan initsializatsiya qilinadi.
    *   `can_partition` funksiyasining dastlabki chaqiruvi amalga oshiriladi.
    *   Natijaga qarab "YES" yoki "NO" chop etiladi.

## Edge case lar va eslatmalar

*   **Massaning bo'linmasligi**: Agar barcha yulduzlarning umumiy massasi `k` ga bo'linmasa, masala yechimi aniq "NO" bo'ladi. Bu eng tezkor tekshiruv.
*   **Massalarning qiymati**: Masala shartida `m_i <= 10^7` deyilgan, ammo `m_i >= 1` ekanligi aniq aytilmagan. Agar `m_i` nolga teng bo'lishi mumkin bo'lsa ham, algoritm to'g'ri ishlaydi, chunki nol massalar yig'indiga ta'sir qilmaydi.
*   **`N` ning kichikligi**: `N <= 20` bo'lishi bitmask va rekursiv yechimdan foydalanishga imkon beradigan asosiy cheklovdir. Agar `N` katta bo'lganda, boshqa algoritm (masalan, DP bilan profillar) talab qilinishi mumkin edi.
*   **Saralashning ahamiyati**: `m_stars` massasini kamayish tartibida saralash (`sort(m_stars.rbegin(), m_stars.rend())`) muhim optimizatsiya hisoblanadi. Bu katta massali yulduzlar bilan boshlab, maqsadli yig'indidan tezroq oshib ketadigan yo'llarni kesishga (pruning) yordam beradi, bu esa hisoblash vaqtini sezilarli darajada kamaytiradi.
*   **`start_idx_for_inner` parametri**: Bu parametr, bir galaktikani shakllantirishda yulduzlarni tanlash permutatsiyalarini oldini oladi. Ya'ni, agar biz A yulduzini keyin B yulduzini tanlasak, keyinroq B yulduzini keyin A yulduzini tanlashga urinmaymiz, chunki ularning yig'indisi bir xil. Bu ham vaqtni tejaydi.
*   **Memoizatsiya holati**: Memoizatsiya faqat `current_bucket_sum == 0` bo'lganda qo'llaniladi. Bu juda muhim, chunki `current_bucket_sum` holatning bir qismi sifatida juda ko'p turli qiymatlarni qabul qilishi mumkin va bu holatni to'g'ridan-to'g'ri memoizatsiya qilish xotirani oshirib yuborishi mumkin. `(k_remaining, available_mask)` juftligi to'liq galaktikalarni shakllantirish holatini anglatadi va ushbu turdagi `subset sum` muammolarida samarali hisoblanadi.
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M076B) platformasidagi **M076B** raqamli **Космическая Балансировка** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M076B>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M076B, Космическая Балансировка yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
