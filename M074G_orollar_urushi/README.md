# M074G — Orollar urushi

## Masala haqida
Bu masalada $N$ ta shahar va ularni ketma-ket bog'lovchi $N-1$ ta ko'prik bor. Ya'ni, $i$-chi ko'prik $i$ va $i+1$ shaharlarni bog'laydi. Shaharlar orasida $M$ ta nizo mavjud bo'lib, har bir nizo $(u, v)$ shaharlar juftligi orasida yo'l bo'lmasligini talab qiladi. Bizning vazifamiz — barcha nizolarni hal qilish uchun kamida nechta ko'prikni buzish kerakligini topish.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi — bu klassik "oraliq qoplash (interval covering)" muammosining bir variantidir. Har bir nizo $(u, v)$ shaharlar juftligi orasida mavjud bo'lsa, bu $u$ dan $v$ gacha bo'lgan yo'ldagi kamida bitta ko'prikni buzishni talab qiladi. Ko'priklar $1$ dan $N-1$ gacha indekslarga ega: $k$-chi ko'prik $k$ va $k+1$ shaharlarini bog'laydi.

Agar $u$ va $v$ shaharlari orasida nizo bo'lsa, ularni bog'lovchi yo'l ustida $min(u, v)$ va $max(u, v)$ shaharlar oralig'i yotadi. Bu oralig'dagi ko'priklar $min(u, v)$ indeksidan boshlab $max(u, v) - 1$ indeksigacha bo'lgan ko'priklar hisoblanadi. Demak, har bir nizo $(u, v)$ uchun biz $min(u, v)$ va $max(u, v) - 1$ indekslari orasidagi ko'priklar oralig'idan kamida bittasini buzishimiz kerak.

Muammoni hal qilish uchun **ochko'z (greedy) algoritm** qo'llaniladi:
1.  Barcha nizolarni ko'priklar oralig'iga aylantiramiz.
2.  Bu oraliqlarni ularning o'ng chegarasi (eng katta ko'prik indeksi) bo'yicha o'sish tartibida saralaymiz.
3.  Saralangan oraliqlarni ketma-ket ko'rib chiqamiz. Agar joriy oraliq oldingi buzilgan ko'priklar bilan qoplanmagan bo'lsa, uni qoplash uchun yangi ko'prikni buzishga majburmiz. Eng samarali usul — joriy oraliqning o'ng chegarasidagi ko'prikni buzishdir, chunki bu eng ko'p sonli keyingi oraliqlarni ham qoplash imkoniyatini beradi.

## Algoritm qadamlari
1.  **Kirish ma'lumotlarini o'qish va ko'prik oraliqlarini aniqlash**: $N$ va $M$ sonlarini o'qib olamiz. Har bir $(u, v)$ nizo uchun, shaharlar orasidagi ko'priklar oralig'ini topamiz. Bu oraliqning chap chegarasi $L = \min(u, v)$ va o'ng chegarasi $R = \max(u, v) - 1$ bo'ladi. Bu $(L, R)$ juftliklarni saqlaydigan ro'yxat (yoki `vector`) yaratamiz.
2.  **Oraloqlarni saralash**: Hosil bo'lgan barcha ko'prik oraliqlarini ularning o'ng chegarasi ($R$) bo'yicha o'sish tartibida saralaymiz. Agar o'ng chegaralar teng bo'lsa, chap chegara ($L$) bo'yicha saralash mumkin (garchi bu qat'iy zarur bo'lmasa-da, har doim bir xil natija berishini ta'minlaydi).
3.  **Ochko'z yondashuvni qo'llash**:
    *   `broken_bridges_count` (buzilgan ko'priklar soni) nomli o'zgaruvchini 0 ga tenglaymiz.
    *   `last_broken_bridge_pos` (oxirgi buzilgan ko'prikning indeksi) nomli o'zgaruvchini 0 ga tenglaymiz. Bu qiymat, ko'prik indekslari 1 dan boshlanganligi sababli, har qanday birinchi oraliqni qoplamagan holat sifatida ko'rilishi uchun mo'ljallangan.
    *   Saralangan oraliqlar ro'yxati bo'ylab takrorlash (iterate) qilamiz:
        *   Har bir joriy oraliq $(L, R)$ uchun, agar uning chap chegarasi $L$ `last_broken_bridge_pos` dan katta bo'lsa ($L > last_broken_bridge_pos$), bu shuni anglatadiki, joriy oraliq oldin buzilgan ko'priklar bilan qoplanmagan.
        *   Bu holatda, biz yangi ko'prikni buzishimiz shart. Shuning uchun `broken_bridges_count` ni bittaga oshiramiz.
        *   Eng optimal variant - joriy oraliqning o'ng chegarasidagi ko'prikni buzishdir. Bu joriy oraliqni qoplaydi va keyingi oraliqlardan ham iloji boricha ko'proq qismini qoplash imkoniyatini yaratadi. Shuning uchun `last_broken_bridge_pos` ni joriy oraliqning $R$ qiymatiga yangilaymiz.
4.  **Natijani chiqarish**: Barcha oraliqlar ko'rib chiqilgandan so'ng, `broken_bridges_count` ni chop etamiz.

## Murakkablik tahlili
-   **Vaqt murakkabligi**: `O(M log M)`
    *   $M$ ta nizodan ko'prik oraliqlarini yaratish uchun `O(M)` vaqt ketadi.
    *   `std::vector` dagi $M$ ta oraliqni saralash `O(M log M)` vaqt talab qiladi.
    *   Saralangan oraliqlar bo'ylab bir marta takrorlash (iterating) va hisoblash `O(M)` vaqt oladi.
    *   Umumiy vaqt murakkabligi: `O(M log M)`. Masala shartlariga ko'ra $M \le 10^5$ bo'lganligi sababli, `10^5 * log(10^5)` taxminan `10^5 * 17` ga teng, bu esa `1.7 * 10^6` operatsiyani tashkil etadi va 1000 ms vaqt limitiga to'liq sig'adi.

-   **Xotira murakkabligi**: `O(M)`
    *   $M$ ta ko'prik oraliqlarini `std::vector<std::pair<int, int>>` da saqlash uchun `O(M)` xotira talab qilinadi.
    *   $M \le 10^5$ bo'lganda, `10^5` juftlik uchun xotira taxminan `10^5 * (4 + 4) = 8 * 10^5` bayt (ya'ni, 800 KB) bo'ladi. Bu 32 MB xotira limitiga bemalol sig'adi.

## Kod izohi

```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun
#include <vector>   // Dinamik massiv (vektor) ishlatish uchun
#include <algorithm> // Saralash funksiyalari (std::sort) uchun
#include <utility>   // std::pair ishlatish uchun

int main() {
    // Kirish/chiqish operatsiyalarini tezlashtirish uchun
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M; // N - shaharlar soni, M - nizolar soni
    std::cin >> N >> M;

    // Har bir nizo uchun ko'prik oralig'ini saqlash uchun vektor
    // {chap chegara (ko'prik indeksi), o'ng chegara (ko'prik indeksi)}
    std::vector<std::pair<int, int>> intervals;
    intervals.reserve(M); // Vektor hajmini oldindan M ga ajratish, samaradorlikni oshirish uchun

    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        
        // u va v shaharlar orasidagi yo'ldagi ko'priklar oralig'ini hisoblash.
        // k-chi ko'prik k va k+1 shaharlarni bog'laydi.
        // Agar u < v bo'lsa, yo'l u, u+1, ..., v shaharlaridan o'tadi.
        // Ko'priklar: (u, u+1), (u+1, u+2), ..., (v-1, v).
        // Ko'prik indekslari: u, u+1, ..., v-1.
        // Demak, oraliq [min(u,v), max(u,v)-1] bo'ladi.
        int left_bridge_idx = std::min(u, v);
        int right_bridge_idx = std::max(u, v) - 1;
        intervals.push_back({left_bridge_idx, right_bridge_idx}); // Oraliqni vektorga qo'shish
    }

    // Oraloqlarni saralash: avval o'ng chegara (second element) bo'yicha o'sish tartibida.
    // Agar o'ng chegaralar teng bo'lsa, chap chegara (first element) bo'yicha o'sish tartibida.
    std::sort(intervals.begin(), intervals.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second != b.second) { // Agar o'ng chegaralar teng bo'lmasa
            return a.second < b.second; // Kichikroq o'ng chegarasi bo'lgan oldinda bo'ladi
        }
        return a.first < b.first; // Agar o'ng chegaralar teng bo'lsa, chap chegara bo'yicha saralash
    });

    int broken_bridges_count = 0; // Buzilgan ko'priklar soni
    // last_broken_bridge_pos: oxirgi buzilgan ko'prikning indeksi.
    // 0 ga boshlashning sababi: ko'prik indekslari 1 dan boshlanadi.
    // Shunday qilib, birinchi oraliq (masalan, [1, R]) uchun 1 > 0 sharti har doim bajariladi
    // va birinchi ko'prik buzilishi kafolatlanadi.
    int last_broken_bridge_pos = 0; 

    // Saralangan oraliqlar bo'ylab iteratsiya qilish (takrorlash)
    for (const auto& interval : intervals) {
        // Agar joriy oraliqning chap chegarasi (interval.first) oldin buzilgan ko'prikning
        // indeksidan (last_broken_bridge_pos) katta bo'lsa,
        // demak bu oraliq oldingi buzilgan ko'priklar bilan qoplanmagan.
        if (interval.first > last_broken_bridge_pos) {
            broken_bridges_count++; // Yangi ko'prik buzishga majburmiz
            // Eng ko'p sonli keyingi oraliqlarni qoplash uchun,
            // joriy oraliqning o'ng chegarasidagi ko'prikni buzamiz.
            last_broken_bridge_pos = interval.second;
        }
    }

    std::cout << broken_bridges_count << std::endl; // Natijani chop etish

    return 0; // Dastur muvaffaqiyatli yakunlandi
}

```

## Edge case lar va eslatmalar
*   **Ko'prik indekslari**: Masala matnida $i$-chi tugun $i$ va $i+1$ shaharlarni bog'laydi deb yozilgan, ammo odatda "ko'prik $i$ va $i+1$ shaharlarni bog'laydi" deb ifodalanadi. Kodda bu `min(u,v)` va `max(u,v)-1` oraliqqa o'girilishi ko'prik indekslari $1$ dan $N-1$ gacha ekanligini anglatadi. Masalan, 1 va 2-shaharlar orasidagi ko'prik 1-indeksga ega.
*   **`last_broken_bridge_pos` ning boshlang'ich qiymati**: `0` ga o'rnatish muhimdir, chunki ko'prik indekslari $1$ dan boshlanadi. Agar uni `1` qilib qo'yilsa va birinchi oraliq `[1, R]` bo'lsa, `1 > 1` sharti bajarilmaydi va noto'g'ri hisobga olish mumkin. `0` ga o'rnatish birinchi ko'prik indeksini ($1$) har doim `0` dan katta deb hisoblashni ta'minlaydi, bu esa birinchi qoplanmagan oraliq uchun ko'prikni buzishni kafolatlaydi.
*   **Saralash tartibi**: Oraloqlarni o'ng chegarasi bo'yicha saralash bu ochko'z algoritmning to'g'riligi uchun juda muhim. Agar o'ng chegaralar teng bo'lsa, chap chegara bo'yicha saralash natijaga ta'sir qilmaydi, ammo xuddi shunday qiymatlarga ega oraliqlar uchun tartibni barqaror qiladi.
*   **N va M chegaralari**: $N, M \le 10^5$ kabi katta qiymatlar `O(M log M)` yoki `O(N log N)` kabi samarali algoritmlarni talab qilishini ko'rsatadi, kvadratik (`O(N^2)`) yechimlar vaqt limitidan oshib ketadi. Bizning yechimimiz bu talabga javob beradi.
