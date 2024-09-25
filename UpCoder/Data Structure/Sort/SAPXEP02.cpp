#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Check_Prime_Number(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

void Input(int& n, vector<int>& prime, vector<int>& values)
{
    cin >> n;
    values.resize(n);  
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
        if (Check_Prime_Number(values[i]))
            prime.push_back(values[i]);
    }
}

void Print_Prime(int n, vector<int>& prime, vector<int>& values)
{
    sort(prime.rbegin(), prime.rend());  

    int Prime_index = 0;
    for (int i = 0; i < n; i++)
        if (Check_Prime_Number(values[i]))
            values[i] = prime[Prime_index++]; 
}

void Output(int n, vector<int>& prime, vector<int>& values)
{
    Print_Prime(n, prime, values);  
    for (int i = 0; i < n; i++)
        cout << values[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    vector<int> values;
    vector<int> prime;

    Input(n, prime, values);  
    Output(n, prime, values);

    return 0;
}
