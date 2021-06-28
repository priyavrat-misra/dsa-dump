// given a sorted array a, find if there exists some element
// whose value is same as it's index (a[i] == i)
#include <iostream>

int find_i(int* a, int n, int i) {
	if (n == 1) {
		return *a == i ? i : -1;
	} else {
		int m = n / 2;
		i += m;
		if (i < a[m])
			return find_i(a, m, i - m);
		else if (i > a[m])
			return find_i(a + m, n - m, i);
		else
			return i;
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
