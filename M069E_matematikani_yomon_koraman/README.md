# M069E — Matematikani yomon ko'raman

## Masala haqida
Biloliddin matematikani yomon ko'rgani uchun, sonlarni tagma-tag qo'shish usulini o'ziga xos tarzda bajaradi: u raqamlarni bir-biriga qo'shganda hosil bo'lgan yig'indi (masalan, `5+8=13`) ikkita xonali bo'lib qolsa, ortiqcha raqamni keyingi xonaga o'tkazish o'rniga, shunchaki yonma-yon yozib qo'yadi. Masalan, rasmda ko'rsatilganidek, `6815 + 428` ni qo'shganda, u `612313` natijasini oladi. Berilgan `n` soni Biloliddinning shu usuli bilan olingan natija bo'lsa, yuqoridagi ikkita nomanfiy sonni (ya'ni `A` va `B` ni) necha xil usulda tanlash mumkinligini topish talab qilinadi.

## Yondashuv (g'oya)

Masala Biloliddinning qo'shish usulini tushunishni talab qiladi. Bu usulda, aslida, ikkita son (`A` va `B`) ning bir xonali raqamlari (mos joylashuvdagi) qo'shiladi va hosil bo'lgan yig'indi (u bir xonali yoki ikki xonali bo'lishi mumkin) to'g'ridan-to'g'ri natijaning bir qismi sifatida yoziladi. Yuqoridagi misolda (`6815 + 428 = 612313`) quyidagicha ajratish mumkin:
*   Birlar xonasi: `5 + 8 = 13`
*   O'nlar xonasi: `1 + 2 = 3`
*   Yuzlar xonasi: `8 + 4 = 12`
*   Minglar xonasi: `6 + 0 = 6`
Natijada `6`, `12`, `3`, `13` yig'indilari ketma-ket yozilib, `612313` soni hosil bo'lgan.

Demak, berilgan `n` soni, aslida, bir qator raqamlarning yig'indilarini (ular bir yoki ikki xonali son bo'lishi mumkin) ketma-ket ulash natijasidir. Biz `n` ni o'ngdan chapga qarab tahlil qilib, har bir qismni (bir yoki ikki xonali) ikkita bir xonali sonning (`a` va `b`, `0-9` oralig'ida) yig'indisi deb qarashimiz mumkin. Bu vazifa dinamik dasturlash (Dynamic Programming, DP) yordamida samarali hal qilinishi mumkin.

Asosiy g'oya quyidagicha:
1.  **`count_pairs_func(s)` funksiyasi**: Berilgan `s` yig'indini hosil qilish uchun nechta `(a, b)` juftlik mavjudligini hisoblaydigan funksiya yaratiladi, bu yerda `a` va `b` `0` dan `9` gacha bo'lgan raqamlar.
    *   Agar `0 <= s <= 9` bo'lsa, `s+1` ta juftlik bor (masalan, `s=5` bo'lsa, `(0,5), (1,4), (2,3), (3,2), (4,1), (5,0)` jami 6 ta juftlik).
    *   Agar `10 <= s <= 18` bo'lsa, `19-s` ta juftlik bor (masalan, `s=10` bo'lsa, `(1,9), (2,8), ..., (9,1)` jami 9 ta juftlik).
    *   Boshqa holatlarda `0` juftlik.
2.  **Dinamik dasturlash**: Biz `n` sonini satr ko'rinishida olamiz (`s_n`). `dp[i]` holat (`state`) `s_n` satrining `i`-chi indeksidan boshlab oxirigacha bo'lgan qismini (ya'ni `s_n[i...len-1]`) Biloliddin usuli bo'yicha hosil qilishning necha xil usuli borligini ifodalasin.
    *   Biz `n` ning raqamlari ustidan o'ngdan chapga (ya'ni satrning oxiridan boshiga) yurib chiqamiz.
    *   Har bir `i`-chi indeksda, biz `s_n[i]` ni bitta raqam yig'indisi (`d1`) deb yoki `s_n[i]s_n[i+1]` ni ikkita raqam yig'indisi (`d2`) deb qarashimiz mumkin.
    *   Agar `s_n[i]` bir xonali yig'indi bo'lsa, u `count_pairs_func(d1)` ta juftlik beradi va qolgan `s_n[i+1...len-1]` qismini hosil qilish uchun `dp[i+1]` usul bor.
    *   Agar `s_n[i]s_n[i+1]` ikki xonali yig'indi bo'lsa (va `s_n[i]` `0` ga teng bo'lmasa, chunki `05` kabi ikki xonali yig'indi bo'lmaydi, faqat `5` bo'ladi), u `count_pairs_func(d2)` ta juftlik beradi va qolgan `s_n[i+2...len-1]` qismini hosil qilish uchun `dp[i+2]` usul bor.

## Algoritm qadamlari

1.  **`count_pairs_func(s)` funksiyasini aniqlash**:
    *   `s` o'zgaruvchisi ikkita bir xonali sonning (0-9 oralig'ida) yig'indisini ifodalaydi.
    *   Agar `s` `0` dan `9` gacha bo'lsa, `s+1` ni qaytaring.
    *   Agar `s` `10` dan `18` gacha bo'lsa, `19-s` ni qaytaring.
    *   Boshqa holatlarda (masalan, `s < 0` yoki `s > 18`), `0` ni qaytaring.
2.  **Kirish ma'lumotlarini o'qish**: `n` nomanfiy sonini o'qing.
3.  **Satrga aylantirish**: `n` sonini satr ko'rinishiga o'tkazing (`s_n`). Bu raqamlarni indekslar bo'yicha tahlil qilishni osonlashtiradi. Satr uzunligini (`len`) aniqlang.
4.  **DP massivini inizializatsiya qilish**: `dp` nomli `long long` turidagi massivni `len + 1` o'lchamda yarating va barcha elementlarini `0` ga sozlang.
5.  **Baza holati**: `dp[len] = 1` deb belgilang. Bu `s_n` satrining bo'sh qismi (ya'ni hech qanday raqamlar qolmagan holat) ni hosil qilishning bitta usuli borligini (hech qanday juftlik tanlamaslik) anglatadi.
6.  **DP iteratsiyasi**: `i` indeksini `len - 1` dan `0` gacha (teskari tartibda) kamaytirib iteratsiya qiling:
    *   **Bir xonali raqam sifatida ajratish**:
        *   `s_n[i]` belgisini raqamga aylantiring (`d1 = s_n[i] - '0'`).
        *   `dp[i]` ga `count_pairs_func(d1) * dp[i+1]` qiymatini qo'shing. Bu `s_n[i]` ni alohida yig'indi sifatida ko'rib chiqish va qolgan `s_n[i+1...len-1]` qismini hosil qilish usullarini hisobga olish degani.
    *   **Ikki xonali raqam sifatida ajratish**:
        *   Agar `i + 1 < len` bo'lsa (ya'ni `s_n[i+1]` raqami mavjud bo'lsa) va `s_n[i]` belgisi `'0'` bo'lmasa:
            *   `s_n[i]` va `s_n[i+1]` belgilaridan ikki xonali raqamni hosil qiling (`d2 = (s_n[i] - '0') * 10 + (s_n[i+1] - '0')`).
            *   `dp[i]` ga `count_pairs_func(d2) * dp[i+2]` qiymatini qo'shing. Bu `s_n[i]s_n[i+1]` ni alohida yig'indi sifatida ko'rib chiqish va qolgan `s_n[i+2...len-1]` qismini hosil qilish usullarini hisobga olish degani. `s_n[i] != '0'` sharti, masalan, `05` kabi noto'g'ri ikki xonali raqamlarning hisobga olinmasligini ta'minlaydi, chunki `05` aslida `5` bo'lishi kerak.
7.  **Natijani chop etish**: `dp[0]` elementini chop eting, bu `n` sonining to'liq qismini Biloliddin usuli bo'yicha hosil qilishning umumiy usullari sonidir.

## Murakkablik tahlili

*   **Vaqt murakkabligi**: `O(log10(N))`
    *   `n` sonini satrga aylantirish `O(log10(N))` vaqt talab qiladi, chunki satrning uzunligi `n` ning o'nlik raqamlari soniga (logarifmiga) teng. `N = 10^18` uchun bu taxminan 19 raqam.
    *   Dinamik dasturlash sikli `len` marta, ya'ni `O(log10(N))` marta takrorlanadi. Har bir iteratsiyada bir nechta arifmetik amallar va funksiya chaqiruvlari (doimiy vaqtda bajariladigan) amalga oshiriladi.
    *   Shuning uchun umumiy vaqt murakkabligi `O(log10(N))` bo'ladi, bu berilgan `N` chegarasi (10^18) uchun juda samarali.

*   **Xotira murakkabligi**: `O(log10(N))`
    *   `n` sonining satr ko'rinishini (`s_n`) saqlash uchun `O(log10(N))` xotira kerak.
    *   `dp` massivi ham `len + 1` o'lchamda bo'lib, uning uzunligi `O(log10(N))` ni tashkil qiladi.
    *   Shuning uchun umumiy xotira murakkabligi `O(log10(N))` bo'ladi, bu berilgan 32 MB chegarasiga bemalol sig'adi.

## Kod izohi

```cpp
#include <iostream> // Kirish/chiqish operatsiyalari uchun
#include <string>   // String ma'lumot turi bilan ishlash uchun
#include <vector>   // Dinamik massiv (vektor) bilan ishlash uchun
#include <algorithm> // Boshqa standart algoritmlar uchun (bu masalada ishlatilmagan)

using namespace std; // std nomlar fazosidan foydalanish

// Ikki bir xonali nomanfiy sonning yig'indisi 's' ni hosil qilish mumkin bo'lgan juftliklar sonini hisoblaydi.
long long count_pairs_func(int s) {
    if (s >= 0 && s <= 9) { // Agar yig'indi bir xonali bo'lsa (0-9)
        return s + 1;       // s+1 ta juftlik mavjud (masalan, s=5 uchun 6 ta: (0,5)...(5,0))
    } else if (s >= 10 && s <= 18) { // Agar yig'indi ikki xonali bo'lsa (10-18)
        return 19 - s;      // 19-s ta juftlik mavjud (masalan, s=10 uchun 9 ta: (1,9)...(9,1))
    }
    return 0;               // Boshqa holatlarda (s<0 yoki s>18) juftlik yo'q
}

int main() {
    // Tez kirish/chiqish operatsiyalari uchun standart C++ oqimlarini sinxronizatsiyadan chiqarish
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n; // Kiritiladigan son n, 10^18 gacha bo'lishi mumkin, shuning uchun long long
    cin >> n;    // n ni o'qish

    string s_n = to_string(n); // n sonini stringga aylantirish, raqamlarga indeks orqali kirish uchun
    int len = s_n.length();    // Stringning uzunligi (n dagi raqamlar soni)

    // Dinamik dasturlash massivi (vektor).
    // dp[i] => s_n[i...len-1] qismini Biloliddin usuli bo'yicha hosil qilish usullari soni.
    vector<long long> dp(len + 1, 0);

    dp[len] = 1; // Baza holati: bo'sh qoldiq qismni hosil qilishning bitta usuli bor (hech narsa tanlamaslik)

    // DP iteratsiyasi: stringning oxiridan (len-1) boshiga (0) qarab harakatlanamiz
    for (int i = len - 1; i >= 0; --i) {
        // 1. Joriy s_n[i] raqamini bir xonali yig'indi sifatida ko'rib chiqish
        int d1 = s_n[i] - '0'; // Char raqamni int raqamga aylantirish
        dp[i] += count_pairs_func(d1) * dp[i+1]; // d1 uchun juftliklar sonini keyingi holat (dp[i+1]) bilan ko'paytirib qo'shamiz

        // 2. Joriy s_n[i] va keyingi s_n[i+1] raqamlarini ikki xonali yig'indi sifatida ko'rib chiqish
        // Bu faqat i+1 chegaradan chiqib ketmasa va s_n[i] '0' bo'lmasa amalga oshiriladi
        // (chunki "05" kabi ikki xonali yig'indi faqat "5" sifatida yoziladi)
        if (i + 1 < len) {
            if (s_n[i] != '0') { // Ikki xonali sonning birinchi raqami nol bo'lmasligi kerak
                // Ikki xonali raqamni hosil qilish (masalan, '1' va '2' dan 12)
                int d2 = (s_n[i] - '0') * 10 + (s_n[i+1] - '0');
                // d2 uchun juftliklar sonini keyingi holat (dp[i+2]) bilan ko'paytirib qo'shamiz
                dp[i] += count_pairs_func(d2) * dp[i+2];
            }
        }
    }

    cout << dp[0] << endl; // Natija: dp[0] to'liq n sonini hosil qilish usullari sonini beradi

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
```

## Edge case lar va eslatmalar

*   **`n=0` holati**: Agar `n=0` kiritilsa, `s_n = "0"`, `len=1`. `dp[1]=1`. Loop `i=0` uchun ishlaydi. `d1=0`. `count_pairs_func(0)` `1` ni qaytaradi (faqat `(0,0)` juftligi 0 ni beradi). `dp[0] += 1 * dp[1] = 1*1 = 1`. Ikki xonali tekshiruv `i+1 < len` sharti `0+1 < 1` (yolg'on) bo'lgani uchun o'tkazib yuboriladi. Natija `1`. Bu to'g'ri, chunki `A=0, B=0` juftligi Biloliddin usuli bilan `0` ni beradi, bu bitta usul.
*   **`long long` dan foydalanish**: `n` soni 10^18 gacha bo'lishi mumkin. Bu shuni anglatadiki, natijada olinadigan juftliklar soni ham juda katta bo'lishi mumkin. `dp` massividagi qiymatlar va yakuniy natija `long long` ma'lumot turiga sig'ishi kerak. Masala uchun berilgan testlarda va umumiy `N` chegaralarida `long long` yetarli ekanligi tasdiqlangan.
*   **`s_n[i] != '0'` shartining ahamiyati**: Ikki xonali raqamni ajratishda `s_n[i]` ning `0` bo'lmasligi shart. Misol uchun, agar `n = 105` bo'lsa:
    *   `105` ni `10` va `5` deb ajratish mumkin.
    *   `105` ni `1`, `0` va `5` deb ajratish mumkin.
    *   Lekin `105` ni `1` va `05` deb ajratib bo'lmaydi, chunki `05` (ikkita bir xonali raqam yig'indisi sifatida) aslida `5` deb yozilishi kerak. `s_n[i] != '0'` sharti shu kabi noto'g'ri parchalashlarning oldini oladi va faqat `10` kabi haqiqiy ikki xonali sonlarnigina ikki xonali yig'indi deb hisoblashga imkon beradi.
*   **`i + 1 < len` sharti**: Ikki xonali raqamni ajratish uchun `s_n[i+1]` raqami mavjud bo'lishi kerak. Bu shart DP siklining chegaralardan chiqib ketmasligini ta'minlaydi.
