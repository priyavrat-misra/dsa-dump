// maximum sub-array sum and maximum sum sub-array (Kadane's Algo)
#include <iostream>

int main(){
	int size, maxsum=0, cursum=0, x, y, s=0;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	int* a = new int[size];
	std::cout << "Enter the elements: ";
	for(int i=0; i<size; i++)
		std::cin >> a[i];
	std::cout << "maximum sub-array sum is: ";
	for(int i=0; i<size; i++){
		cursum += a[i];
		if(cursum < 0){
			cursum=0;
			s=i+1;
		}
		if(cursum > maxsum){
			maxsum=cursum;
			x=s;
			y=i;
		}
	}
	std::cout << maxsum << std::endl;
	std::cout << "maximum sum sub-array is: [ ";
	for(int i=x; i<=y; i++)
		std::cout << a[i] << " ";
	std::cout << "]" << std::endl;
	delete[] a;
}
