# M069H — Satrni tiklash

## Masala haqida
Sizga `S` satri va `k` butun soni berilgan. Siz satr ustida istalgancha amal bajarishingiz mumkin: satrning boshidan `k` ta belgini o'chirish va satrning oxiriga istalgan `k` ta belgini qo'shish. Maqsad: ushbu amallardan foydalanib, satrni dastlabki holatiga qaytarish uchun minimal nechta operatsiya kerak bo'lishini topish. Natija 0 ga teng bo'lmasligi kerak.

## Yondashuv (g'oya)
Masalaning asosiy g'oyasi shundaki, biz satrni dastlabki holatiga qaytarish uchun uning ba'zi qismlarini saqlab qolishimiz mumkin. Agar biz `m` marta operatsiya bajarsak, satrning boshidan `m*k` ta belgi o'chiriladi. Qolgan qism `S[m*k ... N-1]` (bu yerda `N` satrning asl uzunligi) original satrning oxirgi `N - m*k` belgisi bo'ladi. Keyin biz satrning oxiriga `m*k` ta ixtiyoriy belgi qo'shamiz.

Satr dastlabki holatiga qaytishi uchun ikkita shart bajarilishi kerak:
1.  Saqlab qolingan `S[m*k ... N-1]` qismi original satrning mos prefiksi (boshlang'ich qismi) `S[0 ... N - m*k - 1]` bilan aynan bir xil bo'lishi kerak.
2.  Qo'shilgan `m*k` ta belgi original satrning qolgan mos suffiksi (oxirgi qismi) `S[N - m*k ... N-1]` bilan aynan bir xil bo'lishi kerak. Ikkinchi shart har doim bajariladi, chunki biz ixtiyoriy belgilarni qo'sha olamiz. Shunday qilib, biz faqat birinchi shartga e'tibor qaratamiz.

`S[m*k ... N-1]` suffiksining `S[0 ... N - m*k - 1]` prefiksi bilan mos kelishini tekshirish uchun Z-algoritmidan foydalanish eng samarali yondashuvdir. Z-algoritm berilgan satr `T` uchun `Z-massiv`ni hisoblaydi, bu yerda `Z[i]` `T` satri va uning `i`-indeksdan boshlanuvchi suffiksi `T[i...]` ning eng uzun umumiy prefiksi (Longest Common Prefix) uzunligini ko'rsatadi. Agar `Z[m*k]` ning qiymati `N - m*k` dan katta yoki teng bo'lsa, demak bizga kerakli shart bajarilgan.

## Algoritm qadamlari

1.  **Z-massivni hisoblash**: Kirish satri `S` uchun Z-algoritm yordamida `Z-massiv`ni hisoblaymiz. `Z[i]` qiymati `S` satri va uning `i`-chi indeksidan boshlanadigan suffiksining eng uzun umumiy prefiksining uzunligini ifodalaydi.
2.  **Boshlang'ich minimal operatsiyalar sonini aniqlash**: Satrning barcha `N` ta belgisini olib tashlab, keyin `N` ta yangi belgi qo'shish holatini ko'rib chiqamiz. Har bir operatsiyada `k` ta belgi o'chirilgani sababli, `N` ta belgini o'chirish uchun `(N + k - 1) / k` ta operatsiya kerak bo'ladi (bu `ceil(N/k)` ga teng, ya'ni `N/k` ning yuqoriga yaxlitlangan qiymati). Bu bizning boshlang'ich minimal operatsiyalarimiz `min_ops` bo'ladi.
3.  **Qisman mos kelish holatini tekshirish**: `m` (operatsiyalar soni) ni 1 dan boshlab, `m*k < N` sharti bajarilgunicha oshirib boramiz.
    *   Har bir `m` qiymati uchun, biz `m*k` ta belgini o'chiramiz deb faraz qilamiz.
    *   Original satrning `m*k` indeksidan boshlanadigan qismi `S[m*k ... N-1]` qoladi. Bu qismning uzunligi `length_to_match = N - m*k` ga teng.
    *   Agar `Z-massiv`dagi `z_array[m*k]` qiymati `length_to_match` dan katta yoki teng bo'lsa, bu degani `S[m*k ... N-1]` suffiksi `S` ning boshlang'ich `length_to_match` uzunlikdagi prefiksi bilan aynan bir xil.
    *   Agar shart bajarilsa, `m` operatsiyalar soni yetarli bo'ladi. Biz `min_ops` ni `m` va joriy `min_ops` ning kichikrog'iga yangilaymiz: `min_ops = std::min(min_ops, m)`.
4.  **Natijani chop etish**: Oxirida `min_ops` qiymatini chop etamiz.

## Murakkablik tahlili
-   **Vaqt**: `calculate_z_array` funksiyasi Z-algoritmini ishlatadi, bu `O(N)` vaqt murakkabligiga ega. Asosiy tsikl `m` ni `1` dan `N/k` gacha oshirib boradi (ya'ni `m*k < N` sharti bajarilgunicha). Har bir iteratsiyada bir nechta arifmetik amal va bitta `std::min` chaqiruvi bajariladi, bu `O(1)` vaqt oladi. Shunday qilib, tsiklning umumiy vaqt murakkabligi `O(N/k)` ga teng. Jami vaqt murakkabligi `O(N + N/k)` bo'lib, `k >= 1` bo'lganligi sababli `O(N)` ga soddalashadi.
    `N` ning maksimal qiymati 1,000,000 bo'lgani uchun `O(N)` operatsiyalar soni (taxminan 10^6) 1000 ms vaqt limiti ichida bemalol bajariladi.

-   **Xotira**: Satr `S` `N` ta belgi uchun `O(N)` xotira talab qiladi. Z-massiv ham `N` ta butun son (integer) saqlaydi, bu ham `O(N)` xotira talab qiladi. Umumiy xotira murakkabligi `O(N)` ga teng.
    `N = 1,000,000` bo'lganida, 1,000,000 ta butun son taxminan 4 MB xotira egallaydi (har bir int 4 bayt). Bu 32 MB xotira limitiga bemalol sig'adi.

## Kod izohi

### Z-algoritm implementatsiyasi (`calculate_z_array` funksiyasi)
```cpp
std::vector<int> calculate_z_array(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    if (n == 0) {
        return z;
    }
    z[0] = n; // Z[0] har doim satrning o'zining uzunligiga teng.

    int l = 0, r = 0; // [l, r] - hozirgi Z-box chegaralari
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            // Agar 'i' joriy Z-box ichida bo'lsa, z[i] uchun pastki chegara mavjud.
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        // z[i] ni belgilar mos kelishini tekshirib kengaytirish.
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        // Agar joriy Z-box ilgari 'r' dan oshib ketsa, 'l' va 'r' ni yangilash.
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
```
Bu funksiya berilgan `s` satri uchun Z-massivni hisoblaydi. `Z[i]` `s` satri va uning `i`-chi indeksidan boshlanadigan suffiksining eng uzun umumiy prefiksi uzunligidir. Algoritm `[l, r]` deb nomlanuvchi "Z-box" (eng o'nggacha cho'zilgan umumiy prefiks) dan foydalanadi. Bu optimizatsiya har bir belgini bir martadan ortiq solishtirmaslikka yordam beradi, natijada `O(N)` vaqtda ishlaydi.

### Asosiy logika (`main` funksiyasi)
```cpp
int main() {
    // Kiritish/chiqarish operatsiyalarini tezlashtirish.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;

    int n = s.length();

    // Z-massivni hisoblash.
    std::vector<int> z_array = calculate_z_array(s);

    // 1-holat: Butun satrni almashtirish.
    // N ta belgini olib tashlash va qo'shish uchun kerakli minimal operatsiyalar soni.
    int min_ops = (n + k - 1) / k; // N/k ni yuqoriga qarab yaxlitlash

    // 2-holat: Satrning bir qismini (suffiksini) saqlab qolish.
    // m - operatsiyalar soni.
    // m*k < n bo'lguncha takrorlaymiz, chunki butun satrni o'chirish holatini yuqorida ko'rdik.
    for (long long m = 1; m * k < n; ++m) {
        long long current_idx = m * k; // Boshidan o'chirilgan belgilar soni
        long long length_to_match = n - current_idx; // Saqlab qolingan suffiks uzunligi
        
        // Agar saqlab qolingan suffiks original satrning prefiksi bilan mos kelsa...
        if (z_array[current_idx] >= length_to_match) {
            min_ops = std::min(min_ops, static_cast<int>(m)); // Minimal operatsiyani yangilash
        }
    }

    std::cout << min_ops << std::endl;

    return 0;
}
```
`main` funksiyasi avval I/O optimizatsiyalarini bajaradi, so'ng `S` satri va `k` sonini o'qiydi. `calculate_z_array` yordamida `Z-massiv`ni yaratadi. Keyin u minimal operatsiyalar sonini hisoblashning ikki asosiy holatini ko'rib chiqadi:
1.  Barcha `N` belgini olib tashlash va qayta kiritish. Bu `(N + k - 1) / k` operatsiya talab qiladi.
2.  `m` operatsiya bajarish orqali `m*k` ta belgini o'chirish va `S` ning qolgan suffiksini uning prefiksi bilan mos kelishini tekshirish. Agar mos kelsa, `m` joriy minimal operatsiyadan kichikroq bo'lsa, u yangilanadi. `m*k` ko'paytmasi `int` turidan oshib ketmasligi uchun `m` o'zgaruvchisi `long long` turida e'lon qilingan.

## Edge case lar va eslatmalar
*   **`k` ning katta qiymati**: Agar `k` satr uzunligi `N` dan katta bo'lsa (ya'ni `k >= N`), u holda `(N + k - 1) / k` ifodasi 1 ga teng bo'ladi. Bu holda satrning barcha belgilarini bir operatsiyada o'chirish va ularning o'rniga yangi `k` belgini qo'shish mumkin, bu esa satrni to'liq tiklaydi. Tsikldagi `m*k < n` sharti ham to'g'ri ishlaydi va `m=1` dan boshlab `m*k >= N` bo'lganligi sababli tsikl umuman ishlamaydi, natijada `min_ops` 1 bo'lib qoladi, bu to'g'ri.
*   **`N=0` (bo'sh satr)**: Masala matnida "0 ga teng bo'lmagan minimum amallar sonini chop eting" deyilganligi sababli, kiruvchi satrning bo'sh bo'lmasligi ehtimoli yuqori (odatda kamida 1 belgidan iborat bo'ladi). Kod `N=0` holatini ham to'g'ri ishlashi mumkin, `z_array` bo'sh qaytariladi va `min_ops = 0` bo'ladi. Biroq, masala shartiga ko'ra natija 0 bo'lmasligi kerak, shuning uchun `N >= 1` deb faraz qilish mumkin.
*   **`long long` dan foydalanish**: `m` operatsiyalar soni va `k` ko'paytmasi `m*k` `int` turining maksimal qiymatidan (taxminan 2 * 10^9) oshib ketishi mumkin (`m` 10^6 ga, `k` ham 10^6 ga yetishi mumkin, ko'paytma 10^12). Shuning uchun `m` va uning ko'paytmasi uchun `long long` turidan foydalanish zarur va kodda bu to'g'ri qo'llanilgan.
