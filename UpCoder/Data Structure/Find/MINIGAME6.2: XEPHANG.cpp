#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, maxVal = INT_MIN;
    cin >> n;

    int values[n], exclude[n] = { 1 };
    for (int& val : values) 
        cin >> val;

    for (int i = 1; i < n; i++)
    {
        if (values[i - 1] == values[i])
            exclude[i] = exclude[i - 1] + 1;
        else
            exclude[i] = 1;
    }

    for (int ex : exclude)
        if (maxVal < ex) maxVal = ex;
    cout << n - maxVal;
    return 0;
}
