#include <iostream>
#include <istream>
#include <ostream>
#include <math.h>

using namespace std;

struct BACNHAT{
	float a[100];
	int b[100], n;

};

istream& operator >>(istream &is, BACNHAT &bn);
ostream& operator <<(ostream &os, BACNHAT bn);
float Tinh(BACNHAT bn, float x);
BACNHAT daoHam(BACNHAT & bn);
int main()
{
	float x;
	BACNHAT bn;
	cin >> bn;
	cin >> x;
	
	cout << bn << endl;
	
	
	cout << Tinh(bn, x) << endl;
	cout << daoHam(bn);
	//system("pause");
	return 0;
}
istream& operator >>(istream &is, BACNHAT &bn)
{
	is >> bn.n;
	for (int i = 0; i < bn.n; ++i)
	{
		is >> bn.a[i];
	}
	for (int i = 0; i < bn.n; ++i)
	{
		is >> bn.b[i];
	}
	return is;
}
ostream& operator <<(ostream &os, BACNHAT bn)
{
	if (bn.a[0] == 0)
	{
		for (int i = 1; i < bn.n; ++i)
		{
			bn.a[i - 1] = bn.a[i];
			bn.b[i - 1] = bn.b[i];
		}
		bn.n -= 1;

	}
	for (int i = 0; i < bn.n; ++i)
	{
		if (i == 0)
		{
			if (bn.a[i] != 0)
			{
				if (bn.a[i] == 1)
				{
					if (bn.b[i] == 0)
					{
						cout << bn.a[i];
					}
					else
					{
						if (bn.b[i] == 1)
						{
							cout << "x";
						}
						else
						{
							cout << "x^" << bn.b[i];
						}

					}

				}
				else
				{
					if (bn.b[i] == 0)
					{
						cout << bn.a[i];
					}
					else
					{
						if (bn.b[i] == 1)
						{
							cout << bn.a[i] << "x";
						}
						else
						{
							cout << bn.a[i] << "x^" << bn.b[i];
						}

					}
				}

			}
		}
		else
		{
			if (bn.a[i] != 0)
			{
				if (bn.a[i] == 1)
				{
					if (bn.b[i] == 0)
					{
						cout << " + " << bn.a[i];
					}
					else
					{
						if (bn.b[i] == 1)
						{
							cout << " + x";
						}
						else
						{
							cout << " + x^" << bn.b[i];
						}

					}

				}
				else
				{
					if (bn.b[i] == 0)
					{
						cout << " + " << bn.a[i];
					}
					else
					{
						if (bn.b[i] == 1)
						{
							cout << " + " << bn.a[i] << "x";
						}
						else
						{
							cout << " + " << bn.a[i] << "x^" << bn.b[i];
						}

					}

				}
			}
		}
	}

	return os;
}
float Tinh(BACNHAT bn, float x)
{
	float kq = 0;
	for (int i = 0; i < bn.n; ++i)
	{
		kq += bn.a[i] * pow(x, bn.b[i]);
	}
	return kq;
}
BACNHAT daoHam(BACNHAT & bn)
{
	for (int i = 0; i < bn.n; ++i)
	{
		if (bn.b[i] == 0)
		{
			bn.a[i] = 0;
		}
		else
		{
			bn.a[i] *= bn.b[i];
			bn.b[i] -= 1;
		}
	}
	return bn;
}
