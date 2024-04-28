#include <iostream>
#include <string>

using namespace std;

void Day_NP(int number, string prefix = "") {
	if (number == 1) cout << prefix << endl;
	else {
		Day_NP(number - 1, prefix + "0");
		Day_NP(number - 1, prefix + "1");
	}
}
int main() {
	
	int number; cin >> number;
	Day_NP(number);
	return 0;
}
