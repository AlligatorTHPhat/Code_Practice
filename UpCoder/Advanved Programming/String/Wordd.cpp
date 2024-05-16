#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int split_string(string str) {
	vector <string>vec;
	
	str[0] = tolower(str[0]);
	int i = 0;
	int check = 0;

	while (i < str.size()) {
		if (str[i] == str[i + 1]) {
			vec.push_back(str.substr(check, i - check + 1));

			while (str[i] == str[i + 1]) {
				++i;
				if (i + 1 >= str.size())
					return vec.size();
			}
			check = i + 1;
		}
		++i;
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	return vec.size() + 1;
}

int main() {
	string str;
	getline(cin, str);

	cout << split_string(str);
}
