#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> str;
    char kytu;
    
    while(cin >> kytu)
    {
        if(kytu == '*')
        {
            if(str.empty())
            {
                continue;
            }
            cout << str.top();
            str.pop();
        }
        else 
        {
            str.push(kytu);
        }
    }
    return 0;
}
