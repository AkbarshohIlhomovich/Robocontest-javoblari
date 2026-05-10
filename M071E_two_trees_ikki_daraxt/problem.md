# M071E — Two Trees (Ikki daraxt)

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 512 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M071E

## Masala matni

Daraxt deb bog’langan yo’nalmagan asiklik grafga aytiladi.
Sizga ikkita ildizli daraxt berilgan, ikkala daraxtda ham N tadan tugun bor. Birinchi daraxtning ildizi
\(r_1\)
, ikkinchi daraxtning ildizi
\(r_2\)
-tugun.
\(S_1(v)\)
deb shunday
\(u\)
tugunlar to’plamiga aytiladiki, birinchi daraxtda
\(r_1\)
dan u tugunga boruvchi yo’l
\(v\)
tugundan o’tadi. Xuddi shunday,
\(S_2(v)\)
deb shunday
\(u\)
tugunlar to’plamiga aytiladiki, ikkinchi daraxtda
\(r_2\)
dan
\(u\)
tugunga boruvchi yo’l
\(v\)
tugundan o’tadi.
Sizdan so’ralgan narsa barcha
\(1 ≤ v ≤ N\)
tugunlar uchun
\(S_1(v)\)
∩
\(S_2(v)\)
to’plam kesishmalarining o’lchamlarini topish.
Kiruvchi ma'lumotlar:
Birinchi qatorda sizga
\(N\)
,
\(r_1\)
va
\(r_2\)
butun sonlari beriladi - tugunlar soni va daraxtlarning ildizlari.
Ikkinchi qatorda
\(p_1[1], p_1[2],...,p_1[N]\)
butun sonlari beriladi. Bunda barcha
\(1 ≤ i ≤ N\)
va
\( i ≠ r1\)
uchun birinchi daraxtda i va p1 [i] tugunlar o’rtasida qirra bor.
Uchinchi qatorda
\(p_2[1], p_2[2],...p_2[N]\)
butun sonlari beriladi. Bunda barcha
\(1 ≤ i ≤ N\)
va
\(i ≠ r2\)
uchun ikkinchi daraxtda
\(i\)
va
\(p_2[i]\)
tugunlar o’rtasida qirra bor.
E’tibor bering,
\(p_1[r_1]\)
va
\(p_2[r_2]\)
elementlarning qiymatlari −1ga teng.
Chegaralar
• 2 ≤
\(N\)
≤ 3 · 105
• 1 ≤
\(r_1\)
,
\(r_2\)
≤
\(N\)
• 1 ≤
\(p_1[i]\)
≤
\(N\)
, barcha
\(1 ≤ i ≤ N\)
va
\(i≠r_1\)
uchun
•
\(1 ≤ p_2 [i] ≤ N\)
, barcha
\(1 ≤ i ≤ N\)
va
\(i≠r_2\)
uchun
•
\(p_1 [r_1 ] = −1 \)
va
\(p_2 [r_2 ] = −1 \)
\(p_1\)
va
\(p_2\)
massivlar daraxt hosil qilishi kafolatlanadi.
Subtasks
\(c(v) \)
bu
\(p[i] = v\)
bo’ladigan
\(i\)
indekslar soni bo’lsin.
Binar
daraxt deganda barcha
\(1 ≤ v ≤ N\)
tugunlar uchun
\(c(v) = 0\)
yoki
\(c(v) = 2\)
shart bajariladigan
daraxtga aytiladi.
Chiziqli
daraxt deganda barcha 1 ≤ v ≤ N tugunlar uchun c(v) ≤ 1 shart bajariladigan daraxtga
aytiladi.
1. (11 ball) Daraxtlar bir xil, ya’ni
\(r_1 = r_2\)
va
\(p_1 = p_2\)
2. (12 ball)
\(N\)
≤ 3000
3. (13 ball) Ikkala daraxtlar ham binar.
4. (17 ball) Ikkala daraxtlar ham chiziqli.
5. (21 ball) Birinchi daraxt chiziqli.
6. (26 ball) Qo’shimcha chegaralarsiz.
Chiquvchi ma'lumotlar:
Yagona qatorda
\(N\)
ta son chiqaring, har bir
\(v\)
uchun javob.

## Sample testlar

### Sample 1

**Input:**
```
5 3 1
3 3 -1 1 2
-1 1 2 3 3
```

**Output:**
```
2 2 3 1 1
```
