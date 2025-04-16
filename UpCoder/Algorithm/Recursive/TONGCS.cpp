#include <iostream>

using namespace std;

int TONGCS(int n)
{
    if(n < 10) return n;
    return (n % 10) + TONGCS(n / 10);
}

int main()
{
    int n; 
    cin >> n;
    cout << TONGCS(n);
    return 0;
}
