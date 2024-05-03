#include <iostream>
#include <cmath>
using namespace std;

struct Fraction
{
	int numer, denom;

	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a % b);
	}

	void Simplifies()
	{
		int d = gcd(this->numer, this->denom);
		this->numer /= d;
		this->denom /= d;
		return;
	}

	friend istream& operator >> (istream& is, Fraction& f)
	{
		is >> f.numer >> f.denom;
		return is;
	}

	friend ostream& operator << (ostream& os, Fraction f)
	{
		f.Simplifies();
		os << f.numer << "/" << f.denom;
		return os;
	}

	Fraction operator + (Fraction f)
	{
		Fraction res;
		res.numer = this->numer * f.denom + this->denom * f.numer;
		res.denom = this->denom * f.denom;
		return res;
	}

	bool operator  == (Fraction f)
	{
		return this->numer * f.denom == this->denom * f.numer;
	}

	bool operator != (Fraction f)
	{
		return ((*this) != f);
	}
};

struct Array
{
	int size = 0;
	Fraction *values;

	Fraction operator [] (int index)
	{ 
		return values[index];
	}

	friend istream& operator >> (istream& is, Array& arr) 
	{
		arr.values = new Fraction[100];
		while (cin >> arr.values[arr.size]) arr.size++;

		return is;
	}

	friend ostream& operator << (ostream& os, Array arr)
	{
		arr.Sum();

		return os;
	}

	void Sum()
	{
		Fraction res = values[0];
		for (int i = 1; i < this->size; i++)
		{
			res = res + values[i];
		}
		cout << res;
	}
};

int main()
{
	Array a;
	cin >> a;
	cout << a;
	

	return 0;
}
