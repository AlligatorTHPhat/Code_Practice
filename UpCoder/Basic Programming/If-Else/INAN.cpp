#include <iostream>
#include<cmath>

using namespace std;

int main() {

	int T;
	long long P, C, res;

	cin >> T >> P >> C;

	1 <= T; T <= 2;
	1 <= P; P <= pow(10, 9);
	1 <= C; C <= pow(10, 9);

	if (T == 1) {
		res = P * C;
	}

	else if (T == 2) {
		res = (P / 2 + P % 2) * C;
	}

	cout << res;
	return 0;
}
