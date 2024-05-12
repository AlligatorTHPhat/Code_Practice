#include<iostream>
#include<string>

using namespace std;

void generate_Binary(int n, string prefix = "") {
	if (n == 0) cout << prefix << endl;
	else {
		generate_Binary(n - 1, prefix + "0");
		generate_Binary(n - 1, prefix + "1");
	}
}
int main() {
	int n; cin >> n;
	generate_Binary(n);
	return 0;
}
