// insertion sort
#include <iostream>

bool compare(int& a, int& b, bool& decr){
	if(decr) return a<b;
	else return a>b;
}

void insertion_sort(int* a, int& n, bool (&cmpr)(int&,int&,bool&)){
	int i, j, key;
	bool decr = false;
	for(i=1; i<n; i++){
		key = a[i];
		j = i-1;
		while(j>=0 && cmpr(a[j], key, decr)){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
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
	insertion_sort(arr, size, compare);
	std::cout << "Sorted Array: ";
	for(int i=0; i<size; i++)
		std::cout << *(arr+i) << " ";
	std::cout << std::endl;
	delete[] arr;
}	
