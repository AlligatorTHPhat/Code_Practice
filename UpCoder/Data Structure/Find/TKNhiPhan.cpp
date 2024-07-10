#include <iostream>
using namespace std;

int binary_search(int size,int values[], int target) {
	int left = 0, right = target - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (values[mid] == target) return mid;
		else if (values[mid] < target) left = mid + 1;
		else if (values[mid]) right = mid - 1;
	}
	return -1;
}

int main() {
	int size, values[100], target;
	cin >> size >> target;
	for (int i = 0; i < size; i++) 
		cin >> values[i];

	cout << binary_search(size, values, target);
	
	return 0;
}
