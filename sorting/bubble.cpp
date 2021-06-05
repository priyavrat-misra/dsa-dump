// bubble sort
#include <iostream>

bool compare(int& a, int& b, bool& decr){
	if(decr) return a<b;
	else return a>b;
}

void swap(int& i, int& j){
	int temp = i;
	i = j;
	j = temp;
}

void bubble_sort(int* a, int& n, bool (&cmpr)(int&,int&,bool&)){
	bool swapped, decr=false;
	for(int i=0; i<n-1; i++){
		swapped=false;
		for(int j=0; j<n-i-1; j++)
			if(cmpr(a[j], a[j+1], decr)){
				swap(a[j], a[j+1]);
				swapped = true;
			}
		if(!swapped) break;
	}
}

int main(){
	int size;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "Enter the elements: ";
	for(int i=0; i<size; i++)
		std::cin >> *(arr+i);
	std::cout << "Sorted Array: ";
	bubble_sort(arr, size, compare);
	for(int i=0; i<size; i++)
		std::cout << *(arr+i) << " ";
	std::cout << std::endl;
	delete[] arr;
}
