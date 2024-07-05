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

	Complex_Number operator - (Complex_Number z) {
		Complex_Number res;
		res.a = this->a - z.a;
		res.b = this->b - z.b;
		return res;
	}

	Complex_Number operator * (Complex_Number z) {
		Complex_Number res;
		res.a = this->a * z.a - this->b * z.b;
		res.b = this->a * z.b + this->b * z.a;
		return res;
	}

	friend ostream& operator << (ostream& os, Complex_Number z) {
		if (z.a != 0) os << z.a;
		if (z.b > 0 && z.a != 0) os << "+" << z.b << "*i";
		else if (z.b > 0 && z.a == 0) os << z.b << "*i";
		else if (z.b < 0) os << z.b << "*i";
		else if (z.b == 1 && z.a != 0) os << "+i";
		else if (z.b == 1 && z.a == 0) os << "i";
		else if (z.b == -1 && z.a != 0) os << "-i";
		os << endl;
		return os;
	}

	bool operator < ( Complex_Number& z) {
		if (this->a < z.a) return 1;
		if (this->a == z.a) {
			if (this->b < z.b) return 1;
		}
		return 0;
	}

};

struct Array {
	int size = 0;
	Complex_Number values[100];

	Complex_Number& operator [] (int index) { return values[index]; }

	friend istream& operator >> (istream& is, Array& arr) {
		is >> arr.size;
		for (int i = 0; i < arr.size; i++) {
			is >> arr.values[i];
		}
		return is;
	}

	friend ostream& operator << (ostream& os, Array arr) {
		os << arr.Compare_Max();
		arr.Sum();
		arr.Accumulation();
		arr.Subtract();

		return os;
	}

	void Sum() {
		Complex_Number res = this->values[0];
		for (int i = 1; i < this->size; i++) {
			res = res + this->values[i];
		}
		cout << res;

	}

	void Subtract() {
		cout << Compare_Max() - Compare_Min();
	}

	void Accumulation() {
		Complex_Number res = this->values[0];
		for (int i = 1; i < this->size; i++) {
			res = res * this->values[i];
		}
		cout << res;

	}

	Complex_Number Compare_Max() {
		Complex_Number max = this->values[0];
		for (int i = 1; i < this->size; i++) {
			if (max < this->values[i]) max = this->values[i];
		}
		return max;
	}

	Complex_Number Compare_Min() {
		Complex_Number min = this->values[0];
		for (int i = 1; i < this->size; i++) {
			if (this->values[i] < min ) min = this->values[i];
		}
		return min;
	}
};

int main() {
	Array a;
	cin >> a;
	cout << a;
}
