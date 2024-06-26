#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	float result = (a + b + c) * 1.0 / (d + e + f);
	cout << fixed << setprecision(1) << result;
	return 0;
}
