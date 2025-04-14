#include <iostream>
#include <vector>
#include <algorithm>
//#include <cmath>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	vector<int> computer(n);
	vector<int> buy;

	for (int i = 0; i < n; i++)
		cin >> computer[i];

	for (int i = 0; i < n; i++)
		if (computer[i] < 0)
			buy.push_back(computer[i]);

	sort(buy.begin(), buy.end());

	int sum = 0;
	int max_count = min(m, (int)buy.size());

	for (int i = 0; i < max_count; i++)
		if (!buy.empty())
			sum += -buy[i];

	/*for (int i = 0; i < max_count; i++)
	{
		if (!buy.empty())
			sum += -buy[i];
		else
			sum = 0;
	}*/

	cout << sum;

	return 0;
}
