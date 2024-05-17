#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(int n) {
	return (int)sqrt(n) == sqrt(n);
}

int main() {
	int n, k;
	cin >> n >> k;

	int* values = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}

	sort(values, values + n);
	cout << count_if(values, values + n, check) << endl;

	if (find(values, values + n, k) != (values + n)) cout << "Yes";
	else cout << "No";

	cout << endl;

	for (int i = 0; i < n; i++) {
		if (!check(values[i])) 
			cout << values[i] << " ";
	}
}
