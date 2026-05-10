---
title: "M087B — Tik Tak Toe | Robocontest.uz Yechimi"
description: "Robocontest.uz M087B (Tik Tak Toe) masalasining C++17 yechimi va o'zbek tilida batafsil tushuntirishi. Kategoriya: Algoritm. Vaqt limiti: 1000 ms, xotira: 32 MB."
keywords: "robocontest M087B, Tik Tak Toe yechimi, robocontest Tik Tak Toe, M087B c++ kod, algoritm, robocontest.uz, robocontest yechimlari, c++17, olimpiada yechimi, algoritm"
permalink: /M087B_tik_tak_toe/
lang: uz
---

# M087B — Tik Tak Toe

## Masala haqida
Ushbu masala klassik Tik Tak Toe (X va O) o'yinining bir o'lchovli (bir chiziqli) variantini simulyatsiya qilishni talab qiladi. O'yin holati `x` (band joy) va `o` (bo'sh joy) belgilaridan tashkil topgan satr sifatida beriladi. Ikki o'yinchi navbati bilan harakat qiladi va har bir o'yinchi satrdagi eng chapdagi birinchi `o` belgisini `x` ga almashtiradi. Maqsad — o'z harakati natijasida uchta ketma-ket `x` ni hosil qilgan birinchi o'yinchi g'alaba qozonadi. Agar hech kim g'alaba qozona olmasa, o'yin durang (Hech kim) bilan yakunlanadi.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi — o'yinni boshlang'ich holatdan to yakunlangunga qadar qoidalarga muvofiq simulyatsiya qilish. Biz har bir o'yinchining navbatini ketma-ket bajarib boramiz, eng chapdagi bo'sh katakchani `x` ga aylantiramiz va har bir harakatdan so'ng o'yin holatini g'oliblikka tekshiramiz. Agar g'olib aniqlansa yoki bo'sh katakchalar qolmasa, simulyatsiyani to'xtatamiz va tegishli natijani chiqaramiz.

## Algoritm qadamlari
1.  **Boshlang'ich holatni o'qish**: O'yinning boshlang'ich holatini ifodalovchi satrni (string) qabul qilinadi.
2.  **O'yinchi navbatini kuzatish**: Kimning navbati ekanligini ko'rsatuvchi o'zgaruvchi (masalan, `current_player`, boshida 1-o'yinchi) aniqlanadi.
3.  **O'yin simulyatsiyasi**: O'yin g'olib aniqlangunga yoki bo'sh joylar tugagunga qadar takroriy siklda (loop) davom ettiriladi:
    a.  **Birinchi bo'sh joyni topish**: Joriy o'yin holatida (`string`) eng chapdagi birinchi `o` belgisining indeksini (o'rnini) topiladi.
    b.  **O'yin tugashini tekshirish (1)**: Agar satrda `o` belgisi topilmasa (ya'ni barcha kataklar band bo'lsa), demak o'yinda harakat qilish uchun joy qolmagan. Bunday holda, "Hech kim" deb chiqariladi va sikl tugatiladi.
    c.  **Harakatni bajarish**: Topilgan `o` belgisini `x` ga almashtirish orqali joriy o'yinchi harakati bajariladi.
    d.  **G'oliblikni tekshirish**: Harakat bajarilgandan so'ng, butun satrda ketma-ket uchta `x` bormi yo'qmi tekshiriladi. Bu maxsus `check_win` funksiyasi yordamida amalga oshiriladi.
    e.  **O'yin tugashini tekshirish (2)**: Agar `check_win` funksiyasi `true` (ha) qaytarsa, demak joriy o'yinchi o'z harakati bilan g'alaba qozongan. Kim g'olib bo'lganiga qarab "Birinchi" yoki "Ikkinchi" deb chiqariladi va sikl tugatiladi.
    f.  **Navbatni almashtirish**: Agar hech kim g'alaba qozonmagan bo'lsa, navbat keyingi o'yinchiga o'tkaziladi (1-o'yinchidan 2-o'yinchiga yoki aksincha).

## Murakkablik tahlili
-   **Vaqt murakkabligi**: O(`N^2`)
    -   `N` kirish satrining uzunligi bo'lsin.
    -   Har bir o'yinchi harakatida:
        -   `s.find('o')` operatsiyasi satrni boshidan oxirigacha ko'rib chiqishi mumkin, bu O(`N`) vaqt talab qiladi.
        -   `s[first_o_idx] = 'x'` operatsiyasi O(1) vaqt talab qiladi.
        -   `check_win(s)` funksiyasi ham butun satrni skanerlaydi, bu O(`N`) vaqt talab qiladi.
    -   Eng yomon holatda, satrda `N` ta `o` belgisi bo'lishi mumkin. Shunday qilib, o'yin sikli eng ko'pi `N` marta takrorlanishi mumkin.
    -   Har bir sikl ichida O(`N`) operatsiyalar bajarilgani sababli, umumiy vaqt murakkabligi `N * O(N) = O(N^2)` bo'ladi.
    -   Masala shartiga ko'ra, `N` ning maksimal qiymati 100 dan oshmaydi. `100^2 = 10000` operatsiya juda tez bajariladi va 1000 ms vaqt limiti uchun juda mos keladi.

-   **Xotira murakkabligi**: O(`N`)
    -   Faqa kirish satrini saqlash uchun xotira talab qilinadi. String uzunligi `N` bo'lgani uchun xotira murakkabligi O(`N`) dir.
    -   `N <= 100` bo'lgani uchun, bu juda kichik xotira hajmini (taxminan 100 bayt) anglatadi, 32 MB xotira limiti uchun yetarlidir.

## Kod izohi
Kodni asosiy qismlarga bo'lib tushuntiramiz:

### `check_win` funksiyasi
```cpp
bool check_win(const string& board) {
    for (int i = 0; i <= (int)board.length() - 3; ++i) {
        if (board[i] == 'x' && board[i+1] == 'x' && board[i+2] == 'x') {
            return true;
        }
    }
    return false;
}
```
*   Bu funksiya kirish sifatida `board` (o'yin holatini ifodalovchi `string`) ni qabul qiladi.
*   U satrning boshidan oxirigacha qarab chiqadi, lekin loop `board.length() - 3` gacha davom etadi. Buning sababi, biz har bir `i` pozitsiyasidan boshlab `i`, `i+1`, `i+2` indekslardagi belgilarni tekshiramiz. Agar `i` `board.length() - 3` dan katta bo'lsa, `i+2` indeks satrning chegarasidan tashqariga chiqib ketishi mumkin.
*   Agar ketma-ket uchta `x` (ya'ni `board[i] == 'x'`, `board[i+1] == 'x'` va `board[i+2] == 'x'`) topilsa, funksiya darhol `true` (ha) qaytaradi.
*   Agar sikl tugagunga qadar uchta ketma-ket `x` topilmasa, funksiya `false` (yo'q) qaytaradi.

### `main` funksiyasi
```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int current_player = 1; // 1 for "Birinchi", 2 for "Ikkinchi"

    while (true) {
        size_t first_o_idx = s.find('o');

        if (first_o_idx == string::npos) {
            // If no 'o's are found, the game cannot proceed or all moves have been made.
            // If no player won by their move, then "Hech kim" (No one).
            cout << "Hech kim\n";
            break;
        }

        // Current player makes a move: replaces the first 'o' with an 'x'.
        s[first_o_idx] = 'x';

        // Check if this move resulted in a win for the current player.
        if (check_win(s)) {
            if (current_player == 1) {
                cout << "Birinchi\n";
            } else { // current_player == 2
                cout << "Ikkinchi\n";
            }
            break; // Game ends, a player has won.
        }

        // Switch to the other player for the next turn.
        current_player = 3 - current_player; // Toggles between 1 and 2.
    }

    return 0;
}
```
*   `ios_base::sync_with_stdio(false); cin.tie(0);`: Bu qatorlar C++ da kirish/chiqish operatsiyalarini tezlashtirish uchun standart optimizatsiyalardir. Ular `cin` va `cout` ni C tilining `scanf`/`printf` funksiyalari bilan sinxronizatsiyasini o'chiradi va `cin` ning `cout` dan oldin bo'shatilishini bekor qiladi.
*   `string s; cin >> s;`: O'yinning boshlang'ich holati `s` nomli `string` o'zgaruvchisiga o'qib olinadi.
*   `int current_player = 1;`: Kimning navbati ekanligini kuzatish uchun `current_player` o'zgaruvchisi ishlatiladi. Dastlab 1-o'yinchining navbati.
*   `while (true)`: Bu o'yin tugagunga qadar cheksiz siklni boshlaydi. `break` operatori yordamida sikldan chiqiladi.
*   `size_t first_o_idx = s.find('o');`: `string::find` funksiyasi satrda birinchi `o` belgisini qidiradi va uning indeksini qaytaradi. Agar topilmasa, `string::npos` maxsus qiymatini qaytaradi.
*   `if (first_o_idx == string::npos)`: Agar `o` belgisi topilmasa, bu o'yinda bo'sh joy qolmaganini anglatadi. "Hech kim" deb chiqariladi va sikl tugatiladi.
*   `s[first_o_idx] = 'x';`: Topilgan `o` indeksidagi belgini `x` ga o'zgartirish orqali joriy o'yinchi harakati amalga oshiriladi.
*   `if (check_win(s))`: Harakatdan so'ng `check_win` funksiyasi chaqiriladi. Agar `true` qaytarsa, joriy o'yinchi g'olib bo'lgan.
*   G'olib aniqlangach, `current_player` qiymatiga qarab "Birinchi" yoki "Ikkinchi" chiqariladi va sikl tugatiladi.
*   `current_player = 3 - current_player;`: Agar hech kim g'alaba qozonmagan bo'lsa, navbat keyingi o'yinchiga o'tkaziladi. Bu formula `1` ni `2` ga, `2` ni `1` ga o'zgartirishning qulay usulidir.

## Edge case lar va eslatmalar
*   **Bo'sh joy yo'qligi**: Agar boshlang'ich satrda umuman `o` belgisi bo'lmasa (masalan, "xxxxxxx"), `s.find('o')` darhol `string::npos` qaytaradi va dastur "Hech kim" deb chiqarib tugaydi. Bu to'g'ri.
*   **Qisqa satrlar**: Agar kirish satrining uzunligi 3 dan kam bo'lsa (masalan, "xo", "xx"), `check_win` funksiyasining sikli (`i <= (int)board.length() - 3`) ishlamaydi va `false` qaytaradi, chunki uchta ketma-ket `x` hosil qilish imkonsiz. Bu ham to'g'ri.
*   **Boshida allaqachon uchta 'x' mavjud bo'lsa**: Masalan, "xxoxxx". Birinchi o'yinchi birinchi `o` ni almashtiradi (masalan, "xxxoxx" bo'ladi). Shundan so'ng `check_win` funksiyasi tekshirib, g'olibni topadi ("Birinchi" o'yinchi g'alaba qozonadi), chunki masala sharti "Kimda birinchi bo'lib 3 ta ketma-ket x hosil bo'lsa o'sha g'olib bo'ladi" deydi, bu o'z harakati natijasida hosil bo'lishini anglatadi.
---

## Robocontest haqida ko'proq

Bu masala — [Robocontest.uz](https://robocontest.uz/tasks/M087B) platformasidagi **M087B** raqamli **Tik Tak Toe** masalasi. U **algoritm** kategoriyasiga kiradi va C++17 da yechilgan.

- Asl masala havolasi: <https://robocontest.uz/tasks/M087B>
- Boshqa yechimlar: [INDEX.md](../INDEX.md)
- Repo: [Robocontest-javoblari](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari)

<sub>**Kalit so'zlar**: robocontest M087B, Tik Tak Toe yechimi, robocontest masalalari, c++17, olimpiada yechimi, algoritm, dasturlash uzbek, competitive programming O'zbekiston.</sub>
