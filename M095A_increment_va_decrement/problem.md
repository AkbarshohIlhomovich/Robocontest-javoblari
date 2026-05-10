# M095A — Increment va Decrement

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M095A

## Masala matni

N ta butun sonlar massivi mavjud. Dastlab, har bir element 0 ga teng. Q so'rovlar mavjud bo'lib, ularning har biri quyidagilardan iborat:
\(1\ X\ Y\)
: birinchi X ta elementlarning qiymatini Y ga oshiring.
\(2\ X\ Y\)
: oxirgi X ta elementlarning qiymatini Y ga kamaytiring.
Barcha so'rovlarni bajargandan so'ng, har bir element o'zining mutlaq qiymati bilan almashtiriladi. Nihoyat, massivning eng katta elementining qiymati qanday?
Kiruvchi ma'lumotlar:
Kirish faylining birinchi qatorida 2 ta butun son - N va Q
\((1 \le N \le 10^9, 1 \le Q \le 10^5)\)
kiritiladi. Keyingi Q ta qatorning har birida 3 tadan butun son - T, X, Y
\((T \isin (1, 2),  1 \le X \le N, 1 \le Y \le 10^9)\)
kiritiladi.
Chiquvchi ma'lumotlar:
Barcha so'rovdan so'ng, massivdagi absolyut qiymati eng katta bo'lgan sonni chop eting.

## Sample testlar

### Sample 1

**Input:**
```
6 3
1 2 3
2 3 5
1 4 1
```

**Output:**
```
5
```
