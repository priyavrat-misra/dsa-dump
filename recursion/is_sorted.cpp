// check if an array is sorted
#include <iostream>

bool is_sorted(int* a, int n) {
	if (n == 1)
		return true;
	else
		return a[0] <= a[1] && is_sorted(a+1, n-1);
}

int main() {
	int n;
	std::cout << "Enter size of the array: ";
	if (std::cin >> n && n > 0) {
		int* a = new int[n];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];

		std::cout << "The given array "
			<< (is_sorted(a, n) ? "is sorted." : "isn't sorted.")
			<< std::endl;
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
