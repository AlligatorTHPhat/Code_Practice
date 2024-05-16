#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string A, string B) {
	string sorted_A = A;
	string sorted_B = B;
	sort(sorted_A.begin(), sorted_A.end());
	sort(sorted_B.begin(), sorted_B.end());

	return sorted_A == sorted_B;
}
int main() {
	string A, B;
	cin >> A >> B;

	cout << (check(A, B) ? "True" : "False");
	return 0;
}
