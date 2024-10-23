#include <iostream>

using namespace std;

template <class DataType>
class Queue;

template <class DataType>
class Node
{
	friend class Queue<DataType>;

private:
	DataType _data;
	Node* _pNext;
public:
	Node(DataType data);
	void Display();
};

template<class DataType>
Node<DataType>::Node(DataType data)
{
	_data = data;
	_pNext = NULL;
}

template<class DataType>
void Node<DataType>::Display()
{
	cout << _data << " ";
}

template<class DataType>
class Queue
{
private:
	Node<DataType>* _pFront;
	Node<DataType>* _pRear;
	int _iSize;
public:
	Queue();
	bool IsEmpty();
	void EnQueue(DataType data);
	DataType DeQueue();
	DataType Peek();
	void Clear();
	void Display();
	int GetSize();
	~Queue();
};

template<class DataType>
Queue<DataType>::Queue()
{
	_pFront = NULL;
	_pRear = NULL;
	_iSize = 0;
}

template<class DataType>
bool Queue<DataType>::IsEmpty()
{
	return _pFront == NULL;
}

template<class DataType>
void Queue<DataType>::EnQueue(DataType data)
{
	Node<DataType>* pNew = new Node<DataType>(data);
	if (pNew == NULL)
		cout << "Khong the chen vao Queue!\n";
	else
	{
		if (_pRear == NULL)
		{
			_pFront = pNew;
			_pRear = pNew;
		}
		else
		{
			_pRear->_pNext = pNew;
			_pRear = pNew;
		}
		_iSize++;
	}
}

template<class DataType>
DataType Queue<DataType>::DeQueue()
{
	if (IsEmpty())
	{
		cout << "Stack rong!\n";
		exit(1);
	}
	Node<DataType>* pTemp = _pFront;
	DataType temp = pTemp->_data;
	_pFront = pTemp->_pNext;
	delete pTemp;
	_iSize--;

	if (_pFront == NULL)
		_pRear = NULL;

	return temp;
}

template<class DataType>
DataType Queue<DataType>::Peek()
{
	if (IsEmpty())
	{
		cout << "Queue Rong!\n";
		exit(1);
	}
	return _pFront->_data;
}

template<class DataType>
void Queue<DataType>::Clear()
{
	Node<DataType>* pTemp;
	while (_pFront != NULL)
	{
		pTemp = _pFront;
		_pFront = pTemp->_pNext;
		delete pTemp;
	}
	_iSize = 0;
	_pRear = NULL;
}

template<class DataType>
void Queue<DataType>::Display()
{
	Node<DataType>* pTemp = _pFront;
	while (pTemp != NULL)
	{
		pTemp->Display(); 
		pTemp = pTemp->_pNext; 
	}
	cout << endl; 
}

template<class DataType>
Queue<DataType>::~Queue()
{
	Clear();
}

void input(string& str)
{
	cin >> str;
}

void Solve(string str)
{
	Queue<char> queue;
	for (char c : str)
	{
		if (c == '*')
		{
			if (queue.IsEmpty())
				continue;
			cout << queue.Peek();
			queue.DeQueue();
		}
		else
		{
			queue.EnQueue(c);
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
