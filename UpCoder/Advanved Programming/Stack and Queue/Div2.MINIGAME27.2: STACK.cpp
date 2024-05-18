#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int q, n, k;
	stack<int> stk;

	cin >> q;

	while (q--) {
		cin >> n;

		switch (n) {
			case 1:
				cin >> k;
				stk.push(k);
				break;
			case 2:
				stk.pop();
				break;
			case 3:
				int tmp = stk.top();
				stk.pop();
				cout << stk.top() << endl;
				stk.push(tmp);
				break;
		}
	}

	return 0;
}
