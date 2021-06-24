// cyclically rotate an array by k
/* 
 * approach: modulus
 * running time: linear
 */
#include <iostream>

int main() {
	int s;
	std::cout << "Enter the size: ";
	if (std::cin >> s && s > 0) {
		int* a = new int[s];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < s; ++i)
			std::cin >> a[i];
		
		int k;
		std::cout << "Enter k: ";
		std::cin >> k;
		k = k > s ? k%s : k;
		
		std::cout << "The k rotated array is: ";
		for (int i = s-k; i < 2*s-k; ++i)
			std::cout << " " << a[i%s];
		
		std::cout << std::endl;
		delete[] a;
	} else {
		std::cout << "Size must be positive." << std::endl;
	}
}
