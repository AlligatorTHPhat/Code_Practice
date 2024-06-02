#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, x;
	cin >> a >> x;
	double S = (a + sin(x)) / sqrt(pow(a, 2) + pow(x, 2) + 1);

	cout << S;
}
