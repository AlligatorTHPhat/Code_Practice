#include <iostream>
using namespace std;

void input(int& size, int& target, int values[])
{
	cin >> size >> target;
	for (int i = 0; i < size; i++)
	{
		cin >> values[i];
	}
}

int binary_search(int size, int target, int values[])
{
	int left = 0, right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (values[mid] == target) return mid;
		else if (values[mid] < target) left = mid + 1;
		else if (values[mid] > target) right = mid - 1;
	}
	return -1;
}

int main()
{
	int size, target, values[100];
	input(size, target, values);
	cout << binary_search(size, target, values);

	return 0;
}

// 5 3
// 1 2 3 4 5

// #include <iostream>
// #include <vector>
// using namespace std;

// void input(int& size, int& target, vector<int>& values)
// {
//     cin >> size >> target;
//     values.resize(size);  // Thiết lập kích thước cho vector
//     for (int i = 0; i < size; i++)
//     {
//         cin >> values[i];
//     }
// }

// int binary_search(int size, int target, const vector<int>& values)
// {
//     int left = 0, right = size - 1;
//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         if (values[mid] == target) return mid;
//         else if (values[mid] < target) left = mid + 1;
//         else right = mid - 1;
//     }
//     return -1;
// }

// int main()
// {
//     int size, target;
//     vector<int> values;  // Khai báo vector
//     input(size, target, values);
    
//     // Tìm kiếm nhị phân trong vector
//     int result = binary_search(size, target, values);
//     cout << result << endl;  // In ra vị trí hoặc -1 nếu không tìm thấy

//     return 0;
// }
