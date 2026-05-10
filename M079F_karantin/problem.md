# M079F — Karantin

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M079F

## Masala matni

Robolandiya
\(N\)
ta shaharni
\(M\)
ta temir yo'l bilan bog'lagan ajoyib maskan. Bunda istalgan ikki shahar o'rtasida to'g'ridan-to'g'ri bog'langan temir yo'llar soni bittadan ko'p emas. Har bir shahardan boshqasiga reyslar yo'lga qo'yilgan.  Bunda aynan
\(N*(N-1)\)
ta reys mavjud bo'ladi.
Robolandiyada xavfli virus avj oldi. Shu sababli virus tarqagan shaharlarni karantinga olish zarur. Agar qaysidir shahar karantinga olinsa, kiruvchi va chiquvchi barcha yo'llar to'siladi. Shu sababli, ba'zi reyslarni vaqtincha bekor qilishga to'g'ri keladi.
Har bir shahar uchun, agar ushbu shahar karantinga olinsa, nechta reyslar vaqtincha bekor bo'lishini aniqlang.
Kiruvchi ma'lumotlar:
Birinchi qatorda
\(N\)
va
\(M\)
sonlari kiritiladi.
Keyingi
\(M\)
ta qatorning har birida ikkitadan butun son
\(a_i\)
va
\(b_i\)
sonlari kiritiladi. Bu
\(a_i\)
va
\(b_i\)
shaharlar o'zaro bog'langanligini anglatadi.
\(1 \le N \le 10^5\)
\(1 \le M \le 5*10^5\)
\(1 \le a_i, b_i \le N, \ a_i \neq b_i\)
Chiquvchi ma'lumotlar:
N ta qatorni chop eting.
\(i-\)
qatordagi son
\(i-\)
shahar karantinga olinsa, bekor bo'ladigan reyslar soni bo'lishi kerak.

## Sample testlar

### Sample 1

**Input:**
```
5 5
1 2
2 3
1 3
3 4
4 5
```

**Output:**
```
8
8
16
14
8
```
