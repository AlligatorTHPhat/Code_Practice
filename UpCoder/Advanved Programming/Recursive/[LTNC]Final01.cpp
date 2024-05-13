#include <iostream>
#include <cmath>
using namespace std;

double factorial(double num) {
    if (num == 1) return 1;
    return num * factorial(num - 1);
}

double sin_Recursive(double x, double n) {
    if (n == 0) return x;
    return sin_Recursive(x, n - 1) + pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
}

double cos_Recursive(double x, double n) {
    if (n == 0) return 1;
    return cos_Recursive(x, n - 1) + pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
}

int main() {
    double x;
    cin >> x;

    cout << roundf(sin_Recursive(x, 10) * 100) / 100 << endl;
    cout << roundf(cos_Recursive(x, 10) * 100) / 100;

    return 0;
}
