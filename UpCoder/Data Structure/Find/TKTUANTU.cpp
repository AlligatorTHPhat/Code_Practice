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
DataType sequential_find(DataType _size, DataType find, DataType values[])
{
	DataType result = -1;
	for (int i = 0; i < _size; i++)
	{
		if (values[i] == find)
			result = i;
	}
	return result;
}

int main()
{
	int n, x, values[100];
	input<int>(n, x, values);

	cout << sequential_find<int>(n, x, values);

	return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// void input(int& n, int& x, vector<int>& vec)
// {
// 	cin >> n >> x;

// 	for (int i = 0; i < vec.size(); i++)
// 		cin >> vec[i];

// }

// int sequential_search(int n, int x, vector<int>vec)
// {
// 	int result = -1;
// 	for (int i = 0; i < vec.size(); i++)
// 	{
// 		if (vec[i] == x) { result = i; break; }
// 	}

// 	return result;
// }

// int main()
// {
// 	ios::sync_with_stdio;
// 	cin.tie(0); cout.tie(0);

// 	int n, x;
// 	vector<int> vec(n);
// 	input(n, x, vec);
// 	cout << sequential_search(n, x, vec);

// 	return 0;
// }

// 5 3
// 2 1 3 5 3

// 5 10
// 2 1 3 5 7
	
//#include <iostream>
//
//using namespace std;
//
//void input(int& n,int& x, int values[])
//{
//	cin >> n >> x;
//
//	for (int i = 0; i < n; i++)
//		cin >> values[i];
//
//	return;
//}
//
//int sequential_search(int n, int x, int values[])
//{
//	int result = -1;
//	for (int i = 0; i < n; i++)
//	{
//		if (values[i] == x)
//			result = i;
//	}
//	return result;
//}
//
//int main() {
//	int n, x, values[100];
//	input(n, x, values);
//	cout << sequential_search(n, x, values);
//
//	return 0;
//}

