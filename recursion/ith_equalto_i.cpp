// given a sorted array a, find if there exist some element
// whose value is same as it's index (a[i] == i)
#include <iostream>

int find_i(int* a, int n, int e) {
	if (n == 1) {
		return *a == e ? e : -1;
	} else {
		int m = n / 2;
		e += m;
		if (e < a[m])
			return find_i(a, m, e - m);
		else if (e > a[m])
			return find_i(a + m, n - m, e);
		else
			return e;
	}
}

int main() {
	int n;
	std::cout << "Enter size of the array: ";
	if (std::cin >> n && n > 0) {
		int* a = new int[n];
		std::cout << "Enter the element(s): ";
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];

		int i = find_i(a, n, 0);
		if (i > -1) {
			std::cout << "Element found at position "
				<< i << "." << std::endl;
		} else {
			std::cout << "No such element found."
				<< std::endl;
		}
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
