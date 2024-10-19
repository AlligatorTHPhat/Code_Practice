#include <iostream>

using namespace std;

template <class DataType>
class Node {
public:
    DataType _data;
    Node* _pNext;

    Node(DataType data) : _data(data), _pNext(nullptr) {}
    void display() const {
        cout << _data << " ";
    }
};

template <class DataType>
class LinkedList {
private:
    Node<DataType>* _pHead;
    Node<DataType>* _pTail;
    int _iSize;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    void addHead(DataType data);
    void addAfter(Node<DataType>* node, DataType data);
    void pushBack(DataType data);
    Node<DataType>* search(DataType data) const;
    Node<DataType>* searchPre(Node<DataType>* node) const;
    void removeHead();
    void removeTail();
    void removeAfter(Node<DataType>* node);
    void remove(DataType data);
    void selectionSort();
    void display() const;
    int getSize() const;
    void clear();
    bool solve() const;
};

template <class DataType>
LinkedList<DataType>::LinkedList() : _pHead(nullptr), _pTail(nullptr), _iSize(0) {}

template <class DataType>
LinkedList<DataType>::~LinkedList() {
    clear();
}

template <class DataType>
bool LinkedList<DataType>::isEmpty() const {
    return _pHead == nullptr;
}

template <class DataType>
void LinkedList<DataType>::addHead(DataType data) {
    Node<DataType>* pAdd = new Node<DataType>(data);
    if (isEmpty()) {
        _pHead = _pTail = pAdd;
    }
    else {
        pAdd->_pNext = _pHead;
        _pHead = pAdd;
    }
    ++_iSize;
}

template <class DataType>
void LinkedList<DataType>::pushBack(DataType data) {
    Node<DataType>* pAdd = new Node<DataType>(data);
    if (isEmpty()) {
        _pHead = _pTail = pAdd;
    }
    else {
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    ++_iSize;
}

template <class DataType>
void LinkedList<DataType>::display() const {
    Node<DataType>* pWalker = _pHead;
    while (pWalker != nullptr) {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }
    cout << endl;
}

template <class DataType>
void LinkedList<DataType>::addAfter(Node<DataType>* node, DataType data) {
    if (!node) return;  // Node cannot be nullptr

    Node<DataType>* pAdd = new Node<DataType>(data);
    pAdd->_pNext = node->_pNext;
    node->_pNext = pAdd;

    if (node == _pTail) {
        _pTail = pAdd;
    }
    ++_iSize;
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::search(DataType data) const {
    Node<DataType>* p = _pHead;
    while (p != nullptr && p->_data != data) {
        p = p->_pNext;
    }
    return p;
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::searchPre(Node<DataType>* node) const {
    if (_pHead == node) return nullptr;

    Node<DataType>* p = _pHead;
    while (p != nullptr && p->_pNext != node) {
        p = p->_pNext;
    }
    return p;
}

template <class DataType>
void LinkedList<DataType>::removeHead() {
    if (!isEmpty()) {
        Node<DataType>* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;

        if (_pHead == nullptr) {
            _pTail = nullptr;
        }
        --_iSize;
    }
}

template <class DataType>
void LinkedList<DataType>::removeTail() {
    if (isEmpty()) return;

    if (_pHead == _pTail) {
        delete _pHead;
        _pHead = _pTail = nullptr;
    }
    else {
        Node<DataType>* preTail = searchPre(_pTail);
        if (preTail) {
            delete _pTail;
            preTail->_pNext = nullptr;
            _pTail = preTail;
        }
    }
    --_iSize;
}

template <class DataType>
void LinkedList<DataType>::removeAfter(Node<DataType>* node) {
    if (node && node->_pNext) {
        Node<DataType>* pTemp = node->_pNext;
        node->_pNext = pTemp->_pNext;
        if (pTemp == _pTail) {
            _pTail = node;
        }
        delete pTemp;
        --_iSize;
    }
}

template <class DataType>
void LinkedList<DataType>::remove(DataType data) {
    Node<DataType>* node = search(data);
    if (!node) return;

    if (node == _pHead) {
        removeHead();
    }
    else {
        Node<DataType>* preNode = searchPre(node);
        removeAfter(preNode);
    }
}

template<class DataType>
void LinkedList<DataType>::selectionSort() {
    for (Node<DataType>* p = _pHead; p != nullptr; p = p->_pNext) {
        Node<DataType>* pMin = p;
        for (Node<DataType>* q = p->_pNext; q != nullptr; q = q->_pNext) {
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
int LinkedList<DataType>::getSize() const {
    return _iSize;
}

template <class DataType>
void LinkedList<DataType>::clear() {
    while (!isEmpty()) {
        removeHead();
    }
}

template <class DataType>
bool LinkedList<DataType>::solve() const {
    for (Node<DataType>* a = _pHead; a != nullptr; a = a->_pNext) {
        for (Node<DataType>* b = _pHead; b != nullptr; b = b->_pNext) {
            if (b == a) continue;
            for (Node<DataType>* c = _pHead; c != nullptr; c = c->_pNext) {
                if (c == a || c == b) continue;
                if (a->_data == b->_data + c->_data) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    LinkedList<int> l;
    int n, tmp;
    cin >> n;

    while (n--) {
        cin >> tmp;
        l.pushBack(tmp);
    }

    cout << (l.solve() ? "YES" : "NO") << endl;
    l.clear();
    return 0;
}
