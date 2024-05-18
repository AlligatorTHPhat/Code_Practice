#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool check(string str) {
	stack<char> s;
	
	for (auto c : str) {
		if (s.empty() || c != s.top()) s.push(c);
		else if (s.top() == c) s.pop();
	}
	return s.empty();
}

int main() {
	int n;
	cin >> n;

	string str;
	vector<string> vec;

	while (n--) {
		cin >> str;
		if (check(str))
			vec.push_back(str);
	}

	cout << vec.size() << endl;
	for (auto x : vec)
		cout << x << endl;

	return 0;
}
