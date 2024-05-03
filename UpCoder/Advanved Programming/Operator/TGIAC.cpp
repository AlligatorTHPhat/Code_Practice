#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point
{
	int x, y;

	friend istream& operator >> (istream& is, Point& O)
	{
		is >> O.x >> O.y;

		return is;
	}

	friend ostream& operator << (ostream& os, Point O)
	{
		os << "(" << O.x << "," << O.y << ")";

		return os;
	}

	double distance(Point O)
	{
		return sqrt(pow(this->x - O.x, 2) + pow(this->y - O.y,2));
	}

	bool operator == (Point O)
	{
		return (this->x == O.x && this->y == O.y);
	}

};

struct Triangle
{
	Point a, b, c;

	friend istream& operator >> (istream& is, Triangle& T)
	{
		is >> T.a >> T.b >> T.c;

		return is;
	}

	friend ostream& operator << (ostream& os, Triangle  T)
	{
		os << T.a << T.b << T.c;

		return os;
	}

	double Perimeter()
	{
		return a.distance(b)+ b.distance(c) + c.distance(a);
	}

	double operator + (Triangle T)
	{
		return this->Perimeter() + T.Perimeter();
	}

	bool operator < (Triangle T)
	{
		return this->Perimeter() < T.Perimeter();
	}

	bool operator == (Triangle T)
	{
		if ((this->a == T.a || this->a == T.b || this->a == T.c) &&
			(this->b == T.a || this->b == T.b || this->b == T.c) &&
			(this->c == T.a || this->c == T.b || this->c == T.c)) return 1;
	}
};
int main()
{
	Triangle a, b;
	cin >> a >> b;

	cout << a << endl;
	cout << b << endl;

	if (a < b) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;

	if (a == b) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;

	return 0;
}
