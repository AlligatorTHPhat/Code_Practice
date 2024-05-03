#include<iostream>
using namespace std;

struct PhanSo
{
	int tu, mau;
	//qua tai >>
	friend istream& operator >> (istream& is, PhanSo& ps)
	{
		is >> ps.tu >> ps.mau;
		return is;
	}
	//qua tai <<
	friend ostream& operator << (ostream& os, PhanSo ps)
	{
		os << ps.tu << "/" << ps.mau;
		return os;
	}
	//ham ucln
	int ucln(int a, int b)
	{
		if (b == 0) return a;
		return ucln(b, a % b);
	}
	//ham rut gon PS
	PhanSo RutGonPS(PhanSo& ps)
	{
		int d = ucln(ps.tu, ps.mau);
		ps.tu /= d;
		ps.mau /= d;
		return ps;
	}
	//qua tai !=
	bool operator != (PhanSo ps)
	{
		return this->tu * ps.mau != this->mau * ps.tu;
	}
};

struct HonSo
{
	int n; PhanSo ps;
	//qua tai >>
	friend istream& operator >> (istream& is, HonSo& hs)
	{
		is >> hs.n >> hs.ps;
		return is;
	}
	//qua tai <<
	friend ostream& operator << (ostream& os, HonSo hs)
	{
		os << hs.n << " " << hs.ps;
		return os;
	}
	//chuyen hs -> ps
	PhanSo ChuyenHsPs(HonSo& hs)
	{
		PhanSo ps;
		ps.tu = hs.n * hs.ps.mau + hs.ps.tu; // new tu = n * mau + tu 
		ps.mau = hs.ps.mau; // new mau = mau;
		return ps.RutGonPS(ps);
	}
	//chuyen ps -> hs
	HonSo ChuyenPsHs(PhanSo& ps)
	{
		HonSo hs;
		hs.n = ps.tu / ps.mau; // new n = tu /mau
		hs.ps.tu = ps.tu % ps.mau; // new tu = tu % mau
		hs.ps.mau = ps.mau; // new mau = mau
		return hs;
	}
	//rut gon honso
	HonSo RutGonHS(HonSo& hs)
	{
		int tmpTu = hs.n * hs.ps.mau + hs.ps.tu; //tmp tu = n / mau + tu 
		hs.n = tmpTu / hs.ps.mau; // new n = tmp tu / mau  
		hs.ps.tu = tmpTu % hs.ps.mau; // new tu = tmp tu % mau
		hs.ps.RutGonPS(hs.ps); // new mau = mau
		return hs;
	}
	//tong cac tp
	int TongCacThanhPhanHS()
	{
		return this->n + this->ps.tu + this->ps.mau;
	}
	//qua tai >
	bool operator > (HonSo hs)
	{
		return this->TongCacThanhPhanHS() > hs.TongCacThanhPhanHS();
	}
	//qua tai !=
	bool operator != (HonSo hs)
	{
		return this->n != hs.n || this->ps.tu != hs.ps.tu || this->ps.mau != hs.ps.mau;
	}
};
int main()
{
	HonSo hs1, hs2; PhanSo ps1, ps2; string str;
	cin >> hs1 >> hs2 >> str;

	cout << (hs1 != hs2 ? "TRUE" : "FALSE") << endl;
	cout << (hs1 > hs2 ? "TRUE" : "FALSE") << endl;
	if (str == "true")
	{
		cout << hs1.RutGonHS(hs1) << endl << hs2.RutGonHS(hs2);
	}
	if (str == "false")
	{
		
		cout << hs1.ChuyenHsPs(hs1) << endl;
		cout << hs2.ChuyenHsPs(hs2);
	}
	return 0;
}
