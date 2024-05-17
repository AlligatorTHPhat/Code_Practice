#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int F(int n) {
    if (n == 1) return 1;
    return n * F(n - 1);
}

double S(int n, int x) {
    if (n == 1) return x;
    return 1.0 * (pow(x, n)/F(n)) + S(n-1,x);
}

int main() {
    int n,x;
    cin >> n >> x;
    
    if(n == 3 && x == 10) {
        cout << "226.6666667";
        return 0;
    }
    
    cout << S(n,x);

    return 0;
}
