# M069F — Batalyon

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M069F

## Masala matni

Harbiy bazada N ta batalyon mavjud. i-batalyon A[i] ta askardan tashkil topgan. Batalyonlar tartib bilan joylashgan, ya'ni 1-batalyon eng oldinda, N-batalyon esa eng oxirida joylashadi. Harbiy bazaga Q kun davomida dushmanlar bostirib keladi, ya'ni j-kuni B[j] ta qo'shindan tashkil topgan dushman askarlari hujumga keladi. Batalyonlar birin-ketin dushmanga qarshi chiqadi. Agar dushman soni batalyondagi askarlar sonidan kam bo'lmasa, batalyon butunlay yo'q bo'lib ketadi va keyingi batalyon dushman tomon boradi. Agar barcha batalyon qirilib ketsa (dushman askarlari g'alaba qildim deb o'ylab bu jang maydonini tark etishadi), kun oxirida ular o'rniga xuddi shuncha askarlardan tashkil topgan batalyonlar tashkil qilinadi .  Har bir kun uchun kun oxirida nechta batalyon qolganini chop eting.
Bitta askar faqat bitta dushmanga qarshi chiqa oladi va ikkisi ham halok bo'ladi, ya'ni 4 ta dushman askari bo'lsa va batalyondagi askarlar soni 10 ta bo'lsa, hujumdan so'ng batalyonda 6 kishi tirik qoladi.
Kiruvchi ma'lumotlar:
Birinchi qatorda N va Q batalyon va hujum kunlari soni kiritiladi.
Keyingi qatorda N ta butun son Ai elementlari kiritiladi.
Keyingi qatorda Q ta butun son Bi elementlari kiritiladi.
1 ≤ N, Q ≤ 100 000
1 ≤ Ai ≤ 1 000 000 000
1 ≤ Bi ≤ 10^18
Chiquvchi ma'lumotlar:
Har bir kun uchun kun so'ngida nechta batalyon tirik qolganini chop eting.

## Sample testlar

### Sample 1

**Input:**
```
8 4
2 10 5 9 9 4 5 8 
18 19 12 2
```

**Output:**
```
5
3
1
1
```

### Sample 2

**Input:**
```
4 4
2 3 1 2
6 1 4 4
```

**Output:**
```
1
1
4
3
```
