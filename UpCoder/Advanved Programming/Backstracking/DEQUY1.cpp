#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void generate_kary_strings(vector<string>& vec, int k, int n, string prefix)
{
	if (prefix.size() == n)
	{
		vec.push_back(prefix);
		return;
	}

	for (int i = 1; i <= k; ++i)
		generate_kary_strings(vec, k, n, prefix + to_string(i));
}

vector<string> generate_kary_strings(int k, int n)
{
	vector<string> vec;
	generate_kary_strings(vec, k, n, "");
	return vec;
}

int main()
{
	int k, n;
	cin >> k >> n;

	vector<string> kary_strings = generate_kary_strings(k,n);

	sort(kary_strings.begin(), kary_strings.end());
	
	cout << kary_strings.size() << endl;

	for (string& str : kary_strings)
		cout << str << endl;

	return 0;
}
