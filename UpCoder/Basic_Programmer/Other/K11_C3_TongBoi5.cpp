#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

bool check(ll n) {
	if (n % 5 == 0) return true;
	return false;
}

int main() {
	ll n;
	cin >> n;

	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (check(i)) sum += i;
	}
	cout << sum;

	return 0;
}
