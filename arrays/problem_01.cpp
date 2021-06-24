// reverse an array 
/*
 * approach: two pointers
 * running time: linear
 */
#include <iostream>

void reverse(int* a, int s) {
	int start = 0, end = s - 1, temp;
	while (end > start) {
		temp = a[start];
		a[start++] = a[end];
		a[end++] = temp;
	}
}

int main() {
	int size;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> size && size > 0) {
		int* arr = new int[size];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < size; ++i)
			std::cin >> arr[i];

		std::cout << "The reverse of the array is: ";
		reverse(arr, size);
		
		for (int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		delete[] arr;
	} else {
		std::cout << "Size must be positive." << std::endl;
	}
}
