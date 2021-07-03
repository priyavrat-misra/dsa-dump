// quick sort
#include <iostream>

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void qsort(int* a, int size) {
	if (size > 1) {
		int i = 0, j = 1, pivot = 0;
		while (j < size) {
			if (a[pivot] < a[j]) {
				++j;
			} else {
				swap(a[i+1], a[j]);
				++i;
				++j;
			}
		}
		swap(a[pivot], a[i]);

		qsort(a, i);
		qsort(a + i + 1, size - i - 1);
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

		qsort(a, n);
		
		std::cout << "The sorted array:";
		for (int i = 0; i < n; ++i)
			std::cout << " " << a[i];
		std::cout << std::endl;

		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
