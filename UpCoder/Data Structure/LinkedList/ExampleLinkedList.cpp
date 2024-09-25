#include <iostream>
using namespace std;

template <class DataType>
class Node {
private:
    DataType data;
    Node<DataType>* next;  // Khai báo con trỏ next với template

public:
    // Constructor
    Node(DataType val) {
        data = val;
        next = nullptr;
    }

    void display() {
        cout << data << " ";
    }

    // Getter và Setter cho next
    Node<DataType>* getNext() {
        return next;
    }

    void setNext(Node<DataType>* nextNode) {
        next = nextNode;
    }
};

template <class DataType>
class LinkedList {
private:
    Node<DataType>* head;  // Lưu địa chỉ đầu tiên
    Node<DataType>* tail;  // Lưu địa chỉ cuối cùng
    int size;              // Kích thước của danh sách

public:
    LinkedList();  // Constructor
    ~LinkedList(); // Destructor
    void add_Head(DataType data);  // Thêm phần tử vào đầu danh sách
    void display();  // Hiển thị danh sách
};

template<class DataType>
LinkedList<DataType>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class DataType>
LinkedList<DataType>::~LinkedList() {
    // Hủy tất cả các Node khi danh sách bị hủy
    Node<DataType>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->getNext();
        delete temp;
    }
}

template<class DataType>
void LinkedList<DataType>::add_Head(DataType data) {
    Node<DataType>* new_Node = new Node<DataType>(data);  // Tạo Node mới

    if (head == nullptr) {
        head = tail = new_Node;  // Nếu danh sách rỗng, Node mới là đầu và đuôi
    } else {
        new_Node->setNext(head);  // Node mới trỏ đến Node đầu hiện tại
        head = new_Node;  // Cập nhật head thành Node mới
    }
    ++size;
}

template<class DataType>
void LinkedList<DataType>::display() {
    Node<DataType>* walker = head;
    while (walker != nullptr) {
        walker->display();  // Gọi hàm display của Node
        walker = walker->getNext();  // Duyệt qua Node tiếp theo
    }
    cout << endl;
}

int main() {
    LinkedList<int> l;
    int x;
    
    // Nhập dữ liệu từ người dùng và thêm vào danh sách liên kết
    cout << "Nhập các số nguyên (nhập -1 để kết thúc): ";
    while (cin >> x && x != -1) {
        l.add_Head(x);
    }

    cout << "Danh sách liên kết: ";
    l.display();  // Hiển thị danh sách
    return 0;
}
