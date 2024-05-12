#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(string str) {
	char tmp[] = { 'u', 'p', 'c','o','d','e','r' };

	int index = 0;
	for (char c : str) {
		if (c == tmp[index]) index++;
	}
	return index == 7;
}
int main() {
	vector<int> vec; int index = 1;

	int number; cin >> number;

	string str; cin.ignore();
	while (number--) {
		getline(cin, str);
		if (check(str)) vec.push_back(index);
		index++;
	}

	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	return 0;
}
