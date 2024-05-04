#include <iostream>

using namespace std;

struct Fraction {
    int numer, denom;

    int gcd(int a, int b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void Simplified()
    {
        int d = gcd(this->numer, this->denom);
        this->numer /= d;
        this->denom /= d;
        return;
    }

    friend istream& operator >> (istream& is, Fraction& f)
    {
        is >> f.numer >> f.denom;
        if (f.denom < 0) {
            f.numer = -f.numer;
            f.denom = abs(f.denom);
        }
        return is;
    }

    friend ostream& operator << (ostream& os, Fraction f)
    {
        f.Simplified();
        os << f.numer << "/" << f.denom;
        return os;
    }

    Fraction operator + (Fraction f)
    {
        Fraction res;
        res.numer = this->numer * f.denom + f.numer * this->denom;
        res.denom = this->denom * f.denom;
        return res;
    }

    bool operator > (Fraction f)
    {
        return this->numer * f.denom > this->denom * f.numer;
    }
};

template <typename T>
struct Array {
    int size = 0;
    T values[100];

    T Input() {
        T index;
        cin >> index;
        values[size++] = index;
    }

    T Min() {
        T min = values[0];
        for (int i = 1; i < size; i++) {
            if (min > values[i]) min = values[i];
        }
        return min;
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

    Array<int> arr_Int;
    Array<float> arr_Float;
    Array<Fraction> arr_Frac;

    char c;

    while (cin >> c)
    {
        if (c == 'a') arr_Int.Input();
        if (c == 'b') arr_Float.Input();
        if (c == 'c') arr_Frac.Input();
    }

    if (arr_Int.size > 0) cout << arr_Int.Min() << endl;
    else cout << "khong co" << endl;

    if (arr_Float.size > 0) cout << arr_Float.Min() << endl;
    else cout << "khong co" << endl;

    if (arr_Frac.size > 0) cout << arr_Frac.Min() << endl;
    else cout << "khong co" << endl;

    return 0;
}
