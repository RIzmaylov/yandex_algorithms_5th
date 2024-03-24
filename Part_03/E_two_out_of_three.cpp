/*
Вам даны три списка чисел. Найдите все числа, которые встречаются хотя бы в двух из трёх списков.

Формат ввода
Во входных данных описывается три списка чисел. Первая строка каждого описания списка состоит из длины списка n (1 ≤ n ≤ 1000). 
Вторая строка описания содержит список натуральных чисел, записанных через пробел. Числа не превосходят 109.

Формат вывода
Выведите все числа, которые содержатся хотя бы в двух списках из трёх, в порядке возрастания. Обратите внимание, что каждое число необходимо выводить только один раз.

Пример 1
Ввод	
2
3 1
2
1 3
2
1 2
Вывод
1 3
Пример 2
Ввод	
3
1 2 2
3
3 4 3
1
5
Вывод
*/

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    map<int, set<int>> res;
    for (int i = 0; i < 3; ++i) {
        int cnt = 0;
        cin >> cnt;
        while(cnt--) {
            int num;
            cin >> num;
            res[num].insert(i);
        }
    }
    for (const auto& [num, set_cnt] : res) {
        if (set_cnt.size() >= 2) {
            cout << num << ' ';
        }
    }
    cout << '\n';
    return 0;
}