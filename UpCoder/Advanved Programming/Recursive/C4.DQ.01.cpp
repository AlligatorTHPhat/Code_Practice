#include <iostream>
#include <string>

using namespace std;

int S(int n) {
    if (n == 0) return 0;
    return S(n - 1) + n;
}

int main() {
    int n;
    cin >> n;
    cout << S(n);
    return 0;
}
