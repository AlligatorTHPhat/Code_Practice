#include <iostream>

using namespace std;

int array_size = 0, values[100];

void input(int& array_size, int values[]) {
	int tmp;
	while (cin >> tmp) {
		values[array_size++] = tmp;
	} return;
}

int Partition(int values[], int start, int end) {
	int pivot = values[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (values[i] <= pivot)
			count++;
	}

	int pivot_Index = start + count;
	swap(values[pivot_Index], values[start]);

	int i = start, j = end;

	while (i<pivot_Index && j>pivot_Index) {
		while (values[i] < pivot) {
			i++;
		}

		while (values[j] > pivot) {
			i--;
		}

		if (i < pivot_Index && j >pivot_Index) {
			swap(values[i++], values[j--]);
		}
	}
	return pivot_Index;
}

void Quick_Sort(int values[], int left, int right) {
	if (left < right) {
		int pivot = Partition(values, left, right);
		Quick_Sort(values, left, right - 1);
		Quick_Sort(values, left + 1, right);
	}
}

int main() {
	input(array_size, values);

	Quick_Sort(values, 0, array_size - 1);

	for (int i = 0; i < array_size; i++) {
		cout << values[i] << " ";
	}

	return 0;
}
