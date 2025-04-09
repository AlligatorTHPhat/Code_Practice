#include <iostream>

using namespace std;

int sum = 0;

int TONGCS(int i)
{
	if (i <= 0)
		return 0;

	return i % 10 + TONGCS(i / 10);
}

int main()
{
	int n; cin >> n;
	
	cout << TONGCS(n);

	return 0;
}
