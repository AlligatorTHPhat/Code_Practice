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
	Node<DataType>* _pHead; // luu dia chi phan tu dau tien
	Node<DataType>* _pTail; //luu dia chi phan tu cuoi cung
	int _iSize;				// luu so luong phan tu
public:
	LinkedList();		//phuog thuc khoi tao mac dinh
	~LinkedList();		//phuong thuc huy

	void addHead(DataType data);
	void addAfter(Node<DataType>* node, DataType data);
	Node<DataType>* search(DataType data);
	Node<DataType>* searchPre(Node<DataType>* node);

	void display();
};

template <class DataType>
LinkedList<DataType>::LinkedList() {
	_pHead = NULL;
	_pTail = NULL;
	_iSize = 0;
}

template <class DataType>
LinkedList<DataType>::~LinkedList() {
}

template <class DataType>
void LinkedList<DataType>::addHead(DataType data) {
	Node<DataType>* pAdd = new Node<DataType>(data);
	//neu danh sach khong co phan tu
	if (_pHead == NULL) {
		_pHead = _pTail = pAdd;
	}
	else {   //danh sach co phan tu
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
	else
		addHead(pAdd);
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

int main() {
	LinkedList<int> l;

	int x;
	while (cin >> x) {
		l.addHead(x);
	}

	l.display();
	cout << endl;
	Node<int>* tmp = l.search(5);
	if (tmp != NULL) {
		cout << "tim thay ";
		tmp->display();
	}
	else
		cout << "khong thay";

	return 0;
}
