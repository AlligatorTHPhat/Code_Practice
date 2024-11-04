#include <iostream>
#include <string>

using namespace std;

const int Max_size = 100;

template <class DataType>
struct Stack
{
	int _iSize;
	int _iTop;
	DataType* _data;

	void init();
	bool empty();
	bool full();
	void push(DataType data);
	DataType pop();
	DataType top();
};

template <class DataType>
void Stack<DataType>::init()
{
	_iSize = Max_size;
	_iTop = -1;
	_data = new DataType[_iSize];
}

template <class DataType>
bool Stack<DataType>::empty()
{
	return _iTop == -1;
}

template <class DataType>
bool Stack<DataType>::full()
{
	return _iTop == _iSize - 1;
}

template <class DataType>
void Stack<DataType>::push(DataType data)
{
	if (full())
		exit(1);
	_data[++_iTop] = data;
}

template <class DataType>
DataType Stack<DataType>::pop()
{
	if (empty())
		exit(1);

	DataType temp = _data[_iTop];
	_iTop--;

	return temp;
}

template <class DataType>
DataType Stack<DataType>::top()
{
	if (empty())
		exit(1);
	return _data[_iTop];
}

bool operatorCheck(string str)
{
	char c = str[0];
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int calculate(int a, int b, char c)
{
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
	if (c == '/') return a / b;
}

int main()
{
	Stack<int> stack;

	stack.init();

	string str;
	while (cin >> str)
	{
		if (!operatorCheck(str))
			stack.push(stoi(str));
		else
		{
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();

			stack.push(calculate(a, b, str[0]));
		}
	}

	cout << stack.top();

	return 0;
}
