// reverse an array
#include <iostream>

void reverse(int* a, int s){
	int start = 0, end = s-1, temp;
	while(end>start){
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}

int main(){
	int size;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "Enter the elements: ";
	for(int i=0; i<size; i++){
		std::cin >> *(arr+i);
	}
	std::cout << "The reverse of the array is: ";
	reverse(arr, size);
	for(int i=0; i<size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	delete[] arr;
}
