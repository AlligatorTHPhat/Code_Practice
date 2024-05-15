#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

void Viet_Hoa(string& s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
}

void Chuan_Hoa(string& s) {
	s[0] = toupper(s[0]);
	for (int i = 1; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}
int main() {
	int number;
	cin >> number;
	
	cin.ignore();
	map<string, int> mp;

	while (number--) {
		string s;
		getline(cin, s);

		vector<string> vec;
		stringstream ss(s);

		string tmp;
		string res = "";
		while (ss >> tmp)
			vec.push_back(tmp);

		Chuan_Hoa(vec[vec.size() - 1]);
		cout << vec[vec.size() - 1] << ", ";

		for (int i = 0; i < vec.size() - 1; i++) {
			Chuan_Hoa(vec[i]); cout << vec[i];
			if (i != vec.size() - 2) cout << " ";
		}
		cout << endl;
	}
}

//input
// 1
// Tran Hoang Phat

//output
// Phat, Tran Hoang
