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

int sum;
string str;
vector<string> suffix;

int priority(char c)
{
    if (c == '*') return 4;
    if (c == '/') return 3;
    if (c == '+') return 2;
    if (c == '-') return 1;
    return 0;
}

int calculate(int a, int b, char c)
{
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
    return pow(a, b);
}

void middleToSuffix()
{
    string tmp;
    Stack<string> s;
    stringstream ss(str);

    while (ss >> tmp) 
    {
        if (isdigit(tmp[0])) suffix.push_back(tmp);
        else if (tmp[0] == '(') s.push(tmp);

        else if (tmp[0] == ')') 
        {
            while (!s.empty() && s.top() != "(") 
            {
                suffix.push_back(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop();
        }

        else 
        {
            while (!s.empty() && priority(s.top()[0]) > priority(tmp[0])) 
            {
                suffix.push_back(s.top());
                s.pop();
            }
            s.push(tmp);
        }
    }

    while (!s.empty()) 
    {
        suffix.push_back(s.top());
        s.pop();
    }
}

void calculateValues()
{
    Stack<int> s;

    for (string x : suffix) 
    {
        if (isdigit(x[0]))
            s.push(stoi(x));

        else 
        {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            char c = x[0];
            s.push(calculate(a, b, c));
        }
    }

    sum = s.top();
}

int main() {
    getline(cin, str);

    middleToSuffix();
    calculateValues();

    cout << sum;

    return 0;
}
