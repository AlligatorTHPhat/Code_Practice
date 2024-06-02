#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

bool check(ll n) {
	if (n == pow(sqrt(n), 2)) return true;
	return false;
}

int main() {
	ll n;
	cin >> n;

	cout << (check(n) ? "True" : "False");

	return 0;
}
