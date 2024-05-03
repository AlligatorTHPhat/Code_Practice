#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo
{
	int tu, mau;

	friend istream& operator >> (istream& is, PhanSo& ps)
	{
		is >> ps.tu >> ps.mau;
		return is;
	}

	friend ostream& operator << (ostream& os, PhanSo ps)
	{
		ps.RutGon();
		os << ps.tu << "/" << ps.mau;
		return os;
	}

	void RutGon() {
		int d = __gcd(this->tu, this->mau);
		this->tu /= d;
		this->mau /= d;
		return;
	}

	PhanSo operator + (PhanSo ps) {
		PhanSo kq;
		kq.tu = this->tu * ps.mau + this->mau * ps.tu;
		kq.mau = this->mau * ps.mau;
		return kq;
	}

	bool operator == (PhanSo ps) {
		return this->tu * ps.mau == this->mau * ps.tu;
	}
	
	bool operator != (PhanSo ps) {
		return !(*this == ps);
	}

};

int main()
{
	PhanSo a, b;
	cin >> a >> b;
	cout << a + b;
	return 0;
}
