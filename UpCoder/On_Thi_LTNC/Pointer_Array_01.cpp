#include <iostream>
using namespace std;

bool check(int* values, int n) {
	for (int i = 0; i < n; i++)
		if (values[i] != values[n - i - 1])
			return false;
	return true;
}

int main() {
	int n;
	cin >> n;

	int* values = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}

	if (check(values, n)) cout << "mang doi xung";
	else {
		cout << "mang khong doi xung" << endl;
		for (int i = 0; i < n / 2; i++) {
			if (values[i] != values[n - i - 1])
				cout << values[i] << " " << values[n - i - 1] << endl;
		}
	}
}
