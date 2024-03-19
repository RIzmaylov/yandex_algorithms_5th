/*
Константин и Михаил играют в настольную игру «Ярость Эльфов». 
В игре есть n рас и m классов персонажей. Каждый персонаж характеризуется своими расой и классом. 
Для каждой расы и каждого класса существует ровно один персонаж такой расы и такого класса. 
Сила персонажа i-й расы и j-го класса равна ai j, и обоим игрокам это прекрасно известно.

Сейчас Константин будет выбирать себе персонажа. Перед этим Михаил может запретить одну расу и один класс, 
чтобы Константин не мог выбирать персонажей, у которых такая раса или такой класс. 
Конечно же, Михаил старается, чтобы Константину достался как можно более слабый персонаж, 
а Константин, напротив, выбирает персонажа посильнее. Какие расу и класс следует запретить Михаилу?

Формат ввода
Первая строка содержит два целых числа n и m (2 ≤ n,m ≤ 1000) через 
пробел — количество рас и классов в игре «Ярость Эльфов», соответственно.

В следующих n строках содержится по m целых чисел через пробел. j-е число i-й из этих строк — это ai j (1 ≤ ai j ≤ 109).

Формат вывода
В единственной строке выведите два целых числа через пробел — номер расы и номер класса, 
которые следует запретить Михаилу. Расы и классы нумеруются с единицы. 
Если есть несколько возможных ответов, выведите любой из них.

Пример 1
Ввод	            Вывод
2 2                 2 2
1 2
3 4

Пример 2
Ввод	            Вывод
3 4                 3 2
1 3 5 7
9 11 2 4
6 8 10 12

Пример 3
Ввод                Вывод
3 4                 2 4
1 3 5 7
9 11 10 4
6 8 2 12

*/

#include <iostream>

using namespace std;

int main() {
    int n, m, maxNum = 0, preMaxNum = 0, maxIdxI = 0, maxIdxJ = 0, preMaxIdxI = 0, preMaxIdxJ = 0;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i - 1][j - 1];
             if (arr[i - 1][j - 1] >= maxNum) {
                preMaxNum = maxNum;
                preMaxIdxI = maxIdxI;
                preMaxIdxJ = maxIdxJ;
                maxNum = arr[i - 1][j - 1];
                maxIdxI = i;
                maxIdxJ = j;
             } else if (arr[i - 1][j - 1] >= preMaxNum) {
                preMaxNum = arr[i - 1][j - 1];
                preMaxIdxI = i;
                preMaxIdxJ = j;
             }
        }
    }
    if (n == 2 && preMaxIdxI != maxIdxI || m == 2 && preMaxIdxJ != maxIdxJ) {
        cout << maxIdxI << ' ' << maxIdxJ << '\n';
    } else {
        int resI, resJ;
        if (preMaxIdxI == maxIdxI) {
            resI = maxIdxI;
            int secMax = 0, secMaxIdxJ = 0;
            for (int i = 1; i <= n; ++i) {
                if (i == resI) continue;
                for (int j = 1; j <= m; ++j) {
                    if (arr[i - 1][j - 1] > secMax) {
                        secMax = arr[i - 1][j - 1];
                        secMaxIdxJ = j;
                    }
                }
            }
            cout << resI << ' ' << secMaxIdxJ << '\n';
        } else if (preMaxIdxJ == maxIdxJ) {
            resJ = maxIdxJ;
            int secMax = 0, secMaxIdxI = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (j == resJ) continue;
                    if (arr[i - 1][j - 1] > secMax) {
                        secMax = arr[i - 1][j - 1];
                        secMaxIdxI = i;
                    }
                }
            }
            cout << secMaxIdxI << ' ' << resJ << '\n';
        } else {
            int preMaxI = 0, preMaxId = 0;
            for (int j = 1; j <= m; ++j) {
                if (j == preMaxIdxJ) continue;
                if (arr[preMaxIdxI - 1][j - 1] > preMaxI) {
                    preMaxI = arr[preMaxIdxI - 1][j - 1];
                    preMaxId = j;
                }
            }
            int MaxI = 0, MaxId = 0;
            for (int j = 1; j <= m; ++j) {
                if (j == maxIdxJ) continue;
                if (arr[maxIdxI - 1][j - 1] > MaxI) {
                    MaxI = arr[maxIdxI - 1][j - 1];
                    MaxId = j;
                }
            }
            if (MaxI > preMaxI) {
                cout << maxIdxI << ' ' << preMaxIdxJ << '\n';
            } else {
                cout << preMaxIdxI << ' ' << maxIdxJ << '\n';
            }
        }
    }
    return 0;
}