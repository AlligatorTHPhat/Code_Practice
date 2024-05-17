#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;

    friend istream& operator >> (istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }

    friend ostream& operator << (ostream& os, Point p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }

    bool operator == (Point p) {
        return this->x == p.x && this->y == p.y;
    }

    bool operator < (Point p) {
        if (this->x < p.x) return true;
        else if (this->x == p.x) {
            if (this->y < p.y) return true;
            else return false;
        }
        else return false;
    }

    Point operator + (Point p) {
        Point res;
        res.x = this->x + p.x;
        res.y = this->y + p.y;
        return res;
    }
};

struct Array {
    int size = 0;
    Point* values;

    Point operator [](int i) { return values[i]; }

    friend istream& operator >> (istream& is, Array& arr) {
        arr.values = new Point[100];
        while (is >> arr.values[arr.size])
            arr.size++;
        return is;
    }

    friend ostream& operator << (ostream& os, Array arr) {
        arr.max(); os << endl;
        arr.Sum();
        return os;
    }

    Array operator + (Array arr) {
        Array res;
        res.size = (this->size, arr.size ? this->size : arr.size);
        for (int i = 1; i < res.size; i++) {
            res.values[i] = this->values[i] + arr.values[i];
        }
        return res;
    }

    void Sum() {
        Point res = this->values[0];
        for (int i = 1; i < this->size; i++) {
            res = res + this->values[i];
        }
        cout << res;
    }

    void max() {
        Point max = this->values[0];
        for (int i = 1; i < this->size; i++) {
            if (max < this->values[i]) max = this->values[i];
        }
        cout << max;
    }
};

int main() {
    Array a;
    cin >> a;
    cout << a;
}
