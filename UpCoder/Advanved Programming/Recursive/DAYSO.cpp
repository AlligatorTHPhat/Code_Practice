#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int max_number(int n) {
	if (n < 2) return n;
	if (n % 2 == 0)
		return max_number(n / 2);
	else
		return max_number(n / 2) + max_number(n / 2 + 1);
}

int main() {
	int n;
	cin >> n;

	int max = -1;
	for (int i = 0; i <= n; i++) {
		if (max_number(i) > max)
			max = max_number(i);
	}
	cout << max;

	return 0;
}
