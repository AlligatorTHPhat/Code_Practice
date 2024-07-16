#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
	int distantce_a = pow(a.first, 2) + pow(a.second, 2);
	int distantce_b = pow(b.first, 2) + pow(b.second, 2);
	if (distantce_a != distantce_b) return distantce_a < distantce_b;
	if (a.first != b.first) {
		return a.first < b.first;
	} return a.second < b.second;
}

int solve(int n) {
	if (n > 10) return 5;
	if (n <= 10) return 100;
}
int main() {
	int n;
	cin >> n;
	
	pair<int, int> values[n];
	for (int i = 0; i < n; i++) {
		cin >> values[i].first >> values[i].second;
	}

	sort(values, values + n, compare); 
	for (auto it : values) {
		cout << it.first << " " << it.second;
	}
	
	return 0;
}
