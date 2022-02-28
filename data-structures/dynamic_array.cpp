#include <iostream>

int element() {
	int e;
	std::cout << "Enter the element: ";
	std::cin >> e;
	return e;
}

int position(int& size) {
	int pos;
	std::cout << "Enter the position: ";
	while (!(std::cin >> pos && pos > -1 && pos <= size))
		std::cerr << "Not a valid position, try again: ";
	return pos;
}

void expand_array(int** a, int& size, int& alloc_size) {
	alloc_size = 2 * size;
	int* exp_arr = new int[alloc_size];
	for (int i = 0; i < size; ++i)
		exp_arr[i] = (*a)[i];
	delete[] *a;
	*a = exp_arr;
}

void print_array(int* a, int& size) {
	for (int i = 0; i < size; ++i)
		std::cout << " " << a[i];
	std::cout << std::endl;
}

int* insert(int* a, int& size, const int& pos, int& alloc_size) {
	if (size == alloc_size)
		expand_array(&a, size, alloc_size);
	
	if (pos != size)
		for (int i = size + 1; i > pos; --i)
			a[i] = a[i-1];

	a[pos] = element();
	++size;
	return a;
}

int* del(int* a, int& size, const int& pos) {
	if (pos < size-1)
		for (int i = pos; i < size; ++i)
			a[i] = a[i+1];
	--size;
	return a;
}

int main() {
	int size, alloc_size;
	std::cout << "Enter the size of the array you want to start with: ";
	if (std::cin >> size && size > 0) {
		alloc_size = size;
		int* a = new int[size];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < size; ++i)
			std::cin >> a[i];
		int choice = 0;
		while (choice != 3) {
			std::cout
				<< "1. Insert element(s)\n"
				<< "2. Delete element(s)\n"
				<< "3. Exit" << std::endl
				<< "Choose one (1, 2 or 3): ";
			std::cin >> choice;
			std::cout << std::endl;
			switch (choice) {
				case 1:
					while (choice != 3) {
						std::cout
							<< "1. Insert element at end\n"
							<< "2. Insert element at a given position\n"
							<< "3. Go back" << std::endl
							<< "Choose one (1, 2 or 3): ";
						std::cin >> choice;
						std::cout << std::endl;
						switch (choice) {
							case 1:
								a = insert(a, size, size, alloc_size);
								std::cout << "Element inserted at the end.\n"
									<< "New array:";
								print_array(a, size);
								std::cout << std::endl;
								break;
							case 2:
								a = insert(a, size, position(size), alloc_size);
								std::cout << "Element inserted at the given position.\n"
									<< "New array:";
								print_array(a, size);
								std::cout << std::endl;
								break;
							case 3:
								break;
							default:
								std::cerr << "Not a valid choice, try again." << std::endl;
								break;
						}
					}
					choice = 0;
					break;
				case 2:
					while (choice != 3) {
						std::cout
							<< "1. Delete the last element\n"
							<< "2. Delete element at a given position\n"
							<< "3. Go back" << std::endl
							<< "Choose one (1, 2 or 3): ";
						std::cin >> choice;
						std::cout << std::endl;
						if (size == 0) {
							std::cout << "There's nothing to delete." << std::endl;
							choice = 3;
						}
						switch (choice) {
							case 1:
								a = del(a, size, size-1);
								std::cout << "Last element deleted.\n"
									<< "New array:";
								print_array(a, size);
								std::cout << std::endl;
								break;
							case 2:
								a = del(a, size, position(size));
								std::cout << "Element at the given position deleted.\n"
									<< "New array:";
								print_array(a, size);
								std::cout << std::endl;
								break;
							case 3:
								break;
							default:
								std::cerr << "Not a valid choice, try again." << std::endl;
								break;
						}
					}
					choice = 0;
					break;
				case 3:
					delete[] a;
					break;
				default:
					std::cerr << "Not a valid choice, try again." << std::endl;
					break;
			}
		}
	} else {
		std::cerr << "Not a valid size." << std::endl;
	}
}

