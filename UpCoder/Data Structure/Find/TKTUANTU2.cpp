#include <iostream>
#include <vector>
using namespace std;

int size_values, values[100], target;
vector<int>vec;

int linear_search(int size_values, int values[], int target) {
	for (int i = 0; i < size_values; i++) {
		if (values[i] == target) vec.push_back(i);
	}
	if (!vec.empty()) {
		for (auto x : vec) cout << x << " ";
	}
	else cout << -1;
}

int main() {
	cin >> size_values >> target;
	for (auto& x : values) cin >> x;

	linear_search(size_values, values, target);
	
}
