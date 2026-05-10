---
title: "M069G — Good binary tree | Robocontest.uz Yechimi"
description: "Robocontest.uz M069G (Good binary tree) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M069G, Good binary tree yechimi, robocontest Good binary tree, M069G c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M069G_good_binary_tree/
lang: uz
---

# M069G — Good binary tree

## Masala haqida
Bu masala bizga "Good Binary Tree" ni, uning barglarining chapdan o'ngga qarab berilgan balandliklari asosida qayta tiklashni talab qiladi. "To'liq ikkilik daraxt" (Full binary tree) har bir tugunning 0 yoki 2 ta bolasi bo'lgan va tugunlari 1 dan K gacha raqamlangan daraxtdir. "Good Binary Tree" esa qo'shimcha ikkita xususiyatga ega:
1. Har bir tugun o'z bolalaridan kichik raqamga ega (masalan, yuqoridagi rasmdagi 1-tugun 2 va 5-tugunlardan kichik).
2. Har bir tugun uchun, uning chap qismdaraxtidagi eng katta tugun raqami, o'ng qismdaraxtidagi eng kichik tugun raqamidan kichikdir (masalan, 1-tugun uchun, uning chap qismdaraxtidagi (2, 3, 4) tugunlarning maksimali (4) o'ng qismdaraxtidagi (5, 6, 7, 8, 9, 10, 11, 12, 13) tugunlarning minimalidan (5) kichik).
Kirish sifatida N ta barg balandliklari (chapdan o'ngga tartiblangan) beriladi. Chiqishda daraxtdagi umumiy tugunlar soni (K) va har bir tugunning otasi (ildiz tugunining otasi 0 deb olinadi) chop etilishi kerak.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi – daraxtni barglarning balandliklari ma'lumotlari asosida qurishdir. "Good Binary Tree" ning ikkinchi sharti (chap qismdaraxtdagi tugunlar raqami o'ng qismdaraxtdagi tugunlar raqamidan kichik) tugunlarga ketma-ket raqam berishimiz mumkinligini ko'rsatadi: birinchi chap qismdaraxt to'liq quriladi va raqamlanadi, so'ngra o'ng qismdaraxt quriladi va raqamlanadi. Bu yondashuv chuqurlik bo'yicha qidiruv (Depth First Search - DFS) bilan mos keladi.

Biz iterativ DFS dan foydalanamiz, buning uchun `std::stack` ma'lumot tuzilmasi kerak bo'ladi. Stekda har bir tugun uchun uning identifikatori (ID), chuqurligi (depth) va holati (state) saqlanadi. Holat, shu tugunning chap bolasi bilan ishlayotganimizni yoki o'ng bolasi bilan ishlayotganimizni bildiradi.

Algoritmning asosiy mantig'i: hozirgi tugunning keyingi (chap yoki o'ng) bolasi joylashishi kerak bo'lgan chuqurlikni (ya'ni, `curr_depth + 1`) kirishdagi navbatdagi bargning balandligi (`H[current_leaf_idx]`) bilan solishtirish.
- Agar `curr_depth + 1` **teng** `H[current_leaf_idx]` bo'lsa, bu degani, biz qurayotgan bola **barg** tugunidir. Biz unga yangi ID beramiz, ota-onasini bog'laymiz va `current_leaf_idx` ni keyingi bargga o'tkazamiz.
- Agar `curr_depth + 1` **kichik** `H[current_leaf_idx]` bo'lsa, bu degani, biz qurayotgan bola **ichki** tugun bo'lishi kerak, chunki navbatdagi barg undan ham pastroqda joylashgan. Biz unga yangi ID beramiz, ota-onasini bog'laymiz va keyin bu yangi ichki tugunni stekka qo'shamiz (yoki rekursiv chaqiramiz) uning o'z qismdaraxtini qurishni boshlash uchun.

Barcha tugunlarga IDlar 1 dan boshlab ketma-ket beriladi. Ildiz tugun har doim 1-IDga ega bo'ladi.

## Algoritm qadamlari
1.  **Dastlabki sozlash:**
    *   `parents` (ota-onalar) massivini yaratamiz. Bu massiv `parents[i]` i-tugunning otasi ID'sini saqlaydi. Massivning hajmi `2 * N + 1` qilib belgilanadi, chunki eng yomon holatda daraxtda `2 * N - 1` tagacha tugun bo'lishi mumkin va tugun ID'lari 1 dan boshlanadi.
    *   `next_node_id = 1` deb boshlanadi. Bu o'zgaruvchi keyingi yaratiladigan tugunga beriladigan ID ni kuzatib boradi.
    *   `current_leaf_idx = 0` deb boshlanadi. Bu kirishdagi `H` massividagi navbatdagi bargning balandligiga ishora qiluvchi indeks.
    *   `std::stack<std::tuple<int, int, int>> s;` (`s` stekini) e'lon qilamiz. Har bir tuple (`node_id`, `depth`, `state`) ma'lumotlarini saqlaydi. `state` (holat) 0 bo'lsa, bu tugunning chap bolasi qurilishi kerak; 1 bo'lsa, o'ng bolasi qurilishi kerak.
2.  **Ildiz tugunini yaratish:**
    *   `root_node_id = next_node_id++` orqali ildiz tuguniga 1-ID beramiz.
    *   `parents[root_node_id] = 0` deb belgilaymiz, chunki ildiz tugunining otasi yo'q.
    *   Ildizni stekka joylashtiramiz: `s.push({root_node_id, 0, 0})`. Bu 0 chuqurlikdagi ildiz tuguni va uning chap bolasi qurilishi kerakligini bildiradi.
3.  **Daraxtni qurish (stek bo'sh bo'lmaguncha):**
    *   Stekning tepasidagi elementni olamiz: `auto& [curr_node_id, curr_depth, state] = s.top();`. Bu `#include <tuple>` va C++17 ning "structured binding" xususiyati orqali stekdagi elementni to'g'ridan-to'g'ri o'zgartirishga imkon beradi.
    *   **Agar `state == 0` bo'lsa (chap bolani qurish):**
        *   Navbatdagi bola chuqurligini (`curr_depth + 1`) `H[current_leaf_idx]` bilan solishtiramiz.
        *   **Agar `curr_depth + 1 == H[current_leaf_idx]` bo'lsa:**
            *   Chap bola barg tugunidir. Unga `next_node_id++` orqali yangi ID beramiz.
            *   `parents[yangi_bola_id] = curr_node_id` deb ota-onani bog'laymiz.
            *   `current_leaf_idx` ni keyingi bargga o'tkazamiz.
            *   Joriy tugun (`curr_node_id`) holatini `state = 1` ga o'zgartiramiz, chunki uning chap bolasi qurilib bo'ldi va endi o'ng bolasi qurilishi kerak.
        *   **Aks holda (`curr_depth + 1 < H[current_leaf_idx]`):**
            *   Chap bola ichki tugundir. Unga `next_node_id++` orqali yangi ID beramiz.
            *   `parents[yangi_bola_id] = curr_node_id` deb ota-onani bog'laymiz.
            *   Joriy tugun (`curr_node_id`) holatini `state = 1` ga o'zgartiramiz.
            *   Yangi chap bolani stekka `s.push({yangi_bola_id, curr_depth + 1, 0})` deb joylashtiramiz, uning o'z qismdaraxtini (chap boladan boshlab) qurish uchun.
    *   **Agar `state == 1` bo'lsa (o'ng bolani qurish):**
        *   Navbatdagi bola chuqurligini (`curr_depth + 1`) `H[current_leaf_idx]` bilan solishtiramiz.
        *   **Agar `curr_depth + 1 == H[current_leaf_idx]` bo'lsa:**
            *   O'ng bola barg tugunidir. Unga `next_node_id++` orqali yangi ID beramiz.
            *   `parents[yangi_bola_id] = curr_node_id` deb ota-onani bog'laymiz.
            *   `current_leaf_idx` ni keyingi bargga o'tkazamiz.
            *   Joriy tugun (`curr_node_id`) ikkala bolasini ham qurib bo'lgani uchun, uni stekdan olib tashlaymiz (`s.pop()`).
        *   **Aks holda (`curr_depth + 1 < H[current_leaf_idx]`):**
            *   O'ng bola ichki tugundir. Unga `next_node_id++` orqali yangi ID beramiz.
            *   `parents[yangi_bola_id] = curr_node_id` deb ota-onani bog'laymiz.
            *   Joriy tugun (`curr_node_id`) ikkala bolasini ham qurib bo'lgani uchun, uni stekdan olib tashlaymiz (`s.pop()`).
            *   Yangi o'ng bolani stekka `s.push({yangi_bola_id, curr_depth + 1, 0})` deb joylashtiramiz, uning o'z qismdaraxtini (chap boladan boshlab) qurish uchun.
4.  **Natijani chop etish:**
    *   Daraxtdagi jami tugunlar sonini (`next_node_id - 1`) chop etamiz. `next_node_id` oxirgi tugunga ID berilgandan so'ng yana bir marta oshirilgani uchun 1 ni ayirish kerak.
    *   `parents` massividagi 1 dan `next_node_id - 1` gacha bo'lgan barcha tugunlarning ota-onalarini chop etamiz.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(K)` yoki `O(N)`. Bu yerda `K` daraxtdagi umumiy tugunlar soni, maksimal `2N-1` ga teng bo'lishi mumkin. Algoritm har bir tugunni stekka bir marta joylashtiradi va bir marta chiqaradi. Har bir stek operatsiyasi va tugun yaratish `O(1)` vaqt oladi. Shuning uchun umumiy vaqt murakkabligi daraxtdagi tugunlar soniga proportsionaldir, ya'ni `O(K)`. `K` `N` ga bog'liq bo'lganligi sababli, bu `O(N)` deb ham ifodalanishi mumkin.
-   **Xotira murakkabligi**: `O(K)` yoki `O(N)`. `parents` massivi `K` ta butun sonni saqlash uchun `O(K)` xotira talab qiladi. `std::stack` esa eng yomon holatda (masalan, bir tomonlama qiyshiq daraxtda) `O(K)` elementni saqlashi mumkin, chunki stekning maksimal hajmi daraxtning balandligiga teng bo'ladi, bu ham `K` ga yetishi mumkin. Shuning uchun umumiy xotira murakkabligi `O(K)` yoki `O(N)` dir.

-   **Nega shu murakkablik chegaraga sig'adi?**
    *   `N` maksimal `50,000` bo'lishi mumkin. Bu degani `K` maksimal `2 * 50,000 - 1 = 99,999` bo'ladi.
    *   `O(N)` vaqt murakkabligi `50,000` ga yaqin operatsiyani bildiradi. Zamonaviy kompyuterlar soniyasiga o'n millionlab operatsiyalarni bajara oladi, shuning uchun `10^5` ga yaqin operatsiya `1000 ms` vaqt limiti ichida juda tez (taxminan bir necha millisekundda) bajariladi. Amaliy natija (18 ms) buni tasdiqlaydi.
    *   `O(N)` xotira murakkabligi `100,000` ta `int` (butun son) massivi uchun taxminan `100,000 * 4 byte = 400 KB` xotira talab qiladi. Stek ham shunga yaqin xotira egallashi mumkin. Bu `32 MB` (32,768 KB) xotira limiti uchun juda kichikdir. Amaliy natija (96 KB) buni tasdiqlaydi.

## Kod izohi
*   **Sarlavhalar va optimizatsiyalar:**
    *   `#include <iostream>`, `#include <vector>`, `#include <stack>`, `#include <tuple>`: Standart kirish/chiqish, dinamik massivlar, stek ma'lumot tuzilmasi va tuple (bir nechta qiymatni birlashtirish) uchun kerakli sarlavhalar.
    *   `std::ios_base::sync_with_stdio(false); std::cin.tie(0);`: C++ standart kirish/chiqish oqimlarini C standarti bilan sinxronizatsiyasini o'chiradi va `cin` ning `cout` bilan bog'liqligini bekor qiladi. Bu katta miqdordagi kiritish/chiqarish operatsiyalari uchun dasturning tezligini oshiradi.
*   **Kiritish ma'lumotlarini o'qish:**
    *   `int N; std::cin >> N;`: Barglar soni `N` o'qib olinadi.
    *   `std::vector<int> H(N);`: `N` ta elementdan iborat `H` vektori (dinamik massivi) e'lon qilinadi, u barglarning balandliklarini saqlaydi.
    *   `for (int i = 0; i < N; ++i) { std::cin >> H[i]; }`: Barg balandliklari o'qib olinadi.
*   **`parents` massivi va hisoblagichlar:**
    *   `std::vector<int> parents(2 * N + 1);`: Tugunlarning ota-onalarini saqlash uchun `parents` vektori e'lon qilinadi. Tugun ID'lari 1 dan boshlanadi, shuning uchun `2*N+1` o'lcham etarli bo'ladi.
    *   `int next_node_id = 1;`: Yangi tugunlarga beriladigan navbatdagi ID.
    *   `int current_leaf_idx = 0;`: `H` massividagi keyingi ishlov beriladigan bargning indeksini kuzatib boradi.
*   **Stek e'lon qilish:**
    *   `std::stack<std::tuple<int, int, int>> s;`: Stek tugun IDsi, uning chuqurligi va holatini (chap yoki o'ng bolani qurish kerakligini) saqlaydi.
*   **Ildiz tugunini yaratish:**
    *   `int root_node_id = next_node_id++;`: Ildizga 1-ID beriladi.
    *   `parents[root_node_id] = 0;`: Ildizning otasi 0 deb belgilanadi.
    *   `s.push({root_node_id, 0, 0});`: Ildiz stekka joylashtiriladi (chuqurlik 0, holat 0 - chap bolani qurishga tayyor).
*   **Asosiy daraxt qurish tsikli:**
    *   `while (!s.empty()) { ... }`: Stek bo'sh bo'lmaguncha davom etadi.
    *   `auto& [curr_node_id, curr_depth, state] = s.top();`: Stekning tepasidagi tugun ma'lumotlari olinadi va `state` o'zgaruvchisiga to'g'ridan-to'g'ri murojaat qilish uchun referans sifatida ishlatiladi.
    *   **Chap bola holati (`if (state == 0)`)**:
        *   `if (curr_depth + 1 == H[current_leaf_idx])`: Agar keyingi chuqurlik navbatdagi barg balandligiga teng bo'lsa, chap bola bargdir. Yangi ID beriladi, `parents` yoziladi, `current_leaf_idx` oshiriladi, va holat `state = 1` ga o'zgaradi (o'ng bolani qurishga tayyor).
        *   `else`: Agar keyingi chuqurlik navbatdagi barg balandligidan kichik bo'lsa, chap bola ichki tugundir. Yangi ID beriladi, `parents` yoziladi, holat `state = 1` ga o'zgaradi va yangi chap bola o'z qismdaraxtini qurish uchun stekka `state=0` bilan joylashtiriladi.
    *   **O'ng bola holati (`else { // state == 1 }`)**:
        *   `if (curr_depth + 1 == H[current_leaf_idx])`: Agar keyingi chuqurlik navbatdagi barg balandligiga teng bo'lsa, o'ng bola bargdir. Yangi ID beriladi, `parents` yoziladi, `current_leaf_idx` oshiriladi, va `curr_node_id` tuguni stekdan chiqariladi, chunki uning ikkala bolasi ham qurildi.
        *   `else`: Agar keyingi chuqurlik navbatdagi barg balandligidan kichik bo'lsa, o'ng bola ichki tugundir. Yangi ID beriladi, `parents` yoziladi, `curr_node_id` tuguni stekdan chiqariladi, va yangi o'ng bola o'z qismdaraxtini qurish uchun stekka `state=0` bilan joylashtiriladi.
*   **Natijani chop etish:**
    *   `std::cout << next_node_id - 1 << std::endl;`: Jami tugunlar soni chop etiladi.
    *   `for (int i = 1; i < next_node_id; ++i) { ... }`: 1 dan `K` gacha bo'lgan tugunlarning ota-onalari massivdan olinib, bo'sh joy bilan ajratib chop etiladi.

## Edge case lar va eslatmalar
*   **Minimal `N` (barglar soni) 2 ga teng:** Masala shartida `2 <= N <= 50000` ekanligi aytilgan. Bu shuni anglatadiki, daraxtda har doim kamida bitta ildiz va uning ikkita barg bolasi bo'ladi (chuqurliklari 1, 1). Bu holat umumiy algoritm tomonidan to'g'ri ishlanadi.
*   **`current_leaf_idx` ning boshqarilishi:** Bu indeks har safar kirishdagi barg balandligiga mos keladigan barg tugun yaratilganda to'g'ri oshirilishi juda muhim.
*   **Tugun ID'larining ketma-ketligi:** Algoritm tugunlarga 1 dan boshlab ketma-ket ID'lar beradi. "Good Binary Tree" ning shartlari (ota bolalaridan kichik va chap qismdaraxt o'ng qismdaraxtdan kichik ID'larga ega) shu ketma-ket raqamlash usulini qo'llab-quvvatlaydi, chunki biz daraxtni chapdan o'ngga qarab qurib boramiz va har doim yangi, eng kichik mavjud ID ni beramiz.
*   **`std::stack` va `std::tuple` ning ishlatilishi:** Bu yondashuv rekursiv DFS ni iterativ shaklga aylantirish uchun standart usul hisoblanadi. `std::tuple` bir nechta turli xil ma'lumotlarni bitta obyektda saqlash uchun qulay, `auto& [ ... ] = s.top();` esa C++17 xususiyati bo'lib, stekning tepasidagi tuple a'zolarini osonlikcha o'zgartirish imkonini beradi.
*   **Javobning mavjudligi kafolati:** Masala matnida har doim javob mavjudligi kafolatlanadi. Bu bizni noto'g'ri kirish ma'lumotlari yoki hech qanday daraxt qurib bo'lmaydigan holatlar haqida tashvishlanishdan xalos qiladi.
---
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M069G) platformasidagi **M069G** raqamli **Good binary tree** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M069G>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M069G, Good binary tree yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
