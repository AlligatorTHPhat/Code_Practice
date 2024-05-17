#include <iostream>
#include <vector>

#define Max 250

using namespace std;

struct Ray {
	int x, y;

	Ray(int xx, int yy) {
		x = xx;
		y = yy;
	}
};

int m, n;
int location[Max + 1][Max + 1];
int sum = 0, area = 0;
vector<Ray> vec;
bool visited[Max + 1][Max + 1];

void Try(int i, int j);

int main() {
	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> location[i][j];
			if (location[i][j] == 1)
				sum++;
		}
	}
	cout << sum << endl;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && location[i][j] == 1) {
				area = 0;

				Try(i, j);

				cout << area << " ";

				for (int k = 0; k < vec.size(); k++) {
					cout << "[" << vec[k].x << "," << vec[k].y << "]";
					if (k < vec.size() - 1)
						cout << ", ";
				}
				cout << endl;
				vec.clear();
			}
		}
	}

	return 0;
} 

void Try(int i, int j) {
	if (1 <= i && i <= m && 1 <= j && j <= n && location[i][j] == 1) {
		area++;
		visited[i][j] = true;
		vec.push_back(Ray(i, j));

		if (!visited[i - 1][j]) Try(i - 1, j);
		if (!visited[i + 1][j]) Try(i + 1, j);
		if (!visited[i][j - 1]) Try(i, j - 1);
		if (!visited[i][j + 1]) Try(i, j + 1);
	}
}
