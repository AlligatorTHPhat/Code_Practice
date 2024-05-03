#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;

    friend istream& operator >> (istream& in, Point& other)  {
        in >> other.x >> other.y;
        return in;
    }

    friend ostream& operator << (ostream& out, Point other) {
        out << "(" << other.x << "," << other.y << ")";
    }

    double distance(Point other) {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
    }

    bool operator == (Point other) {
        return this->x == other.x && this->y == other.y;
    }
};

struct Triangle {
    Point a;
    Point b;
    Point c;

    friend istream& operator >> (istream& in, Triangle& other) {
        in >> other.a >> other.b >> other.c;
        return in;
    }

    friend ostream& operator << (ostream& out, Triangle other) {
        out << other.a << other.b << other.c;
        return out;
    }

    double perimeter() {
        return a.distance(b) + b.distance(c) + c.distance(a);
    }

    double operator + (Triangle other) {
        return this->perimeter() + other.perimeter();
    }

    bool operator < (Triangle other) {
        return this->perimeter() < other.perimeter();
    }

    bool operator == (Triangle other) {
        if ((this->a == other.a || this->a == other.b || this->a == other.c) &&
            (this->b == other.b || this->b == other.c || this->b == other.a) &&
            (this->c == other.c || this->c == other.a || this->c == other.b)) return true;
        return false;
    }
};

int main() {
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
