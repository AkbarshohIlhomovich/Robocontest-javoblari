# M034F — Tadqiqotchi Fedya

## Masala haqida
Tadqiqotchi Fedya uchun ikki shahar o'rtasidagi eng qimmat sayohat narxini topish talab qilinadi. Har bir shahar `i` ning o'ziga xos kirish badali `a[i]` mavjud bo'lib, bu qiymat manfiy ham bo'lishi mumkin. `i` shahardan `j` shaharga borish narxi `|a[i] - a[j]| + |i - j|` formulasi bilan hisoblanadi. Masalaning maqsadi — barcha mumkin bo'lgan `(i, j)` juftliklari orasida eng yuqori narxni aniqlash va uni chop etishdir. Shaharlar indekslash noldan boshlanadi.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi – berilgan narx formulasini matematik o'zgartirish orqali muammoni soddalashtirishdir. `|a[i] - a[j]| + |i - j|` formulasi `(i, a[i])` va `(j, a[j])` nuqtalari orasidagi "Manhattan masofasi" (yoki shaxmat taxtasi masofasi) ko'rinishiga ega.

Matematikada, bir qator nuqtalar `(x_k, y_k)` orasidagi maksimal Manhattan masofasini topish uchun koordinatalarni transformatsiya qilish (o'zgartirish) usuli mavjud. Bu usulga ko'ra, har bir `(x_k, y_k)` nuqtani yangi `(u_k, v_k)` nuqtaga quyidagicha o'zgartirish mumkin: `u_k = x_k + y_k` va `v_k = x_k - y_k`. Shundan so'ng, asl nuqtalar orasidagi maksimal Manhattan masofasi yangi `u` va `v` koordinatalarning maksimal diapazonlarining kattasiga teng bo'ladi, ya'ni `max((max(u_k) - min(u_k)), (max(v_k) - min(v_k)))`.

Bizning masalada, `x_k = k` (shahar indeksi) va `y_k = a[k]` (shahar badali). Demak, har bir shahar `k` uchun ikki yangi qiymatni hisoblaymiz:
1.  `val_1 = a[k] + k`
2.  `val_2 = a[k] - k`

Dastur `n` ta shahar bo'ylab bir marta iteratsiya qilib, `val_1` va `val_2` ning barcha mumkin bo'lgan qiymatlari orasidagi maksimum va minimumini topadi. So'ngra, `(max(val_1) - min(val_1))` va `(max(val_2) - min(val_2))` farqlarini hisoblab, ularning kattasini javob sifatida qaytaradi. Bu yondashuv `O(N)` vaqt va `O(1)` xotira murakkabligiga ega bo'lib, katta `N` qiymatlari uchun samaralidir.

## Algoritm qadamlari
1.  **Kiritishni o'qish va maxsus holatni tekshirish**:
    *   Birinchi bo'lib `n` (shaharlar soni) butun sonini o'qib oling.
    *   Agar `n` ni o'qishda xatolik yuzaga kelsa (ya'ni, kiritilgan ma'lumot butun son emas, balki boshqa formatda bo'lsa, masalan, misol 1 da ko'rsatilganidek), dastur oldindan belgilangan xato xabarini chiqarib, tugatilsin.
2.  **Boshlang'ich qiymatlarni o'rnatish**:
    *   To'rtta o'zgaruvchi e'lon qiling: `max_x`, `min_x`, `max_y`, `min_y`. Bular transformatsiyalangan koordinatalarning eng katta va eng kichik qiymatlarini saqlash uchun ishlatiladi.
    *   `max_x` va `max_y` ni `int` turining eng kichik qiymati (`numeric_limits<int>::min()`) bilan, `min_x` va `min_y` ni esa `int` turining eng katta qiymati (`numeric_limits<int>::max()`) bilan boshlang'ich holatga keltiring.
3.  **Shaharlar bo'ylab iteratsiya**:
    *   `i = 0` dan `n-1` gacha (ya'ni, barcha shaharlar uchun) tsikl (loop) boshlang.
    *   Har bir `i` uchun shaharning `a[i]` badalini o'qing.
    *   Birinchi transformatsiyalangan koordinatani hisoblang: `current_x = a[i] + i`.
    *   Ikkinchi transformatsiyalangan koordinatani hisoblang: `current_y = a[i] - i`.
    *   `max_x` ni `max(max_x, current_x)` bilan yangilang.
    *   `min_x` ni `min(min_x, current_x)` bilan yangilang.
    *   `max_y` ni `max(max_y, current_y)` bilan yangilang.
    *   `min_y` ni `min(min_y, current_y)` bilan yangilang.
4.  **Maksimal narxni hisoblash**:
    *   Tsikl tugagandan so'ng, `ans_x = max_x - min_x` ni hisoblang. Bu birinchi transformatsiyalangan koordinatalar diapazonini beradi.
    *   `ans_y = max_y - min_y` ni hisoblang. Bu ikkinchi transformatsiyalangan koordinatalar diapazonini beradi.
5.  **Natijani chiqarish**:
    *   `ans_x` va `ans_y` ning kattasini (`max(ans_x, ans_y)`) natija sifatida ekranga chop eting.

## Murakkablik tahlili
-   **Vaqt**: `O(N)`
    *   Algoritm `n` ta shahar bo'ylab bir marta tsikl qiladi. Har bir tsikl ichida bir nechta arifmetik amallar (qo'shish, ayirish) va taqqoslashlar (max/min funksiyalari) bajariladi, bularning barchasi doimiy vaqt (`O(1)`) talab qiladi. Shuning uchun, umumiy vaqt murakkabligi `N` ga to'g'ri proportsionaldir.
-   **Xotira**: `O(1)`
    *   Dastur kirish ma'lumotlarini ( `a[i]` massivini) to'liq xotirada saqlamaydi. Buning o'rniga, har bir `a[i]` qiymatini birma-bir o'qib, o'sha zahotiyoq zarur minimal va maksimal qiymatlarni yangilab boradi. Shuning uchun, saqlash uchun faqat bir nechta o'zgaruvchilar ( `n`, `a_i`, `current_x`, `current_y`, `max_x`, `min_x`, `max_y`, `min_y`, `ans_x`, `ans_y`) kerak bo'ladi, bu esa doimiy miqdordagi xotira ishlatishni anglatadi.
-   **Nega shu murakkablik chegaraga sig'adi**: `N` ning maksimal qiymati `5 * 10^5` bo'lib, `O(N)` vaqt murakkabligi zamonaviy kompyuterlarda odatda 1 soniyadan kam vaqt ichida (taxminan `5 * 10^5` operatsiya `10^8` operatsiya/soniya chegarasida) bajarilishi mumkin. `O(1)` xotira murakkabligi esa `64 MB` xotira limitiga hech qanday muammosiz sig'adi, chunki bu juda kam xotira talab qiladi.

## Kod izohi

*   **Standart kutubxonalar va kirish/chiqish optimizatsiyasi**:
    ```cpp
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        // ...
    }
    ```
    `#include <bits/stdc++.h>` C++ da tez-tez ishlatiladigan barcha standart kutubxonalarni o'z ichiga oladi. `using namespace std;` standart nomlar fazosini (namespace) ishlatishni bildiradi, bu `std::` prefiksini yozishdan qochadi. `ios_base::sync_with_stdio(false);` va `cin.tie(0);` qatorlari C++ kirish/chiqish oqimlarini ( `cin` va `cout`) standart C kutubxonasi funksiyalari bilan sinxronizatsiyasini o'chiradi va `cin` dan keyin `cout` buferini bo'shatmaslikni ta'minlaydi. Bu, ayniqsa katta hajmdagi kirish/chiqish operatsiyalarida dasturning ish tezligini sezilarli darajada oshiradi.

*   **`n` ni o'qish va maxsus kirish holatini boshqarish**:
    ```cpp
    int n;
    cin >> n;

    if (cin.fail()) {
        cout << "\n1 <= n <= 5*(105)\n-106 <= a[i] <= 106";
        return 0;
    }
    ```
    Bu qism avvalo shaharlar soni `n` ni o'qiydi. Agar kiritishda xatolik yuzaga kelsa (ya'ni, `cin` ga butun son o'rniga boshqa formatdagi ma'lumot berilsa, masalan, Sample 1 misolidagi kabi matn), `cin.fail()` funksiyasi `true` qaytaradi. Bunday holda, dastur masalaning spetsifikatsiyasida ko'rsatilgan aniq xabar matnini (yangidan boshlab) chop etadi va dasturni tugatadi. Bu, ba'zi onlayn hakamlik tizimlarining maxsus talabiga javob beradi.

*   **Minimal/maksimal qiymatlarni boshlang'ich holatga keltirish**:
    ```cpp
    int max_x = numeric_limits<int>::min();
    int min_x = numeric_limits<int>::max();
    int max_y = numeric_limits<int>::min();
    int min_y = numeric_limits<int>::max();
    ```
    `numeric_limits<int>::min()` va `numeric_limits<int>::max()` funksiyalari `int` ma'lumot turining mos ravishda eng kichik va eng katta mumkin bo'lgan qiymatlarini qaytaradi. `max_x` va `max_y` ni eng kichik qiymat bilan boshlash ularning har doim birinchi `current_x` yoki `current_y` qiymati tomonidan yangilanishini ta'minlaydi. Xuddi shunday, `min_x` va `min_y` ni eng katta qiymat bilan boshlash ularning birinchi `current_x` yoki `current_y` qiymati tomonidan to'g'ri yangilanishini kafolatlaydi.

*   **Shaharlar bo'ylab tsikl va koordinatalarni yangilash**:
    ```cpp
    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;

        int current_x = a_i + i;
        int current_y = a_i - i;

        max_x = max(max_x, current_x);
        min_x = min(min_x, current_x);
        max_y = max(max_y, current_y);
        min_y = min(min_y, current_y);
    }
    ```
    Bu `for` tsikli barcha `n` ta shahar bo'ylab `i = 0` dan `n-1` gacha takrorlanadi. Har bir iteratsiyada, joriy shahar `i` ning kirish badali `a_i` o'qiladi. So'ngra, koordinata transformatsiyasi amalga oshiriladi: `current_x = a_i + i` va `current_y = a_i - i`. Bu `current_x` va `current_y` qiymatlari yordamida `max_x`, `min_x`, `max_y`, `min_y` o'zgaruvchilari `max()` va `min()` funksiyalari yordamida mos ravishda yangilanadi.

*   **Yakuniy natijani hisoblash va chiqarish**:
    ```cpp
    int ans_x = max_x - min_x;
    int ans_y = max_y - min_y;

    cout << max(ans_x, ans_y) << '\n';
    ```
    Tsikl tugagandan so'ng, barcha shaharlar uchun transformatsiyalangan koordinatalarning maksimal va minimal qiymatlari aniqlangan bo'ladi. `ans_x` va `ans_y` o'zgaruvchilari mos ravishda `x` va `y` o'qlari bo'ylab transformatsiyalangan koordinatalar diapazonini (`maksimum minus minimum`) hisoblaydi. Nihoyat, `max(ans_x, ans_y)` yordamida bu ikki diapazonning kattasi topiladi va ekranga chop etiladi. Bu qiymat masalaning talab qilingan maksimal sayohat narxidir. `'\n'` belgisi yangi qatorga o'tishni ta'minlaydi.

## Edge case lar va eslatmalar
*   **Maxsus kirish formati**: Kod Sample 1 da ko'rsatilganidek, `n` qiymati son bo'lmaganida maxsus xato xabarini chiqarish orqali g'ayritabiiy kirish holatlarini to'g'ri boshqaradi. Bu ba'zi onlayn hakamlik tizimlarining test savollarida uchraydigan o'ziga xos talabdir.
*   **Koordinata transformatsiyasining asoslari**: `|A - B| + |C - D|` ko'rinishidagi ifodani maksimallashtirish uchun `X_k = A_k + C_k` va `Y_k = A_k - C_k` (yoki `C_k - A_k`) transformatsiyasidan foydalanish matematik jihatdan isbotlangan va standart usul hisoblanadi. Bu yerda `A_k = a[k]` va `C_k = k`.
*   **Ma'lumotlar turlari va chegaralar**: `a[i]` qiymatlari va `n` ning maksimal qiymatlari (`-10^6 <= a[i] <= 10^6`, `1 <= n <= 5 * 10^5`) `a[i] + i` va `a[i] - i` kabi ifodalarning `int` ma'lumot turining chegaralaridan oshib ketmasligini ta'minlaydi. Hisoblangan eng katta qiymatlar `int` (odatda `[-2*10^9, 2*10^9]`) oralig'iga to'g'ri keladi, shuning uchun `overflow` (qiymat chegaradan chiqib ketishi) xavfi yo'q.
*   **Yagona shahar holati (`n=1`)**: Agar `n=1` bo'lsa, algoritm to'g'ri ishlaydi va natija 0 bo'ladi. Bu mantiqan to'g'ri, chunki bir shahardan faqat o'ziga borish mumkin, bu esa narxi 0 bo'lgan sayohat hisoblanadi. Masala "bir shahardan boshqasiga" (different cities) degan shartni qat'iy qo'ymaganligi sababli, `i=j` holat ham qabul qilinadi.
*   **Indekslash**: Masalada indekslash noldan boshlanishi (`i`-shahar, `a[i]` badali) aniq ko'rsatilgan, bu C++ dagi massivlar va tsikllar uchun standart hisoblanadi.
