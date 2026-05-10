# M071D — Thanos sort

**Vaqt limiti**: 1500 ms  
**Xotira limiti**: 128 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M071D

## Masala matni

Tanosning saralash algoritmi deb quyidagi saralashga aytiladi: - Agar massiv kamaymaslik tartibida* saralangan bo’lsa, u holda Tanos hech narsa qilmaydi. - Aks holda Tanos cheksizlik toshlari yordamida massivni teng ikkiga bo’ladi va istalgan yarmini o’chirib tashlaydi. - Massiv saralanmagunicha shu ishni davom ettiradi.
Sizda uzunligi
\(N\)
ga teng bo’lgan
\(a[1], a[2], ..., a[N ]\)
massivi bor. Shuningdek, Qta so’rovda sizga
\(l\)
va
\(r\)
sonlari beriladi. Vazifangiz
\(a[l], a[l + 1], ..., a[r]\)
qismmassivni saralash uchun cheksizlik toshlarini eng kamida nechi marta ishlatish kerakligini topish. Bunda berilgan qismmassiv uzunligi 2 ning darajasi ekanligi kafolatlanadi.
*Kamaymaslik tartibida har bir element o’zidan avvalgi elementdan kichkina bo’lmasligi lozim.
Ya’ni
\(a[1] ≤ a[2] ≤ ... ≤ a[N ].\)
Kiruvchi ma'lumotlar:
Birinchi qatorda sizga N va Q sonlari beriladi - elementlar va so’rovlar soni.
Ikkinchi qatorda
\(a[1], a[2], ..., a[N ]\)
- massiv elementlari. Keyingi
\(Q\)
ta qatorda
\(l\)
va
\(r\)
- so’rovlar.
Chegaralar
• 1 ≤
\(N\)
≤ 131 072
• 1 ≤
\(Q\)
≤ 200 000
•
\(1 ≤   a[i]   ≤ 10^9\)
, barcha
\(1 ≤  i   ≤  N\)
uchun
• 1 ≤
\(l\)
≤
\(r\)
≤
\(N\)
, hamda
\(r − l + 1 = 2x\)
,
\(x\)
- nomanfiy butun son
Subtasks
1. (6 ball) So’rovlarda
\(r\)
=
\(l\)
+ 1
2. (13 ball)
\(N\)
≤ 8;
\(Q\)
= 1;
\(l\)
= 1;
\(r\)
= N
3. (21 ball)
\(Q\)
= 1;
\(l\)
= 1;
\(r\)
= N
4. (24 ball) Barcha so’rovlar uchun javob 2dan oshmaydi.
5. (15 ball)
\(N\)
≤ 16384
6. (21 ball) Qo’shimcha chegaralarsiz.
Chiquvchi ma'lumotlar:
\(Q\)
ta qatorda har bir so’rov uchun javobni chiqaring.

## Sample testlar

### Sample 1

**Input:**
```
9 3
3 1 4 1 5 9 2 6 5
1 8
5 5
3 4
```

**Output:**
```
2
0
1
```
