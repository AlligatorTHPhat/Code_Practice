#include <iostream>
using namespace std;

int binary_search(int size,int values[], int n) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int m = (left + right) / 2;
		if (values[m] == n) return m;
		else if (values[m] < n) left = m + 1;
		else if (values[m]) right = m - 1;
	}
	return -1;
}

int main() {
	int size, values[100], n;
	cin >> size >> n;
	for (int i = 0; i < size; i++) 
		cin >> values[i];

	cout << binary_search(size, values, n);
	
	return 0;
}
