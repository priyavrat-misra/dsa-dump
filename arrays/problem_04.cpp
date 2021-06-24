// maximum sub-array sum and maximum sum sub-array
/* 
 * approach: bruteforce
 * running time: cubic
 */
#include <iostream>
#include <climits> 

int main() {
	int size, maxsum = INT_MIN, subsum, x, y;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> size && size > 0) {
		int* a = new int[size];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < size; ++i)
			std::cin >> a[i];

		std::cout << "maximum sub-array sum is: ";
		for (int i = 0; i < size; ++i) {
			for (int j = i; j < size; ++j) {
				subsum = 0;
				for (int k = i; k <= j; ++k)
					subsum += a[k];
				if (subsum > maxsum) {
					maxsum = subsum;
					x = i;
					y = j;
				}
			}
		}
		std::cout << maxsum << std::endl;
		std::cout << "maximum sum sub-array is: [ ";
		for (int i = x; i <= y; ++i)
			std::cout << a[i] << " ";
		std::cout << "]" << std::endl;
		delete[] a;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
