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
void selection_sort(int n, DataType values[])
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (values[min] > values[j])
				swap(values[min], values[j]);
		}
	}
}

template <typename DataType>
void reverse_selection_sort(int n, int mid, DataType values[])
{
	for (int i = mid; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (values[min] < values[j])
				swap(values[min], values[j]);
		}
	}
}

template <typename DataType>
void interchange_sort(int n, DataType values[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (values[i] > values[j])
				swap(values[i], values[j]);
		}
	}
}

template <typename DataType>
void reverse_interchange_sort(int n, int mid, DataType values[])
{
	for (int i = mid; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (values[i] < values[j])
				swap(values[i], values[j]);
		}
	}
}

template <typename DataType>
void bubble_sort(int n, DataType values[])
{
	for (int i = 0; i < n; i++)
	{
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++)
			if (values[j] > values[j + 1])
			{
				swap(values[j], values[j + 1]);
				swapped = true;
			}
		if (swapped == false)
			break;
	}
}

template <typename DataType>
void reverse_bubble_sort(int n, int mid, DataType values[])
{
	for (int i = mid; i < n; i++)
	{
		bool swapped = false;
		for (int j = mid; j < n - (i - mid) - 1; j++)
		
			if (values[j] < values[j + 1])
			{
				swap(values[j], values[j + 1]);
				swapped = true;
			}
		if (swapped == false)
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
void reverse_insertion_sort(int n, int mid, DataType values[]) 
{
	for (int i = mid; i < n; i++)
	{
		DataType key = values[i];
		int j = i - 1;
		while (j >= mid && values[j] < key)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = key;
	}
}

template <typename DataType>
void output(int n, DataType values[])
{
	int mid = (n % 2 == 0) ? n / 2 : (n / 2) + 1;

	//selection_sort(mid, values);
	//reverse_selection_sort(n, mid, values);

	//interchange_sort(mid, values);
	//reverse_interchange_sort(n, mid, values);

	bubble_sort(mid, values);
	reverse_bubble_sort(n, mid, values);

	//insertion_sort(mid, values);
	//reverse_insertion_sort(n, mid, values);

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
