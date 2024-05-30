#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double degree_to_radian(double x) {
    return (x * M_PI) / 180;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double a, b, C;
    cin >> a >> b >> C;
    if (C == 180) cout << "KHONG PHAI TAM GIAC";
    else {
        double R_C = degree_to_radian(C);
        double c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(R_C));
        cout << roundf(c*10000)/10000;
    }
    
    return 0;
}

