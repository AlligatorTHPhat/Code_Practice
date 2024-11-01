#include <iostream>

using namespace std;

const int Max_size = 10e6;

template <class DataType>
struct Queue
{
	int _iCapacity, _iFront, _iRear;
	DataType* _data;

	Queue();
	Queue(int size);
	bool IsEmpty();
	bool IsFull();
	void Push(DataType data);
	DataType Pop();
	DataType Peek();
	~Queue();
};

template <class DataType>
Queue<DataType>::Queue()
{
	this->_iCapacity = Max_size;
	_iFront = -1;
	_iRear = -1;

	_data = new DataType[_iCapacity];
}

template <class DataType>
Queue<DataType>::Queue(int size)
{
	this->_iCapacity = size > 0 ? size : Max_size;
	_data = new DataType[_iCapacity];
	_iFront = -1;
	_iRear = -1;
}

template <class DataType>
bool Queue<DataType>::IsEmpty()
{
	return _iFront == -1;
}

template <class DataType>
bool Queue<DataType>::IsFull()
{
	return _iRear - _iFront == _iCapacity - 1;
}

template <class DataType>
void Queue<DataType>::Push(DataType data)
{
	if (IsFull())
	{
		exit(1);
	}

	if (_iRear == _iCapacity)
	{
		for (int i = _iFront; i < _iCapacity; i++)
		{
			_data[i - 1] = _data[i];
		}
		_iFront--;
		_iRear--;
	}

	_data[++_iRear] = data;

	if (_iFront == -1)
	{
		_iFront = _iRear;
	}
}

template <class DataType>
DataType Queue<DataType>::Pop()
{
	if (IsEmpty())
		exit(1);

	DataType temp = _data[_iFront];
	_iFront++;

	if (_iFront > _iRear)
	{
		_iFront = -1;
		_iRear = -1;
	}
	return temp;
}

template <class DataType>
DataType Queue<DataType>::Peek()
{
	if (IsEmpty())
	{
		exit(1);
	}
	return _data[_iFront];
}

template <class DataType>
Queue<DataType>::~Queue()
{
	delete[] _data;
}

int main()
{
	Queue<int> q1;
	Queue<int> q2;

	int n, k, tmp;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		q1.Push(i);
	}

	while (k--)
	{
		cin >> tmp;
		q2.Push(tmp);
	}

	while(!q1.IsEmpty())
	{
		k = q2.Peek();
		q2.Push(k);
		q2.Pop();

		for (int i = 1; i < k; i++)
		{
			q1.Push(q1.Peek());
			q1.Pop();
		}
		cout << q1.Peek() << " ";
		q1.Pop();
	}

	return 0;
}
