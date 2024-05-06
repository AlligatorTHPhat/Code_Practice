#include <iostream>
#include <cmath>
#include <string>
#include <algorithm> // for std::swap
using namespace std;

struct KG2C {
    int x, y;

    friend istream& operator>>(istream& is, KG2C& point) {
        is >> point.x >> point.y;
        return is;
    }
    friend ostream& operator<<(ostream& os, const KG2C& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    double operator-(const KG2C& a) const {
        return hypot(a.x - x, a.y - y);
    }

    bool operator<(const KG2C& a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
};

struct KG3C {
    int x, y, z;

    friend istream& operator>>(istream& is, KG3C& point) {
        is >> point.x >> point.y >> point.z;
        return is;
    }
    friend ostream& operator<<(ostream& os, const KG3C& point) {
        os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
        return os;
    }

    double operator-(const KG3C& a) const {
        return hypot(hypot(a.x - x, a.y - y), a.z - z);
    }

    bool operator<(const KG3C& a) const {
        return x == a.x ? (y == a.y ? z < a.z : y < a.y) : x < a.x;
    }
};

template <typename T, int maxSize>
struct Array {
    int size = 0;
    T values[maxSize];

    T& operator[](int index) {
        return values[index];
    }

    friend istream& operator>>(istream& is, Array& arr) {
        if (arr.size < maxSize) {
            is >> arr.values[arr.size++];
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Array& arr) {
        for (int i = 0; i < arr.size; i++) {
            os << arr.values[i] << " ";
        }
        return os;
    }

    double MaxRange() const {
        double result = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                double dist = values[i] - values[j];
                if (result < dist)
                    result = dist;
            }
        }
        return result;
    }

    void SortMax() {
        sort(values, values + size);
    }

    void SortMin() {
        sort(values, values + size, [](const T& a, const T& b) { return b < a; });
    }
};

int main() {
    string str;
    Array<KG2C, 100> arr2;
    Array<KG3C, 100> arr3;
    while (cin >> str) {
        if (str == "Oxy")
            cin >> arr2;
        else if (str == "Oxyz")
            cin >> arr3;
    }

    arr2.SortMax();
    cout << arr2 << "\n";
    arr3.SortMin();
    cout << arr3 << "\n";

    cout << round(arr2.MaxRange() * 1000) / 1000 << "\n";
    cout << round(arr3.MaxRange() * 1000) / 1000 << "\n";

    return 0;
}
