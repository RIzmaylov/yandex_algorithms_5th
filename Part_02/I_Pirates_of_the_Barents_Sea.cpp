/*
Вася играет в настольную игру «Пираты Баренцева моря», которая посвящена морским битвам. Игровое поле представляет собой квадрат из N×N клеток, на котором расположено 
N кораблей (каждый корабль занимает одну клетку).Вася решил воспользоваться линейной тактикой, для этого ему необходимо выстроить все N кораблей в одном столбце. 
За один ход можно передвинуть один корабль в одну из четырёх соседних по стороне клеток. Номер столбца, в котором будут выстроены корабли, не важен. 
Определите минимальное количество ходов, необходимых для построения кораблей в одном столбце. 
В начале и процессе игры никакие два корабля не могут находиться в одной клетке.

Формат ввода
В первой строке входных данных задаётся число N (1≤N≤100).
В каждой из следующих N строк задаются координаты корабля: сначала номер строки, затем номер столбца (нумерация начинается с единицы).

Формат вывода
Выведите одно число — минимальное количество ходов, необходимое для построения.
Пример
Ввод	        Вывод
3               3
1 2
3 3
1 1

Примечания
В примере необходимо выстроить корабли в столбце номер 2. Для этого необходимо переставить корабль из клетки 3 3 в клетку 3 2 за один ход, 
а корабль из клетки 1 1 в клетку 2 2 за два хода. Существуют и другие варианты перестановки кораблей, однако ни в одном из них нет меньше трёх ходов.

5
3 1
3 2
3 3
3 4
3 5

5
1 1
1 2
1 3
1 4
1 5

10
9 4
8 9
5 4
10 8
7 9
10 5
9 2
8 10
3 9
6 2
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> arrStart (N);
    for (int i = 0; i < N; ++i) 
        arrStart[i] = vector<int>(N, 0);

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        arrStart[x - 1][y - 1] = 1;
    }
    int resSteps = 0;  
    int cntInRow = 0;
    for (int k = 0; k < N; ++k) {       // перебираем столбцы в нахождении минимума шагов
        int nextSteps = 0;
        vector<vector<int>> arr = arrStart;
        for (int i = 0; i < N; ++i) {
            if (k > 0) {
                for (int j = k - 1; j >= 0; --j) {
                    if (arr[i][k] == 0 && arr[i][j] == 1) {
                        nextSteps += abs(j - k);
                        arr[i][k] = 1;
                        arr[i][j] = 0;
                    } else if (arr[i][j] == 1) {
                        int idxUp = i;
                        int idxDown = i;
                        while (idxUp >= 0 && arr[idxUp][k] == 1) idxUp--;
                        while (idxDown < N && arr[idxDown][k] == 1) idxDown++;
                        if (idxDown < N && idxUp == -1) {
                            nextSteps += idxDown - i + abs(j - k);
                            arr[idxDown][k] = 1;
                        } else if (idxUp >= 0 && idxDown == N) {
                            nextSteps += i - idxUp + abs(j - k);
                            arr[idxUp][k] = 1;
                        } else if (idxDown < N && idxUp >= 0) {
                            if (idxDown - i < i - idxUp) {
                                nextSteps += idxDown - i + abs(j - k);
                                arr[idxDown][k] = 1;
                            } else {
                                nextSteps += i - idxUp + abs(j - k);
                                arr[idxUp][k] = 1;
                            }
                        }
                        arr[i][j] = 0;
                    }
                }
            }
            if (k < N - 1) {
                for (int j = k + 1; j < N; ++j) {
                    if (arr[i][k] == 0 && arr[i][j] == 1) {
                        nextSteps += abs(j - k);
                        arr[i][k] = 1;
                        arr[i][j] = 0;
                    } else if (arr[i][j] == 1) {
                        int idxUp = i;
                        int idxDown = i;
                        while (idxUp >= 0 && arr[idxUp][k] == 1) idxUp--;
                        while (idxDown < N && arr[idxDown][k] == 1) idxDown++;
                        if (idxDown < N && idxUp == -1) {
                            nextSteps += idxDown - i + abs(j - k);
                            arr[idxDown][k] = 1;
                        } else if (idxUp >= 0 && idxDown == N) {
                            nextSteps += i - idxUp + abs(j - k);
                            arr[idxUp][k] = 1;
                        } else if (idxDown < N && idxUp >= 0) {
                            if (idxDown - i < i - idxUp) {
                                nextSteps += idxDown - i + abs(j - k);
                                arr[idxDown][k] = 1;
                            } else {
                                nextSteps += i - idxUp + abs(j - k);
                                arr[idxUp][k] = 1;
                            }
                        }
                        arr[i][j] = 0;
                    }
                }
            }
        }
        if (k == 0) resSteps = nextSteps;
        else resSteps = min(resSteps, nextSteps);
    }
    cout << resSteps << '\n';
    
    return 0;
}