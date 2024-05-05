#include <iostream>

using namespace std;

template <typename T>
struct M1C
{
	int size;
	T* values;

	M1C() : size(0), values(new int[100]) {}
	void nhap()
	{
		int index;
		while(cin >> index)
			values[size++] = index;
	}

	int tong()
	{
		int res = 0;
		for (int i = 0; i < size; i++)
			res += values[i];
		return res;
	}

	void xuat()
	{
		for (int i = 0; i < size; i++)
		cout << values[i] << " ";
	}
};
int main()
{
	M1C <int> m1c_int;
	m1c_int.nhap();
	cout << m1c_int.tong();
}
