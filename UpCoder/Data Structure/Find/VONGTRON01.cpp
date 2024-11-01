#include <iostream>

using namespace std;

const int Max_Size = 100;

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
	DataType Front();
	~Queue();
};

template <class DataType>
Queue<DataType>::Queue()
{
	this->_iCapacity = Max_Size;
	_data = new DataType[_iCapacity];
	_iFront = -1;
	_iRear = -1;
}

template <class DataType>
Queue<DataType>::Queue(int size)
{
	this->_iCapacity = size > 0 ? size : Max_Size;
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
		//cout << "Queue da day!\n";
		exit(1);
	}

	if(_iRear == _iCapacity)
	{
		for (int i = _iFront; i < _iCapacity; i++)
		{
			_data[i - 1] = _data[i];
		}
		_iRear--;
		_iFront--;
	}

	_data[++_iRear] = data;

	if (_iFront == -1)
		_iFront = _iRear;
}

template <class DataType>
DataType Queue<DataType>::Pop()
{
	if (IsEmpty())
	{
		//cout << "Queue da rong!\n";
		exit(1);
	}

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
DataType Queue<DataType>::Front()
{
	if (IsEmpty())
	{
		//cout << "Queue da rong!\n";
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
	Queue<int> q;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		q.Push(i);
	}

	while (!q.IsEmpty())
	{
		for (int i = 1; i < k; i++)
		{
			q.Push(q.Front());
			q.Pop();
		}
		cout << q.Front() << " ";
		q.Pop();
	}

	return 0;
}

// #include <iostream>
// #include <queue>

// using namespace std;


// void input(int& n, int& k, queue<int>& que) {
// 	cin >> n >> k;
// 	for (int i = 0; i < n;i++) {
// 		que.push(i);
// 	} return;
// }

// void linear_Search(int n, int k, queue<int> que) {
// 	while (!que.empty()) {
// 		for (int i = 1; i < k; i++) {
// 			que.push(que.front());
// 			que.pop();
// 		}
// 		cout << que.front() << " ";
// 		que.pop();
// 	} return;
// }

// int main() {
// 	int n, k;
// 	queue<int> que;

// 	input(n, k, que);

// 	linear_Search(n, k, que);

// 	return 0;
// }


