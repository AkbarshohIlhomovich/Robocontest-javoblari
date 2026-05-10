# M069G — Good binary tree

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M069G

## Masala matni

Full binary tree - har bir tugun uchun bolalari 0 yoki 2 ta bo'lgan va har bir tuguni 1 dan K gacha raqamlangan tree hisoblanadi. Bunda K - daraxtdagi tugunlar soni.
A tugun B tugundan katta deyiladi - agar A tugunning tartib raqami B tugunning tartib raqamidan katta bo'lsa.
Tugunning balandligi deb shu tugundan boshlab ildiz tugungacha bo'lgan masofaga aytiladi.
Good binary tree deb quyidagicha xususiyatli tree ga aytiladi:
Har bir tugun uchun, agar uning bolalari mavjud bo'lsa, shu tugun bolalaridan kichik;
Har bir tugun uchun, agar uning bolalari mavjud bo'lsa, shu tugunning chap tomonidagi eng katta tugun o'ng tomonidagi eng kichik tugundan kichik;
Sizga Good Binary tree barglarining balandliklari berilgan. Good Binary Tree qanday bo'lishini aniqlang.
Kiruvchi ma'lumotlar:
1-qatorda N butun soni - barglar soni kiritiladi.
Keyingi qatorda N ta butun son har bir barg balandligi berilgan. E'tibor bering barglar chapdan o'ngga qarab tartiblangan.
2 ≤ N ≤ 50 000
Kiritilgan ma'lumotlarda har doim javob mavjudligi kafolatlanadi.
Chiquvchi ma'lumotlar:
Birinchi qatorda daraxtdagi tugunlar sonini chop eting.
Keyingi qatorda daraxtni chop eting. Bunda i-raqam i-tugunning otasi bo'lishi kerak. Ildiz tugunning otasi bo'lmaganligi sababli ildiz ning otasini 0 deb oling.

## Sample testlar

### Sample 1

**Input:**
```
3
1 2 2
```

**Output:**
```
5
0 1 1 3 3
```

### Sample 2

**Input:**
```
7
2 2 2 5 5 4 3
```

**Output:**
```
13
0 1 2 2 1 5 5 7 8 9 9 8 7
```

### Sample 3

**Input:**
```
8
1 3 4 4 3 4 5 5
```

**Output:**
```
15
0 1 1 3 4 4 6 6 3 9 9 11 11 13 13
```
