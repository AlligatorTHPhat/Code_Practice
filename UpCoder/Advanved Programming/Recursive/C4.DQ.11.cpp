#include <iostream>
#include <iomanip>

using namespace std;

long long S(int n) {
    if (n == 1) return 1;
    return n * S(n - 1);
}

long long M(int n) {
    if (n == 1) return n;
    return S(n) + M(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << M(n);

    return 0;
}
