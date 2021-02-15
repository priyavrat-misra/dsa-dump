// maximum and minimum of an array
#include <iostream>
#include <climits>

int main(){
	int smallest = INT_MAX, largest = INT_MIN;
	int size;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "Enter the elements: ";
	for(int i=0; i<size; i++)
		std::cin >> *(arr+i);
	for(int i=0; i<size; i++){
		if(arr[i]>largest)
			largest = arr[i];
		if(arr[i]<smallest)
			smallest = arr[i];
	}
	std::cout << "Largest element: " << largest << std::endl;
	std::cout << "Smallest element: " << smallest << std::endl;
	delete[] arr;
}
