#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    set<int> se;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        se.insert(x);
    }

    cout << se.size();
}

/*
input 
    8
    1 2 3 1 3 2 0 4
output
    4
*/
