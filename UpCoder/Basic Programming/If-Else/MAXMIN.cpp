#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int i = 4, max = 0, min = n % 10;
    while (i != 0) {
        int temp = n % 10;
        if (max < temp) max = temp;
        if (min > temp) min = temp;
        // std::cout << "max: " << max << " ";
        // std::cout << "min: " << min << " ";
        n /= 10;
        i--;
    }
    std::cout << max + min;
    return 0;
}
