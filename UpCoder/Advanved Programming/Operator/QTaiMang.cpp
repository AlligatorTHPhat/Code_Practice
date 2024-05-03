#include <iostream>
using namespace std;

struct Array 
{
	int n;
	int arr[100];
	//qua tai = cua Array
	void operator = (Array& a)
	{
		n = a.n;
		for (int i = 0; i < a.n; a)
		{
			arr[i] = a.arr[i];
		}
	}
	//qua tai [] cua Array
	int& operator [] (int i)
	{
		return arr[i];
	}
	//qua tai nhap
	friend istream& operator >> (istream& is, Array& a)
	{
		is >> a.n;
		for (int i = 0; i < a.n; i++)
		{
			is >> a.arr[i];
		}
		return is;
	}
	//qua tai xuat
	friend ostream& operator << (ostream& os, Array a)
	{
		for (int i = 0; i < a.n; i++)
		{
			os << a.arr[i] << " ";
		}
		return os;
	}
    //qua tai cong 2 phan tu mang
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
	//qua tai ==
	bool operator == (Array a)
	{
		if (this->n != a.n) return 0;

		for (int i = 0; i < this->n; i++)
		{
			if (this->arr[i] < a.arr[i])
				return 0;
		}
		return 1;
	}

	bool operator != (Array a)
	{
	    return *this != a;
	}
};

int main()
{
	Array a1, a2;
	cin >> a1 >> a2;
	cout << (a1 == a2 ? "yes" : "no");
	return 0;
}
