#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;

	int x, n;
	
	cin >> n;
	while (n != 0) {
		cin >> x;
		v.push_back(x);
		n--;
	}

	for (auto it = v.rbegin(); it != v.rend(); it++ ) {
		cout << *it << " ";
	}

	return 0;
}
