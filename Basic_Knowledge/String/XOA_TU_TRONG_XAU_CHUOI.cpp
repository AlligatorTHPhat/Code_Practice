// XOA TU TRONG XAU CHUOI

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	string word; 
	cin >> word;

	stringstream ss(s);
	string token;

	vector<string> vec;
	while (ss >> token) {
		if(token != word) 
			vec.push_back(token);
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
		if(i != vec.size() - 1 )
			cout << " ";
	}

	return 0;
}
