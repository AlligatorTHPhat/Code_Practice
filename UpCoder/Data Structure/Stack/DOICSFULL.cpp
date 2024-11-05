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
    void clear();
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
        cout << "Stack da rong!\n";
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
        cout << "Stack da rong!\n";
        exit(1);
    }
    return _pTop->_data;
}

template<class DataType>
void Stack<DataType>::clear()
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
    clear();
}

void changeFactor(long factor10, int newFactor)
{
    string str = "0123456789ABCDEF";
    
    Stack<char> stack;

    if (factor10 == 0)
    {
        cout << 0;
        return;
    }

    int type;
    switch (newFactor)
    {
        case 0: type = 2; break;
        case 1: type = 8; break;
        case 2: type = 16; break;
    }

    while (factor10)
    {
        stack.Push(str[factor10 % type]);
        factor10 /= type;
    }

    while (!stack.IsEmpty())
    {
        cout << stack.Peek();
        stack.Pop();
    }
}

int main()
{
    long factor10;
    int newFactor;

    cin >> factor10 >> newFactor;

    changeFactor(factor10, newFactor);

    return 0;
}
