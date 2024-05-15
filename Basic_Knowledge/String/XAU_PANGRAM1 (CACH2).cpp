#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int values[26] = {0}; 
	for (char x : s) {
		values[x - 'a'] = 1;
	}
	for (int i = 0; i < 26; i++) {
		if (!values[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 1;
}

