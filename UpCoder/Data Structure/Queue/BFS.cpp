#include <iostream>
#include <vector>
#include <algorithm>
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
};

template<class DataType>
Node<DataType>::Node(DataType data)
{
	_data = data;
	_pNext = NULL;
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
	{
		cout << "Khong the chen vao Queue!\n";
	}
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
		cout << "Queue rong!\n";
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
Queue<DataType>::~Queue()
{
	while (!IsEmpty())
	{
		DeQueue();
	}
}

void BFS(int start, const vector<vector<int>>& adjList, vector<bool>& visited)
{
	Queue<int> q;
	q.EnQueue(start);
	visited[start] = true;

	while (!q.IsEmpty())
	{
		int current = q.DeQueue();
		cout << current << " ";

		for (int neighbor : adjList[current])
		{
			if (!visited[neighbor])
			{
				q.EnQueue(neighbor);
				visited[neighbor] = true;
			}
		}
	}
}

int main()
{
	int nV, nE, S;
	cin >> nV >> nE >> S;

	// Khởi tạo danh sách kề với chỉ số từ 1 đến nV
	vector<vector<int>> adjList(nV + 1);
	for (int i = 0; i < nE; i++)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a); // Đồ thị vô hướng
	}

	// Sắp xếp các đỉnh kề theo thứ tự tăng dần
	for (int i = 1; i <= nV; i++)
	{
		sort(adjList[i].begin(), adjList[i].end());
	}

	// Mảng đánh dấu các đỉnh đã được thăm
	vector<bool> visited(nV + 1, false);

	// Duyệt BFS từ đỉnh S
	BFS(S, adjList, visited);

	return 0;
}
