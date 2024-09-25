#include <iostream>

using namespace std;

typedef struct Fraction
{
	int numer, denom;
	Fraction* Linked;
};

int main()
{
	/*Fraction* f;
	f = new Fraction;
	f->numer = 5;
	f->denom = 7;

	cout << "Fraction : " << f->numer << "/" << f->denom;
	delete f;*/

	Fraction x, y, z;

	x.numer = 7; x.denom = 5;
	x.Linked = NULL;

	y.numer = 4; y.denom = 9;
	y.Linked = NULL;

	z.numer = 2; z.denom = 6;
	z.Linked = NULL;

	x.Linked = &y;
	y.Linked = &z;

	(x.Linked)->numer = 12;
	(x.Linked)->denom = 23;

	Fraction* f;
	f = &x;

	while (f != NULL)
	{
		cout << f->numer << "/" << f->denom << endl;
		f = f->Linked;
	}

	return 0;
}

