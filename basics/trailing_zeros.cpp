// program to find number of trailing zeros in a given no's factorial
#include <iostream>

int main() {
	int n;
	std::cout << "Enter a natural number: ";
	if (std::cin >> n && n>0) {
		int z = 0;
		for (int i=5; n/i; i*=5)
			z += n/i;

		std::cout << "The number of trailing zeros in it's factorial is: " << z << std::endl;
	} else {
		std::cout << "That's not a natural number!" << std::endl;
	}
}
