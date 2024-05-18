#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string str;
	vector<string> vec;
    
    cin >> n;
    
	while (n--) {
		cin >> str;
		if (find(vec.begin(), vec.end(), str) == vec.end()) cout << "OK\n";
		else cout << str << count(vec.begin(), vec.end(), str) << endl;
		vec.push_back(str);
	}
	return 0;
}
