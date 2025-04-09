#include <iostream>

using namespace std;

void binaryString(int *arr, int i, int n);

int main()
{
	int n; cin >> n;

	int* arr = new int[n + 1];
	binaryString(arr, 1,n);

	return 0;
}

void binaryString(int *arr, int i, int n)
{
	if (i > n)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[j];
		cout << "\n";
		return;
	}

	arr[i] = 0;
	binaryString(arr,i + 1,n);

	arr[i] = 1;
	binaryString(arr,i + 1,n);
}
