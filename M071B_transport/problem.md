# M071B — Transport

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 128 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M071B

## Masala matni

Dadorlandtiria mamlakatida
\((N + 1)\)
ta shahar bor va ular 1 dan
\((N + 1)\)
gacha raqamlangan.Shuningdek, mamlakatda 4 xil transport turi bor: avtobus, taksi, poyezd, samolyot.Sizga o’lchamlari 4 × N bo’lgan ikki o’lchamli a massiv berilgan.
\(a[t][i]\)
bu
\(t\)
-transport yordamida
\(i\)
-shahardan
\((i + 1)\)
-shaharga borish uchun chipta narxi. Agar
\(a[t][i]\)
= −1 bo’lsa u holda bu transport bilan
\(i\)
va
\((i + 1)\)
-shaharlar orasida yurib bo’lmaydi. Bundan tashqari, har bir transport uchun oylik abonement mavjud. Agar siz qaysidir transportga abonement sotib olsangiz undan tekinga xohlaganingizcha foydalanishingiz mumkin.
\(t\)
-transport abonementi
\(c[t]\)
dollar turadi. Vazifangiz 1-shahardan
\((N + 1)\)
-shaharga borish uchun eng kamida qancha pul sarflash kerakligini topish. E’tibor bering, Dadorlandtiria mamlakatida barcha yo’llar bir tomonlik. Ya’ni i-shahardan
\((i + 1)\)
-shaharga o’tish mumkin, biroq
\((i + 1)\)
-shahardan
\(i\)
-shaharga o’tib bo’lmaydi.
Kiruvchi ma'lumotlar:
Birinchi qatorda sizga
\(N , c[1], c[2], c[3], c[4]\)
sonlari beriladi - yo’llar soni va abonement narxlari.
Keyingi 4ta qatorda
\(N\)
tadan butun son, ikki o’lchamli
\(a\)
massiv elementlari.
Chegaralar
•
\(1 ≤   N  ≤ 10^5\)
•
\( 1 ≤   c[t]   ≤ 10^9\)
, barcha
\(1 ≤ t ≤ 4 \)
uchun
•
\(−1 ≤   a[t][i]   ≤ 10^9\)
, barcha
\(1 ≤ t ≤ 4 \)
va
\(1 ≤  i   ≤   N\)
uchun
Subtasks
1. (11 ball)
\(a[i][j] ≠ −1\)
2. (10 ball) Abonement sotib olmasdan ham optimal javob topish mumkin.
3. (20 ball) Faqat 1 ta transportga abonement sotib olish orqali optimal javob topish mumkin.
4. (21 ball) Ko’pi bilan 2ta transportga abonement sotib olish orqali optimal javob topish mumkin.
5. (29 ball) Faqatgina 1 - va/yoki 2 - turdagi transportlar orqali optimal javobni topish mumkin.
6. (9 ball) Qo’shimcha chegaralarsiz.
Chiquvchi ma'lumotlar:
Yagona qatorda 1-shahardan
\((N + 1)\)
-shaharga borish uchun minimal pul miqdori.

## Sample testlar

### Sample 1

**Input:**
```
5 11 5 10 99
-1 5 4 -1 -1
4 -1 -1 -1 9
-1 8 -1 6 -1
10 10 10 10 10
```

**Output:**
```
19
```
