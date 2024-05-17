#include <iostream>

using namespace std;

char location[100][100];

bool marked[100][100];  //true == da di qua, false == chua di qua

int x_cow, y_cow; //toa do con bo
int x_byre, y_byre; //toa do chuong bo

int n, m; //n dong, m cot

//4 huong di chuyen
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int number_grid_had_come = 0;
int shortest_way; //luu do dai duong di ngan nhat

//xet tai vi tri ( x,y )
void Try(int x, int y);

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> location[i][j];
			if (location[i][j] == 'C') { // toa do xuat phat == toa do con bo
				x_cow = i;
				y_cow = j;
			}
			if (location[i][j] == 'B') { // toa do xuat phat == toa do chuon bo
				x_byre = i;
				y_byre = j;
			}
		}
	}

	//kiem tra du lieu nhap vao
	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			cout << location[i][j] << " ";
		}
		cout << endl;
	}
	*/

	//di tu o xuat phat x_cow, y_cow
	number_grid_had_come = 1;
	marked[x_cow][y_cow] = true;

	shortest_way = n * m; //cho gia tri ban dau cua min la so lon nhat co the co

	Try(x_cow, y_cow); //vi tri xuat phat

	cout << shortest_way - 1;

	return 0;
}

void Try(int x, int y) {
	if (x == x_byre && y == y_byre) {
		if (number_grid_had_come < shortest_way) {
			shortest_way = number_grid_had_come;
		}
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int x_new = x + dx[i];
			int y_new = y + dy[i];
			if (0 <= x_new && x_new < n && 0 <= y_new && y_new < m // nam trong ban do
				&& marked[x_new][y_new] == false && location[x_new][y_new] != '*') {
				
				//thu ?
				marked[x_new][y_new] = true;
				number_grid_had_come++;
				
				Try(x_new, y_new);

				//quay lui
				number_grid_had_come--;
				marked[x_new][y_new] = false;
			}
		}
	}
}
