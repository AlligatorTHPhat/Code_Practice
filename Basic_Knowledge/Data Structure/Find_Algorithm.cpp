//Phép toán đổi chỗ: Là phép toán đảo giá trị 2 biến
void swap(datatype &a, datatype &b) {
datatype temp = a; //datatype-kiểu dữ liệu của phần tử
    a = b;
    b = temp;
}
//Phép toán so sánh: Trả về true nếu a > b và trả về false cho trường hợp ngược lại.
compare(datatype a, datatype b) {
    if (a > b) {
        return true;
    } else {
        return false;
    }
}
//Sắp xếp chèn (Insertion Sort)
void insertionSort(int a[], int array_size) {
    int i, j, last;
    for (i=1; i < array_size; i++) {
        last = a[i];
        j = i;
    while ((j > 0) && (a[j-1] > last)) {
        a[j] = a[j-1];
        j = j - 1; }
        a[j] = last;
    } // end for
} // end of isort
//Sắp xếp lựa chọn (Selection Sort)
void selectionSort(int a[], int n){
    int i, j, min, temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++){
            if (a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}
//Sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int a[], int n){
    int i, j;
    for (i = (n-1); i >= 0; i--) {
        for (j = 1; j <= i; j++){
            if (a[j-1] > a[j])
            swap(a[j-1],a[j]);
        }
    }
} 
//Sắp xếp trộn (merge sort) là một thuật toán sắp xếp loại so sánh
MERGE-SORT(A, p, r)
    if p < r 
        then q ← (p + r)/2 // Chia (Divide)
            MERGE-SORT(A, p, q) // Trị (Conquer)
            MERGE-SORT(A, q + 1, r) // Trị (Conquer)
            MERGE(A, p, q, r) // Tổ hợp (Combine)
    endif
//Giả sử có hai dãy đã được sắp xếp L[1..𝑛1] và R[1..n2]. Ta có thể trộn chúng lại thành một dãy mới M[1..n1+n2] được sắp xếp theo cách sau:  
//Khi đó, ta sẽ thu được dãy cần tìm.
MERGE(M, p, q, r)
    // Sao n1 phần tử đầu tiên vào L[1 . . n1] và n2 phần tử tiếp theo vào R[1 . . n2]
    // L[n1 + 1] ← infty; R[n2 + 1] ← infty
    i ← 1; j ← 1
    for k ← p to r do
        if L[ i ] ≤ R[ j ]
        then
            M[k] ← L[ i ]
            i ←i + 1
        else
            M[k] ← R[ j ]
            j ← j + 1
//Quick Sort (QS)
  Quick-Sort(A, Left, Right)
    if (Left < Right ) {
        Pivot = Partition(A, Left, Right);
        Quick-Sort(A, Left, Pivot – 1);
        Quick-Sort(A, Pivot + 1, Right); }
//Heap (đống) là cây nhị phân gần hoàn chỉnh có hai tính chất:
// Tính cấu trúc (Structural property): tất cả các mức đều đầy đủ node con, ngoại trừ mức cuối cùng. Mức cuối được điền từ trái sang phải.
// Tính có thứ tự hay tính chất đống (heap property): với mỗi nút x, có Parent(x) ≥ x.
// Biểu diễn đống dưới dạng mảng, ta có:

// Gốc của cây là A[1]
// Con trái của A[i] là A[2i]*
// Con phải của A[i] là A[2i + 1]*
// Cha của A[i] là A[ i/2 ]
// Số lượng phần tử của heap là Heapsize[A] ≤ length[A]
// Phân loại: Có 2 loại

// Max-heaps (Phần tử lớn nhất ở gốc): với mọi nút i, ngoại trừ gốc: A[parent(i)] ≥ A[i]
// Min-heaps (Phần tử nhỏ nhất ở gốc): với mọi nút i, ngoại trừ gốc: A[parent(i)] ≤ A[i]
Max-Heapify(A, i, n)
    // n = heapsize[A]
    l ← left-child(i); r ← right-child(i);
    if (l ≤ n) and (A[l] > A[i])
        then largest ← l
        else largest ← i
    if (r ≤ n) and (A[r] > A[largest])
        then largest ← r
    if largest != i
        then Exchange(A[i],A[largest])
    Max-Heapify(A,largest,n)
//Thuật toán Heapsort
Build-Max-Heap(A)
    n = length[A]
    for i ← n/2 downto 1
        do Max-Heappify(A, i, n)



