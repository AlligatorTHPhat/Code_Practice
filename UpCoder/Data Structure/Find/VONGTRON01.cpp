#include <iostream>
#include <queue>

using namespace std;


void input(int& n, int& k, queue<int>& que) {
	cin >> n >> k;
	for (int i = 0; i < n;i++) {
		que.push(i);
	} return;
}

void linear_Search(int n, int k, queue<int> que) {
	while (!que.empty()) {
		for (int i = 1; i < k; i++) {
			que.push(que.front());
			que.pop();
		}
		cout << que.front() << " ";
		que.pop();
	} return;
}

int main() {
	int n, k;
	queue<int> que;

	input(n, k, que);

	linear_Search(n, k, que);

	return 0;
}


