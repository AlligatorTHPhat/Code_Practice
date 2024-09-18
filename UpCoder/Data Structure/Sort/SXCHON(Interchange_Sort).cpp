#include <iostream>

using namespace std;

int values[100], array_size = 0;

void input(int values[], int& array_size) {
	int tmp;
	while (cin >> tmp) {
		values[array_size++] = tmp;
	} return;
}

void Interchange_Sort(int values[], int array_size){	
    for (int i = 0; i < array_size - 1; i++)
        for (int j = i + 1; j < array_size; j++)
	        if(values[i] > values[j])  
		        swap(values[i], values[j]);
}

int main() {
	input(values, array_size);
	Interchange_Sort(values, array_size);

	for (int i = 0; i < array_size; i++) {
		cout << values[i] << " ";
	} return 0;
}
