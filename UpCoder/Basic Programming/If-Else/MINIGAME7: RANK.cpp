#include <iostream>

using namespace std;

int main() {
    int Gold_VN, Silver_VN, Bronze_VN;
    int Gold_TL, Silver_TL, Bronze_TL;
    int x;
    
    cin >> Gold_VN >> Silver_VN >> Bronze_VN;
    cin >> Gold_TL >> Silver_TL >> Bronze_TL;
    cin >> x;

    if (x == 1) {
        if (Gold_VN + Silver_VN + Bronze_VN > Gold_TL + Silver_TL + Bronze_TL) {
            cout << "VN";
        } else if (Gold_VN + Silver_VN + Bronze_VN < Gold_TL + Silver_TL + Bronze_TL) {
            cout << "TL";
        } else {
            cout << "TIE";
        }
    } else if (x == 2) {
        if (Gold_VN > Gold_TL) {
            cout << "VN";
        } else if (Gold_VN < Gold_TL) {
            cout << "TL";
        } else { // Gold_VN == Gold_TL
            if (Silver_VN > Silver_TL) {
                cout << "VN";
            } else if (Silver_VN < Silver_TL) {
                cout << "TL";
            } else { // Silver_VN == Silver_TL
                if (Bronze_VN > Bronze_TL) {
                    cout << "VN";
                } else if (Bronze_VN < Bronze_TL) {
                    cout << "TL";
                } else { // Bronze_VN == Bronze_TL
                    cout << "TIE";
                }
            }
        }
    }

    return 0;
}
