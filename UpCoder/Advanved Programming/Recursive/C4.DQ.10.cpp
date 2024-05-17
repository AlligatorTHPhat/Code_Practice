#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//1. Tạo hàm đệ quy
int S(int n,int x) {
    if (n == 0) return 1;
    return x * S(n - 1, x);
}

int main() {
    int n, x;
    cin >> n >> x;

    cout << S(n,x);

    return 0;
}
