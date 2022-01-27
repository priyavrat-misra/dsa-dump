#include <iostream>

int max(int* a, int& n) {
	int max = a[0];
	for (int i = 1; i < n; ++i) {
		if (max < a[i])
			max = a[i];
	}
	return max;
}

void count_sum(int* a, int& n, int* c, int& m) {
	for (int i = 0; i < n; ++i)
		++c[a[i]];

	for (int i = 1; i < m; ++i)
		c[i] += c[i-1];
}

int* csort(int* a, int& n, int* c, int& m) {
	int* b = new int[n];
	for (int i = n - 1; i >= 0; --i)
		b[--c[a[i]]] = a[i];
	
	delete[] a;
	delete[] c;
	return b;
}

int main() {
	int n;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> n && n > 0) {
		int* a = new int[n];
		std::cout << "Enter the elements (+ve numbers only): ";
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];
		
		int m = max(a, n) + 1;
		int* c = new int[m]{0};
		count_sum(a, n, c, m);
		a = csort(a, n, c, m);
		
		std::cout << "Sorted array:";
		for (int i = 0; i < n; ++i)
			std::cout << " " << a[i];
		std::cout << std::endl;

		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
