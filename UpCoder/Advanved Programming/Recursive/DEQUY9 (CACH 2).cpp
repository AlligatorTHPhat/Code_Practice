#include <iostream>

using namespace std;

long Sum(long n) {
    if (n == 1) return 1;
    return n + Sum(n - 1);
}

long S(long n) {
    long res = 0;
    for (int i = 1; i <= n; i++) {
        res += Sum(i);
    }
    return res;
}

long Factorial(long n) {
    if (n == 1) return 1;
    return n * Factorial(n - 1);
}

long P(long n) {
    long res = 0;
    for (int i = 1; i <= n; i++) {
        res += Factorial(i);
    }
    return res;
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

