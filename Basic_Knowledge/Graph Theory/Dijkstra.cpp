#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;

const int max_Nv = 1000001;

int Nv, Ne, S;
vector<pair<int, int>> adj[max_Nv];

void input_Dijkstra() {
	cin >> Nv >> Ne >> S;
	for (int i = 0; i < Ne; i++) {
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({ y,w });
		//vo huong
		//adj[y].push_back({ x,w });
	}
}

const int INF = 1e9;
void Dijkstra(int S) {
	//Luu khoang cach duong di;
	vector<ll> d(Nv + 1, INF);
	d[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	//{{Khoang cach, dinh}
	Q.push({ 0,S });
	while (!Q.empty()) {
		//Chon ra dinh co khoang cach nho nhat
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int distance = top.first;
		if (distance > d[u]) continue;
		//Relaxation : Cap nhat khoang cach tu S cho den moi dinh ke voi u
		for (auto it : adj[u]) {
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for (int i = 1; i <= Nv; i++) {
		cout << d[i] << " ";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input_Dijkstra();
	Dijkstra(S);

	return 0;
}
