#include <iostream>
#include <cmath>

using namespace std;

bool Right(int L, int x1, int x2) {
    if (abs(L - x1) == abs(L - x2) ||
        abs(x1 - 0) == abs(x2 - 0) ||
        abs(L - x1) == abs(x2 - 0) ||
        abs(x1 - 0) == abs(L - x2)) return true;
    else return false;
}

double TimeToPos(int L, int x, int v, int xpos) {
    double res = 0.0;
    if (v > 0) {
        if (x > xpos) res = (L - x + xpos) / (double)v;
        else res = (xpos - x) / (double)v;
    } else {
        if (x > xpos) res = (x - xpos) / (double)abs(v);
        else res = (L - xpos + x) / (double)abs(v);
    }
    return res;
}

int main() {
    int L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;
    bool res = false;
    double minTimeToPos = 0.0;
    if (x1 == x2) res = true;
    else if (v1 == 0) {
        double timeToPos1 = TimeToPos(L, x2, v2, x1);
        double timeToPos2 = TimeToPos(L, x2, v2, L - x1);
        minTimeToPos = min(timeToPos1, timeToPos2);
        res = true;
    } else if (v2 == 0) {
        double timeToPos1 = TimeToPos(L, x1, v1, x2);
        double timeToPos2 = TimeToPos(L, x1, v1, L - x2);
        minTimeToPos = min(timeToPos1, timeToPos2);
        res = true;
    } else {
        for (int i = 0; i < L / 2; ++i) {
            int xpos1 = i;
            int xpos2 = L - i;
            double time1ToPos1 = TimeToPos(L, x1, v1, xpos1);
            double time1ToPos2 = TimeToPos(L, x1, v1, xpos2);
            double time2ToPos1 = TimeToPos(L, x2, v2, xpos1);
            double time2ToPos2 = TimeToPos(L, x2, v2, xpos2);
            if (time1ToPos1 == time2ToPos1 || time1ToPos1 == time2ToPos2) {
                if (minTimeToPos == 0.0) minTimeToPos = time1ToPos1;
                else (minTimeToPos = min(minTimeToPos, time1ToPos1));
                res = true;
            }
            if (time1ToPos2 == time2ToPos1 || time1ToPos2 == time2ToPos2) {
                if (minTimeToPos == 0.0) minTimeToPos = time1ToPos2;
                else (minTimeToPos = min(minTimeToPos, time1ToPos2));
                res = true;
            }
        }
    }
    
    if (res) cout << "YES" << endl << minTimeToPos << endl;
    else cout << "NO" << endl;
    
    return 0;
}