#include <iostream>

using namespace std;

int main() {
    int ab, bc, ca;
    int t;
    
    cin >> ab >> bc >> ca;
    cin >> t;
    
    int res = t % (ab + bc + ca);
    
    if (res == 0) {
        cout << "A";
    } else if (res < ab) {
        cout << "AB";
    } else if (res == ab) {
        cout << "B";
    } else if (res < bc + ab && res > ab) {
        cout << "BC";
    } else if (res == bc + ab) {
        cout << "C";
    } else if (res < ca + bc + ab && res > bc + ab) {
        cout << "CA";
    }
    
    return 0;
}
