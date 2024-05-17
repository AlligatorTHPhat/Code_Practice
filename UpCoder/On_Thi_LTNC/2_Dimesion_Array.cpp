#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int** values = new int * [5]; // so hang (row)

	for (int i = 0; i < 5; i++) {
		values[i] = new int[10]; // moi hang co 10 cot (col)
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			values[i][j] = i * 10 + j;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << values[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
