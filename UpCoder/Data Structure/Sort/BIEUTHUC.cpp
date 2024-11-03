#include <iostream>

using namespace std;

using ll = long long;

void input(ll& n, ll& k, ll*& values)
{
	cin >> n >> k;

	values = new long long[n];

	for (long long i = 0; i < n; i++)
		cin >> values[i];
}

template <typename DataType>
void quick_sort(ll left, ll right, DataType values[])
{
	if (left >= right)
		return;

	ll x = values[(left + right) / 2];
	ll i = left, j = right;

	while (i <= j)
	{
		while (values[i] > x) i++;
		while (values[j] < x) j--;

		if (i <= j)
		{
			swap(values[i], values[j]);
			i++, j--;
		}
	}

	quick_sort(left, j, values);
	quick_sort(i, right, values);
}

void output(ll n, ll k, ll values[])
{
	ll sum = values[0];
	values[0] = 0;

	quick_sort(0, n - 1, values);

	for (ll i = 0; i < n; i++)
	{
		if (i < k)
			sum += values[i];
		else
			sum -= values[i];
	}

	cout << sum;
}

int main()
{
	ll n, k, *values;

	input(n, k, values);
	output(n, k, values);

	delete[] values;

	return 0;
}
