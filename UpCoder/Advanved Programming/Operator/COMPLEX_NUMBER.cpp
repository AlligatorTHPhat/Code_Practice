#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Complex_Number {
	int a, b;

	friend istream& operator >> (istream& is, Complex_Number& z) {
		is >> z.a >> z.b;
		return is;
	}

	double Modun() {
		return sqrt(pow(this->a, 2) + pow(this->b, 2));
	}

	Complex_Number operator + (Complex_Number z) {
		Complex_Number res;
		res.a = this->a + z.a;
		res.b = this->b + z.b;
		return res;
	}

	friend ostream& operator << (ostream& os, Complex_Number z) {
		os << "{";
		if (z.a != 0) cout << z.a;
		if (z.b > 0 && z.a != 0) cout << "+" << z.b << "i";
		else if (z.b < 0) cout << z.b << "i";
		else if (z.b == 1 && z.a != 0) cout << "+i";
		else if (z.b == 1 && z.a == 0) cout << "i";
		else if (z.b == -1 && z.a != 0) cout << "-i";
		cout << "}";
		return os;
	}
};

struct Array {
	int size = 0;
	Complex_Number values[100];

	Complex_Number& operator [] (int index) { return values[index]; }

	friend istream& operator >> (istream& is, Array& arr) {
		while (is >> arr.values[arr.size]) arr.size++;
		return is;
	}

	friend ostream& operator << (ostream& os, Array arr) {
		for (int i = 0; i < arr.size; i++) {
			os << arr.values[i] <<  " ";
		}
		cout << endl; 
		for (int i = 0; i < arr.size; i++) {
			os << fixed << setprecision(2) << arr.values[i].Modun() << " ";
		}
		cout << endl; arr.Sum();
		return os;
	}

	void Sum() {
		Complex_Number res = this->values[0];
		for (int i = 1; i < this->size; i++) {
			res = res + this->values[i];
		}
		cout << res;

	}
};

int main() {
	Array a;
	cin >> a;
	cout << a;
}
