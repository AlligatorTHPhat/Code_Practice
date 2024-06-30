#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int x;
	cin >> x;

	if (x == 0) cout << "KHONG";
	else if (x > 0) cout << "DUONG";
	else if (x < 0) cout << "AM";

	return 0;
}
