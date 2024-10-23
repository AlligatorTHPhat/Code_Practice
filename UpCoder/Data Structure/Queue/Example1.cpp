#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

template <class DataType>
class Queue
{
private:
	<DataType>* _values;
	int _iCapacity;
	int _iFront;
	int _iRear;
public:
	Queue();
	Queue(int maxSize);
	bool IsEmpty();
	bool IsFull();
	void enQueue(DataType data);
	DataType deQueue();
	DataType peek();

	~Queue();
};

template <class DataType>
Queue<DataType>::Queue()
{
	_iCapacity = MAX_SIZE;
	_values = new int[_iCapacity];
	_iFront = -1;
	_iRear = -1;
}

template <class DataType>
Queue<DataType>::Queue(int maxSize)
{
	_iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
	_values = new int[_iCapacity];
	_iFront = -1;
	_iRear = -1;
}

template <class DataType>
bool Queue<DataType>::IsEmpty()
{
	return (_iFront == -1);

}

template <class DataType>
bool Queue<DataType>::IsFull()
{
	return (_iRear - _iFront == _iCapacity -1);
}

template <class DataType>
void Queue<DataType>::enQueue(DataType data)
{
	if (IsFull())
	{
		cout << "Queue da day!\n";
		exit(1);
	}

	if (_iRear == _iCapacity - 1)
	{
		for (int i = _iFront; i < _iCapactiy; i++)
		{
			_values[i - 1] = values[i];
		}

		_iRear--;
		_iFront--;
	}
	_values[++_iRear] = data;
	if (_iFront == -1)
		_iFront = _iRear;

	return;
}

template <class DataType>
DataType Queue<DataType>::deQueue()
{
	if (IsEmpty())
	{
		cout << "Queue da rong!\n";
		exit(1);
	}
	DataType temp = _values[_iFront];
	_iFront++;
	if (_iFront > _iRear)
	{
		_iFront = -1;
		_iRear = -1;
	}
	return temp;
}

template <class DataType>
DataType Queue<DataType>::peek()
{
	if (IsEmpty())
	{
		cout << "Queue da rong!\n";
		exit(1);
	}
	
	return _values[_iFront];
}

template <class DataType>
Queue<DataType>::~Queue()
{

}

int main()
{
	return 0;
}
