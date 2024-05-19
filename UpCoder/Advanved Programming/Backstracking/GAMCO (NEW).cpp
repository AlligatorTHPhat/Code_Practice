#include <bits/stdc++.h>

using namespace std;

int n, m, cnt(0), MIN(INT_MAX);
int x_C, y_C, x_B, y_B;
char location[100][100];

int dx[]{ -1,1,0,0};
int dy[]{ 0,0,1,-1 };

void Try(int x, int y) {
	if (x == x_C && y == y_C) {
		if (cnt < MIN) MIN = cnt;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && location[xx][yy] != '*') {
				char tmp = location[xx][yy];
				location[xx][yy] = '*';
				cnt++;
				
				Try(xx, yy);

				location[xx][yy] = tmp;
				cnt--;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> location[i][j];
		    			
			if (location[i][j] == 'C') x_C = i, y_C = j;
			if (location[i][j] == 'B') x_B = i, y_B = j;
		}
	}

	Try(x_B, y_B);
	cout << MIN;
	return 0;
}
