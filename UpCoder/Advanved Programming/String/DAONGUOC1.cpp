#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Reversed_Num(string num) {
	int res = 0;
	for (int i = num.length() -1; i >= 0; i--) {
		if (num[i] == '-') res = -res;
		else res = res * 10 + (num[i] - '0');
	}
	return res;
}
int main() {
	string max = "-100000";
	string num;

	while (cin >> num) {
		if (Reversed_Num(num) > Reversed_Num(max))
			max = num;
	}
  cout << max; 
  
	return 0;
}
