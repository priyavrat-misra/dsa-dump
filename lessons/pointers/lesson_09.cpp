// Arrays as function arguments
#include <iostream>

void Double(int* A, int size) {
	for (int i = 0; i < size; ++i)
		A[i] *= 2;
}

int main() {
	int A[] = {1, 2, 3, 4, 5};
	int size = sizeof(A) / sizeof(int);
	Double(A, size);
	for (int i = 0; i < size; ++i)
		std::cout << A[i] << "\t";

	std::cout << std::endl;
}
