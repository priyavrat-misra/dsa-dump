// Pointers and Arrays
#include <iostream>

int main() {
	int A[] = {2, 4, 5, 1, 9};
	std::cout << "*A = " << *A << std::endl;  // 2
	std::cout << "A = " << A << std::endl;  // base address
	std::cout << "------------------" << std::endl;
	std::cout << "ways to access elements:" << std::endl;
	// address of 3rd element
	std::cout << "A+2 = " << A+2 << std::endl;
	std::cout << "&A[2] = " << &A[2] << std::endl;
	// value of 3rd element
	std::cout << "*(A+2) = " << *(A+2) << std::endl;
	std::cout << "A[2] = " << A[2] << std::endl;
}
