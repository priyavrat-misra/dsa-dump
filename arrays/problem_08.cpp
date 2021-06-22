// transpose a 2D array
/* 
 * approach: bruteforce
 * running time: quadratic
 */
#include <iostream>

int main() {
	int m, n;
	std::cout << "Enter the number of rows and columns: ";
	if (std::cin >> m >> n && m>0 && n>0) {
		int* a = new int[m*n];
		std::cout << "Enter the elements row-wise:" << std::endl;
		for (int i=0; i<m*n; i++)
			std::cin >> a[i];

		std::cout << "The transpose of the array is:" << std::endl;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				std::cout << a[i+n*j] << " ";
			std::cout << std::endl;
		}

		delete[] a;
		a = nullptr;

	} else {
		std::cout << "rows and columns count must be positive." << std::endl;
	}
}
