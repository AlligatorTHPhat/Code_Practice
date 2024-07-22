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
	int tmp;
	while (cin >> tmp) {
		values[array_size++] = tmp;
	} return;
}

void Selection_Sort(int values[], int array_size) {
	int i, j, min, tmp;
	for (int i = 0; i < array_size - 1; i++) {
		min = i;
		for (int j = i + 1; j < array_size; j++) {
			if (values[j] < values[min])
				min = j;
		}	
		swap(values[i], values[min]);
	}
	return;
}

int main() {
	input(values, array_size);
	Selection_Sort(values, array_size);

	for (int i = 0; i < array_size; i++) {
		cout << values[i] << " ";
	} return 0;
}

