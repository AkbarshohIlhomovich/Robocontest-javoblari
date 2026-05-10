# M064D — Qavslar

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M064D

## Masala matni

Ozodbek yaqinda kompyuteriga g'alati text editor dasturini o'rnatdi. Text editor da 3 ta funksiya mavjud:
‘(’ - satrning oxiriga ‘(’ belgisini qo'shadi.
‘)’ - satrning oxiriga ‘)’ belgisini qo'shadi.
‘-’ - satrdagi oxirgi belgini o'chiradi.
Yaxshi satr deb quyidagiga aytiladi:
();
(x) x - yaxshi satr;
xy - x va y yaxshi satrlar;
Sizga q ta so'rov berilgan. Har bir so'rovdan so'ng satrda nechta yaxshi qism satr borligini aniqlang.
Qism satr - satrning boshidan bir nechta (ehtimol 0) va oxiridan bir nechta (ehtimol 0) element o'chirilganidan hosil bo'lgan satr.
Kiruvchi ma'lumotlar:
Kirish faylida bo'sh bo'lmagan s satr - buyruqlar qatori kiritiladi. Satr uzunligi 200000 dan oshmaydi.
‘-’ buyrug'i kelgan vaqtda satr bo'sh bo'lmasligi kafolatlanadi.
Chiquvchi ma'lumotlar:
Har bir uchun alohida qatorda yaxshi qism satrlar sonini chop eting.

## Sample testlar

### Sample 1

**Input:**
```
(()())---)
```

**Output:**
```
0
0
1
1
3
4
3
1
1
2
```

### Sample 2

**Input:**
```
()--()()----)(()()))
```

**Output:**
```
0
1
0
0
0
1
1
3
1
1
0
0
0
0
0
1
1
3
4
4
```
