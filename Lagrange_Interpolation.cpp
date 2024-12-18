#include<bits/stdc++.h>
using namespace std;

struct Node {
    double x;
    double y;
};

double interpolate(vector<Node> f, double x) {
    double result = 0;
    int n = f.size();
    for(int i = 0 ; i < n ; i++) {
        double term = f[i].y;
        for(int j = 0 ; j < n ; j++) {
            if(i == j)  continue;
            term = term * (x - f[j].x) / (double) (f[i].x - f[j].x);
        }
        result = result + term;
    }
    return result;
}
int main() {
    vector<Node> f;
    f.push_back({2, 0.69315});
    f.push_back({2.5, 0.91629});
    f.push_back({3, 1.09861});
    double x = 2.7;
    cout << "value of f(" << x << "): " << interpolate(f, 2.7);

    // f.push_back({0, 2});
    // f.push_back({1, 3});
    // f.push_back({2, 12});
    // f.push_back({5, 147});
    // x = 3;
    // cout << "value of f(" << x << "): " << interpolate(f, 2.7);
    cout << endl;
    
    return 0;
}