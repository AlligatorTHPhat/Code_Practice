#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

int ans;
string inp, str;
vector<string> suffix;

int priority(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
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

void addSpace()
{
    str = "";
    for (int i = 0; i < inp.size(); i++) {
        if (!isdigit(inp[i])) str += ' ';
        str += inp[i];
        if (isdigit(inp[i + 1]) && !isdigit(inp[i])) str += ' ';
    }
}

void middleToSuffix()
{
    string tmp;
    Stack<string> s;
    stringstream ss(str);

    while (ss >> tmp) {
        if (isdigit(tmp[0])) suffix.push_back(tmp);
        else if (tmp[0] == '(') s.Push(tmp);

        else if (tmp[0] == ')') {
            while (!s.IsEmpty() && s.Peek() != "(") {
                suffix.push_back(s.Pop());
            }
            if (!s.IsEmpty()) s.Pop();
        }

        else {
            while (!s.IsEmpty() && priority(s.Peek()[0]) >= priority(tmp[0])) {
                suffix.push_back(s.Pop());
            }
            s.Push(tmp);
        }
    }

    while (!s.IsEmpty()) {
        suffix.push_back(s.Pop());
    }
}
void calculateValues()
{
    Stack<int> s;

    for (string x : suffix) {
        if (isdigit(x[0]))
            s.Push(stoi(x));
        else {
            int b = s.Pop();
            int a = s.Pop();
            char c = x[0];
            s.Push(calculate(a, b, c));
        }
    }
    ans = s.Pop();
}

int main() {
    cin >> inp;
    addSpace();
    middleToSuffix();
    calculateValues();
    cout << ans;
    return 0;
}
