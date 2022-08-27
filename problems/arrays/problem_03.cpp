// Problem:
/*
 * Generate all possible sub-arrays of a given array.
 */

// Solution:
/*
 * approach: bruteforce
 * running time: cubic
 */

# include <iostream>

int main() {
	int size;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> size && size > 0) {
		int* a = new int[size];

		std::cout << "Enter the elements: ";
		for (int i = 0; i < size; ++i)
			std::cin >> a[i];

		std::cout << "All possible sub-arrays of the given array are:" << std::endl;
		for (int i = 0; i < size; ++i) {
			for (int j = i; j < size; ++j) {
				std::cout << "[ ";
				for (int k = i; k <= j; ++k)
					std::cout << a[k] << " ";
				std::cout << "]" << std::endl;
			}
		}
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
