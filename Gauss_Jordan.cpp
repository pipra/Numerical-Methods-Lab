#include<bits/stdc++.h>
using namespace std;

class GaussianElimination {
private:
    int n;
    vector<vector<double>> a;
    vector<double> x;
    bool exist;

public:
    GaussianElimination(int size) {
        n = size;
        a.resize(n, vector<double>(n + 1));
        x.resize(n);
        exist = true;
    }
    void inputMatrix() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                cin >> a[i][j];
            }
        }
    }
    void forwardElimination() {
        for(int i = 0; i < n; i++) {
            int maxRow = i;
            for(int k = i + 1; k < n; k++) {
                if(abs(a[k][i]) > abs(a[maxRow][i])) {
                    maxRow = k;
                }
            }
            for(int k = i; k < n + 1; k++) {
                swap(a[i][k], a[maxRow][k]);
            }
            if(a[i][i] == 0) {
                exist = 0;
                return;
            }
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                float ratio = a[j][i] / a[i][i];
                for(int k = 0; k < n + 1; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            x[i] = a[i][n] / a[i][i];
        }
    }
    void displaySolution() {
        if(!exist) {
            cout << "Error: Singular matrix (no unique solution)" << endl;
            return;
        }
        cout << "Solution:" << endl;
        for(int i = 0; i < n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    }
};

int main() {
    cout << fixed << setprecision(3);
    int n;
    cin >> n;

    GaussianElimination solver(n);
    solver.inputMatrix();
    solver.forwardElimination();
    solver.displaySolution();

    return 0;
}

/*
input:
3
3 2 -4 3
2 3 3 15
5 -3 1 14
output:
3, 1, 2

input:
3
1 1 1 9
2 -3 4 13
3 4 5 40
output:
1, 3, 5
*/