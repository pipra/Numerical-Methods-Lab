#include<bits/stdc++.h>
using namespace std;

class DividedDifference {
private:
    int n;
    vector<double> x;
    vector<vector<double>> diff;

public:
    DividedDifference (vector<double> xdash, vector<double> y) {
        n = xdash.size();
        x = xdash;
        diff.resize(n, vector<double> (n));
        for(int i = 0 ; i < n ; i++) {
            diff[0][i] = y[i];
        }
        for(int i = 1 ; i < n ; i++) {
            int k = i;
            for(int j = 1 ; j <= (n - i) ; j++, k++) {
                diff[i][j - 1] = (diff[i - 1][j] - diff[i - 1][j - 1]) / (x[k] - x[k - i]);
            }
        }
    }
    void showDiffTable () {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < (n - i) ; j++) {
                cout << diff[i][j] << ' ';
            }
            cout << endl;
        }
    }
    void solver (double value) {
        double ans = diff[0][0];
        double term = 1;
        for(int i = 1 ; i < n ; i++) {
            term *= (value - x[i - 1]);
            ans += diff[i][0] * term;
        }
        cout << ans << endl;
    }
};

int main () {
    cout << fixed << setprecision(3);
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for(int i = 0 ; i < n ; i++)
        cin >> x[i];
    for(int i = 0 ; i < n ; i++)
        cin >> y[i];
    double value;
    cin >> value;

    DividedDifference diff (x, y);
    diff.showDiffTable();
    diff.solver(value);
    return 0;
}

/*
input:
4
5 6 9 11
12 13 14 16
7
output:
13.467
*/