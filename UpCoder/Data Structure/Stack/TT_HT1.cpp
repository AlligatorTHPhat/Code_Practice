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

int priority(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main()
{
    Stack<char> stack;
    
    char c;
    while (cin >> c)
    {
        if (isalnum(c)) cout << c;

        else if (c == '(') 
            stack.Push(c);
            
        else if (c == ')')
        {
            while (!stack.IsEmpty() && stack.Peek() != '(')
            {
                cout << stack.Peek();
                stack.Pop();
            }
            if (!stack.IsEmpty())
                stack.Pop();
        }

        else
        {
            while (!stack.IsEmpty() && priority(stack.Peek()) >= priority(c))
            {
                cout << stack.Peek();
                stack.Pop();
            }
            stack.Push(c);
        }
    }

    while (!stack.IsEmpty())
    {
        cout << stack.Peek();
        stack.Pop();
    }

    return 0;
}
