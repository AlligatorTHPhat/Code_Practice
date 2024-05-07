#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> stk;
    string input;
    cin >> input;
    
    for(char c : input)
    {
        if(c == '*') 
        {
            if(!stk.empty())
            {
                cout << stk.top() << endl;
                stk.pop();
            }
        } else {
            stk.push(c);
        }
    }
    
    return 0;
}
