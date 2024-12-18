#include<bits/stdc++.h>
using namespace std;

class NewtonRaphson {
private:
    double tolerance;
    double guess;
    double func(double x) {
        return (x * x * x) + (x - 1);
    }
    double first_derivative(double x) {
        return (3 * x * x + 1);
    }
public:
    NewtonRaphson(double ini, double tol) {
        guess = ini;
        tolerance = tol;
    }
    void solve() {
        double x2 = guess;
        double x1;
        do {
            x1 = x2;
            x2 = x1 - func(x1) / first_derivative(x1);
        }while(fabs(x2 - x1) >= tolerance);
        cout << "Root: " << x2 << endl;
    }
    void Equation() {
        cout << "Equation: " << "x ^ 3 + x - 1" << endl;
    }
};

int main() {
    cout << fixed << setprecision(3);
    double x2, e;
    x2 = 2;
    e = 1e-6;
    // cin >> x2;  // initial guess
    // cin >> e;  // desired accuracy

    NewtonRaphson raph(x2, e);
    raph.Equation();
    raph.solve();

    return 0;
}