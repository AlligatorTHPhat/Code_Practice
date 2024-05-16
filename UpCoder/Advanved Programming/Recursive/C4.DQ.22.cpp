#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.14159

double S(int n, int x) {
	if (n == 1) return sin((x * PI) / 180) + cos((x * PI) / 180);
	return (sin(n * (x * PI) / 180) + cos(n * (x * PI) / 180)) + S(n - 1, x);
}

int main() {
	int n, x;
	cin >> n >> x;

	cout << fixed << setprecision(3) << S(n, x);

	return 0;
}
