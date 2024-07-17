#include <bits/stdc++.h>

using namespace std;

void input(int& n, int& x, int values[]) {
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> values[i];
	return;
}

void linear_search(int n ,int x, int values[]) {
	for (int i = 0; i < n; i++) {
		if (values[i] == x) {
			cout << "Y" << endl << i;
			return;
		}
	}
	
	int k = INT_MIN;
	for (int i = n - 1; i >= 0; i--) {
		if (values[i] < x && values[i] > k) {
			k = values[i];
		}
	}

	if (k != INT_MIN) {
		for (int i = n - 1; i >= 0; i--) {
			if (values[i] == k) {
				cout << "N" << endl << i;
				return;
			}
		}
	}
	else cout << "N" << endl << -1; return;
}

int main() {
	int n, x;
	int values[100];

	input(n, x, values);

	linear_search(n, x, values);

	return 0;

}
/*
input :
	8 52
	41 59 26 53 58 97 93 41

	5 7 
	10 9 13 8 12
*/
