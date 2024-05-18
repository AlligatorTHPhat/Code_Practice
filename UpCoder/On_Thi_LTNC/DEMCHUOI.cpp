#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int count(string word, string str)
{
    int cnt = 0;
    int pos = str.find(word);
    while(pos != string::npos)
    {
        cnt++;
        pos = str.find(word,pos + 1); 
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    string word;
    cin >> word;
    cin.ignore();

    int cnt;
    for(int i = 0; i < n; ++i)
    {
        string str;
        getline(cin,str);
        
        cnt = count(word,str);
        cout << cnt << "\n";
    }
    
    return 0;
}
