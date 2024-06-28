#include <iostream>
#include <cmath>

using namespace std;

bool check(int n) {
	int k = sqrt(n);
	return k * k == n;
}

int main() {
	int n; cin >> n;
	cout << ( check(n) ? "yes" : "no");

	return 0;
}
