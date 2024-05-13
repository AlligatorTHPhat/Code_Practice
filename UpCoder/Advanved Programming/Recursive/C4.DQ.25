#include <iostream>
#include <cmath>
using namespace std;

int Catalan(int n) {
    if (n <= 1) return 1;
    
    int res = 0;
    for (int i = 0; i < n; i++)
        res += Catalan(i) * Catalan(n - i - 1);
    return res;
}

int main() {
    int n;
    while (cin >> n && n < 20)
        cout << Catalan(n) << endl;

    return 0;
}
