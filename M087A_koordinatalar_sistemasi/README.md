# M087A — Koordinatalar sistemasi

## Masala haqida
Bu masalada Ali, Vali va G'ani ismli uchta o'yinchi ishtirok etadi. Ularga uch o'lchamli fazoda $N$ ta nuqta berilgan. Har bir o'yinchi ma'lum bir koordinata o'qini tanlaydi: Ali X o'qini, Vali Y o'qini va G'ani Z o'qini tanlaydi. Keyin har bir o'yinchi barcha $N$ ta nuqtani o'zi tanlagan o'qqa proyeksiyalaydi (ya'ni, perpendikulyar tushiradi) va shu o'qda hosil bo'lgan turli (noyob) nuqtalar sonini hisoblaydi. Kim eng ko'p turli nuqtaga ega bo'lsa, o'sha o'yinchi g'olib hisoblanadi. Agar bir nechta o'yinchi bir xil maksimal ball olsa, ularning barchasi g'olib bo'ladi.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi har bir o'yinchi uchun noyob koordinatalar sonini samarali hisoblash va keyin bu sonlarni solishtirishdan iborat.
1.  **Noyob elementlarni hisoblash**: Har bir o'yinchi uchun mos keladigan koordinatalarni (Ali uchun $x$, Vali uchun $y$, G'ani uchun $z$) saqlash va ularning orasidan faqat noyoblarini sanash kerak. C++ tilidagi `std::set` (to'plam) ma'lumot tuzilmasi aynan shu vazifa uchun juda qulay: u elementlarni avtomatik ravishda tartibda saqlaydi va bir xil elementlarni ikki marta qo'shishga yo'l qo'ymaydi. Shunday qilib, `set`ga barcha koordinatalarni kiritgandan so'ng, uning o'lchami (ya'ni `size()`) noyob koordinatalar sonini beradi.
2.  **G'olibni aniqlash**: Uchala o'yinchining noyob koordinatalar sonini hisoblagandan so'ng, bu qiymatlar orasidan maksimalini topish kerak. Keyin esa, kimning bali shu maksimal qiymatga teng bo'lsa, o'sha o'yinchi g'olib deb e'lon qilinadi.

## Algoritm qadamlari
1.  Kirish ma'lumotlaridan `N` (nuqtalar soni) ni o'qing.
2.  Uchta `std::set<int>` (butun sonlar to'plami) yarating:
    *   `ali_coords`: Ali ning X o'qi bo'yicha noyob koordinatalarini saqlash uchun.
    *   `vali_coords`: Vali ning Y o'qi bo'yicha noyob koordinatalarini saqlash uchun.
    *   `gani_coords`: G'ani ning Z o'qi bo'yicha noyob koordinatalarini saqlash uchun.
3.  `N` marta takrorlanadigan sikl (loop) boshlang:
    a.  Siklning har bir iteratsiyasida, navbatdagi nuqtaning $x, y, z$ koordinatalarini o'qing.
    b.  `x` koordinatasini `ali_coords` to'plamiga `insert()` (kiritish) qiling.
    c.  `y` koordinatasini `vali_coords` to'plamiga `insert()` qiling.
    d.  `z` koordinatasini `gani_coords` to'plamiga `insert()` qiling. `set`ning xususiyati tufayli, agar kiritilayotgan koordinata allaqachon to'plamda mavjud bo'lsa, u qayta kiritilmaydi.
4.  Sikl tugagandan so'ng, har bir o'yinchining balini hisoblang:
    a.  `ali_score = ali_coords.size()`
    b.  `vali_score = vali_coords.size()`
    c.  `gani_score = gani_coords.size()`
5.  Uchala ball orasidan eng katta (maksimal) ballni toping: `max_score = max(ali_score, max(vali_score, gani_score))`.
6.  Natijalarni chop etish:
    a.  Agar `ali_score` `max_score` ga teng bo'lsa, "Ali" ni chop eting.
    b.  Agar `vali_score` `max_score` ga teng bo'lsa, "Vali" ni chop eting.
    c.  Agar `gani_score` `max_score` ga teng bo'lsa, "G'ani" ni chop eting. E'tibor bering, har bir shart alohida `if` bilan tekshiriladi, bu bir nechta g'olibni chiqarishga imkon beradi.

## Murakkablik tahlili
*   **Vaqt murakkabligi**: $O(N \cdot \log C)$
    *   `N` ta nuqtani qayta ishlaymiz.
    *   Har bir nuqta uchun uchta `std::set` ga `insert()` operatsiyasini bajaramiz.
    *   `std::set` ga element qo'shish $O(\log k)$ vaqt oladi, bu yerda $k$ `set`dagi elementlar soni.
    *   Koordinatalar qiymati $-100$ dan $100$ gacha, shuning uchun eng ko'pi bilan $201$ ta turli koordinata mavjud bo'lishi mumkin. Ya'ni, $k \le C = 201$.
    *   Shunday qilib, har bir nuqta uchun uchta `insert()` operatsiyasi jami $O(\log C)$ vaqt oladi.
    *   Natijada, umumiy vaqt murakkabligi $N$ ta nuqta uchun $O(N \cdot \log C)$ bo'ladi.
    *   `N=100` va `log C` (`log 201` taxminan $8$ ga teng) bo'lgani sababli, $100 \cdot 8$ operatsiya juda tez bajariladi va vaqt limiti (1000 ms) ichiga bemalol sig'adi.

*   **Xotira murakkabligi**: $O(C)$
    *   Har bir `std::set` eng ko'pi bilan `C` (ya'ni 201) ta noyob koordinata qiymatini saqlashi mumkin.
    *   Uchta `set` ishlatilgani uchun umumiy xotira $3 \cdot C \cdot \text{sizeof(int)}$ bo'ladi.
    *   Bu juda kichik qiymat ($3 \cdot 201 \cdot 4$ bayt $\approx 2.4$ KB) va 32 MB xotira limitiga bemalol sig'adi. Amalda, $C$ doimiy kichik son bo'lgani uchun, xotira murakkabligini $O(1)$ (doimiy) deb ham baholash mumkin.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Barcha standart kutubxonalarni o'z ichiga oladi.
                         // set ma'lumot tuzilmasi uchun kerak.

using namespace std; // std:: old qo'shimchasini yozmaslik uchun nomlar makonidan foydalanamiz.

int main() {
    // Tez kirish/chiqish (I/O) uchun optimizatsiyalar.
    // stdio kutubxonasi bilan C++ iostream sinxronizatsiyasini o'chiradi.
    ios_base::sync_with_stdio(false);
    // cin va cout o'rtasidagi bog'lanishni bekor qiladi, bu ham tezlikni oshiradi.
    cin.tie(0);

    int n; // Nuqtalar sonini saqlash uchun o'zgaruvchi.
    cin >> n; // N qiymatini kiritish.

    // Har bir o'yinchi uchun noyob koordinatalarni saqlash uchun set (to'plam) e'lon qilish.
    // set avtomatik ravishda dublikatlarni o'chira oladi.
    set<int> ali_coords;   // Ali ning X koordinatalari
    set<int> vali_coords;  // Vali ning Y koordinatalari
    set<int> gani_coords;  // G'ani ning Z koordinatalari

    // N ta nuqtani o'qish va ularning koordinatalarini tegishli setlarga kiritish.
    for (int i = 0; i < n; ++i) {
        int x, y, z; // Har bir nuqtaning x, y, z koordinatalari.
        cin >> x >> y >> z; // Koordinatalarni o'qish.

        // Koordinatalarni tegishli setlarga kiritish.
        // Agar koordinata allaqachon setda mavjud bo'lsa, set uni qayta qo'shmaydi.
        ali_coords.insert(x);
        vali_coords.insert(y);
        gani_coords.insert(z);
    }

    // Har bir o'yinchining noyob koordinatalar sonini (ballini) hisoblash.
    // set.size() funksiyasi setdagi elementlar sonini qaytaradi, bu esa noyob elementlar sonidir.
    int ali_score = ali_coords.size();
    int vali_score = vali_coords.size();
    int gani_score = gani_coords.size();

    // Uchala o'yinchi orasidagi maksimal ballni topish.
    int max_score = 0;
    max_score = max(max_score, ali_score); // Ali balli bilan solishtiramiz.
    max_score = max(max_score, vali_score); // Vali balli bilan solishtiramiz.
    max_score = max(max_score, gani_score); // G'ani balli bilan solishtiramiz.

    // Kim g'olib bo'lganini aniqlash va chop etish.
    // Har bir shart alohida if bilan tekshiriladi, bu bir nechta g'olibni chiqarishga imkon beradi.
    if (ali_score == max_score) {
        cout << "Ali\n"; // Ali g'olib bo'lsa ismini chop etish.
    }
    if (vali_score == max_score) {
        cout << "Vali\n"; // Vali g'olib bo'lsa ismini chop etish.
    }
    if (gani_score == max_score) {
        cout << "G'ani\n"; // G'ani g'olib bo'lsa ismini chop etish.
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Minimal $N$ qiymati ($N=1$)**: Agar faqat bitta nuqta berilsa (masalan, `5 3 1`), Ali $x=5$, Vali $y=3$, G'ani $z=1$ koordinatalarini oladi. Har birining `set`ida bittadan element bo'ladi, shuning uchun barchasi 1 ball oladi va uchalasi ham g'olib deb e'lon qilinadi. Kod bu holatni to'g'ri boshqaradi.
*   **Barcha nuqtalar bir xil bo'lsa**: Agar barcha $N$ ta nuqta bir xil koordinatalarga ega bo'lsa, har bir o'yinchining `set`ida faqat bitta noyob koordinata bo'ladi. Natijada, barchasi 1 ball oladi va uchalasi ham g'olib bo'ladi. Bu ham to'g'ri ishlaydi.
*   **Koordinatalar diapazoni**: Koordinatalar `[-100, 100]` oralig'ida joylashgan. `std::set<int>` bu butun son qiymatlarini muammosiz saqlay oladi va performance jihatidan hech qanday muammo tug'dirmaydi.
*   **Bir nechta g'oliblar**: Masala shartiga ko'ra, agar bir nechta o'yinchi eng yuqori ballga ega bo'lsa, ularning barchasi g'olib hisoblanadi. Kodda g'oliblarni chiqarish uchun alohida `if` shartlaridan foydalanilgan, bu esa bir nechta ismni chop etishga imkon beradi (masalan, Ali va Vali g'olib bo'lsa, ikkisining ham ismi chiqariladi).
*   **Kiritish/chiqish (I/O) optimizatsiyasi**: `ios_base::sync_with_stdio(false); cin.tie(0);` qatorlari odatda competitive programmingda C++ `cin`/`cout` funksiyalarining tezligini oshirish uchun ishlatiladi. Bu kichik `N` va `C` qiymatlari uchun unchalik muhim bo'lmasa-da, katta kirish ma'lumotlari bo'lganda dasturning vaqt chegarasiga sig'ishiga yordam beradi.
