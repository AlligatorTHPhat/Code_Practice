#include <iostream>
#include <string>

using namespace std;

int point_X = 0;
int point_O = 0;

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

void check(string n) {
    if (n == "x") point_X += 1;
    else if (n == "o") point_O += 1;
    else point_X += 1, point_O += 1;
}

int main() {
    string x, o;

    cout << "Select Character: X" << endl;
    getline(cin, x);

    cout << endl;

    cout << "Select Character: O" << endl;
    getline(cin, o);

    string n;
    cout << endl;

    cout << "Strength: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Power: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Speed: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Agility: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Durability: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Endurance: ";
    cin >> n; check(n);
    cout << endl;

    cout << "IQ: ";
    cin >> n; check(n);
    cout << endl;

    cout << "BIQ: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Combat: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Range: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Weapon: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Skill: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Arsenal: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Stamina: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Destructive: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Accuracy: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Offense: ";
    cin >> n; check(n);
    cout << endl;

    cout << "Defense: ";
    cin >> n; check(n);
    cout << endl;

    if (point_X == point_O) {
        cout << "Free Point: ";
        cin >> n; check(n);
        cout << point_X << " / " << point_O << endl;
        if (point_X - point_O == 0) { cout << endl << MAGENTA << "TIE" << RESET << endl; return 0; }
        else {
            cout << (point_X > point_O ? x : o) << endl;
            cout << endl << MAGENTA << "INSANE DIFF" << RESET << endl; return 0;
        }
    }

    cout << point_X << " / " << point_O << endl << endl;

    if (point_X > point_O) cout << x << endl;
    else if (point_X < point_O) cout << o << endl;

    int winner, loser;
    winner = (point_X > point_O ? point_X : point_O);
    loser = (point_X > point_O ? point_O : point_X);
    if (winner - loser < 2) { cout << endl << MAGENTA << "EXTREME DIFF" << RESET << endl; return 0; }

    else if (winner - loser < 4) { cout << endl << RED << "HIGH-EXTREME DIFF" << RESET << endl; return 0; }
    else if (winner - loser < 6) { cout << endl << RED << "HIGH DIFF" << RESET << endl; return 0; }

    else if (winner - loser < 8) { cout << endl << YELLOW << "MID-HIGH DIFF" << RESET << endl; return 0; }
    else if (winner - loser < 10) { cout << endl << YELLOW << "MID DIFF" << RESET << endl; return 0; }

    else if (winner - loser < 12) { cout << endl << GREEN << "LOW-MID DIFF" << RESET << endl; return 0; }
    else if (winner - loser < 14) { cout << endl << GREEN << "LOW DIFF" << RESET << endl; return 0; }

    else if (winner - loser < 16) { cout << endl << BLUE << "NO-LOW DIFF" << RESET << endl; return 0; }
    else if (winner - loser <= 18) { cout << endl << BLUE << "NO DIFF" << RESET << endl; return 0; }

    return 0;
}
