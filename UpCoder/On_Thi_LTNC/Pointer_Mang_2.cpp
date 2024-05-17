#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int** values = new int* [n];
	for (int i = 0; i < n; i++) {
		values[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			values[i][j] = (i == j ? 1 : 0);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << values[i][j] << " ";
		}
		cout << endl;
	}
}
