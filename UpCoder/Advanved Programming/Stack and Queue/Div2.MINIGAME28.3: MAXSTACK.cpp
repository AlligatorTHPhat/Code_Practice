#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int q, n, tmp;
	stack<int> stk, stk_max;

	cin >> q;

	while (q--) {
		cin >> n;

		switch (n) {
			case 1:
				cin >> tmp;
				stk.push(tmp);

				if (stk_max.empty() || stk_max.top() < tmp)
					stk_max.push(tmp);
				else
					stk_max.push(stk_max.top());
				break;
			case 2:
				stk.pop();
				stk_max.pop();
				break;
			case 3:
				cout << stk_max.top() << endl;
				break;
		}
	}

	return 0;
}
