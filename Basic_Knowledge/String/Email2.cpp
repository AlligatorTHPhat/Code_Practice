#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    map<string, int> mp;

    while (n--)
    {
        string str;
        getline(cin, str);
        for (int i = 0; i < str.size(); i++)
        {
            str[i] = tolower(str[i]);
        }
        vector<string> vt;
        stringstream ss(str);

        string tmp;
        string res = "";
        while (ss >> tmp)
        {
            vt.push_back(tmp);
        }
        res += vt[vt.size() - 1]; // res += vt.back()
        for (int i = 0; i < vt.size() - 1; i++)
        {
            res += vt[i][0];
        }
        if (mp[res] == 0)
            cout << res << "@gmail.com\n";
        else
            cout << res << mp[res] + 1 << "@gmail.com\n";

        mp[res]++;
    }
    return 0;
}

/*
input
6
Hans Seetck
HANS SEETCK
hans seectk
Winter
Mirroer
Kirhin

output
seetckh@gmail.com
seetckh2@gmail.com
seectkh@gmail.com
winter@gmail.com
mirroer@gmail.com
*/
