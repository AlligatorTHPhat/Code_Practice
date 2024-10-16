#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

template <class DataType>
class Stack
{
private:
	DataType* _values;
	int _iTop;
	int _iCapacity;

public:
	Stack();
	Stack(int maxSize);
	bool IsEmpty();
	bool IsFull();
	void Push(DataType data);
	DataType Pop();
	~Stack();

};

template <class DataType>
Stack<DataType>::Stack()
{
	_iCapacity = MAX_SIZE;
	_values = new DataType[_iCapacity];
	_iTop = -1;
}

template <class DataType>
Stack<DataType>::Stack(int maxSize)
{
	_iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
	_values = new DataType[_iCapacity];
	_iTop = -1;
}

template <class DataType>
bool Stack<DataType>::IsEmpty()
{
	return (_iTop == -1);
}

template <class DataType>
bool Stack<DataType>::IsFull()
{
	return (_iTop == _iCapacity - 1);

}

template <class DataType>
void Stack<DataType>::Push(DataType data)
{
	if (IsFull())
		cout << "Stack day! Khong the them phan tu!\n";
	else
		_values[++_iTop] = data;
}

template <class DataType>
DataType Stack<DataType>::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack rong!\n";
		exit(1);
	}
	
	DataType temp = _values[_iTop];
	_iTop--;
	return temp;
}

template <class DataType>
Stack<DataType>::~Stack()
{
	delete[] _values;
}




int main()
{
	/*Stack<int> stack(100); 
	stack.Push(10);
	stack.Push(20);
	cout << "Phan tu da xoa: " << stack.Pop() << endl;
	cout << "Phan tu da xoa: " << stack.Pop() << endl;*/

	Stack<int> stk(100);
	
	int n; cin >> n;

	if (n == 0) cout << 0;
	else
	{
		while (n > 0)
		{
			stk.Push(n % 2);
			n /= 2;
		}

		while (!stk.IsEmpty())
		{
			cout << stk.Pop();
		}
	}

	return 0;
}
