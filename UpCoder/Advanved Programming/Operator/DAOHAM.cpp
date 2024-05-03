#include <iostream>
#include <cmath> // Use cmath instead of math.h for C++

using namespace std;

struct Polynomial {
    float coefficients[100];
    int powers[100];
    int size;
};

// Overloaded extraction operator for input
istream& operator>>(istream &is, Polynomial &poly) {
    is >> poly.size;
    for (int i = 0; i < poly.size; ++i) {
        is >> poly.coefficients[i];
    }
    for (int i = 0; i < poly.size; ++i) {
        is >> poly.powers[i];
    }
    return is;
}

// Overloaded insertion operator for output
ostream& operator<<(ostream &os, Polynomial poly) {
    if (poly.coefficients[0] == 0) {
        for (int i = 1; i < poly.size; ++i) {
            poly.coefficients[i - 1] = poly.coefficients[i];
            poly.powers[i - 1] = poly.powers[i];
        }
        poly.size -= 1;
    }
    
    for (int i = 0; i < poly.size; ++i) {
        if (i == 0) {
            if (poly.coefficients[i] != 0) {
                if (poly.coefficients[i] == 1) {
                    if (poly.powers[i] == 0) {
                        cout << poly.coefficients[i];
                    } else {
                        if (poly.powers[i] == 1) {
                            cout << "x";
                        } else {
                            cout << "x^" << poly.powers[i];
                        }
                    }
                } else {
                    if (poly.powers[i] == 0) {
                        cout << poly.coefficients[i];
                    } else {
                        if (poly.powers[i] == 1) {
                            cout << poly.coefficients[i] << "x";
                        } else {
                            cout << poly.coefficients[i] << "x^" << poly.powers[i];
                        }
                    }
                }
            }
        } else {
            if (poly.coefficients[i] != 0) {
                if (poly.coefficients[i] == 1) {
                    if (poly.powers[i] == 0) {
                        cout << " + " << poly.coefficients[i];
                    } else {
                        if (poly.powers[i] == 1) {
                            cout << " + x";
                        } else {
                            cout << " + x^" << poly.powers[i];
                        }
                    }
                } else {
                    if (poly.powers[i] == 0) {
                        cout << " + " << poly.coefficients[i];
                    } else {
                        if (poly.powers[i] == 1) {
                            cout << " + " << poly.coefficients[i] << "x";
                        } else {
                            cout << " + " << poly.coefficients[i] << "x^" << poly.powers[i];
                        }
                    }
                }
            }
        }
    }

    return os;
}

// Function to evaluate the polynomial for a given value of x
float Evaluate(Polynomial poly, float x) {
    float result = 0;
    for (int i = 0; i < poly.size; ++i) {
        result += poly.coefficients[i] * pow(x, poly.powers[i]);
    }
    return result;
}

// Function to compute the derivative of the polynomial
Polynomial Derivative(Polynomial &poly) {
    for (int i = 0; i < poly.size; ++i) {
        if (poly.powers[i] == 0) {
            poly.coefficients[i] = 0;
        } else {
            poly.coefficients[i] *= poly.powers[i];
            poly.powers[i] -= 1;
        }
    }
    return poly;
}

int main() {
    float x;
    Polynomial poly;

    cin >> poly;
    cin >> x;
    
    cout << poly << endl;
    cout << Evaluate(poly, x) << endl;
    cout << Derivative(poly);
    
    return 0;
}
