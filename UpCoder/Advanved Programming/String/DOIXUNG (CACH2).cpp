#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool check(string str)
{
    stringstream ss(str);
    string word;
    string tmp = "";
    while(ss >> word)
    {
        tmp += word;
    }
    
    int len = 0, rig = tmp.size() - 1;
    while(len <= rig)
    {
        if(toupper(tmp[len]) != toupper(tmp[rig]))
            return false;
        
        len++;
        rig--;
    }
    return true;
}

int main()
{
    string str;
    int n;
    cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++)
    {
        getline(cin,str);
        if(check(str) == 1)
            cout << 1 << '\n';
        else 
            cout << 0 << '\n';
    }
    return 0;
}
