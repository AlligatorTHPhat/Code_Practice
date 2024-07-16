#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);

	int n, x; 
	cin >> n >> x;

	vector<int> vec(n);

	for (int i = 0; i < vec.size(); i++)
		cin >> vec[i];

    int res = -1;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == x) { res = i; break; }
	}
	
	cout << res;

	return 0;
}

//Other way

// #include <iostream>

// using namespace std;

// void input(int &n, int &x, int values[]) {
// 	cin >> n >> x;
// 	for (int i = 0; i < n; i++)
// 		cin >> values[i];
// }

// void Sequential_Search(int n, int x, int values[]) {
// 	int res = -1;
// 	for (int i = 0; i < n; i++) {
// 		{
// 			if (x == values[i]) {
// 				res = i;
// 				break;
// 			}
// 		}
// 	} cout << res;
// }

// int main() {
// 	int n, x;
// 	int values[100];

// 	input(n, x, values);

// 	Sequential_Search(n, x, values);

// }
