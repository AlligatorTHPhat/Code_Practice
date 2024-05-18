#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	char s;
	cin >> s;

	size_t pos = str.find(s);
	while (pos != string::npos) {
	    cout << pos << " "; 
	    pos = str.find(s, pos + 1);
	}

	return 0;
} 
