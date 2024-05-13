#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

bool Is_Palindrom(string str) {
	string s = str;

	transform(s.begin(), s.end(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());


	string reversed = s;

	reverse(reversed.begin(), reversed.end());
	return s == reversed;
}
int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	string str;
	while (getline(cin, str)) {
		cout << Is_Palindrom(str) << endl;
	}

	cin.close();
	cout.close();
	return 0;
}
