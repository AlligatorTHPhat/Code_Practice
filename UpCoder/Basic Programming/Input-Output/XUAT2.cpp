#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j;
		}
		cout << endl;
	}

	return 0;
}

/*
#include <iostream>
using namespace std;

int main() {
	cout << 1 << endl;
 cout<< 12 << endl;
 cout << 123 << endl;
 cout << 1234 << endl;
 cout << 12345;
	return 0;
}
*/
