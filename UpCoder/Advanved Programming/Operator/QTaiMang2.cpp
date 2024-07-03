#include <iostream>

using namespace std;

struct Array {
	int size;
	int values[100];

	friend istream& operator >> (istream& is, Array& arr) {
		is >> arr.size;
		for (int i = 0; i < arr.size; i++)
			is >> arr.values[i];
		return is;
	}

	friend ostream& operator << (ostream& os, Array arr) {
		for (int i = 0; i < arr.size; i++)
			os << arr.values[i] << " ";
		return os;
	}

	int operator [] (int index) { return values[index]; }

	Array operator + (Array arr) {
		Array res;
		res.size = max(this->size, arr.size);

		for (int i = 0; i < res.size; i++) {
			//This checks if the current index i is within the bounds of both arrays (this and arr).
			if (i < this->size && i < arr.size) res.values[i] = this->values[i] + arr.values[i];
			else res.values[i] = (i < this->size ? this->values[i] : arr.values[i]);
		}
		return res;
	}

	bool operator == (Array arr) {
		if (this->size != arr.size) return 0;
		else {
			for (int i = 0; i < this->size; i++) {
				if (this->values[i] != arr.values[i]) return 0;;
			}
		}
		return 1;
	}

	bool operator != (Array arr) {
		return (*(this) != arr);
	}

	bool operator > (Array arr) {
		if (this->size > arr.size) return 1;
		else if (this->size == arr.size) {
			for (int i = 0; i < this->size; i++) {
				if (this->values[i] > arr.values[i]) return 1;
			}
		}
		else return 0;
	}
};
int main() {
	Array a, b;
	cin >> a >> b;
	cout << (a + b);

	return 0;
}
