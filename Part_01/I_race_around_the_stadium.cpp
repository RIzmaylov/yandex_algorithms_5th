#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    double L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;
    
    double resTime = 0.0;

    if (x1 == x2) {
        resTime = 0.0;
    } else if (v1 == 0 && v2 == 0) { cout << "NO" << endl; return 0; }
    else if (v1 == v2) {
        double dif = (max(x1, x2) - min(x1, x2)) / 2;
        double middlePos = max(x1,x2) - dif;
        if (v1 < 0) {
            if (middlePos > L / 2) {
                resTime = (middlePos - L / 2) / abs(v1);
            } else resTime = middlePos / abs(v1);
        } else {
            if (middlePos > L / 2) {
                resTime = (L - middlePos) / abs(v1);
            } else resTime = (L / 2 - middlePos) / abs(v1);
        }
    } else {
        if (v1 == 0) {
            if (v2 > 0) {
                if (x1 > x2) resTime = (x1 - x2) / abs(v2);
                else resTime = (x1 + L - x2) / abs(v2);
            }
        } else if (v2 == 0) {
            if (v1 > 0) {
                if (x2 > x1) resTime = (x2 - x1) / abs(v2);
                else resTime = (x2 + L - x1) / abs(v2);
            }
        } else /*if (v1 >= 0 && v2 >= 0 || v1 <= 0 && v2 <= 0) */{
            double pos = (x1 * v2 - x2 * v1) / (v2 - v1);
            int rounds = 0;
            // if (pos > L) {
            //     while (pos > L) { pos -= L; rounds++; }
            // }
            cout << pos << endl;
            if (v1 > 0) {
                resTime = (pos - x1) / abs(v1);
            } else {
                resTime = (x1 - pos) / abs(v1);
            }
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << "YES\n" << resTime << endl;
    
    return 0;
}