#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

string inp;
vector<string> suffix;

int priority(char c) {
    if (c == '^') return 5;
    if (c == '*') return 4;
    if (c == '/') return 3;
    if (c == '+') return 2;
    if (c == '-') return 1;
    return 0;
}

void middleToSuffix() {
    string tmp;
    Stack<string> stack;
    stringstream ss(inp);

    while (ss >> tmp) {
        if (isdigit(tmp[0])) 
            suffix.push_back(tmp);
        
        else if (tmp[0] == '(') 
            stack.push(tmp);
        
        else if (tmp[0] == ')') 
        {
            while (!stack.empty() && stack.top() != "(") 
            {
                suffix.push_back(stack.top());
                stack.pop();
            }
            if (!stack.empty()) stack.pop();
        }

        else 
        {
            while (!stack.empty() && priority(stack.top()[0]) > priority(tmp[0]))
            {
                suffix.push_back(stack.top());
                stack.pop();
            }
            stack.push(tmp);
        }
    }

    while (!stack.empty())
    {
        suffix.push_back(stack.top());
        stack.pop();
    }
}

int main()
{
    getline(cin, inp);

    middleToSuffix();

    for (string s : suffix)
        cout << s << " ";

    return 0;
}
