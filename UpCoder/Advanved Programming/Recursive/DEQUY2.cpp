#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int Factorial(int number) {
	if (number < 1) return 1;
	else return number * Factorial(number - 1);
}

void Permutation_Chain(int number, string str) {
	if (str.length() == number)
		cout << str << endl;
	else {
		for (int i = 1; i <= number; i++) {
			string num = to_string(i);
			auto check = str.find(num);
			if (check != string::npos) continue;
			else Permutation_Chain(number, str + num);
		}
	}
	return;
}

int main() {
	int number; 
	cin >> number;
	cout << Factorial(number) << endl;

	string str;
	Permutation_Chain(number, str);

	return 0;
}
