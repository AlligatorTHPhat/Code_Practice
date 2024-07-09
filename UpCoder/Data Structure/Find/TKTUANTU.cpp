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

// int linear_search(int size,int values[], int n) {
// 	for (int i = 0; i < size; i++) {
// 		if (values[i] == n)
// 			return i;
// 	} return -1;
// }

// int main() {
// 	int size, values[100], n;
// 	cin >> size >> n;
// 	for (int i = 0; i < size; i++) 
// 		cin >> values[i];

// 	cout << linear_search(size, values, n);
	
// 	return 0;
// }
