// maximum sub-array sum and maximum sum sub-array (optimized)
#include <iostream>
#include <climits>

int main() {
	int size, maxsum=INT_MIN, subsum, x, y;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> size && size>0) {
		int* a = new int[size];
		
		std::cout << "Enter the elements: ";
		for (int i=0; i<size; ++i)
			std::cin >> a[i];
		
		int* csum = new int[size];
		csum[0] = a[0];
		for (int i=1; i<size; ++i)
			csum[i] = a[i] + csum[i-1];

		std::cout << "maximum sub-array sum is: ";
		for (int i=0; i<size; ++i) {
			for (int j=i; j<size; ++j) {
				subsum = csum[j] - csum[i-1];
				if (subsum>maxsum) {
					maxsum=subsum;
					x=i;
					y=j;
				}
			}
		}
		delete[] csum;
		std::cout << maxsum<< std::endl;
		
		std::cout << "maximum sum sub-array is: [ ";
		for (int i=x; i<=y; ++i)
			std::cout << a[i] << " ";
		std::cout << "]" << std::endl;

		delete[] a;
	} else {
		std::cout << "Size must be positive." << std::endl;
}
