#include <iostream>

using namespace std;

int Catalan(int number) {
	if (number <= 1) return 1;

	int res = 0;
	for (int i = 0; i < number; i++)
		res += Catalan(i) * Catalan(number - i - 1);
	return res;
}

int main() {
	int number;
	while(cin >> number) {
	    cout << Catalan(number)<< endl;
	}
	return 0;
}
