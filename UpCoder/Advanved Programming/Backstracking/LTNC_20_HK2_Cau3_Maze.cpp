#include <bits/stdc++.h>

using namespace std;

struct Point {
	int first, second;
	Point(int a, int b) : first(a), second(b) {};
};

int n, m, MIN(INT_MAX);
int x_A, y_A, x_B, y_B;
char location[100][100];
vector<Point> result, path;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Try(int x, int y) {
	if (x == x_B && y == y_B) {
		if (path.size() < MIN) {
			MIN = path.size();
			result = path;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && location[xx][yy] != '*') {
				char tmp = location[xx][yy];

				location[xx][yy] = '*';
				path.push_back({ xx,yy });

				Try(xx, yy);

				location[xx][yy] = tmp;
				path.pop_back();
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> location[i][j];
			if (location[i][j] == 'A') x_A = i, y_A = j;
			if (location[i][j] == 'B') x_B = i, y_B = j;
		}
	}

	path.push_back({ x_A,y_A });

	Try(x_A, y_A);

	cout << MIN << endl;
	for (auto p : result)
		cout << "(" << p.first << "," << p.second << ") ";

	return 0;
}
