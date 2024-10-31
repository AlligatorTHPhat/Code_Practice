#include <iostream>
using namespace std;

template <typename DataType>
void input(DataType& _size, DataType& find, DataType values[])
{
	cin >> _size >> find;
	for (int i = 0; i < _size; i++)
	{
		cin >> values[i];
	}
}

template <typename DataType>
int sequential_find(DataType _size, DataType find, DataType values[], DataType results[])
{
	int res_size = 0;
	for (int i = 0; i < _size; i++)
	{
		if (values[i] == find)
		{
			results[res_size] = i;
			res_size++;
		}
	}
	return res_size;
}

template <typename DataType>
void print_sequential_result(DataType _size, DataType find, DataType values[])
{
	DataType results[100];
	int res_size = sequential_find(_size, find, values, results);

	if (res_size == 0)
		cout << -1;
	else
	{
		for (int i = 0; i < res_size; i++)
			cout << results[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n, x, values[100];
	input<int>(n, x, values);

	print_sequential_result<int>(n, x, values);

	return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// template <typename DataType>
// void input(int& _size, DataType& find, DataType values[])
// {
// 	cin >> _size >> find;
// 	for (int i = 0; i < _size; i++)
// 	{
// 		cin >> values[i];
// 	}
// }

// template <typename DataType>
// vector<DataType> sequential_find(int _size, DataType find, DataType values[])
// {
// 	vector<DataType> result;
// 	for (int i = 0; i < _size; i++)
// 	{
// 		if (values[i] == find)
// 		{
// 			result.push_back(i);
// 		}
// 	}
// 	return result;
// }

// template <typename DataType>
// void print_sequential_result(int _size, DataType find, DataType values[])
// {
// 	vector<DataType> result = sequential_find(_size, find, values);
// 	if (result.empty())
// 		cout << -1;
// 	else
// 	{
// 		for (DataType res : result)
// 			cout << res << " ";
// 	}
// }

// int main()
// {
// 	int n, x, values[100];
// 	input<int>(n, x, values);

// 	print_sequential_result<int>(n, x, values);

// 	return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// vector <int> res;

// void input(int& n, int& x, vector<int>& vec)
// {
// 	cin >> n >> x;

// 	vec.resize(n);

// 	for (int i = 0; i < vec.size(); i++)
// 		cin >> vec[i];

// }

// int sequential_search(int n, int x, vector<int>vec)
// {
// 	int result = -1;
// 	for (int i = 0; i < vec.size(); i++)
// 	{
// 		if (vec[i] == x) { result = i; res.push_back(i); }
// 	}

// 	return result;
// }

// void print_result(int n, int x, vector<int>vec)
// {
// 	sequential_search(n, x, vec);
// 	if (!res.empty())
// 	{
// 		for (auto& r : res)
// 			cout << r << " ";
// 	}
// 	else
// 		cout << -1;
// }

// int main()
// {
// 	int n, x;
// 	vector<int> vec;

// 	input(n, x, vec);
	
// 	print_result(n, x, vec);

// 	return 0;
// }

// 5 3
// 2 1 3 5 3

// 5 10
// 2 1 3 5 7
