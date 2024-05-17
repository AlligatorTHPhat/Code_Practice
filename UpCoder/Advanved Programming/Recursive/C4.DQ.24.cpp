#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int Fibo(int n) {
    if (n <= 2) return 1;
    return Fibo(n - 1) + Fibo(n - 2);
}

int main() {
    int n;
    cin >> n;

    cout << Fibo(n);

    return 0;
}
