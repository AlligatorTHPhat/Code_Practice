#include <iostream>

using namespace std;

int array_size, values[100];

/*
void swap(dataptype& a, datatype& b) {
		datatype temp = a;
		a = b;
		b = temp;
		return;
}
*/

void input(int& array_size, int values[]) {
	cin >> array_size;
	for (int i = 0; i < array_size; i++) {
		cin >> values[i];
	} return;
}

void Insertion_Sort(int array_size, int values[]) {
	int j;
	for (int i = 1; i < array_size / 2; i++) {
		j = i;
		while ((j > 0) && (values[j - 1] > values[j])) {
			swap(values[j - 1], values[j]);
			j--;
		} 
	} return;
}

void Reverse_Sort(int array_size, int values[]) {
	int start = (array_size + 1) / 2, j;
	for (int i = start + 1; i < array_size; i++) {
		j = i;
		while ((j > start) && (values[j - 1] < values[j])) {
			swap(values[j - 1], values[j]);
			j--;
		}
	} return;
}

void output(int array_size, int values[]) {
	for (int i = 0; i < array_size; i++)
		cout << values[i] << " ";
	return;
}

int main() {
	input(array_size, values);
	Insertion_Sort(array_size, values);
	Reverse_Sort(array_size, values);
	output(array_size, values);
	
	return 0;
}
