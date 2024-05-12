#include <iostream>
#include <string>
using namespace std;

int main() {
	string X, Y;
	int count = 0, j = 0;

	getline(cin, X); getline(cin, Y);

	for (int i = 0; i < X.length(); i++) {
		while (X[i] != Y[j]) { j++; count++; };
		if (j > Y.length()) break;
		j++;
	}
	
	cout << (j > Y.length() ? "NO" : "YES");
	if (!(j > Y.length())) cout << endl << count;
}
