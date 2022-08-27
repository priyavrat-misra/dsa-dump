// Problem:
/*
 * Given an array, find it's maximum and minimum.
 */

// Solution:
/*
 * approach: comparison within pairs
 * running time: linear
 * approx number of comparisons: 1.5 * n
 */

#include <iostream>

inline int min(int& a, int& b) {
	return a < b ? a : b;
}

inline int max(int& a, int& b) {
	return a > b ? a : b;
}

int main() {
	int size;
	
	std::cout << "Enter the size of the array: ";
	if (std::cin >> size && size > 1) {
		int* arr = new int[size];
	
		std::cout << "Enter the elements: ";
		for (int i = 0; i < size; ++i)
			std::cin >> arr[i];
		
		int smallest, largest, i;
		if (size % 2) {
			i = 1;
			smallest = arr[0];
			largest = arr[0];
		} else {
			i = 2;
			smallest = min(arr[0], arr[1]);
			largest = max(arr[0], arr[1]);
		}
		while (i < size) {
			int cmin = min(arr[i], arr[i+1]);
			int cmax = max(arr[i], arr[i+1]);
			smallest = min(smallest, cmin);
			largest = max(largest, cmax);
			i += 2;
		}

		std::cout << "Largest element: " << largest << std::endl;
		std::cout << "Smallest element: " << smallest << std::endl;
		delete[] arr;
	} else {
		std::cerr << "Size must be at least 2." << std::endl;
	}
}
