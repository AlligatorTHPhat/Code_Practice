#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void split_name(string full_name) {
    stringstream ss(full_name);
    vector<string> word;
    string tmp;

    while (getline(ss, tmp, ' ')) {
        word.push_back(tmp);
    }

    if (word.size() > 2) {
        cout << word[0] << endl;
        for (int i = 1; i < word.size() - 1; i++) {
            cout << word[i] << " ";
        }
        cout << endl << word.back();
    }
    else {
        cout << word[0] << word[1];
    }
    return;
}

int main() {
    string full_name;
    getline(cin, full_name);
    split_name(full_name);

    return 0;
}
