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

	bool operator == (Fraction f)
	{
		return this->numer * f.denom == this->denom * f.numer;
	}

};

template <typename T>
void solve()
{
	T a, b;
	cin >> a >> b;
	cout << (a == b ? "true" : "false");

	return;
}

int main()
{
	char c;
	cin >> c;
	
	if (c == 'a') solve<int>();
	else if (c == 'b') solve<float>();
	else if (c == 'c') solve<Fraction>();

	return 0;
}
