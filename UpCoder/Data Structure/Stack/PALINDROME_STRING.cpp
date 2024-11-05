#include <iostream>
#include <algorithm>
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
    Stack() { init(); }
    void init();
    bool empty();
    void push(DataType data);
    DataType pop();
    DataType top();
    void clear();
    ~Stack();
};

template<class DataType>
void Stack<DataType>::init()
{
    _pTop = NULL;
    _iSize = 0;
}

template<class DataType>
bool Stack<DataType>::empty()
{
    return _pTop == NULL;
}

template<class DataType>
void Stack<DataType>::push(DataType data)
{
    Node<DataType>* pTemp = new Node<DataType>(data);
    pTemp->_pNext = _pTop;
    _pTop = pTemp;
    _iSize++;
}

template<class DataType>
DataType Stack<DataType>::pop()
{
    if (empty())
    {
        cout << "Stack is empty!\n";
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
DataType Stack<DataType>::top()
{
    if (empty())
    {
        cout << "Stack is empty!\n";
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

bool check(string str)
{
    str.erase(remove_if(str.begin(), str.end(), [](char& c)
        {c = tolower(c); return !isalpha(c); }), str.end());

    Stack<char> s;
    for (char c : str)
        s.push(c);

    for (char c : str)
    {
        if (s.top() != c) return false;
        s.pop();
    }

    return true;
}

int main()
{
    string str;
    getline(cin, str);

    cout << (check(str) ? "YES" : "NO");

    return 0;
}
