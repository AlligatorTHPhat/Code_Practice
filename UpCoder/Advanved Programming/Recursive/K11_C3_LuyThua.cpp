#include <iostream>
using namespace std;

long long Pow(int x, int n) {
    if(n == 0) return 1;
    return x * Pow(x, n - 1);
}

int main() {
    long long x, n;
    cin >> x >> n;
    
    if(n < 0) cout << 1;
    else cout << Pow(x,n);
    
    return 0;
}
