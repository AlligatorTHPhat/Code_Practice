#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Permutation(int n, int k, string str = "") {
	if (str.size() == n) cout << str << endl;
	else {
		for (int i = 1; i <= k; i++) {
			string number = to_string(i);
			auto check = str.find(number);
			if (check != string::npos)
				continue;
			else Permutation(n, k, str + number);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	Permutation(n,k);

	return 0;
}
