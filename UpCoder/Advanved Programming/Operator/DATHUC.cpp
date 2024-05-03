#include <iostream>
using namespace std;

struct BacNhat 
{
	int a, b;
	int num;

	friend istream& operator >> (istream& is, BacNhat& B1)
	{
		is >> B1.a >> B1.b;
		return is;
	}

	friend ostream& operator << (ostream& os, BacNhat B1)
	{
		os << B1.a << "x";
		if (B1.b < 0) cout << "-" << B1.b;
		else cout << "+" << B1.b;

		return os;
	}

	int Sum(int num)
	{
		return this->a * num + b;
	}

	BacNhat operator + (BacNhat B1)
	{
		BacNhat res;
		res.a = this->a + B1.a;
		res.b = this->b + B1.b;
		return res;
	}

	bool operator == (BacNhat B1)
	{
		return this->a + this->b == B1.a + B1.b;
	}

	bool operator != (BacNhat B1)
	{
		return (*this) != B1;
	}
};

int main()
{
	BacNhat a,b;
	cin >>a >> b;

	int num;
	cin >> num; 

	cout << a << endl;
	cout << b << endl;
	cout << a << "+" << b << "=" << a + b << endl;
	cout << a.Sum(num) << endl;
	cout << b.Sum(num) << endl;
	cout << (a == b ? "TRUE" : "FALSE");

	return 0;
}
