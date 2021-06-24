// binary search
#include <iostream>

int main() {
	int s;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> s && s > 0) {
		int* a = new int[s];
		std::cout << "Enter the elements in increasing order: ";
		for (int i = 0; i < s; ++i)
			std::cin >> a[i];
		
		int n, start = 0, end = s;
		std::cout << "Enter the number to search: ";
		std::cin >> n;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (a[mid] == n) {
				std::cout << "Number found at position " << mid+1 << std::endl;
				delete[] a;
				exit(0);
			} else if (a[mid] > n) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
		std::cout << "Number not in the given array." << std::endl;
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}

