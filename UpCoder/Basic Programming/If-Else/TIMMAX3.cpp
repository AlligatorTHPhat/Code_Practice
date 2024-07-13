#include <iostream>
#include <cmath>

bool check(int n) {
    return n >= std::pow(10, 5);
}

int main() {
    int values[5];
    for(int i = 0; i < 5; i++) {
        std::cin >> values[i];
        if(check(values[i])) return 0;
    }
    
    int max = values[0];
    for(int i = 1; i < 5; i++) {
        if(max < values[i]) max = values[i];
    }
    
    std::cout << max;
    
    return 0;
}
