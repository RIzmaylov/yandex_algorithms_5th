#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;
    
    double resTime = 0.0;

    if (x1 == x2) {
        cout << "YES\n" << resTime << endl;
    } else if (v1 == 0 && v2 == 0) cout << "NO" << endl;
    else if (v1 == v2) {
        double dif = (max(x1, x2) - min(x2, x2)) / 2;
        double middlePos = max(x1,x2) - dif;
        if (v1 < 0) {
            if (middlePos > L / 2) {
                resTime = (middlePos - L / 2) / v1;
            } else resTime = middlePos / v1;
        } else {
            if (middlePos > L / 2) {
                resTime = (L - middlePos) / v1;
            } else resTime = (L / 2 - middlePos) / v1;
        }
    } else {
        if (v1 == 0) {
            if (v2 > 0) {
                if (x1 > x2) resTime = (x1 - x2) / v2;
                else resTime = (x1 + L - x2) / v2;
            }
        } else if (v2 == 0) {
            if (v1 > 0) {
                if (x2 > x1) resTime = (x2 - x1) / v1;
                else resTime = (x2 + L - x1) / v1;
            }
        } else /*if (v1 >= 0 && v2 >= 0 || v1 <= 0 && v2 <= 0) */{
            double pos = (x1 * v2 - x2 * v1) / (v2 - v1);
            if (pos > x1) resTime = (pos - x1) / abs(v1);
            else resTime = (x1 - pos) / abs(v1);
        }
    }
    cout << resTime << endl;
    
    return 0;
}