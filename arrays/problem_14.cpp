// minimize the maximum difference between heights
/*
 * source: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
 * approach: sorting
 * running time: quadratic
 */
#include <iostream>

void sort(int* a, int& s) {
	int key, j;
	for (int i = 1; i < s; ++i) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = key;
	}
}

inline int min(int a, int b) {
	return a > b ? b : a;
}

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int s;
	std::cout << "Enter the size of the array: ";
	if (std::cin >> s && s > 0) {
		int* a = new int[s];
		std::cout << "Enter the elements: ";
		for (int i = 0; i < s; ++i)
			std::cin >> a[i];

		sort(a, s);
		
		int k, ans, mn, mx;
		std::cout << "Enter a non-negative integer: ";
		std::cin >> k;
		
		ans = a[s-1] - a[0];
		for (int i = 1; i < s; ++i) {
			mn = min(a[0] + k, a[i] - k);
			mx = max(a[s-1] - k, a[i-1] + k);
			ans = min(ans, mx - mn);
		}

		std::cout << "Maximum difference is: " << ans << std::endl;

		delete[] a;
	} else {
		std::cout << "Size must be positive." << std::endl;
	}
}
