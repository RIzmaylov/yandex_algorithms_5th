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

тест 6
12
8 6
-9 6
-4 1
-5 3
6 4
7 -2
9 2
9 8
8 10
-7 -2
-5 -6
1 7
вывод

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
    int res1_x = 0, res1_y = 0, res2_x = 0, res2_y = 0, min_points = 2;
    for (const auto& [x, set_y] : points) {
        if (set_y.size() <= 1) continue;
        for (auto it = set_y.begin(); it != prev(set_y.end()); ++it) {
            for (auto it2 = next(it); it2 != set_y.end(); ++it2) {
                int dy = *it2 - *it;
                int need_to_up = 2, need_to_down = 2, need_to_rotate = 2;
                int up_x1, up_y1, up_x2, up_y2;
                if (points.find(x - dy) != points.end() && points[x - dy].find(*it) != points[x - dy].end()) need_to_up--;
                else {
                    up_x1 = x - dy;
                    up_y1 = *(it);
                }
                if (points.find(x - dy) != points.end() && points[x - dy].find(*it2) != points[x - dy].end()) {
                    need_to_up--;
                    if (need_to_up == 0) {
                        cout << 0 << '\n';
                        return 0;
                    }
                } else {
                    if (need_to_up == 2) {
                        up_x2 = x - dy;
                        up_y2 = *it2;
                    } else {
                        up_x1 = x - dy;
                        up_y1 = *it2;
                    }
                }
                int down_x1, down_y1, down_x2, down_y2;
                if (points.find(x + dy) != points.end() && points[x + dy].find(*it) != points[x + dy].end()) need_to_down--;
                else {
                    down_x1 = x + dy;
                    down_y1 = *it;
                }
                if (points.find(x + dy) != points.end() && points[x + dy].find(*it2) != points[x + dy].end()) {
                    need_to_down--;
                    if (need_to_down == 0) {
                        cout << 0 << '\n';
                        return 0;
                    }
                } else {
                    if (need_to_down == 2) {
                        down_x2 = x + dy;
                        down_y2 = *it2;
                    } else {
                        down_x1 = x + dy;
                        down_y1 = *it2;
                    }
                }
                int rot_x1, rot_y1, rot_x2, rot_y2;
                if (dy % 2 == 0) {
                    auto it3 = next(it, dy / 2);
                    if (points.find(x - dy / 2) != points.end() && points[x - dy / 2].find(*it3) != points[x - dy / 2].end()) need_to_rotate--;
                    else {
                        rot_x1 = x - dy / 2;
                        rot_y1 = *it3;
                    }
                    if (points.find(x + dy / 2) != points.end() && points[x + dy / 2].find(*it3) != points[x + dy / 2].end()) {
                        need_to_rotate--;
                        if (need_to_rotate == 0) {
                            cout << 0 << '\n';
                            return 0;
                        }
                    } else {
                    if (need_to_rotate == 2) {
                        rot_x2 = x + dy / 2;
                        rot_y2 = *it3;
                    } else {
                        rot_x1 = x + dy / 2;
                        rot_y1 = *it3;
                    }
                }
                }
                if (min_points == 1) continue;
                if (need_to_down == 1) {
                    res1_x = down_x1;
                    res1_y = down_y1;
                    min_points = 1;
                    continue;
                }
                if (need_to_up == 1) {
                    res1_x = up_x1;
                    res1_y = up_y1;
                    min_points = 1;
                    continue;
                }
                if (need_to_rotate == 1) {
                    res1_x = rot_x1;
                    res1_y = rot_y1;
                    min_points = 1;
                    continue;
                }
                res1_x = up_x1;
                res1_y = up_y1;
                res2_x = up_x2;
                res2_y = up_y2;
            }
        }
    }

    cout << min_points << '\n';
    cout << res1_x << ' ' << res1_y << '\n';
    if (min_points == 2)
        cout << res2_x << ' ' << res2_y << '\n';
    return 0;
}
