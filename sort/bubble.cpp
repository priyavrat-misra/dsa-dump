// bubble sort
#include <iostream>

bool swap(int& i, int& j) {
	int temp = i;
	i = j;
	j = temp;
	return true;
}

void bubble_sort(int* a, int& n) {
	bool swapped;
	for (int i = 0; i < n-1; ++i) {
		swapped = false;
		for (int j = 0; j < n-i-1; ++j)
			if (a[j] > a[j+1]) swapped = swap(a[j], a[j+1]);
		if (!swapped) break;
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

		std::cout << "Sorted Array: ";
		bubble_sort(arr, size);
		for(int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
		
		delete[] arr;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
