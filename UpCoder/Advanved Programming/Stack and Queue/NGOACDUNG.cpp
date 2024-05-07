#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_matching(char open, char close)
{
	return (open == '(' && close == ')') ||
		(open == '[' && close == ']') ||
		(open == '{' && close == '}');
}

bool is_balance(string str)
{
	stack<char> stk;

	for (char c : str)
	{
		if (c == '(' || c == '[' || c == '{') 
		    stk.push(c);
		else if (c == ')' || c == ']' || c == '}')
		{
			if (stk.empty() || !is_matching(stk.top(), c))
			    return 0;
		    stk.pop();
		}
	}
	return stk.empty();
}

int main()
{
	string str;
	cin >> str;


	cout << (is_balance(str) ? "yes" : "no");
}
