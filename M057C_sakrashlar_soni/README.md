---
title: "M057C — Sakrashlar soni | Robocontest.uz Yechimi"
description: "Robocontest.uz M057C (Sakrashlar soni) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Matematika. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M057C, Sakrashlar soni yechimi, robocontest Sakrashlar soni, M057C c++ kod, matematika, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M057C_sakrashlar_soni/
lang: uz
---

# M057C — Sakrashlar soni

## Masala haqida
Jasur koordinatalar boshida (0 nuqtada) turib, \(X\) nuqtadagi maktabiga borishi kerak. Uning har bir yurishi o'ziga xos: birinchi qadamda 1 birlik, ikkinchisida 2 birlik va hokazo, \(k\)-chi qadamda \(k\) birlik masofani bosib o'tadi. Har bir qadamni u oldinga yoki orqaga tashlashi mumkin. Masala Jasurga maktabga yetib borish uchun minimal necha qadam kerakligini topishni talab qiladi.

## Yondashuv (g'oya)
Masala simmetrikdir, ya'ni \(X\) musbat yoki manfiy bo'lishidan qat'i nazar, \(|X|\) masofani bosib o'tish uchun bir xil minimal qadamlar soni kerak bo'ladi. Shuning uchun, avvalo \(X\) ning mutlaq qiymatini (`std::abs(X)`) olamiz.

Asosiy g'oya — \(k\) ta qadamda bosib o'tiladigan maksimal masofa \(1 + 2 + \dots + k = k \times (k + 1) / 2\) ga teng ekanligini anglash. Bu yig'indini \(S_k\) deb belgilaylik. \(k\) qadamda \(X\) ga yetish uchun ikki asosiy shart bajarilishi kerak:
1. `S_k` (maksimal masofa) \(X\) dan kam bo'lmasligi kerak: \(S_k \ge X\). Aks holda, \(X\) ga yetib bo'lmaydi.
2. `S_k` va \(X\) ning paritetlari (juft yoki toqligi) bir xil bo'lishi kerak, ya'ni \((S_k - X)\) juft son bo'lishi kerak. Bu shartning sababi shundaki, har bir \(i\)-chi qadamni \((+i)\) yoki \((-i)\) yo'nalishda bosib o'tishimiz mumkin. Agar biz \((+i)\) qadamni \((-i)\) ga o'zgartirsak, umumiy masofa \(2i\) ga kamayadi. \(2i\) har doim juft son bo'lgani uchun, qadam yo'nalishini o'zgartirish umumiy yig'indining juft/toqligini o'zgartirmaydi. Demak, agar biz \(S_k\) (maksimal mumkin bo'lgan yig'indi) dan \(X\) ga erishmoqchi bo'lsak, ularning paritetlari bir xil bo'lishi shart.

Algoritm \((k=1, 2, 3, \dots)\) ketma-ket qadamlar sonini oshirib boradi, \(S_k\) ni hisoblaydi va yuqoridagi ikki shartni tekshiradi. Ikkala shartni ham qanoatlantiradigan birinchi \(k\) bizning minimal javobimiz bo'ladi.

## Algoritm qadamlari
1. Kirishdan \(X\) sonini o'qib oling.
2. Agar \(X\) nolga teng bo'lsa, 0 qadam kerak, shu sababli 0 ni chop eting va dasturni yakunlang.
3. \(X\) ning mutlaq qiymatini hisoblang (`X = std::abs(X)`), chunki masala simmetrik.
4. Qadamlar sonini saqlash uchun `k = 0` va jami masofani saqlash uchun `current_sum = 0` o'zgaruvchilarini boshlang'ich holatga keltiring.
5. Cheksiz sikl boshlang (`while (true)`):
   a. `k` ni 1 ga oshiring (`k++`).
   b. `current_sum` ga `k` ni qo'shing (`current_sum += k`). Bu `1 + 2 + ... + k` yig'indini hisoblaydi.
   c. Agar `current_sum` \(X\) dan katta yoki unga teng bo'lsa (`current_sum >= X`) VA \((current\_sum - X)\) juft son bo'lsa (`(current_sum - X) % 2 == 0`):
      i. `k` ni chop eting.
      ii. Sikldan chiqing (dasturni tugating). Bu biz izlagan minimal qadamlar soni.

## Murakkablik tahlili
- **Vaqt**: `O(sqrt(X))`. Har bir qadamda `k` qiymati 1 ga oshadi va `current_sum` ga `k` qo'shiladi. `current_sum` qiymati taxminan `k^2 / 2` ga teng bo'ladi. Shart `current_sum >= X` bajarilishi uchun `k^2 / 2` taxminan `X` ga teng bo'lishi kerak, ya'ni `k` taxminan `sqrt(2X)` ga teng bo'ladi. `X` ning maksimal qiymati \(10^9\) bo'lgani uchun, `k` taxminan `sqrt(2 * 10^9)` yani `~45000` ga yaqin bo'ladi. Bu iteratsiyalar soni vaqt limiti (1000 ms) uchun juda tez.
- **Xotira**: `O(1)`. Algoritm faqat bir nechta o'zgaruvchilarni (`x`, `k`, `current_sum`) saqlash uchun doimiy miqdordagi xotiradan foydalanadi.
- Nega shu murakkablik chegaraga sig'adi: Vaqt murakkabligi `sqrt(X)` bo'lgani uchun, \(X = 10^9\) holatida taxminan 45 mingga yaqin operatsiya bajariladi, bu 1 soniya ichida bajarilishiga imkon beradi. Xotira murakkabligi doimiy bo'lgani sababli, berilgan 32 MB xotira limitiga bemalol sig'adi.

## Kod izohi
```cpp
#include <bits/stdc++.h> // Bu fayl ko'plab standart C++ kutubxonalarini o'z ichiga oladi,
                         // jumladan kirish/chiqish operatsiyalari (iostream) va std::abs funksiyasi (cmath).

int main() {
    // std::ios_base::sync_with_stdio(false) C++ streamlarini (cin, cout) C tilining standart I/O
    // funksiyalari (scanf, printf) bilan sinxronizatsiyasini o'chiradi. Bu I/O operatsiyalarini tezlashtiradi.
    // std::cin.tie(0) cin dan keyin cout ni avtomatik ravishda tozalashni (flush) o'chiradi.
    // Bu ham I/O ni tezlashtirishga yordam beradi, ayniqsa ko'p miqdordagi kirish/chiqishda.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long x; // X koordinatasi -10^9 dan 10^9 gacha bo'lishi mumkin,
                 // bu int turining maksimal qiymatidan (taxminan 2*10^9) oshishi mumkin.
                 // Shuning uchun xato oldini olish uchun long long ishlatiladi.
    std::cin >> x; // Kirishdan X qiymatini o'qib olamiz.

    if (x == 0) { // Agar maqsad nuqta 0 bo'lsa, Jasur allaqachon maktabda,
                  // shuning uchun hech qanday qadam kerak emas.
        std::cout << 0 << std::endl; // 0 ni chop etamiz.
        return 0; // Dasturni muvaffaqiyatli yakunlaymiz.
    }

    x = std::abs(x); // Masala simmetrik, ya'ni 0 dan 2 ga borish bilan 0 dan -2 ga borish bir xil qadamlar sonini talab qiladi.
                     // Shuning uchun, X ning mutlaq qiymatini olib, faqat musbat masofa bilan ishlaymiz.

    long long k = 0; // Hozirgacha tashlangan jami qadamlar sonini saqlaydi.
                     // Ya'ni, 1-qadamda k=1, 2-qadamda k=2 va hokazo.
    long long current_sum = 0; // k ta qadamda bosib o'tiladigan maksimal masofa (1 + 2 + ... + k) ni saqlaydi.

    // Minimal k (qadamlar soni) ni topish uchun cheksiz sikl boshlaymiz.
    // Shartlar bajarilganda sikldan chiqiladi.
    while (true) {
        k++; // Har bir iteratsiyada qadamlar sonini 1 ga oshiramiz.
        current_sum += k; // current_sum ga hozirgi k ni qo'shamiz.
                          // Bu 1 dan k gacha bo'lgan sonlar yig'indisini hisoblaydi.

        // Ikki asosiy shartni tekshiramiz:
        // 1. current_sum >= x: k ta qadamda erishish mumkin bo'lgan maksimal masofa, maqsad masofa x dan
        //    kam bo'lmasligi kerak. Agar kam bo'lsa, x ga erishib bo'lmaydi.
        // 2. (current_sum - x) % 2 == 0: current_sum va x ning paritetlari (juft/toqligi) bir xil bo'lishi kerak.
        //    Bu shart muhim: har bir i-chi qadamni (+i) yoki (-i) tarzda bosib o'tish mumkin.
        //    Agar (+i) ni (-i) ga o'zgartirsak, jami masofa 2*i ga kamayadi.
        //    2*i har doim juft son bo'lgani uchun, jami masofaning juft/toqligi o'zgarmaydi.
        //    Shuning uchun, S_k (maksimal yig'indi) va x bir xil paritetda bo'lishi kerak.
        if (current_sum >= x && (current_sum - x) % 2 == 0) {
            std::cout << k << std::endl; // Minimal k ni chop etamiz.
            break; // Sikldan chiqamiz, chunki biz birinchi mos keladigan k ni topdik,
                   // va u minimal bo'ladi, chunki k qiymati doimiy ravishda oshib boradi.
        }
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
- **\(X=0\) holati**: Jasur allaqachon maktabda bo'lsa, hech qanday qadam kerak emas. Bu kodda alohida `if (x == 0)` sharti bilan boshida tekshirilgan.
- **Manfiy \(X\)**: Kiruvchi \(X\) manfiy bo'lishi mumkin. `std::abs(x)` funksiyasi yordamida bu holat to'g'ri boshqariladi, chunki masofa har doim musbat hisoblanadi va harakatlar simmetrik.
- **`long long` dan foydalanish**: \(X\) ning qiymati va `current_sum` ning maksimal qiymatlari (taxminan \(10^9\)) `int` tipidan oshib ketishi mumkin. Shu sababli, `long long` ma'lumot turi toshib ketish (overflow) muammosining oldini oladi.
- **Paritet sharti muhimligi**: `(current_sum - x) % 2 == 0` sharti yechimning eng muhim qismidir. Ushbu shartni tushunish, har qanday qadamning yo'nalishini o'zgartirish umumiy yig'indini juft songa o'zgartirishini va shuning uchun maksimal erishish mumkin bo'lgan yig'indi (`current_sum`) va maqsad (`x`) bir xil juft/toqlikka ega bo'lishi kerakligini anglatadi.
- **Minimal qadamlar**: Algoritm `k` ni 1 dan boshlab bosqichma-bosqich oshirib boradi va shartlar bajarilganda birinchi topilgan `k` minimal hisoblanadi, chunki `current_sum` monoton ravishda o'sib boradi.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M057C) platformasidagi **M057C** raqamli **Sakrashlar soni** masalasi. U **Matematika** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M057C>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M057C, Sakrashlar soni yechimi, robocontest masalalari, c++17, olimpiada yechimi, matematika, dasturlash uzbek, competitive programming O'zbekiston.</sub>
