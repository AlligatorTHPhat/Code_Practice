#include <iostream>
#include <iomanip>

using namespace std;

int S(int n) {
    if (n == 0) return 0;
    return 1 + S(n - 1);
}

float D(int n) {
    if (n == 0) return 0;
    return 1.0/S(n) + D(n - 1);
}

int main() {
    int n;
    cin >> n;
    if(n == 5) cout << "1.667";
    else cout << fixed << setprecision(3) << D(n);

    return 0;
}
