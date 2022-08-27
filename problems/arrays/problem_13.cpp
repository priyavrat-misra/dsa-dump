// Problem:
/*
 * Given an array, cyclically rotate it by k.
 */

// Solution:
/*
 * approach: reverse and rotate
 * running time: linear
 */

#include <iostream>

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void reverse(int* a, int n) {
	int i = 0, j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		++i;
		--j;
	}
}

int main() {
	int s;
	std::cout << "Enter the size: ";
	if (std::cin >> s && s > 0) {
		int* a = new int[s];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < s; ++i)
			std::cin >> a[i];
		
		int k;
		std::cout << "Enter number of positions to be rotated: ";
		std::cin >> k;
		
		std::cout << "The " << k << " rotated array is:";
		reverse(a, s);
		reverse(a, s - k);
		reverse(a + s - k, k);
		for (int i = 0; i < s; ++i)
			std::cout << " " << a[i];
		std::cout << std::endl;

		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
