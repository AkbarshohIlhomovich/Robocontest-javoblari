# M076I — Язык Foo

**Vaqt limiti**: 2000 ms  
**Xotira limiti**: 32 MB  
**Qiyinchilik**: 1%  
**Kategoriya**: 

**Manba**: https://robocontest.uz/tasks/M076I

## Masala matni

Ниже вам будет приведен псевдокод некоторой функции Foo. Вам нужно понять, как работает эта функция, и лучше ее реализовать.
function Foo(array_of_ints a): // input parameters: array of integers
result = 0
while size(a) > 2: // as long as the array length is at least two elements
sort(a) // sort the array in ascending order
n = size(a)
x = a[0] + a[n - 2]
result += x // add x to the accumulated result
delete(a, n-2) // delete element by index (n-2)
delete(a, 0) // delete element at index 0
add(a, x) // add element by value x to end of array
return sum(a) + result // add the sum of elements to the accumulated result
Обратите внимание, что этот псевдокод использует 0-индексацию массива.
Kiruvchi ma'lumotlar:
Первая строка входных данных содержит одно целое число
\(n\)
(1 ≤
\(n\)
≤ 300 000) — количество элементов в массиве
\(a\)
.
Вторая строка содержит
\(n\)
целых чисел
\(a_i\)
(0 ≤
\(a_i\)
≤ 1 000 000). Числа в строке разделены одинарными пробелами.
Chiquvchi ma'lumotlar:
Выведите одно целое число - ответ на задачу.

## Sample testlar

### Sample 1

**Input:**
```
1
362018
```

**Output:**
```
362018
```

### Sample 2

**Input:**
```
3
3 6 2018
```

**Output:**
```
2036
```

### Sample 3

**Input:**
```
6
3 6 2 0 1 8
```

**Output:**
```
53
```
