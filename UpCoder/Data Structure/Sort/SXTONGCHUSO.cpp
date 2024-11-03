#include <iostream>

using namespace std;

void input(int& n, int*& values)
{
	cin >> n;
	values = new int[n];

	for (int i = 0; i < n; i++)
		cin >> values[i];
}

bool prime_number(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)return false;
	return n > 1;
}

int sum(int n)
{
	int result = 0;
	while (n)
	{
		result += n % 10;
		n /= 10;
	}
	return result;
}

template <typename DataType>
bool check_sum(DataType a, DataType b)
{
	if (sum(a) < sum(b)) return true;
	if (sum(a) == sum(b)) return a > b;
	return false;
}

template <typename DataType>
void reverse_bubble_sort(DataType n, DataType values[])
{
	for (int i = 0; i < n - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (check_sum(values[j], values[j + 1]))
			{
				swap(values[j], values[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

void output(int n, int values[])
{
	//reverse_bubble_sort(n, values);

	for (int i = 0; i < n; i++)
		if (prime_number(sum(values[i])))
			cout << values[i] << " ";
	cout << endl;

	reverse_bubble_sort(n, values);

	for (int i = 0; i < n; i++)
		cout << values[i] << " ";
}

int main()
{
	int n, * values;

	input(n, values);

	output(n, values);

	return 0;
}
