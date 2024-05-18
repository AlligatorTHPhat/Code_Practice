#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k, tmp;
    cin >> n >> k;
    
    queue<int> que;
    while(n--) {
        cin >> tmp;
        que.push(tmp);
    }
    
    while(k--) {
        que.push(que.front());
        que.pop();
    }
    
    while(!que.empty()) {
        cout << que.front()<< " ";
        que.pop();
    }
    
    return 0;
}
