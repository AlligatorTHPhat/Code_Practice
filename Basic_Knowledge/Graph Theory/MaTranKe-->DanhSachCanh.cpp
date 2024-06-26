//Ma Tran Ke --> Danh Sach Canh
#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> adj[1001];
vector<pair<int, int>> edge;
 
int values[1001][1001];

int main() {
	//Nhap kich thuoc Ma Tran
	cin >> n;
	//Nhap Ma Tran Ke
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> values[i][j];
		}
	}
	//Kiem tra va luu Danh Sach Canh
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (values[i][j] && i < j) { // i < j de tranh danh sach bi lap
				edge.push_back({ i,j });
			}
		}
	}
	//Nhap Danh Sach Canh
	for (auto it : edge) {
		cout << it.first << " " << it.second << endl;
	}
}

/*
Input :
	5
	0 1 1 1 0
	1 0 1 1 1
	1 1 0 1 1
	1 1 0 1 1
	0 1 1 1 0

Output
	1 2
	1 3
	1 4
	2 3
	2 4
	2 5
	3 4
	3 5
	4 5
*/
