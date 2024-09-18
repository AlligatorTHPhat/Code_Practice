#include <iostream>
#include <vector>

using namespace std;

vector <int> res;

void input(int& n, int& x, vector<int>& vec)
{
	cin >> n >> x;

	vec.resize(n);

	for (int i = 0; i < vec.size(); i++)
		cin >> vec[i];

}

int sequential_search(int n, int x, vector<int>vec)
{
	int result = -1;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == x) { result = i; res.push_back(i); }
	}

	return result;
}

void print_result(int n, int x, vector<int>vec)
{
	sequential_search(n, x, vec);
	if (!res.empty())
	{
		for (auto& r : res)
			cout << r << " ";
	}
	else
		cout << -1;
}

int main()
{
	int n, x;
	vector<int> vec;

	input(n, x, vec);
	
	print_result(n, x, vec);

	return 0;
}
