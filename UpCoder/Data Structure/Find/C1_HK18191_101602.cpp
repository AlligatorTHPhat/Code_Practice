#include <iostream>

using namespace std;

void input(int& n, int& x, int values[]) {
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> values[i];
	return;
}

void linear_search(int n ,int x, int values[]) {
	for (int i = n-1; i >= 0; i--) {
		if (values[i] == x) {
			cout << "Y" << endl << i;
			return;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (values[i] > x) {
			cout << "N" << endl << i;
			return;
		}
	}	cout << "N" << endl << -1; return;
}

int main() {
	int n, x;
	int values[100];

	input(n, x, values);

	linear_search(n, x, values);

	return 0;

}
/*
input :
	5 7
	1 6 3 0 2

	5 7 
	1 9 3 8 2
*/

// #include<bits/stdc++.h>

// using namespace std;

// int sequential_search1(int n, int x, int values[])
// {
// 	for (int i = n - 1; i >= 0; i--)
// 	{
// 		if (x == values[i])
// 			return i;
// 	}
// 	return -1;
// }

// int sequential_search2(int n, int x, int values[])
// {
// 	int max = INT_MIN;
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (values[i] > x)
// 			{
// 			    max = i;
// 		        return max;
// 			}
// 	}
//     return INT_MIN;
// }

// int main()
// {
// 	int n, x, values[100];
// 	cin >> n >> x;

// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> values[i];
// 	}

// 	int Y = sequential_search1(n, x, values);
// 	if (Y != -1)
// 	{
// 		cout << "Y" << endl << Y;
// 	}
// 	else
// 	{
// 		int X = sequential_search2(n, x, values);
// 		if (X != INT_MIN)
// 		{
// 			cout << "N" << endl << X;
// 		}
// 		else
// 		{
// 			cout << "N" << endl << -1;
// 		}
// 	}

// }

// // 5 7 
// // 1 6 3 0 2

// // 5 7
// // 1 9 3 8 2
