// EMAIL 1

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	cin.ignore();

	while (n--) {
		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			s[i] = tolower(s[i]);
		}

		vector<string> vec;
		stringstream ss(s);
		string tmp;

		while (ss >> tmp) {
			vec.push_back(tmp);
		}
		
		cout << vec[vec.size() - 1]; // cout << vec.back();

		for (int i = 0; i < vec.size() - 1; i++) {
			cout << vec[i][0];
		}
		cout << "@gmail.com" << endl;
	}	
	return 0;
}

// Input : 
// 2 
// NguYEN VAN maNH
// nGYUEN thuY LinH 
// 
// Output
// manhnv@gmail.com
// linhnt@gmail.com 
