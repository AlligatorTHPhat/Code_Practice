#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int Num_Counting(string num) {
	stringstream ss(num);

	int cnt = 0;
	while (ss >> num) {
		bool is_Num = true;
		for (char c : num) {
			if (!isdigit(c)) {
				is_Num = false;
				break;
			}
		}
		if (is_Num)
			cnt++;
	}
	return cnt;
}
int main() {
	string str;
	while (getline(cin, str)) {
		cout << Num_Counting(str) << endl;
	}
	return 0;
}
