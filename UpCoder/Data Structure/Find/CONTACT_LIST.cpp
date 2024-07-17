#include <iostream>
#include <string>

using namespace std;

void input(int& n, string& str, string values[], int a[], int b[]) {
	cin >> n;
	cin >> str;

	
	for (int i = 0; i < n; i++) {
		cin >> values[i];
		cin >> a[i] >> b[i];
	} str;
}

void linear_search(int n, string str, string values[], int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (values[i] == str) {
			cout << "{" << values[i] << "," << a[i] << "," << b[i] << "}";
			break;
		}
	}

	int max_a = a[0], min_b = b[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max_a) max_a = a[i];
		if (b[i] < min_b) min_b = b[i];
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		if (a[i] == max_a) {
			cout << "{" << values[i] << "," << a[i] << "," << b[i] << "}";
			break;
		}
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		if (a[i] == min_b) {
			cout << "{" << values[i] << "," << a[i] << "," << b[i] << "}";
			return;
		}
	}
}

int main() {
	int n;
	string str, values[10];
	int a[10], b[10];

	input(n, str, values, a, b);
	linear_search(n, str, values, a, b);
}
