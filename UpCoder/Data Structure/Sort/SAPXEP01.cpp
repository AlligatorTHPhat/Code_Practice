//do truyện của anh làm cũng khá dài, nên anh nghĩ là nên làm 1 cái oneshot thử lửa trước rồi mới up truyện gốc

#include <iostream>

using namespace std;

template <typename DataType>
void input(int& n, DataType values[])
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> values[i];
}

template <typename DataType>
void interchange_sort(int n, DataType values[])
{
	int mid = n / 2;
	for (int i = 0; i < mid; i++)
	{
		for (int j = i + 1; j < mid; j++)
		{
			if (values[j] < values[i])
				swap(values[j], values[i]);
		}
	}
}

template <typename DataType>
void reverse_sort(int n, DataType values[])
{
	int mid = (n % 2 == 0) ? n / 2 : n / 2 + 1;
	for (int i = mid; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (values[j] > values[i])
				swap(values[j], values[i]);
		}
	}
}

template <typename DataType>
void print_result(int n, DataType values[])
{
	interchange_sort(n, values);
	reverse_sort(n, values);

	for (int i = 0; i < n; i++)
	{
		cout << values[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	int values[100];

	input(n, values);
	print_result(n, values);

	return 0;
}



// #include <iostream>

// using namespace std;

// int array_size, values[100];

// /*
// void swap(dataptype& a, datatype& b) {
// 		datatype temp = a;
// 		a = b;
// 		b = temp;
// 		return;
// }
// */

// void input(int& array_size, int values[]) {
// 	cin >> array_size;
// 	for (int i = 0; i < array_size; i++) {
// 		cin >> values[i];
// 	} return;
// }

// void Insertion_Sort(int array_size, int values[]) {
// 	int j;
// 	for (int i = 1; i < array_size / 2; i++) {
// 		j = i;
// 		while ((j > 0) && (values[j - 1] > values[j])) {
// 			swap(values[j - 1], values[j]);
// 			j--;
// 		} 
// 	} return;
// }

// void Reverse_Sort(int array_size, int values[]) {
// 	int start = (array_size + 1) / 2, j;
// 	for (int i = start + 1; i < array_size; i++) {
// 		j = i;
// 		while ((j > start) && (values[j - 1] < values[j])) {
// 			swap(values[j - 1], values[j]);
// 			j--;
// 		}
// 	} return;
// }

// void output(int array_size, int values[]) {
// 	for (int i = 0; i < array_size; i++)
// 		cout << values[i] << " ";
// 	return;
// }

// int main() {
// 	input(array_size, values);
// 	Insertion_Sort(array_size, values);
// 	Reverse_Sort(array_size, values);
// 	output(array_size, values);
	
// 	return 0;
// }
