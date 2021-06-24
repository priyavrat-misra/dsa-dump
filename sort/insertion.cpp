// insertion sort
#include <iostream>

void insertion_sort(int* a, int& n) {
	int j, key;
	for (int i = 1; i < n; ++i) {
		key = a[i];
		j = i - 1;
		while (j>=0 && a[j]>key) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = key;
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
		
		insertion_sort(arr, size);
		
		std::cout << "Sorted Array: ";
		for (int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
		
		delete[] arr;
	} else {
		std::cout << "Size must be positive." << std::endl;
	}
}
