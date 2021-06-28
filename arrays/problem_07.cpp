// Problem:
/*
 * Given a sorted array, find pairs which sum to k.
 */

// Solution:
/*
 * approach: two pointers
 * running time: linear
 */

#include <iostream>

int main() {
	int size, i, j, s, k;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> size && size > 0) {
		int* a = new int[size];
		std::cout << "Enter the elements: ";
		for(int i = 0; i < size; i++)
			std::cin >> a[i];
		i = 0;
		j = size - 1;
		std::cout << "Enter k: ";
		std::cin >> k;
		std::cout << "Pairs which sum to k:" << std::endl;

		while (i < j) {
			s = a[i] + a[j];
			if (s < k)
				++i;
			else if (s > k)
				--j;
			else{
				std::cout << "[ " << a[i] << ", " << a[j] << " ]" << std::endl;
				++i;
				--j;
			}
		}
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
