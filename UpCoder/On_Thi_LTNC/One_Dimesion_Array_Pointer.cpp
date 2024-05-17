#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool condition(int a, int b) {
	return a > b;
}

int main() {
	int* arr = new int[5];
	for (int i = 0; i < 5; i++)
		cin >> arr[i]; // cin >> *(arr + i);

	for (int i = 0; i < 5; i++)
		cout << arr[i] << " "; // cout << *(arr + i);
	cout << endl;

	reverse(arr, arr + 5);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " "; // cout << *(arr + i);
	cout << endl;

	sort(arr, arr + 5);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " "; // cout << *(arr + i);
	cout << endl;

	sort(arr, arr + 5, condition);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " "; // cout << *(arr + i);
	cout << endl;

	sort(arr, arr + 5, [](int a, int b) {return a > b; });
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " "; // cout << *(arr + i);
	cout << endl;

	delete[] arr;
	return 0;
}
