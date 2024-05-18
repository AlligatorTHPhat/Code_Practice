#include <bits/stdc++.h>

using namespace std;

int n, res(INT_MIN), sum(0);
int location[100][100];
vector<int> result, path;

int dx[] = { 1,1 };
int dy[] = { 0,1 };

void Try(int x, int y) {
	if (x == n) {
		if (res < sum) {
    	res = sum;
    	result = path;
        }	
	}
	else {
		for (int i = 0; i < 2; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= xx) {
				sum += location[xx][yy];
				path.push_back(location[xx][yy]);

				Try(xx, yy);

				sum -= location[xx][yy];
				path.pop_back();
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> location[i][j];
		}
	}

	sum = location[1][1];
	path.push_back(location[1][1]);

	Try(1, 1);

	for (int x : result) cout << x << " ";
	cout << endl << res;

	return 0;
}
