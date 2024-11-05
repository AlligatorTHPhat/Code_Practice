#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

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

int main() {
    int n, k, x;

    Stack<int> stack, sum;

    cin >> k;

    while (k--)
    {
        cin >> n;

        if (n == 1)
        {
            cin >> x;
            stack.push(x);

            if (sum.empty())
                sum.push(x);
            else
                sum.push(max(sum.top(), x));
        }

        else if (n == 2)
        {
            stack.pop();
            sum.pop();
        }

        else if (n == 3)
            cout << sum.top() << '\n';
    }

    return 0;
}
