#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> numbers;
    int num;

    while (cin >> num) {
        numbers.push_back(num);
    }

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        cout << *it << " ";
    }

    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int>vt;
    int n;
    while(cin>>n) {
        vt.push_back(n);
    }
    vector<int>::iterator it;
    for(it = vt.begin(); it != vt.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    vector<int>::reverse_iterator rit;
    for(rit = vt.rbegin(); rit != vt.rend(); rit++) {
        cout << *rit << " ";
    }
    return 0;
    
}
*/
