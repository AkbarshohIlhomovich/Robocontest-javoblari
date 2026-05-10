# M034F — Tadqiqotchi Fedya

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 64 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M034F

## Masala matni

Tadqiqotchi Fedya bir kuni bir shahardan boshqasiga borish haqida o'ylab qoldi. Ammo u unchalik ham boy bo'lmagani uchun sizdan yordam so'ramoqchi qaysi shahardan qaysi shaharga borsa eng qimmatga tushadi shuni bilmoqchi. Har bitta shaharga kirish uchun badal mavjud.Ba'zi shaharlarda bu qiymat manfiy chunki ular turizmni rivojlantirishmoqchi. Bunda
i
shahardan
j
shaharga borish narxi
|a[i] - a[j]| + |i - j|
a[i] - i-shaharga kirish badali.
Bunda indekslash noldan boshlanadi.
Fedyaga bu narxni topishda yordam bering.
Kiruvchi ma'lumotlar:
Birinchi qatorda n shaharlar soni. Ikkinchi qatorda esa mos ravishda n ta shaharga kirish badali.
1 <= n <= 5*(10^5
)
-10^6
<=
a[i]
<= 10^6
Chiquvchi ma'lumotlar:
1 ta butun son eng maksimal narx bir shahardan boshqasiga sayohat qilish uchun.

## Sample testlar

### Sample 1

**Input:**
```

|a[i] - a[j]| + |i - j|
a[i] - i-shaharga kirish badali.
```

**Output:**
```

1 <= n <= 5*(105)
-106 <= a[i] <= 106
```

### Sample 2

**Input:**
```
3
1 3 -1
```

**Output:**
```
5
```

### Sample 3

**Input:**
```
4
5 9 2 6
```

**Output:**
```
8
```
