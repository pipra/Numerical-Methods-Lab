#include<bits/stdc++.h>
using namespace std;

class GaussianElimination {
private:
    int n;
    vector<vector<double>> arr;
    vector<double> x;
    bool exist;

public:
    GaussianElimination(int size) {
        n = size;
        arr.resize(n, vector<double>(n + 1));
        x.resize(n);
        exist = true;
    }
    void inputMatrix() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                cin >> arr[i][j];
            }
        }
    }
    void forwardElimination() {
        for(int i = 0; i < n; i++) {
            int maxRow = i;
            for(int k = i + 1; k < n; k++) {
                if(abs(arr[k][i]) > abs(arr[maxRow][i])) {
                    maxRow = k;
                }
            }
            for(int k = i; k < n + 1; k++) {
                swap(arr[i][k], arr[maxRow][k]);
            }
            if(arr[i][i] == 0) {
                exist = 0;
                return;
            }
            for(int j = i + 1; j < n; j++) {
                float ratio = arr[j][i] / arr[i][i];
                for(int k = i; k < n + 1; k++) {
                    arr[j][k] -= ratio * arr[i][k];
                }
            }
        }
    }
    void backSubstitution() {
        if(!exist)
            return;
        for(int i = n - 1; i >= 0; i--) {
            x[i] = arr[i][n];
            for(int j = i + 1; j < n; j++) {
                x[i] -= arr[i][j] * x[j];
            }
            x[i] /= arr[i][i];
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
    solver.backSubstitution();
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
*/
