#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double a, b;
	cin >> a >> b;

	if (a != 0) {
		cout << fixed << setprecision(2) << (-b / a);
	}
	else if (a == 0) {
		if (b != 0) cout << "VN";
		else if (b == 0) cout << "VSN";
	}
	return 0;
}
