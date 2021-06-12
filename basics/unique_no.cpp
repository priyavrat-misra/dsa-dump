// Finds the unique number from a list containing 
// duplicates and one unique number. 
#include <iostream>

int main() {
	int n, no, ans = 0;
	std::cout << "Enter number of elements: ";
	if (std::cin>>n && n>0) {
		std::cout << "Enter " << n << " number(s):" << std::endl;

		for (int i=0; i<n; ++i) {
			std::cin >> no;
			ans ^= no; // xor
		}

		if (ans) {
			std::cout << ans << " is unique." << std::endl;
		} else {
			std::cout << "No unique number present." << std::endl;
		}
	} else {
		std::cout << "Number must be positive." << std::endl;
	}
}
