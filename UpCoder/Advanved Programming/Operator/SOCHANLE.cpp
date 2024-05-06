#include <iostream>
#include <string>
using namespace std;

struct SoChanLe
{
	string num; int n;

	int SoLe()
	{
		int sum = 0;
		for (int i = 1; i < this->num.length(); i+=2)
		{
			sum = sum * 10 + (this->num[i] - '0'); // '0' = 48
		}
		return sum;
	}

	int SoChan()
	{
		int sum = 0;
		for (int i = 0; i < this->num.length(); i+=2)
		{
			sum = sum * 10 + (this->num[i] - '0'); // '0' = 48
		}
		return sum;
	}

	friend istream& operator >> (istream& is, SoChanLe& scl)
	{
		is >> scl.num;
		return is;
	}

	friend ostream& operator << (ostream& os, SoChanLe scl)
	{
		cout << scl.SoChan();
		return os;
	}

	int sum(SoChanLe scl, int n = 0)
	{
		int SoChan = 0; int SoLe = 0;
		for (int i = 0; i < scl.num.length(); i++)
		{
			if (i % 2 == 0) SoChan += (scl.num[i] - '0');
			else SoLe += (scl.num[i] - '0');
		}

		if (n == 0) return SoChan;
		else if (n == 1) return SoLe;
	}

	bool operator < (SoChanLe scl)
	{
		return this->SoChan() < scl.SoChan();
	}
		
};
int main()
{
	SoChanLe a, b; int n;
	cin >> a >> b >> n;
	cout << a << endl << b << endl;
	cout << (a < b ? "true" : "false") << endl;
	cout << a.sum(a, n) << endl << b.sum(b, n);
	return 0;
}
