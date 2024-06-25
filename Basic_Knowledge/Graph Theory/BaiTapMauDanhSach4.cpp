//Ma Tran Ke --> Danh Sach Ke
#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> adj[1001];
vector<pair<int, int>> edge;
 
int values[1001][1001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> values[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (values[i][j]) { 
				adj[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= n;i++) {
		cout << i << " : ";
		for (auto x : adj[i]) {
			cout << x << " ";
		} cout << endl;
	}
}
  
/*
Input :
	5
	0 1 1 1 0
	1 0 1 1 1
	1 1 0 1 1
	1 1 1 0 1
	0 1 1 1 0

Output
	1 : 2 3 4
	2 : 1 3 4 5
	3 : 1 2 4 5
	4 : 1 2 3 5
	5 : 2 3 4
*/
