#include <iostream>
#include <string>

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
    Node(DataType data) : _data(data), _pNext(NULL) {}
};

template<class DataType>
class Stack
{
private:
    Node<DataType>* _pTop;
    int _iSize;

public:
    Stack() : _pTop(NULL), _iSize(0) {}
    bool IsEmpty() const { return _pTop == NULL; }
    void Push(DataType data)
    {
        Node<DataType>* pTemp = new Node<DataType>(data);
        pTemp->_pNext = _pTop;
        _pTop = pTemp;
        _iSize++;
    }
    DataType Pop()
    {
        if (IsEmpty())
        {
            exit(1);
        }
        Node<DataType>* pTemp = _pTop;
        DataType temp = pTemp->_data;
        _pTop = pTemp->_pNext;
        delete pTemp;
        _iSize--;
        return temp;
    }
    DataType Peek() const
    {
        if (IsEmpty())
        {
            exit(1);
        }
        return _pTop->_data;
    }
    void clear()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }
    ~Stack() { clear(); }
};

int main()
{
    int n;
    Stack<int> stack;
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        stack.Push(value);
    }

    string sum;

    while (!stack.IsEmpty())
    {
        int k = stack.Pop();

        if (k == 0)
            sum.insert(0, "()"); 
        else
        {
            sum.insert(0, "(");
            sum.insert(k, ")");
        }
    }

    cout << sum << endl;

    return 0;
}
