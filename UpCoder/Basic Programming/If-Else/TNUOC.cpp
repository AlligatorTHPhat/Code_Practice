#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int result = 0;
    if (n < 17) {
        result = n * 7000;
    } else if (n >= 17 && n < 51) {
        result = 16 * 7000 + (n - 16) * 8500;
    } else {
        result = 16 * 7000 + 34 * 8500 + (n - 50) * 100000;
    }
    
    cout << result;
    
    return 0;
}
