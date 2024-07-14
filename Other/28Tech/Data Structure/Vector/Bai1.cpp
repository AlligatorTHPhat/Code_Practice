#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x;
    vector<int> vec;

    int i = n;
    while (i != 0) {
        int tmp;
        cin >> x;
        if (x == 1) {
            cin >> tmp; 
            vec.push_back(tmp);
        }
        else if (x == 2 && !vec.empty()) {
            vec.pop_back();
        }
        else if (x == 2);
        i--;
    }

    if (vec.empty()) {
        cout << "EMPTY";
    } else {
        for (auto v : vec) {
            cout << v << " ";
        }
    }
    return 0;
}

/*
input :
    7
    1 56
    2
    2
    1 81
    1 51
    1 12
    1 2
*/
