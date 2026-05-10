---
title: "M043C — Oshib borish | Robocontest.uz Yechimi"
description: "Robocontest.uz M043C (Oshib borish) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 16 MB."
keywords: "robocontest M043C, Oshib borish yechimi, robocontest Oshib borish, M043C c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# M043C — Oshib borish

## Masala haqida
Ushbu masalada bizga $N$ ta natural sonlardan iborat massiv beriladi. Bizdan shu massiv elementlarini qayta tartiblash orqali uni qat'iy o'suvchi (ya'ni, $a_1 < a_2 < \dots < a_n$ shartini qanoatlantiradigan) qilib tuzish mumkinmi yoki yo'qligini aniqlash so'raladi. Agar mumkin bo'lsa "YES", aks holda "NO" javobini chiqarish kerak.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi shundaki, agar massivni qat'iy o'suvchi ketma-ketlikka keltirish imkoni bo'lsa, u holda bu ketma-ketlikdagi barcha elementlar o'zaro noyob (unique) bo'lishi shart. Ya'ni, hech qaysi ikki element bir xil bo'lmasligi kerak. Agar massivda ikkita bir xil element (dublikat) mavjud bo'lsa, ularni qat'iy o'suvchi tartibda joylashtirib bo'lmaydi, chunki $a_i < a_{i+1}$ shartida $a_i = a_{i+1}$ bo'lishiga ruxsat berilmaydi.

Shu sababli, yechimning asosiy strategiyasi massivda dublikat (takrorlanuvchi) elementlar mavjudligini tekshirishdan iborat bo'ladi. Elementlarni osonroq tekshirish uchun massivni avval tartiblash (sort qilish) maqsadga muvofiqdir. Tartiblangan massivda yonma-yon joylashgan elementlar bir xil bo'lsa, bu dublikat borligini anglatadi.

## Algoritm qadamlari
1.  Har bir test holati uchun:
    *   Massivning uzunligi $N$ ni o'qib oling.
    *   $N$ ta elementdan iborat bo'lgan `a` massivini (yoki `vector`ini) e'lon qiling va uning elementlarini kirishdan o'qib oling.
2.  `a` massivini o'sish tartibida tartiblang (sort qiling). Buning uchun `std::sort` funksiyasidan foydalanish mumkin.
3.  `possible` nomli mantiqiy (boolean) o'zgaruvchini `true` deb boshlang'ich qiymat bering. Bu massivni qat'iy o'suvchi qilish mumkin deb faraz qilishimizni bildiradi.
4.  Tartiblangan massivning ikkinchi elementidan boshlab (ya'ni `i = 1` dan `N-1` gacha) for siklini aylantiring.
    *   Har bir `i` indeksida `a[i]` elementni o'zidan oldingi `a[i-1]` element bilan solishtiring.
    *   Agar `a[i] == a[i-1]` sharti to'g'ri bo'lsa, bu massivda dublikat borligini bildiradi. Bunday holda, `possible` o'zgaruvchini `false` ga o'rnating va siklni to'xtating (chunki bitta dublikat ham javobni "NO" qilish uchun yetarli).
5.  Sikl tugagandan so'ng, agar `possible` o'zgaruvchisi hali ham `true` bo'lsa, demak massivda dublikatlar yo'q va uni qat'iy o'suvchi qilib tartiblash mumkin. Bu holda "YES" javobini chiqaring.
6.  Aks holda, agar `possible` o'zgaruvchisi `false` bo'lsa, massivda dublikatlar bor va uni qat'iy o'suvchi qilib tartiblab bo'lmaydi. Bu holda "NO" javobini chiqaring.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: $O(N \log N)$
    *   Massivni o'qib olish $O(N)$ vaqt talab qiladi.
    *   `std::sort` funksiyasi massivni tartiblash uchun $O(N \log N)$ vaqt sarflaydi, bu yerda $N$ massiv elementlari soni.
    *   Tartiblangan massivni dublikatlar uchun tekshirish $O(N)$ vaqt talab qiladi, chunki biz massiv bo'ylab bir marta iteratsiya qilamiz.
    *   Shunday qilib, umumiy vaqt murakkabligi $O(N) + O(N \log N) + O(N) = O(N \log N)$ bo'ladi.
-   **Xotira murakkabligi**: $O(N)$
    *   `vector<int> a(n)` massivi $N$ ta butun sonni saqlash uchun $O(N)$ xotira talab qiladi.
    *   `std::sort` funksiyasi ko'p hollarda $O(\log N)$ yoki hatto $O(N)$ qo'shimcha xotira (yordamchi bo'shliq) ishlatishi mumkin, lekin zamonaviy implementatsiyalarda ko'pincha joyida (in-place) tartiblashga harakat qilinadi. Shuning uchun, amalda qo'shimcha xotira minimal bo'ladi, lekin eng yomon holatda $O(N)$ deb hisoblanishi mumkin.
    *   Umumiy xotira murakkabligi asosan massivning o'zi uchun $O(N)$ ni tashkil qiladi.
-   **Nega shu murakkablik chegaraga sig'adi**:
    Masala cheklovlari bo'yicha $N \le 100$ va $T \le 100$.
    Eng yomon holatda bitta test uchun $N=100$ bo'lsa, $N \log N \approx 100 \times \log_2(100) \approx 100 \times 6.64 \approx 664$ operatsiya. $T=100$ ta test uchun bu jami $100 \times 664 \approx 66400$ operatsiya demakdir. Zamonaviy kompyuterlar soniyasiga $10^8$ dan ortiq operatsiyani bajarishga qodir. Bu miqdordagi operatsiyalar berilgan 1000 ms vaqt limiti uchun juda tez hisoblanadi (amalda 2 ms da bajarilgan).
    Xotira jihatdan ham $N=100$ uchun $100 \times \text{sizeof(int)}$ (taxminan $100 \times 4$ bayt = 400 bayt) juda kichik, bu 16 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi, shu jumladan vector va algorithm (sort uchun)
using namespace std;     // std nomfazosidan foydalanishni osonlashtiradi

void solve() { // Har bir test holati uchun asosiy mantiqni o'z ichiga oluvchi funksiya
    int n;
    cin >> n; // Massiv uzunligini o'qish
    vector<int> a(n); // N o'lchamli integer (butun son) massivini e'lon qilish
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Massiv elementlarini o'qish
    }

    // An array can be rearranged to be strictly increasing if and only if
    // all its elements are unique. If there are duplicate elements,
    // it's impossible to satisfy the strict inequality condition.
    
    // Sort the array to easily check for duplicates.
    sort(a.begin(), a.end()); // Massivni o'sish tartibida tartiblaydi.

    bool possible = true; // Massivni qat'iy o'suvchi qilish mumkinligini ko'rsatuvchi flag. Boshida "mumkin" deb faraz qilinadi.
    for (int i = 1; i < n; ++i) { // Massivni boshidan oxirigacha aylanish (ikkinchi elementdan boshlab)
        if (a[i] == a[i-1]) { // Agar joriy element o'zidan oldingi elementga teng bo'lsa (dublikat topildi)
            possible = false; // Imkoniyat yo'q deb belgilaymiz
            break; // Siklni to'xtatamiz, chunki bitta dublikat ham yetarli
        }
    }

    if (possible) { // Agar `possible` hali ham `true` bo'lsa (dublikatlar topilmadi)
        cout << "YES\n"; // "YES" chiqarish
    } else { // Aks holda (dublikatlar topildi)
        cout << "NO\n"; // "NO" chiqarish
    }
}

int main() {
    // I/O operatsiyalarini tezlashtirish uchun standart C++ kodlari
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t; // Testlar sonini o'qish
    while (t--) { // Har bir test uchun `solve` funksiyasini chaqirish
        solve();
    }

    return 0; // Dasturning muvaffaqiyatli yakunlanganini bildirish
}
```

## Edge case lar va eslatmalar
*   **Massiv uzunligi $N=1$ bo'lgan holat**: Agar massivda faqat bitta element bo'lsa (masalan, `[5]`), uni har doim qat'iy o'suvchi ketma-ketlik deb hisoblash mumkin, chunki solishtirish uchun ikkinchi element yo'q. Algoritmimiz ham bu holatni to'g'ri boshqaradi: $N=1$ bo'lganda `for (int i = 1; i < n; ++i)` sikli hech qachon ishlamaydi, `possible` o'zgaruvchisi `true`ligicha qoladi va "YES" chiqariladi.
*   **Barcha elementlar bir xil bo'lgan holat**: Agar `n > 1` va barcha elementlar bir xil bo'lsa (masalan, `[1, 1, 1, 1]`), tartiblangandan keyin ham ular bir xil bo'ladi. Birinchi `a[i] == a[i-1]` tekshiruvda dublikat topiladi va "NO" chiqariladi, bu to'g'ri.
*   **Katta sonlar**: Massiv elementlari $10^9$ gacha bo'lishi mumkin. `int` ma'lumot turi C++ da odatda $2 \times 10^9$ gacha bo'lgan sonlarni saqlay oladi, shuning uchun bu qiymatlar `int` turiga sig'adi.
*   **I/O tezlashtirish**: `ios_base::sync_with_stdio(false); cin.tie(0);` qatorlari C++ dagi standart kirish-chiqish (I/O) operatsiyalarini tezlashtirish uchun ishlatiladi. Bu ayniqsa katta hajmdagi kirish ma'lumotlari (ko'p testlar yoki katta $N$) bo'lganda vaqt limitiga rioya qilishga yordam beradi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M043C) platformasidagi **M043C** raqamli **Oshib borish** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M043C>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M043C, Oshib borish yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
