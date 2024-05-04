#include <iostream>

using namespace std;

struct Fraction
{
	int numer, denom;

	friend istream& operator >> (istream& is, Fraction& f)
	{
		is >> f.numer >> f.denom;

		return is;
	}

	friend ostream& operator << (ostream& os, Fraction f)
	{
		os << f.numer << "/" << f.denom;

		return os;
	}

	Fraction operator ++ ()
	{
		this->numer += 1;
		return (*this);
	}

	Fraction operator ++ (int)
	{
		Fraction temp = *this;
		this->numer += 1;
		return temp;
	}

	Fraction operator -- ()
	{
		this->numer -= 1;
		return (*this);
	}

	Fraction operator - (int)
	{
		Fraction temp = *this;
		this->numer -= 1;
		return temp;
	}
};
int main()
{
	Fraction f;
	cin >> f; 
	cout << f;

	string str; 
	cin  >> str;

	if (str == "++") cout << endl << ++f;
	else if (str == "--") cout << endl << --f;

	return 0;

}
