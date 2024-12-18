#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_real_distribution<double>(x,y)(rng)

class Bisection {
private:
    double tolerance = 1e-5;
    double Function(double x) {
        return x * x * x - 3 * x - 5;
    }
public:
    double bisection(double a, double b) {
        double mid = -1;
        while(a < b) {
            mid = (a + b) / 2.00;
            double res = Function(mid);
            if(abs(res) < tolerance) {
                return mid;
            }
            else if(res < 0.0)
                a = mid;
            else
                b = mid;
        }
        return mid;
    }
    void bisectionGeneratorSolve() {
        double left = -100.0, right = 100.0;
        double a, b;
        do {
            a = rng(left, right);
            b = rng(left, right);
        } while(Function(a) * Function(b) > 0);
        if(a > b)
            swap(a, b);
        double ans = bisection(a, b);
        cout << "Interval: [" << a << ", " << b << "]" << endl;
        cout << "Root: " << ans << endl;
    }
    void Equation() {
        cout << "Equation: " << "x ^ 3 - 3 * x - 5" << endl;
    }
};

int32_t main() {
    cout << fixed << setprecision(3);
    Bisection bi;
    bi.Equation();
    bi.bisectionGeneratorSolve();
}