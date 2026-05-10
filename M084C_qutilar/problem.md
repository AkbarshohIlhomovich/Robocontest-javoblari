# M084C — Qutilar

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 16 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M084C

## Masala matni

Ikkita quti mavjud Birinchisining o'lchami
\(A_1*B_1*C_1\)
, ikkinchisiniki esa
\(A_2*B_2* C_2\)
. Bir qutini ikkichisining ichiga to'liq joylashtirish mumkinmi?
Kiruvchi ma'lumotlar:
Kirish faylining birinchi qatorida birinchi quti o'lchamlari bo'sh joy bilan ajratilgan holda kiritiladi. Keyingi qatorda ikkinchi quti o'lchamlari kiritiladi. Sonlar orasi bo'sh joy bilan ajratiladi. Barcha sonlar butunligi va
\(10^3\)
dan oshmasligi kafolatlanadi.
Chiquvchi ma'lumotlar:
Agar qutilar o'lchami bir xil bo'lsa “Qutilar o'zaro teng”;
Agar ikkinchi quti birinchi qutiga joylasha olsa “Birinchi quti ikkinchisidan katta”;
Agar ikkinchi quti birinchi qutiga joylasha olsa “Birinchi quti ikkinchisidan kichik”;
Boshqa har qanday holatda “Qutilarni solishtirib bo'lmaydi” jumlasini chop eting.

## Sample testlar

### Sample 1

**Input:**
```
1 2 3
2 1 3
```

**Output:**
```
Qutilar o'zaro teng
```

### Sample 2

**Input:**
```
4 5 6
4 4 3
```

**Output:**
```
Birinchi quti ikkinchisidan katta
```

### Sample 3

**Input:**
```
4 5 6
5 6 8
```

**Output:**
```
Birinchi quti ikkinchisidan kichik
```

### Sample 4

**Input:**
```
4 5 6
7 2 4
```

**Output:**
```
Qutilarni solishtirib bo'lmaydi
```
