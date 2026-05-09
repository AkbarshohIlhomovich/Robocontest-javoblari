# A0002 — Dasturchilar kuni

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 16 MB  
**Qiyinchilik**: 13%  
**Kategoriya**: #Oson

**Manba**: https://robocontest.uz/tasks/A0002

## Masala matni

Dasturchilar kuni yilning 255-kunida nishonlanadi(bunda 1 - yanvar nolinchi kun deb hisoblanadi). Berilgan yildagi dasturchilar kuni sanasini aniqlaydigan dastur yozishingiz kerak.
Grigorian taqvimida kabisa yili hisoblanadi:
yil raqami 400 ga bo'linadigan yil
yil raqami 4 ga bo'linadigan, ammo, 100 ga bo'linmaydigan yil
Kiruvchi ma'lumotlar:
INPUT.TXT kirish faylining yagona satrida bizning eraga tegishli bo'lgan yilning nomerini ifodalaydigan 1 dan 9999 gacha bo'lgan butun son berilgan.
Chiquvchi ma'lumotlar:
OUTPUT.TXT chiqish faylining yagona satrida dasturchilar kuni sanasini DD/MM/YYYY formatida chop eting. bu yerda DD — sana, MM — oy raqami(01 — yanvar, 02 — fevral, ..., 12 — dekabr), YYYY — yil raqami.

## Sample testlar

### Sample 1

**Input:**
```
2000
```

**Output:**
```
12/09/2000
```

### Sample 2

**Input:**
```
2009
```

**Output:**
```
13/09/2009
```

### Sample 3

**Input:**
```
9
```

**Output:**
```
13/09/0009
```
