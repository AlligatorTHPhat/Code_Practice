#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>  // Để sử dụng setw cho định dạng bảng

using namespace std;

class Book {
public:
    string bookID;
    string title;
    string author;
    string publisher;
    double price;
    int releaseYear;
    int pages;
    string entryDate;
    int status; // 0 - chưa mượn, số phiếu mượn khi đã mượn

    Book(string id, string t, string a, string p, double pr, int y, int pg, string d, int s)
        : bookID(id), title(t), author(a), publisher(p), price(pr), releaseYear(y), pages(pg), entryDate(d), status(s) {}

    void display() {
        cout << setw(10) << bookID << setw(20) << title << setw(20) << author << setw(20) << publisher
            << setw(10) << price << setw(10) << releaseYear << setw(10) << pages << setw(15) << entryDate
            << setw(10) << status << endl;
    }
};

class Reader {
public:
    string readerID;
    string fullName;
    string registrationDate;

    Reader(string id, string name, string date) : readerID(id), fullName(name), registrationDate(date) {}
};

class BorrowReceipt {
public:
    int receiptID;
    string readerID;
    string bookID;
    string borrowDate;
    string dueDate;
    int status; // 1 - đang mượn, 0 - đã trả

    BorrowReceipt(int rID, string rIDr, string bID, string bDate, string dDate, int s)
        : receiptID(rID), readerID(rIDr), bookID(bID), borrowDate(bDate), dueDate(dDate), status(s) {}
};

// Các hàm tiện ích và quản lý hệ thống

void login() {
    string username, password;
    int attempts = 0;
    while (attempts < 3) {
        cout << "User: ";
        cin >> username;
        cout << "Password: ";
        char ch;
        password = "";
        while ((ch = _getch()) != 13) { // 13 là mã ASCII của phím Enter
            if (ch != 8) { // 8 là mã ASCII của phím Backspace
                password += ch;
                cout << '*';
            }
        }
        cout << endl;

        // Kiểm tra thông tin đăng nhập từ file Admin.txt
        ifstream adminFile("Admin.txt");
        string storedUser, storedPass;
        bool loginSuccess = false;
        while (adminFile >> storedUser >> storedPass) {
            if (username == storedUser && password == storedPass) {
                loginSuccess = true;
                break;
            }
        }
        adminFile.close();

        if (loginSuccess) {
            cout << "Dang nhap thanh cong!" << endl;
            break;
        }
        else {
            cout << "Sai thong tin dang nhap. Vui long thu lai." << endl;
            attempts++;
        }
    }

    if (attempts == 3) {
        cout << "Ban da nhap sai qua 3 lan. He thong se thoat." << endl;
        exit(0);
    }
}

// Hàm hiển thị menu

void showMenu() {
    cout << "========= MENU =========" << endl;
    cout << "1. Quan ly sach" << endl;
    cout << "2. Quan ly phieu muon" << endl;
    cout << "3. Thoat" << endl;
    cout << "=========================" << endl;
}

int main() {
    login();

    while (true) {
        showMenu();
        int choice;
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Thuc hien cac thao tac voi sach
            break;
        case 2:
            // Thuc hien cac thao tac voi phieu muon
            break;
        case 3:
            cout << "Ket thuc chuong trinh." << endl;
            exit(0);
        default:
            cout << "Lua chon khong hop le." << endl;
        }
    }

    return 0;
}
