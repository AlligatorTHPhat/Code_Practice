#include <iostream>
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

int main()
{
	Fraction a, b;
	cin >> a >> b;
	cout << a + b;

	return 0;
}
