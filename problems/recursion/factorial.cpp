#include <iostream>

long long factorial(const int &n) {
	if (n) {
		return n * factorial(n-1);
	} else {
		return 1;
	}
}

int main() {
	int n;
	std::cout << "Enter a natural number: ";
	if (std::cin >> n && n >= 0) {
		std::cout << n << "! = " << factorial(n) << std::endl;
	} else {
		std::cerr << "That's not a natural number!" << std::endl;
	}
}
