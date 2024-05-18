#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    string str("abcdef");
    
    queue<char> que;
    cin >> n;
    
    for(char c : str)
        que.push(c);
    
    while(n--) {
        que.push(que.front());
        que.pop();
    }
    
    while(!que.empty()) {
        cout << que.front();
        que.pop();
    }
    
    return 0;
}
