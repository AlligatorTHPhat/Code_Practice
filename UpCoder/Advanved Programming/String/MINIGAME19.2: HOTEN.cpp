#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void split_name(string full_name) {
    vector<string> name_part;
    stringstream ss(full_name);
    string part;
    while (ss >> part) {
        name_part.push_back(part);
    }
    if (name_part.size() > 2) {
        cout << "Ho: " << name_part[0] << endl;
        cout << "Lot: ";
        for (int i = 1; i <= name_part.size() - 2; i++) {
            cout << name_part[i] << " ";
        }
        cout << endl << "Ten: " << name_part.back();
    }
    else
        cout << "Ho: " << name_part[0] << endl << "Ten: " << name_part[1];

}

int main() {
    string full_name;
    getline(cin, full_name);

    split_name(full_name);

    return 0;
}
