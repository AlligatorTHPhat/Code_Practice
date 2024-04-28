#include <iostream>
#include <string>

using namespace std;

int TONGCS(int number) {
	int result = 0;
	while (number > 0) {
		int digit = number % 10;
		result += digit;
		number /= 10;
	}
	return result;
}
int main() {
	
	int number; cin >> number;
	cout << TONGCS(number);
	return 0;
}
