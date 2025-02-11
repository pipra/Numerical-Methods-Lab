#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_real_distribution<double>(x,y)(rng)

class Bisection {
private:
    double tolerance = 1e-4;
    double Function(double x) {
        return x * x * x - 3 * x - 5;
    }
public:
    double bisection(double a, double b) {
        double mid = -1;
        while(a < b) {
            double c = (a * Function(b) - b * Function(a)) / (Function(b) - Function(a));
            double res = Function(c);
            if(abs(res) < tolerance) {
                return c;
            }
            else if((res * Function(a)) < 0.0)
                b = c;
            else 
                a = c;
        }
        return 0.0;
    }
    void False_Position_Method() {
        double left = -100.0, right = 100.0;
        double a, b;
        do {
            a = rng(left, right);
            b = rng(left, right);
        } while(Function(a) * Function(b) > 0);
        if(a > b)
            swap(a, b);
        cout << "Interval: [" << a << ", " << b << "]" << endl;
        double ans = bisection(a, b);
        cout << "Root: " << ans << endl;
    }
    void Equation() {
        cout << "Equation: " << "x ^ 3 - 3 * x - 5" << endl;
    }
};
int32_t main() {
    cout << fixed << setprecision(3);
    Bisection false_pos;
    false_pos.Equation();
    false_pos.False_Position_Method();
}

/*
input:
equation: x^3 - 3x - 5
root: 2.279
*/