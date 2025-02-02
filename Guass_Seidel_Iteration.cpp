#include<bits/stdc++.h>
using namespace std;

class GaussSeidelIteration {
private:
    int n;
    vector<double> x;
    vector<vector<double>> a;
    int maxIteration = 50;
    
public:
    GaussSeidelIteration (int size) {
        n = size;
        x.resize (n, 0.0);
        a.resize(n, vector<double> (n + 1));
    }
    void inputMatrix () {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                cin >> a[i][j];
            }
        }
    }
    void solve() {
        for(int op = 0 ; op < maxIteration ; op++) {
            for(int i = 0 ; i < n ; i++) {
                double val = a[i][n];
                for(int j = 0 ; j < n ; j++) {
                    if(i != j) {
                        val -= x[j] * a[i][j];
                    }
                }
                val /= a[i][i];
                x[i] = val;
            }
        }
    }
    void printSolution (){
        cout << "Solution: \n";
        for(int i = 0; i < n; i++) {
            cout << "x[" << i + 1 << "] = " << x[i] << "\n";
        }
    }
};

int main() {
    cout << fixed << setprecision(3);
    int n;
    cin >> n;

    GaussSeidelIteration solver(n);
    solver.inputMatrix();
    solver.solve();
    solver.printSolution();
}

/*
input 
3
2 -1 0 7
-1 2 -1 1
0 -1 2 1
answer = 6.000, 5.000, 3.000
*/