// find the index of last ocuurance of a given element in an array
#include <iostream>

int last_occ(int* a, int n, const int& e) {
	if (n == 0)
		return -1;
	else {
		int i = last_occ(a + 1, n - 1, e);
		if (i == -1)
			return *a == e ? 0 : -1;
		else
			return i + 1;
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
		int i = last_occ(a, n, e);
		if (i > -1) {
			std::cout << "Last occurance of " << e
				<< " found at index " << i << "." 
				<< std::endl;
		} else {
			std::cout << "Element not found."
				<< std::endl;
		}
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
