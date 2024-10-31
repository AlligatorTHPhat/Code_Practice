#include <iostream>

using namespace std;

template <typename DataType>
void input(int& _size, DataType& find, DataType values[])
{
	/*cin >> _size >> find;
	for (int i = 0; i < _size; i++)
	{
		cin >> values[i];
	}*/

	cin >> find;

	DataType temp;
	while (cin >> temp)
	{
		values[_size++] = temp;
	}
}

template <typename DataType>
int sequential_search(int _size, DataType find, DataType values[], int result[])
{
	int max = -1e6, pos = 0;

	for (int i = 0; i < _size; i++)
	{
		if (max < values[i] && values[i] <= find)
		{
			max = values[i];
		}
	}

	for (int i = 0; i < _size; i++)
	{
		if (max == values[i])
		{
			result[pos++] = i;
		}
	}

	return pos;
}

template <typename DataType>
void print_sequential_search(int _size, DataType find, DataType values[])
{
	int result[100];
	int pos = sequential_search(_size, find, values, result);
	if (pos == 0)
		cout << -1;
	else
	{
		for (int i = 0; i < pos; i++)
			cout << result[i] << " ";
	}
}

int main()
{
	int n = 0;
	int x, values[100];

	input<int>(n, x, values);

	print_sequential_search<int>(n, x, values);

	return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> r;

// void input(int& x, vector<int>& vec)
// {
// 	cin >> x;

// 	vec.resize(0);

// 	int n;
// 	while (cin >> n)
// 	{
// 		vec.push_back(n);
// 	}
// }

// int sequential_search(int x, vector<int>vec)
// {
// 	int res = -1, max = -10e6;
// 	for (int i = 0; i < vec.size(); i++)
// 		if (vec[i] <= x && max < vec[i]) { res = i, max = vec[i]; }

// 	return res;
// }

// void print_result(int x, vector<int> vec)
// {
// 	int val = sequential_search(x, vec);
// 	if (val != -1)
// 	{
// 		for (int i = 0; i < vec.size(); i++)
// 			if(vec[i] == vec[val]) r.push_back(i);
// 		for (auto v : r) cout << v << " ";
// 	}
// 	else cout << -1;
// }

// int main()
// {
// 	ios::sync_with_stdio;
// 	cin.tie(0); cout.tie(0);

// 	int x;
// 	vector<int> vec;

// 	input(x, vec);

// 	print_result(x, vec);

// 	return 0;
// }


// //4
// //2 1 3 5 3 1
