# A0015 — Raqamlangan to'plar

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 16 MB  
**Qiyinchilik**: 25%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/A0015

## Masala matni

Hasan va Husan o'yin o'ynashmoqda. Ularda 0 dan
\(N-1\)
gacha raqamlangan to'plar mavjud. Husan Hasandan to'plarning o'rnini o'zgartirishni, ya'ni tartibini 0,1,2,3 dan 3,2,1,0 ga o'zgartirishni so'raydi. Keyinchalik u Hasandan to'plarning tartibini o'zgartirishni har safar bir pozitsiya o'ngdan boshlashni va toki oxirgi pozitsiyagacha shu ishni takrorlashni so'raydi.
Masalan:
\(N = 5\)
bo'lganida
\((0, 1, 2, 3, 4) → (4, 3, 2, 1, 0) → (4, 0, 1, 2, 3) → (4, 0, 3, 2, 1) → (4, 0, 3, 1, 2) → (4, 0, 3, 1, 2)\)
.
O'yin oxirida Husan Hasandan o'yinning boshida K - tartibdagi element o'yin oxirida qaysi tartibda bo'lishini so'raydi(tartiblash 0 dan boshlangan). Agarda Hasan to'g'ri javob bera olsa o'yinda Hasan g'olib bo'ladi, aks holda Husan. Hasanga o'yinda g'olib bo'lishiga yordam bering.
Kiruvchi ma'lumotlar:
INPUT.TXT kirish faylining dastlabki qatorida bitta butun son,
\(T(1 ≤ T ≤ 50)\)
jami o'yinlar soni kiritiladi. Keyingi T qatorning har birida ikkitadan butun son,
\(N(1 ≤ N ≤ 10^5)\)
va
\(K(0 ≤ K < N)\)
sonlari kiritiladi.
Chiquvchi ma'lumotlar:
OUTPUT.TXT chiqish fayliga har bir o'yin uchun alohida qatorda o'yin boshida K - tartibdagi to'p o'yin oxirida qaysi tartibda bo'lishini chop eting!

## Sample testlar

### Sample 1

**Input:**
```
2
3 1
5 2
```

**Output:**
```
2
4
```
