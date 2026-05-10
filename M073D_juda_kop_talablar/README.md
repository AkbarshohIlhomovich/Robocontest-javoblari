---
title: "M073D — Juda ko'p talablar | Robocontest.uz Yechimi"
description: "Robocontest.uz M073D (Juda ko'p talablar) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M073D, Juda ko'p talablar yechimi, robocontest Juda ko'p talablar, M073D c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
lang: uz
---

# M073D — Juda ko'p talablar

## Masala haqida
Bu masala `N` ta butun sondan iborat `A` ketma-ketligini topishni talab qiladi. `A` ketma-ketligi qat'iy o'smaydigan (non-decreasing) bo'lishi kerak, ya'ni `1 <= A_1 <= A_2 <= ... <= A_N <= M` shartni qanoatlantirishi lozim. Berilgan `Q` ta talabdan (har biri `(a_i, b_i, c_i, d_i)` to'rtligi) foydalanib, `A` ketma-ketligi uchun maksimal natijani (score) topish kerak. Natija, `A[b_i] - A[a_i] = c_i` shartni qanoatlantiruvchi barcha `d_i` larning yig'indisi sifatida hisoblanadi.

## Yondashuv (g'oya)
Masalaning asosiy cheklovlari (`N <= 10`, `M <= 10`) juda kichik bo'lib, bu barcha mumkin bo'lgan `A` ketma-ketliklarini tekshirishga imkon beradigan brut-kuch (brute-force) yoki qaytarma (backtracking) yondashuvini qo'llash mumkinligini ko'rsatadi. `A` ketma-ketligi o'smaydigan bo'lishi kerakligi sababli, biz rekursiv funksiya yordamida qidirishni optimallashtirishimiz mumkin. Har bir `A_i` elementi uchun avvalgi element `A_{i-1}` dan kichik bo'lmagan qiymatlarni tanlab boramiz.

## Algoritm qadamlari
Algoritm rekursiv funksiya yordamida `A` ketma-ketligini elementma-element quradi:

1.  **Global o'zgaruvchilar**:
    *   `N, M, Q`: masala parametrlari.
    *   `queries`: barcha `(a_i, b_i, c_i, d_i)` talablarni saqlaydigan `tuple` vektor (massivi).
    *   `current_A`: hozirda shakllantirilayotgan `A` ketma-ketligini saqlaydigan `int` vektor.
    *   `max_score`: topilgan maksimal natijani saqlaydigan `long long` o'zgaruvchi. Dastlab `0` ga teng.

2.  **`solve(index, prev_val)` rekursiv funksiyasi**:
    *   `index`: `A` ketma-ketligining hozirda qaysi elementini (0 dan `N-1` gacha) to'ldirayotganimizni bildiradi.
    *   `prev_val`: `A[index]` uchun tanlanishi mumkin bo'lgan minimal qiymat. Bu `A` ketma-ketligining o'smaydigan xususiyatini ta'minlaydi.

3.  **Baza holat (Base case)**:
    *   Agar `index == N` bo'lsa, bu degani `A` ketma-ketligi to'liq shakllantirilgan.
    *   `current_score` nomli `long long` o'zgaruvchi `0` ga tenglab olinadi.
    *   `queries` massivi bo'ylab takroriy tsikl yuritiladi. Har bir `(a, b, c, d)` talab uchun:
        *   Agar `current_A[b-1] - current_A[a-1] == c` shart bajarilsa (eslatma: masala 1-indeksli hisoblaydi, C++ 0-indeksli, shuning uchun `b-1` va `a-1` ishlatiladi), `current_score` ga `d` qo'shiladi.
    *   `max_score` `max(max_score, current_score)` yordamida yangilanadi.
    *   Funksiya tugaydi (return).

4.  **Rekursiv qadam (Recursive step)**:
    *   `val` `prev_val` dan `M` gacha bo'lgan barcha mumkin bo'lgan qiymatlar bo'ylab tsikl yuritiladi.
    *   `current_A[index] = val` o'rnatiladi.
    *   `solve(index + 1, val)` rekursiv chaqiruvi amalga oshiriladi. Keyingi elementni to'ldirish uchun, minimal qiymat `val` bo'ladi, chunki `A_i` `A_{i-1}` dan kichik bo'lmasligi kerak.

5.  **`main` funksiyasi**:
    *   Tezroq kiritish/chiqarish (I/O) uchun `ios_base::sync_with_stdio(false); cin.tie(0);` ishlatiladi.
    *   `N, M, Q` kiritiladi.
    *   `current_A` vektori `N` o'lchamda o'lchamlashtiriladi (resize).
    *   `queries` vektori `Q` ta talab bilan to'ldiriladi.
    *   `solve(0, 1)` chaqiriladi. Bu `A` ketma-ketligining 0-indeksli elementini to'ldirishni boshlaydi, va `A_0` uchun minimal qiymat 1 bo'ladi.
    *   Yakuniy `max_score` ekranga chiqariladi.

## Murakkablik tahlili
-   **Vaqt**: `O( (M+N-1 choose N) * Q )`
    *   `N` va `M` juda kichik bo'lganligi sababli (maksimal 10), bizning rekursiv funksiyamiz `A` ketma-ketligining barcha mumkin bo'lgan o'smaydigan variantlarini yaratadi. `1` dan `M` gacha bo'lgan `N` ta sondan takrorlashga ruxsat berilgan holda o'smaydigan ketma-ketliklar soni kombinatorikada "kombinatsiyalar takrorlash bilan" deb ataladi va uning formulasi $\binom{M+N-1}{N}$ ga teng.
    *   `N=10` va `M=10` bo'lganda, bu $\binom{10+10-1}{10} = \binom{19}{10} = 92378$ ta ketma-ketlikni tashkil qiladi.
    *   Har bir to'liq `A` ketma-ketligi uchun `Q` ta talab tekshiriladi. `Q` ning maksimal qiymati 50.
    *   Umumiy vaqt murakkabligi: $92378 \times 50 \approx 4.6 \times 10^6$ operatsiya. Bu 1 soniya (taxminan $10^8$ operatsiya) vaqt limiti ichida juda yaxshi sig'adi.

-   **Xotira**: `O(N + Q)`
    *   `current_A` vektori `N` ta `int` saqlaydi (`O(N)`).
    *   `queries` vektori `Q` ta `tuple` saqlaydi (`O(Q)`).
    *   Rekursiya stekining chuqurligi `N` ga teng (`O(N)`).
    *   Umumiy xotira `N=10` va `Q=50` bo'lganda juda kichik (taxminan `10*sizeof(int) + 50*sizeof(tuple) + 10*sizeof(stack_frame)`), bu 32 MB xotira limitiga bemalol sig'adi.

-   **Nega shu murakkablik chegaraga sig'adi**: Yuqorida ko'rsatilgan hisob-kitoblar shuni ko'rsatadiki, maksimal `N` va `M` qiymatlarida ham operatsiyalar soni millionlab, ya'ni tipik competitive programming muhitida 1 soniyada bajariladigan operatsiyalar sonidan ancha kam. Xotira talabi ham minimal.

## Kod izohi
### Global o'zgaruvchilar va `main` funksiyasi
```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi
using namespace std;

int N, M, Q; // Masala parametrlari: ketma-ketlik uzunligi, maksimal qiymat, talablar soni
vector<tuple<int, int, int, int>> queries; // Har bir talabni (a, b, c, d) tuple sifatida saqlaydi
vector<int> current_A; // Hozirda shakllantirilayotgan A ketma-ketligi
long long max_score = 0; // Topilgan maksimal natija, long long int haddan oshmasligi uchun
```
Bu qismda `N`, `M`, `Q` butun sonlari, `queries` (talablar) va `current_A` (joriy A ketma-ketligi) vektorlari e'lon qilinadi. `max_score` esa `long long` turida e'lon qilinadi, chunki umumiy natija int chegarasidan oshib ketishi mumkin (garchi bu masala uchun `int` ham yetarli bo'lsa-da, bu xavfsizroq yondashuv).

### `solve` rekursiv funksiyasi
```cpp
void solve(int index, int prev_val) {
    if (index == N) { // Baza holat: A ketma-ketligi to'liq shakllantirilgan
        long long current_score = 0; // Joriy ketma-ketlik uchun ballni hisoblaymiz
        for (const auto& q_tuple : queries) { // Barcha talablar bo'ylab iteratsiya
            int a = get<0>(q_tuple); // tuple dan a qiymatini olish
            int b = get<1>(q_tuple); // tuple dan b qiymatini olish
            int c = get<2>(q_tuple); // tuple dan c qiymatini olish
            int d = get<3>(q_tuple); // tuple dan d qiymatini olish

            // Agar A[b-1] - A[a-1] == c shart bajarilsa (0-indeksli hisoblash)
            if (current_A[b - 1] - current_A[a - 1] == c) {
                current_score += d; // Ballga d ni qo'shamiz
            }
        }
        max_score = max(max_score, current_score); // Maksimal ballni yangilaymiz
        return; // Rekursiya tugaydi
    }

    // Rekursiv qadam: A ketma-ketligining keyingi elementini tanlash
    for (int val = prev_val; val <= M; ++val) { // prev_val dan M gacha bo'lgan qiymatlarni sinab ko'ramiz
        current_A[index] = val; // Joriy elementga qiymatni tayinlaymiz
        solve(index + 1, val); // Keyingi elementni to'ldirish uchun rekursiv chaqiruv
    }
}
```
`solve` funksiyasi `A` ketma-ketligini rekursiv ravishda hosil qiladi.
*   **`index == N` holati**: Bu `A` ketma-ketligi `N` ta elementdan iborat bo'lib, to'liq shakllantirilganligini bildiradi. Shu holatda, `queries` vektoridagi barcha talablar tekshiriladi. Agar `A[b-1] - A[a-1] == c` sharti bajarilsa, `d` qiymati `current_score` ga qo'shiladi. Nihoyat, `max_score` topilgan `current_score` bilan solishtirilib, kattasi tanlanadi.
*   **`for (int val = prev_val; val <= M; ++val)` tsikli**: Bu tsikl `current_A[index]` elementiga `prev_val` dan `M` gacha bo'lgan har bir mumkin bo'lgan qiymatni tanlash imkonini beradi. `prev_val` qiymati `A` ketma-ketligining o'smaydigan xususiyatini ta'minlaydi (`A_i >= A_{i-1}`). Har bir tanlangan `val` uchun `solve` funksiyasi `index + 1` (keyingi element) va `val` (keyingi element uchun minimal qiymat) bilan rekursiv tarzda chaqiriladi.

### `main` funksiyasining qolgan qismi
```cpp
int main() {
    ios_base::sync_with_stdio(false); // C++ standart I/O streamlarini C standart I/O bilan sinxronizatsiyani o'chiradi
    cin.tie(0); // cin va cout o'rtasidagi bog'lanishni o'chiradi, I/O operatsiyalarini tezlashtiradi

    cin >> N >> M >> Q; // N, M, Q ni kiritamiz

    current_A.resize(N); // current_A vektorini N o'lchamga keltiramiz
    queries.reserve(Q); // queries vektorini Q sig'imga rezerv qilamiz (majburiy emas, lekin samaraliroq bo'lishi mumkin)

    for (int i = 0; i < Q; ++i) { // Q ta talabni kiritamiz
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries.emplace_back(a, b, c, d); // Talabni tuple sifatida vektorga qo'shamiz
    }

    solve(0, 1); // Rekursiyani boshlaymiz: 0-indeksli elementdan boshlab, minimal qiymat 1 bilan

    cout << max_score << endl; // Yakuniy maksimal ballni chiqaramiz

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
```
`main` funksiyasi dasturning kirish nuqtasidir. U kirish ma'lumotlarini o'qiydi, zaruriy ma'lumot tuzilmalarini (masalan, `current_A` va `queries`) tayyorlaydi va `solve` rekursiv funksiyasini chaqirib, jarayonni boshlaydi. Nihoyat, u hisoblangan maksimal natijani chiqaradi. `ios_base::sync_with_stdio(false);` va `cin.tie(0);` qatorlari katta kirish/chiqish hajmlari bo'lgan musobaqa dasturlarida samaradorlikni oshirish uchun standart amaliyotdir.

## Edge case lar va eslatmalar
*   **1-indeksdan 0-indeksga o'tish**: Masala matnida `a_i` va `b_i` 1-indeksli hisoblanadi (ya'ni `A_1`, `A_2`...). C++ vektorlari esa 0-indeksli. Shuning uchun kodda `current_A[b-1]` va `current_A[a-1]` ishlatilganligiga diqqat qiling.
*   **`long long` ishlatish**: `d_i` qiymati $10^5$ gacha, `Q` esa 50 gacha bo'lishi mumkin. Bu degani, umumiy natija $50 \times 10^5 = 5 \times 10^6$ gacha yetishi mumkin. `int` tipining maksimal qiymati taxminan $2 \times 10^9$ bo'lganligi sababli, bu masala uchun `int` tipi ham yetarli bo'lardi. Biroq, `long long` dan foydalanish har doim katta yig'indilarni hisoblashda xavfsizlikni ta'minlaydi va yaxshi amaliyot hisoblanadi.
*   **`prev_val` ning muhimligi**: `solve(index + 1, val)` rekursiv chaqiruvida `val` ning ikkinchi parametr sifatida berilishi juda muhimdir. Bu `A` ketma-ketligining `A_k >= A_{k-1}` shartni qanoatlantirishini ta'minlaydi, ya'ni ketma-ketlik o'smaydigan (non-decreasing) bo'ladi.
*   **Kichik cheklovlar**: `N` va `M` uchun kichik cheklovlar (maksimal 10) bunday brut-kuch/qaytarma yechimning samarali bo'lishiga imkon beradi. Agar bu cheklovlar katta bo'lganida, boshqa (masalan, dinamik dasturlash kabi) yondashuvlar kerak bo'lar edi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M073D) platformasidagi **M073D** raqamli **Juda ko'p talablar** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M073D>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M073D, Juda ko'p talablar yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
