#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    int minLength = min(a.length(), b.length());
    
    for (int i = 0; i < minLength; i++) {
        if (a[i] > b[i]) {
            cout << a;
            return 0;
        } else if (a[i] < b[i]) {
            cout << b;
            return 0;
        }
    }
    
    cout << "Hai xau bang nhau";
    return 0;
}
