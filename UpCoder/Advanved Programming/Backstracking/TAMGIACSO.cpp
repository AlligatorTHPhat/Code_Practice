#include <iostream>
#include <vector>

using namespace std;

const int Max_N = 100;

int num;
int sum;
int m = 1;
int max_sum = 0;
int result[Max_N];
int save_result[Max_N];
int values[Max_N][Max_N];
int dx[2] = { 1,1 };
int dy[2] = { 0,1 };

void Try(int x, int y) {
	if (x == num - 1) {
		if (sum > max_sum) {
			max_sum = sum;
		for (int i = 0; i < num; ++i)
			save_result[i] = result[i];
		}
	}
	else {
		for (int i = 0; i < 2; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < num && yy >= 0 && yy < num) {
				result[m] = values[xx][yy];
				++m;
				sum += values[xx][yy];
				Try(xx, yy);
				sum -= values[xx][yy];
				--m;
				result[m] = 0;
			}
		}
	}
}
int main()
{
	cin >> num;

	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			cin >> values[i][j];
		}
	}

	result[0] = values[0][0];
	sum = values[0][0];

	Try(0, 0);

	for (int i = 0; i < num; i++) {
		cout << save_result[i] << " ";
	}
	cout << endl;

	cout << max_sum << endl;

	return 0;
}
