# M075A — Yuklar

## Masala haqida
Sunnatga `n` ta yuk kelishi kutilmoqda. Har bir `i`-yuk `l_i` kundan `r_i` kungacha bo'lgan oraliqda pochta markazidan olinishi mumkin. Sunnat pochta markaziga bir marta borganida eng ko'pi bilan `k` ta yuk olib keta oladi. Masala Sunnat barcha yuklarini olib ketish uchun pochta markaziga minimal necha marta borishi kerakligini topishdan iborat.

## Yondashuv (g'oya)
Bu masala uchun optimal yechim "greedy" (ochko'z) yondashuvga asoslangan. Asosiy g'oya shundan iboratki, har safar pochta markaziga borilganda, olinishi kerak bo'lgan yuklardan birini (eng erta tugash muddatiga ega bo'lganini) aniqlash va shu yukning tugash kunini (yoki undan oldingi bir kunni) tanlab, iloji boricha ko'proq (maksimal `k` tagacha) yukni bir vaqtning o'zida olib ketishdir. Bu strategiya, har bir sayohatda eng jiddiy ("deadlined") yukni hal qilish bilan birga, boshqa yuklarni yig'ish uchun eng katta imkoniyatni saqlab qoladi.

Algoritm quyidagicha ishlaydi:
1.  Barcha yuklarni ularning tugash kuni (`r_i`) bo'yicha o'sish tartibida saralaymiz. Agar tugash kunlari bir xil bo'lsa, kelish kuni (`l_i`) bo'yicha saralaymiz. Bu bizga har doim eng yaqin muddati tugaydigan yukni ko'rib chiqish imkonini beradi.
2.  Saralangan yuklar ichida hali yig'ib olinmagan birinchi yukni topamiz. Bu yukning muddati boshqa yig'ilmagan yuklarnikidan qisqaroq (yoki teng) bo'ladi.
3.  Ushbu yukni yig'ib olish uchun sayohatni rejalashtiramiz. Sayohat kunini shu yukning tugash kuni (`r_i`) deb belgilash eng optimal hisoblanadi, chunki bu bilan boshqa yuklarni ham shu kunga qadar yig'ib olish uchun maksimal vaqt oralig'i yaratiladi.
4.  Tanlangan sayohat kunida (`r_i`) va `k` limiti ichida iloji boricha ko'proq boshqa yuklarni yig'ib olamiz. Bu yuklar tanlangan kunga qadar yetib kelgan bo'lishi (`l_j <= r_i`) va hali yig'ilmagan bo'lishi kerak.
5.  Ushbu jarayon barcha yuklar yig'ib olinguncha takrorlanadi.

`std::set` ma'lumotlar tuzilmasidan foydalanish yig'ib olinmagan yuklarni samarali boshqarishga yordam beradi, chunki u elementlarni tartiblangan holda saqlaydi va tezkor qidirish, qo'shish, o'chirish operatsiyalarini (O(log N) vaqtda) ta'minlaydi.

## Algoritm qadamlari

1.  **Test holatlarini boshqarish**: Dastur `T` ta test holatini o'qiydi va har birini `solve()` funksiyasini chaqirish orqali alohida hal qiladi.
2.  **Ma'lumotlarni o'qish va tayyorlash**:
    *   Har bir test holati uchun `n` (yuklar soni) va `k` (bir sayohatda olinadigan maksimal yuklar) o'qiladi.
    *   `n` ta yukning `l_i` (kelish kuni) va `r_i` (olib ketishning oxirgi kuni) ma'lumotlari `Package` strukturasiga o'qilib, `std::vector<Package> packages` ga joylanadi. Har bir yukning asl indeksi (`id`) ham saqlanadi.
3.  **Yuklarni saralash**: `packages` vektori `comparePackages` funksiyasi yordamida saralanadi. Bu funksiya yuklarni avval `r` qiymati (tugash kuni) bo'yicha o'sish tartibida, so'ngra `l` qiymati (kelish kuni) bo'yicha o'sish tartibida saralaydi.
4.  **Yig'ilmagan yuklarni kuzatish**: `std::set<int> uncollected_indices` yaratiladi. Boshida bu setga `0` dan `n-1` gacha bo'lgan barcha yuklarning saralangan indekslari joylanadi. Bu set hozircha yig'ib olinmagan yuklarning indekslarini saqlaydi.
5.  **Sayohatlarni hisoblash**:
    *   `trips` nomli butun son o'zgaruvchisi `0` ga tenglashtiriladi. Bu Sunnatning jami sayohatlari sonini hisoblab boradi.
    *   `i` indeksi bo'yicha `0` dan `n-1` gacha saralangan `packages` vektori bo'ylab iteratsiya qilinadi.
    *   **Yuk yig'ish mantiqi**:
        *   Agar `uncollected_indices` setida `i` indeksli yuk topilmasa, bu yuk avvalgi sayohatlardan birida yig'ib olinganligini bildiradi. Shuning uchun, bu yukni o'tkazib yuboriladi (`continue`).
        *   Agar `i` indeksli yuk `uncollected_indices` setida bo'lsa, bu degani u eng yaqin muddati tugaydigan yuk va u uchun sayohat qilish kerak. `trips` soni bittaga oshiriladi.
        *   Joriy sayohat uchun yig'ib olish kuni (`current_collection_day`) `packages[i].r` ga, ya'ni shu yukning tugash kuniga tenglashtiriladi.
        *   `collected_in_this_trip` nomli hisoblagich `0` ga tenglashtiriladi.
        *   `uncollected_indices` setida `i` indeksidan boshlab (yoki `i` dan keyingi birinchi elementdan) iteratsiya qilinadi (`auto it = uncollected_indices.lower_bound(i);`).
        *   `it` iterator set oxiriga yetguncha yoki `collected_in_this_trip` soni `k` ga yetguncha ichki `while` sikli ishlaydi:
            *   Joriy ko'rib chiqilayotgan yukning indeksi `current_package_idx = *it` orqali olinadi.
            *   Agar `packages[current_package_idx].l <= current_collection_day` sharti bajarilsa (ya'ni, bu yuk tanlangan `current_collection_day` ga qadar pochta markaziga yetib kelgan bo'lsa), bu yukni joriy sayohatda yig'ib olish mumkin.
                *   Yuk `uncollected_indices` setidan o'chiriladi (`it = uncollected_indices.erase(it);`). `erase()` funksiyasi o'chirilgan elementdan keyingi elementga ishora qiluvchi iteratorni qaytaradi, bu esa iteratsiyani uzluksiz davom ettirish imkonini beradi.
                *   `collected_in_this_trip` soni bittaga oshiriladi.
            *   Aks holda (agar yuk hali yetib kelmagan bo'lsa), bu yukni joriy sayohatda yig'ish mumkin emas, shuning uchun keyingi yukka o'tiladi (`++it`).
6.  **Natijani chop etish**: Asosiy sikl tugagach, `trips` ning yakuniy qiymati chop etiladi.

## Murakkablik tahlili

-   **Vaqt murakkabligi**:
    *   Har bir test holati uchun:
        *   Yuklarni o'qish: O(N)
        *   Yuklarni saralash (`std::sort`): O(N log N)
        *   `uncollected_indices` setiga `N` ta elementni kiritish: O(N log N)
        *   Asosiy `for` sikli `N` marta ishlaydi. Har bir iteratsiyada:
            *   `std::set::find` operatsiyasi: O(log N)
            *   Ichki `while` siklida `k` tagacha element `uncollected_indices` setidan o'chirilishi mumkin (`std::set::erase`). Har bir `erase` operatsiyasi O(log N) vaqt oladi. E'tibor bering, har bir yuk setdan faqat bir marta o'chiriladi. Shuning uchun, barcha `erase` operatsiyalarining umumiy vaqti butun algoritm davomida O(N log N) ni tashkil qiladi. `std::set::lower_bound` va iteratorni oshirish (`++it`) operatsiyalari ham O(log N) yoki O(1) amortizatsiyalanadi.
    *   Demak, bir test holati uchun umumiy vaqt murakkabligi **O(N log N)**.
    *   Masala cheklovlariga ko'ra, barcha testlar bo'yicha `N` ning yig'indisi `10^6` dan oshmaydi. Shuning uchun umumiy vaqt murakkabligi `sum(N log N)` bo'lib, bu eng yomon holatda `10^6 * log(10^6)` ga teng, taxminan `10^6 * 20 = 2 * 10^7` operatsiyani tashkil qiladi. Bu 1000 ms vaqt limitiga bemalol sig'adi.

-   **Xotira murakkabligi**:
    *   `std::vector<Package> packages`: `N` ta `Package` strukturasini saqlaydi. Har bir `Package` 2 ta `int` (yoki 3 ta `int`, `id` bilan) dan iborat. Bu **O(N)** xotira talab qiladi.
    *   `std::set<int> uncollected_indices`: `N` tagacha `int` elementini saqlaydi. `std::set` ichki qizil-qora daraxt (red-black tree) sifatida amalga oshirilganligi sababli, har bir element uchun qo'shimcha xotira sarflanadi, lekin baribir **O(N)** chegarasidan chiqmaydi.
    *   Jami xotira murakkabligi **O(N)**.
    *   `N` ning maksimal qiymati `10^5` bo'lganligi sababli, `10^5` ta `Package` (taxminan 12 bayt * `10^5` = 1.2 MB) va `10^5` ta `int` (taxminan 4 bayt * `10^5` = 0.4 MB, plus set overhead) 64 MB xotira limitiga bemalol sig'adi.

## Kod izohi

1.  **`#include <iostream>`, `<vector>`, `<algorithm>`, `<set>`**: Kerakli kutubxonalarni o'z ichiga oladi. `iostream` kirish/chiqish uchun, `vector` dinamik massivlar uchun, `algorithm` saralash funksiyalari uchun, `set` esa tartiblangan noyob elementlar to'plamini saqlash uchun.

2.  **`struct Package { int l, r; int id; };`**: Har bir yukni ifodalovchi struktura. `l` yuk keladigan kun, `r` yukni olib ketishning oxirgi kuni. `id` asl indeksni saqlaydi, garchi bu masalada unchalik muhim bo'lmasa ham.

3.  **`bool comparePackages(const Package& a, const Package& b)`**: Yuklarni saralash uchun maxsus solishtirish funksiyasi. Bu yuklarni avval `r` (oxirgi kun) bo'yicha o'sish tartibida, keyin `l` (kelish kuni) bo'yicha o'sish tartibida saralaydi.

4.  **`void solve()` funksiyasi**:
    *   **`int n, k; std::cin >> n >> k;`**: `n` va `k` qiymatlarini o'qiydi.
    *   **`std::vector<Package> packages(n);`**: `n` ta yukni saqlash uchun vektor yaratadi.
    *   **Yuklarni o'qish sikli**: `for` sikli ichida har bir yukning `l` va `r` qiymatlari o'qiladi va `packages` vektoriga joylanadi. `id` ham o'rnatiladi.
    *   **`std::sort(packages.begin(), packages.end(), comparePackages);`**: Yuklarni `comparePackages` funksiyasi yordamida saralaydi.
    *   **`std::set<int> uncollected_indices;`**: Hali yig'ilmagan yuklarning indekslarini saqlash uchun `std::set` yaratiladi. Boshida barcha yuklarning indekslari unga joylashtiriladi.
    *   **`int trips = 0;`**: Sayohatlar sonini hisoblash uchun hisoblagich.
    *   **Asosiy `for` sikli (`for (int i = 0; i < n; ++i)`)**: Saralangan yuklar bo'yicha iteratsiya qiladi.
        *   **`if (uncollected_indices.find(i) == uncollected_indices.end()) { continue; }`**: Agar joriy `packages[i]` yuk allaqachon yig'ib olingan bo'lsa, keyingi yukka o'tiladi.
        *   **`trips++;`**: Yangi sayohat boshlanganini bildiradi.
        *   **`int current_collection_day = packages[i].r;`**: Joriy sayohat uchun yig'ib olish kunini eng erta muddati tugaydigan yukning `r` qiymatiga tenglashtiradi.
        *   **`int collected_in_this_trip = 0;`**: Joriy sayohatda yig'ilgan yuklar sonini hisoblagich.
        *   **Ichki `while` sikli (`while (it != uncollected_indices.end() && collected_in_this_trip < k)`)**: `uncollected_indices` setida `i` indeksidan boshlab (yoki undan keyingi elementdan) iteratsiya qiladi va `k` ta yuk yig'ib olinmaguncha davom etadi.
            *   **`if (packages[current_package_idx].l <= current_collection_day)`**: Agar yuk tanlangan kunga qadar kelgan bo'lsa.
                *   **`it = uncollected_indices.erase(it);`**: Yukni setdan o'chiradi va iteratorni keyingi elementga yangilaydi.
                *   **`collected_in_this_trip++;`**: Yig'ilgan yuklar sonini oshiradi.
            *   **`else { ++it; }`**: Agar yuk hali kelmagan bo'lsa, keyingi yukka o'tadi.
    *   **`std::cout << trips << std::endl;`**: Yakuniy sayohatlar sonini chop etadi.

5.  **`int main()` funksiyasi**:
    *   **`std::ios_base::sync_with_stdio(false); std::cin.tie(0);`**: Kirish/chiqish operatsiyalarini tezlashtirish uchun optimizatsiyalar.
    *   **`int t; std::cin >> t; while (t--) { solve(); }`**: `T` test holatlarini o'qiydi va har biri uchun `solve()` funksiyasini chaqiradi.

## Edge case lar va eslatmalar

*   **Vaqt oralig'i katta (`10^9`)**: `l_i` va `r_i` qiymatlari juda katta bo'lishi mumkin, lekin bu integer overflow muammosini keltirmaydi, chunki biz faqat ularni taqqoslaymiz va saqlaymiz. Kunlar sanasi emas, balki ularning nisbiy tartibi muhim.
*   **`k=1` holati**: Agar Sunnat bir sayohatda faqat bitta yuk olib keta olsa, har safar pochta markaziga borganida faqat bitta yukni (eng erta muddati tugaydiganini) olib ketadi va yana bir sayohat qilishi kerak bo'ladi. Bu holda ham algoritm to'g'ri ishlaydi.
*   **Yuklarning kelish tartibi**: Yuklar saralanganligi sababli, `current_collection_day` (`packages[i].r`) har doim `packages[j].r` dan (`j >= i` uchun) kichik yoki teng bo'ladi. Shu sababli, ichki `while` siklida `packages[current_package_idx].r >= current_collection_day` shartini tekshirish shart emas, chunki bu shart `current_package_idx >= i` bo'lgan har qanday yuk uchun avtomatik bajariladi. Faqat `packages[current_package_idx].l <= current_collection_day` shartini tekshirish kifoya.
*   **Greedy yondashuvning to'g'riligi**: Nega "eng erta muddat" strategiyasi optimal? Chunki biz har doim eng qisqa muddat ichida yig'ilishi kerak bo'lgan yukni birinchi bo'lib ko'rib chiqamiz. Bu yukni yig'ishni keyinga qoldirish, boshqa yuklarning muddatini ham tugatishi mumkin, natijada ko'proq sayohat qilishga to'g'ri keladi. Bu yukni uning tugash kunida yig'ish esa, boshqa yuklar uchun maksimal yig'ish oynasini saqlab qoladi va ularni ham shu sayohatda yig'ish imkoniyatini oshiradi.
