#include <iostream>
using namespace std;

int size_values = 0, values[100];


void linear_search(int size_values, int values[], int x) {
	int res = -1, tmp = -10e6;
	for (int i = 0; i < size_values; i++) {
		if (values[i] <= x && values[i] > tmp) res = i, tmp = values[i];
	} cout << res;
}

int main() {
    int temp, x;
    
	cin >> x;
	
	while(cin >> temp) values[size_values++] = temp;
	linear_search(size_values, values, x);

    return 0;
}
