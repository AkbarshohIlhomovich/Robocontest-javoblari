# M069K — Qo'yxona

## Masala haqida
Bu masalada cho'ponning `N` ta qo'yxonasi borligi aytiladi, ular 1 dan `N` gacha raqamlangan. Har bir qo'yxonaning kaliti boshqa bir qo'yxonada joylashgan. Qo'yxonaning eshigi yopiq bo'lsa, uning kalitini olish uchun devordan oshib o'tish (buzish) kerak bo'ladi. Masala barcha qo'ylarni chiqarish uchun eng kamida nechta devor oshish kerakligini topishni talab qiladi.

## Yondashuv (g'oya)
Masalani graf nazariyasi nuqtai nazaridan ko'rib chiqish mumkin. Har bir qo'yxona grafning tuguni (node), va `i`-qo'yxonaning kaliti `j`-qo'yxonada joylashgani `i` tugundan `j` tugunga yo'naltirilgan chekka (edge) mavjudligini bildiradi. Har bir tugundan faqat bitta chiqish chekkasi (out-degree = 1) mavjud bo'lgan bunday graf "funksional graf" (functional graph) deb ataladi.

Funksional grafning har bir komponenti (bog'langan qismi) bitta sikl (cycle) va shu siklga olib boruvchi daraxtlardan (trees) iborat bo'ladi. Barcha qo'yxonalarni ochish uchun, agar qo'yxonalar zanjir hosil qilsa (masalan, A kaliti B da, B kaliti C da, C kaliti A da bo'lsa), bu zanjirni ochish uchun kamida bitta qo'yxonaning devoridan oshib o'tish kerak bo'ladi. Bir devordan o'tib, kalitni olgach, sikldagi qolgan qo'yxonalarni birin-ketin ochish mumkin. Shuning uchun, barcha qo'yxonalarni ochish uchun zarur bo'lgan minimal devor oshishlar soni funksional grafdagi mustaqil sikllar soniga tengdir.

Yechimning asosiy g'oyasi – grafdagi barcha sikllar sonini topish uchun chuqurlik bo'yicha qidirish (DFS - Depth-First Search) algoritmining o'zgartirilgan versiyasidan foydalanishdir.

## Algoritm qadamlari
1.  **Grafni qurish:** `N` qo'yxonalar sonini o'qing. `adj` nomli massiv (yoki `std::vector`) yordamida grafni ifodalang, bunda `adj[i]` qiymati `i`-qo'yxonaning kaliti joylashgan qo'yxona raqamini ko'rsatadi. Qo'yxonalar 1 dan `N` gacha raqamlanganligi sababli, massiv 1-indekslangan bo'ladi (ya'ni, `N+1` o'lchamda e'lon qilinadi).
2.  **Holatni kuzatish uchun massiv:** `color` nomli massivni yarating. Bu massiv har bir tugunning (qo'yxonaning) hozirgi holatini saqlaydi:
    *   `color[u] = 0`: `u` tuguniga hali tashrif buyurilmagan.
    *   `color[u] = 1`: `u` tuguni hozirgi DFS qidirish yo'lida (ya'ni, rekursiv chaqiruvlar stekida).
    *   `color[u] = 2`: `u` tuguniga tashrif buyurilgan va uning komponentasi to'liq tekshirilgan.
    Dastlab barcha `color` qiymatlari `0` ga o'rnatiladi.
3.  **Sikl hisoblagich:** `cycles_count` nomli o'zgaruvchini `0` ga initsializatsiya qiling. Bu topilgan sikllar sonini saqlaydi.
4.  **Tugunlar bo'ylab iteratsiya:** `i = 1` dan `N` gacha har bir tugun (qo'yxona) uchun takrorlang.
5.  **DFS boshlash:** Agar `color[i]` `0` bo'lsa (ya'ni, `i`-tugun hali tashrif buyurilmagan bo'lsa), yangi komponentni tekshirishni boshlang:
    *   `current_node = i` dan boshlang.
    *   `path` nomli `std::vector` yarating. Bu hozirgi yo'lda bo'lgan tugunlarni saqlaydi va siklni aniqlashda yordam beradi.
6.  **Yo'l bo'ylab harakatlanish:** `current_node` dan boshlab, toki `color[current_node]` `0` bo'lmaguncha quyidagi qadamlarni bajaring:
    *   `color[current_node]` ni `1` ga o'rnating (bu tugun hozirgi yo'lda ekanligini bildiradi).
    *   `current_node` ni `path` vektoriga qo'shing.
    *   `current_node` ni `adj[current_node]` ga o'zgartiring (kalit joylashgan keyingi qo'yxonaga o'ting).
7.  **Sikl aniqlash:** `while` siklidan chiqqaningizda, bu `current_node` ning `color` qiymati `0` emasligini bildiradi:
    *   Agar `color[current_node]` `1` ga teng bo'lsa, bu degani siz hozirgi DFS yo'lida bo'lgan tugunga qaytib keldingiz, ya'ni sikl topildi! `cycles_count` ni bittaga oshiring.
    *   Agar `color[current_node]` `2` ga teng bo'lsa, bu degani siz ilgari tekshirilgan boshqa bir komponentaga qo'shildingiz, yangi sikl mavjud emas.
8.  **Yo'ldagi tugunlarni belgilash:** `path` vektoridagi barcha tugunlarning `color` qiymatini `2` ga o'rnating. Bu, ushbu tugunlarning komponentasi to'liq tekshirilganligini bildiradi va ularni keyingi iteratsiyalarda qayta ishlashdan saqlaydi.
9.  **Natijani chop etish:** `cycles_count` ni ekranga chiqaring.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(N)`. Algoritm har bir tugunga va har bir chekkaga (kalit joylashuvi) faqat bir marta tashrif buyuradi. Har bir tugundan bir marta DFS boshlanadi, va ichki `while` sikli har bir tugunni faqat bir marta `color=0` dan `color=1` ga o'zgartiradi. So'ngra `color=1` dan `color=2` ga o'zgarishi ham bir martalik operatsiya. Shunday qilib, umumiy operatsiyalar soni tugunlar soniga proporsionaldir.
-   **Xotira murakkabligi**: `O(N)`.
    *   `adj` vektori `N+1` butun sonni saqlaydi.
    *   `color` vektori `N+1` butun sonni saqlaydi.
    *   `path` vektori eng yomon holatda `N` ta tugunni saqlashi mumkin (agar butun graf bitta katta sikl yoki bitta tugundan boshlanib uzun yo'l bo'lsa).
-   **Nega shu murakkablik chegaraga sig'adi**: `N` ning qiymati `10^6` gacha bo'lgani uchun, `O(N)` vaqt murakkabligi juda samarali hisoblanadi (taxminan `10^6` ta operatsiya, bu 2000 ms vaqt limiti ichida bemalol sig'adi). `O(N)` xotira murakkabligi ham `10^6` ta butun son uchun taxminan 4MB atrofida xotira talab qiladi, bu 256 MB xotira limiti ichida muammosiz sig'adi.

## Kod izohi
```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun
#include <vector>   // Dinamik massivlar (vektorlar) uchun
#include <numeric>  // Ba'zi hollarda foydali, bu yechimda to'g'ridan-to'g'ri ishlatilmagan

int main() {
    // Kirish/chiqish operatsiyalarini tezlashtirish.
    // C++ oqimlarini C standart I/O funksiyalari bilan sinxronizatsiyasini o'chiradi
    // va cin ning cout bilan bog'lanishini bekor qiladi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N; // Qo'yxonalar soni
    std::cin >> N; // N ni o'qish

    // adj vektori, har bir qo'yxona kaliti qaysi qo'yxonada joylashganini saqlaydi.
    // 1-indekslangan qo'yxonalar uchun N+1 o'lchamda e'lon qilingan.
    std::vector<int> adj(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> adj[i]; // i-qo'yxona kaliti joylashgan qo'yxona raqamini o'qish
    }

    // color vektori har bir tugun holatini (0: tashrif buyurilmagan, 1: hozirgi yo'lda, 2: tashrif buyurilgan) saqlaydi.
    // Dastlab barchasi 0 (tashrif buyurilmagan) ga o'rnatilgan.
    std::vector<int> color(N + 1, 0); 
    int cycles_count = 0; // Topilgan sikllar soni

    // Har bir qo'yxona (tugun) bo'ylab iteratsiya qilish.
    for (int i = 1; i <= N; ++i) {
        // Agar tugunga hali tashrif buyurilmagan bo'lsa (0 holatida), yangi komponentni tekshirishni boshla.
        if (color[i] == 0) {
            int current_node = i; // Hozirgi tugunni belgilash
            std::vector<int> path; // Hozirgi DFS yo'lidagi tugunlarni saqlash uchun vektor

            // current_node dan boshlab yo'l bo'ylab harakatlanish, toki tashrif buyurilmagan tugun tugaguncha.
            while (color[current_node] == 0) {
                color[current_node] = 1; // Tugunni "hozirgi yo'lda" deb belgilash
                path.push_back(current_node); // Yo'lga qo'shish
                current_node = adj[current_node]; // Keyingi tugunga o'tish (kalit joylashgan qo'yxona)
            }

            // while siklidan chiqqandan so'ng, current_node ning color qiymati 0 emas.
            // Agar color[current_node] == 1 bo'lsa, bu sikl topilganini bildiradi,
            // chunki biz hozirgi qidiruv yo'limizdagi tugunga qaytib keldik.
            if (color[current_node] == 1) {
                cycles_count++; // Sikl hisobini oshirish
            }
            
            // Hozirgi komponentadagi barcha tugunlarni "tashrif buyurilgan va ishlov berilgan" deb belgilash.
            // Bu ularni boshqa iteratsiyalarda qayta tekshirishdan saqlaydi.
            for (int node : path) {
                color[node] = 2;
            }
        }
    }

    // Jami topilgan sikllar sonini chop etish.
    std::cout << cycles_count << std::endl;

    return 0; // Dasturni muvaffaqiyatli yakunlash
}

```

## Edge case lar va eslatmalar
*   **O'z-o'ziga ishora qiluvchi sikllar (Self-loops):** Agar `i`-qo'yxonaning kaliti aynan `i`-qo'yxonada joylashgan bo'lsa (`adj[i] == i`), bu bitta tugundan iborat sikl hisoblanadi. Algoritm buni to'g'ri aniqlaydi va `cycles_count` ni bittaga oshiradi.
*   **Bog'lanmagan komponentlar:** Algoritmning tashqi `for` sikli barcha tugunlarni qamrab olganligi sababli, u grafning barcha bog'lanmagan komponentlarini avtomatik ravishda tekshiradi va har bir komponentdagi sikllarni hisobga oladi.
*   **Massiv indeksatsiyasi:** C++ da `std::vector`lar odatda 0-indekslangan bo'ladi. Masalada qo'yxonalar 1 dan `N` gacha raqamlanganligi sababli, kodda massivlar `N+1` o'lchamda e'lon qilingan va 1-indekslangan holda ishlatilgan. Bu noqulaylikni oldini oladi va masalaning shartiga mos keladi.
*   **Vaqt va xotira optimallashlari:** `std::ios_base::sync_with_stdio(false); std::cin.tie(0);` qatorlari katta kirish ma'lumotlari (input) bilan ishlashda C++ oqimlarining ish faoliyatini sezilarli darajada oshiradi, bu `N = 10^6` kabi katta qiymatlar uchun muhim ahamiyatga ega.
