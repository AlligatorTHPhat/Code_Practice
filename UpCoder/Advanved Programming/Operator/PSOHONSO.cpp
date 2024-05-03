#include <iostream>
using namespace std;

struct Fraction
{
    int numer, denom;

    friend istream& operator >> (istream& is, Fraction& f)
    {
        is >> f.numer >> f.denom;
        return is;
    }

    friend ostream& operator << (ostream& os, Fraction f)
    {
        os << f.numer << "/" << f.denom;
        return os;
    }

    int gcd(int a, int b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void Simplified_Frac()
    {
        int d = gcd(numer, denom);
        numer /= d;
        denom /= d;
    }

    bool operator != (Fraction f)
    {
        return this->numer * f.denom != this->denom * f.numer;
    }
};

struct Mixed_Number
{
    int number;
    Fraction frac;

    friend istream& operator >> (istream& is, Mixed_Number& m)
    {
        is >> m.number >> m.frac;
        return is;
    }

    friend ostream& operator << (ostream& os, Mixed_Number m)
    {
        os << m.number << " " << m.frac;
        return os;
    }

    Fraction Trans_Mixed_to_Frac()
    {
        Fraction f;
        f.numer = this->number * this->frac.denom + this->frac.numer;
        f.denom = this->frac.denom;
        f.Simplified_Frac();
        return f;
    }

    Mixed_Number Trans_Frac_to_Mixed()
    {
        Mixed_Number m;
        m.number = this->frac.numer / this->frac.denom;
        m.frac.numer = this->frac.numer % this->frac.denom;
        m.frac.denom = this->frac.denom;
        m.frac.Simplified_Frac();
        return m;
    }

    Mixed_Number Simplified_Mixed()
    {
        Mixed_Number m;
        int temp_Numer = this->number * this->frac.denom + this->frac.numer;
        m.number = temp_Numer / this->frac.denom;
        m.frac.numer = temp_Numer % this->frac.denom;
        m.frac.denom = this->frac.denom;
        m.frac.Simplified_Frac();
        return m;
    }

    bool operator != (Mixed_Number m)
    {
        return this->number != m.number || this->frac != m.frac;
    }

    int tongCacThanhPhan()
    {
        return this->number + this->frac.numer + this->frac.denom;
    }

    bool operator > (Mixed_Number m)
    {
        return this->tongCacThanhPhan() > m.tongCacThanhPhan();
    }
};

int main()
{
    Mixed_Number m1, m2;
    string str;
    cin >> m1 >> m2 >> str;

    cout << (m1 != m2 ? "TRUE" : "FALSE") << endl;
    cout << (m1 > m2 ? "TRUE" : "FALSE") << endl;
    if (str == "true")
    {
        cout << m1.Simplified_Mixed() << endl << m2.Simplified_Mixed();
    }
    if (str == "false")
    {
        cout << m1.Trans_Mixed_to_Frac() << endl;
        cout << m2.Trans_Mixed_to_Frac();
    }
    return 0;
}
