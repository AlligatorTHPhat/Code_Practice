// #include <iostream>
// using namespace std;
// int a[100],k,n;
// string s;
// void inkq(){
//     for (int i = 0 ; i< n ; i++){
//         cout << s[i] ;
//     }
//     cout << endl;
// }
// void try(int i){
//     for  (int j = 1; j <= k ; j++){
//         if (i == K) { inkq();}
//         else {
//             try(i + 1);
//         }
//     }
// }
// int main(){
//     cin >>  k >> n;
//     cin.ignore();
//     cin >> s;
//     try(1);
// }
#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
vector<string> printedWords; 

void dqQL(const string& result, int index) {
    if (result.length() == k) {
        cout << result << endl;
        printedWords.push_back(result);
        return;
    }

    for (int i = index; i < n; ++i) {
        dqQL(result + s[i], i); 
    }
}

void noi() {
    sort(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        dqQL(string(1, s[i]), i);
    }
}

int main() {
    cin >> n >> k >> s;
    noi();

    return 0;
}

