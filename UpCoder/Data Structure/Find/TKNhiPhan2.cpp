#include <iostream>

using namespace std;

void input(int& n, int& x, int values[])
{
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}
}

int binary_search(int n, int x, int values[])
{
	int left = 0, right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (values[mid] == x) return values[mid];
		else if (values[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

void print_result(int n, int x, int values[])
{
	int result = binary_search(n, x, values);
	if (result != -1)
	{
		for (int i = 0; i < n; i++)
		{
			if (values[i] == result)
				cout << i << " ";
		}
	}
	else
		cout << -1;
	return;
}

int main()
{
	int n, x, values[100];

	input(n, x, values);

	print_result(n, x, values);

	return 0;
}

// #include <iostream>

// using namespace std;

// void input(int& size, int& target, int values[])
// {
// 	cin >> size >> target;
// 	for (int i = 0; i < size; i++)
// 	{
// 		cin >> values[i];
// 	}
// }

// bool check_valid(int size, int values[])
// {
// 	for (int i = 0; i < size; i++)
// 	{
// 		if (values[i] >= values[i - 1])
// 			return true;
// 	}
// 	return false;
// }

// int binary_search(int size, int target, int values[])
// {
// 	int left = 0, right = size - 1;
// 	while (left <= right)
// 	{
// 		int mid = (left + right) / 2;
// 		if (values[mid] == target) return mid;
// 		else if (values[mid] < target) left = mid + 1;
// 		else if (values[mid] > target) right = mid - 1;
// 	}
// 	return -1;
// }

// void print_result(int size, int target, int values[])
// {
// 	int result = binary_search(size, target, values);
// 	if (result != -1)
// 	{
// 		for (int i = 0; i < size; i++)
// 			if (values[i] == target) cout << i << " ";
// 	}
		
// 	else cout << -1;
// }

// int main()
// {
// 	int size, target, values[100];
// 	input(size, target, values);
// 	if (check_valid(size, values))
// 		print_result(size, target, values);
// 	else
// 		cout << "Khong hop le";

// 	return 0;
// }

// // 5 3
// // 1 2 3 3 4
