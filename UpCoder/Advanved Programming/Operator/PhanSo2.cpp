#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo
{
	int tu, mau;
	//qua tai >>
	friend istream& operator >> (istream& is, PhanSo& ps)
	{
		is >> ps.tu >> ps.mau;
		return is;
	}
	//qua tai <<
	friend ostream& operator << (ostream& os, PhanSo ps)
	{
		ps.RutGon();
		os << ps.tu << "/" << ps.mau;
		return os;
	}
	//ham rut gon
	void RutGon()
	{
		int d = __gcd(this->tu, this->mau);
		this->tu /= d;
		this->mau /= d;
		return;
	}
	//qua tai +
	PhanSo operator + (PhanSo ps)
	{
		PhanSo kq;
		kq.tu = this->tu * ps.mau + this->mau * ps.tu;
		kq.mau = this->mau * ps.mau;
		return kq;

	}
	//qua tai ==
	bool operator == (PhanSo ps)
	{
		return this->tu * ps.mau == this->mau * ps.tu;
	}

	bool operator != (PhanSo ps)
	{
		return !(*this == ps);
	}
};

struct Array
{
	int n; 
	PhanSo* arr; // PhanSo arr[100];
	//qua tai >>
	friend istream& operator >> (istream& is, Array& a)
	{
		a.n = 0; a.arr = new PhanSo[100]; // a.arr
		while (is >> a.arr[a.n]) a.n++;
		return is;
	}
	//qua tai <<
	friend ostream& operator << (ostream& os, Array a)
	{
		for (int i = 0; i < a.n; i++)
		{
			os << a.arr[a.n] << " ";
		}
		return os;
	}
	//qua tai []
	PhanSo& operator [] (int i)
	{
		if (i >= 0 && i < this->n)
			return this->arr[i];
	}
};

int main()
{
	Array a; cin >> a;
	PhanSo res = a.arr[0];

	for (int i = 1; i < a.n; i++)
	{
		res = res + a.arr[i];
	}
	cout << res;
	return 0;
}
