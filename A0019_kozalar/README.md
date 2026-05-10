---
title: "A0019 — Ko'zalar | Robocontest.uz Yechimi"
description: "Robocontest.uz A0019 (Ko'zalar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest A0019, Ko'zalar yechimi, robocontest Ko'zalar, A0019 c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /A0019_kozalar/
lang: uz
---

# A0019 — Ko'zalar

## Masala haqida
Bu masalada bizga ikki xil hajmdagi (A va B litr) ko'zalar va cheksiz suv manbai beriladi. Bizning vazifamiz — shu ko'zalar yordamida aniq C litr suvni idishlardan birida hosil qilib bo'ladimi yoki yo'qligini aniqlash. Har bir test holati uchun "YES" yoki "NO" javobini chiqarish talab qilinadi.

## Yondashuv (g'oya)
Masalaning yechimi sonlar nazariyasidagi muhim tushuncha – **Bézout ayniyati** (ingl. Bézout's Identity) va **eng katta umumiy bo'luvchi (EKUB)** (ingl. Greatest Common Divisor, GCD) ga asoslanadi. Bu ayniyatga ko'ra, agar ikkita butun son `a` va `b` berilgan bo'lsa, `ax + by` shaklida ifodalash mumkin bo'lgan har qanday son `a` va `b` ning EKUBiga karrali bo'ladi. Va aksincha, `a` va `b` ning EKUBining har qanday karralisi `ax + by` shaklida ifodalanishi mumkin (bu yerda `x` va `y` butun sonlar).

Bizning ko'za muammomizda, biz suvni ko'zalarga quyish (`+A`, `+B`), to'kib tashlash (`-A`, `-B`) yoki biridan ikkinchisiga quyish orqali manipulyatsiya qilamiz. Bu operatsiyalarning barchasi effektif ravishda bizga `k_1 * A + k_2 * B` shaklida suv miqdorlarini hosil qilish imkonini beradi, bu yerda `k_1` va `k_2` musbat yoki manfiy butun sonlar bo'lishi mumkin. Demak, biz hosil qila oladigan har qanday suv miqdori `A` va `B` ning EKUBiga karrali bo'lishi shart. Agar `C` miqdor suvni hosil qilish kerak bo'lsa, `C` ham `EKUB(A, B)` ga bo'linishi kerak.

Bundan tashqari, agar `C` miqdor suvni birorta ko'zada hosil qilish kerak bo'lsa, `C` miqdori ko'zalarning maksimal sig'imidan (ya'ni, `max(A, B)`) oshmasligi kerak. Agar `C` ikkala `A` va `B` dan ham katta bo'lsa, bu miqdordagi suvni ko'zalardan biriga sig'dirishning iloji yo'q.

## Algoritm qadamlari
1.  **Kirishni o'qish:** `A`, `B`, `C` butun sonlarini kirishdan o'qib olinadi.
2.  **Boshlang'ich tekshiruv:** Agar `C` miqdori `A` dan ham, `B` dan ham katta bo'lsa (`C > A && C > B`), u holda `C` litr suvni hech qaysi ko'zaga sig'dirib bo'lmaydi. Bunday holda "NO" javobi chiqariladi va keyingi test holatiga o'tiladi.
3.  **EKUBni hisoblash:** `A` va `B` sonlarining eng katta umumiy bo'luvchisi (`common_divisor = std::gcd(A, B)`) hisoblanadi. `std::gcd` funksiyasi C++17 standart kutubxonasida mavjud va Yevklid algoritmi yordamida EKUBni samarali hisoblaydi.
4.  **Bo'linishni tekshirish:** Agar `C` soni `common_divisor` ga qoldiqsiz bo'linsa (`C % common_divisor == 0`), bu `C` litr suvni hosil qilish mumkinligini anglatadi. Bunday holda "YES" javobi chiqariladi.
5.  **Aks holda:** Agar `C` soni `common_divisor` ga qoldiqsiz bo'linmasa, "NO" javobi chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(log(min(A, B)))`
    Har bir test holati uchun asosiy operatsiya `std::gcd(A, B)` ni hisoblashdir. Yevklid algoritmi `min(A, B)` sonining logarifmiga proporsional qadamlarda EKUBni topadi. `A` va `B` ning maksimal qiymati 1000 bo'lganligi sababli, `log(1000)` juda kichik son (taxminan 10). Jami `T` ta test holati bo'lgani uchun umumiy vaqt murakkabligi `T * O(log(min(A, B)))` bo'ladi. `100 * log(1000)` juda tez ishlaydi.
-   **Xotira murakkabligi**: `O(1)`
    Algoritm faqat bir nechta o'zgaruvchidan foydalanadi va qo'shimcha ma'lumot strukturalariga ehtiyoj sezmaydi. Shuning uchun xotira sarfi doimiy va kirish ma'lumotlari hajmiga bog'liq emas.
-   **Nega shu murakkablik chegaraga sig'adi**: Berilgan vaqt (1000 ms) va xotira (16 MB) chegaralari bu algoritm uchun juda keng. `O(log(min(A, B)))` vaqt murakkabligi va `O(1)` xotira murakkabligi eng tezkor va eng kam xotira talab qiladigan yechimlar qatoriga kiradi, shuning uchun masala chegaralarida muammosiz ishlaydi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi, shu jumladan <numeric> (gcd uchun)
using namespace std; // std nom fazosidan foydalanishni soddalashtiradi

void solve() { // Har bir test holati uchun ishlaydigan funksiya
    int A, B, C; // Ko'za hajmlari va maqsadli miqdor uchun o'zgaruvchilar
    cin >> A >> B >> C; // A, B, C ni kiritishdan o'qiymiz

    if (C > A && C > B) { // Maxsus holatni tekshirish: C ikkala ko'za hajmidan ham katta bo'lsa
        cout << "NO\n"; // Bu miqdorni hosil qilib bo'lmaydi
        return; // Funksiyadan chiqib, keyingi test holatiga o'tish
    }

    int common_divisor = std::gcd(A, B); // A va B ning EKUBini hisoblaymiz
                                        // std::gcd C++17 da <numeric> sarlavhasida joylashgan
                                        // <bits/stdc++.h> buni o'z ichiga oladi

    if (C % common_divisor == 0) { // Agar C EKUBga qoldiqsiz bo'linsa
        cout << "YES\n"; // Bu miqdorni hosil qilish mumkin
    } else { // Aks holda
        cout << "NO\n"; // Hosil qilish mumkin emas
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++ oqimlari (cin/cout) va C oqimlari (printf/scanf) orasidagi sinxronizatsiyani o'chiradi
                                      // Bu kirish/chiqish operatsiyalarini tezlashtiradi
    cin.tie(0); // cin operatsiyasidan keyin cout buferini tozalamaslikni buyuradi,
                // bu ham kirish/chiqishni tezlashtiradi

    int T; // Test holatlari soni
    cin >> T; // T ni kiritishdan o'qiymiz
    while (T--) { // Har bir test holati uchun takrorlash
        solve(); // solve funksiyasini chaqirish
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi
}
```

## Edge case lar va eslatmalar
*   **`C > A && C > B` holati:** Bu yechimdagi eng muhim edge case hisoblanadi. Agar maqsadli miqdor `C` ikkala ko'za hajmidan ham katta bo'lsa, u holda `C` litr suvni *hech qaysi* ko'zaga sig'dirishning iloji yo'q. Garchi Bézout ayniyati nazariy jihatdan `max(A, B)` dan katta miqdorlarni hosil qilish mumkinligini ko'rsatsa ham (masalan, 3 va 5 litr ko'za bilan 8 litrni hosil qilish mumkin, faqat u birorta ko'zada emas, balki "jami" bo'ladi), masala shartida "idishlardan birida C litr suvni hosil qilib bo'ladimi?" deyilgani uchun, `C` oxir-oqibat `A` yoki `B` hajmli ko'zalardan biriga joylanishi kerak. Shu sababli, agar `C > max(A, B)` bo'lsa, javob "NO" bo'ladi.
*   **`std::gcd` funksiyasi:** Bu funksiya C++17 standarti bilan qo'shilgan. Agar eskiroq kompilyator (masalan, C++14) ishlatilayotgan bo'lsa, `std::gcd` o'rniga o'z Yevklid algoritmi implementatsiyasini yozish kerak bo'ladi. Ko'pchilik zamonaviy onlayn hakamlar (Online Judge) C++17 yoki undan yangiroq standartni qo'llab-quvvatlaydi.
*   **`A` yoki `B` nol bo'lishi:** Masala shartiga ko'ra `1 <= A, B, C <= 1000`, shuning uchun `A` yoki `B` ning nol bo'lish holati haqida tashvishlanish shart emas.
*   **`A = B` holati:** Agar `A = B` bo'lsa, `std::gcd(A, A)` `A` ga teng bo'ladi. Agar `C` ham `A` ga teng bo'lsa (`C % A == 0`), "YES" chiqadi, bu to'g'ri. Agar `C` `A` dan farqli bo'lsa, `C % A != 0` bo'ladi va "NO" chiqadi, bu ham to'g'ri.
*   **`C <= 0` holati:** Masala shartiga ko'ra `1 <= C <= 1000`, shuning uchun `C` ning nol yoki manfiy bo'lish holatlari ham ko'rib chiqilmaydi.
---
---
---

## Fayllar

- [`solution.cpp`](./solution.cpp) — C++17 yechim kodi
- [`problem.md`](./problem.md) — masala matni va sample testlar
- [`meta.json`](./meta.json) — natija (vaqt, xotira, submission ID)

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/A0019) platformasidagi **A0019** raqamli **Ko'zalar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/A0019>
- Boshqa yechimlar: [Yechimlar indeksi](../)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest A0019, Ko'zalar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
