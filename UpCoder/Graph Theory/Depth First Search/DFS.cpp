#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int Nv, Ne, U;
vector<int> adj[100];
bool visited[1001];

int DFS(int U) {
	cout << U << " ";
	visited[U] = true;

	for (int v : adj[U])
		if (!visited[v])
			DFS(v);
}

int main() {
	cin >> Nv >> Ne >> U;

	for (int i = 0; i < Ne; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	//Set all elements of arr to false
	memset(visited, false, sizeof(visited));
	DFS(U);
}
