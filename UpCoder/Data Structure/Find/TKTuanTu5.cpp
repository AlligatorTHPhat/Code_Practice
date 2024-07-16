#include <iostream>

using namespace std;

void input(int& n, int& x, int& y, int values[]) {
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	} return;
}

void linear_Search(int n, int x, int y, int values[]) {
	for (int i = 0; i < n; i++) {
		if (values[i] == x) {
			cout << i; 
			return;
		}
	}

	int a = x, b = x;
	while (a >= x - y && b <= x + y) {
		for (int i = 0; i < n; i++) {
			if (values[i] == a || values[i] == b) {
				cout << i; return;
			}
		} a--, b++;
	} cout << -1; return;
}

int main() {
	int n, x, y;
	int values[100];

	input(n, x, y, values);

	linear_Search(n, x, y, values);

	return 0;
}


