#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>

using namespace std;

bool Symmetry(string str) {
	stringstream ss(str);
	string word; string temp = "";

	while (ss >> word) temp += word;

	int left = 0, right = temp.length() - 1;

	while (left <= right) {
		if (toupper(temp[left]) != toupper(temp[right]))
			return 0;
		left++; right--;
	}
	return 1;
}
int main() {
	int n; cin >> n;
	string str; cin.ignore();

	for (int i = 0; i < n; i++) {
		
		getline(cin, str);
		cout << (Symmetry(str) ? 1 : 0);
		cout << endl;
	}
	return 0;
}

