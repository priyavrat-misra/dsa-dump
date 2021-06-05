// linear search
#include <iostream>

int main() {
	int s, n;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> s && s>0) {
		int* a = new int[s];
		std::cout << "Enter the elements: ";
		for (int i=0; i<s; ++i)
			std::cin >> a[i];

		std::cout << "Enter the number to search: ";
		std::cin >> n;
		for (int i=0; i<s; ++i) {
			if (a[i] == n) {
				std::cout << "Number found at position " << i+1 << std::endl;
				delete[] a;
				exit(0);
			}
		}
		std::cout << "Number not in the given array." << std::endl;
		delete[] a;
	} else {
		std::cout << "Size must be positive." << std::endl;
	}
}
