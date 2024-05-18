#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int num = 0;
	for (char c : str) {
		if (isdigit(c)) num += c - '0';
	}

	cout << num;


}
