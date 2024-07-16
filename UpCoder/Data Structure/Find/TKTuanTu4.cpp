#include <iostream>

using namespace std;

void input(int& x, int values[], int& size) {
	cin >> x;

	int tmp;
	while (cin >> tmp) {
		values[size++] = tmp;
	} return;
}

void linear_search(int x, int values[], int size) {
	int res = -1, max = -1e6;
	for (int i = 0; i < size; i++) {
		if (values[i] <= x && values[i] >= max) {
			res = i; max = values[i];
		}
	}

	if (res != -1) {
		for (int i = 0; i < size; i++) {
			if (values[i] == values[res]) cout << i << " ";
		} return;
	} cout << res;
}

int main() {
	int x;
	int values[100], size = 0;

	input(x, values, size);

	linear_search(x, values, size);


}
