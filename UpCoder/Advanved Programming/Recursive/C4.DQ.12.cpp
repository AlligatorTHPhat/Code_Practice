#include <iostream>
#include <cmath>
using namespace std;

long long S(int n, int x) {
	if (n == 1) return x;
	return pow(x, n) + S(n - 1, x);
}

int main() {
	int n, x;
	cin >> n >> x;
	cout << S(n, x);
	return 0;
}
