#include <iostream>

using namespace std;

int main() {
	double n, month;
	cin >> n >> month;

	if (n < 0 || month < 0) { cout << 0; return 0; }

	double interest = n * 0.05;
	double result = interest;

	while (month < 12) {
		interest *= 0.05;
		result += interest;
		month++;
	}

	cout << result + n;

	return 0;
}
