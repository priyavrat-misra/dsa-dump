// bubble sort
#include <iostream>

bool swap(int& i, int& j) {
	int temp = i;
	i = j;
	j = temp;
	return true;
}

void recursive_bsort(int* a, const int& n, int j = 0) {
	if (n > 1) {
		if (j == n - 1) // outer loop
			return recursive_bsort(a, n - 1);
		if (a[j] > a[j+1])
			swap(a[j], a[j+1]);
		
		recursive_bsort(a, n, j + 1); // inner loop
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
		recursive_bsort(arr, size);
		for(int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
		
		delete[] arr;
	} else {
		std::cerr << "Size must be positive." << std::endl;
	}
}
