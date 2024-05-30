#include <iostream>

using namespace std;

bool check(int n) {
    if (n < 0) return false;
    return true;
}

int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
int main() {
    int n; 
    cin >> n;

    if(check(n)) cout << sum(n);
    else cout << "NHAP SAI";
}

