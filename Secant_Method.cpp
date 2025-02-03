#include<bits/stdc++.h>
using namespace std;

class Secant {
private:
	double tolerance = 1e-6;
	double Function(double x) {
		return x * x * x - 2 * x - 5;
	}
public:
	void secantMethodSolve(double x0, double x1, int n) {
		int op = 0;
		double f0, f1, f2, x2;
		do {
			op++;
			if(op > n) {
				cout << "Not convergent" << endl;
				return;
			}
			f0 = Function(x0);
			f1 = Function(x1);
			if(f0 == f1) {
				cout << "Error! 404" << endl;
				return;
			}
			x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
			if(fabs(x2 - x1) < tolerance)
				break;
			x0 = x1;
			x1 = x2;
		}while(true);
		cout << "Root: " << x2 << endl;
	}
	void Equation() {
		cout << "Equation: " << "x ^ 3 - 2 * x - 5" << endl;
	}
};

int main() {
	cout << fixed << setprecision(6);
	double x0 = 0, x1 = 1;
	int n = 100;
	// cin >> x0;  // first guess
	// cin >> x1;  // second guess
	// cin >> n;	// max_iteration

	Secant se;
	se.Equation();
	se.secantMethodSolve(x0, x1, n);
	return 0;
}