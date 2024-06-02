#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

int main() {
	ll n;
	cin >> n;

	if (n == 0) { cout << 0; }

	else {
	    if(n < 0) n = -n;
		ll sum = 0;
		for (ll i = 1; i <= n; ++i)
			if (n % i == 0) sum += i;
		cout << sum;
	}

	return 0;
}
