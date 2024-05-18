#include <iostream>
#include <string>

using namespace std;

struct Customer {
    string Customer_Number;
    string Customer_Name;
    long long Current_Money;

    friend istream& operator >> (istream& in, Customer& cs) {
        string str;
        int start = 0, end = 0;
        getline(in, str);

        for (end; str[end] != '-'; end++);
        cs.Customer_Number = str.substr(start, end - start - 1);

        start = end + 2;
        for (end++; str[end] != '-'; end++);
        cs.Customer_Name = str.substr(start, end - start - 1);

        start = end + 2;
        cs.Current_Money = stoll(str.substr(start));
    }

    friend ostream& operator << (ostream& out, Customer cs) {
        out << cs.Customer_Number << " - ";
        out << cs.Customer_Name << " - ";
        out << cs.Current_Money;
    }
};

int main() {
    int n, cnt = 0;
    cin >> n;
    cin.ignore();
    Customer arr[n], res;
    for (Customer& x : arr) cin >> x;

    res = arr[0];
    cnt = (arr[0].Current_Money >= 0);

    for (int i = 1; i < n; i++) {
        cnt += (arr[i].Current_Money >= 0);
        if (arr[i].Current_Money > res.Current_Money)
            res = arr[i];
    }

    cout << cnt << endl << res;
    return 0;
}
