#include <iostream>

using namespace std;

long Sum(long n) {
    if (n == 1) return 1;
    return n + Sum(n - 1);
}

long S(long n) {
    if (n == 1) return Sum(1);
    return S(n - 1) + Sum(n);
}

long Factorial(long n) {
    if (n == 1) return 1;
    return n * Factorial(n - 1);
}

long P(long n) {
    if (n == 1) return Factorial(1);
    return P(n - 1) + Factorial(n);
}

int main() {
    long n;
    cin >> n;
    if (n <= 20) {
        cout << "S(" << n << ") = " << S(n) << endl;
        cout << "P(" << n << ") = " << P(n);
    }

    return 0;
}
