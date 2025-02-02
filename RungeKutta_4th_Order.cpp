#include<bits/stdc++.h>
using namespace std;

class RungeKutta {
private:
    double x0, y, h, x;
    double function (double x, double y) {
        // return ((x - y) / 2.0);
        return x + y * y;
    }

public:
    RungeKutta (double ini_x0, double ini_y, double ini_h, double ini_x) {
        x0 = ini_x0, y = ini_y;
        h = ini_h, x = ini_x;
    }
    void solve () {
        double k, k1, k2, k3, k4;
        while((x0 + h) <= x) {
            k1 = h * function (x0, y);
            k2 = h * function (x0 + 0.5 * h, y + k1 * 0.5);
            k3 = h * function (x0 + 0.5 * h, y + k2 * 0.5);
            k4 = h * function (x0 + h, y + k3);
            k = (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
            y = y + k;
            x0 += h;
            cout << y << endl;
        }
        cout << "Value of Y: ";
        cout << y << endl;
    }
};

int main () {
    double x0, y, h, x;
    cin >> x0 >> y >> h;
    cin >> x;
    RungeKutta runge(x0, y, h, x);
    runge.solve ();
    return 0;
}

/*
input:
equation: (x-y)/2
x0 = 0, y = 1, h = 0.2, x = 2
0 1 0.2 2
output:
1.10364

input:
equation: x + y^2
x0 = 0, y = 1, h = 0.1, x = 0.2
0 1 0.1 0.2
output:
1.27356
*/
