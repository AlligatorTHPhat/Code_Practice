#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int Reverse(string num) {
	int res = 0;
	for (int i = num.length() - 1; i >= 0; i--) {
		if (num[i] == '-') res = -res;
		else res = res * 10 + num[i] - '0';
	}
	return res;
}

int main() {

	ifstream ifile; ifile.open("inDaoNguoc2.txt");
	ofstream ofile; ofile.open("outDaoNguoc2.txt");

	string max = "-100000";
	string num; int index = 0;
	vector <int> vec;

	while (ifile >> num) {
		if (Reverse(max) < Reverse(num)) {
			max = num;
			vec.clear();
			vec.push_back(index);
		}
		else if (Reverse(max) == Reverse(num)) {
			vec.push_back(index);
		}
		index++;
	}
	ofile << max << endl;
	if (vec.size() > 1)
		for (int x : vec) ofile << x << " ";
	ifile.close(); ofile.close();
	return 0;
}
