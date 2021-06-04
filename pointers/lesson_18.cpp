/*
 * Dynamic allocation of 2D arrays using array of pointers.
 * Note: The resulting array won't be contiguous in memory.
 */

#include <iostream>

int main() {
	int m, n;
	std::cout << "Enter number of rows and columns: ";
	if (std::cin >> m >> n && m>0 && n>0) {
		int** arr = new int*[m];
		std::cout << "Enter the elements row-wise:" << std::endl;
		
		for (int i=0; i<m; i++) {
			arr[i] = new int[n];
			for (int j=0; j<n; j++)
				std::cin >> arr[i][j];
		}

		std::cout << "The address of the elements are:" << std::endl;
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++)
				std::cout << arr[i]+j << " ";
			std::cout << std::endl;
			delete[] arr[i];	
		}

		delete[] arr;
		arr = nullptr;

	} else {
		std::cout << "rows and columns count must be positive." << std::endl;
	}
}
