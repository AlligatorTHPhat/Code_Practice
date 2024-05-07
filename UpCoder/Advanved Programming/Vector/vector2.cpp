#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    //day so
    vector<int> vt;
    string str;
    getline(cin,str);
    
    if(str.length() < 3) {
        //str[0] = ASCII ? chuyen thanh so nguyen va 48 = ASCII 0
        int pos_a = str[0] - 48;
        
        int n;
        while(cin >> n) {
            vt.push_back(n);
        }
        //xoa vi tri a
        if(str[0] != '-') vt.erase(vt.begin() + pos_a);
        else vt.clear();
    } 
    else {
        //str[0] = ASCII ? chuyen thanh so nguyen va 48 = ASCII 0
        //in ra vi tri a tu string -> int cua ASCII
        int pos_a = str[0] - 48;
        int pos_b = str[2] - 48;
        
        int n;
        while(cin >> n) vt.push_back(n);
        // xoa khoang cach [a,b) <=> a, b - 1
        vt.erase(vt.begin() + pos_a, vt.begin() + pos_b );
    }
    
    if(!(vt.empty())) {
        for(int i = 0; i < vt.size(); i++) {
            cout << vt[i] << " ";
        }
    } else cout << "empty";
    
    return 0;
    
}
