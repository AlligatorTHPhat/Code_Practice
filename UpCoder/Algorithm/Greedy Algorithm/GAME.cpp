#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;

void solve(int n, int m, vector<int>& a, vector<int>& b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int sum_a = 0, sum_b = 0;

	for (int i = 0; i < m; i++)
		sum_a += a[i], sum_b += b[i];

	cout << (sum_a > sum_b ? "YES" : "NO") << endl;

	//sort(a.rbegin(), a.rend());
	//sort(b.rbegin(), b.rend());

	////vector<int> sum_a, sum_b;

	//int sum_a = 0, sum_b = 0;
	//for (int i = 0; i < min(m, (int)a.size()); i++)
	//	sum_a += a[i], sum_b += b[i];

	//cout << (sum_a > sum_b ? "YES" : "NO") << "\n";
}

void GAME()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;

        n >= 0 && n <= 1000;
		vector<int> a(n), b(n);
		for (int j = 0; j < n; j++)
			cin >> a[j];
		for (int j = 0; j < n; j++)
			cin >> b[j];
		solve(n, m, a, b);
	}
}

int main()
{
	GAME();
}
