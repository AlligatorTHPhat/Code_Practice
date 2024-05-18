#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, tmp;
	list<int> l;

	cin >> n;
	while (n--) {
		cin >> tmp;
		l.push_back(tmp);
	}

	auto it = l.begin();
	advance(it, l.size() / 2);

	while (it != l.end()) {
		cout << *it << " ";
		it++;
	}

	return 0;
}
