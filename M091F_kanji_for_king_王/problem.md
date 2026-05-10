# M091F — Kanji for king (王)

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M091F

## Masala matni

N tugunli daraxt bor. Tugunlar 1 dan N gacha raqamlangan. Daraxtning nechta har xil sub-daraxti(bir yoki bir nechta qo’shni tugunlardan tashkil topgan qismi)ni "Kanji for King" daraxti shaklida ifodalash mumkinligini aniqlang!
Kanji for king daraxti:
Agar bitta sub-daraxtda qaysidir tugun mavjud bo'lsa, lekin boshqa sub-daraxtda bo'lmasa, ikkita sub-daraxt har xil hisoblanadi.
Daraxt - sikl mavjud bo'lmagan va bir tugundan boshqasiga har doim yo'l mavjud bo'lgan graf.
Kiruvchi ma'lumotlar:
Kirish faylining 1-qatorida
\(N(1 \le N \le 10^5)\)
- tugunlar soni kiritiladi. Keyingi N-1 ta qatorning har biri ikkita butun son -
\(u\)
va
\(v\)
\((1 \le u , v \le N, u \ne v\)
kiritiladi - bu degani
\(u\)
va
\(v\)
tugunlar o'zaro bog'langan.
Chiquvchi ma'lumotlar:
Daraxtning nechta har xil sub-daraxtini "Kanji for King" daraxti shaklida ifodalash mumkinligini aniqlang, hamda uni
\(10^9+7\)
ga bo'lgandagi qoldiqni chop eting.

## Sample testlar

### Sample 1

**Input:**
```
9
1 2
2 3
4 5
5 6
7 8
8 9
2 5
5 8
```

**Output:**
```
1
```

### Sample 2

**Input:**
```
17
1 2
2 3
4 5
5 6
7 8
8 9
2 5
5 8
10 11
11 12
13 9
9 14
15 16
16 17
11 9
9 16
```

**Output:**
```
10
```
