#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool stringpbrk(string str) {
	string cdt = "bdfhkt";
	for (char c : str) {
		if (cdt.find(c) != string::npos) return 0;
	}
	return 1;
}

int main() {
	string str, res;

	while (getline(cin,str)) {
		stringstream ss(str);
		string word;

		while (ss >> word) {
			if (stringpbrk(word)) {
				if (word.size() > res.size())
					res = word;
			}
		}
	}
	cout << res;

	return 0;
}
