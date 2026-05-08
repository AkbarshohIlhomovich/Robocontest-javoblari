#include <bits/stdc++.h>

using namespace std;

// Modulni doimiy sifatida aniqlaymiz.
// Bu operatsiyalarda xatoliklarni kamaytirishga yordam beradi va kodni o'qishni osonlashtiradi.
const long long MOD = 1e9 + 7; // 10^9 + 7

int main() {
    // Tez I/O uchun standart kutubxona oqimlarini optimallashtiramiz.
    // Bu katta hajmdagi kirish/chiqish operatsiyalarida vaqtni tejashga yordam beradi.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T; // Test holatlari sonini o'qiymiz

    while (T--) {
        long long N;
        cin >> N; // Har bir test holati uchun N sonini o'qiymiz

        // Masaladagi ketma-ketlikni soddalashtiramiz:
        // T_n = n^2 - (n-1)^2
        // T_n = n^2 - (n^2 - 2n + 1)
        // T_n = n^2 - n^2 + 2n - 1
        // T_n = 2n - 1
        //
        // S_n = T_1 + T_2 + ... + T_n
        // S_n = (2*1 - 1) + (2*2 - 1) + ... + (2*n - 1)
        // S_n = 1 + 3 + 5 + ... + (2n - 1)
        // Bu birinchi n ta toq sonning yig'indisi.
        // Birinchi n ta toq sonning yig'indisi n^2 ga teng.
        // Demak, S_n = N^2.

        // Biz N^2 ni MOD ga bo'lgandagi qoldiqni topishimiz kerak.
        // N juda katta bo'lishi mumkin (10^16), shuning uchun N^2 to'g'ridan-to'g'ri hisoblansa,
        // long long tipidan ham oshib ketishi mumkin (10^32 bo'ladi).
        // Shuning uchun modulyar arifmetikadan foydalanamiz:
        // (A * B) % M = ((A % M) * (B % M)) % M
        // Bizning holatda A = N, B = N, M = MOD.
        // Shuning uchun, (N * N) % MOD = ((N % MOD) * (N % MOD)) % MOD.

        // Avval N ni MOD ga bo'lgandagi qoldiqni hisoblaymiz.
        // N % MOD qiymati MOD dan kichik bo'ladi (taxminan 10^9).
        long long N_mod = N % MOD;

        // Keyin N_mod * N_mod ni hisoblaymiz va yana MOD ga bo'lamiz.
        // N_mod * N_mod maksimal qiymati taxminan (10^9)^2 = 10^18 bo'ladi,
        // bu long long tipiga sig'adi.
        long long result = (N_mod * N_mod) % MOD;

        cout << result << "\n"; // Natijani alohida qatorda chiqaramiz
    }

    return 0; // Dastur muvaffaqiyatli yakunlanganini bildiramiz
}
