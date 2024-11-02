#include <iostream>

using namespace std;

/*
void swap(dataptype& a, datatype& b) {
		datatype temp = a;
		a = b;
		b = temp;
		return;
}
*/

template <typename DataType>
void input(int& n, DataType values[])
{
	n = 0;

	DataType temp;
	while (cin >> temp)
		values[n++] = temp;
}

template <typename DataType>
void selection_sort(int n, DataType values[])
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (values[min] > values[j])
				swap(values[min], values[j]);
	}
}

template <typename DataType>
void interchange_sort(int n, DataType values[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (values[i] > values[j])
				swap(values[i], values[j]);
	}
}

template <typename DataType>
void bubble_sort(int n, DataType values)
{
	for (int i = 0; i < n; i++)
	{
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++)
			if (values[j] > values[j + 1])
			{
				swap(values[j], values[j + 1]);
				bool swapped = false;
			}
		if (swapped == true)
			break;
	}
}

template <typename DataType>
void insertion_sort(int n, DataType values[])
{
	for (int i = 0; i < n; i++)
	{
		DataType key = values[i];
		
		int j = i - 1;
		while (j >= 0 && values[j] > key)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = key;
	}
}

template <typename DataType>
int partition(int start, int end, DataType values[])
{
	DataType pivot = values[start];

	int count = 0;

	for (int i = start + 1; i <= end; i++)
	{
		if (values[i] <= pivot)
			count++;
	}

	int pivot_index = start + count;

	swap(values[pivot_index], values[start]);

	int i = start, j = end;

	while (i<pivot_index && j >pivot_index)
	{
		while (values[i] < pivot)
			i++;
		while (values[j] > pivot)
			j--;
		if (i < pivot_index && j > pivot_index)
			swap(values[i++], values[j--]);
	}

	return pivot_index;
}

template <typename DataType>
void quick_sort(int left, int right, DataType values[])
{
	if (left < right)
	{
		int pivot = partition(left, right, values);
		quick_sort(left, right - 1, values);
		quick_sort(left + 1, right, values);
	}
}

template <typename DataType>
void output(int n, DataType values)
{
	//selection_sort(n, values);
	//interchange_sort(n, values);
	//bubble_sort(n, values);
	insertion_sort(n, values);
	//quick_sort(n, values);

	for (int i = 0; i < n; i++)
		cout << values[i] << " ";
}

int main()
{
	int n;

	int values[100];

	input(n, values);

	output(n, values);

	return 0;
}
