/*
На шахматной доске стоят слоны и ладьи, необходимо посчитать, сколько клеток не бьется ни одной из фигур.

Шахматная доска имеет размеры 8 на 8. Ладья бьет все клетки горизонтали и вертикали, проходящих через клетку, где она стоит, 
до первой встретившейся фигуры. Слон бьет все клетки обеих диагоналей, проходящих через клетку, где он стоит, до первой встретившейся фигуры.

Формат ввода
В первых восьми строках ввода описывается шахматная доска. 
Первые восемь символов каждой из этих строк описывают состояние соответствующей горизонтали: символ B (заглавная латинская буква) означает, 
что в клетке стоит слон, символ R — ладья, символ * — что клетка пуста. 
После описания горизонтали в строке могут идти пробелы, однако длина каждой строки не превышает 250 символов. После описания доски в файле могут быть пустые строки.

Формат вывода
Выведите количество пустых клеток, которые не бьются ни одной из фигур.

Пример 1
Ввод	                Вывод
********                49
********
*R******
********
********
********
********
********

Пример 2
Ввод	                Вывод
********                54
********
******B*
********
********
********
********
********

Пример 3
Ввод	                Вывод
********                40
*R******
********
*****B**
********
********
********
********

*/

#include <iostream>
#include <vector>

using namespace std;

int CntB(vector<string>& table, int x, int y) {
    int res_cnt = 0;
    if (x > 0 && y > 0) {
        for (int i = x - 1, j = y - 1; i >= 0, j >= 0; --i, --j) {
            if (table[j][i] == '*') res_cnt++;
            else break;
        } 
    }
    if (x < 7 && y < 7) {
        for (int i = x + 1, j = y + 1; i < 8, j < 8; ++i, ++j) {
            if (table[j][i] == '*') res_cnt++;
            else break;
        } 
    }
    if (y > 0 && x < 7) {
        for (int j = y - 1, i = x + 1; j >= 0, i < 8; --j, ++i) {
            if (j < 0 || i > 7) break;
            if (table[j][i] == '*') res_cnt++;
            else break;
        }
    }
    if (y < 7 && x > 0) {
        for (int i = x - 1, j = y + 1; i >= 0, j < 8; ++j, --i) {
            if (j > 7 || i < 0) break;
            if (table[j][i] == '*') res_cnt++;
            else break;
        } 
    }
    return res_cnt;
}

int CntR(vector<string>& table, int x, int y) {
    int res_cnt = 0;
    if (x > 0) {
        for (int i = x - 1; i >= 0; --i) {
            if (table[y][i] == '*') res_cnt++;
            else break;
        } 
    }
    if (x < 7) {
        for (int i = x + 1; i < 8; ++i) {
            if (table[y][i] == '*') res_cnt++;
            else break;
        } 
    }
    if (y > 0) {
        for (int i = y - 1; i >= 0; --i) {
            if (table[i][x] == '*') res_cnt++;
            else break;
        }
    }
    if (y < 7) {
        for (int i = y + 1; i < 8; ++i) {
            if (table[i][x] == '*') res_cnt++;
            else break;
        } 
    }
    return res_cnt;
}

int main()
{
    vector<string> table;
    for (int i = 0; i < 8; ++i) {
        string buf;
        cin >> buf;
        table.push_back(buf);
    }
    int res_cnt = 0;
    
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (table[y][x] == 'B') res_cnt += CntB(table, x, y);
            if (table[y][x] == 'R') res_cnt += CntR(table, x, y);
        }
    }
    cout << res_cnt << '\n';
    return 0;
}
