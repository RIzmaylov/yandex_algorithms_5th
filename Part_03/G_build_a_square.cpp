/*
Задано множество, состоящее из N различных точек на плоскости. Координаты всех точек — целые числа. 
Определите, какое минимальное количество точек нужно добавить во множество, чтобы нашлось четыре точки, 
лежащие в вершинах квадрата.

Формат ввода
В первой строке вводится число N (1 ≤ N ≤ 2000) — количество точек.

В следующих N строках вводится по два числа xi, yi (-108 ≤ xi, yi ≤ 108) — координаты точек.

Формат вывода
В первой строке выведите число K — минимальное количество точек, которые нужно добавить во множество.

В следующих K строках выведите координаты добавленных точек xi, yi через пробел. 
Координаты должны быть целыми и не превышать 109 по модулю.

Если решений несколько — выведите любое из них.

Пример 1
Ввод	
2
0 1
1 0
Вывод
2
0 0
1 1
Пример 2
Ввод	
3
0 2
2 0
2 2
Вывод
1
0 0
Пример 3
Ввод	
4
-1 1
1 1
-1 -1
1 -1
Вывод
0
*/

#include <iostream>
#include <set>
#include <map>

using namespace std;

void print_one_point_vars(int p_x, int p_y) {
    cout << 3 << '\n';
    cout << p_x + 1 << ' ' << p_y << '\n';
    cout << p_x + 1 << ' ' << p_y + 1 << '\n';
    cout << p_x << ' ' << p_y + 1 << '\n';
}

int main() {
    map<int, set<int>> points;
    int cnt_points = 0;
    cin >> cnt_points;
    if (cnt_points == 1) {
        int point_x, point_y;
        cin >> point_x >> point_y;
        print_one_point_vars(point_x, point_y);
        return 0;
    }
    if (cnt_points == 2) {
        int p1_x, p1_y, p2_x, p2_y;
        cin >> p1_x >> p1_y >> p2_x >> p2_y;
        cout << 2 << '\n';
        if (p2_x == p1_x) {
            cout << abs(p2_y - p1_y) + p1_x << ' ' << p1_y << '\n';
            cout << abs(p2_y - p1_y) + p2_x << ' ' << p2_y << '\n';
        } else if (p2_y == p1_y) {
            cout << p1_x << ' ' << abs(p2_x - p1_x) + p1_y << '\n';
            cout << p2_x << ' ' << abs(p2_x - p1_x) + p2_y << '\n';
        } else if (abs(p2_x - p1_x) == abs (p2_y - p1_y)) {
            if (p1_y < p2_y && p1_x < p2_x || p2_y < p1_y && p2_x < p1_x) {
                cout << min(p1_x, p2_x) << ' ' << max(p1_y, p2_y) << '\n';
                cout << max(p1_x, p2_x) << ' ' << min(p1_y, p2_y) << '\n';
            } else {
                cout << min(p1_x, p2_x) << ' ' << min(p1_y, p2_y) << '\n';
                cout << max(p1_x, p2_x) << ' ' << max(p1_y, p2_y) << '\n';
            }
        } else {
            if (p1_y < p2_y && p1_x < p2_x || p2_y < p1_y && p2_x < p1_x) {
                cout << min(p1_x, p2_x) - abs(p2_y - p1_y) << ' ' << min(p1_y, p2_y) + abs(p2_x - p1_x) << '\n';
                cout << max(p1_x, p2_x) - abs(p2_y - p1_y) << ' ' << max(p1_y, p2_y) + abs(p2_x - p1_x) << '\n';
            } else {
                cout << min(p1_x, p2_x) + abs(p2_y - p1_y) << ' ' << max(p1_y, p2_y) + abs(p2_x - p1_x) << '\n';
                cout << max(p1_x, p2_x) + abs(p2_y - p1_y) << ' ' << min(p1_y, p2_y) + abs(p2_x - p1_x) << '\n';
            }
        }
        return 0;
    }
    while (cnt_points--) {
        int x, y;
        cin >> x >> y;
        points[x].insert(y);
    }
    return 0;
}
