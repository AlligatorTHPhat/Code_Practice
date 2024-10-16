#include <iostream>

using namespace std;

template <class DataType>
class Stack;

template <class DataType>
class Node
{
	friend class Stack<DataType>;

private:
	DataType _data;
	Node* _pNext;
public:
	Node(DataType data);
};

//constructor Node
template<class DataType>
Node<DataType>::Node(DataType data)
{
	_data = data;
	_pNext = NULL;
}

template<class DataType>
class Stack
{
private:
	Node<DataType>* _pTop;
	int _iSize;
public:
	Stack();
	bool IsEmpty();
	void Push(DataType data);
	DataType Pop();
	DataType Peek();
	void Clear();
	~Stack();
};

template<class DataType>
Stack<DataType>::Stack()
{
	_pTop = NULL;
	_iSize = 0;
}

template<class DataType>
bool Stack<DataType>::IsEmpty()
{
	return _pTop == NULL;
}

template<class DataType>
void Stack<DataType>::Push(DataType data)
{
	Node<DataType>* pTemp = new Node<DataType>(data);
	pTemp->_pNext = _pTop;
	_pTop = pTemp;
	_iSize++;
}

template<class DataType>
DataType Stack<DataType>::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack rong!\n";
		exit(1);
	}
	Node<DataType>* pTemp = _pTop;
	DataType temp = pTemp->_data;
	_pTop = pTemp->_pNext;
	delete pTemp;
	_iSize--;
	return temp;
}

template<class DataType>
DataType Stack<DataType>::Peek()
{
	if (IsEmpty())
	{
		cout << "Stack Rong!\n";
		exit(1);
	}
	return _pTop->_data;
}

template<class DataType>
void Stack<DataType>::Clear()
{
	Node<DataType>* pTemp;
	while (_pTop != NULL)
	{
		pTemp = _pTop;
		_pTop = pTemp->_pNext;
		delete pTemp;
	}
	_iSize = 0;
}

template<class DataType>
Stack<DataType>::~Stack()
{
	Clear();
}

void input(string& str)
{
	cin >> str;
}

void Solve(string str)
{
	Stack<char> stack;
	for (char c : str)
	{
		if (c == '*')
		{
			if (stack.IsEmpty())
				continue;
			cout << stack.Peek();
			stack.Pop();
		}
		else
		{
			stack.Push(c);
		}
	}
	
}

int main()
{
	string str;

	input(str);

	Solve(str);

	

	return 0;
}
