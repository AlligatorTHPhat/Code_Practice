#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

float Factorial(float n) {
	if (n == 1) return 1;
	return n * Factorial(n - 1);
}

float Sum(int n, int x) {
	if (n == 0) return x;
	return (pow(-1, n) * pow(x, 2*n+1)/Factorial(2 * n + 1)) + Sum(n - 1, x);
}

int main() {
	float n, x;
	cin >> n >> x;

	cout << roundf(Sum(n, x) * 1000) / 1000;
	
	return 0;
}
