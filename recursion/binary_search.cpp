// binary search
#include <iostream>

int bsearch(const int* a, const int& n, const int& e, int i = 0) {
	if (n == 1)
		return *a == e ? i : -1;
	else {
		int m = n / 2;
		if (e < a[m])
			return bsearch(a, m, e, i);
		else if (e > a[m])
			return bsearch(a + m + 1, n - m - 1, e, i + m + 1);
		else
			return i + m;
	}
}

int main() {
	int n;
	std::cout << "Enter size of the array: ";
	if (std::cin >> n && n > 0) {
		int* a = new int[n];
		std::cout << "Enter the elements in increasing order: ";
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];
		int e;
		std::cout << "Enter the element to search: ";
		std::cin >> e;
		
		int i = bsearch(a, n, e);
		if (i > -1) {
		       std::cout << "Element found at index "
			       << i << "." << std::endl;
		} else {
			std::cout << "Element not found." << std::endl;
		}

		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
