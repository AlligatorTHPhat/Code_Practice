#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int max = a;
	if (b > a) max = b;
	if (c > b) max = c;

	int min = a;
	if (b < a) min = b;
	if (c < b) min = c;

	cout << max << " " << min;
	return 0;
}
