#include <iostream>

using namespace std;

int values[100], array_size = 0;

/*
void swap(dataptype& a, datatype& b) {
		datatype temp = a;
		a = b;
		b = temp;
		return;
}
*/

void input(int values[], int& array_size) {
	cin >> array_size;
	for (int i = 0; i < array_size; i++) {
		cin >> values[i];
	} return;
}

void Insertion_Sort(int values[], int array_size) {
	for (int i = 1; i < array_size / 2; i++) {
		int j = i;
		while ((j > 0) && (values[j - 1] > values[j])) {
			swap(values[j - 1], values[j]);
			j--;
		}
	} return;
}

void Reverse_Insertion(int values[], int array_size) {
	int start = ((array_size + 1) / 2);
	for (int i = start + 1; i < array_size; i++) {
		int j = i;
		while ((j > start) && (values[j - 1] < values[j])) {
			swap(values[j - 1], values[j]);
			j--;
		}
	} return;
}

int main() {
	input(values, array_size);
	Insertion_Sort(values, array_size);
	Reverse_Insertion(values, array_size);

	for (int i = 0; i < array_size; i++) {
		cout << values[i] << " ";
	} return 0;
}

