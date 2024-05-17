#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	cin >> n;

	vector<int> vec(n);
	for (int& x : vec) fin >> x;
	for (int x : vec) fout << x;

	fin.close();
	fout.close();
	
	return 0;
}
