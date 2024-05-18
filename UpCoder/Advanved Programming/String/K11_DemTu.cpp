#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	vector<string> vec;

	while (cin >> str) {
		vec.push_back(str);
	}

	cout << vec.size();

	

	return 0;
} 
