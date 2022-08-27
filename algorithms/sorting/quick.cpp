// quick sort

/* note: for randomized quick sort,
 * uncomment the following */
// #include <algorithm>
// #include <random>
#include <iostream>

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int partition(int* a, int& n, int pivot = 0) {
	int i = 0, j = 1;
	swap(a[pivot], a[0]); // brings pivot to beginning
	while (j < n) {
		if (a[0] < a[j]) {
			++j;
		} else {
			swap(a[i+1], a[j]);
			++i;
			++j;
		}
	}
	swap(a[0], a[i]);

	return i;
}

void qsort(int* a, int size) {
	if (size > 1) {
		// partition
		int i = partition(a, size);

		// divide
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
		
		// (for randomized quick sort)
		/* randomly shuffling the array
		 * and picking the first element as 
		 * pivot everytime can be thought of
		 * as choosing the pivot at random */
		// std::random_device rd;
    		// std::mt19937 g(rd());
		// std::shuffle(a, a + n, g);
		
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
