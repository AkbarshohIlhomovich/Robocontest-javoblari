# R095D — Ifodani maksimallashtirish

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 512 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/R095D

## Masala matni

Sizga n ta sondan tashkil topgan massiv beriladi. Siz quyidagi amalni ko'pida bir marotaba bajarishingiz kerak:
(i va j) juftlikni tanlang va
\(a_i\)
ni qiymatini
\(a_j\)
bilan o'zgartiring. (
\(a[i] = a[j]\)
)
Bu amalni bajarishdan asosiy maqsad esa 1 ta k (1 ≤ k ≤ n) butun sonini tanlash va quyidagi ifoda qiymatini maksimallashtirish:
(
\(a_1\)
&
\(a_2\)
&…&
\(a_k\)
) + (
\(a_{k+1}\)
&
\(a_{k+2}\)
&…&
\(a_n\)
)
Bu yerda & belgisi -
bitwise AND operatori
Kiruvchi ma'lumotlar:
birinchi qatorda n butun soni (2 ≤ n ≤
\(10^5\)
) - massivning uzunligi.
ikkinchi qatorda n ta sondan tashkil topgan a massivi (0 ≤
\(a_i\)
≤
\(10^9\)
)
Chiquvchi ma'lumotlar:
Har bir testcase uchun berilgan ifodaning maksimal qiymatini chop eting

## Sample testlar

### Sample 1

**Input:**
```
6
6 5 4 3 5 6
```

**Output:**
```
10
```

### Sample 2

**Input:**
```
3
0 7 3
```

**Output:**
```
10
```

### Sample 3

**Input:**
```
9
5 0 4 3 3 0 1 3 3
```

**Output:**
```
5
```
