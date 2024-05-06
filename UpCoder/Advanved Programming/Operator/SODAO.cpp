#include <iostream>
using namespace std;

struct ReversedNumber {
    int number;

    friend istream& operator >> (istream &in, ReversedNumber &rn) {
        in >> rn.number;
        return in;
    }

    friend ostream& operator << (ostream &out, ReversedNumber rn) {
        out << "[SoDao] " << rn.number;
        return out;
    }

    int reverse() {
        int tmp = this->number;
        int res = 0;
        while (tmp > 0) {
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        return res;
    }

    bool operator > (ReversedNumber rn) {
        return this->reverse() > rn.reverse();
    }

    int operator + (int x) {
        return this->reverse() + x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ReversedNumber a, b;
    cin >> a >> b;

    cout << a << endl;
    cout << b << endl;

    cout << (a > b ? "YES" : "NO") << endl;
    
    int res = a + 0;
    cout << b + res;

    return 0;
}
