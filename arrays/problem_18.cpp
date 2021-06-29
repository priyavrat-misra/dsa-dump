// Problem:
/*
 * Given an array, return an array where each index stores the product
 * of all numbers in the array except the number at the index itself.
 */

// Solution:
/* 
 * approach: running product
 * running time: linear
 */

#include <iostream>

int main() {
	int n;
	std::cout << "Enter size of the array: ";
	if (std::cin >> n && n > 0) {
		int* a = new int[n];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];

		int* b = new int[n];
		int i = 0, temp = 1;
		while (i < n) {
			b[i] = temp;
			temp *= a[i++];
		}
		
		temp = 1;
		while (i--) {
			b[i] = temp * b[i];
			temp *= a[i];
		}

		std::cout << "Array of products:";
		for (int i = 0; i < n; ++i)
			std::cout << " " << b[i];
		
		std::cout << std::endl;
		
		delete[] a;
		delete[] b;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
