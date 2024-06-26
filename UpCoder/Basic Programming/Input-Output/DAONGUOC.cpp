#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while (n != 0) {
		int tmp = n % 10;
		cout << tmp;
		n /= 10;
	}

	return 0;
}
