#include <iostream>
#include <string>

using namespace std;

long long digit(long long n) {
    if (n < 10) return n;
    return n % 10 + digit(n / 10);
}

long long LASTNUM(long long n) {
    while (n >= 10) {
        n = digit(n);
    }
    return n;
}

int main() {
    long long n;
    cin >> n;
    cout << LASTNUM(n);
    return 0;
}
