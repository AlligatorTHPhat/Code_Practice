#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    
    while(cin >> str) {
        size_t pos = str.find("@gmail.com");
        if(pos != string::npos) cout << str << "\n";
    }
}
