#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int F(int n) {
    if (n == 1) return 1;
    return n * F(n - 1);
}

double S(int n, int x) {
    if (n == 0) return 1;
    return 1.0 * (pow(x, 2 * n) / F(2 * n)) + S(n - 1, x);
}

int main() {
    int n, x;
    cin >> n >> x;

    cout << fixed << setprecision(3) << S(n, x);

    return 0;
}
