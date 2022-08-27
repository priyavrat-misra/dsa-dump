// find the index of 1st ocuurance of a given element in an array
#include <iostream>

int first_occ(int* a, int n, const int& e) {
	if (n == 0)
		return -1;
	else {
		if (*a == e)
			return 0;
		else {
			int i = first_occ(a + 1, n - 1, e);
			return i == -1 ? -1 : i + 1;
		}
	}
}

int main() {
	int n;
	std::cout << "Enter size of the array: ";
	if (std::cin >> n && n > 0) {
		int* a = new int[n];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];

		int e;
		std::cout << "Enter the element to search: ";
		std::cin >> e;
		int i = first_occ(a, n, e);
		if (i > -1) {
			std::cout << e << " first appears at index "
				<< i << "." << std::endl;
		} else {
			std::cout << "Element not found."
				<< std::endl;
		}
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
