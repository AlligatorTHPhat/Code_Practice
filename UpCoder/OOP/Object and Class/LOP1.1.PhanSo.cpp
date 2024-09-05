#include <iostream>

using namespace std;

class Fraction {
	int numer, denom;

	friend istream& operator >>(istream& is, Fraction& frac) {
		is >> frac.numer >> frac.denom;
		return is;
	}

	friend ostream& operator <<(ostream& os, Fraction& frac) {
		os << frac.numer << "/" << frac.denom;
		return os;
	}

};
int main() {
	Fraction f;
	cin >> f;
	cout << f;

	return 0;
}
