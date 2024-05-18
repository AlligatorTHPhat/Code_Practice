#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, tmp;
	list<int> l;

	cin >> n;
	while (n--) {
		cin >> tmp;
		l.push_back(tmp);
	}

	l.reverse();

	for (int x : l) 
		cout << x << " ";

	return 0;
}
