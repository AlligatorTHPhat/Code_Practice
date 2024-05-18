#include <iostream>
#include <string>

using namespace std;

string Captialize(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (i == 0 || str[i - 1] == ' ')
			str[i] = toupper(str[i]);
		else {
			str[i] = tolower(str[i]);
		}
	}
	return str;
}
int main() {
	string str;

	getline(cin, str);

	cout << Captialize(str);
	return 0;
}
