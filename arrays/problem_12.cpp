// Problem:
/*
 * Find union and intersection of two given sorted arrays.
 * 
 * source: https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/
 */

// Solution:
/*
 * approach: two pointers
 * running time: linear
 */

#include <iostream>

void fill(int* arr, int& s) {
	for (int i = 0; i < s; ++i)
		std::cin >> arr[i];
}

void uniontwo(int* a, int* b, int& m, int& n) {
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (a[i] < b[j])
			std::cout << " " << a[i++];
		else if (a[i] > b[j])
			std::cout << " " << b[j++];
		else {
			std::cout << " " << a[i];
			++i;
			++j;
		}
	}
	
	while (i < m)
		std::cout << " " << a[i++];
	while (j < n)
		std::cout << " " << b[j++];
	
	std::cout << std::endl;
}
	
void intertwo(int* a, int* b, int& m, int& n) {
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (a[i] < b[j])
			++i;
		else if (a[i] > b[j])
			++j;
		else {
			std::cout << " " << b[j];
			++i;
			++j;
		}
	}
	std::cout << std::endl;
}

int main() {
	int m, n;
	std::cout << "Enter sizes for 2 sorted arrays: ";
	if (std::cin >> m >> n && m > 0 && n > 0) {
		int* a = new int[m]; 
		int* b = new int[n];
		
		std::cout << "Enter elements for the first array: ";
		fill(a, m);
		
		std::cout << "Enter elements for the second array: ";
		fill(b, n);
		
		std::cout << "The union of the two arrays is:";
		uniontwo(a, b, m, n);
		
		std::cout << "The intersection of the two arrays is:";
		intertwo(a, b, m, n);
		
		delete[] a;
		delete[] b;
	} else {
		std::cerr << "Sizes must be positive." << std::endl;
	}
}
