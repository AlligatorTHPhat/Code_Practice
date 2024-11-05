#include <iostream>
using namespace std;

template <class DataType>
class PriorityQueue;

template <class DataType>
class PriorityNode
{
    friend class PriorityQueue<DataType>;

private:
    DataType _data;
    int _priority;
    PriorityNode* _pNext;

public:
    PriorityNode(DataType data, int priority);
    void Display();
};

template <class DataType>
PriorityNode<DataType>::PriorityNode(DataType data, int priority)
{
    _data = data;
    _priority = priority;
    _pNext = NULL;
}

template <class DataType>
void PriorityNode<DataType>::Display()
{
    cout << "(" << _data << ", Priority: " << _priority << ") ";
}

template <class DataType>
class PriorityQueue
{
private:
    PriorityNode<DataType>* _pFront;
    int _iSize;

public:
    PriorityQueue();
    bool IsEmpty();
    void EnQueue(DataType data, int priority);
    DataType DeQueue();
    DataType Peek();
    DataType Back();
    void Clear();
    void Display();
    int GetSize();
    ~PriorityQueue();
};

template <class DataType>
PriorityQueue<DataType>::PriorityQueue()
{
    _pFront = NULL;
    _iSize = 0;
}

template <class DataType>
bool PriorityQueue<DataType>::IsEmpty()
{
    return _pFront == NULL;
}

template <class DataType>
void PriorityQueue<DataType>::EnQueue(DataType data, int priority)
{
    PriorityNode<DataType>* pNew = new PriorityNode<DataType>(data, priority);
    if (pNew == NULL)
    {
        cout << "Không thể chèn vào hàng đợi!\n";
        return;
    }

    if (_pFront == NULL || _pFront->_priority < priority)
    {
        pNew->_pNext = _pFront;
        _pFront = pNew;
    }
    else
    {
        PriorityNode<DataType>* pTemp = _pFront;
        while (pTemp->_pNext != NULL && pTemp->_pNext->_priority >= priority)
        {
            pTemp = pTemp->_pNext;
        }
        pNew->_pNext = pTemp->_pNext;
        pTemp->_pNext = pNew;
    }
    _iSize++;
}

template <class DataType>
DataType PriorityQueue<DataType>::DeQueue()
{
    if (IsEmpty())
    {
        cout << "Hàng đợi rỗng!\n";
        exit(1);
    }

    PriorityNode<DataType>* pTemp = _pFront;
    DataType temp = pTemp->_data;
    _pFront = pTemp->_pNext;
    delete pTemp;
    _iSize--;

    return temp;
}

template <class DataType>
DataType PriorityQueue<DataType>::Peek()
{
    if (IsEmpty())
    {
        cout << "Hàng đợi rỗng!\n";
        exit(1);
    }
    return _pFront->_data;
}

template <class DataType>
DataType PriorityQueue<DataType>::Back()
{
    if (IsEmpty())
    {
        cout << "Hàng đợi rỗng!\n";
        exit(1);
    }

    PriorityNode<DataType>* pTemp = _pFront;
    while (pTemp->_pNext != NULL)
    {
        pTemp = pTemp->_pNext;
    }

    return pTemp->_data;
}

template <class DataType>
void PriorityQueue<DataType>::Clear()
{
    PriorityNode<DataType>* pTemp;
    while (_pFront != NULL)
    {
        pTemp = _pFront;
        _pFront = pTemp->_pNext;
        delete pTemp;
    }
    _iSize = 0;
}

template <class DataType>
void PriorityQueue<DataType>::Display()
{
    PriorityNode<DataType>* pTemp = _pFront;
    while (pTemp != NULL)
    {
        pTemp->Display();
        pTemp = pTemp->_pNext;
    }
    cout << endl;
}

template <class DataType>
int PriorityQueue<DataType>::GetSize()
{
    return _iSize;
}

template <class DataType>
PriorityQueue<DataType>::~PriorityQueue()
{
    Clear();
}

int main()
{
    int n;
    char c;

    PriorityQueue<int> queue;

    while (cin >> c)
    {
        if (c == '+')
        {
            cin >> n;
            if (queue.GetSize() < 15000)
                queue.EnQueue(n, n);  
        }
        else
        {
            if (!queue.IsEmpty())
            {
                int max = queue.Peek();
                while (!queue.IsEmpty() && queue.Peek() == max)
                    queue.DeQueue();
            }
        }
    }

    PriorityQueue<int> sum;
    while (!queue.IsEmpty())
    {
        int current = queue.Peek(); 
        if (sum.IsEmpty() || sum.Back() != current) 
        {
            sum.EnQueue(queue.DeQueue(), 0); 
        }
        else
        {
            queue.DeQueue(); 
        }
    }

    cout << sum.GetSize() << '\n';
    while (!sum.IsEmpty())
    {
        cout << sum.DeQueue() << " ";
    }
    cout << endl;

    return 0;
}
