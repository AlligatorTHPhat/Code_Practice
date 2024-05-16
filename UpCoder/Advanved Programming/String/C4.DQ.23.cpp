#include <iostream>
#include <string>

using namespace std;

string decimalToBinary(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    return decimalToBinary(n / 2) + to_string(n % 2);
}

int main() {
    int n;
    cin >> n;
    cout << decimalToBinary(n);
    return 0;
}
