#include <iostream>
#include <vector>

using namespace std;

vector<int> r;

void input(int& x, vector<int>& vec)
{
	cin >> x;

	vec.resize(0);

	int n;
	while (cin >> n)
	{
		vec.push_back(n);
	}
}

int sequential_search(int x, vector<int>vec)
{
	int res = -1, max = -10e6;
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] <= x && max < vec[i]) { res = i, max = vec[i]; }

	return res;
}

void print_result(int x, vector<int> vec)
{
	int val = sequential_search(x, vec);
	if (val != -1)
	{
		for (int i = 0; i < vec.size(); i++)
			if(vec[i] == vec[val]) r.push_back(i);
		for (auto v : r) cout << v << " ";
	}
	else cout << -1;
}

int main()
{
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);

	int x;
	vector<int> vec;

	input(x, vec);

	print_result(x, vec);

	return 0;
}


//4
//2 1 3 5 3 1