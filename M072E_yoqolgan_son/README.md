# M072E — Yo'qolgan son

## Masala haqida
Bu masalada bizga $n$ dan $m$ gacha (inklyuziv) bo'lgan barcha butun sonlar ro'yxati berilgan, ammo ulardan bittasi bilvosita o'chirilgan. Bizning vazifamiz, berilgan qolgan sonlar asosida aynan qaysi son o'chirilganini aniqlash. Sonlar $1 \le n < m \le 10^5$ oralig'ida bo'lishi mumkin.

## Yondashuv (g'oya)
Yechimning asosiy g'oyasi – sonlar qatorining umumiy yig'indisi xususiyatidan foydalanish. Agar $n$ dan $m$ gacha bo'lgan barcha sonlar mavjud bo'lsa, ularning yig'indisini aritmetik progressiya formulasidan foydalanib hisoblashimiz mumkin. Keyin, bizga kirish sifatida berilgan sonlarning yig'indisini hisoblaymiz. Ushbu ikkita yig'indi o'rtasidagi farq aynan o'chirilgan sonni beradi, chunki o'chirilgan son yig'indidan "yetishmaydigan" qismdir.

## Algoritm qadamlari
1.  Kirish ma'lumotlari sifatida $n$ (boshlang'ich son) va $m$ (oxirgi son) butun sonlarini o'qiymiz.
2.  $n$ dan $m$ gacha bo'lgan barcha sonlarning kutilayotgan umumiy yig'indisini hisoblaymiz. Bu aritmetik progressiya yig'indisi formulasidan foydalangan holda amalga oshiriladi:
    $$ S = \frac{\text{sonlar soni} \times (\text{birinchi son} + \text{oxirgi son})}{2} $$
    Bu yerda `sonlar soni` $m - n + 1$ ga teng. Shunday qilib, formula quyidagicha bo'ladi: `(m - n + 1) * (n + m) / 2`.
    Bu hisoblash uchun `long long` (uzun butun son) ma'lumot turi ishlatiladi, chunki yig'indi juda katta qiymatga ega bo'lishi mumkin ($10^{10}$ gacha).
3.  Keyin, kirishda berilgan $m - n$ ta sonni bitta-bitta o'qib, ularning yig'indisini (`given_sum` – mavjud yig'indi) hisoblaymiz. Har bir o'qilgan sonni `given_sum` ga qo'shamiz.
4.  O'chirilgan sonni topish uchun `expected_total_sum` (kutilayotgan umumiy yig'indi) dan `given_sum` (mavjud yig'indi) ni ayiramiz.
5.  Natijani (o'chirilgan sonni) standart chiqishga chop etamiz.

## Murakkablik tahlili
-   **Vaqt**: $O(M-N)$
    Algoritm asosan bitta siklda $M-N$ ta sonni o'qib ularning yig'indisini hisoblaydi. Bu holatda $M-N$ marta son o'qiladi va yig'indiga qo'shiladi. Boshqa hisob-kitoblar (yig'indini topish formulasi) doimiy vaqtda $O(1)$ bajariladi. Shunday qilib, umumiy vaqt murakkabligi $O(M-N)$ ni tashkil etadi. $M-N$ ning maksimal qiymati $10^5$ bo'lganligi sababli, bu operatsiyalar 1000 ms (1 sekund) vaqt limiti ichida bemalol bajariladi.
-   **Xotira**: $O(1)$
    Algoritm faqat bir nechta o'zgaruvchilarni saqlash uchun doimiy miqdordagi xotiradan foydalanadi ($n, m$, kutilayotgan yig'indi, mavjud yig'indi va sikl o'zgaruvchisi). Kirish sonlari massivda (yoki boshqa ma'lumot tuzilmasida) saqlanmaydi, balki o'qilish jarayonidayoq yig'indiga qo'shiladi. Shuning uchun xotira murakkabligi doimiy $O(1)$ dir. Berilgan 32 MB xotira limiti uchun bu juda samarali va osongina sig'adi.

## Kod izohi

```cpp
#include <bits/stdc++.h> // Standart C++ kutubxonalarini o'z ichiga oladi. Odatda competitive programmingda hamma kerakli narsalarni qo'shish uchun ishlatiladi.

int main() {
    // Kiritish/chiqarish (I/O) operatsiyalarini tezlashtirish uchun satrlar.
    // std::ios_base::sync_with_stdio(false) C++ streamlarining (cin, cout) C standart I/O (printf, scanf) bilan sinxronlashishini o'chiradi. Bu I/O operatsiyalarini tezlashtiradi.
    // std::cin.tie(0) esa std::cin va std::cout o'rtasidagi bog'liqlikni bekor qiladi. Odatda std::cin dan keyin std::cout buferi tozalaydi, bu esa ortiqcha vaqt oladi. Buni bekor qilish tezlikni oshiradi.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long n, m; // n va m butun son o'zgaruvchilarini e'lon qilish.
                    // long long ma'lumot turi ishlatilgan, chunki n va m 10^5 gacha bo'lishi mumkin va ularning yig'indisi int diapazonidan chiqishi mumkin.
    std::cin >> n >> m; // n va m qiymatlarini kiritish.

    // n dan m gacha bo'lgan barcha sonlarning kutilayotgan umumiy yig'indisini hisoblash.
    // Formula: (sonlar soni) * (birinchi_son + oxirgi_son) / 2
    // Sonlar soni: m - n + 1
    // Birinchi son: n, Oxirgi son: m
    // Hisoblangan yig'indini long long turidagi expected_total_sum o'zgaruvchisiga saqlaymiz.
    long long expected_total_sum = (m - n + 1) * (n + m) / 2;
    
    long long given_sum = 0; // Kirishda berilgan sonlarning yig'indisini saqlash uchun o'zgaruvchi. Boshlang'ich qiymati 0.
    int count = m - n; // O'qish kerak bo'lgan sonlar soni (jami sonlar sonidan bitta kam, chunki bittasi o'chirilgan).
    
    // m-n marta takrorlanadigan sikl. Har bir siklda bitta son o'qiladi.
    for (int i = 0; i < count; ++i) { 
        long long x; // Har bir sonni saqlash uchun vaqtinchalik o'zgaruvchi.
        std::cin >> x; // Sonni kiritish.
        given_sum += x; // Kiritilgan sonni given_sum ga qo'shish.
    }

    // Kutilayotgan umumiy yig'indidan berilgan sonlar yig'indisini ayirib, o'chirilgan sonni topish.
    // Natija to'g'ridan-to'g'ri standart chiqishga chop etiladi.
    std::cout << expected_total_sum - given_sum << std::endl;

    return 0; // Dastur muvaffaqiyatli yakunlanganligini bildiradi.
}
```

## Edge case lar va eslatmalar
*   **Katta sonlar yig'indisi**: $n$ va $m$ ning qiymatlari $10^5$ gacha bo'lishi mumkin. Bu holatda $n$ dan $m$ gacha bo'lgan sonlar yig'indisi $10^{10}$ gacha yetishi mumkin. C++ da `int` ma'lumot turi bu kabi katta qiymatlarni saqlay olmaydi (odatda $2 \cdot 10^9$ gacha). Shuning uchun `long long` ma'lumot turidan foydalanish shart. Yechimda bu to'g'ri qo'llanilgan.
*   **Minimal oraliq**: $m - n$ ning minimal qiymati 1 bo'lishi mumkin (masalan, $n=1, m=2$). Bu holatda bizga $m-n=1$ ta son beriladi. Algoritm bu holatda ham to'g'ri ishlaydi, chunki sikl bir marta aylanadi va to'g'ri sonni topadi. Misol: $n=1, m=2$. Expected sum $=(2-1+1)*(1+2)/2 = 2*3/2 = 3$. Kirishda 1 ta son, masalan 1 beriladi. Given sum = 1. Natija $3-1 = 2$.
*   **Kirish/chiqarish tezligi**: $m - n$ sonining maksimal qiymati $10^5$ bo'lganligi sababli, $10^5$ ta sonni kiritish va bitta sonni chiqarish nisbatan ko'p vaqt olishi mumkin. `std::ios_base::sync_with_stdio(false);` va `std::cin.tie(0);` qatorlari C++ dagi kiritish/chiqarish operatsiyalarini sezilarli darajada tezlashtiradi va vaqt limiti oshib ketishining oldini oladi. Yechimda bu optimizatsiyalar qo'llanilgan.
*   **Xotira samaradorligi**: Yechim sonlarni massivda saqlamasdan, ularni o'qish jarayonida darhol yig'indiga qo'shadi. Bu xotiradan foydalanishni sezilarli darajada kamaytiradi va berilgan 32 MB limitiga osongina mos keladi.

Ushbu yechim berilgan cheklovlar va talablarga to'liq javob beradi, juda samarali va to'g'ri ishlaydi.
