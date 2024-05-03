#include <iostream>
using namespace std;

struct Array
{
	int n;
	int arr[100];

	void operator = (Array& a)
	{
		n = a.n;
		for (int i = 0; i < a.n; i++)
		{
			arr[i] = a.arr[i];
		}
	}

	int& operator [] (int i)
	{
		return arr[i];
	}

	friend istream& operator >> (istream& is, Array& a)
	{
		is >> a.n;
		for (int i = 0; i < a.n; i++)
		{
			is >> a.arr[i];
		}
		return is;
	}

	friend ostream& operator << (ostream& os, Array a)
	{
		for (int i = 0; i < a.n; i++)
		{
			os << a.arr[i] << " ";
		}
		return os;
	}

	Array operator + (Array a)
	{
		Array res;
		res.n = max(this->n, a.n);

		for (int i = 0; i < res.n; i++)
		{
			if (i < this->n && i < a.n)
				res.arr[i] = this->arr[i] + a.arr[i];
			else res.arr[i] = (i < this->n ? this->arr[i] : a.arr[i]);
		}
		return res;
	}
};

int main()
{
	Array a, b;
	cin >> a >> b;
	cout << a + b;
	return 0;
}
