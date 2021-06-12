// merge two sorted arrays without using extra space
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
#include <iostream>

bool swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
	return true;
}

void isort(int* b, int& n) {
	int j, key;
	for (int i=1; i<n; ++i) {
		key = b[i];
		j = i-1;
		while (j>=0 && b[j]>key) {
			b[j+1] = b[j];
			--j;
		}
		b[j+1] = key;
	}
}

void merge(int* a, int* b, int& m, int& n) {
	int i=0, j=0, k=m-1;
	while (i<=k && j<n) {
		if (a[i]<b[j]) {
			++i;
		} else {
			swap(a[k], b[j]);
			--k;
			++j;
		}
	}
	isort(a, m);
	isort(b, n);
}

int main() {
	int m, n;
	std::cout << "Enter the size of the arrays: ";
	if (std::cin>>m>>n && m>0 && n>0) {
		int* a = new int[m];
		int* b = new int[n];
		std::cout << "Enter elements for the 1st array: ";
		for (int i=0; i<m; ++i)
			std::cin >> a[i];
		std::cout << "Enter elements for the 2nd array: ";
		for (int i=0; i<n; ++i)
			std::cin >> b[i];
		
		merge(a, b, m, n);

		std::cout << "The merged array:";
		for (int i=0; i<m; ++i)
			std::cout << " " << a[i];
		for (int i=0; i<n; ++i)
			std::cout << " " << b[i];
		std::cout << std::endl;

		delete[] a, b;
	} else {
		std::cout << "Sizes must be positive." << std::endl;
	}
}
