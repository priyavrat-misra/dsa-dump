/*
 * Dynamic allocation of 2D arrays using a single pointer.
 * The resulting array will be contiguous in memory.
 */

#include <iostream>

int main() {
	int m, n;
	std::cout << "Enter number of rows and columns: ";
	if (std::cin >> m >> n && m>0 && n>0) {
		int* arr = new int[m*n];
		std::cout << "Enter the elements row-wise:" << std::endl;
		
		for (int i=0; i<m*n; i++)
			std::cin >> arr[i];

		std::cout << "The address of the elements are:" << std::endl;
		for (int i=0; i<m; i++){
			for (int j=0; j<n; j++)
				std::cout << arr + i*n + j << " "; // or &a[i][j]
			
			std::cout << std::endl;
		}

		delete[] arr;
		arr = nullptr;

	} else {
		std::cout << "rows and columns count must be positive." << std::endl;
	}
}
