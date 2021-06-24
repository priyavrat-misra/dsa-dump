// find the duplicate number
/* source: https://leetcode.com/problems/find-the-duplicate-number/
 * approach: sorting
 * running time: quadratic
 */
#include <iostream>

void isort(int* a, int& n) {
	int j, key;
	for (int i = 1; i < n; ++i) {
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
	int n;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> n && n > 0) {
		int* a = new int[n];
		std::cout << "Enter " << n << " number(s): ";

		for (int i = 0; i < n; ++i)
			std::cin >> a[i];
		
		isort(a, n);

		for (int i = 0; i < n-1; ++i) {
			if (a[i] == a[i+1]) {
				std::cout << a[i] << " is the duplicate." << std::endl;
				delete[] a;
				exit(0);
			}
		}
		std::cout << "No duplicates found." << std::endl;
		delete[] a;
	} else {
		std::cerr << "Size must be positive" << std::endl;
	}
}