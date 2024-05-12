#include <iostream>
#include <string>
using namespace std;

int find_position(int number) {
	string sequence = "";
	int position = 0;

	for (int i = 1; i <= 100000; i++) {
		sequence += to_string(i);

		size_t found = sequence.find(to_string(number));
		if (found != string::npos) {
			position = found + 1;
			break;
		}
	}
	return position;
}
int main() {
	int Number;
	cin >> Number;
	cout << find_position(Number);

	return 0;
}
