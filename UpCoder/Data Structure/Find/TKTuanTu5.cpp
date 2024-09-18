#include <iostream>
#include <vector>

using namespace std;

int n, x, y;
vector<int> vec;

void input(int& n, int& x, int& y, vector<int>& vec)
{
	cin >> n >> x >> y;

	vec.resize(n);

	for (int i = 0; i < vec.size(); i++)
		cin >> vec[i];
}

int sequential_search(int n, int x, int y, vector<int>vec)
{
	int result = -1;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == x) { return i; }
	}

	int a = x, b = x;
	while (a >= x - y && b <= x + y) {
		for (int i = 0; i < n; i++) {
			if (vec[i] == a || vec[i] == b) {
				return i;
			}
		} a--, b++;
	} return - 1;
}

int main()
{
	input(n, x, y, vec);
	cout << sequential_search(n, x, y, vec);

	return 0;
}
