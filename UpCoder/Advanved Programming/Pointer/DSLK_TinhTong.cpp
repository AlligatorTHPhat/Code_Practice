#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int *values = new int[n];
  for(int i = 0; i < n; i++)
    cin >> values[i];

  int sum(0);
  for(int i = 0; i < n; i++)
    sum += values[i];

  cout << sum;

  delete[] values;
  return 0;
}
