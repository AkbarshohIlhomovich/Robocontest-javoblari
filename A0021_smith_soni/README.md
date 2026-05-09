# A0021 — Smith soni

## Masala haqida
Ushbu masala berilgan \(N\) sonining "Smith soni" ekanligini aniqlashni talab qiladi. Smith soni — bu murakkab (tub bo'lmagan) son bo'lib, uning o'z raqamlari yig'indisi, uning tub ko'paytuvchilarining (karraliligi bilan hisoblangan) raqamlari yig'indisiga teng bo'ladi. Masalan, 378 soni: raqamlari yig'indisi $3+7+8=18$. Tub ko'paytuvchilari $2 \times 3 \times 3 \times 3 \times 7$. Ularning raqamlari yig'indisi: $2 + (3+3+3) + 7 = 2+3+3+3+7=18$. Demak, 378 Smith soni. Kirish faylida $N$ soni beriladi ($0 < N < 2 \cdot 10^9$), chiqish faylida agar $N$ Smith soni bo'lsa 1, aks holda 0 chiqarish kerak.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi quyidagilardan iborat:
1.  Berilgan \(N\) sonining raqamlari yig'indisini hisoblash.
2.  \(N\) sonini tub ko'paytuvchilarga ajratish. Har bir tub ko'paytuvchining (karraliligi bilan) raqamlari yig'indisini topish.
3.  Topilgan barcha tub ko'paytuvchilarning raqamlari yig'indisini umumiy yig'indiga jamlash.
4.  Agar \(N\) murakkab son bo'lsa (ya'ni, tub son bo'lmasa) VA uning o'z raqamlari yig'indisi tub ko'paytuvchilarining raqamlari yig'indisiga teng bo'lsa, \(N\) Smith soni hisoblanadi.

## Algoritm qadamlari

1.  **`sum_digits_iterative(int n)` funksiyasini aniqlash:** Bu yordamchi funksiya berilgan sonning (masalan, `N` yoki uning tub ko'paytuvchisining) barcha raqamlari yig'indisini hisoblab qaytaradi. Masalan, `sum_digits_iterative(378)` chaqirilsa, $3+7+8=18$ qaytaradi.
2.  **Kirish ma'lumotini o'qish:** `main` funksiyasidan `solve` funksiyasiga o'tgach, `N` butun soni `std::cin` orqali o'qiladi.
3.  **`N` ning raqamlari yig'indisini hisoblash:** `N` sonining raqamlari yig'indisi `sum_digits_iterative(N)` yordamida hisoblanadi va `original_N_sum_digits` o'zgaruvchisiga saqlanadi.
4.  **Tub ko'paytuvchilarning raqamlari yig'indisini boshlash:** `sum_prime_factor_digits` (`long long` turida, garchi `int` yetarli bo'lsa ham) nolga, `temp_N` esa `N` ga tenglashtiriladi. `is_composite` mantiqiy o'zgaruvchisi `false` ga o'rnatiladi. Bu o'zgaruvchi `N` murakkab son ekanligini aniqlash uchun ishlatiladi.
5.  **2 ga bo'linishini tekshirish:** Dastlab `temp_N` ning 2 ga bo'linishini tekshiriladi. Agar bo'linsa, `is_composite` `true` ga o'rnatiladi. Keyin `temp_N` 2 ga bo'linmay qolguncha, sikl davomida:
    *   `sum_prime_factor_digits` ga 2 ning raqamlari yig'indisi (`sum_digits_iterative(2)`) qo'shiladi.
    *   `temp_N` 2 ga bo'linadi.
6.  **3 dan boshlab toq sonlar bo'yicha tekshirish:** Keyin 3 dan boshlab `temp_N` ning kvadrat ildizigacha (shu jumladan) bo'lgan barcha toq sonlar `i` bo'yicha sikl amalga oshiriladi (`i*i <= temp_N` sharti bilan). Har bir `i` uchun:
    *   Agar `temp_N` `i` ga bo'linsa, `is_composite` `true` ga o'rnatiladi.
    *   Keyin `temp_N` `i` ga bo'linmay qolguncha, ichki sikl davomida:
        *   `sum_prime_factor_digits` ga `i` ning raqamlari yig'indisi (`sum_digits_iterative(i)`) qo'shiladi.
        *   `temp_N` `i` ga bo'linadi.
7.  **Oxirgi tub ko'paytuvchini hisobga olish:** Agar yuqoridagi sikllardan so'ng `temp_N` ning qiymati 1 dan katta bo'lsa, bu degani `temp_N` ning o'zi ham tub son (va `N` ning eng katta tub ko'paytuvchisi) ekanligini anglatadi. Bunday holda, `sum_prime_factor_digits` ga `temp_N` ning raqamlari yig'indisi (`sum_digits_iterative(temp_N)`) qo'shiladi.
8.  **Natijani chiqarish:** Agar `is_composite` `true` bo'lsa (ya'ni `N` murakkab son bo'lsa) VA `original_N_sum_digits` `sum_prime_factor_digits` ga teng bo'lsa, konsolga `1` chiqariladi. Aks holda `0` chiqariladi.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(sqrt(N) * log10(N))`
    *   `sum_digits_iterative` funksiyasi sonning raqamlar soni (`log10(n)`) ga proporsional vaqtda ishlaydi.
    *   Tub ko'paytuvchilarga ajratish qismi eng yomon holatda `sqrt(N)` ga yaqin iteratsiyani talab qiladi (masalan, `N` katta tub son bo'lsa). Har bir iteratsiyada `sum_digits_iterative` chaqirilishi mumkin. Shuning uchun umumiy vaqt murakkabligi taxminan `O(sqrt(N) * log10(N))` ni tashkil qiladi.
    *   `N` ning maksimal qiymati $2 \cdot 10^9$ dan kichik bo'lgani uchun, $\sqrt{N}$ taxminan $45000$ atrofida bo'ladi. $log10(N)$ esa taxminan $10$ atrofida. Demak, operatsiyalar soni taxminan $45000 \times 10 = 450000$ bo'ladi, bu esa 1000 ms vaqt chegarasi uchun juda tez ishlaydi.
-   **Xotira murakkabligi**: `O(1)`
    *   Dastur bir nechta o'zgaruvchini saqlash uchun doimiy miqdordagi xotiradan foydalanadi. Kirish soni qanchalik katta bo'lishidan qat'i nazar, qo'shimcha xotira talab qilinmaydi.
-   **Nega shu murakkablik chegaraga sig'adi**: Yuqorida tahlil qilinganidek, `sqrt(N)` ga asoslangan tub ko'paytuvchilarga ajratish algoritmi berilgan $N$ qiymati ($2 \cdot 10^9$ dan kichik) uchun juda samarali. Raqamlar yig'indisini hisoblash logarifmik vaqtda amalga oshiriladi, bu esa umumiy hisoblash vaqtiga sezilarli ta'sir qilmaydi. Shuning uchun, 1000 ms vaqt limiti va 16 MB xotira limiti doirasida bemalol ishlaydi.

## Kod izohi

### `sum_digits_iterative` funksiyasi
```cpp
int sum_digits_iterative(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10; // Sonning oxirgi raqamini yig'indiga qo'shish
        n /= 10;       // Sonning oxirgi raqamini olib tashlash
    }
    return sum;
}
```
Bu funksiya berilgan `n` butun sonining barcha raqamlarining yig'indisini hisoblaydi. Bu jarayon `n` nolga teng bo'lmaguncha davom etadi, har safar `n % 10` orqali oxirgi raqam olinadi va `n /= 10` orqali sonning o'ngdan bir raqami olib tashlanadi.

### `solve` funksiyasi
```cpp
void solve() {
    int N;
    std::cin >> N; // Kirish sonini o'qish

    int original_N_sum_digits = sum_digits_iterative(N); // N ning o'z raqamlari yig'indisi
    long long sum_prime_factor_digits = 0; // Tub ko'paytuvchilar raqamlari yig'indisi
    int temp_N = N; // N ni tub ko'paytuvchilarga ajratish uchun vaqtinchalik o'zgaruvchi
    bool is_composite = false; // N murakkab son ekanligini belgilovchi flag
    // ... davomi bor ...
}
```
Bu bo'limda asosiy ishni bajaruvchi `solve` funksiyasi boshlanadi. `N` o'qiladi, `original_N_sum_digits` hisoblanadi. `sum_prime_factor_digits` va `is_composite` flaglari boshlang'ich holatga keltiriladi.

```cpp
    if (temp_N % 2 == 0) {
        is_composite = true; // Agar N 2 ga bo'linsa, u murakkab
        while (temp_N % 2 == 0) {
            sum_prime_factor_digits += sum_digits_iterative(2); // 2 ning raqamlari yig'indisini qo'shish
            temp_N /= 2; // N ni 2 ga bo'lish
        }
    }
```
Bu blok `N` ning 2 ga bo'linishini tekshiradi va barcha 2 ko'paytuvchilarini ajratib oladi. Agar `N` 2 ga bo'linsa, `is_composite` `true` bo'ladi, chunki u tub son emas. Har bir 2 ko'paytuvchisi uchun `sum_prime_factor_digits` ga 2 ning raqamlari yig'indisi (ya'ni 2) qo'shiladi.

```cpp
    for (int i = 3; (long long)i * i <= temp_N; i += 2) {
        if (temp_N % i == 0) {
            is_composite = true; // Agar N i ga bo'linsa, u murakkab
            while (temp_N % i == 0) {
                sum_prime_factor_digits += sum_digits_iterative(i); // i ning raqamlari yig'indisini qo'shish
                temp_N /= i; // N ni i ga bo'lish
            }
        }
    }
```
Bu sikl qolgan `temp_N` ni 3 dan boshlab, barcha toq tub ko'paytuvchilarga ajratadi. `(long long)i * i <= temp_N` sharti `i*i` int diapazonidan chiqib ketishini oldini oladi va faqat `sqrt(temp_N)` gacha bo'lgan tub ko'paytuvchilarni tekshirish yetarli ekanligini bildiradi. Agar `temp_N` `i` ga bo'linsa, `is_composite` `true` ga o'rnatiladi va `i` ning barcha karralari ajratiladi, ularning raqamlari yig'indisi umumiy yig'indiga qo'shiladi.

```cpp
    if (temp_N > 1) {
        // Agar temp_N 1 dan katta bo'lsa, u qolgan eng katta tub ko'paytuvchidir.
        // Masalan, N=170, temp_N=17 bo'lsa.
        sum_prime_factor_digits += sum_digits_iterative(temp_N);
    }
```
Yuqoridagi sikllardan so'ng, agar `temp_N` hali ham 1 dan katta bo'lsa, bu uning o'zi tub son va `N` ning eng katta tub ko'paytuvchisi ekanligini anglatadi. Uning raqamlari yig'indisi ham `sum_prime_factor_digits` ga qo'shiladi.

```cpp
    if (is_composite && original_N_sum_digits == sum_prime_factor_digits) {
        std::cout << 1 << std::endl; // Agar Smith soni bo'lsa
    } else {
        std::cout << 0 << std::endl; // Aks holda
    }
}
```
Bu oxirgi blok natijani hisoblab chiqaradi. Agar `N` murakkab son bo'lsa (`is_composite == true`) VA uning raqamlari yig'indisi tub ko'paytuvchilari raqamlari yig'indisiga teng bo'lsa, `1` chiqariladi. Aks holda, `0` chiqariladi.

### `main` funksiyasi
```cpp
int main() {
    std::ios_base::sync_with_stdio(false); // C++ oqimlari va C stdio oqimlari orasidagi sinxronizatsiyani o'chirish
    std::cin.tie(0); // std::cin va std::cout orasidagi bog'lanishni bekor qilish (tezlikni oshirish uchun)
    solve(); // Asosiy yechim funksiyasini chaqirish
    return 0; // Dasturning muvaffaqiyatli yakunlanganini bildirish
}
```
`main` funksiyasi C++ kirish/chiqish oqimlarining tezligini oshirish uchun standart optimizatsiyalarni amalga oshiradi va `solve` funksiyasini chaqiradi.

## Edge case lar va eslatmalar

*   **Tub sonlar:** Agar `N` tub son bo'lsa, u Smith soni bo'la olmaydi, chunki Smith soni ta'rifiga ko'ra murakkab bo'lishi kerak. Kod `is_composite` flagi yordamida bu holatni to'g'ri boshqaradi. Agar `N` tub son bo'lsa (masalan, `N=7`), `is_composite` `false` bo'lib qoladi va natija `0` bo'ladi.
*   **1 soni:** Masala shartida `0 < N` deb berilganligi sababli, `N=1` holati e'tiborga olinmaydi. Agar `N=1` bo'lganida, u na tub, na murakkab son, shuning uchun Smith soni bo'lmaydi.
*   **Katta tub ko'paytuvchilar:** Agar `N` ning eng katta tub ko'paytuvchisi `sqrt(N)` dan katta bo'lsa, u `temp_N > 1` shartida alohida hisobga olinadi. Masalan, `N=14 = 2 \times 7`. 2 ajratilgach, `temp_N=7` qoladi. Bu 7 ham tub son sifatida hisobga olinadi.
*   **`long long` dan foydalanish:** Kodda `sum_prime_factor_digits` `long long` deb e'lon qilingan. Aslida, $N < 2 \cdot 10^9$ bo'lgani uchun, uning raqamlari yig'indisi eng ko'pi $1+9 \times 9 = 82$ (masalan, $1,999,999,999$ uchun). Tub ko'paytuvchilarning raqamlari yig'indisi ham bundan katta bo'lmaydi, chunki ular \(N\) dan kichik bo'ladi. Shuning uchun `int` turi ham ushbu yig'indilar uchun yetarli bo'ladi. Biroq, `(long long)i * i <= temp_N` qismi `i*i` ning `int` diapazonidan chiqib ketishini oldini olish uchun muhim va to'g'ri ishlatilgan.
