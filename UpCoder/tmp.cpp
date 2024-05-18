#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <iomanip>

using namespace std;

class Student {
	char* name;
	int boy;
	float mark[3];

	float avg_mark() {
		return (mark[0] + mark[1] + mark[2]) / 3;
	}

	friend istream& operator >> (istream& is, Student& st) {
		st.name = new char[100];
		is.ignore();
		fgets(st.name, 100, stdin);
		st.name[strcspn(st.name, "\n")] = ' ';
		is >> st.name;
		for (int i = 0; i < 3; i++)
			is >> st.mark[i];
			return is;
	}

	friend ostream& operator << (ostream& os, Student st) {
		os << fixed << setprecision(2);
		os << st.name << " - " << st.boy << " - " << st.avg_mark();
		return os;
	}
};

void input_array_Student(Student* list, int n) {
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
}

void list_decrease(Student *list, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (list[i].avg_mark() < list[j].avg_mark()) swap(list[i], list[j]);
		}
	}
}

void print_list_Student(Student* list, int n) {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " - " << list[i];
	}
}

int main() {
	int n; cin >> n;
	Student* list = new Student[n];
	input_array_Student(list, n);
	list_decrease(list, n);
	print_list_Student(list, n);

	or (int i = 0; i < n; ++i)
		delete[] list[i].name;
	return 0;
}
