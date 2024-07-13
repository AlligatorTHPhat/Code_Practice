#include <iostream>
#include <cmath>

bool check(int n) {
    return n <= std::pow(10, 4);
}

int main() {
    int n;
    std::cin >> n;

    if (!check(n)) return 0;

    if (n % 3 == 0) {
        std::cout << n << " chia het cho 3";
    } else {
        std::cout << n << " chia 3 du " << (n % 3);
    }

    return 0;
}
