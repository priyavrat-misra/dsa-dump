// "K"th largest and smallest of an array
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
#include <iostream>

void ins_sort(int a[], int& s) {
	int j, key;
	for (int i=1; i<s; ++i) {
		key = a[i];
		j = i-1;
		while (j>=0 && a[j]>key) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = key;
	}
}

int main() {
	int s;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> s && s>0) {
		int* a = new int[s];
		
		std::cout << "Enter the elements: ";
		for (int i=0; i<s; ++i)
			std::cin >> a[i];

		int k;
		std::cout << "Enter k: ";
		if (std::cin >> k && k>0 && k<=s+1) {
			ins_sort(a, s);
			std::cout << "kth smallest number is: " << a[k-1] << std::endl;	
			std::cout << "kth largest number is: " << a[s-k] << std::endl;
			delete[] a;	
		} else {
			std::cout << "k out of range [1, " << s+1 << "]" << std::endl;
			delete[] a;
			exit(0);
		}
	} else {
		std::cout << "Size must be positive." << std::endl;
	}
}
