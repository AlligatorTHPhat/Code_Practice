#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double S(int n) {
	if (n == 1) return 1;
	return sqrt(n + S(n - 1));
}

int main() {
	int n;
	cin >> n;

	n <= 100;
	cout << roundf(S(n) * 1000) / 1000;

	return 0;
}
