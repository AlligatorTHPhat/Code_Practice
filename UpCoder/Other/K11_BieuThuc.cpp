#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float x;
	cin >> x;
	if (x < 2.5) { cout << "NHAP SAI"; return 0; }
	cout << sqrt(2*x - 5);
	return 0;
}
