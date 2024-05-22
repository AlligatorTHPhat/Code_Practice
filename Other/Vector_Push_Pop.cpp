#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int x;  cin >> x;

        if (x == 1) {
            int t; cin >> t;
            vec.push_back(t);
        } else {
            if (!vec.empty()) {
                vec.pop_back();
            }
        }
    } 

    if (vec.empty()) cout << "EMPTY\n";
    else {
        for (auto x : vec) cout << x << " ";
    }
    return 0;
}

/*
input 
    7
    1 5
    1 10
    1 20
    2
    1 15
    2
    2
output
    5
*/
