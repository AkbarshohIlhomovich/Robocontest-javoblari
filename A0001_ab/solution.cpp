#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

// Competitive programmingda tez I/O uchun odatiy
// using namespace std; da #include <bits/stdc++.h> ishlatilganda ham kiradi.
// Hozirgi holatda faqat std::string, std::reverse, std::cin, std::cout, std::endl ishlatiladi,
// shuning uchun <iostream>, <string>, <algorithm> kiritildi.
using namespace std;

// Katta butun sonlarni (string ko'rinishida) qo'shish funksiyasi
string big_int_add(string num1, string num2) {
    // Sonlarni teskari tartibda saqlash, bu qo'shishni birinchi (eng kichik) raqamdan boshlash imkonini beradi.
    // Bu qo'lda qo'shish usuliga o'xshaydi.
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result = ""; // Natijani saqlash uchun string
    int carry = 0;      // Qoldiq (o'tkazish)
    int i = 0;          // Birinchi sonning indeks bo'yicha yuruvchi pointeri
    int j = 0;          // Ikkinchi sonning indeks bo'yicha yuruvchi pointeri

    // Ikkala sonning barcha raqamlarini yoki qoldiq mavjud bo'lsa, davom etamiz
    while (i < num1.length() || j < num2.length() || carry) {
        // Birinchi sondan raqamni olish, agar son tugagan bo'lsa 0 deb hisoblaymiz
        int digit1 = (i < num1.length()) ? (num1[i] - '0') : 0;
        // Ikkinchi sondan raqamni olish, agar son tugagan bo'lsa 0 deb hisoblaymiz
        int digit2 = (j < num2.length()) ? (num2[j] - '0') : 0;

        // Joriy raqamlar va qoldiqni qo'shamiz
        int current_sum = digit1 + digit2 + carry;
        
        // Yangi qoldiqni hisoblaymiz
        carry = current_sum / 10;
        
        // Joriy yig'indining oxirgi raqamini natijaga qo'shamiz
        result += to_string(current_sum % 10);

        // Keyingi raqamga o'tish
        i++;
        j++;
    }

    // Natija stringi teskari tartibda bo'lgani uchun uni to'g'irlash
    reverse(result.begin(), result.end());

    // Agar natija "00", "0123" kabi boshlang'ich nollarga ega bo'lsa, ularni olib tashlaymiz.
    // Biroq, bizning algoritmimizda, agar kirish "0" bo'lmasa, yakuniy natijada boshlang'ich nol bo'lmaydi.
    // Yagona istisno: agar natija "0" bo'lsa (masalan, 0+0), u holda "0" chiqishi kerak.
    // Bizning algoritm "0" ni to'g'ri qaytaradi, "00" kabi narsalarni yaratmaydi.
    // Shuning uchun bu yerda maxsus boshlang'ich nollarni o'chirishga hojat yo'q.

    return result;
}

int main() {
    // Standart I/O (cin/cout) bilan C++ streamlarini sinxronizatsiyasini o'chirish
    // Bu kirish/chiqish operatsiyalarini tezlashtiradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0); // cin va cout o'rtasidagi bog'liqlikni bekor qilish

    string a, b; // Kiruvchi sonlar uchun stringlar
    cin >> a >> b; // Sonlarni string sifatida o'qish

    // Qo'shish funksiyasini chaqirish va natijani chop etish
    cout << big_int_add(a, b) << endl;

    return 0; // Dastur muvaffaqiyatli yakunlandi
}
