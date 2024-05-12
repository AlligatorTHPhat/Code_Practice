#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;



int main() {
	ifstream ifile("CONNECT.INP");
	ofstream ofile("CONNECT.OUT");

	vector<int> vec; string res = "";

	int number; ifile >> number;

	while (number--) {
		int n; ifile >> n;
		vec.push_back(n);
	}

	sort(vec.begin(), vec.end(), [](int a, int b) {
		return to_string(a) + to_string(b) > to_string(b) + to_string(a);
		});

	for (int x : vec) 
		res += to_string(x);

	ofile << res;

	ifile.close();
	ofile.close();

	return 0;
}
