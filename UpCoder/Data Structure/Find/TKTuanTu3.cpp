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
int sequential_search(int _size, DataType find, DataType values[])
{
	int max = -1e6, pos = -1;
	for (int i = 0; i < _size; i++)
	{
		if (max < values[i] && values[i] <= find)
		{
			max = values[i], pos = i;
		}
	}
	return pos;
}

template <typename DataType>
void print_sequential_search(int _size, DataType find, DataType values[])
{
	cout << sequential_search(_size, find, values);
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
// 		if (vec[i] <= x && max < vec[i]) { res = i, max = vec[i]; };

// 	return res;
// }

// int main()
// {
// 	ios::sync_with_stdio;
// 	cin.tie(0); cout.tie(0);

// 	int x;
// 	vector<int> vec;

// 	input(x, vec);
// 	cout << sequential_search(x, vec);

// 	return 0;
// }


//4
//2 1 3 5 3 1
