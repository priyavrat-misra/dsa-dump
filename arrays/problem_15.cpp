// Problem:
/*
 * Given an array of integers containing n + 1 integers
 * where each integer is in the range [1, n] inclusive.
 * There is only one repeated number, return this repeated number.
 *
 * source: https://leetcode.com/problems/find-the-duplicate-number/
 */

// Solution:
/*
 * approach: sum of all elements
 * running time: linear
 */

#include <iostream>

int main() {
	int n;
	std::cout << "Enter 'n': ";
	if (std::cin >> n && n > -1) {
		int* a = new int[n+1];
		int sum = 0;
		std::cout << "Enter " << n + 1
			<< " number(s) in range [1, n]: ";
		for (int i = 0; i <= n; ++i) {
			std::cin >> a[i];
			sum += a[i];
		}
		std::cout << "The repeated number is: "
			<<  sum - ((n * (n+1)) / 2) << std::endl;
		delete[] a;
	} else {
		std::cerr << "'n' must be a whole number." << std::endl;
	}
}
