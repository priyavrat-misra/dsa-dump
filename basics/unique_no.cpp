// Finds the unique number from a list containing 
// numbers occuring twice and one number occuring once. 
#include <iostream>

int main() {
	int n, no, ans = 0;
	std::cout << "Enter number of elements: ";
	std::cin >> n;
	std::cout << "Enter " << n << " number(s):" << std::endl;

	for (int i=0; i<n; ++i) {
		std::cin >> no;
		ans ^= no; // xor
	}

	if (ans) {
		std::cout << ans << " is unique." << std::endl;
	}
	else {
		std::cout << "No unique number present." << std::endl;
	}
}
