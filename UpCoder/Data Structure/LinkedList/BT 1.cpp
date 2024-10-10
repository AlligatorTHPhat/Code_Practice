#include <iostream>

using namespace std;

template <class DataType>
class Node {
public:
    DataType _data;
    Node* _pNext;
public:
    Node(DataType data);
    void display();
};

template <class DataType>
Node<DataType>::Node(DataType data) {
    _data = data;
    _pNext = NULL;
}

template <class DataType>
void Node<DataType>::display() {
    cout << _data << " ";
}

template <class DataType>
class LinkedList {
private:
    Node<DataType>* _pHead; // Pointer to the first element
    Node<DataType>* _pTail; // Pointer to the last element
    int _iSize;             // Size of the list
public:
    LinkedList();       // Default constructor
    ~LinkedList();      // Destructor

    void addHead(DataType data);
    void addAfter(Node<DataType>* node, DataType data);
    Node<DataType>* search(DataType data);
    Node<DataType>* searchPre(Node<DataType>* node);
    void removeHead();
    void removeTail();
    void removeAfter(Node<DataType>* node);
    void remove(DataType data);  // Remove function
    void selectionSort();
    void display();
    int get_Size();   // Get the size of the linked list
    void clear();     // Clear the entire list
};

template <class DataType>
LinkedList<DataType>::LinkedList() {
    _pHead = NULL;
    _pTail = NULL;
    _iSize = 0;
}

template <class DataType>
LinkedList<DataType>::~LinkedList() {
    clear();  // Ensures all nodes are properly deleted
}

template <class DataType>
void LinkedList<DataType>::addHead(DataType data) {
    Node<DataType>* pAdd = new Node<DataType>(data);
    // If the list is empty
    if (_pHead == NULL) {
        _pHead = _pTail = pAdd;
    }
    else {   // The list has elements
        pAdd->_pNext = _pHead;
        _pHead = pAdd;
    }
    ++_iSize;
}

template <class DataType>
void LinkedList<DataType>::display() {
    Node<DataType>* pWalker = _pHead;
    while (pWalker != NULL) {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }
    cout << endl;
}

template <class DataType>
void LinkedList<DataType>::addAfter(Node<DataType>* node, DataType data) {
    Node<DataType>* pAdd = new Node<DataType>(data);

    if (node != NULL) {
        pAdd->_pNext = node->_pNext;
        node->_pNext = pAdd;
        if (node == _pTail)
            _pTail = pAdd;
    }
    else {
        addHead(data);
    }
    ++_iSize;
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::search(DataType data) {
    Node<DataType>* p = _pHead;

    while ((p != NULL) && (p->_data != data))
        p = p->_pNext;
    return p;
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::searchPre(Node<DataType>* node) {
    Node<DataType>* p = _pHead;
    if (p == node)
        return NULL;
    while ((p != NULL) && (p->_pNext != node))
        p = p->_pNext;
    return p;
}

template <class DataType>
void LinkedList<DataType>::removeHead() {
    if (_pHead != NULL) {
        Node<DataType>* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if (_pHead == NULL) { // If the list becomes empty after removal
            _pTail = NULL;
        }
        --_iSize;
    }
}

template <class DataType>
void LinkedList<DataType>::removeTail() {
    if (_pHead == NULL) return; // Empty list

    if (_pHead == _pTail) { // Only one element in the list
        delete _pHead;
        _pHead = _pTail = NULL;
    }
    else {
        Node<DataType>* pTemp = _pTail;
        _pTail = searchPre(_pTail);
        if (_pTail != NULL) _pTail->_pNext = NULL;
        delete pTemp;
    }
    --_iSize;
}

template <class DataType>
void LinkedList<DataType>::removeAfter(Node<DataType>* node) {
    Node<DataType>* pTemp;
    if (node != NULL && node->_pNext != NULL) {
        pTemp = node->_pNext;
        node->_pNext = pTemp->_pNext;
        if (pTemp == _pTail) {
            _pTail = node;
        }
        delete pTemp;
        --_iSize;
    }
    else if (node == NULL) {
        removeHead();
    }
}

template <class DataType>
void LinkedList<DataType>::remove(DataType data) {
    // Find the node to remove
    Node<DataType>* node = search(data);
    if (node == NULL) return; // Element not found

    // If the node to remove is the head
    if (_pHead == node) {
        removeHead();
        return;
    }

    // Find the node before the one to be removed
    Node<DataType>* preNode = searchPre(node);

    // If the node exists, remove it
    if (preNode != NULL && node != NULL) {
        removeAfter(preNode);
    }
}

template<class DataType>
void LinkedList<DataType>::selectionSort()
{
    for (Node<DataType>* p = _pHead; p != NULL; p = p->_pNext) {
        Node<DataType>* pMin = p;
        for (Node<DataType>* q = p->_pNext; q != NULL; q = q->_pNext) {
            if (q->_data < pMin->_data) {
                pMin = q;
            }
        }
        if (pMin != p) {
            swap(p->_data, pMin->_data);
        }
    }
}

template <class DataType>
int LinkedList<DataType>::get_Size() {
    return _iSize;
}

template <class DataType>
void LinkedList<DataType>::clear() {
    while (_pHead != NULL) {
        removeHead();
    }
}

int main() {
    LinkedList<int> l;

    int x;
    while (cin >> x) {
        l.addHead(x);
    }

    l.display();

    cout << "Size of the list: " << l.get_Size() << endl;

    // Sorting the list
    l.selectionSort();
    cout << "After sorting: " << endl;
    l.display();

    // Removing a specific element
    l.remove(5);
    cout << "After removing 5:" << endl;
    l.display();

    // Clearing the list
    l.clear();
    cout << "After clearing the list: " << endl;
    l.display();

    cout << "Size of the list after clearing: " << l.get_Size() << endl;

    return 0;
}
