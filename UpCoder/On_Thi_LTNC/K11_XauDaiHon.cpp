#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);

	if (a.size() > b.size()) cout << a;
	else if (b.size() > a.size()) cout << b;
	else cout << "Hai xau dai bang nhau";

  return 0;
}
