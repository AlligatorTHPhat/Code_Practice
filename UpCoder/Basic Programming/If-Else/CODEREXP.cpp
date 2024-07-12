#include <iostream>

using namespace std;

int main() {
    int basic, normal, advanced, hard;
    
    cin >> basic >> normal >> advanced >> hard;
    
    int point = (basic * 10) + (normal * 20) + (advanced * 30) + (hard * 40);
    
    if (point < 1) cout << point << "\nCoder So Sinh";
    else if (point < 49) cout << point << "\nCoder Lop Mam";
    else if (point < 99) cout << point << "\nCoder Lop Choi";
    else if (point < 499) cout << point << "\nCoder Lop La";
    else if (point < 999) cout << point << "\nCoder Tieu Hoc";
    else if (point < 1499) cout << point << "\nCoder THCS";
    else if (point < 1999) cout << point << "\nCoder THPT";
    else if (point < 2499) cout << point << "\nCoder Trung Cap";
    else if (point < 3499) cout << point << "\nCoder Cao Dang";
    else if (point < 4199) cout << point << "\nCoder Dai Hoc";
    else if (point < 5499) cout << point << "\nCoder Thac Si";
    else if (point < 6999) cout << point << "\nCoder Tien Si";
    else if (point >= 7000) cout << point << "\nCoder Giao Su";
    
    return 0;
}
