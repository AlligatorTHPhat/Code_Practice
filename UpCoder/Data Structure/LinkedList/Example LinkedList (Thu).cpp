#include <iostream>

using namespace std;

template <class DataType>
class Node {
	+:
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
class LinkedList{
	private:
		Node<DataType>* _pHead; // luu dia chi phan tu dau tien
		Node<DataType>* _pTail; //luu dia chi phan tu cuoi cung
		int _iSize;				// luu so luong phan tu
	public:
		LinkedList();		//phuog thuc khoi tao mac dinh
		~LinkedList();		//phuong thuc huy

		void addHead(DataType data);

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
int main() {
	LinkedList<int> l;

	int x;
	while (cin >> x) {
		l.addHead(x);
	}

	l.display();

	return 0;
}
