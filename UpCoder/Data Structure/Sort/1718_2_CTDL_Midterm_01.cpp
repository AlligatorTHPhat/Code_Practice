#include <iostream>

using namespace std;

template <class DataType>
struct Set
{
	int N;
	DataType *data;

	Set(int _N)
	{
		this->N = 0;
		data = new DataType[_N];
	}

	~Set()
	{
		delete[] data;
	}

	bool check(DataType X);
	void push(DataType X);
	void insertion_sort();
	void display();
};

template <class DataType>
bool Set<DataType>::check(DataType X)
{
	for (int i = 0; i < N; i++)
	{
		if (data[i] == X)
		{
			return true;
		}
	}
	return false;
}

template <class DataType>
void Set<DataType>::push(DataType X)
{
	if (!check(X))
	{
		data[N++] = X;
		//this->insertion_sort();
	}
// 	else
// 		cout << "Trung lap gia tri!\n";
}

template <class DataType>
void Set<DataType>::insertion_sort()
{
	for (int i = 0; i < N; i++)
	{
		DataType key = data[i];
		int j = i - 1;

		while (j >= 0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = key;
	}
}

template <class DataType>
void Set<DataType>::display()
{
	for (int i = 0; i < N; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;	
}

int main()
{
	int n, val;

	cin >> n;

	Set<int> set(n);

	while(cin >> val)
		set.push(val);
		
	set.insertion_sort();

    set.display();

	return 0;
}
