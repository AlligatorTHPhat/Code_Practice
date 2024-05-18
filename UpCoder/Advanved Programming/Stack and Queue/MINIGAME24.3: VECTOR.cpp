#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q, tmp;
	cin >> n;
	
	vector<int> vec(n);
	for (int& x : vec) cin >> x;

	cin >> q;
	while (q--) {
		cin >> tmp;
		auto it = lower_bound(vec.begin(), vec.end(), tmp);
		cout << (vec[it - vec.begin()] == tmp ? "Yes" : "No");
		cout << it - vec.begin() + 1;
	}

	return 0;
}
