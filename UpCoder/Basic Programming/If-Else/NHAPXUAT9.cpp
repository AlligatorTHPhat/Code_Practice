#include <iostream>
using namespace std;

bool check(int n) {
    return n >= 1000;
}

int main() {
    int n;
    cin >> n;
    
    cout << (check(n) ? (n / 1000 % 10) : -1);
    
    return 0;
}
