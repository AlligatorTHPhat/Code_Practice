#include<bits/stdc++.h>
using namespace std;
void xoaSo(string &a){
    for(int i = 0 ; i < a.size(); i++){
        if(a[i] >= 'a' && a[i] <='z' || a[i] >= 'A' && a[i] <= 'Z'){
            a[i] =' ';
        }
    }
}
void change(string &a, string &b){
    if(a.size() > b.size()){
        reverse(b.begin(), b.end());
        for(int i = b.size(); i < a.size() ; i++){
            b+='0';
        }
        reverse(b.begin(), b.end());
    }
    // return b;
    else if(a.size() < b.size()){
        reverse(a.begin(), a.end());
        for(int i = a.size(); i < b.size() ; i++){
            a+='0';
        }
        reverse(a.begin(), a.end());
    }
}
string sumString(string a, string b){
    change(a, b);
    string c = "";
    int n = a.size();
    int k = 0;
    int j;
    for(int i = n - 1; i >= 0 ; i--){
        k += a[i] - 48 + b[i] - 48;
        
        if(k <= 9 && i != 0){
            c += (k + '0');
            k = 0;
        }
        else if(k > 9 && i != 0){
            c += (k - 10 + '0');
            k = 1;
        }
        if(i == 0){
               if(k <= 9){
                   c+= (k + '0');
               }
               else {
                   c += (k % 10 + '0');
                   k/=10;
                   c +=(k + '0');
               }
        }
    }
    reverse(c.begin(), c.end());
    return c;
    
}

int main(){
    // string str1 = "657677778777999999979797";
    // string str2 = "000000000086910869102893";
    // cout << str1.compare(str2);
    
    
    
    
    // return 0;
    string a;
    getline(cin, a);
    xoaSo(a);
    stringstream ss(a);
    string s ="000";
    string word;
    while(ss >> word){
        while(word[0] == '0'){
            word.erase(0,1);
        }
        while(s[0] == '0'){
            s.erase(0,1);
        }
        
        if(s.size() == word.size()){
            long long k = s.compare(word);
            if(k <= 0){
                s = word;
            }
        }
        else if(s.size() < word.size()){
            s = word;
        }
    }
    
    if(s.empty()) cout <<"0";
    cout << s;
    return 0;
}
