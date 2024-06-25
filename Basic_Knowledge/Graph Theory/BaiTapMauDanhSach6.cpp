//Danh Sach Ke --> Danh Sach Canh
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int n;

vector<int> adj[1001];
vector<pair<int, int>> edge;

int values[1001][1001];

int main() {
	cin >> n;

	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s, num;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> num) {
			if (stoi(num) > i) {
				edge.push_back({ i,stoi(num) });
			}
		}
	}

	for (auto it : edge) {
		cout << it.first << " " << it.second << endl;
	}
}

/*
Input :
	5
	2 3 4
	1 3 4 5
	1 2 4 5
	1 2 3 5
	2 3 4
Output :
	1 2
	1 3
	1 4
	2 3
	2 4
	2 5
	3 4
	3 5
	4 5
*/
