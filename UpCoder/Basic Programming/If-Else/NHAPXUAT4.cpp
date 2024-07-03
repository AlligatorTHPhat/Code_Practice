#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	cout << (n > 100 ? (n / 100) % 10 : -1);
	return 0;
}
