# M074B — Daraxtdagi LIS

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 64 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M074B

## Masala matni

N ta tugundan tashkil topgan daraxt mavjud.
\(i-\)
yo'l
\(u_i\)
va
\(v_i\)
tugunlarni o'zaro bog'laydi va qiymati
\(a_i\)
ga teng. 1 dan N gacha bo'lgan har bir k butun soni uchun quyidagini aniqlang:
Yo'llarga yozilgan butun sonlarni 1-yo'ldan k-yo'lgacha bo'lgan eng qisqa yo'l bo'ylab ular paydo bo'ladigan tartibda qatorlab ketma-ketlik hosil qilamiz.  Ushbu ketma-ketlikning eng uzun ortib boruvchi pastki ketma-ketligi (LIS)ining uzunligini toping.
Bu yerda uzunligi
\(L\)
boʻlgan
\(A\)
ketma-ketlikning eng uzun ortib boruvchi pastki ketma-ketligi
\(M\)
ning mumkin boʻlgan eng katta qiymatiga ega boʻlgan
\(A_{i_1}\)
,
\(A_{i_2}\)
,...,
\(A_{i_M}\)
qatori boʻlib,
\(1≤i_1 <i_2 <...<i_M ≤L\)
va
\(A_{i_1} < A_{i_2} <...< A_{i_M}\)
bo'ladi.
Kiruvchi ma'lumotlar:
Birinchi qatorda N butun soni kiritiladi.
Keyingi qatorda N ta butun son a massiv elementlari kiritiladi
Keyingi N-1 ta qatorning har birida 2 tadan butun son
\(u_i\)
va
\(v_i\)
kiritiladi.
\(2 \le N \le 2*10^5\)
\(1 \le a_i \le 10^9\)
\(1 \le u_i, v_i \le N\)
\(u_i \neq v_i\)
Graf daraxt ekanligi kafolatlanadi.
Barcha qiymatlar butun sonlardir.
Chiquvchi ma'lumotlar:
N qatorni chop eting.  k-chi qator, 1-yo'ldan k-yo'lgacha bo'lgan eng qisqa yo'ldan olingan ketma-ketlikning eng uzun o'sib boruvchi pastki ketma-ketligi uzunligini chop eting.

## Sample testlar

### Sample 1

**Input:**
```
10
1 2 5 3 4 6 7 3 2 4
1 2
2 3
3 4
4 5
3 6
6 7
1 8
8 9
9 10
```

**Output:**
```
1
2
3
3
4
4
5
2
2
3
```
