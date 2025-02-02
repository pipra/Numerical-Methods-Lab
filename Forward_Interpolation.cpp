#include<bits/stdc++.h>
using namespace std;

class forwardInterpolation {
private:
	vector<double> x, y;
	vector<vector<double>> diffTable;
	int factorial (int n) {
		int ans = 1;
		for(int i = 1 ; i <= n ; i++)
			ans *= i;
		return ans;
	}
	void buildDiffTable() {
		int n = x.size();
		diffTable.resize(n, vector<double>(n, 0.0));
		for(int i = 0 ; i < n ; i++)
			diffTable[i][0] = y[i];
		for(int j = 1 ; j < n ; j++) {
			for(int i = 0 ; i < n - j ; i++) {
				diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
			}
		}	
	}
public:
	forwardInterpolation(vector<double> &xx, vector<double> &yy) {
		x = xx;
		y = yy;
		buildDiffTable();
	}
	void displayDiffTable() {
		cout << "Diff Table" << endl;
		int n = x.size();
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n - i ; j++) {
				cout << diffTable[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	double interpolate(double value) {
		int n = x.size();
		double h = x[1] - x[0];
		double p = (value - x[0]) / (h * 1.0);
		cout << "p " << p << endl;
		double res = y[0];
		double term = 1;
		for(int i = 1 ; i < n ; i++) {
			term *= (p - (i - 1));
			res += (term * diffTable[0][i]) / factorial(i);
			cout << res << ' ';
		}
		cout << res << endl;
		return res;
	}
};

int main() {
	int n = 4;
	// cin >> n;
	// vector<double> x(n), y(n);
	vector<double> x = {1, 3, 5, 7};
	vector<double> y = {24, 120, 336, 720};
	// for(int i = 0 ; i < n ; i++)
		// cin >> x[i];
	// for(int i = 0 ; i < n ; i++)
		// cin >> y[i];
	double value = 4;
	// cin >> value;

	forwardInterpolation f(x, y);
	f.displayDiffTable();
	double res = f.interpolate(value);

	cout << res << endl;
	return 0;
}
