#include <iostream>
using namespace std;

template <typename DataType>

/*
void swap(dataptype& a, datatype& b) {
        datatype temp = a;
        a = b;
        b = temp;
        return;
}
*/

void input(int& n, DataType values[])
{
    n = 0;
    int temp;
    while (cin >> temp)
    {
        values[n++] = temp;
    }
}

template <typename DataType>
void selection_sort(int n, DataType values[])
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[min])
            {
                min = j;
            }
        }
        swap(values[i], values[min]);
    }
}

template <typename DataType>
void interchange_sort(int n, DataType values[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[i])
            {
                swap(values[j], values[i]);
            }
        }
    }
}

template <typename DataType>
void bubble_sort(int n, DataType values[])
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (values[j + 1] < values[j])
            {
                swap(values[j + 1], values[j]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

template <typename DataType>
int partition(int start, int end, DataType values[])
{
    DataType pivot = values[start];

    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (values[i] <= pivot)
            count++;
    }

    int pivot_index = start + count;

    swap(values[pivot_index], values[start]);

    int i = start, j = end;

    while (i<pivot_index && j >pivot_index)
    {
        while (values[i] < pivot)
            i++;
        while (values[j] > pivot)
            j--;
        if (i < pivot_index && j > pivot_index)
            swap(values[i++], values[j--]);
    }

    return pivot_index;
}

template <typename DataType>
void quick_sort(int left, int right, DataType values[])
{
    if (left < right)
    {
        int pivot = partition(left, right, values);
        quick_sort(left, right - 1, values);
        quick_sort(left + 1, right, values);
    }
}

template <typename DataType>
void print_result(int n, DataType values[])
{
    // selection_sort(n, values);
    // interchange_sort(n, values);
    //bubble_sort(n, values);
    quick_sort(0, n - 1, values);

    for (int i = 0; i < n; i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, values[100];
    input(n, values);
    print_result(n, values);
    return 0;
}
