#include <iostream>
#include <fstream>
#include <vector>
#define Max 250

using namespace std;

struct Ray {
	int x, y;

	Ray(int x1, int y1) {
		x = x1;
		y = y1;
	}
};

ifstream is("RAY.INP");
ofstream os("RAY.OUT");

int m, n;
int a[Max + 1][Max + 1];
int sum = 0, dientich = 0;
vector <Ray> v;
bool visited[Max + 1][Max + 1];

void Try(int i, int j) {
	if (1 <= i && i <= m && 1 <= j && j <= n && a[i][j] == 1) {
		dientich++;
		visited[i][j] = true;
		v.push_back(Ray(i, j));

		if (!visited[i - 1][j])
			Try(i - 1, j);
		if (!visited[i + 1][j])
			Try(i + 1, j);
		if (!visited[i][j - 1])
			Try(i, j - 1);
		if (!visited[i][j + 1])
			Try(i, j + 1);
	}
}

int main() {
	is >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			is >> a[i][j];
			if (a[i][j] == 1)
				sum++;
		}
	}
	os << sum << endl;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && a[i][j] == 1) {
				dientich = 0;

				Try(i, j);

				os << dientich << " ";

				for (int k = 0; k < v.size(); k++) {
					os << "[" << v[k].x << "," << v[k].y << "]";
					if (k < v.size() - 1)
						os << ", ";
				}
				os << endl;
				v.clear();
			}
		}
	}

	is.close();
	os.close();

	return 0;
}
