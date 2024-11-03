#include <iostream>

using namespace std;

void input(char& c, int& n, char*& values)
{
	cin >> c >> n;

	values = new char[n];
	for (int i = 0; i < n; i++)
		cin >> values[i];
}

template <typename DataType>
void Insertion_Sort(int n, DataType values[])
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
void reverse_Insertion_Sort(int n, DataType values[])
{
	for (int i = 0; i < n; i++)
	{
		DataType key = values[i];

		int j = i - 1;
		while (j >= 0 && values[j] < key)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = key;
	}
}

void output(char c, int n, char values[])
{
	if (c == 'A')
		Insertion_Sort(n, values);
	else if (c == 'D')
		reverse_Insertion_Sort(n, values);
	else
	{
		cout << "ky tu khong hop le!";
		exit(1);
	}

	for (int i = 0; i < n; i++)
		cout << values[i] << " ";
}

int main()
{
	int n;
	char c, * values = nullptr;

	input(c, n, values);
	output(c, n, values);

	delete[] values;

	return 0;
}
