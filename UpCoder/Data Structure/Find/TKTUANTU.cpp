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
