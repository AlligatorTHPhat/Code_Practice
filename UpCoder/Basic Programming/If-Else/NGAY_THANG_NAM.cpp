#include <iostream>
using namespace std;

bool check_leap_year(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int main() {
    int day, month, year;
    cin >> day >> month >> year;
    
    if (year < 1900 || month < 1 || month > 12) {
        cout << "NO";
        return 0;
    }
    
    int max_day;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            max_day = 31;
            break;
        case 4: case 6: case 9: case 11:
            max_day = 30;
            break;
        case 2:
            max_day = check_leap_year(year) ? 29 : 28;
            break;
        default:
            max_day = 0; // This case should never happen due to previous validation
    }
    
    if (day >= 1 && day <= max_day) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
