#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Character {
	string name;
	int mark;


};
int main() {
	int n;
	cin >> n;

	vector<Character> vec(n);

	for (auto& x : vec)
		cin >> x.name >> x.mark;

	sort(vec.begin(), vec.end(), [](Character a, Character b) {
		return a.mark > b.mark; 
	});

	for (auto x : vec)
		cout << x.name << endl;
	return 0;
}
