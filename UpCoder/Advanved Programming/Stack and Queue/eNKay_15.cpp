#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	stack<int> stk;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') stk.push(i + 1);
		else {
			cout << stk.top() << " " << i + 1 << "\n";
			stk.pop();
		}
	}

	return 0;
} 
