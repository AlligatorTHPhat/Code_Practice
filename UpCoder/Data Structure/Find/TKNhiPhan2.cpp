#include <iostream>
using namespace std;

int size_values;
int target;

int binary_search(int size_values, int values[], int target) {
	int left = 0, right = target - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (values[mid] == target) return mid;
		else if (values[mid] < target) left = mid + 1;
		else if (values[mid]) right = mid - 1;
	} return -1;
}

int main() {

	cin >> size_values >> target;

	int values[100];
	for (auto &x : values)
		cin >> x;

	int res = binary_search(size_values, values, target);

	if (res != -1) {
		for (int i = 0; i < size_values; i++)
			if(values[i] == target) cout << i << " ";
	}
	else cout << -1;
}
