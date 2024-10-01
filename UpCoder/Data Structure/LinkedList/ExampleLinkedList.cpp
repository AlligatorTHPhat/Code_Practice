#include <iostream>

using namespace std;

template <class DataType>
class Node {
private:
    DataType data;
    Node<DataType>* next; 

public:
    Node(DataType val) : data(val), next(nullptr) {}

    DataType get_Data() {
        return data;
    }

    void display() {
        cout << data << " ";
    }

    Node<DataType>* get_Next() {
        return next;
    }

    void set_Next(Node<DataType>* next_Node) {
        next = next_Node;
    }
};

template <class DataType>
class LinkedList {
private:
    Node<DataType>* head;  
    Node<DataType>* tail;  
    int size_LK;              

public:
    LinkedList();  
    ~LinkedList(); 
    void add_Head(DataType data);  
    void display();  
};

template<class DataType>
LinkedList<DataType>::LinkedList() : head(nullptr), tail(nullptr), size_LK(0) {}

template<class DataType>
LinkedList<DataType>::~LinkedList() {
    Node<DataType>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->get_Next();
        delete temp;
    }
}

template<class DataType>
void LinkedList<DataType>::add_Head(DataType data) {
    Node<DataType>* new_Node = new Node<DataType>(data);  

    if (head == nullptr) {
        head = tail = new_Node;
    }
    else {
        new_Node->set_Next(head);
        head = new_Node;
    }
    ++size_LK;
}

template<class DataType>
void LinkedList<DataType>::display() {
    Node<DataType>* walker = head;
    while (walker != nullptr) {
        walker->display();  
        walker = walker->get_Next();  
    }
    cout << endl;
}

int main() {
    LinkedList<int> l;
    int x;
    
    cout << "Nhap cac gia tri: ";
    while (cin >> x) {
        l.add_Head(x);
    }

    cout << "Danh sach lien ket: ";
    l.display();  

    return 0;
}
