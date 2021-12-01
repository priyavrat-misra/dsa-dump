// Function pointer application in stdlib qsort
#include <iostream>
#include <cstdlib>

int compare(const void* a, const void* b) {
	return *((int*) a) - *((int*) b);
}

int main() {
	int A[] = {-31, 22, -1, 50, -6, 4};
	qsort(A, 6, sizeof(int), compare);
	for (int i = 0; i < 6; ++i)
		std::cout << A[i] << '\t';
	std::cout << std::endl;	
}
