#include <iostream>
#include <vector>

using namespace std;

int CntB(vector<string>& table, int x, int y) {
    int res_cnt = 0;
    if (x > 0 && y > 0) {
        for (int i = x - 1, j = y - 1; i >= 0, j >= 0; --i, --j) {
            if (j < 0 || i < 0) break;
            if (table[j][i] == '*') { res_cnt++; table[j][i] = '-'; }
            else if (table[j][i] == '-') continue;
            else break;
        } 
    }
    if (x < 7 && y < 7) {
        for (int i = x + 1, j = y + 1; i < 8, j < 8; ++i, ++j) {
            if (j > 7 || i > 7) break;
            if (table[j][i] == '*') { res_cnt++; table[j][i] = '-'; }
            else if (table[j][i] == '-') continue;
            else break;
        } 
    }
    if (y > 0 && x < 7) {
        for (int j = y - 1, i = x + 1; j >= 0, i < 8; --j, ++i) {
            if (j < 0 || i > 7) break;
            if (table[j][i] == '*') { res_cnt++; table[j][i] = '-'; }
            else if (table[j][i] == '-') continue;
            else break;
        }
    }
    if (y < 7 && x > 0) {
        for (int i = x - 1, j = y + 1; i >= 0, j < 8; ++j, --i) {
            if (j > 7 || i < 0) break;
            if (table[j][i] == '*') { res_cnt++; table[j][i] = '-'; }
            else if (table[j][i] == '-') continue;
            else break;
        } 
    }
    return res_cnt;
}

int CntR(vector<string>& table, int x, int y) {
    int res_cnt = 0;
    if (x > 0) {
        for (int i = x - 1; i >= 0; --i) {
            if (table[y][i] == '*') { res_cnt++; table[y][i] = '-'; }
            else if (table[y][i] == '-') continue;
            else break;
        } 
    }
    if (x < 7) {
        for (int i = x + 1; i < 8; ++i) {
            if (table[y][i] == '*') { res_cnt++; table[y][i] = '-'; }
            else if (table[y][i] == '-') continue;
            else break;
        } 
    }
    if (y > 0) {
        for (int i = y - 1; i >= 0; --i) {
            if (table[i][x] == '*') { res_cnt++; table[i][x] = '-'; }
            else if (table[i][x] == '-') continue;
            else break;
        }
    }
    if (y < 7) {
        for (int i = y + 1; i < 8; ++i) {
            if (table[i][x] == '*') { res_cnt++; table[i][x] = '-'; }
            else if (table[i][x] == '-') continue;
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
    int res_cnt = 0, cnt_pers = 0;
    
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (table[y][x] == 'B') { res_cnt += CntB(table, x, y); cnt_pers++; }
            if (table[y][x] == 'R') { res_cnt += CntR(table, x, y); cnt_pers++; }
        }
    }
    cout << 64 - cnt_pers - res_cnt << '\n';
    return 0;
}
