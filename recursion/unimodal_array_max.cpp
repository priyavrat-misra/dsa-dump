// max element in an unimodal array with logarithmic running time
#include <iostream>

int umax(int* a, int n) {
	if (n > 1) {
		int m = n / 2;
		return a[m-1] < a[m] ? umax(a+m, n-m) : umax(a, m);
	} else {
		return *a;
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
		std::cout << "Max element: " << umax(a, n) << std::endl;
		delete[] a;
	} else {
		std::cout << "Size must be positive." << std::endl;
	}
}
