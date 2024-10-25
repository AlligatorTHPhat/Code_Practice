#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <filesystem>

using namespace std;

string getday();
string getmon();
string getyear();
string getback(string day, string mon, string year);
bool checkAdmin(string username, string password);
void MainConsole();
void BookConsole();
void CardConsole();
void BookDisplay();
void addBook();
void deleteBook();
bool file_is_empty(string filename);
void tokenize(string& str, char delim, vector<string>& out);
void CardDisplay();
void createCard();
void returnCard();
bool checkmasach(string masach);
bool checkmabandoc(string mabandoc);
void updatebook(string masach);
void updatecard(string masach, string mabandoc);

/***************************************************
* @ Description Class Book
* 
* @ Gom cac thong tin ve mot cuon sach :
* + id : ID cua cuon sach (Kieu du lieu : string)
* + name : Ten cua cuon sach (Kieu du lieu : string)
* + author : Ten cua tac gia (Kieu du lieu : string)
* + publisher : Nha xuat ban (Kieu du lieu : string)
* + price : Gia cua cuon sach (Kieu du lieu : string)
* + year : Nam xuat ban cua cuon sach (Kieu du lieu : string)
* + numpage : So trang cua cuon sach (Kieu du lieu : string)
* + dayin : Ngay sach nhap kho (Kieu du lieu : string)
* + status : Tinh trang sach (0 la dang khong duoc muon - 1 la dang duoc muon) (Kieu du lieu : string)
***************************************************/
class Book {
public:
	string id;
	string name;
	string author;
	string publisher;
	string price;
	string year;
	string numpage;
	string dayin;
	string status;

	/**********************************************
	* @ Description ham nhap du lieu cuon sach tu ban phim
	* 
	* @ return : None
	**********************************************/
	void getinfor() {
		cout << "Nhap id : ";
		cin >> id;
		cin.ignore();
		cout << "Nhap ten sach : ";
		getline(std::cin, name);
		cout << "Nhap ten tac gia: ";
		getline(std::cin, author);
		cout << "Nhap ten nha xuat ban: ";
		getline(std::cin, publisher);
		cout << "Nhap gia sach: ";
		cin >> price;
		cout << "Nhap nam xuat ban: ";
		cin >> year;
		cout << "Nhap so trang: ";
		cin >> numpage;
		dayin = getday() + "/" + getmon() + "/" + getyear();
		status = '0';
	}

	void getfromfile(string fileid, string filename, string fileauthor, string filepublisher, string fileprice, string fileyear, string filenumpage, string filedayin, string filestatus);
	void display();
};

/**************************************************
* @ Description Ham doc du lieu tu file
* 
* @ return None
**************************************************/
void Book::getfromfile(string fileid, string filename, string fileauthor, string filepublisher, string fileprice, string fileyear, string filenumpage, string filedayin, string filestatus) {
	id = fileid;
	name = filename;
	author = fileauthor;
	publisher = filepublisher;
	price = fileprice;
year = fileyear;
	numpage = filenumpage;
	dayin = filedayin;
	status = filestatus;
}

/**************************************************
* @ Description Ham display du lieu 
*
* @ return None
**************************************************/
void Book::display() {
	cout << id << "|" << name << "|" << author << "|" << publisher << "|" << price << "|" << year << "|" << numpage << "|" << dayin << "|" << status << endl;
}

/***************************************************
* @ Description Class Reader
*
* @ Gom cac thong tin ve mot cuon sach :
* + id : ID cua cuon ban doc (Kieu du lieu : string)
* + name : Ten cua ban doc (Kieu du lieu : string)
* + day_create : Ngay tao ban doc (Kieu du lieu : string)
***************************************************/
class Reader {
public:
	string id;
	string name;
	string day_create;

	void getinfor() {
		cout << "Nhap id: ";
		cin >> id;
		cout << "Nhap ho va ten: ";
		getline(std::cin, name);
		day_create = getday() + "/" + getmon() + "/" + getyear();
	}

	void getfromfile(string fileid, string filename, string fileday_create);
	void display();
};

/**************************************************
* @ Description Ham lay du lieu tu file
*
* @ return None
**************************************************/
void Reader::getfromfile(string fileid, string filename, string fileday_create) {
	id = fileid;
	name = filename;
	day_create = fileday_create;
}

/**************************************************
* @ Description Ham display du lieu cua ban doc
*
* @ return None
**************************************************/
void Reader::display() {
	cout << id << "|" << name << "|" << day_create << endl;
}

/***************************************************
* @ Description Class Card
*
* @ Gom cac thong tin ve mot cuon sach :
* + num : so phieu muon (Kieu du lieu : string)
* + id_reader : ID cua cuon ban doc (Kieu du lieu : string)
* + id_book : ID cua cuon sach (Kieu du lieu : string)
* + day_rent : Ngay muon sach (Kieu du lieu : string)
* + day_giveback : Ngay phai tra sach (Kieu du lieu : string)
* + status : Trang thai cua phieu muon (1 la dang su dung - 0 la khong su dung) (Kieu du lieu : string)
***************************************************/
class Card {
public:
	string num;
	string id_reader;
	string id_book;
	string day_rent;
	string day_giveback;
	string status;

	/**************************************************
	* @ Description Ham lay du lieu tu ban phim
	*
	* @ return None
	**************************************************/
	void getinfor() {
		cout << "Nhap vao so phieu muon: ";
		cin >> num;
		cout << "Nhap vao id cua ban doc: ";
		cin >> id_reader;
		cout << "Nhap vao id cua sach: ";
		cin >> id_book;
		day_rent = getday() + "/" + getmon() + "/" + getyear();
		day_giveback = getback(getday(), getmon(), getyear());
		status = "0";
	}
void getfromfile(string filenum, string fileid_reader, string fileid_book, string fileday_rent, string fileday_giveback, string filestatus); //Lay du lieu tu file
	void display();
};

/**************************************************
* @ Description Ham lay du lieu tu file
*
* @ return None
**************************************************/
void Card::getfromfile(string filenum, string fileid_reader, string fileid_book, string fileday_rent, string fileday_giveback, string filestatus) {
	num = filenum;
	id_reader = fileid_reader;
	id_book = fileid_book;
	day_rent = fileday_rent;
	day_giveback = fileday_giveback;
	status = filestatus;
}
/**************************************************
* @ Description Ham display du lieu
*
* @ return None
**************************************************/
void Card::display() {
	cout << num << "|" << id_reader << "|" << id_book << "|" << day_rent << "|" << day_giveback << "|" << status << endl;
}
/***************************************************
* @ Description Class NODE
*
* @ Gom cac thong tin ve mot cuon sach :
* + _data : Chua data cua mot NODE
* + _pNext : Con tro chi toi Node tiep theo
***************************************************/
template <class DataType>
class Node {
public:
	DataType _data;
	Node* _pNext;
public:
	Node(DataType data);
	void display();
};

/***************************************************
* @ Description Ham khoi tao gia tri cho con tro
*
* @ return NODE
* @ para data
***************************************************/
template <class DataType>
Node<DataType>::Node(DataType data) {
	_data = data;
	_pNext = NULL;
}
/***************************************************
* @ Description Ham bieu dien gia tri cua con tro
*
* @ return None
***************************************************/
template <class DataType>
void Node<DataType>::display() {
	_data.display();
}

/***************************************************
* @ Description Class LinkedList
*
* @ Gom cac thong tin ve mot cuon sach :
* + _pHead : NODE dau tien cua Linked List (Kieu du lieu NODE) 
* + _pTail : NODE cuoi cung cua Linked List (Kieu du lieu NODE)
***************************************************/
template <class DataType>
class LinkedList {
public:
	Node<DataType>* _pHead;
	Node<DataType>* _pTail;
	int _iSize;
public:
	LinkedList();
	~LinkedList();
	void addTail(DataType data);
	Node<DataType>* search(DataType data);
	void display();
	void remove(DataType data);
};

/***************************************************
* @ Description Ham khoi tao NODE rong
*
* @ return LinkedList
***************************************************/
template <class DataType>
LinkedList<DataType>::LinkedList() {
	_pHead = NULL;
	_pTail = NULL;
	_iSize = 0;
}

/***************************************************
* @ Description Ham them Node cuoi vao tail
*
* @ return None
***************************************************/
template <class DataType>
void LinkedList<DataType>::addTail(DataType data) {
Node<DataType>* pAdd = new Node<DataType>(data);
	if (_pHead == NULL) {
		_pHead = _pTail = pAdd;
	}
	else {
		_pTail->_pNext = pAdd;
		_pTail = pAdd;
	}
	_iSize++;
}

/***************************************************
* @ Description Bieu dien gia tri cua Linked List
*
* @ return None
***************************************************/
template <class DataType>
void LinkedList<DataType>::display() {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		pWalker->display();
		pWalker = pWalker->_pNext;
	}
}

/***************************************************
* @ Description Tim kiem Node co gia tri cho truoc
*
* @ return Node
***************************************************/
template <class DataType>
Node<DataType>* LinkedList<DataType>::search(DataType data) {
	Node<DataType>* p = _pHead;
	while ((p != NULL) && (p->_data.id != data.id)) {
		p = p->_pNext;
	}
	return p;
}

/***************************************************
* @ Description Xoa Node co gia tri cho truoc
*
* @ return None
***************************************************/
template <class DataType>
void LinkedList<DataType>::remove(DataType data) {
	Node<DataType>* pWalker = _pHead, * pTemp = NULL;
	if (pWalker->_data.id == _pHead->_data.id) {
		pTemp = _pHead->_pNext;
		_pHead = pTemp;
		delete pWalker;
		return;
	}
	while ((pWalker != NULL) && (pWalker->_data.id != data.id)) {
		pTemp = pWalker; pWalker = pWalker->_pNext;
	}
	if (pWalker == NULL) return;
	if (pTemp != NULL) {
		if (pWalker == _pTail) {
			_pTail = pTemp;
			_pTail->_pNext = NULL;
		}
		pTemp->_pNext = pWalker->_pNext;
		delete pWalker;
		_iSize--;
	}
}

int main()
{
	string username;
	string password;
	int count = 0;

	while(true){
		cout << "*******************************************" << endl;
		cout << "*" << "      Dang nhap he thong     " << "*" << endl;
		cout << "*******************************************" << endl;

		cout << "  User:      ";
		cin >> username;
		cout << "  Password:  ";
		cin >> password;
		if (checkAdmin(username, password)==true) {
			MainConsole();
			break;
		}
		else {
			cout << "Nhap sai, moi nhap lai!" << endl;
			count += 1;
		}
		if (count == 3) {
			exit(0);
		}
	}
	return 0;
}

/***************************************************
* @ Description Ham lay ngay hien tai
*
* @ return day (kieu du lieu string)
***************************************************/
string getday() {
	time_t present = time(0);

	tm* ltm = localtime(&present);
	string day;
	day = to_string(ltm->tm_mday);
	return day;
}

/***************************************************
* @ Description Ham lay thang hien tai
*
* @ return thang (kieu du lieu string)
***************************************************/
string getmon() {
	time_t present = time(0);

	tm* ltm = localtime(&present);
	string mon;
	mon = to_string(1 + ltm->tm_mon);
	return mon;
}

/***************************************************
* @ Description Ham lay nam hien tai
*
* @ return nam (kieu du lieu string)
***************************************************/
string getyear() {
	time_t present = time(0);

	tm* ltm = localtime(&present);
	string year;
	year = to_string(1900 + ltm->tm_year);
	return year;
}
/***************************************************
* @ Description Ham lay ngay thang nam sau khi + them 7 ngay
*
* @ return ngay/thang/nam (kieu du lieu string)
* 
* @ para :
* string day, string mon, string year
***************************************************/
string getback(string day, string mon, string year) {
	int dayy, monn, yearr;
	dayy = stoi(day);
	monn = stoi(mon);
	yearr = stoi(year);

	if (monn == 2 && dayy > 21) {
		mon += 1;
		dayy = dayy + 7 - 28;
	}
	else {
		dayy += 7;
	}
	return to_string(dayy) + "/" + to_string(monn) + "/" + to_string(yearr);
	if ((monn == 1 || monn == 3 || monn == 5 || monn == 7 || monn == 8 || monn == 10) && dayy > 24) {
		monn += 1;
		dayy = dayy + 7 - 31;
	}
	else {
		dayy += 7;
	}
	return to_string(dayy) + "/" + to_string(monn) + "/" + to_string(yearr);
	if ((monn == 4 || monn == 6 || monn == 9 || monn == 11) && dayy > 23) {
		monn += 1;
		dayy = dayy + 7 - 30;
	}
	else {
		dayy += 7;
	}
	return to_string(dayy) + "/" + to_string(monn) + "/" + to_string(yearr);
	if (monn == 12 && dayy > 24) {
		yearr += 1;
		monn = 1;
		dayy = dayy + 7 - 31;
	}
	else {
		dayy += 7;
	}
	return to_string(dayy) + "/" + to_string(monn) + "/" + to_string(yearr);
}
/***************************************************
* @ Description Kiem tra dang nhap
*
* @ return bool (1 - Dung, 0 - Sai)
***************************************************/
bool checkAdmin(string username, string password) {
	string tmpuser, tmppass;
	ifstream admin("Admin.txt");
	admin >> tmpuser;
	admin >> tmppass;
	if (username == tmpuser && password == tmppass) {
		return true;
	}
	else {
		return false;
	}
}
/***************************************************
* @ Description Giao dien chinh
*
* @ return None
***************************************************/
void MainConsole() {
	system("cls");
	int choice;
	cout << "1. Quan ly Sach" << endl;
	cout << "2. Quan ly Phieu Muon" << endl;
	cout << "3. Thoat" << endl;
	cout << endl;
	cout << "Hay nhap lua chon cua ban: ";
	cin >> choice;
	if (choice == 1) {
		BookConsole();
	}
	else if (choice == 2) {
		CardConsole();
	}
	else {
		cout << "Vui long nhap lai yeu cau";
	}
}
/***************************************************
* @ Description Giao dien Quan ly sach
*
* @ return None
***************************************************/
void BookConsole() {
	system("cls");
	int choice;
	cout << "1. Hien thi thong tin sach" << endl;
	cout << "2. Them sach" << endl;
	cout << "3. Xoa sach" << endl;
	cout << endl;
	cout << "Hay nhap lua chon cua ban: ";
	cin >> choice;
	if (choice == 1) {
		//cout << "Hien thi thong tin sach" << endl;
		BookDisplay();
	}
	else if (choice == 2) {
		//cout << "Them sach" << endl;
		addBook();
	}
	else if (choice == 3) {
		//cout << "Xoa sach" << endl;
		deleteBook();
	}
	else {
cout << "Vui long nhap lai yeu cau";
	}
}
/***************************************************
* @ Description Giao dien Quan ly phieu muon
*
* @ return None
***************************************************/
void CardConsole() {
	system("cls");
	int choice;
	cout << "1. Hien thi thong tin phieu muon" << endl;
	cout << "2. Muon sach" << endl;
	cout << "3. Tra sach" << endl;
	cout << endl;
	cout << "Hay nhap lua chon cua ban: ";
	cin >> choice;
	if (choice == 1) {
		//cout << "Hien thi thong tin phieu muon" << endl;
		CardDisplay();
	}
	else if (choice == 2) {
		//cout << "Muon sach" << endl;
		createCard();
	}
	else if (choice == 3) {
		//cout << "Tra sach" << endl;
		returnCard();
	}
	else {
		cout << "Vui long nhap lai yeu cau";
	}
}
/***************************************************
* @ Description Kiem tra file co rong hay khong
*
* @ para : Ten file (string)
* @ return bool (1 - rong, 0 - khong rong)
***************************************************/
bool file_is_empty(string filename) {
	ifstream pFile(filename);
	return pFile.peek() == std::ifstream::traits_type::eof();
}
/***************************************************
* @ Description Chuyen tu chuoi string sang vector
*
* @ return None
***************************************************/
void tokenize(string& str, char delim, vector<string>& out) {
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}
/***************************************************
* @ Description Display nhung cuon sach hien co trong csdl
*
* @ return None
***************************************************/
void BookDisplay() {
	system("cls");
	string path = "Sach.txt";
	if (file_is_empty(path)) {
		ofstream write("Sach.txt");
		string text;
		cout << "File hien dang rong, vui long them sach vao: ";
		Book s1;
		s1.getinfor();
		text = s1.id + '\t' + s1.name;
		write << text << endl;
		write.close();
	}
	else {
		cout << "  ID  |  Name  |  Author  |  Publisher  |  Price  |  Year  |  NUMPAGE  |  DAYIN  |  STATUS  " << endl;
		fstream f;
		f.open(path);
		string line;
		while (!f.eof()) {
			getline(f, line);
			cout << line << endl;
		}
		f.close();
	}
}
/***************************************************
* @ Description Them sach vao file text
*
* @ return None
***************************************************/
void addBook() {
	system("cls");
	string path = "Sach.txt";
	fstream f;
	f.open(path);
	string line;
	LinkedList<Book> *l = new LinkedList<Book>();
	while (!f.eof()) {
		getline(f, line);
		char d = '|';
		vector<string> a;
		tokenize(line, d, a);
		Book s;
		s.getfromfile(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
		l->addTail(s);
	}
	f.close();
	fstream w;
	w.open(path, ios::app);
	Book tmp;
	tmp.getinfor();
	while (true) {
		if (l->search(tmp) == NULL) {
			l->addTail(tmp);
w << "\n" + tmp.id + "|" + tmp.name + "|" + tmp.author + "|" + tmp.publisher + "|" + tmp.price + "|" + tmp.year + "|" + tmp.numpage + "|" + tmp.dayin + "|" + tmp.status;
			w.close();
			break;
		}
		else {
			string choice;
			cout << "Sach da ton tai" << endl;
			cout << "1. Nhap sach khac" << endl;
			cout << "2. Thoat chuong trinh" << endl;
			cout << "Hay nhap su lua chon cua ban: ";
			cin >> choice;
			if (choice == "2") {
				exit(0);
			}
			else {
				tmp.getinfor();
			}
		}
	}
}
/***************************************************
* @ Description Xoa sach khoi file text
*
* @ return None
***************************************************/
void deleteBook() {
	system("cls");
	string id;
	cout << "Nhap id cuon sach ban muon xoa: ";
	cin >> id;
	string path = "Sach.txt";
	fstream f;
	f.open(path);
	string line;
	LinkedList<Book>* l = new LinkedList<Book>();
	int flag = 0;
	while (!f.eof()) {
		getline(f, line);
		char d = '|';
		vector<string> a;
		tokenize(line, d, a);
		if (a[0] == id) {
			flag = 1;
			continue;
		}
		Book s;
		s.getfromfile(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
		l->addTail(s);
	}

	f.close();
	Node<Book>* tmp = l->_pHead->_pNext;
	fstream w;
	w.open(path, ios::out | ios::trunc);
	w << l->_pHead->_data.id + "|" + l->_pHead->_data.name + "|" + l->_pHead->_data.author + "|" + l->_pHead->_data.publisher + "|" + l->_pHead->_data.price + "|" + l->_pHead->_data.year + "|" + l->_pHead->_data.numpage + "|" + l->_pHead->_data.dayin + "|" + l->_pHead->_data.status;
	while (tmp != NULL) {
		//tmp->display();
		w << "\n" + tmp->_data.id + "|" + tmp->_data.name + "|" + tmp->_data.author + "|" + tmp->_data.publisher + "|" + tmp->_data.price + "|" + tmp->_data.year + "|" + tmp->_data.numpage + "|" + tmp->_data.dayin + "|" + tmp->_data.status;
		tmp = tmp->_pNext;
	}
	w.close();
	if(flag == 1){
		cout << "Da xoa thanh cong, vui long kiem tra lai file!";
	}
	else {
		cout << "Sach ban muon xoa khong ton tai trong csdl";
	}
}
/***************************************************
* @ Description Giao dien khi truy cap vao quan ly phieu muon
*
* @ return None
***************************************************/
void CardDisplay() {
	system("cls");
	string path = "PhieuMuon.txt";
	if (file_is_empty(path)) {
		ofstream write("PhieuMuon.txt");
		string text;
		cout << "File hien dang rong, vui long them sach vao: ";
		Book s1;
		s1.getinfor();
		text = s1.id + '\t' + s1.name;
		write << text << endl;
		write.close();
	}
	else {
		cout << "ID|ID_READER|ID_BOOK||DAY_RENT|DAY_GIVEBACK" << endl;
		fstream f;
		f.open(path);
		string line;
		while (!f.eof()) {
			getline(f, line);
			cout << line << endl;
		}
		f.close();
	}
}
/***************************************************
* @ Description Tao phieu muon
*
* @ return None
***************************************************/
void createCard() {
	string masach;
	string mabandoc;
	cout << "Vui long nhap ma sach: ";
	cin >> masach;
	cout << "Vui long nhap ma ban doc: ";
cin >> mabandoc;
	if (checkmasach(masach) && checkmabandoc(mabandoc)) {
		updatebook(masach);
		updatecard(masach, mabandoc);
		//cout << "Da update thanh cong";
	}
	else {
		cout << "Vui long kiem tra lai thong tin!";
	}

}
/***************************************************
* @ Description Tra phieu muon
*
* @ return None
***************************************************/
void returnCard() {
	string sophieumuon;
	cout << "Nhap so phieu muon: ";
	cin >> sophieumuon;
	string pathphieumuon = "PhieuMuon.txt";
	string pathsach = "Sach.txt";
	string id_sach;
	int flag = 0;
	fstream f;
	f.open(pathphieumuon);
	string line;
	LinkedList<Card>* l = new LinkedList<Card>();
	while (!f.eof()) {
		getline(f, line);
		char d = '|';
		vector<string> a;
		tokenize(line, d, a);
		if (a[0] == sophieumuon) {
			id_sach = a[1];
			a[5] = "0";
			flag = 1;
		}
		Card s;
		s.getfromfile(a[0], a[1], a[2], a[3], a[4], a[5]);
		l->addTail(s);
	}
	f.close();
	if (flag == 0) {
		cout << "Khong ton tai phieu muon ben trong csdl";
	}
	Node<Card>* tmp = l->_pHead->_pNext;
	fstream w;
	w.open(pathphieumuon, ios::out | ios::trunc);
	w << l->_pHead->_data.num + "|" + l->_pHead->_data.id_book + "|" + l->_pHead->_data.id_reader + "|" + l->_pHead->_data.day_rent + "|" + l->_pHead->_data.day_giveback + "|" + l->_pHead->_data.status;
	while (tmp != NULL) {
		//tmp->display();
		w << "\n" + tmp->_data.num + "|" + tmp->_data.id_book + "|" + tmp->_data.id_reader + "|" + tmp->_data.day_rent + "|" + tmp->_data.day_giveback + "|" + tmp->_data.status;
		tmp = tmp->_pNext;
	}
	w.close();
	// UPDATE SACH
	fstream fsach;
	fsach.open(pathsach);
	string linesach;
	LinkedList<Book>* ls = new LinkedList<Book>();
	while (!fsach.eof()) {
		getline(fsach, linesach);
		char d = '|';
		vector<string> asach;
		tokenize(linesach, d, asach);
		if (asach[0] == id_sach) {
			asach[8]="0";
		}
		Book x;
		x.getfromfile(asach[0], asach[1], asach[2], asach[3], asach[4], asach[5], asach[6], asach[7], asach[8]);
		ls->addTail(x);
	}
	fsach.close();
	Node<Book>* tmpbook = ls->_pHead->_pNext;
	fstream wsach;
	wsach.open(pathsach, ios::out | ios::trunc);
	wsach << ls->_pHead->_data.id + "|" + ls->_pHead->_data.name + "|" + ls->_pHead->_data.author + "|" + ls->_pHead->_data.publisher + "|" + ls->_pHead->_data.price + "|" + ls->_pHead->_data.year + "|" + ls->_pHead->_data.numpage + "|" + ls->_pHead->_data.dayin + "|" + ls->_pHead->_data.status;
	while (tmpbook != NULL) {
		wsach << "\n" + tmpbook->_data.id + "|" + tmpbook->_data.name + "|" + tmpbook->_data.author + "|" + tmpbook->_data.publisher + "|" + tmpbook->_data.price + "|" + tmpbook->_data.year + "|" + tmpbook->_data.numpage + "|" + tmpbook->_data.dayin + "|" + tmpbook->_data.status;
		tmpbook = tmpbook->_pNext;
	}
	wsach.close();
}
/***************************************************
* @ Description Kiem tra xem id sach nhap vao co kha thi khong
*
* @ return book (1-co, 2-khong)
***************************************************/
bool checkmasach(string masach) {
	string path = "Sach.txt";
	fstream f;
	f.open(path);
	string line;
	LinkedList<Book>* l = new LinkedList<Book>();
	while (!f.eof()) {
		getline(f, line);
		char d = '|';
		vector<string> a;
		tokenize(line, d, a);
		if (a[0] == masach && a[8] == "0") {
			return true;
		}
		Book s;
		s.getfromfile(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
		l->addTail(s);
	}
	f.close();
	return false;
}
/***************************************************
* @ Description Kiem tra xem id ban doc nhap vao co kha thi khong
*
* @ return book (1-co, 2-khong)
***************************************************/
bool checkmabandoc(string mabandoc) {
	string path = "BanDoc.txt";
	fstream f;
	f.open(path);
	string line;
	LinkedList<Reader>* l = new LinkedList<Reader>();
	while (!f.eof()) {
		getline(f, line);
		char d = '|';
		vector<string> a;
		tokenize(line, d, a);
		if (a[0] == mabandoc) {
			return true;
		}
		Reader s;
		s.getfromfile(a[0], a[1], a[2]);
		l->addTail(s);
	}
	f.close();
	return false;
}
/***************************************************
* @ Description Update lai fiel Sach sau khi tao phieu muon
*
* @ return None
***************************************************/
void updatebook(string masach) {
	string path = "Sach.txt";
	fstream f;
	f.open(path);
	string line;
	LinkedList<Book>* l = new LinkedList<Book>();
	while (!f.eof()) {
		getline(f, line);
		char d = '|';
		vector<string> a;
		tokenize(line, d, a);
		if (a[0] == masach) {
			a[8] = "1";
		}
		Book s;
		s.getfromfile(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
		l->addTail(s);
	}
	f.close();
	Node<Book>* tmp = l->_pHead->_pNext;
	fstream w;
	w.open(path, ios::out | ios::trunc);
	w << l->_pHead->_data.id + "|" + l->_pHead->_data.name + "|" + l->_pHead->_data.author + "|" + l->_pHead->_data.publisher + "|" + l->_pHead->_data.price + "|" + l->_pHead->_data.year + "|" + l->_pHead->_data.numpage + "|" + l->_pHead->_data.dayin + "|" + l->_pHead->_data.status;
	while (tmp != NULL) {
		//tmp->display();
		w << "\n" + tmp->_data.id + "|" + tmp->_data.name + "|" + tmp->_data.author + "|" + tmp->_data.publisher + "|" + tmp->_data.price + "|" + tmp->_data.year + "|" + tmp->_data.numpage + "|" + tmp->_data.dayin + "|" + tmp->_data.status;
		tmp = tmp->_pNext;
	}
	w.close();
}
/***************************************************
* @ Description Update lai file PhieuMuon sau khi tao phieu muon
*
* @ return None
***************************************************/
void updatecard(string masach, string mabandoc) {
	string path = "PhieuMuon.txt";
	fstream f;
	f.open(path);
	string line;
	LinkedList<Card>* l = new LinkedList<Card>();
	while (!f.eof()) {
		getline(f, line);
		char d = '|';
		vector<string> a;
		tokenize(line, d, a);
		Card s;
		s.getfromfile(a[0], a[1], a[2], a[3], a[4], a[5]);
		l->addTail(s);
	}
	f.close();
	fstream w;
	w.open("PhieuMuon.txt", ios::app);
w << "\n" + to_string(l->_iSize+1) + "|" + masach + "|" + mabandoc + "|" + getday() + "/" + getmon() + "/" + getyear() + "|" + getback(getday(), getmon(), getyear()) + "|" + "1";
	w.close();
}
