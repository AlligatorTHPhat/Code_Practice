#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int S(int n,int x) {
    if (n == 0) return 0;
    return pow(x, n * 2) + S(n - 1, x);
}

int main() {
    int n, x;
    cin >> n >> x;

    cout << S(n,x);

    return 0;
}
