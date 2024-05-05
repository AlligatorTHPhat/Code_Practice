#include <iostream>
using namespace std;

struct Fraction {
    int numer, denom;

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    friend istream& operator >> (istream& is, Fraction& f) {
        is >> f.numer >> f.denom;
        return is;
    }

    friend ostream& operator << (ostream& os, Fraction f) {
        int d = f.gcd(f.numer, f.denom);
        f.numer /= d;
        f.denom /= d;

        os << f.numer << "/" << f.denom;
        return os;
    }

    Fraction operator + (Fraction f) {
        Fraction res;
        res.numer = this->numer * f.denom + this->denom * f.numer;
        res.denom = this->denom * f.denom;
        return res;
    }
};

template <typename T>
struct Array {
    int size;
    T* values;

    Array() : size(0), values(new T[100]) {}

    T& operator [] (int index) {
        return this->values[index];
    }
};

int main() {
    Array<int> arr_Int;
    Array<Fraction> arr_Frac;

    char c;
    while (cin >> c) {
        switch (c) {
        case 'a':
            cin >> arr_Int[arr_Int.size];
            arr_Int.size++;
            break;

        case 'b':
            cin >> arr_Frac[arr_Frac.size];
            arr_Frac.size++;
            break;
        }
    }

    if (arr_Int.size == 0) {
        cout << "khong co" << endl;
    }
    else {
        int res = 0;
        for (int i = 0; i < arr_Int.size; i++) {
            res += arr_Int.values[i];
        }
        cout << res << endl;
    }

    if (arr_Frac.size == 0) {
        cout << "khong co" << endl;
    }
    else if (arr_Frac.size == 1) {
        cout << arr_Frac.values[0] << endl;
    }
    else {
        Fraction res = arr_Frac.values[0];
        for (int i = 1; i < arr_Frac.size; i++) {
            res = res + arr_Frac.values[i];
        }
        cout << res << endl;
    }

    return 0;
}
