---
title: "M074B — Daraxtdagi LIS | Robocontest.uz Yechimi"
description: "Robocontest.uz M074B (Daraxtdagi LIS) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 64 MB."
keywords: "robocontest M074B, Daraxtdagi LIS yechimi, robocontest Daraxtdagi LIS, M074B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M074B_daraxtdagi_lis/
lang: uz
---

# M074B — Daraxtdagi LIS

## Masala haqida
Bu masala N tugundan iborat daraxtda berilgan. Har bir `i` tugunning `a[i]` qiymati bor. Masalaning talabiga ko'ra, 1 dan N gacha bo'lgan har bir `k` tugun uchun, 1-tugundan `k`-tugungacha bo'lgan eng qisqa yo'ldagi tugun qiymatlaridan ketma-ketlik hosil qilinadi. Bizdan shu ketma-ketlikning eng uzun o'sib boruvchi pastki ketma-ketligi (LIS — Longest Increasing Subsequence) uzunligini topish talab qilinadi. Natijalar `N` qatorda, har bir `k` uchun alohida chop etilishi kerak.

## Yondashuv (g'oya)
Masalani yechish uchun chuqurlikka qarab qidirish (DFS - Depth-First Search) va dinamik dasturlash usulining LIS topish variantidan foydalanamiz. Asosiy g'oya — daraxt bo'ylab DFS orqali harakatlanar ekanmiz, hozirgi tugun (`u`) gacha bo'lgan yo'ldagi elementlardan tuzilgan LISni saqlab borish. Bu LIS "kichik oxirlar" usuli (O(N log N) murakkablikka ega) yordamida `LIS_tails` nomli vektor ichida saqlanadi. `LIS_tails` vektori ma'lum bir uzunlikdagi barcha o'suvchi pastki ketma-ketliklarning eng kichik oxirgi elementlarini o'z ichiga oladi va doimo o'suvchi tartibda bo'ladi.

Har bir tugunga kirganimizda, uning qiymatini `LIS_tails`ga qo'shamiz (yoki undagi mos elementni yangilaymiz) va shu yo'l uchun LIS uzunligini yozib olamiz. Tugundan chiqqanimizda (ya'ni, uning barcha avlodlari qayta ishlanib bo'lgach), `LIS_tails`ni tugunga kirishdan oldingi holatiga qaytarish juda muhim, chunki boshqa shoxlar (bir xil ota-onadan tarqalgan bolalar) uchun LIS hisob-kitoblari tugunning o'zgarishlaridan ta'sirlanmasligi kerak.

## Algoritm qadamlari

1.  **Ma'lumot tuzilmalarini initsializatsiya qilish**:
    *   `adj` massivi: Daraxtning yonma-yonlik (adjacency) ro'yxatini saqlaydi.
    *   `a` massivi: Har bir tugunning qiymatini saqlaydi.
    *   `ans` massivi: Har bir `k` tugun uchun topilgan LIS uzunligini saqlaydi.
    *   `LIS_tails` vektori: LISni hisoblash uchun ishlatiladigan asosiy ma'lumot tuzilmasi. Bu vektor doimo o'suvchi tartibda bo'ladi va undagi `LIS_tails[i]` element `i+1` uzunlikdagi o'suvchi pastki ketma-ketlikning eng kichik oxirgi elementini bildiradi.

2.  **DFS (Chuqurlikka qarab qidirish) funksiyasi (`dfs(u, p)`)**:
    *   `u`: Hozirgi tugun.
    *   `p`: `u` tugunining ota-onasi (DFSda ortga qaytishni oldini olish uchun).

3.  **`dfs(u, p)` ichida LISni yangilash**:
    *   `lower_bound(LIS_tails.begin(), LIS_tails.end(), a[u])`: `LIS_tails` vektorida `a[u]` qiymatidan kichik bo'lmagan birinchi elementning pozitsiyasini (iteratordan indeksni) topadi. Bu `a[u]` LISni kengaytirishi mumkin bo'lgan joyni aniqlaydi.
    *   `pos`: Yuqoridagi `lower_bound` natijasi.
    *   `original_val` va `pushed_back` o'zgaruvchilari orqaga qaytish (backtracking) uchun oldingi holatni saqlashga yordam beradi.
    *   **Holat 1**: Agar `pos == LIS_tails.size()` bo'lsa (ya'ni, `a[u]` `LIS_tails`dagi barcha elementlardan katta bo'lsa):
        *   `a[u]` ni `LIS_tails` vektorining oxiriga qo'shamiz (`push_back(a[u])`). Bu LIS uzunligini 1 ga oshiradi.
        *   `pushed_back = true` deb belgilaymiz.
    *   **Holat 2**: Agar `pos < LIS_tails.size()` bo'lsa (ya'ni, `a[u]` mavjud elementni almashtirishi mumkin bo'lsa):
        *   `LIS_tails[pos]` ni `original_val`ga saqlaymiz, chunki keyinchalik bu qiymatni tiklash kerak bo'ladi.
        *   `LIS_tails[pos]` ni `a[u]` ga almashtiramiz. Bu LIS uzunligini o'zgartirmaydi, lekin xuddi shu uzunlikdagi LIS uchun oxirgi elementni kichikroq (`a[u]`) qilish orqali kelajakda LISni yanada kengaytirish imkoniyatini oshiradi.
        *   `pushed_back = false` deb belgilaymiz.

4.  **Natijani saqlash**:
    *   `ans[u] = LIS_tails.size();`: Hozirgi `LIS_tails` vektorining uzunligi 1-tugundan `u`-tugungacha bo'lgan yo'ldagi LIS uzunligini bildiradi. Buni `ans[u]` ga saqlaymiz.

5.  **Rekursiv chaqiruvlar**:
    *   `u` tugunining har bir qo'shnisi `v` uchun, agar `v` ota-ona `p` ga teng bo'lmasa, `dfs(v, u)` funksiyasini chaqiramiz. Bu daraxtning chuqurlashishini ta'minlaydi.

6.  **Backtracking (Ortga qaytish)**:
    *   `u` tugunining barcha avlodlari qayta ishlanib, `dfs` chaqiruvlari qaytib kelganidan so'ng, `LIS_tails` vektorini `u` tuguniga kirishdan oldingi holatiga qaytaramiz:
        *   Agar `pushed_back` `true` bo'lgan bo'lsa, `LIS_tails` vektoridan oxirgi elementni o'chiramiz (`pop_back()`).
        *   Agar `pushed_back` `false` bo'lgan bo'lsa, `LIS_tails[pos]` elementini `original_val` ga tiklaymiz.

7.  **`main` funksiyasi**:
    *   Tez I/O ni yoqish.
    *   `N` ni o'qish.
    *   Tugun qiymatlarini `a` massiviga o'qish.
    *   `N-1` ta yo'lni o'qish va `adj` yonma-yonlik ro'yxatini to'ldirish.
    *   `dfs(1, 0)` ni chaqirish (1-tugun ildiz, 0 soxta ota-ona).
    *   `ans` massividagi natijalarni 1 dan `N` gacha chiqarish.

## Murakkablik tahlili
-   **Vaqt**: `O(N log N)`
    *   Har bir tugun (`N` ta) DFS orqali bir marta ko'rib chiqiladi.
    *   Har bir tugunni ko'rib chiqishda `lower_bound` operatsiyasi `LIS_tails` vektorida bajariladi. `LIS_tails` ning maksimal uzunligi `N` bo'lishi mumkin, shuning uchun `lower_bound` operatsiyasi `O(log N)` vaqt oladi.
    *   `push_back`, `pop_back` va elementlarni almashtirish operatsiyalari o'rtacha `O(1)` vaqt oladi.
    *   Shuning uchun umumiy vaqt murakkabligi `N` tugun uchun `N * O(log N) = O(N log N)` ni tashkil qiladi.
-   **Xotira**: `O(N)`
    *   `adj` massivi (yonma-yonlik ro'yxati) daraxt uchun `O(N)` xotira oladi.
    *   `a` massivi `O(N)` xotira oladi.
    *   `ans` massivi `O(N)` xotira oladi.
    *   `LIS_tails` vektori maksimal `N` elementni saqlashi mumkin, shuning uchun `O(N)` xotira oladi.
    *   DFS rekursiya steki eng yomon holatda (`N` chuqurlikdagi shoxchalar) `O(N)` xotira oladi.
    *   Jami xotira murakkabligi `O(N)` ni tashkil qiladi.

-   **Nega shu murakkablik chegaraga sig'adi**: `N` ning qiymati 2 \* 10^5 gacha bo'lishi mumkin. `O(N log N)` taxminan 2 \* 10^5 \* log(2 \* 10^5) ~ 2 \* 10^5 \* 18 ~ 3.6 \* 10^6 operatsiyaga teng. Bu 1000 ms (1 soniya) vaqt cheklovi uchun juda tez va bemalol sig'adi. Xotira `O(N)` (taxminan 2 \* 10^5 ta butun son ~ 0.8 MB) 64 MB chegarasidan ancha kam.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart kutubxonalarni o'z ichiga oladi (misol uchun, vector, algorithm, iostream)

using namespace std; // std nom fazosidan foydalanish

const int MAXN = 200005; // Maksimal tugunlar soni uchun konstanta, N=2*10^5 ga mo'ljallangan
vector<int> adj[MAXN];  // Yonma-yonlik ro'yxati (har bir tugun uchun qo'shnilari ro'yxati)
int a[MAXN];            // Tugunlarning qiymatlarini saqlaydi (a[i] i-tugunning qiymati)
int ans[MAXN];          // Har bir tugun uchun LIS uzunligini saqlaydi (ans[i] 1-i yo'lidagi LIS)
vector<int> LIS_tails;  // LISni hisoblash uchun "kichik oxirlar" vektorini saqlaydi
                        // Bu vektor doimo o'suvchi tartibda bo'ladi:
                        // LIS_tails[k] - (k+1) uzunlikdagi barcha LISlar ichidagi eng kichik oxirgi element
```

**`dfs` funksiyasi**: Daraxtni chuqurlikka qarab kezish va LISni hisoblash.

```cpp
void dfs(int u, int p) { // u: hozirgi tugun, p: u ning ota-onasi
    // lower_bound a[u] dan kichik bo'lmagan birinchi elementga iteratordan indeksni qaytaradi.
    // Bu, LIS_tails dagi a[u] ning o'rnini yoki qo'shiladigan joyini aniqlaydi.
    int pos = lower_bound(LIS_tails.begin(), LIS_tails.end(), a[u]) - LIS_tails.begin();
    
    int original_val = -1; // a[u] o'rniga qo'yilishi mumkin bo'lgan dastlabki qiymat
                           // (faqat agar mavjud element almashtirilsa ishlatiladi)
    bool pushed_back = false; // a[u] LISni kengaytirdimi (push_back qilinganmi) yoki yo'qmi
                              // (mavjud elementni almashtirganmi)

    if (pos == LIS_tails.size()) { // Agar a[u] LIS_tails dagi barcha elementlardan katta bo'lsa
                                   // Bu LISni yangi, uzunroq qilib kengaytiradi
        LIS_tails.push_back(a[u]); // a[u] ni vektorning oxiriga qo'shamiz
        pushed_back = true;        // Qo'shilganini belgilaymiz
    } else { // a[u] mavjud elementni almashtiradi, LIS uchun potensial "yaxshiroq" qator hosil qiladi
             // Bu LIS uzunligini o'zgartirmaydi, lekin keyingi elementlar uchun qulayroq holat yaratadi
        original_val = LIS_tails[pos]; // Orqaga qaytish (backtracking) uchun dastlabki qiymatni saqlash
        LIS_tails[pos] = a[u];         // Mavjud elementni a[u] ga almashtirish
    }

    ans[u] = LIS_tails.size(); // 1 dan u gacha bo'lgan yo'l uchun LIS uzunligi hozirgi LIS_tails.size() ga teng
                               // Buni ans massiviga saqlaymiz

    // Rekursiv chaqiruvlar: u tugunining barcha bolalarini kezish
    for (int v : adj[u]) { // u ning har bir qo'shnisi v uchun
        if (v == p) {      // Agar v ota-ona p bo'lsa, o'tkazib yuboramiz (daraxtda ortga qaytishni oldini olish)
            continue;
        }
        dfs(v, u); // v bolaga dfs ni chaqiramiz, u ni uning ota-onasi qilib
    }

    // Orqaga qaytish (backtracking): LIS_tails ni u tugunini qayta ishlashdan oldingi holatiga qaytarish
    // Bu boshqa shoxlarni to'g'ri qayta ishlash uchun muhim
    if (pushed_back) {         // Agar a[u] LIS_tails ga push_back qilingan bo'lsa
        LIS_tails.pop_back();  // Qo'shilgan elementni o'chirish
    } else {                   // Agar a[u] mavjud elementni almashtirgan bo'lsa
        LIS_tails[pos] = original_val; // 'pos' dagi dastlabki qiymatni tiklash
    }
}
```

**`main` funksiyasi**: Asosiy dastur mantig'i, kiritish/chiqarish va DFSni boshlash.

```cpp
int main() {
    ios_base::sync_with_stdio(false); // C++ standart I/O oqimlarini C I/O oqimlari bilan sinxronlashni o'chiradi
    cin.tie(0);                        // cin va cout o'rtasidagi bog'lanishni bekor qiladi, tezroq I/O uchun

    int N; // Tugunlar soni
    cin >> N; // N ni o'qish

    for (int i = 1; i <= N; ++i) { // Tugun qiymatlarini o'qish (1-indekslangan)
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; ++i) { // N-1 ta yo'lni (chegarani) o'qish
        int u, v; // Yo'lni tashkil etuvchi tugunlar
        cin >> u >> v; // u va v ni o'qish
        adj[u].push_back(v); // u dan v ga yo'l qo'shish
        adj[v].push_back(u); // v dan u ga yo'l qo'shish (ikki tomonlama yo'l, chunki daraxt)
    }

    dfs(1, 0); // 1-tugundan (ildiz) boshlab DFS ni chaqirish, 0 soxta ota-ona sifatida
               // (0 mavjud tugun raqami emas, shuning uchun p != v sharti buzilmaydi)

    for (int i = 1; i <= N; ++i) { // Har bir tugun uchun hisoblangan LIS uzunliklarini chop etish
        cout << ans[i] << "\n"; // ans[i] ni yangi qator bilan chop etish
    }

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
```

## Edge case lar va eslatmalar
*   **1-tugun ildiz**: Masala shartida har doim 1-tugundan `k`-tugungacha bo'lgan yo'l uchun LIS hisoblash so'ralgan. Kod 1-tugundan DFSni boshlash orqali buni qondiradi.
*   **Qiymatlar oralig'i**: `a_i` qiymatlari 1 dan 10^9 gacha bo'lishi mumkin. `int` ma'lumot turi bu oralig'ni bemalol saqlay oladi.
*   **1-indekslangan tugunlar**: Masala va kod tugunlarni 1-dan `N` gacha indekslaydi. Bu `a` va `adj` massivlari uchun `MAXN` hajmini to'g'ri belgilashni talab qiladi.
*   **`LIS_tails` tartibi**: `LIS_tails` vektori har doim o'suvchi tartibda saqlanadi, bu `lower_bound` funksiyasining to'g'ri ishlashi uchun zarur.
*   **Backtracking (Ortga qaytish)**: DFSda global holatni (bu yerda `LIS_tails`) o'zgartirganda, tugundan chiqishda uni oldingi holatiga qaytarish zarur. Bu, daraxtning turli shoxlarini bir-biridan mustaqil ravishda qayta ishlash imkonini beradi. Aks holda, bir shoxdagi o'zgarishlar boshqa shoxlarga noto'g'ri ta'sir qilishi mumkin.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M074B) platformasidagi **M074B** raqamli **Daraxtdagi LIS** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M074B>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M074B, Daraxtdagi LIS yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
