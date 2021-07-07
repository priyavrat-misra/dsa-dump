// quick select

/* note: for randomized quick select,
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

int qselect(int* a, int n, int k) {
	if (n == 1) {
		return *a;
	} else {
		// partition
		int i = partition(a, n);

		// divide
		if (i > k)
			return qselect(a, i, k);
		else if (i < k)
			return qselect(a + i + 1, n - i - 1, k - i - 1);
		else
			return a[i];
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
		
		int k;
		while (true) {
			std::cout << "Enter the required smallest element: ";
			if (std::cin >> k && k > 0 && k <= n)
				break;
			else
				std::cerr << "Out of range. Try Again." << std::endl;
		}
		// (for randomized quick select)
		/* randomly shuffling the array
		 * and picking the first element as 
		 * pivot everytime can be thought of
		 * as choosing the pivot at random */
		// std::random_device rd;
    		// std::mt19937 g(rd());
		// std::shuffle(a, a + n, g);
		
		std::cout << k << "th smallest in the given array is: "
			<< qselect(a, n, k - 1) << std::endl;
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
