#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int Ne, Nv, S, T;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void DFS(int U) {
	visited[U] = true;
	for (int v : adj[U]) {
		//ghi nhan Parent cua v la u
		if(!visited[v]) {
			parent[v] = U;
			DFS(v);
		}
	}
}
void BFS(int S) {
	queue<int> que;
	que.push(S);
	visited[S] = true;

	while (!que.empty()) {
		int q = que.front();
		que.pop();
		for (int x : adj[q]) {
			if (!visited[x]) {
				que.push(x);
				visited[x] = true;
				parent[x] = q;
			}
		}
	}
}

void Path(int S, int T) {
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));

	//DFS(S);
	BFS(S);

	if (!visited[T]) cout << "khong co duong di";
	else {
		//truy vet duong di
		vector<int> path;
		//bat dau tu dinh T
		while (T != S) {
			path.push_back(T);
			//lat nguoc lai
			T = parent[T];
		}
		path.push_back(S);
		reverse(path.begin(), path.end());
		for (int x : path) {
			cout << x << " ";
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

	Path(S, T);

	return 0;
}

/*
input :
	10 8 1 7
	1 2
	2 3
	2 4
	3 6
	3 7
	6 7
	5 8
	8 9
output (DFS) :
	1 2 3 6 7
	   (BFS) : 
	1 2 3 7
*/
