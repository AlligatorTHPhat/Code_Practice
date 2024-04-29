#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void Permutation_Combination(int n, int k, string str) {
	if (str.length() == n) cout << str << endl;
	else {
		for (int i = 1; i <= k; i++) {
			string number = to_string(i);
			auto check = str.find(number);
			if (check != string::npos) continue;
			else Permutation_Combination(n, k, str + number);
		}
	}
	return;
}

int main() {
	int n, k;
	cin >> n >> k;

	string str;
	Permutation_Combination(n, k, str);
	
	return 0;
}
