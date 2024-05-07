#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void generated_kary_strings(vector<string>& results, int k, int n,string prefix)
{
	if (prefix.size() == n)
	{
		results.push_back(prefix);
		return;
	}

	for (int i = 1; i <= k; ++i)
		generated_kary_strings(results, k, n, prefix + to_string(i));
}

int main()
{
	int k, n;
	cin >> k >> n;

	vector<string> kary_strings;

	generated_kary_strings(kary_strings, k, n, "");

	sort(kary_strings.begin(), kary_strings.end());
	cout << kary_strings.size() << endl;

	for (const string& str : kary_strings)
		cout << str << endl;

	return 0;
}
