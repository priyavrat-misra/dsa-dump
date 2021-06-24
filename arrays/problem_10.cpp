// Sort a given array containing 0s, 1s and 2s.
/*
 * source: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
 * aka Dutch national flag problem
 * approach: two pointers
 * running time: linear
 */
#include <iostream>

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int main() {
	int s;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> s && s > 0) {
		int* a = new int[s];
		std::cout << "Enter the elements (0, 1, 2): ";
		for (int i = 0; i < s; ++i)
			std::cin >> a[i];

		int low = 0, mid = 0, high = s-1;
		while (mid <= high) {
			switch (a[mid]) {
				case 0:
					swap(a[low], a[mid]);
					++low;
					++mid;
					break;
				case 1:
					++mid;
					break;
				case 2:
					swap(a[mid], a[high]);
					--high;
					break;
				default:
					std::cout << "Number other than 0, 1 or 2 found." << std::endl;
					delete[] a;
					exit(0);
			}
		}

		std::cout << "The sorted array:";
		for (int i = 0; i < s; ++i)
			std::cout << " " << a[i];
		
		std::cout << std::endl;
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
