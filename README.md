<h1 align="center">Robocontest.uz yechimlari</h1>

<p align="center">
  <i><a href="https://robocontest.uz">robocontest.uz</a> platformasidan masalalarning <b>C++17 yechimlari</b> va o'zbek tilida batafsil tushuntirishlari</i>
</p>

<p align="center">
  <a href="./INDEX.md"><img alt="Yechilgan" src="https://img.shields.io/badge/yechilgan-36+-brightgreen?style=for-the-badge"></a>
  <img alt="Til" src="https://img.shields.io/badge/til-C%2B%2B17-00599C?style=for-the-badge&logo=cplusplus">
  <img alt="Tushuntirishlar" src="https://img.shields.io/badge/docs-o'zbek-blue?style=for-the-badge">
  <img alt="Litsenziya" src="https://img.shields.io/badge/litsenziya-MIT-yellow?style=for-the-badge">
</p>

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

## Tezkor navigatsiya

**Barcha yechimlar bo'yicha to'liq jadval** → [INDEX.md](./INDEX.md)

Tanlangan masalalar:

| Masala | Kategoriya |
|--------|-----------|
| [A0001 — A+B](./A0001_ab) | Uzun sonlar arifmetikasi |
| [A0002 — Dasturchilar kuni](./A0002_dasturchilar_kuni) | Sana arifmetikasi |
| [A0006 — O'yin](./A0006_oyin) | Sonlar nazariyasi |
| [A0020 — Kanfetlar](./A0020_kanfetlar) | Dinamik dasturlash |
| [A0021 — Smith soni](./A0021_smith_soni) | Sonlar nazariyasi |
| [A0022 — Super daraja](./A0022_super_daraja) | Sonlar nazariyasi |
| ... | _va boshqa 30+ masala — [INDEX.md](./INDEX.md) ga qarang_ |

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

## Litsenziya

**MIT** — kodni erkin ishlatishingiz mumkin. Lekin o'rganishga vaqt sarflamasangiz, foyda kam bo'ladi.

---

<p align="center">
  <sub>Robocontest.uz — O'zbekistondagi yetakchi competitive programming platforma.<br>Mualliflar va platforma jamoasiga rahmat.</sub>
</p>
