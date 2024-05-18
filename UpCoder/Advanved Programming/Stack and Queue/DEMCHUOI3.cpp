#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int q, n;
	cin >> n;

	vector<string> vec(n);
	for (auto& x : vec) cin >> x;

	cin >> q;
	string tmp;

	while (q--) {
		cin >> tmp;
		cout << count(vec.begin(), vec.end(), tmp) << endl;
	}
	return 0;
}
