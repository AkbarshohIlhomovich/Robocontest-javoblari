# M080F — Dunes

**Vaqt limiti**: 1000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M080F

## Masala matni

Geographer Grigory Georgievich is studying the formation of sand dunes. He chose a very long dune and divided it into a huge number of sections, numbering them from
\(1\)
to
\(10^9.\)
Grigory Georgievich's theory states that initially the height of the sand relative to some arbitrary mark on all sections was zero. After that, there were n strong gusts of wind that could alter the landscape. Wind gust number
\(i\)
had a force of
\(x_i\)
and acted on sections from
\(l_i\)
to
\(r_i\)
. As a result of this gust, the height of section number
\(l_i\)
increased by
\(x_i\)
, the height of section number
\(l_i+1\)
decreased by
\(x_i\)
, the next one increased again by
\(x_i\)
, and so on until section number
\(r_i\)
, inclusively. Knowing all the information about all
\(n\)
gusts of wind, Grigory Georgievich wants to determine the final stabilized height of some m sections that interest him. Help him
Kiruvchi ma'lumotlar:
The first line of the input file contains two natural numbers
\(n\)
and
\(m\)
\((1≤n,m≤1000)\)
— the number of wind gusts and the number of sections whose final height interests Grigory Georgievich. Each of the next
\(n\)
lines contains the description of the next wind gust — three integers
\(l_i​,r_i​,x_i​ (1≤l_i​≤r_i​≤10^9; 1≤x_i​≤1000)\)
. Each of the next
\(m\)
lines contains an integer
\(q_i ​(1≤q_ i​≤10^9)\)
— the number of the section for which its final height needs to be determined. The section numbers are given in increasing order.
Chiquvchi ma'lumotlar:

## Sample testlar

### Sample 1

**Input:**
```
2 6
1 6 7
3 7 2
1
2
3
6
7
8
```

**Output:**
```
7
-7
9
-9
2
0
```
