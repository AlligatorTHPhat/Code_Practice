#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string str;
    while(getline(cin,str)) {
        vector<double> vec;
        stringstream ss(str);
        double tmp;
        
        while(ss >> tmp) {
            vec.push_back(tmp);
        }
        
        double sum = 0;
        
        for(int i = 0; i < vec.size(); i++) {
            sum += vec[i];
        }
        cout << roundf(sum * 1000) / 1000 << endl;
    }
    return 0;
}
