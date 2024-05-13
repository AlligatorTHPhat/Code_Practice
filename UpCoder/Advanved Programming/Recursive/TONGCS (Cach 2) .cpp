#include <iostream>

using namespace std;

int Sum(int number) {
	if (number < 10)
		return number;
	return number % 10 + Sum(number / 10);
}

int main() {
	int number;
	cin >> number;
	cout << Sum(number);

	return 0;
}
