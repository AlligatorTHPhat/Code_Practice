#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main() {
	string words;
	getline(cin, words);

	vector<string> vec;
	stringstream ss(words);
	string word;

	while (ss >> word)
		vec.push_back(word);

	for (auto it = vec.rbegin(); it != vec.rend(); it++)
		cout << *it << " ";
	return 0;

}
