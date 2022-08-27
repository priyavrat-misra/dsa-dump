// Problem:
/*
 * Given an array and a number K where K is smaller than size of array,
 * the task is to find the Kth smallest element in the given array.
 * It is given that all array elements are distinct.
 * 
 * source: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
 */

// Solution (not optimal):
/*
 * optimal solution: "../recursion/quick_select.cpp"
 * approach: sorting
 * running time: quadratic (linearitmic if quick or merge sort is used)
 */

#include <iostream>

void isort(int a[], int& s) {
	int j, key;
	for (int i = 1; i < s; ++i) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = key;
	}
}

int main() {
	int s;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> s && s > 0) {
		int* a = new int[s];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < s; ++i)
			std::cin >> a[i];

		int k;
		std::cout << "Enter k: ";
		if (std::cin >> k && k > -1 && k < s) {
			isort(a, s);
			std::cout << "kth smallest number is: " << a[k] << std::endl;
		} else {
			std::cout << "k out of range [0, " << s << ")" << std::endl;
		}
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
