#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if (1 <= a && a <= 1000 && 1 <= b && b <= 1000) {
		cout << a + b;
		return 0;
	}
	else return 0;
}
