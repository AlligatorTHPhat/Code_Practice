#include <iostream>

using namespace std;

int values[100], array_size = 0;

void input(int values[], int& array_size) {
	int tmp;
	while (cin >> tmp) {
		values[array_size++] = tmp;
	} return;
}

void Bubble_Sort(int values[], int array_size)
{
    int i, j;
    bool swapped;
    for (i = 0; i < array_size - 1; i++) {
        swapped = false;
        for (j = 0; j < array_size - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                swap(values[j], values[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main() {
	input(values, array_size);
	Bubble_Sort(values, array_size);

	for (int i = 0; i < array_size; i++) {
		cout << values[i] << " ";
	} return 0;
}
