#include <iostream>
using namespace std;

int main() {
    int values[4];
    
    for(int i = 0; i < 4; i++) {
        cin >> values[i];
        if(values[i] > 100) return 0;
    }
    
    int max = -1;
    for(int i = 0; i < 4; i++) {
        if(max < values[i]) max = values[i];
    }
    
    int cnt = 0, second = -1;
    for(int i = 0; i < 4; i++) {
        if(values[i] > second && values[i] < max) {
            second = values[i];
            cnt++;
        }
    }
    
    if(cnt == 0) cout << -1;
    else cout << second;
    
    return 0;
}
