// TACH TU TRONG XAU CHUOI

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	stringstream ss(s);
	string word;

	vector<string> vec;
	while (ss >> word) {	
		vec.push_back(word);
	}

	for (string str : vec) {
		cout << str << endl;
	}

	return 0;A
}
