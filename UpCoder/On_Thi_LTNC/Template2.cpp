#include <iostream>

using namespace std;

struct Fraction {
    int numer, denom;

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void Simplified() {
        int d = gcd(this->numer, this->denom);
        this->numer /= d;
        this->denom /= d;
        return;
    }

    friend istream& operator >> (istream& is, Fraction& f) {
        is >> f.numer >> f.denom;
        return is;
    }

    friend ostream& operator << (ostream& os, Fraction f) {
        f.Simplified();
        os << f.numer << "/" << f.denom;
        return os;
    }

    Fraction operator + (Fraction f) {
        Fraction res;
        res.numer = this->numer * f.denom + f.numer * this->denom;
        res.denom = this->denom * f.denom;
        return res;
    }
};

template <typename T>
struct Array {
    int size;
    T values[100];

    friend istream& operator >> (istream& is, Array<T>& arr) {
        arr.size = 0;
        while (is >> arr.values[arr.size]) arr.size++;
        return is;
    }

    T Sum() {
        T res = values[0];
        for (int i = 1; i < size; i++) { 
            res = res + values[i];
        }
        return res; 
    }
};

template <typename T>
void solve() {
    Array<T> arr;
    cin >> arr;
    cout << arr.Sum();

    return;
}

int main() {
    char c;
    cin >> c;

    switch (c) {
        case 'a': 
            solve<int>(); 
            break;
        case 'b': 
            solve<Fraction>(); 
            break;
    }

    return 0;
}
