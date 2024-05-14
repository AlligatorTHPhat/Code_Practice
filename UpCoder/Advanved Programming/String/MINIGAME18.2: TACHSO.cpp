#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void split_number(string str) {
    stringstream ss(str);
    string tmp;
    vector<string> vec;
    while (getline(ss, tmp, ',')) {
        vec.push_back(tmp);
    }
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
        sum += stoi(vec[i]);
    }
    cout << sum;
}

int main() {
    string str;
    getline(cin, str);

    split_number(str);

    return 0;
}
