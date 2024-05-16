#include <iostream>

using namespace std;

//1. Sử dụng hàm đệ quy
long long S(int n) {
	if (n == 0) return 0;
	return n*n + S(n - 1);
}

int main() {
	int n;
	cin >> n;
	n <= 1000;
	cout << S(n);
	return 0;
}
