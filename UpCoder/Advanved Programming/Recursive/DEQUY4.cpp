#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int Sum(int n, int x) {
	int sum = 1;
	if (n == 0) return 1;
	return pow(x, n) + Sum(n - 1, x);
}

int main() {
	int n, x;
	cin >> n >> x;

	cout << Sum(n, x);
	
	return 0;
}
