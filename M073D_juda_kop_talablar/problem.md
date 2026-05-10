# M073D — Juda ko'p talablar

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M073D

## Masala matni

Sizga N, M, Q va Q ta to'rtliklar berilgan
\((a_i, b_i, c_i, d_i)\)
.
Quyidagi shartlarga javob beradigan A ketma-ketligini ko'rib chiqing:
A N ta butun sondan iborat ketma-ketlik
\(1 \le A_1 \le A_2 \le ...\le A_N \le M\)
Ushbu ketma-ketlikning natijasini quyidagicha aniqlaymiz:
Natija barcha indekslar bo'yicha
\(d_i\)
yig'indisi. i shundayki
\(A_{b_i}\)
−
\(A_{a_i}\)
=
\(c_i\)
.  (Agar bunday i bo'lmasa, natija 0 ga teng.)
A ning mumkin bo'lgan maksimal ballini toping.
Kiruvchi ma'lumotlar:
Birinchi qatorda N, M va Q kiritiladi.
Keyingi Q ta qatorning har birida 4 tadan butun son -
\(a_i, b_i, c_i, d_i\)
kiritiladi
Barcha qiymatlar butun musbat sonlar.
\(2 \le N \le 10\)
\(1 \le M \le 10\)
\(1 \le Q \le 50\)
\(1 \le a_i < b_i \le N \ (i = 1, 2, ..., Q)\)
\(0 \le c_i \le M-1 \ (i = 1, 2, ..., Q)\)
\((a_i, b_i, c_i) \neq (a_j, b_j, c_j) \)
bunda
\((i  \neq j)\)
\(1 \le d_i \le 10^5 \ (i = 1, 2, ..., Q)\)
Chiquvchi ma'lumotlar:
A ning mumkin bo'lgan maksimal natijasini chop eting.

## Sample testlar

### Sample 1

**Input:**
```
3 4 3
1 3 3 100
1 2 2 10
2 3 2 10
```

**Output:**
```
110
```

### Sample 2

**Input:**
```
4 6 10
2 4 1 86568
1 4 0 90629
2 3 0 90310
3 4 1 29211
3 4 3 78537
3 4 2 8580
1 2 1 96263
1 4 2 2156
1 2 0 94325
1 4 3 94328
```

**Output:**
```
357500
```
