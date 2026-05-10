---
title: "Robocontest.uz Yechimlari — C++ Algoritm Masalalari Arxivi"
description: "Robocontest.uz masalalari uchun C++17 yechimlari va o'zbek tilida batafsil tushuntirishlar. Algoritm, dinamik dasturlash, sonlar nazariyasi bo'yicha 50+ yechilgan masala."
keywords: "robocontest, robocontest.uz, robocontest yechimlari, robocontest masalalari, C++ algoritm, competitive programming O'zbekiston, dasturlash masalalari, olimpiada yechimlari, PIIMA olimpiada, algoritm darslar, dinamik dasturlash, sonlar nazariyasi, c++17, dasturlash uzbek, olimpiada masalalari"
author: "Akbarshoh Dadamirzayev"
lang: uz
---

<h1 align="center">Robocontest.uz Masalalari Yechimlari — C++ Algoritm Arxivi</h1>

<p align="center">
  <b><a href="https://robocontest.uz">Robocontest.uz</a></b> dasturlash olimpiadasi platformasidagi masalalarning to'liq <b>C++17 yechimlari</b> va o'zbek tilida batafsil tushuntirishlari to'plami.
  Algoritm, ma'lumotlar tuzilmalari, dinamik dasturlash, sonlar nazariyasi va boshqa kategoriyalar bo'yicha hujjatlangan yechimlar.
</p>

> **Robocontest masalalari yechimlari**, **olimpiada yechimlari**, **C++ algoritm**, **competitive programming** va boshqa kalit so'zlar bo'yicha qidiruvda topish mumkin.

<!-- AUTO:badges-START -->
<p align="center">
  <a href="./INDEX.md"><img alt="Yechilgan" src="https://img.shields.io/badge/yechilgan-93-brightgreen?style=for-the-badge"></a>
  <img alt="Til" src="https://img.shields.io/badge/til-C%2B%2B17-00599C?style=for-the-badge&logo=cplusplus">
  <img alt="Tushuntirishlar" src="https://img.shields.io/badge/docs-o'zbek-blue?style=for-the-badge">
  <img alt="Litsenziya" src="https://img.shields.io/badge/litsenziya-MIT-yellow?style=for-the-badge">
</p>
<!-- AUTO:badges-END -->

---

## Nima bu?

Bu — robocontest.uz da hal qilingan masalalarni hujjatlangan ko'rinishda saqlovchi arxiv. Har masala uchun:

- **Yechim kodi** — `solution.cpp` (toza C++17, izohsiz)
- **Masala matni** — `problem.md` (asl matn, sample testlar bilan)
- **Tushuntirish** — `README.md` (o'zbek tilida: yondashuv, algoritm, murakkablik tahlili, kod izohi)
- **Meta ma'lumot** — `meta.json` (vaqt, xotira, submission ID)

---

## Papka tuzilishi

```
solutions/
├── INDEX.md                  ← barcha yechimlar ro'yxati
├── README.md                 ← shu fayl
└── A0001_ab/
    ├── solution.cpp          ← C++ kodi
    ├── README.md             ← o'zbekcha tushuntirish
    ├── problem.md            ← masala matni
    └── meta.json             ← natija (vaqt, xotira)
```

---

## Statistika

<!-- AUTO:stats-START -->
- **Jami yechilgan**: 93 ta masala
- **O'rtacha qiyinchilik**: 3.9%
- **O'rtacha vaqt**: 36.9 ms
- **Eng oxirgi**: [M088C — Shirinlik](./M088C_shirinlik) _(2026-05-10)_
<!-- AUTO:stats-END -->

## Kategoriyalar bo'yicha

<!-- AUTO:categories-START -->
| Kategoriya | Yechilgan |
|-----------|-----------|
| Kategoriyasiz | 79 |
| Oson | 7 |
| Sonlar nazariyasi | 3 |
| Uzun sonlar arifmetikasi | 1 |
| Dinamik dasturlash | 1 |
| Matematika | 1 |
| Matrix | 1 |
<!-- AUTO:categories-END -->

## So'nggi yechilgan masalalar

<!-- AUTO:recent-START -->
| ID | Sarlavha | Kategoriya | Vaqt | Sana |
|----|----------|-----------|------|------|
| [M088C](./M088C_shirinlik) | Shirinlik | - | 110 ms | 2026-05-10 |
| [M079F](./M079F_karantin) | Karantin | - | 204 ms | 2026-05-10 |
| [M079C](./M079C_oyin_maydonchasi) | O'yin maydonchasi | - | 385 ms | 2026-05-10 |
| [M080H](./M080H_merlin) | Merlin | - | 1 ms | 2026-05-10 |
| [M080F](./M080F_dunes) | Dunes | - | 3 ms | 2026-05-10 |
| [M074D](./M074D_xor_va_summa) | Xor va summa | - | 10 ms | 2026-05-10 |
| [M073F](./M073F_javascript_vs_python) | JavaScript vs Python | - | 1 ms | 2026-05-10 |
| [M073H](./M073H_modullar_yigindisi) | Modullar yig'indisi | - | 2 ms | 2026-05-10 |
| [M073G](./M073G_satrni_qayta_qurish) | Satrni qayta qurish | - | 1 ms | 2026-05-10 |
| [M073A](./M073A_vazifalar) | Vazifalar | - | 1 ms | 2026-05-10 |
<!-- AUTO:recent-END -->

**Barcha yechimlar bo'yicha to'liq jadval** → [INDEX.md](./INDEX.md)

---

## Yechim qanday topiladi?

Masalan, **A0001 — A+B** ni ko'rmoqchimisiz?

1. [`A0001_ab/`](./A0001_ab) papkasiga o'ting
2. [`problem.md`](./A0001_ab/problem.md) — masalaning to'liq matni
3. [`solution.cpp`](./A0001_ab/solution.cpp) — C++17 yechimi
4. [`README.md`](./A0001_ab/README.md) — yondashuv va kod izohi (o'zbekcha)

---

## Tushuntirish nimani o'z ichiga oladi?

Har bir masala uchun yozilgan o'zbekcha **README.md** quyidagilardan iborat:

- **Masala haqida** — qisqacha mazmuni
- **Yondashuv (g'oya)** — qaysi algoritm/ma'lumotlar tuzilmasi va nega
- **Algoritm qadamlari** — bosqichma-bosqich
- **Murakkablik tahlili** — vaqt va xotira (Big-O)
- **Kod izohi** — kod bloklarini tushuntirish
- **Edge case lar** — diqqat qilish kerak bo'lgan holatlar

---

## Texnik tafsilotlar

| Sozlama | Qiymat |
|---------|--------|
| **Til** | C++17 |
| **Kompilyator** | GCC 9.3.0 (`g++ -std=c++17 -O2`) |
| **Standart kutubxona** | `<bits/stdc++.h>` |
| **I/O** | stdin/stdout, sinxronizatsiyasiz fast I/O |
| **Platforma** | [robocontest.uz](https://robocontest.uz) |

---

## Yangilash

Repo avtomatik to'ldirib boriladi — har AC olingan masala uchun yangi commit yaratiladi va `main` branchga push qilinadi. Yangilanishlarni kuzatish uchun:

```bash
git clone https://github.com/AkbarshohIlhomovich/Robocontest-javoblari.git
cd Robocontest-javoblari
git pull
```

Eng so'nggi commitlar — [Commits sahifasi](https://github.com/AkbarshohIlhomovich/Robocontest-javoblari/commits/main).

---

## Foydalanish bo'yicha eslatma

Bu yechimlar **o'rganish uchun** mo'ljallangan. Tavsiya etiladi:

- Avval masalani **mustaqil yechishga harakat qiling**
- Qiyin bo'lsa — yondashuvni `README.md` dan o'qing, lekin kodni darhol ko'rmang
- Tushunolmasangiz — kod izohlarini o'qib, qaytadan **o'zingiz yozing**
- To'g'ridan-to'g'ri ko'chirib yuborish — o'rganish nuqtai nazaridan foydasiz

---

## Hissa qo'shish

Xato topdingizmi yoki yaxshiroq yechim taklif qilasizmi? **Issue** oching yoki **Pull Request** yuboring.

<p align="center">
  <a href="https://github.com/AkbarshohIlhomovich/Robocontest-javoblari/issues">
    <img alt="Issues" src="https://img.shields.io/github/issues/AkbarshohIlhomovich/Robocontest-javoblari?style=flat-square">
  </a>
  <a href="https://github.com/AkbarshohIlhomovich/Robocontest-javoblari/pulls">
    <img alt="PRs" src="https://img.shields.io/github/issues-pr/AkbarshohIlhomovich/Robocontest-javoblari?style=flat-square">
  </a>
  <a href="https://github.com/AkbarshohIlhomovich/Robocontest-javoblari/stargazers">
    <img alt="Stars" src="https://img.shields.io/github/stars/AkbarshohIlhomovich/Robocontest-javoblari?style=flat-square">
  </a>
</p>

---

## Muallif

<table>
<tr>
<td>

**Akbarshoh Dadamirzayev** ([@akbarshoh2580](https://robocontest.uz/profile/akbarshoh2580))

- O'quv muassasasi: **Eurosoft**
- Viloyat: Toshkent shahar, Mirzo Ulug'bek tumani
- Murabbiy: [Jasurbek Nurmuhammedov](https://robocontest.uz/profile/jasurbek2003)

</td>
<td>

[![GitHub](https://img.shields.io/badge/GitHub-AkbarshohIlhomovich-181717?style=flat-square&logo=github)](https://github.com/AkbarshohIlhomovich)
[![Robocontest](https://img.shields.io/badge/Robocontest-akbarshoh2580-orange?style=flat-square)](https://robocontest.uz/profile/akbarshoh2580)

</td>
</tr>
</table>

---

## Litsenziya

**MIT** — kodni erkin ishlatishingiz mumkin. Lekin o'rganishga vaqt sarflamasangiz, foyda kam bo'ladi.

---

<p align="center">
  <sub>Robocontest.uz — O'zbekistondagi yetakchi competitive programming platforma.<br>Mualliflar va platforma jamoasiga rahmat.</sub>
</p>
