#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string s;
	cin >> s;

	int values[26] {0}; 
	set<char> se;
	for (char x : s) {
		se.insert(x);
	}
	if (se.size() == 26) cout << "YES" << endl;
	else cout << "NO" << endl;
}

