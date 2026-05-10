# M070C — Aliens (O'zga sayyoraliklar)

**Vaqt limiti**: 4000 ms  
**Xotira limiti**: 512 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M070C

## Masala matni

Gulnozaning
\(N × M\)
o’lchamli bog’i bor. Agar
\(a[i][j] = “T”\)
bo’lsa
\((i, j)\)
katakda daraxt bor, aks holda katak bo’sh.
Gulnozaning ukasi Yahyo esa koinotga juda ham qiziqadi va u o’zga sayyoraliklarga romb ko’rinishida xabar jo’natmoqchi. Buning uchun u bog’ning bir-nechta kataklariga toshlar o’rnatib chiqishi mumkin. Toshlar yuqoridan qaraganda romb ko’rinishini hosil qilishi lozim. Biroq Yahyo daraxtlarga ziyon yetkazmoqchi emas (Daraxtlarni asrang!).
Xabar qanchalik katta bo’lsa, o’zga sayyoraliklar uni qabul qilish ehtimoli shunchalik ortadi. Iloji boricha ko’p tosh qo’yish orqali romb yarating!
Kiruvchi ma'lumotlar:
Birinchi qatorda sizga
\(N\)
va
\(M\)
beriladi, Gulnozaning bog’ining o’lchamlari.
Keyingi
\(N\)
ta qatorda
\(M\)
tadan belgi, bunda “
\(T\)
” - daraxtni bildirsa, “
\(.\)
” - bo’sh katakni bildiradi.
Chegaralar
•
\(3 ≤ N, M ≤ 5 000\)
•
\(a[i][j] = “T”\)
yoki “
\(.\)
”, barcha
\(1 ≤ i ≤ N\)
va
\(1 ≤ j ≤ M\)
uchun
• Kamida bitta katak bo’sh ekanligi kafolatlanadi.
Subtasks
1. (10 ball)
\(N = M = 3\)
2. (11 ball)
\(N, M ≤ 30\)
3. (12 ball)
\(N, M ≤ 100\)
4. (13 ball)
\(N, M ≤ 400\)
5. (17 ball)
\(N, M ≤ 1000\)
va ko’pi bilan 10ta daraxt bor
6. (14 ball)
\(N, M ≤ 1000\)
7. (23 ball) Qo’shimcha chegaralarsiz
Chiquvchi ma'lumotlar:
Yagona qatorda ishlatish mumkin bo’lgan maksimal toshlar sonini chiqaring.

## Sample testlar

### Sample 1

**Input:**
```
7 6
.T...T
..T...
T....T
......
T.....
......
...T..
```

**Output:**
```
13
```
