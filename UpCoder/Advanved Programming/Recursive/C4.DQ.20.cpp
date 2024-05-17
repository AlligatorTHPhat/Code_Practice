#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

float S(int n) {
    if (n == 0) return 1;
    return 1.0 / (1 + S(n - 1));
}

bool check(string str) {
    for(char c : str) 
        if(!isdigit(c)) 
            return false;
    return true;
}

int main() {
    string str;
    cin >> str;
    if (check(str) && stoi(str) > 0) {
        cout << fixed << setprecision(4) << S(stoi(str));
    } else cout << -1;

    return 0;
}
