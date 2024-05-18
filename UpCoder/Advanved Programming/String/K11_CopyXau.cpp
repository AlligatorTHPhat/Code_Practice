#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	int n, m;
	cin >> n >> m;

	if (n > str.length() - 1|| m > str.length() - 1) cout << "gioi han khong dung";
	else 
		for (int i = n; i <= m; i++)
			cout << str[i];
}
