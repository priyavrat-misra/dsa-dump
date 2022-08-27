#include <iostream>

int main() {
	int n, i = 2;
	bool isPrime = true;
	std::cout << "Enter a whole number: ";
	if (std::cin >> n && n == 1) {
		std::cout << n << " is not Prime." << std::endl;
	} else if (n > 1) {
		while (i*i <= n) { // not prime if there is a factor between two and the sqrt
			if (n%i == 0) {
				isPrime = false;
				break;
			}
			++i;
		}
		std::cout << n << (isPrime ? " is Prime." : " is not Prime.") << std::endl;
	} else {
		std::cerr << "That's not a whole number!" << std::endl;
	}
}
