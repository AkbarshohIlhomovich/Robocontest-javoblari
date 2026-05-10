# M069J — O'quv mashg'uloti

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M069J

## Masala matni

Bugun N ta askarlar o'quv-mashg'ulot maydoniga amaliyot uchun kelishdi. Maydonning omborxonasida 1 dan M gacha raqamlangan M turdagi avtomat mavjud. Har bir askar A[i] turdagi avtomatda mashg'ulot o'tkazishni xohlaydi. Maydonda K ta otish maydonchasi mavjud. Kichik maydonchalarning har birida 1 kishi faqatgina bitta avtomatdan foydalangan holda mashg'ulot o'tkaza oladi. Boshida hamma kichik maydonchalar bo'sh.
i-askarning navbati kelgan vaqt agar kichik maydonchalarning birortasida u yoqtirgan turdagi avtomat bo'lsa, shu maydonchada mashg'ulot o'tkazadi. Mavjud bo'lmasa, omborxonadan o'zi yoqtirgan turdagi avtomatni olib chiqadi hamda istalgan bo'sh maydonga joylashtiradi. Agar hamma maydoncha band bo'lsa, istalgan birorta maydonchada turgan qurolni omborxonaga qo'yib o'zi istagan turdagi qurolni joylashtirishi mumkin. Eski qurolni omborxonaga qo'yish va yangisini olib kelish uchun bir marta borib kelish kifoya (borishda eskisini tashlab, qaytayotganda yangisini olib keladi). Mashg'ulotni tugatgandan so'ng, qurol shu maydonchada qoladi.
Har bir askar navbatma-navbat mashg'ulot o'tkazsa va optimal harakat qilishsa, eng kamida necha marotaba omborxonaga borish kerak bo'ladi?
Kiruvchi ma'lumotlar:
Birinchi qatorda 3 ta butun son M, K, N - qurollar soni, kichik maydonchalar soni va askarlar soni kiritiladi.
Keyingi qatorda M ta butun son kiritiladi, i-son i-askar qaysi avtomatni yoqtirishini ifodalaydi.
1 ≤ M ≤ 500 000
1 ≤ K ≤ N  ≤ 100 000
Chiquvchi ma'lumotlar:
Barcha askar optimal harakat qilsa, minimum necha marta omborxonaga borish kerak bo'lishini chop eting.

## Sample testlar

### Sample 1

**Input:**
```
3 2 7
2
3
1
2
1
2
3
```

**Output:**
```
4
```

### Sample 2

**Input:**
```
5 3 8
1
5
3
5
3
2
4
2
```

**Output:**
```
5
```
