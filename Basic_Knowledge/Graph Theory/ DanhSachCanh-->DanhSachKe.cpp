//Chuyen doi Danh Sach Canh (vo huong) thanh Danh Sach Ke

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> adj[1001]; //adj[i] : luu danh sach ke cua dinh i
 
int main() {
	//Nhap kich thuoc Ma Tran
	cin >> n >> m;
	//Nhap Danh Sach Canh
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	//Xuat ra Danh Sach Ke
	for (int i = 1; i <= n; i++) {
		cout << i << " : ";
		for (int x : adj[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}
/*
Input :
	5 9
	1 2
	1 3
	1 4
	2 3
	2 4
	2 5
	3 5
	3 5
	4 5

Output :
	1 : 2 3 4
	2 : 1 3 4 5
	3 : 1 2 5 5
	4 : 1 2 5
	5 : 2 3 3 4
*/ 
