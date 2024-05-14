#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Permutation(int n, int k, string str) {
	if (str.size() == k) cout << str << endl;
	else {
		for (int i = 1; i <= n; i++) {
			string number = to_string(i);
			Permutation(n, k, str + number);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
    string str = "";

	cout << pow(n, k) << endl;
	Permutation(n, k, "");

	return 0;
}
