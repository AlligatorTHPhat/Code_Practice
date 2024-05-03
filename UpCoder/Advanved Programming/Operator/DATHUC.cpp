#include <iostream>
using namespace std;

struct BacNhat
{
	int a, b;

	friend istream& operator >> (istream& is, BacNhat& b1)
	{
		is >> b1.a >> b1.b;
		return is;
	}

	friend ostream& operator << (ostream& os, BacNhat b1)
	{
		os << b1.a << "x+" << b1.b;
		return os;
	}

	int TinhGiaTri(int n)
	{
		int res = this->a * n + this->b;
		return res;
	}
	BacNhat operator + (BacNhat b1)
	{
		BacNhat kq;
		kq.a = this->a + b1.a;
		kq.b = this->b + b1.b;
		return kq;
	}

	bool operator == (BacNhat b1)
	{
		return this->a + this->b == b1.a + b1.b;
	}

	bool operator != (BacNhat b1)
	{
		return !(*this == b1);
	}
};
int main()
{
	int n;
	BacNhat ab1, bb1;
	cin >> ab1 >> bb1 >> n;
	cout << ab1 << endl << bb1 << endl;
	cout << ab1 << "+" << bb1 << "=" << ab1 + bb1 << endl;
	cout << ab1.TinhGiaTri(n) << endl;
	cout << bb1.TinhGiaTri(n) << endl;
	cout << (ab1 == bb1 ? "TRUE" : "FALSE"); \
	return 0;
}
