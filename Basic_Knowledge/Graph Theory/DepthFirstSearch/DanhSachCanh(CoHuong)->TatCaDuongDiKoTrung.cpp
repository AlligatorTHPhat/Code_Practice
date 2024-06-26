//Danh Sach Canh (Co Huong) -> Tat Ca Duong Di Ko Trung
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		//adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u) {
	cout << u << " ";

	//Danh dau la u da dc tham
	visited[u] = true;
	for (int v : adj[u]) {
		//Neu V chua duoc tham
		if (!visited[v]){
			dfs(v);
			}
	}
}
int main() {
	input();
	dfs(1);
}

/*
input :
	9 10
	1 2
	1 3
	1 5
	2 4
	3 6
	3 7
	5 8
	6 7
	8 9
	9 3
output : 
	1 2 4 3 6 7 5 8 9
*/
