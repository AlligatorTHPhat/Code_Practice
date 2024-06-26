#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n; n < 100;

	int sum = 0;
	while (n != 0) {
		int tmp = n % 10;
		sum += tmp;
		n /= 10;
	}
	cout << sum;

	return 0;
}
