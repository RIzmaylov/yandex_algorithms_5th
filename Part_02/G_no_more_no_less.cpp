/*
Дан массив целых положительных чисел a длины n. Разбейте его на минимально возможное количество отрезков, 
чтобы каждое число было не меньше длины отрезка которому оно принадлежит. Длиной отрезка считается количество чисел в нем.

Разбиение массива на отрезки считается корректным, если каждый элемент принадлежит ровно одному отрезку.

Формат ввода
Первая строка содержит одно целое число t (1 ≤ t ≤ 1 000) — количество наборов тестовых данных. 
Затем следуют t наборов тестовых данных.

Первая строка набора тестовых данных содержит одно целое число n (1 ≤ n ≤ 105) — длину массива.

Следующая строка содержит n целых чисел a1, a2, …, an (1 ≤ ai ≤ n) — массив a.

Гарантируется, что сумма n по всем наборам тестовых данных не превосходит 2 ⋅ 105.

Формат вывода
Для каждого набора тестовых данных в первой строке выведите число k — количество отрезков в вашем разбиении.

Затем в следующей строке выведите k чисел len1, len2, …, lenk  — длины отрезков в порядке слева направо.

Пример
Ввод	                            Вывод
3                                   3
5                                   1 2 2
1 3 3 3 2                           3
16                                  1 6 9 
1 9 8 7 6 7 8 9 9 9 9 9 9 9 9 9     3
7                                   2 3 2
7 2 3 4 3 2 7

Примечания
Ответы в примере соответствуют разбиениям:

{[1], [3, 3], [3, 2]}

{[1], [9, 8, 7, 6, 7, 8], [9, 9, 9, 9, 9, 9, 9, 9, 9]}

{[7, 2], [3, 4, 3], [2, 7]}

В первом наборе тестовых данных набор длин {1, 3, 1}, соответствующий разбиению {[1], [3, 3, 3], [2]}, 
также был бы корректным.

тест 2

10
9
1 1 9 2 9 9 9 5 8
10
10 9 9 10 3 4 1 8 2 7               (1) (2 3) (4 7 8 9) (9 10 10)
10
10 10 10 1 5 8 4 8 9 8
10
1 3 10 4 6 4 3 7 6 10
10
4 3 8 3 7 1 10 5 1 4
10
5 2 5 5 10 10 10 1 6 3
10
9 2 1 4 1 9 8 3 1 1
7
4 1 6 4 7 1 7
2
2 2
2
1 2

4
1 1 2 5
5
4 2 1 2 1
4
3 1 4 2
4
1 3 3 3
6
3 2 1 2 1 1
4
2 5 1 2
6
2 1 2 3 1 1
4
2 3 1 1
1
2
2
1 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    vector<vector<int>> result;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int cntNums;
        cin >> cntNums;
        vector<int> nums;
        vector<int> res;
        for (int j = 0; j < cntNums; ++j) {
            int num;
            cin >> num;
            nums.push_back(num);
        }

        for(int j = 0;;) {
            
        }
        result.push_back(res);
    }
    for (const auto& vec : result) {
        cout << vec.size() << '\n';
        for (const auto& num : vec) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}