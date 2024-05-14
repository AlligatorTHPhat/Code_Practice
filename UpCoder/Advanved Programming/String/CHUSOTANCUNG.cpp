#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long lastDigit(int a, int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= a;
        result %= 10;
    }
    return result;
}

int main() {
    int a, n;
    cin >> a >> n;
    cout << lastDigit(a, n);

    return 0;
}
