//Danh Sach Ke --> Ma Tran Ke
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
	//Nhap kich thuoc Ma Tran
	cin >> n;

	cin.ignore();
	//Nhap Danh Sach Ke
	for (int i = 1; i <= n; i++) {
		string s, num;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> num) {
			values[i][stoi(num)] = 1;
		}
	}
	//Xuar ra Ma Tran Ke
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << values[i][j] << " ";
		} cout << endl;
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
	0 1 1 1 0
	1 0 1 1 1
	1 1 0 1 1
	1 1 1 0 1
	0 1 1 1 0
*/
