#include <iostream>
using namespace std;

int main() {
	int m, n, cnt(0);
	cin >> m >> n;

	bool* values = new bool[1000];

	for (int i = 0; i < 1000; i++) {
		values[i] = false;
	}

	while (m--) {
		int tmp;
		cin >> tmp;
		values[tmp] = true;
	}

	while (n--) {
		int tmp;
		cin >> tmp;
		if (!values[tmp]) cnt++, values[tmp] = true;
	}

	cout << cnt;
}
