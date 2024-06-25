//Chuyen doi Danh Sach Canh (vo huong) thanh Ma Tran Ke
#include <iostream>

using namespace std;

int n, m;
int values[1001][1001];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		values[x][y] = values[y][x] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << values[i][j] << " ";
		} cout << endl;
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
	0 1 1 1 0
	1 0 1 1 1
	1 1 0 0 1
	1 1 0 0 1
	0 1 1 1 0
*/
