// selection sort
#include <iostream>

void swap(int& i, int& j) {
	int temp = i;
	i = j;
	j = temp;
}

void selection_sort(int* a, int& n) {
	for (int i = 0; i < n-1; ++i) {
		int min_idx = i;
		for (int j = i+1; j < n; ++j)
			if (a[j] < a[min_idx])
				min_idx = j;
		swap(a[i], a[min_idx]);
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
	
		selection_sort(arr, size);
	
		std::cout << "Sorted Array: ";
		for (int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	
		delete[] arr;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
