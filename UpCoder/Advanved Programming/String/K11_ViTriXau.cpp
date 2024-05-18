#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	char s;
	cin >> s;

	int pos = str.find(s);
	cout << (pos != string::npos ? pos : 0);

	return 0;
} 
