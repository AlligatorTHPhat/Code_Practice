#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int Nv, Ne, S, T;
int cnt[1001];
vector<int> adj[1001];
bool visited[1001];


void BFS(int S) {
	queue<int> que;
	que.push(S);
	visited[S] = true;
	cnt[S] = 0;
	
	while (!que.empty()) {
		int q = que.front();
		que.pop();
		for (auto x : adj[q]) {
			if (!visited[x]) {
				que.push(x);
				visited[x] = true;
				cnt[x] = cnt[q] + 1;			}		
		}
	}
}

int main() {
	cin >> Nv >> Ne >> S >> T;

	for (int i = 0; i < Ne; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false,sizeof(visited));
	memset(cnt, -1, sizeof(cnt));

	BFS(S);

	cout << cnt[T];
	
	return 0;
}
