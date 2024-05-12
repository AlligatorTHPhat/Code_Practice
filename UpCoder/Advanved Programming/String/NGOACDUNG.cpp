#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check(string str) {
	stack<char> stk;
	if (str.length() == 0) return 1;
	for (char c : str) {
		if (c == '(' || c == '[' || c == '{') stk.push(c);
		else if (!stk.empty()) {
			char top = stk.top();
			stk.pop();
			if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
				return 0;
		}
		else return 0;
	}
	return stk.empty();
}
int main() {
	string str;
	getline(cin, str);
	cout << (check(str) ? "yes" : "no");

	return 0;
}
