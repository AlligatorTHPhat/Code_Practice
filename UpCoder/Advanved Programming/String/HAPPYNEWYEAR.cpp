#include <iostream>
#include <string>

using namespace std;

long long solve(string str, string sub) {
    long long pos = 0, cnt = 0;

    while ((pos = str.find(sub, pos)) != string::npos) {
        cnt++;
        pos += sub.size();
    }

    return cnt;
}

int main() {
    long long n;
    cin >> n;

    cin.ignore();

    for (long long i = 0; i < n; i++) {
        string message;
        getline(cin, message);

        long long point = solve(message, "Happy new year 2017");
        cout << point << endl;
    }

    return 0;
}
