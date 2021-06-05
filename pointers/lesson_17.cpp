// Function pointer application
#include <iostream>
#include <cmath>

bool compare(int& a, int& b) {
	return a>b;
}

bool abs_compare(int& a, int& b) {
	return abs(a)>abs(b);
}

void bubblesort(int *A, int n, bool (*cmp)(int&, int&)) {
	int temp;
	for (int i=0; i<n-1; ++i) {
		for (int j=0; j<n-i-1; ++j) {
			if (cmp(A[j], A[j+1])) {
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

void print(int *arr, int n) {
	for(int i=0; i<n; ++i)
		std::cout << arr[i] << "\t";
	std::cout << std::endl;
}

int main() {
	int A[] = {3, 2, 6, 5, 1, 4}, size;
	size = sizeof(A)/sizeof(int);
	bubblesort(A, size, compare);
	print(A, size);
	
	int B[] = {-21, -1, -9, 3, 64, -49, 20};
	size = sizeof(B)/sizeof(int);
	bubblesort(B, size, abs_compare);
	print(B, size);
}
