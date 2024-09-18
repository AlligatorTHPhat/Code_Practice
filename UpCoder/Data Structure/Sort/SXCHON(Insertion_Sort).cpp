#include <iostream>

using namespace std;

int values[100], array_size = 0;

void input(int values[], int& array_size) {
	int tmp;
	while (cin >> tmp) {
		values[array_size++] = tmp;
	} return;
}

void Insertion_Sort(int values[], int array_size)
{
    for (int i = 1; i < array_size; ++i) {
        int key = values[i];
        int j = i - 1;

        while (j >= 0 && values[j] > key) {
            values[j + 1] = values[j];
            j = j - 1;
        }
        values[j + 1] = key;
    }
}

int main() {
	input(values, array_size);
	Insertion_Sort(values, array_size);

	for (int i = 0; i < array_size; i++) {
		cout << values[i] << " ";
	} return 0;
}
