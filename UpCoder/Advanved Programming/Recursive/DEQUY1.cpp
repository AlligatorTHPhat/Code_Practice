#include <iostream>
#include <string>
#include <vector>

using namespace std;

void De_Quy_1(int k, int n, vector<string>& result, string prefix = "") {
	if (n == 0) result.push_back(prefix);
	else {
		for (int i = 1; i <= k; i++) {
			De_Quy_1(k, n - 1, result, prefix + to_string(i));
		}
	}
}

int main() {
	int k, n;
	cin >> k >> n;

	vector<string> result;

	De_Quy_1(k, n, result);
	
	cout << result.size() << endl;

	for (const string& str : result) 
		cout << str << endl;

	return 0;
}
