#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int Nv, Ne, U;
vector<int> adj[1001];
bool visited[1001];

void BFS(int U) {
	queue<int> que;
	que.push(U);
	visited[U] = true;

	while (!que.empty()) {
		int q = que.front();
		que.pop();

		cout << q << " ";

		for (auto x : adj[q]) {
			if (!visited[x]) {
				que.push(x);
				visited[x] = true;
			}
		}
	}
}
int main() {
	cin >> Nv >> Ne >> U;

	for (int i = 1; i <= Ne; i++) {
		int x, y; i; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	memset(visited, false, sizeof(visited));

	BFS(U);
}
