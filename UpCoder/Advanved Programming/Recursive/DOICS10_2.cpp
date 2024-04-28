#include <iostream>
#include <stack>
using namespace std;

int main() {
	int numbers; cin >> numbers;

	stack<int> stk;

	if (numbers == 0) stk.push(0);

	while (numbers > 0) {
		stk.push(numbers % 2);
		numbers /= 2;
	}

	while (!(stk.empty())) {
		cout << stk.top();
		stk.pop();
	}
	return 0;
}
