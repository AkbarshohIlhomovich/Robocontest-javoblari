# M088C — Shirinlik

**Vaqt limiti**: 2000 ms  
**Xotira limiti**: 128 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M088C

## Masala matni

Robolandiyada dunyoning boshqa qismlarida bo'lmagan an'ana bor - kuzning boshida bolalar qo'rqinchli liboslar kiyib, uyma-uy yurib, aholidan konfet yig'ishadi.
Zarif va Sunatillo ham konfet yig'ishni rejalashtirmoqda. Ular yo'lning bir tomonida N ta uydan iborat va 1 dan N gacha ketma-ket raqamlangan juda uzun ko'chada yashaydilar. Uylar tartib bilan joylashgan va ular
\(i-\)
uyga tashrif buyurganlarida aynan
\(C_i\)
ta konfet olishadi.
Oxirgi konfet ustida har yili ular o'rtasida janjal kelib chiqqanligi sababli, Zarif va Sunatillo bu safar teng miqdordagi konfet yig'ishga qaror qilishdi. Ularning rejalashtirilgan strategiyasi ma'lum: ikkita L va R uy raqamlarini tanlash va keyin ular orasidagi barcha uylarga tashrif buyurish, ya'ni
\(L, L + 1, . . . , R - 1, R\)
. Shu tarzda ular aynan
\(C_L + C_{L+1} + .. . + C_{R−1} + C_R\)
ta konfet yig'ishadi.
Zarif va Sunatillo juft sonli konfetlarni yig'ish uchun L va R uylarini necha xil usulda tanlashi mumkin?
Kiruvchi ma'lumotlar:
Birinchi qatorda N - konfetlar soni kiritiladi.
Keyingi qatorda N ta butun son -
\(C_i\)
kiritiladi.
\(1 \le N \le 10^6\)
\(1 \le C_i \le 10^9\)
Chiquvchi ma'lumotlar:
Bolalar juft miqdordagi shirinliklar to'plashi mumkin bo'lgan uy raqamlari (L, R) sonini chop eting.

## Sample testlar

### Sample 1

**Input:**
```
4
1 2 3 4
```

**Output:**
```
4
```

### Sample 2

**Input:**
```
1
5
```

**Output:**
```
0
```
