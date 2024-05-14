#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Factorial(int n) {
	if (n == 1) return 1;
	return n * Factorial(n - 1);
}

int Permutation(int n, string str = "") {
	if (str.size() == n) cout << str << endl;
	else {
		for (int i = 1; i <= n; i++) {
			string number = to_string(i);
			auto check = str.find(number);
			if (check != string::npos)
				continue;
			else Permutation(n, str + number);
		}
	}
}

int main() {
	int n;
	cin >> n;

	cout << Factorial(n) << endl;
	Permutation(n);

	return 0;
}
