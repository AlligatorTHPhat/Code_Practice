#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float a;
	cin >> a;

	cout << pow(a, 2) - (pow(a/2,2) * M_PI);
	return 0;
}
