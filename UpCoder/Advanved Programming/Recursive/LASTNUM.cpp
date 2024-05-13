#include <iostream>

using namespace std;

int sum_of_digit(int num) {
	if (num < 10) return num;

	return num % 10 + sum_of_digit(num / 10);
}

int Last_Number(int num) {
	while(num >= 10) 
		num = sum_of_digit(num);
	return num;
}

int main() {
	int num;
	cin >> num;

	cout << Last_Number(num);

	return 0;
}
