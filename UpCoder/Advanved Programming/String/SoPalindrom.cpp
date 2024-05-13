#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool Is_Palindrom(string str) {
	string reversed = str;
	reverse(reversed.begin(), reversed.end());
	return str == reversed;
}
int main() {
	int num;
	cin >> num; 

	string str;
	for(int i = 0; i < num; i++) {
	    cin >> str;
		if (Is_Palindrom(str)) cout << str << " ";
	}

	return 0;
}
