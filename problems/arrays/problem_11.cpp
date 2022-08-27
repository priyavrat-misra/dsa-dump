// Problem:
/*
 * Given an array, move all negative numbers to beginning and positive to end with constant extra space.
 * 
 * source: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
 */

// Solution:
/*
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
		std::cout << "Enter the elements: ";
		for (int i = 0; i < s; ++i)
			std::cin >> a[i];

		int l = 0, r = s-1;
		while (l < r) {
			if (a[l] > 0 && a[r] < 0) {
				swap(a[l], a[r]);
				++l;
				--r;
			} else if (a[l] < 0 && a[r] < 0) {
				++l;
			} else if (a[l] > 0 && a[r] > 0) {
				--r;
			} else {
				++l;
				--r;
			}
		}

		std::cout << "Resultant array: ";
		for (int i = 0; i < s; ++i)
			std::cout << a[i] << " ";
		
		std::cout << std::endl;
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
