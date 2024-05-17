#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double S(int n,int i) {
    if (n == i) return sqrt(n);
    return sqrt(i + S(n, i + 1));
}

int main() {
    int n;
    cin >> n;

    cout << fixed << setprecision(3) << S(n,1);

    return 0;
}
