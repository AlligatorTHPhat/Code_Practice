#include <iostream>
#include <vector>
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

void DFS(int start, const vector<vector<int>>& adjList, vector<bool>& visited)
{
    Stack<int> stack;
    stack.push(start);

    while (!stack.empty())
    {
        int current = stack.pop();

        if (!visited[current])
        {
            cout << current << " ";
            visited[current] = true;
        }

        // Duyệt các đỉnh kề theo thứ tự giảm dần để đảm bảo đỉnh nhỏ hơn được duyệt trước (do Stack là cấu trúc LIFO)
        for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it)
        {
            if (!visited[*it])
            {
                stack.push(*it);
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

    // Duyệt DFS từ đỉnh S
    DFS(S, adjList, visited);

    return 0;
}
